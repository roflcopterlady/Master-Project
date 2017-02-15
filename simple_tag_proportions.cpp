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

int hadronCounter = 1;

//Vector for properties of entier family

bool onceMV = true;

//Geting the correct limits
float maxPt = std::numeric_limits<float>::min();
float minPt = std::numeric_limits<float>::max();
float maxEta = std::numeric_limits<float>::min();
float minEta = std::numeric_limits<float>::max();
float maxPhi = std::numeric_limits<float>::min();
float minPhi = std::numeric_limits<float>::max();
float maxDr = std::numeric_limits<float>::min();
float minDr = std::numeric_limits<float>::max();

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
    
    ///when using output.root remember that branch name was changed 20->10
    
    sample = "output.root"; //187005";
    if(argc>1) sample = argv[1];
    cout<<"Using sample "<<sample<<endl;
    simple_tag_proportions * a = new simple_tag_proportions(sample);
    
    //cut_pos used to pick the different MV2C20 values from the file: utils.h
    ///GO UP TO i=10 to plot over all B-Hadrons
    
    int numberOfHadrons = (hadron_type=="B") ? 10 : 7;
    
    cout<<hadron_type<<"_"<<numberOfHadrons<<endl;
    
    a->Loop(true);
    
    delete a;
    return 1;
}

//Loop over events
void simple_tag_proportions::Loop(bool write) {
    
    std::vector<float> inside_pTAllB;
    std::vector<float> inside_etaAllB;
    
    std::vector<TH1 *> B_PT_labeled_hadrons;
    std::vector<TH1 *> B_PT_tagged_hadrons_low;
    std::vector<TH1 *> B_PT_tagged_hadrons_high;
    
    for (float hadron: b_hadrons) {
        B_PT_labeled_hadrons.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_"+"PT"+"_"+"L", 100, 0, 1000));
        B_PT_tagged_hadrons_low.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_"+"PT"+"_"+"LT_MV:-0.7887", 100, 0, 1000));
        B_PT_tagged_hadrons_high.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_"+"PT"+"_"+"LT_MV:0.4496", 100, 0, 1000));
    }
    
    std::vector<TH1 *> B_ETA_labeled_hadrons;
    std::vector<TH1 *> B_ETA_tagged_hadrons_low;
    std::vector<TH1 *> B_ETA_tagged_hadrons_high;
    
    for (float hadron: b_hadrons) {
        B_ETA_labeled_hadrons.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_"+"ETA"+"_"+"L", 100, -3, 3));
        B_ETA_tagged_hadrons_low.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_"+"ETA"+"_"+"LT_MV:-0.7887", 100, -3, 3));
        B_ETA_tagged_hadrons_high.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_"+"ETA"+"_"+"LT_MV:0.4496", 100, -3, 3));
    }
    
    TH1 * B_all_PT_labeled = MakePlot(hadron_type+"_ALL_PT_L_", 100, 0, 1000);
    TH1 * B_all_PT_tagged_low = MakePlot(hadron_type+"_ALL_PT_LT_-0.7887", 100, 0, 1000);
    TH1 * B_all_PT_tagged_high = MakePlot(hadron_type+"_ALL_PT_LT_0.4496", 100, 0, 1000);
    
    TH1 * B_all_ETA_labeled = MakePlot(hadron_type+"_ALL_ETA_L_", 100, -3, 3);
    TH1 * B_all_ETA_tagged_low = MakePlot(hadron_type+"_ALL_ETA_LT_-0.7887", 100, -3, 3);
    TH1 * B_all_ETA_tagged_high = MakePlot(hadron_type+"_ALL_ETA_LT_0.4496", 100, -3, 3);
    
    float b_hadrons_bins[11] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5};
    TH1 * Hadron_count_plot = new TH1F("B_Hadron_count", "B_Hadron_count", 10, b_hadrons_bins);
    TH1 * Hadron_count_plot_tagged_low = new TH1F("B_Hadron_count_mv_low", "B_Hadron_count_mv_low", 10, b_hadrons_bins);
    TH1 * Hadron_count_plot_tagged_high = new TH1F("B_Hadron_count_mv_high", "B_Hadron_count_mv_high", 10, b_hadrons_bins);
    
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
    
    TH1 * B_ratio_labeled = MakePlot("B_Ratio_L", 100, 0, 1);
    TH1 * B_ratio_labeled_tagged_low = MakePlot("B_LT_low", 100, 0, 1);
    TH1 * B_ratio_labeled_tagged_high = MakePlot("B_LT_high", 100, 0, 1);
    
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
    // Histograms for separation between jets and nearest hadrons (Filled by Label method, so must be initialised here)
    ///WHY DOES THIS HAVE TO BE HERE!
    h_bdR_min = MakePlot("h_b_jet_closest_b_hadron", 50, 0, 2);
    h_bdR_next = MakePlot("h_b_jet_next_closest_b_hadron", 50, 0, 2);
    h_cdR_min = MakePlot("h_c_jet_closest_b_hadron", 50, 0, 2);
    h_cdRc_min = MakePlot("h_c_jet_closest_c_hadron", 50, 0, 2);
    
    
    ///Plot naming convention
    //HadronFamily_HadronNumber_Property_Labelled/LabelledAndTagged_MV2C20Value
    //HadronFamily:                 B or C
    //HadronNumber:                 Check utils.hpp
    //Property:                     PT or ETA or DR
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
            float dR;
            
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
            if( bh.size()>1 || ch.size()>1) continue;
            
            // Load properties of jet
            const float mv = (*jet_MV2c20)[ijet];
            const float PT = (*jet_pT)[ijet];
            const float eta = (*jet_eta)[ijet];
            const float phi = (*jet_phi)[ijet];
            float pt_ratio = 0;
            float h_pt;
            
            maxPt = (PT > maxPt) ? PT : maxPt;
            minPt = (PT < minPt) ? PT : minPt;
            
            maxEta = (eta > maxEta) ? eta : maxEta;
            minEta = (eta < minEta) ? eta : minEta;
            
            maxDr = (dR > maxDr) ? dR : maxDr;
            maxDr = (dR < minDr) ? dR : minDr;
            
            
            if (bh.size()>0) {
                h_pt = (*mchfpart_pt)[bh.at(0)];
                pt_ratio = h_pt/PT;
            }
            
            inside_pTAllB.push_back(PT);
            inside_etaAllB.push_back(eta);
            
            //Iterate total number of jets if label hadron matches one being examined, and number of tagged jets if MV2C20 above cut.
            //LABLED JETS
            
            bool contains = false;
            for (float number: b_hadrons) {
                if (number==hlabel) {
                    contains = true;
                }
            }
            
            if (contains) {
                
                int index = find(b_hadrons.begin(), b_hadrons.end(), hlabel) - b_hadrons.begin();
                
                B_all_PT_labeled->Fill(PT);
                B_all_ETA_labeled->Fill(eta);
                Hadron_count_plot->Fill(index);
                B_ratio_labeled->Fill(pt_ratio);
                
                B_PT_labeled_hadrons[index]->Fill(PT);
                B_ETA_labeled_hadrons[index]->Fill(eta);
                
                if (mv>-0.7887) {
                    B_all_PT_tagged_low->Fill(PT);
                    B_all_ETA_tagged_low->Fill(eta);
                    
                    B_PT_tagged_hadrons_low[index]->Fill(PT);
                    B_ETA_tagged_hadrons_low[index]->Fill(eta);
                    
                    Hadron_count_plot_tagged_low->Fill(index);
                    
                    B_ratio_labeled_tagged_low->Fill(pt_ratio);
                }
                if (mv>0.4496) {
                    B_all_PT_tagged_high->Fill(PT);
                    B_all_ETA_tagged_high->Fill(eta);
                    
                    B_PT_tagged_hadrons_high[index]->Fill(PT);
                    B_ETA_tagged_hadrons_high[index]->Fill(eta);
                    
                    Hadron_count_plot_tagged_high->Fill(index);
                    
                    B_ratio_labeled_tagged_high->Fill(pt_ratio);
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
        TFile * output_file = (hadron_type=="B") ? new TFile("output_plots_B_HADRONS.root", "RECREATE") : new TFile("output_plots_C_HADRONS.root", "RECREATE");
        
        output_file->cd();
        
        for (int i=0; i<b_hadrons.size(); i++) {
            B_PT_labeled_hadrons[i]->Write();
            B_PT_tagged_hadrons_low[i]->Write();
            B_PT_tagged_hadrons_high[i]->Write();
            
            B_ETA_labeled_hadrons[i]->Write();
            B_ETA_tagged_hadrons_low[i]->Write();
            B_ETA_tagged_hadrons_high[i]->Write();
        }
        
        output_file->Close();
        
        TFile * output_file_all = (hadron_type=="B") ? new TFile("output_plots_all_B.root", "RECREATE") : new TFile("output_plots_all_C.root", "RECREATE");
        
        output_file_all->cd();
        
        B_all_PT_labeled->Write();
        B_all_PT_tagged_low->Write();
        B_all_PT_tagged_high->Write();
        
        B_all_ETA_labeled->Write();
        B_all_ETA_tagged_low->Write();
        B_all_ETA_tagged_high->Write();
        
        output_file_all->Close();
        
        TFile * output_file_count = (hadron_type=="B") ? new TFile("output_plots_count_B.root", "RECREATE") : new TFile("output_plots_count_C.root", "RECREATE");

        output_file_count->cd();
        
        Hadron_count_plot->Write();
        Hadron_count_plot_tagged_low->Write();
        Hadron_count_plot_tagged_high->Write();
        
        output_file_count->Close();
        
        TFile * output_file_ratio = (hadron_type=="B") ? new TFile("output_plots_ratio_B.root", "RECREATE") : new TFile("output_plots_ratio_C.root", "RECREATE");
        
        output_file_ratio->cd();
        
        B_ratio_labeled->Write();
        B_ratio_labeled_tagged_low->Write();
        B_ratio_labeled_tagged_high->Write();
        
        output_file_ratio->Close();
    }

}
