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

string sample = "powheg2.root";

int cut_pos;

int hadron_number;
float mv_value;

bool first_time_title = true;
bool loop_hadron = true;

string hadron_type = "B";

int hadronCounter = 1;

std::map<float,int> B_hadron_count;

//Vector for properties of entier family

bool onceMV = true;

//Geting the correct limits
float maxPt = std::numeric_limits<float>::min();
float minPt = std::numeric_limits<float>::max();
float maxEta = std::numeric_limits<float>::min();
float minEta = std::numeric_limits<float>::max();
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
    
    if(argc>1) sample = argv[1];
    cout<<"Using sample "<<sample<<endl;
    simple_tag_proportions * a = new simple_tag_proportions(sample);
    
    //cut_pos used to pick the different MV2C20 values from the file: utils.h
    ///GO UP TO i=10 to plot over all B-Hadrons
    
    cout<<"Hadron Type: "+hadron_type<<endl;
    
    a->Loop(true);
    
    delete a;
    return 1;
}

//Loop over events
void simple_tag_proportions::Loop(bool write) {
    
    std::vector<float> inside_pTAllB;
    std::vector<float> inside_etaAllB;
    
    std::vector<TH1 *> H_PT_labeled_hadrons;
    std::vector<TH1 *> H_PT_tagged_hadrons_low;
    std::vector<TH1 *> H_PT_tagged_hadrons_high;
    
    std::vector<TH1 *> H_PT_RATIO_labeled_hadrons;
    std::vector<TH1 *> H_PT_RATIO_tagged_hadrons_low;
    std::vector<TH1 *> H_PT_RATIO_tagged_hadrons_high;
    
    std::vector<TH1 *> H_ETA_labeled_hadrons;
    std::vector<TH1 *> H_ETA_tagged_hadrons_low;
    std::vector<TH1 *> H_ETA_tagged_hadrons_high;
    
    std::vector<TH1 *> H_LOC_labeled_hadrons;
    std::vector<TH1 *> H_LOC_tagged_hadrons_low;
    std::vector<TH1 *> H_LOC_tagged_hadrons_high;
    
    int hadronArrayLength = (hadron_type=="B") ? b_hadrons.size() : c_hadrons.size();
    
    //    std::vector<float> pt_bins;
    //    for (int i = 0; i<250; i+=10) {
    //        pt_bins.push_back(i);
    //    }
    //    pt_bins.push_back(300);
    //    pt_bins.push_back(400);
    //    pt_bins.push_back(600);
    //    pt_bins.push_back(1000);
    //    int size = pt_bins.size() - 1;
    
    float pt_bins[30] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 300, 400, 600, 1000};
    
    for (int i=0; i<hadronArrayLength; i++) {
        int hadron = (hadron_type=="B") ? b_hadrons[i] : c_hadrons[i];
        
        std::string pt_l_string = hadron_type+"_"+std::to_string(hadron)+"_"+"PT"+"_"+"L";
        std::string pt_lt_low_string = hadron_type+"_"+std::to_string(hadron)+"_"+"ETA"+"_"+"LT_-0.7887";
        std::string pt_lt_high_string = hadron_type+"_"+std::to_string(hadron)+"_"+"ETA"+"_"+"LT_0.4496";
        
        char const * pt_l = pt_l_string.c_str();
        char const * pt_lt_low = pt_lt_low_string.c_str();
        char const * pt_lt_high = pt_lt_high_string.c_str();
        
        TH1* test_pt_l = new TH1F(pt_l, pt_lt_low, 29, pt_bins);
        TH1* test_pt_lt_low = new TH1F(pt_lt_low, pt_lt_low, 29, pt_bins);
        TH1* test_pt_lt_high = new TH1F(pt_lt_high, pt_lt_high, 29, pt_bins);
        
        //        H_PT_labeled_hadrons.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_"+"PT"+"_"+"L", 100, 0, 1000));
        //        H_PT_tagged_hadrons_low.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_"+"PT"+"_"+"LT_-0.7887", 100, 0, 1000));
        //        H_PT_tagged_hadrons_high.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_"+"PT"+"_"+"LT_0.4496", 100, 0, 1000));
        
        H_PT_labeled_hadrons.push_back(test_pt_l);
        H_PT_tagged_hadrons_low.push_back(test_pt_lt_low);
        H_PT_tagged_hadrons_high.push_back(test_pt_lt_high);
        
        H_ETA_labeled_hadrons.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_"+"ETA"+"_"+"L", 100, -3, 3));
        H_ETA_tagged_hadrons_low.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_"+"ETA"+"_"+"LT_-0.7887", 100, -3, 3));
        H_ETA_tagged_hadrons_high.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_"+"ETA"+"_"+"LT_0.4496", 100, -3, 3));
        
        H_PT_RATIO_labeled_hadrons.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_PT_H_VS_J_L", 100, 0, 1));
        H_PT_RATIO_tagged_hadrons_low.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_PT_H_VS_J_LT_-0.7887", 100, 0, 1));
        H_PT_RATIO_tagged_hadrons_high.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_PT_H_VS_J_LT_0.4496", 100, 0, 1));
        
        H_LOC_labeled_hadrons.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_"+"LOC"+"_"+"L", 100, 0, 0.5));
        H_LOC_tagged_hadrons_low.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_"+"LOC"+"_"+"LT_-0.7887", 100, 0, 0.5));
        H_LOC_tagged_hadrons_high.push_back(MakePlot(hadron_type+"_"+std::to_string(hadron)+"_"+"LOC"+"_"+"LT_0.4496", 100, 0, 0.5));
    }
    
    TH1* test_pt_l_all = new TH1F("test_pt_l_all", "test_pt_l_all", 29, pt_bins);
    TH1* test_pt_lt_low_all = new TH1F("test_pt_lt_low_all", "test_pt_lt_low_all", 29, pt_bins);
    TH1* test_pt_lt_high_all = new TH1F("test_pt_lt_high_all", "test_pt_lt_high_all", 29, pt_bins);
    
    test_pt_l_all->Sumw2();
    test_pt_lt_low_all->Sumw2();
    test_pt_lt_high_all->Sumw2();
    
    //    TH1 * H_all_PT_labeled = MakePlot(hadron_type+"_ALL_PT_L", 100, 0, 1000);
    //    TH1 * H_all_PT_tagged_low = MakePlot(hadron_type+"_ALL_PT_LT_-0.7887", 100, 0, 1000);
    //    TH1 * H_all_PT_tagged_high = MakePlot(hadron_type+"_ALL_PT_LT_0.4496", 100, 0, 1000);
    
    TH1 * H_all_ETA_labeled = MakePlot(hadron_type+"_ALL_ETA_L", 100, -3, 3);
    TH1 * H_all_ETA_tagged_low = MakePlot(hadron_type+"_ALL_ETA_LT_-0.7887", 100, -3, 3);
    TH1 * H_all_ETA_tagged_high = MakePlot(hadron_type+"_ALL_ETA_LT_0.4496", 100, -3, 3);
    
    TH1 * H_all_HLOC_labeled = MakePlot(hadron_type+"_ALL_HLOC_L", 100, 0, 0.5);
    TH1 * H_all_HLOC_tagged_low = MakePlot(hadron_type+"_ALL_HLOC_LT_-0.7887", 100, 0, 0.5);
    TH1 * H_all_HLOC_tagged_high = MakePlot(hadron_type+"_ALL_HLOC_LT_0.4496", 100, 0, 0.5);
    
    ///HADRON PRODUCTION RATE ************************
    ///************************
    ///************************
    
    TH1 * H_count_plot;
    TH1 * H_count_plot_tagged_low;
    TH1 * H_count_plot_tagged_high;
    
    if (hadron_type=="B") {
        
        H_count_plot = new TH1F("B_PR_L", "B_PR_L", 10, -0.5, 9.5);
        H_count_plot_tagged_low = new TH1F("B_PR_LT_-0.7887", "B_PR_LT_-0.7887", 10, -0.5, 9.5);
        H_count_plot_tagged_high = new TH1F("B_PR_LT_0.4496", "B_PR_LT_0.4496", 10, -0.5, 9.5);
        
        std::vector<TH1*> count_plot_vector;
        count_plot_vector.push_back(H_count_plot);
        count_plot_vector.push_back(H_count_plot_tagged_low);
        count_plot_vector.push_back(H_count_plot_tagged_high);
        
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
        // float c_hadrons_bins[8] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5};
        H_count_plot = new TH1F("C_PR_L", "C_PR_L", 10, -0.5, 6.5);
        H_count_plot_tagged_low = new TH1F("C_PR_LT_-0.7887", "C_PR_LT_-0.7887", 10, -0.5, 6.5);
        H_count_plot_tagged_high = new TH1F("C_PR_LT_0.4496", "C_PR_LT_0.4496", 10, -0.5, 6.5);
        
        std::vector<TH1*> count_plot_vector;
        count_plot_vector.push_back(H_count_plot);
        count_plot_vector.push_back(H_count_plot_tagged_low);
        count_plot_vector.push_back(H_count_plot_tagged_high);
        
        for (TH1* count_plot: count_plot_vector) {
            auto counter = 1;
            for (int hadron: c_hadrons) {
                char const *pchar = std::to_string(hadron).c_str();
                count_plot->GetXaxis()->SetBinLabel(counter, pchar);
                counter+=1;
            }
        }
    }
    
    ///HADRON PRODUCTION RATE ************************
    ///************************
    ///************************
    
    TH1 * H_ratio_labeled = MakePlot(hadron_type+"_PT_H_VS_J_L", 100, 0, 1);
    TH1 * H_ratio_labeled_tagged_low = MakePlot(hadron_type+"_PT_H_VS_J_LT_-0.7887", 100, 0, 1);
    TH1 * H_ratio_labeled_tagged_high = MakePlot(hadron_type+"_PT_H_VS_J_LT_0.4496", 100, 0, 1);
    
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
            if( bh.size() == 0 || ch.size() == 0 ) continue;
            
            // Load properties of jet
            const float mv = (*jet_MV2c20)[ijet];
            const float PT = (*jet_pT)[ijet];
            const float eta = (*jet_eta)[ijet];
            const float phi = (*jet_phi)[ijet];
            float pt_ratio = 0;
            float h_pt;
            float h_location;
            
            maxPt = (PT > maxPt) ? PT : maxPt;
            minPt = (PT < minPt) ? PT : minPt;
            
            maxEta = (eta > maxEta) ? eta : maxEta;
            minEta = (eta < minEta) ? eta : minEta;
            
            maxDr = (h_location > maxDr) ? h_location : maxDr;
            minDr = (h_location < minDr) ? h_location : minDr;
            
            int sizeArray = (hadron_type=="B") ? bh.size() : ch.size();
            
            if (sizeArray>0) {
                int indexValue = (hadron_type=="B") ? bh.at(0) : ch.at(0);
                h_pt = (*mchfpart_pt)[indexValue];
                pt_ratio = h_pt/PT;
                
                float h_eta = (*mchfpart_eta)[indexValue];
                float h_phi = (*mchfpart_phi)[indexValue];
                h_location = hLoc( eta, phi, h_eta, h_phi);
            }
            
            //Iterate total number of jets if label hadron matches one being examined, and number of tagged jets if MV2C20 above cut.
            //LABLED JETS
            
            //cout<<hlabel<<endl;
            
            bool contains = false;
            if (hadron_type=="B") {
                for (float number: b_hadrons) {
                    if (number==hlabel) {
                        contains = true;
                    }
                }
            }
            else {
                for (float number: c_hadrons) {
                    if (number==hlabel) {
                        contains = true;
                    }
                }
            }
            
            if (contains) {
                
                int index = -1;
                
                if (hadron_type=="B") {
                    
                    index = find(b_hadrons.begin(), b_hadrons.end(), hlabel) - b_hadrons.begin();
                    
                    cout<<"hadron: "<<hlabel<<" index: "<<index<<endl;
                }
                else {
                    index = find(c_hadrons.begin(), c_hadrons.end(), hlabel) - c_hadrons.begin();
                    
                }
                
                // cout<<index<<" Hlabel: "<<hlabel<<endl;
                
                test_pt_l_all->Fill(PT);
                H_all_ETA_labeled->Fill(eta);
                H_all_HLOC_labeled->Fill(h_location);
                H_count_plot->Fill(index);
                H_ratio_labeled->Fill(pt_ratio);
                
                H_PT_labeled_hadrons[index]->Fill(PT);
                H_ETA_labeled_hadrons[index]->Fill(eta);
                H_PT_RATIO_labeled_hadrons[index]->Fill(pt_ratio);
                H_LOC_labeled_hadrons[index]->Fill(h_location);
                
                if (mv>-0.7887) {
                    test_pt_lt_low_all->Fill(PT);
                    H_all_ETA_tagged_low->Fill(eta);
                    H_all_HLOC_tagged_low->Fill(h_location);
                    
                    H_PT_tagged_hadrons_low[index]->Fill(PT);
                    H_ETA_tagged_hadrons_low[index]->Fill(eta);
                    H_PT_RATIO_tagged_hadrons_low[index]->Fill(pt_ratio);
                    H_LOC_tagged_hadrons_low[index]->Fill(h_location);
                    
                    H_count_plot_tagged_low->Fill(index);
                    H_ratio_labeled_tagged_low->Fill(pt_ratio);
                    
                }
                if (mv>0.4496) {
                    test_pt_lt_high_all->Fill(PT);
                    H_all_ETA_tagged_high->Fill(eta);
                    H_all_HLOC_tagged_high->Fill(h_location);
                    
                    H_PT_tagged_hadrons_high[index]->Fill(PT);
                    H_ETA_tagged_hadrons_high[index]->Fill(eta);
                    H_PT_RATIO_tagged_hadrons_high[index]->Fill(pt_ratio);
                    H_LOC_tagged_hadrons_high[index]->Fill(h_location);
                    
                    H_count_plot_tagged_high->Fill(index);
                    H_ratio_labeled_tagged_high->Fill(pt_ratio);
                    
                }
            }
            
        }
    }
    
    TH1 * H_EFF_ALL_PT_LOW = simple_tag_proportions::getEffPlot(test_pt_lt_low_all, test_pt_l_all, hadron_type+"_EFF_ALL_PT_LT_-0.7887");
    TH1 * H_EFF_ALL_PT_HIGH = simple_tag_proportions::getEffPlot(test_pt_lt_high_all, test_pt_l_all, hadron_type+"_EFF_ALL_PT_LT_0.4496");
    
    TH1 * H_EFF_ALL_ETA_LOW = simple_tag_proportions::getEffPlot(H_all_ETA_tagged_low, H_all_ETA_labeled, hadron_type+"_EFF_ALL_ETA_LT_-0.7887");
    TH1 * H_EFF_ALL_ETA_HIGH = simple_tag_proportions::getEffPlot(H_all_ETA_tagged_high, H_all_ETA_labeled, hadron_type+"_EFF_ALL_ETA_LT_0.4496");
    
    TH1 * H_EFF_ALL_HLOC_LOW = simple_tag_proportions::getEffPlot(H_all_HLOC_tagged_low, H_all_HLOC_labeled, hadron_type+"_EFF_ALL_HLOC_LT_-0.7887");
    TH1 * H_EFF_ALL_HLOC_HIGH = simple_tag_proportions::getEffPlot(H_all_HLOC_tagged_high, H_all_HLOC_labeled, hadron_type+"_EFF_ALL_HLOC_LT_0.4496");
    
    TH1 * H_EFF_ALL_PT_H_VS_J_LOW = simple_tag_proportions::getEffPlot(H_ratio_labeled_tagged_low, H_ratio_labeled, hadron_type+"_EFF_ALL_PT_H_VS_J_LT_-0.7887");
    TH1 * H_EFF_ALL_PT_H_VS_J_HIGH = simple_tag_proportions::getEffPlot(H_ratio_labeled_tagged_high, H_ratio_labeled, hadron_type+"_EFF_ALL_PT_H_VS_J_LT_0.4496");
    
    TH1 * H_EFF_ALL_PR_LOW = simple_tag_proportions::getEffPlot(H_count_plot_tagged_low, H_count_plot, hadron_type+"EFF_ALL_PR_LT_-0.7887");
    TH1 * H_EFF_ALL_PR_HIGH = simple_tag_proportions::getEffPlot(H_count_plot_tagged_high, H_count_plot, hadron_type+"EFF_ALL_PR_LT_0.4496");
    
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
    
    // char const *outputChar = std::to_string(sample).c_str();
    string outputIndividualString = sample+"_"+hadron_type+"_individual.root";
    string outputAllString = sample+"_"+hadron_type+"_all.root";
    string outputCountString = sample+"_"+hadron_type+"_count.root";
    string outputRatioString = sample+"_"+hadron_type+"_hPT_vs_jPT.root";
    string outputHLocString = sample+"_"+hadron_type+"_hloc.root";
    string effPlotsString = sample+"_"+hadron_type+"_all_EffPlots.root";
    
    char const *outputIndividual = outputIndividualString.c_str();
    char const *outputAll = outputAllString.c_str();
    char const *outputCount = outputCountString.c_str();
    char const *outputRatio = outputRatioString.c_str();
    char const *effPlots = effPlotsString.c_str();
    
    if (write) {
        TFile * output_file = (hadron_type=="B") ? new TFile(outputIndividual, "RECREATE") : new TFile(outputIndividual, "RECREATE");
        
        output_file->cd();
        
        int hadronArrayLength = (hadron_type=="B") ? b_hadrons.size() : c_hadrons.size();
        
        for (int i=0; i<hadronArrayLength; i++) {
            H_PT_labeled_hadrons[i]->Write();
            H_PT_tagged_hadrons_low[i]->Write();
            H_PT_tagged_hadrons_high[i]->Write();
            
            H_ETA_labeled_hadrons[i]->Write();
            H_ETA_tagged_hadrons_low[i]->Write();
            H_ETA_tagged_hadrons_high[i]->Write();
            
            H_PT_RATIO_labeled_hadrons[i]->Write();
            H_PT_RATIO_tagged_hadrons_low[i]->Write();
            H_PT_RATIO_tagged_hadrons_high[i]->Write();
            
            H_LOC_labeled_hadrons[i]->Write();
            H_LOC_tagged_hadrons_low[i]->Write();
            H_LOC_tagged_hadrons_high[i]->Write();
        }
        
        output_file->Close();
        
        TFile * output_file_all = (hadron_type=="B") ? new TFile(outputAll, "RECREATE") : new TFile(outputAll, "RECREATE");
        
        output_file_all->cd();
        
        test_pt_l_all->Write();
        test_pt_lt_low_all->Write();
        test_pt_lt_high_all->Write();
        
        H_all_ETA_labeled->Write();
        H_all_ETA_tagged_low->Write();
        H_all_ETA_tagged_high->Write();
        
        H_ratio_labeled->Write();
        H_ratio_labeled_tagged_low->Write();
        H_ratio_labeled_tagged_high->Write();
        
        H_all_HLOC_labeled->Write();
        H_all_HLOC_tagged_low->Write();
        H_all_HLOC_tagged_high->Write();
        
        output_file_all->Close();
        
        TFile * output_file_count = (hadron_type=="B") ? new TFile(outputCount, "RECREATE") : new TFile(outputCount, "RECREATE");
        
        output_file_count->cd();
        
        H_count_plot->Write();
        H_count_plot_tagged_low->Write();
        H_count_plot_tagged_high->Write();
        
        output_file_count->Close();
        
        TFile * eff_plots_file = (hadron_type=="B") ? new TFile(effPlots, "RECREATE") : new TFile(effPlots, "RECREATE");
        
        eff_plots_file->cd();
        
        H_EFF_ALL_PT_LOW->Write();
        H_EFF_ALL_PT_HIGH->Write();
        H_EFF_ALL_ETA_LOW->Write();
        H_EFF_ALL_ETA_HIGH->Write();
        H_EFF_ALL_HLOC_LOW->Write();
        H_EFF_ALL_HLOC_HIGH->Write();
        H_EFF_ALL_PT_H_VS_J_LOW->Write();
        H_EFF_ALL_PT_H_VS_J_HIGH->Write();
        H_EFF_ALL_PR_LOW->Write();
        H_EFF_ALL_PR_HIGH->Write();
        
        eff_plots_file->Close();
    }
}

TH1* simple_tag_proportions::getEffPlot(TH1* plot1, TH1* plot2, TString plotName) {
    
    TH1 * Eff = (TH1F*) plot1->Clone();
    Eff->SetTitle(plotName);
    Eff->SetName(plotName);
    Eff->Divide(plot1,plot2,1,1, "B");
    Eff->SetAxisRange(0, 1, "Y");
    return Eff;
}
