#define simple_tag_proportions_cxx
#include "simple_tag_proportions.hpp"
#include <TROOT.h>
#include <TH1.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TLegend.h>
#include <TGraph.h>
#include <THStack.h>
#include <fstream>
#include <cstdlib>
#include "TFile.h"
#include <TGraph.h>
#include <map>

#include <algorithm>
#include <map>
#include <string>
#include <limits>

using std::cin;
using std::string;
using std::ofstream;

string sample;

int cut_pos;

int hadron_number;
float mv_value;

bool first_time_title = true;
bool loop_hadron = true;

string hadron_type = "B";


std::vector<float> countOfB_Hadrons;
std::vector<float> countOfB_HadronsUseful;

int hadronCounter = 1;

//Vector for properties of entire family

bool onceMV = true;

std::vector<float> pTAllB;
std::vector<float> etaAllB;

std::vector<float> pTAllB_labeled;
std::vector<float> etaAllB_labeled;

std::vector<float> pTAllB_tagged_low;
std::vector<float> etaAllB_tagged_low;
std::vector<float> pTAllB_tagged_high;
std::vector<float> etaAllB_tagged_high;

//Geting the correct limits
float maxPt = std::numeric_limits<float>::min();
float minPt = std::numeric_limits<float>::max();
float maxEta = std::numeric_limits<float>::min();
float minEta = std::numeric_limits<float>::max();
float maxPhi = std::numeric_limits<float>::min();
float minPhi = std::numeric_limits<float>::max();
float maxDr = std::numeric_limits<float>::min();
float minDr = std::numeric_limits<float>::max();
//float maxh_loc = std::numeric_limits<float>::min();
//float minh_loc = std::numeric_limits<float>::max();

//Get hadron count
std::map<float, int> Hadron_count_map;
std::map<float, int> Hadron_count_map_tagged_low;
std::map<float, int> Hadron_count_map_tagged_high;

//simple_tag_proportions shared = NULL;

// Script to output tagged proportion of jets for single given event generator and hadron. Takes argument of input file for given event generator.
int main(int argc, char* argv[]) {
    
    /*
     name 	weight cut 	b-jet efficiency [%] 	purity [%] 	c RR 	tau RR 	light RR
     FixedCutBEff_30 	0.9540 	30.17 	99.87 	686.23 	4609.15 	52788.25
     FixedCutBEff_50 	0.7535 	50.26 	99.11 	61.25 	318.80 	6683.46
     FixedCutBEff_60 	0.4496 	60.27 	97.83 	21.32 	94.04 	1704.54
     FixedCutBEff_70 	-0.0436 	70.26 	94.86 	8.03 	26.59 	405.37
     FixedCutBEff_77 	-0.4434 	77.25 	90.90 	4.51 	9.84 	125.93
     FixedCutBEff_80 	-0.5911 	80.24 	88.45 	3.62 	6.77 	71.70
     FixedCutBEff_85 	-0.7887 	85.22 	82.75 	2.60 	3.83 	27.16
     FixedCutBEff_90 	-0.9185 	90.17 	72.89 	1.95 	2.14 	9.27
     */
    
    sample = "/home/oriana/scratch/code/output2.root"; //187005";
    if(argc>1) sample = argv[1];
    cout<<"Using sample "<<sample<<endl;
    simple_tag_proportions * a = new simple_tag_proportions(sample);
    
    //cut_pos used to pick the different MV2C20 values from the file: utils.h
    ///GO UP TO i=10 to plot over all B-Hadrons
    
    int numberOfHadrons = (hadron_type=="B") ? 10 : 7;
    
    cout<<hadron_type<<"_"<<numberOfHadrons<<endl;
    
    for(int i=0; i<numberOfHadrons; i++) {
        
        //Checking which hadron out of total we are on.
        cout<<"\n\n\nOn hadron "<<i+1<<" of "<<numberOfHadrons<<"\n\n\n"<<endl;
        
        loop_hadron = true;
        hadron_number = (hadron_type=="B") ? b_hadrons[i] : c_hadrons[i];
        
        for(int k = 0; k < 2; k++) {
            mv_value = tag[k];
            cut_pos = k;
            a->Loop(true);
        }
    }
    
    cout<<"Limits for "<<hadron_type<<endl;
    cout<<"MaxPt: "<<maxPt<<" MinPt: "<<minPt<<endl;
    cout<<"MaxEta: "<<maxEta<<" MinEta: "<<minEta<<endl;
    cout<<"MaxPhi: "<<maxPhi<<" MinPhi: "<<minPhi<<endl;
    
    cout<<"MaxDr: "<<maxDr<<" MinDr: "<<minDr<<endl;
    //    cout<<"Max h_loc: "<<maxh_loc<<" Min h_loc:"<<minh_loc<<endl;
    
    //Getting the hadron count for TGraph.
    for (float number: countOfB_Hadrons) {
        if (std::find(countOfB_HadronsUseful.begin(), countOfB_HadronsUseful.end(), number) == countOfB_HadronsUseful.end()) {
            countOfB_HadronsUseful.push_back(number);
        }
    }
    
    for (float f: b_hadrons) {
        Hadron_count_map[f] = 0;
        Hadron_count_map_tagged_low[f] = 0;
        Hadron_count_map_tagged_high[f] = 0;
    }
    for (float f: c_hadrons) {
        Hadron_count_map[f] = 0;
        Hadron_count_map_tagged_low[f] = 0;
        Hadron_count_map_tagged_high[f] = 0;
    }
    
    for(int i=0; i<numberOfHadrons; i++) {
        
        hadron_number = (hadron_type=="B") ? b_hadrons[i] : c_hadrons[i];
        
        cout<<"\n\n\nOn hadron "<<i+1<<" of "<<numberOfHadrons<<"\n\n\n"<<endl;
        
        a->Loop(false);
    }
    
    a->plot_all_properties();
    a->hadron_count_plot();
    
    delete a;
    return 1;
}

//Loop over events
void simple_tag_proportions::Loop(bool write) {
    
    std::vector<float> inside_pTAllB;
    std::vector<float> inside_etaAllB;
    
    std::vector<float> inside_pTAllB_labeled_low;
    std::vector<float> inside_etaAllB_labeled_low;
    std::vector<float> inside_pTAllB_labeled_high;
    std::vector<float> inside_etaAllB_labeled_high;
    
    std::vector<float> inside_pTAllB_tagged_low;
    std::vector<float> inside_etaAllB_tagged_low;
    std::vector<float> inside_pTAllB_tagged_high;
    std::vector<float> inside_etaAllB_tagged_high;
    
    // Get name of generator from input file
    TString generator = "powheg";//sample.substr(13, sample.find(".AOD")-13);
    
    // To count number of tagged jets and total jets
    float tagged_jets = 0;
    float total_jets = 0;
    
    if (fChain == 0) {
        cout<<"No chain!"<<endl;
        return;
    }
    
    TString tp = "60";
    
    const int nbins = 7;
    const int nbinsc = 4;
    
    double xbins[nbins+1] = {20, 60,100,140,180,270, 400, 700};
    double xcbins[nbinsc+1] = {20, 60,100,160, 300};
    const int nweights = 11;    
    
    ///Plot naming convention
    //HadronFamily_HadronNumber_Property_Labelled/LabelledAndTagged_MV2C20Value
    //HadronFamily:                 B or C
    //HadronNumber:                 Check utils.hpp
    //Property:                     PT or ETA or H_LOC
    //Labelled/LabelledAndTagged:   L or LT
    //MV2C20Value:                  Check utils.hpp or empty
    
    ///B-Hadrons limits
    //MaxPt: 738.415 MinPt: 20.0023
    //MaxEta: 2.49976 MinEta: -2.49958
    //MaxPhi: 3.14155 MinPhi: -3.14154
    
    ///C-Hadrons limits
    //MaxPt: 1293.71 MinPt: 20.0061
    //MaxEta: 2.49911 MinEta: -2.49971
    //MaxPhi: 3.14151 MinPhi: -3.14153
    
    TH1 * plotMV2C20;
    TH1 * plot_pt_labled;
    TH1 * plot_pt_labled_tagged;
    TH1 * plot_eta_labled;
    TH1 * plot_eta_labled_tagged;
    TH1 * plot_phi_labled;
    TH1 * plot_phi_labled_tagged;
    TH1 * plot_dR_labled;
    TH1 * plot_dR_labled_tagged;
    TH1 * plot_pt_ratio_labled;
    TH1 * plot_pt_ratio_labled_tagged;
    TH1 * plot_h_location;
    
    if (write) {
        plotMV2C20 = MakePlot("plotMV2C20", 50, -1, 1);
        
        plot_pt_labled = MakePlot(hadron_type+"_"+std::to_string(hadron_number)+"_"+"PT"+"_"+"L", 100, 0, 1000);
        plot_pt_labled_tagged = MakePlot(hadron_type+"_"+std::to_string(hadron_number)+"_"+"PT"+"_"+"LT"+"_"+std::to_string(mv_value), 100, 0, 1000);
        
        plot_eta_labled = MakePlot(hadron_type+"_"+std::to_string(hadron_number)+"_"+"ETA"+"_"+"L", 100, -3, 3);
        plot_eta_labled_tagged = MakePlot(hadron_type+"_"+std::to_string(hadron_number)+"_"+"ETA"+"_"+"LT"+"_"+std::to_string(mv_value), 100, -3, 3);
        
        plot_phi_labled = MakePlot(hadron_type+" - Phi Labeled - Hadron: "+std::to_string(hadron_number)+" MV:"+std::to_string(mv_value), 100, 4, -4);
        plot_phi_labled_tagged = MakePlot(hadron_type+" - Phi Labeled and Tagged - Hadron: "+std::to_string(hadron_number)+" MV:"+std::to_string(mv_value), 100, -4, 4);
        
        plot_dR_labled = MakePlot(hadron_type+"_"+std::to_string(hadron_number)+"_"+"DR"+"_"+"L", 100, 0, 1);
        plot_dR_labled_tagged = MakePlot(hadron_type+"_"+std::to_string(hadron_number)+"_"+"DR"+"_"+"LT"+"_"+std::to_string(mv_value), 100, 0, 1);
        
        plot_pt_ratio_labled = MakePlot(hadron_type+"_"+std::to_string(hadron_number)+"_"+"PT_RATIO"+"_"+"L", 100, 0, 1);
        plot_pt_ratio_labled_tagged = MakePlot(hadron_type+"_"+std::to_string(hadron_number)+"_"+"PT_RATIO"+"_"+"LT"+"_"+std::to_string(mv_value), 100, 0, 1);

	plot_h_location = MakePlot(hadron_type+"_"+std::to_string(hadron_number)+"_"+"H_LOC IN JET"+"_"+"LT"+"_"+std::to_string(mv_value), 100, -1, 1);
    }
    
    //Get number of entries, and loop across all entries
    Long64_t nentries = fChain->GetEntriesFast();
    cout<<"Looping over "<<nentries<<" events."<<endl;
    Long64_t nbytes = 0, nb = 0;
    
    //Loop over jets
    for (Long64_t jentry=0; jentry < nentries; jentry++) {
        
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;
        
        if(jentry>0 && jentry % 50000 == 0 ) cout<<"Event "<<jentry<<endl; // To show progress iterating across events
        
        //loop over jets in event
        for(int ijet=0; ijet< (*jet_pT).size(); ijet++) { ///.size if the length of the coloumn -> the number fo jets
            
            //veto jets that are close together:
            bool veto = false;            
            for(int j=0; j<(*jet_pT).size(); j++) {
                if(ijet==j) continue;
                //	if((*jet_overlap_electron)[j]==1) continue;
                if( DeltaR( (*jet_eta)[ijet], (*jet_phi)[ijet], (*jet_eta)[j], (*jet_phi)[j]) <0.8) {
                    veto=true;
                }
            }
            
            if(veto) continue;
            
            //label the jet, based on any heavy hadron inside:
            std::pair<int, int> labels = Label( (*jet_eta)[ijet], (*jet_phi)[ijet], (*jet_MV2c20)[ijet]);
            
            const int label =  labels.first;   //flavour (5,4,0) based on hadron
            const int hlabel = labels.second; //pdg id of hadron
            
            //and only jets with one match:
            if( bh.size()>1 || ch.size()>1 ) continue;
            
            // Load properties of jet
            const float mv = (*jet_MV2c20)[ijet];
            const float PT = (*jet_pT)[ijet];
            const float eta = (*jet_eta)[ijet];
            const float phi = (*jet_phi)[ijet];
	    float pt_ratio = 0;
	    float h_pt;
	    float h_location;

	    // Load properties of hadron
	    if (bh.size()>0){
	    h_pt = (*mchfpart_pt)[bh.at(0)];
            pt_ratio = h_pt/PT;
	    float h_eta = (*mchfpart_eta)[bh.at(0)];
	    float h_phi = (*mchfpart_phi)[bh.at(0)];

	    // Find distance of hadron from jet centre
	    h_location = DeltaR( eta, phi, h_eta, h_phi);
	    }
	    
            inside_pTAllB.push_back(PT);
            inside_etaAllB.push_back(eta);
            
            //Iterate total number of jets if label hadron matches one being examined, and number of tagged jets if MV2C20 above cut.
            //LABLED JETS
            if (hlabel == hadron_number) {
               
                pTAllB_labeled.push_back(PT);
                etaAllB_labeled.push_back(eta);
                
                if (mv>-0.7887) {
                    pTAllB_tagged_low.push_back(PT);
                    etaAllB_tagged_low.push_back(eta);
                    
                }
                if (mv>0.4496) {
                    pTAllB_tagged_high.push_back(PT);
                    etaAllB_tagged_high.push_back(eta);
                }
                
                plotMV2C20->Fill(mv);
                
                //Used to figure out the limits of the different plots.
                maxPt = (PT > maxPt) ? PT : maxPt;
                minPt = (PT < minPt) ? PT : minPt;
                
                maxEta = (eta > maxEta) ? eta : maxEta;
                minEta = (eta < minEta) ? eta : minEta;
                
                maxPhi = (phi > maxPhi) ? phi : maxPhi;
                minPhi = (phi < minPhi) ? phi : minPhi;
                
		// maxh_loc = (h_location > maxh_loc) ? h_location : maxh_loc;
		//minh_loc = (h_location < minh_loc) ? h_location : minh_loc;
                
                plot_pt_labled->Fill(PT);
                plot_eta_labled->Fill(eta);
                plot_phi_labled->Fill(phi);
                plot_pt_ratio_labled->Fill(pt_ratio);
		//plot_h_location->Fill(h_location);
                
                total_jets++;
                
                Hadron_count_map[hadron_number]=total_jets;
                
                //LABLED AND TAGGED JETS
                if (mv > mv_value) {
                    tagged_jets++;
                    
                    plot_pt_labled_tagged->Fill(PT);
                    plot_eta_labled_tagged->Fill(eta);
                    plot_phi_labled_tagged->Fill(phi);
                    plot_pt_ratio_labled_tagged->Fill(pt_ratio);
		    plot_h_location->Fill(h_location);
                    
                }
                
                if (mv>-0.7887) {
                    int currentValue_low = Hadron_count_map_tagged_low[hadron_number];
                    Hadron_count_map_tagged_low[hadron_number] = currentValue_low+=1;
                }
                if (mv>0.4496) {
                    int currentValue_high = Hadron_count_map_tagged_high[hadron_number];
                    Hadron_count_map_tagged_high[hadron_number] = currentValue_high+=1;
                }
            }
        }
        
    }
    
    ///Writing an output file for MV2C20 Analysis
    ///Over all MV2C20 values for B and C-Hadrons in file utils.h
    ofstream MV2C20Info;
    if (first_time_title) {
        MV2C20Info.open("MV2C20Analysis "+hadron_type+".txt");
        
        if (MV2C20Info.fail()) {
            cout<<"Could not open MV2C20Analysis.txt"<<endl;
            exit(1);
        }
        
        MV2C20Info<<"MV2C20Analysis "+hadron_type<<endl;
        MV2C20Info<<""<<endl;
        first_time_title = false;
    }
    else {
        if (loop_hadron) {
            MV2C20Info.open("MV2C20Analysis "+hadron_type+".txt", std::ios::app);
            MV2C20Info<<""<<endl;
            MV2C20Info<<"Looping over hadron "<<hadron_number<<endl;
            MV2C20Info<<"Total number of "<<hadron_number<<" looped over, Labled_jets: "<<total_jets<<endl;
            loop_hadron = false;
        }
        else {
            MV2C20Info.open("MV2C20Analysis "+hadron_type+".txt", std::ios::app);
            MV2C20Info<<"MV2C20 value: "<<mv_value<<"\t"<<"Tagged_Labled_jets/Labled_jets: "<<tagged_jets/total_jets<<endl;
        }
    }
    
    TH1F *h1b_prop = new TH1F("h1b_prop", "Proportions of Tagged and Jets - Generator " + generator + " - MV2C20 Cut " + Form("%f", tag[cut_pos]), 1, 0, 1);
    h1b_prop->SetBinContent(1, tagged_jets/total_jets);
    
    ///USE "UPDATE" to append histograms to the output file
    
    if (write) {
        TFile * output_file = (hadron_type=="B") ? new TFile("output_plots_B_HADRONS.root", "UPDATE") : new TFile("output_plots_C_HADRONS.root", "UPDATE");
        
        output_file->cd();
        
        plotMV2C20->Write();
        
        plot_pt_labled->Write();
        plot_pt_labled_tagged->Write();
        
        plot_eta_labled->Write();
        plot_eta_labled_tagged->Write();
        
        plot_pt_ratio_labled->Write();
        plot_pt_ratio_labled_tagged->Write();

	plot_h_location->Write();
        
        output_file->Close();
    }
    
    pTAllB = inside_pTAllB;
    etaAllB = inside_etaAllB;
}

void simple_tag_proportions::plot_all_properties() {
    
    TH1 * B_all_pt_labeled = MakePlot(hadron_type+"_ALL_PT_L", 100, 0, 1000);
    TH1 * B_all_eta_labeled = MakePlot(hadron_type+"_ALL_ETA_L", 100, -3, 3);
    
    TH1 * B_all_pt_tagged_low = MakePlot(hadron_type+"_ALL_PT_LT_-0.7887", 100, 0, 1000);
    TH1 * B_all_eta_tagged_low = MakePlot(hadron_type+"_ALL_ETA_LT_-0.7887", 100, -3, 3);
    TH1 * B_all_pt_tagged_high = MakePlot(hadron_type+"_ALL_PT_LT_0.4496", 100, 0, 1000);
    TH1 * B_all_eta_tagged_high = MakePlot(hadron_type+"_ALL_ETA_LT_0.4496", 100, -3, 3);
    
    for (float pt: pTAllB_labeled) {
        B_all_pt_labeled->Fill(pt);
    }
    for (float eta: etaAllB_labeled) {
        B_all_eta_labeled->Fill(eta);
    }
    for (float pt: pTAllB_tagged_low) {
        B_all_pt_tagged_low->Fill(pt);
    }
    for (float eta: etaAllB_tagged_low) {
        B_all_eta_tagged_low->Fill(eta);
    }
    for (float pt: pTAllB_tagged_high) {
        B_all_pt_tagged_high->Fill(pt);
    }
    for (float eta: etaAllB_tagged_high) {
        B_all_eta_tagged_high->Fill(eta);
    }
    
    TFile * output_file_all = (hadron_type=="B") ? new TFile("output_plots_all_B.root", "UPDATE") : new TFile("output_plots_all_C.root", "UPDATE");
    
    output_file_all->cd();
    
    B_all_pt_labeled->Write();
    B_all_eta_labeled->Write();
    
    B_all_pt_tagged_low->Write();
    B_all_eta_tagged_low->Write();
    B_all_pt_tagged_high->Write();
    B_all_eta_tagged_high->Write();
    
    output_file_all->Close();
}

void simple_tag_proportions::hadron_count_plot() {
    std::vector<float> totalHadrons;
    std::vector<float> totalHadrons_tagged_low;
    std::vector<float> totalHadrons_tagged_high;
    
    int counterTest = 1;
    
    if (hadron_type=="B") {
        for (float hadron: b_hadrons) {
            int value = Hadron_count_map[hadron];
            int value_low = Hadron_count_map_tagged_low[hadron];
            int value_high = Hadron_count_map_tagged_high[hadron];
            
            for (int i=0; i<(value+1); i++) {
                totalHadrons.push_back(counterTest);
            }
            for (int i=0; i<(value_low+1); i++) {
                totalHadrons_tagged_low.push_back(counterTest);
            }
            for (int i=0; i<(value_high+1); i++) {
                totalHadrons_tagged_high.push_back(counterTest);
            }
            
            counterTest+=1;
        }
    }
    else {
        for (float hadron: c_hadrons) {
            int value = Hadron_count_map[hadron];
            int value_low = Hadron_count_map_tagged_low[hadron];
            int value_high = Hadron_count_map_tagged_high[hadron];
            
            for (int i=0; i<(value+1); i++) {
                totalHadrons.push_back(counterTest);
            }
            for (int i=0; i<(value_low+1); i++) {
                totalHadrons_tagged_low.push_back(counterTest);
            }
            for (int i=0; i<(value_high+1); i++) {
                totalHadrons_tagged_high.push_back(counterTest);
            }
            
            counterTest+=1;
        }
    }
    
    float b_hadrons_bins[11] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5};
    float c_hadrons_bins[8] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5};
    
    TH1 * Hadron_count_plot;
    TH1 * Hadron_count_plot_tagged_low;
    TH1 * Hadron_count_plot_tagged_high;
    
    if (hadron_type=="B") {
        Hadron_count_plot = new TH1F("B_Hadron_count", "B_Hadron_count", 10, b_hadrons_bins);
        Hadron_count_plot_tagged_low = new TH1F("B_Hadron_count_mv_low", "B_Hadron_count_mv_low", 10, b_hadrons_bins);
        Hadron_count_plot_tagged_high = new TH1F("B_Hadron_count_mv_high", "B_Hadron_count_mv_high", 10, b_hadrons_bins);
        
        std::vector<TH1*> count_plot_vector;
        count_plot_vector.push_back(Hadron_count_plot);
        count_plot_vector.push_back(Hadron_count_plot_tagged_low);
        count_plot_vector.push_back(Hadron_count_plot_tagged_high);
        
        for (TH1* count_plot: count_plot_vector) {
            auto counter = 1;
            for (int hadron: b_hadrons) {
                char const *pchar = std::to_string(hadron).c_str();
                count_plot->GetXaxis()->SetBinLabel(counter, pchar);
                counter+=1;
            }
        }
        
    }
    else {
        Hadron_count_plot = new TH1F("C_Hadron_count", "C_Hadron_count", 7, c_hadrons_bins);
        Hadron_count_plot_tagged_low = new TH1F("C_Hadron_count_mv_low", "C_Hadron_count_mv_low", 7, c_hadrons_bins);
        Hadron_count_plot_tagged_high = new TH1F("C_Hadron_count_mv_high", "C_Hadron_count_mv_high", 7, c_hadrons_bins);
        
        std::vector<TH1*> count_plot_vector;
        count_plot_vector.push_back(Hadron_count_plot);
        count_plot_vector.push_back(Hadron_count_plot_tagged_low);
        count_plot_vector.push_back(Hadron_count_plot_tagged_high);
        
        for (TH1* count_plot: count_plot_vector) {
            auto counter = 1;
            for (int hadron: c_hadrons) {
                char const *pchar = std::to_string(hadron).c_str();
                count_plot->GetXaxis()->SetBinLabel(counter, pchar);
                counter+=1;
            }
        }
        
    }
    
    TFile * output_file_count = (hadron_type=="B") ? new TFile("output_plots_count_B.root", "UPDATE") : new TFile("output_plots_count_C.root", "UPDATE");
    
    for (float f: totalHadrons) {
        Hadron_count_plot->Fill(f);
    }
    for (float f: totalHadrons_tagged_low) {
        Hadron_count_plot_tagged_low->Fill(f);
    }
    for (float f: totalHadrons_tagged_high) {
        Hadron_count_plot_tagged_high->Fill(f);
    }
    
    output_file_count->cd();
    Hadron_count_plot->Write();
    Hadron_count_plot_tagged_low->Write();
    Hadron_count_plot_tagged_high->Write();
    output_file_count->Close();
}
