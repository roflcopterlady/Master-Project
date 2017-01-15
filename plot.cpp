#define plot_cxx
#include "plot.hpp"
#include <TH1.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>

#include <algorithm>
#include <map>
#include <string>

using std::string;

string sample;

int main(int argc, char* argv[]) {
	sample = "187005";
	if(argc>1) sample = argv[1];
	cout<<"Using sample "<<sample<<endl;
	plot * a = new plot(sample);
	a->Loop();
	delete a;
	return 1;
}


void plot::Loop() {
	if (fChain == 0) {
		cout<<"No chain!"<<endl;
		return;
	}

	TString tp = "60";

	// Get generator name from input file, then use this for output file name
	TString out_file = sample.substr(13, sample.find(".AOD")-13) + ".root";
	
	// Create output file
	TFile * out = new TFile ("output/" + TString(out_file), "RECREATE");
	out->cd();
	
	const int nbins = 7;
	const int nbinsc = 4;

	double xbins[nbins+1] = {20, 60,100,140,180,270, 400, 700};
	double xcbins[nbinsc+1] = {20, 60,100,160, 300};
	const int nweights = 11;

	// Histograms for separation between jets and nearest hadrons
	h_bdR_min = MakePlot("h_b_jet_closest_b_hadron", 50, 0, 2);
	h_bdR_next = MakePlot("h_b_jet_next_closest_b_hadron", 50, 0, 2);
	h_cdR_min = MakePlot("h_c_jet_closest_b_hadron", 50, 0, 2);
	h_cdRc_min = MakePlot("h_c_jet_closest_c_hadron", 50, 0, 2);

	
	h_bhadron = MakePlot("h_b_hadron", 2, 0, 1.1);
	h_mv2c20 = MakePlot("h_mv2c20", 20, -1, 1); // Histogram of MV2C20 for jets

	h_jet_eta = MakePlot("jet_eta", 100, 0, 10); // Histogram of eta for jets

	// Maps of histograms for untagged jet transverse momentums and fractions of this carried by hadron, for each hadron
	std::map<int, std::vector<TH1*>> h_jet_pT_notags;
	std::map<int, std::vector<TH1*>> h_pT_frac_notags;
	
	// Map of jet transverse momentum, hadron transverse momentum, and fraction carried by hadron, for each hadron
	std::map<int, TH1*> h_jet_pT, h_pT_frac, h_had_pT;

	std::map<int, TGraph*> g_mv_frac; // Map of scatter plots for pt frac carried by hadron against jet MV2C20, for each hadron 

	//==============================================================================


	std::map<int, int> hadron_counts; // Map to count numbers of each hadron

	// Map of vectors of histograms for the proportion of tagged and untagged jets, for each hadron with each MV2C20 cut.
	// Each histogram has two bins - one is filled when jet is tagged, the other when the jet is not tagged.
	std::map<int, vector<TH1*>> tagged_props; 

	// Get number of entries, and loop across all entries
	Long64_t nentries = fChain->GetEntriesFast();
	cout<<"Looping over "<<nentries<<" events."<<endl;
	Long64_t nbytes = 0, nb = 0;
	for (Long64_t jentry=0; jentry < nentries; jentry++) {

		
		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;
		nb = fChain->GetEntry(jentry);   nbytes += nb;
		
		if(jentry>0 && jentry % 50000 == 0 ) cout<<"Event "<<jentry<<endl; // To show progress iterating across events
	   
		// Loop across all particles in event
		for(int i=0; i<(*mchfpart_pdgid).size(); i++) {
			
			// Check if hadron is weakly decaying b-hadron
			if (IsWeakB((*mchfpart_pdgid)[i])) {

				// Iterate count of hadrons, or create counter for hadron if doesn't exist
					if (hadron_counts.find((*mchfpart_pdgid)[i]) == hadron_counts.end()) {
						
						hadron_counts.insert(std::pair<int, int>((*mchfpart_pdgid)[i], 1));						
					} else {
						
						hadron_counts.find((*mchfpart_pdgid)[i])->second++;						
					}
				}
			
		}


		//loop over jets in event		
		for(int ijet=0; ijet< (*jet_pT).size(); ijet++) {
			
			// Fill histogram of jet MV2C20 coefficients
			h_mv2c20->Fill((*jet_MV2c20)[ijet]);

			//veto jets that are close together:
			bool veto = false;
			for(int j=0; j<(*jet_pT).size(); j++) {
				if(ijet==j) continue;
				//	if((*jet_overlap_electron)[j]==1) continue;
				if( DeltaR( (*jet_eta)[ijet], (*jet_phi)[ijet], (*jet_eta)[j], (*jet_phi)[j]) <0.8) veto=true;
			}
			if(veto) continue;
		
			//label the jet, based on any heavy hadron inside:
			std::pair<int, int> labels = Label( (*jet_eta)[ijet], (*jet_phi)[ijet], (*jet_MV2c20)[ijet]);
			const int label =  labels.first;   //flavour (5,4,0) based on hadron
			const int hlabel = labels.second; //pdg id of hadron
      
			// Check if histograms for tagged proportion of jets have been created for this hadron. Create these histograms if not.
			if (tagged_props.find(hlabel) == tagged_props.end()) {
				std::vector<TH1*> hists_vector; // Vector of histograms for given hadron. Note that vector is used, as four MV2C20 cuts are examined.

				// Loop across MV2C20 cuts, and create histograms
				for (int tag_iter = 0; tag_iter < 4; tag_iter++) {
					hists_vector.push_back(MakePlot(strcat(Form("tagged_prop_%f_", tag[tag_iter]), Form("%i", hlabel)), 2, 0, 1.1));
					hists_vector[tag_iter]->SetMinimum(0);
				}

				// Insert plots into map of plots for different hadrons
				tagged_props.insert(std::pair<int, vector<TH1*>>(hlabel, hists_vector));
				
				// Create graph for MV2C20 coefficients and hpt/pt for jets with this hadron
				TGraph * new_graph = new TGraph();
				new_graph->SetName(TString("mv_frac_scatter_") + Form("%i", hlabel));				
				g_mv_frac.insert(std::pair<int, TGraph*>(hlabel, new_graph));
			}
			
			// Get first digit of label, to check if charm or beauty hadron.
			int first_digit = std::to_string(hlabel).at(0) - 48;
			if (first_digit == 0) continue; // Something's bad if first digit is 0, so don't process these.

			//and only jets with one match:
			if( bh.size()>1 || ch.size()>1 ) continue;

			// Load properties of jet
			const float mv = (*jet_MV2c20)[ijet];
			const float pT = (*jet_pT)[ijet];
			const float eta = (*jet_eta)[ijet];
						
			h_jet_eta->Fill(eta); // Fill histogram of eta values for all jets.

			// Loop across MV2C20 cuts, to get appropriate histogram
			for (int tag_iter = 0; tag_iter < 4; tag_iter++) {

				// Fill histogram for matched hadron with '1' if MV2C20 coefficient for jet is above that of cut, or '0' if coefficient is below cut. 
				if (mv > tag[tag_iter]) {
					tagged_props.find(hlabel)->second[tag_iter]->Fill(1);
				} else {
					tagged_props.find(hlabel)->second[tag_iter]->Fill(0);
				}
			}

			// Get values of hpT and dR for jet, from appropriate array, depending if jet matched to charm or beauty hadron.			
			float hpT=0, dR=-1;
			if(first_digit==5) {
				hpT = (*mchfpart_pt)[ bh[0] ];
				dR = DeltaR( (*jet_eta)[ijet], (*jet_phi)[ijet], (*mchfpart_eta)[bh[0]],  (*mchfpart_phi)[bh[0]]); 
			}
			else if (first_digit==4){
				hpT = (*mchfpart_pt)[ ch[0] ];
				dR = DeltaR( (*jet_eta)[ijet], (*jet_phi)[ijet], (*mchfpart_eta)[ch[0]],  (*mchfpart_phi)[ch[0]]); 
			} 

			
			// Check if histograms for jet pt values have been created for this hadron. Create them if not.
			if (h_jet_pT_notags.find(hlabel) == h_jet_pT_notags.end()) {

				TString name = Form("%i", hlabel); // String for name of plots

				// Vectors of histograms for this hadron
				std::vector<TH1*> h_jet_pT_notag_current;
				std::vector<TH1*> h_pT_frac_notag_current;

				// Loop across MV2C20 cuts, and create plots for untagged jet pt and fraction of pt carried by hadron.
				for (int tag_iter = 0; tag_iter < 4; tag_iter++) {
					h_jet_pT_notag_current.push_back(MakePlot("jet_pT_notag_"+name+Form("_%f", tag[tag_iter]), 100,0,200));
					h_pT_frac_notag_current.push_back(MakePlot("jet_pT_frac_notag_"+name+Form("_%f", tag[tag_iter]), 100,0,2));

				}

				// Insert vectors of histograms into respective maps
				h_jet_pT_notags.insert(std::pair<int, std::vector<TH1*>>(hlabel, h_jet_pT_notag_current));
				h_pT_frac_notags.insert(std::pair<int, std::vector<TH1*>>(hlabel, h_pT_frac_notag_current));

				// Insert histograms for pt of all jets matched with this hadron, the pt of the hadron, and the pt fraction carried by hadron.
				h_jet_pT.insert(std::pair<int, TH1*>(hlabel, MakePlot("jet_pT_" + name + "_all", 100, 0, 200)));
				h_had_pT.insert(std::pair<int, TH1*>(hlabel, MakePlot("hadron_pT_" + name + "_all", 100, 0, 100)));
				h_pT_frac.insert(std::pair<int, TH1*>(hlabel, MakePlot("jet_pT_frac_" + name + "_all", 100, 0, 2))); 

			}

			// Find correct histograms from label, and fill.
			h_jet_pT.find(hlabel)->second->Fill(pT);
			h_pT_frac.find(hlabel)->second->Fill(hpT/pT);
			h_had_pT.find(hlabel)->second->Fill(hpT);

			// Add point to graph of hpt/pt against MV2C20 coefficient for jet
			g_mv_frac.find(hlabel)->second->SetPoint(g_mv_frac.find(hlabel)->second->GetN(), (hpT/pT), mv);
			
			// Loop across MV2C20 cuts 
			for (int tag_iter = 0; tag_iter < 4; tag_iter++) {
				
				// If MV2C20 coefficient for jet is less than cut, fill histograms for untagged jets.
				if (mv < tag[tag_iter]) {
					
					h_jet_pT_notags.find(hlabel)->second[tag_iter]->Fill(pT);
					h_pT_frac_notags.find(hlabel)->second[tag_iter]->Fill(hpT/pT);
				}
			}
			
		}//loop over jets

	}

	// Write scatter plots to output root file
	for (std::map<int, TGraph*>::iterator iter = g_mv_frac.begin(); iter != g_mv_frac.end(); ++iter) {
		iter->second->Write();
	} 

	// Output numbers of each hadron processed
	cout << endl << "Hadrons:" << endl;
	for (std::map<int,int>::iterator iter = hadron_counts.begin(); iter != hadron_counts.end(); ++iter) {
		cout << iter->first << ", " << iter->second << endl;
	}

	cout << endl << endl;



	cout<<"Post-processing plots"<<endl;
	out->cd();

	// Iterate across map of untagged jet pt histograms. Use first entry of iterator (label of hadron) as key for maps of other histograms
	for (std::map<int, std::vector<TH1*>>::iterator hadron_iter=h_jet_pT_notags.begin(); hadron_iter != h_jet_pT_notags.end(); ++hadron_iter) {
		
		// Loop across MV2C20 cuts
		for (int tag_iter = 0; tag_iter<4; tag_iter++) {

			// Normalise histograms of untagged jet pT and pT fraction carried by hadron
			hadron_iter->second[tag_iter]->Scale(1./(hadron_iter->second[tag_iter]->Integral()));
			h_pT_frac_notags.find(hadron_iter->first)->second[tag_iter]->Scale(1./(h_pT_frac_notags.find(hadron_iter->first)->second[tag_iter]->Integral()));
			
		}

		// Normalise histograms of pT and fraction carried by hadron for all jets labelled with this hadron
		h_jet_pT.find(hadron_iter->first)->second->Scale(1./(h_jet_pT.find(hadron_iter->first)->second->Integral()));
		h_pT_frac.find(hadron_iter->first)->second->Scale(1./(h_pT_frac.find(hadron_iter->first)->second->Integral()));

	}

	// Normalise plots of separation between jet and hadron
	h_bdR_min->Scale(1./h_bdR_min->Integral());
	h_bdR_next->Scale(1./h_bdR_next->Integral());
	h_cdR_min->Scale(1./h_cdR_min->Integral());
	h_cdRc_min->Scale(1./h_cdRc_min->Integral());
	

	// Write and close output file
	out->Write();
	out->Close();


}
