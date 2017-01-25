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

//Vectots to overlay many graphs
std::vector<TH1*> pTVectors;
std::vector<TH1*> etaVectors;
std::vector<TH1*> phiVectors;

//Geting the correct limits
float maxPt = std::numeric_limits<float>::min();
float minPt = std::numeric_limits<float>::max();
float maxEta = std::numeric_limits<float>::min();
float minEta = std::numeric_limits<float>::max();
float maxPhi = std::numeric_limits<float>::min();
float minPhi = std::numeric_limits<float>::max();
float maxDr = std::numeric_limits<float>::min();
float minDr = std::numeric_limits<float>::max();

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
    
    sample = "output.root"; //187005";
    if(argc>1) sample = argv[1];
    cout<<"Using sample "<<sample<<endl;
    simple_tag_proportions * a = new simple_tag_proportions(sample);
    
    //cut_pos used to pick the different MV2C20 values from the file: utils.h
    ///GO UP TO i=10 to plot over all B-Hadrons
    
    int numberOfHadrons = (hadron_type=="B") ? 10 : 7;
    
    cout<<hadron_type<<"_"<<numberOfHadrons<<endl;
    
    for(int i=0; i<numberOfHadrons; i++) {
        
        //Checking which hadron out of total we are on.
        cout<<"\n\n\nOn hadron "<<i+1<<" of "<<10<<"\n\n\n"<<endl;
        
        loop_hadron = true;
        hadron_number = (hadron_type=="B") ? b_hadrons[i] : c_hadrons[i];
        
        for(int k = 0; k < 2; k++) {
            mv_value = tag[k];
            cut_pos = k;
            a->Loop();
        }
    }
    
    cout<<"Limits for "<<hadron_type<<endl;
    cout<<"MaxPt: "<<maxPt<<" MinPt: "<<minPt<<endl;
    cout<<"MaxEta: "<<maxEta<<" MinEta: "<<minEta<<endl;
    cout<<"MaxPhi: "<<maxPhi<<" MinPhi: "<<minPhi<<endl;
    
    cout<<"MaxDr: "<<maxDr<<" MinDr: "<<minDr<<endl;
    
    //Getting the hadron count for TGraph.
    for (float number: countOfB_Hadrons) {
        if (std::find(countOfB_HadronsUseful.begin(), countOfB_HadronsUseful.end(), number) == countOfB_HadronsUseful.end()) {
            countOfB_HadronsUseful.push_back(number);
        }
    }
    
    a->hadronCountPlot(hadron_type);
//    a->overlayNPlots(pTVectors,"PT Labeled");
//    a->overlayNPlots(etaVectors,"eta Labeled");
//    a->overlayNPlots(phiVectors,"phi Labeled");
    
    delete a;
    return 1;
}

//Loop over events
void simple_tag_proportions::Loop() {
    
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
    
    //B-Hadrons
    //MaxPt: 738.415 MinPt: 20.0023
    //MaxEta: 2.49976 MinEta: -2.49958
    //MaxPhi: 3.14155 MinPhi: -3.14154
    
    //C-Hadrons
    //MaxPt: 1293.71 MinPt: 20.0061
    //MaxEta: 2.49911 MinEta: -2.49971
    //MaxPhi: 3.14151 MinPhi: -3.14153
    
    TH1 * plotMV2C20 = MakePlot("plotMV2C20", 50, -1, 1);
    
    TH1 * plot_pt_labled = MakePlot(hadron_type+"_"+std::to_string(hadron_number)+"_"+"PT"+"_"+"L", 100, 0, 1000);
    TH1 * plot_pt_labled_tagged = MakePlot(hadron_type+"_"+std::to_string(hadron_number)+"_"+"PT"+"_"+"LT"+"_"+std::to_string(mv_value), 100, 0, 1000);
    
    TH1 * plot_eta_labled = MakePlot(hadron_type+"_"+std::to_string(hadron_number)+"_"+"ETA"+"_"+"L", 100, -3, 3);
    TH1 * plot_eta_labled_tagged = MakePlot(hadron_type+"_"+std::to_string(hadron_number)+"_"+"ETA"+"_"+"LT"+"_"+std::to_string(mv_value), 100, -3, 3);
    
    TH1 * plot_phi_labled = MakePlot(hadron_type+" - Phi Labeled - Hadron: "+std::to_string(hadron_number)+" MV:"+std::to_string(mv_value), 100, 4, -4);
    TH1 * plot_phi_labled_tagged = MakePlot(hadron_type+" - Phi Labeled and Tagged - Hadron: "+std::to_string(hadron_number)+" MV:"+std::to_string(mv_value), 100, -4, 4);
    
    TH1 * plot_dR_labled = MakePlot(hadron_type+"_"+std::to_string(hadron_number)+"_"+"DR"+"_"+"L", 100, 0, 1);
    TH1 * plot_dR_labled_tagged = MakePlot(hadron_type+"_"+std::to_string(hadron_number)+"_"+"DR"+"_"+"LT"+"_"+std::to_string(mv_value), 100, 0, 1);
    
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
                    dR = DeltaR( (*jet_eta)[ijet], (*jet_phi)[ijet], (*jet_eta)[j], (*jet_phi)[j]);
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
            
            //Iterate total number of jets if label hadron matches one being examined, and number of tagged jets if MV2C20 above cut.
            //LABLED JETS
            if (hlabel == hadron_number) {
                
                plotMV2C20->Fill(mv);
                
                //Used to figure out the limits of the different plots.
                
                maxPt = (PT > maxPt) ? PT : maxPt;
                minPt = (PT < minPt) ? PT : minPt;
                
                maxEta = (eta > maxEta) ? eta : maxEta;
                minEta = (eta < minEta) ? eta : minEta;
                
                maxPhi = (phi > maxPhi) ? phi : maxPhi;
                maxPhi = (phi < minPhi) ? phi : minPhi;
                
                maxDr = (dR > maxDr) ? dR : maxDr;
                maxDr = (dR < minDr) ? dR : minDr;
                
                plot_pt_labled->Fill(PT);
                plot_eta_labled->Fill(eta);
                plot_phi_labled->Fill(phi);
                plot_dR_labled->Fill(dR);
                
                total_jets++;
                
                //LABLED AND TAGGED JETS
                if (mv > mv_value) {
                    tagged_jets++;
                    
                    plot_pt_labled_tagged->Fill(PT);
                    plot_eta_labled_tagged->Fill(eta);
                    plot_phi_labled_tagged->Fill(phi);
                    plot_dR_labled_tagged->Fill(dR);
                    
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
    TFile * output_file = new TFile("output_plots.root", "RECREATE");
    
    output_file->cd();
    
    plotMV2C20->Write();
    
    plot_pt_labled->Write();
    plot_pt_labled_tagged->Write();
    //ratioPlots(plot_pt_labled_tagged, plot_pt_labled, "PT");
    
    plot_eta_labled->Write();
    plot_eta_labled_tagged->Write();
    //ratioPlots(plot_eta_labled_tagged, plot_eta_labled, "Eta");
    
    plot_phi_labled->Write();
    plot_phi_labled_tagged->Write();
    //ratioPlots(plot_phi_labled_tagged, plot_phi_labled, "Phi");
    
    ///Need to modify how the value is created.
//    plot_dR_labled->Write();
//    plot_dR_labled_tagged->Write();
//    ratioPlots(plot_dR_labled_tagged, plot_dR_labled, "DeltaR");
    
    output_file->Close();
    
//    overlayPlots(plot_pt_labled, plot_pt_labled_tagged, "PT");
//    overlayPlots(plot_eta_labled, plot_eta_labled_tagged, "Eta");
//    overlayPlots(plot_phi_labled, plot_phi_labled_tagged, "Phi");
    
    //Getting an array of total jet count.
    countOfB_Hadrons.push_back(tagged_jets);
    
    //Adding plots to approproprite plots
    pTVectors.push_back(plot_pt_labled);
    etaVectors.push_back(plot_eta_labled);
    phiVectors.push_back(plot_phi_labled);
}

//void simple_tag_proportions::overlayNPlots(std::vector<TH1*> plotArray, TString plotname) {
//    
////    system("mkdir MultipleOverlays");
//    
////    std::vector<TH1*> clonePlotArray;
////    
//////    for (TH1* histogram: plotArray) {
//////        TH1* currentClone = (TH1F*) histogram->Clone();
//////        clonePlotArray.push_back(currentClone);
//////    }
////    
////    TH1* firstH = plotArray.at(0);
////    TH1* secondH = plotArray.at(1);
////    
////    TH1 * plot1_c = (TH1F*) firstH->Clone();
////    TH1 * plot2_c = (TH1F*) secondH->Clone();
////    
////    plot1_c->SetTitle(plotName);
////    
////    TLegend * legend = new TLegend(0.8,0.8,1,1, "", "NDC");
////    legend->AddEntry(plot1_c, "Labeled", "LEP");
////    legend->AddEntry(plot2_c, "L' and Tagged", "LEP");
////    
////    TCanvas * c = new TCanvas();
////    
//////    TCanvas * c = new TCanvas();
//////    
////    int colourCounter = 1;
//////
//////    for (TH1* histogram: clonePlotArray) {
//////        
//////        if (colourCounter == 3) {
//////           
//////            histogram->DrawCopy("same");
//////        }
//////        else {
//////             histogram->DrawCopy();
//////        }
//////        
//////        histogram->SetLineColor(colourCounter);
//////        colourCounter+=1;
//////    }
////    
////    firstH->SetLineColor(2);
////    firstH->DrawCopy();
////    secondH->SetLineColor(4);
////    secondH->DrawCopy("same");
////    legend->Draw();
////    
////    TString counter = (TString) colourCounter;
////    
////    c->Print("MultipleOverlays/"+plotName+".eps");
////    c->Write();
////    c->Update();
//    
//    
//    system("mkdir C-Hadron");
//    
//    TH1* firstH = plotArray.at(1);
//    TH1* secondH = plotArray.at(2);
//    
//    TH1 * plot1_clone = (TH1F*) firstH->Clone();
//    TH1 * plot2_clone = (TH1F*) secondH->Clone();
//    
//    plot1_clone->SetTitle(plotname);
//    
//    TLegend * legend = new TLegend(0.8,0.8,1,1, "", "NDC");
//    legend->AddEntry(plot1_clone, "Labeled", "LEP");
//    legend->AddEntry(plot2_clone, "L' and Tagged", "LEP");
//    
//    TCanvas *c = new TCanvas();
//    
//    plot1_clone->SetLineColor(2);
//    plot1_clone->DrawCopy();
//    plot2_clone->SetLineColor(4);
//    plot2_clone->DrawCopy("same");
//    legend->Draw();
//    
//    c->Print("C-Hadron/"+plotname+".eps");
//    c->Write();
//    c->Update();
//    
//    cout<<"function works"<<endl;
//
//}

void simple_tag_proportions::hadronCountPlot(string type) {
    
    TFile * output_file = new TFile("output_plots.root", "RECREATE");
    output_file->cd();
    
    float* a = &countOfB_HadronsUseful[0];
    
    if (type == hadron_type) {
        TCanvas *c = new TCanvas();
        
        TGraph *gr = new TGraph(10, b_hadrons, a);
        gr->Draw("A*");
        
        c->Print("B-Hadron jet count.eps");
        c->Write();
        c->Update();
    }
    
    output_file->Close();
}