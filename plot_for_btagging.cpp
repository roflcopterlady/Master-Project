//Plotcode for B-Taggging
#define plot_for_btagging_cxx
#include "TString.h"
#include "TFile.h"
#include "TH1.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "array"
#include <iostream>
#include <string>

#include "plot_for_btagging.hpp"

int hadron_number;
float mv_value;

int main() {
    TString sample2 = "powheg2.root";
    
    
std:vector<TString> = {/* list all generator files*/};
    
    plot_for_btagging::resultsForFile(sample2, "powheg2.root");
   
    return 0;
}

//param: Individual, All, Momentum_Vs_J_Momentum
//hadron: B, C, H

void plot_for_btagging::comparingGenerators(TString hadron, TString param, std::vector<TString> fileNames) {
    
    for (TString file: fileNames) {
        std::cout << file << endl;
    }
    
}


void plot_for_btagging::resultsForFile(TString t_name, std::string s_name) {
    
    cout<<"\nRunning over file: "+s_name<<"\n"<<endl;
    
    TString B_HADRONS_INFO = t_name+"_B_individual.root";
    TString C_HADRONS_INFO = t_name+"_C_individual.root";
    
    TString B_PR = t_name+"_B_count.root";
    TString C_PR = t_name+"_C_count.root";
    
    TString B_ALL = t_name+"_B_all.root";
    TString C_ALL = t_name+"_C_all.root";
    
    TString B_ALL_HPT_VS_JPT = t_name+"_B_hPT_vs_jPT.root";
    TString C_ALL_HPT_VS_JPT = t_name+"_C_hPT_vs_jPT.root";
    
    //B_511 info
    TH1 * plot_B_511_PT_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_PT_L");
    TH1 * plot_B_511_ETA_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_ETA_L");
    TH1 * plot_B_511_LOC_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_LOC_L");
    
    TH1 * plot_B_511_PT_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_PT_LT_-0.7887");
    TH1 * plot_B_511_PT_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_PT_LT_0.4496");
    
    TH1 * plot_B_511_ETA_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_ETA_LT_-0.7887");
    TH1 * plot_B_511_ETA_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_ETA_LT_0.4496");
    
    TH1 * plot_B_511_LOC_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_LOC_LT_-0.7887");
    TH1 * plot_B_511_LOC_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_LOC_LT_0.4496");
    
    TH1 * plot_B_511_PT_Eff_low = plot_for_btagging::getEffPlot(plot_B_511_PT_LT_low, plot_B_511_PT_L, "B_511_PT_EFF_-0.7887");
    TH1 * plot_B_511_PT_Eff_high = plot_for_btagging::getEffPlot(plot_B_511_PT_LT_high, plot_B_511_PT_L, "B_511_PT_EFF_0.4496");
    
    TH1 * plot_B_511_ETA_Eff_low = plot_for_btagging::getEffPlot(plot_B_511_ETA_LT_low, plot_B_511_ETA_L, "B_511_ETA_EFF_-0.7887");
    TH1 * plot_B_511_ETA_Eff_high = plot_for_btagging::getEffPlot(plot_B_511_ETA_LT_high, plot_B_511_ETA_L, "B_511_ETA_EFF_0.4496");
    
    TH1 * plot_B_511_LOC_Eff_low = plot_for_btagging::getEffPlot(plot_B_511_LOC_LT_low, plot_B_511_LOC_L, "B_511_LOC_EFF_-0.7887");
    TH1 * plot_B_511_LOC_Eff_high = plot_for_btagging::getEffPlot(plot_B_511_LOC_LT_high, plot_B_511_LOC_L, "B_511_LOC_EFF_0.4496");
    
    //B_521 info
    TH1 * plot_B_521_PT_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_521_PT_L");
    TH1 * plot_B_521_ETA_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_521_ETA_L");
    TH1 * plot_B_521_LOC_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_521_LOC_L");
    
    TH1 * plot_B_521_PT_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_521_PT_LT_-0.7887");
    TH1 * plot_B_521_PT_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_521_PT_LT_0.4496");
    
    TH1 * plot_B_521_ETA_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_521_ETA_LT_-0.7887");
    TH1 * plot_B_521_ETA_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_521_ETA_LT_0.4496");
    
    TH1 * plot_B_521_LOC_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_521_LOC_LT_-0.7887");
    TH1 * plot_B_521_LOC_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_521_LOC_LT_0.4496");
    
    TH1 * plot_B_521_PT_Eff_low = plot_for_btagging::getEffPlot(plot_B_521_PT_LT_low, plot_B_521_PT_L, "B_521_PT_EFF_-0.7887");
    TH1 * plot_B_521_PT_Eff_high = plot_for_btagging::getEffPlot(plot_B_521_PT_LT_high, plot_B_521_PT_L, "B_521_PT_EFF_0.4496");
    
    TH1 * plot_B_521_ETA_Eff_low = plot_for_btagging::getEffPlot(plot_B_521_ETA_LT_low, plot_B_521_ETA_L, "B_521_ETA_EFF_-0.7887");
    TH1 * plot_B_521_ETA_Eff_high = plot_for_btagging::getEffPlot(plot_B_521_ETA_LT_high, plot_B_521_ETA_L, "B_521_ETA_EFF_0.4496");
    
    TH1 * plot_B_521_LOC_Eff_low = plot_for_btagging::getEffPlot(plot_B_521_LOC_LT_low, plot_B_521_LOC_L, "B_521_LOC_EFF_-0.7887");
    TH1 * plot_B_521_LOC_Eff_high = plot_for_btagging::getEffPlot(plot_B_521_LOC_LT_high, plot_B_521_LOC_L, "B_521_LOC_EFF_0.4496");
    
    //B_531 info
    TH1 * plot_B_531_PT_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_531_PT_L");
    TH1 * plot_B_531_ETA_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_531_ETA_L");
    TH1 * plot_B_531_LOC_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_531_LOC_L");
    
    TH1 * plot_B_531_PT_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_531_PT_LT_-0.7887");
    TH1 * plot_B_531_PT_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_531_PT_LT_0.4496");
    
    TH1 * plot_B_531_ETA_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_531_ETA_LT_-0.7887");
    TH1 * plot_B_531_ETA_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_531_ETA_LT_0.4496");
    
    TH1 * plot_B_531_LOC_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_531_LOC_LT_-0.7887");
    TH1 * plot_B_531_LOC_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_531_LOC_LT_0.4496");
    
    TH1 * plot_B_531_PT_Eff_low = plot_for_btagging::getEffPlot(plot_B_531_PT_LT_low, plot_B_531_PT_L, "B_531_PT_EFF_-0.7887");
    TH1 * plot_B_531_PT_Eff_high = plot_for_btagging::getEffPlot(plot_B_531_PT_LT_high, plot_B_531_PT_L, "B_531_PT_EFF_0.4496");
    
    TH1 * plot_B_531_ETA_Eff_low = plot_for_btagging::getEffPlot(plot_B_531_ETA_LT_low, plot_B_531_ETA_L, "B_531_ETA_EFF_-0.7887");
    TH1 * plot_B_531_ETA_Eff_high = plot_for_btagging::getEffPlot(plot_B_531_ETA_LT_high, plot_B_531_ETA_L, "B_531_ETA_EFF_0.4496");
    
    TH1 * plot_B_531_LOC_Eff_low = plot_for_btagging::getEffPlot(plot_B_531_LOC_LT_low, plot_B_531_LOC_L, "B_531_LOC_EFF_-0.7887");
    TH1 * plot_B_531_LOC_Eff_high = plot_for_btagging::getEffPlot(plot_B_531_LOC_LT_high, plot_B_531_LOC_L, "B_531_LOC_EFF_0.4496");
    
    //B_541 info
    TH1 * plot_B_541_PT_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_541_PT_L");
    TH1 * plot_B_541_ETA_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_541_ETA_L");
    TH1 * plot_B_541_LOC_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_541_LOC_L");
    
    TH1 * plot_B_541_PT_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_541_PT_LT_-0.7887");
    TH1 * plot_B_541_PT_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_541_PT_LT_0.4496");
    
    TH1 * plot_B_541_ETA_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_541_ETA_LT_-0.7887");
    TH1 * plot_B_541_ETA_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_541_ETA_LT_0.4496");
    
    TH1 * plot_B_541_LOC_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_541_LOC_LT_-0.7887");
    TH1 * plot_B_541_LOC_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_541_LOC_LT_0.4496");
    
    TH1 * plot_B_541_PT_Eff_low = plot_for_btagging::getEffPlot(plot_B_541_PT_LT_low, plot_B_541_PT_L, "B_541_PT_EFF_-0.7887");
    TH1 * plot_B_541_PT_Eff_high = plot_for_btagging::getEffPlot(plot_B_541_PT_LT_high, plot_B_541_PT_L, "B_541_PT_EFF_0.4496");
    
    TH1 * plot_B_541_ETA_Eff_low = plot_for_btagging::getEffPlot(plot_B_541_ETA_LT_low, plot_B_541_ETA_L, "B_541_PT_EFF_-0.7887");
    TH1 * plot_B_541_ETA_Eff_high = plot_for_btagging::getEffPlot(plot_B_541_ETA_LT_high, plot_B_541_ETA_L, "B_541_PT_EFF_0.4496");
    
    TH1 * plot_B_541_LOC_Eff_low = plot_for_btagging::getEffPlot(plot_B_541_LOC_LT_low, plot_B_541_LOC_L, "B_541_LOC_EFF_-0.7887");
    TH1 * plot_B_541_LOC_Eff_high = plot_for_btagging::getEffPlot(plot_B_541_LOC_LT_high, plot_B_541_LOC_L, "B_541_LOC_EFF_0.4496");
    
    //B_5122 info
    TH1 * plot_B_5122_PT_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_5122_PT_L");
    TH1 * plot_B_5122_ETA_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_5122_ETA_L");
    TH1 * plot_B_5122_LOC_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_5122_LOC_L");
    
    TH1 * plot_B_5122_PT_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_5122_PT_LT_-0.7887");
    TH1 * plot_B_5122_PT_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_5122_PT_LT_0.4496");
    
    TH1 * plot_B_5122_ETA_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_5122_ETA_LT_-0.7887");
    TH1 * plot_B_5122_ETA_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_5122_ETA_LT_0.4496");
    
    TH1 * plot_B_5122_LOC_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_5122_LOC_LT_-0.7887");
    TH1 * plot_B_5122_LOC_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_5122_LOC_LT_0.4496");
    
    TH1 * plot_B_5122_PT_Eff_low = plot_for_btagging::getEffPlot(plot_B_5122_PT_LT_low, plot_B_5122_PT_L, "B_5122_PT_EFF_-0.7887");
    TH1 * plot_B_5122_PT_Eff_high = plot_for_btagging::getEffPlot(plot_B_5122_PT_LT_high, plot_B_5122_PT_L, "B_5122_PT_EFF_0.4496");
    
    TH1 * plot_B_5122_ETA_Eff_low = plot_for_btagging::getEffPlot(plot_B_5122_ETA_LT_low, plot_B_5122_ETA_L, "B_5122_PT_EFF_-0.7887");
    TH1 * plot_B_5122_ETA_Eff_high = plot_for_btagging::getEffPlot(plot_B_5122_ETA_LT_high, plot_B_5122_ETA_L, "B_5122_PT_EFF_0.4496");
    
    TH1 * plot_B_5122_LOC_Eff_low = plot_for_btagging::getEffPlot(plot_B_5122_LOC_LT_low, plot_B_5122_LOC_L, "B_5122_LOC_EFF_-0.7887");
    TH1 * plot_B_5122_LOC_Eff_high = plot_for_btagging::getEffPlot(plot_B_5122_LOC_LT_high, plot_B_5122_LOC_L, "B_5122_LOC_EFF_0.4496");
    
    //C_411 info
    TH1 * plot_C_411_PT_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_411_PT_L");
    TH1 * plot_C_411_ETA_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_411_ETA_L");
    TH1 * plot_C_411_LOC_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_411_LOC_L");
    
    TH1 * plot_C_411_PT_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_411_PT_LT_-0.7887");
    TH1 * plot_C_411_PT_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_411_PT_LT_0.4496");
    
    TH1 * plot_C_411_ETA_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_411_ETA_LT_-0.7887");
    TH1 * plot_C_411_ETA_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_411_ETA_LT_0.4496");
    
    TH1 * plot_C_411_LOC_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_411_LOC_LT_-0.7887");
    TH1 * plot_C_411_LOC_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_411_LOC_LT_0.4496");
    
    TH1 * plot_C_411_PT_Eff_low = plot_for_btagging::getEffPlot(plot_C_411_PT_LT_low, plot_C_411_PT_L, "C_411_PT_EFF_-0.7887");
    TH1 * plot_C_411_PT_Eff_high = plot_for_btagging::getEffPlot(plot_C_411_PT_LT_high, plot_C_411_PT_L, "C_411_PT_EFF_0.4496");
    
    TH1 * plot_C_411_ETA_Eff_low = plot_for_btagging::getEffPlot(plot_C_411_ETA_LT_low, plot_C_411_ETA_L, "C_411_PT_EFF_-0.7887");
    TH1 * plot_C_411_ETA_Eff_high = plot_for_btagging::getEffPlot(plot_C_411_ETA_LT_high, plot_C_411_ETA_L, "C_411_PT_EFF_0.4496");
    
    TH1 * plot_C_411_LOC_Eff_low = plot_for_btagging::getEffPlot(plot_C_411_LOC_LT_low, plot_C_411_LOC_L, "C_411_LOC_EFF_-0.7887");
    TH1 * plot_C_411_LOC_Eff_high = plot_for_btagging::getEffPlot(plot_C_411_LOC_LT_high, plot_C_411_LOC_L, "C_411_LOC_EFF_0.4496");
    
    //C_421 info
    TH1 * plot_C_421_PT_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_421_PT_L");
    TH1 * plot_C_421_ETA_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_421_ETA_L");
    TH1 * plot_C_421_LOC_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_421_LOC_L");
    
    TH1 * plot_C_421_PT_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_421_PT_LT_-0.7887");
    TH1 * plot_C_421_PT_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_421_PT_LT_0.4496");
    
    TH1 * plot_C_421_ETA_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_421_ETA_LT_-0.7887");
    TH1 * plot_C_421_ETA_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_421_ETA_LT_0.4496");
    
    TH1 * plot_C_421_LOC_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_421_LOC_LT_-0.7887");
    TH1 * plot_C_421_LOC_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_421_LOC_LT_0.4496");
    
    TH1 * plot_C_421_PT_Eff_low = plot_for_btagging::getEffPlot(plot_C_421_PT_LT_low, plot_C_421_PT_L, "C_421_PT_EFF_-0.7887");
    TH1 * plot_C_421_PT_Eff_high = plot_for_btagging::getEffPlot(plot_C_421_PT_LT_high, plot_C_421_PT_L, "C_421_PT_EFF_0.4496");
    
    TH1 * plot_C_421_ETA_Eff_low = plot_for_btagging::getEffPlot(plot_C_421_ETA_LT_low, plot_C_421_ETA_L, "C_421_PT_EFF_-0.7887");
    TH1 * plot_C_421_ETA_Eff_high = plot_for_btagging::getEffPlot(plot_C_421_ETA_LT_high, plot_C_421_ETA_L, "C_421_PT_EFF_0.4496");
    
    TH1 * plot_C_421_LOC_Eff_low = plot_for_btagging::getEffPlot(plot_C_421_LOC_LT_low, plot_C_421_LOC_L, "C_421_LOC_EFF_-0.7887");
    TH1 * plot_C_421_LOC_Eff_high = plot_for_btagging::getEffPlot(plot_C_421_LOC_LT_high, plot_C_421_LOC_L, "C_421_LOC_EFF_0.4496");
    
    //C_431 info
    TH1 * plot_C_431_PT_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_431_PT_L");
    TH1 * plot_C_431_ETA_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_431_ETA_L");
    TH1 * plot_C_431_LOC_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_431_LOC_L");
    
    TH1 * plot_C_431_PT_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_431_PT_LT_-0.7887");
    TH1 * plot_C_431_PT_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_431_PT_LT_0.4496");
    
    TH1 * plot_C_431_ETA_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_431_ETA_LT_-0.7887");
    TH1 * plot_C_431_ETA_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_431_ETA_LT_0.4496");
    
    TH1 * plot_C_431_LOC_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_431_LOC_LT_-0.7887");
    TH1 * plot_C_431_LOC_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_431_LOC_LT_0.4496");
    
    TH1 * plot_C_431_PT_Eff_low = plot_for_btagging::getEffPlot(plot_C_431_PT_LT_low, plot_C_431_PT_L, "C_431_PT_EFF_-0.7887");
    TH1 * plot_C_431_PT_Eff_high = plot_for_btagging::getEffPlot(plot_C_431_PT_LT_high, plot_C_431_PT_L, "C_431_PT_EFF_0.4496");
    
    TH1 * plot_C_431_ETA_Eff_low = plot_for_btagging::getEffPlot(plot_C_431_ETA_LT_low, plot_C_431_ETA_L, "C_431_PT_EFF_-0.7887");
    TH1 * plot_C_431_ETA_Eff_high = plot_for_btagging::getEffPlot(plot_C_431_ETA_LT_high, plot_C_431_ETA_L, "C_431_PT_EFF_0.4496");
    
    TH1 * plot_C_431_LOC_Eff_low = plot_for_btagging::getEffPlot(plot_C_431_LOC_LT_low, plot_C_431_LOC_L, "C_431_LOC_EFF_-0.7887");
    TH1 * plot_C_431_LOC_Eff_high = plot_for_btagging::getEffPlot(plot_C_431_LOC_LT_high, plot_C_431_LOC_L, "C_431_LOC_EFF_0.4496");
    
    //C_4122 info
    TH1 * plot_C_4122_PT_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_4122_PT_L");
    TH1 * plot_C_4122_ETA_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_4122_ETA_L");
    TH1 * plot_C_4122_LOC_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_4122_LOC_L");
    
    TH1 * plot_C_4122_PT_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_4122_PT_LT_-0.7887");
    TH1 * plot_C_4122_PT_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_4122_PT_LT_0.4496");
    
    TH1 * plot_C_4122_ETA_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_4122_ETA_LT_-0.7887");
    TH1 * plot_C_4122_ETA_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_4122_ETA_LT_0.4496");
    
    TH1 * plot_C_4122_LOC_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_4122_LOC_LT_-0.7887");
    TH1 * plot_C_4122_LOC_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_4122_LOC_LT_0.4496");
    
    TH1 * plot_C_4122_PT_Eff_low = plot_for_btagging::getEffPlot(plot_C_4122_PT_LT_low, plot_C_4122_PT_L, "C_4122_PT_EFF_-0.7887");
    TH1 * plot_C_4122_PT_Eff_high = plot_for_btagging::getEffPlot(plot_C_4122_PT_LT_high, plot_C_4122_PT_L, "C_4122_PT_EFF_0.4496");
    
    TH1 * plot_C_4122_ETA_Eff_low = plot_for_btagging::getEffPlot(plot_C_4122_ETA_LT_low, plot_C_4122_ETA_L, "C_4122_PT_EFF_-0.7887");
    TH1 * plot_C_4122_ETA_Eff_high = plot_for_btagging::getEffPlot(plot_C_4122_ETA_LT_high, plot_C_4122_ETA_L, "C_4122_PT_EFF_0.4496");
    
    TH1 * plot_C_4122_LOC_Eff_low = plot_for_btagging::getEffPlot(plot_C_4122_LOC_LT_low, plot_C_4122_LOC_L, "C_4122_LOC_EFF_-0.7887");
    TH1 * plot_C_4122_LOC_Eff_high = plot_for_btagging::getEffPlot(plot_C_4122_LOC_LT_high, plot_C_4122_LOC_L, "C_4122_LOC_EFF_0.4496");
    
    //PT info for all B_hadrons
    TH1 * plot_B_ALL_PT_L = plot_for_btagging::getPlot(B_ALL, "B_ALL_PT_L");
    TH1 * plot_B_ALL_PT_LT_low = plot_for_btagging::getPlot(B_ALL, "B_ALL_PT_LT_-0.7887");
    TH1 * plot_B_ALL_PT_LT_high = plot_for_btagging::getPlot(B_ALL, "B_ALL_PT_LT_0.4496");
    
    std::vector<TString> legendsArrayAll = {"ALL", "MV_-0.7887", "MV_0.4496"};
    
    //PT info for all C_hadrons
    TH1 * plot_C_ALL_PT_L = plot_for_btagging::getPlot(C_ALL, "C_ALL_PT_L");
    TH1 * plot_C_ALL_PT_LT_low = plot_for_btagging::getPlot(C_ALL, "C_ALL_PT_LT_-0.7887");
    TH1 * plot_C_ALL_PT_LT_high = plot_for_btagging::getPlot(C_ALL, "C_ALL_PT_LT_0.4496");
    
    //ETA info for all B_hadrons
    TH1 * plot_B_ALL_ETA_L = plot_for_btagging::getPlot(B_ALL, "B_ALL_ETA_L");
    TH1 * plot_B_ALL_ETA_LT_low = plot_for_btagging::getPlot(B_ALL, "B_ALL_ETA_LT_-0.7887");
    TH1 * plot_B_ALL_ETA_LT_high = plot_for_btagging::getPlot(B_ALL, "B_ALL_ETA_LT_0.4496");
    
    //ETA info for all C_hadrons
    TH1 * plot_C_ALL_ETA_L = plot_for_btagging::getPlot(C_ALL, "C_ALL_ETA_L");
    TH1 * plot_C_ALL_ETA_LT_low = plot_for_btagging::getPlot(C_ALL, "C_ALL_ETA_LT_-0.7887");
    TH1 * plot_C_ALL_ETA_LT_high = plot_for_btagging::getPlot(C_ALL, "C_ALL_ETA_LT_0.4496");
    
    //LOC info for all B_hadrons
    TH1 * plot_B_ALL_HLOC_L = plot_for_btagging::getPlot(B_ALL, "B_ALL_PT_L");
    TH1 * plot_B_ALL_HLOC_LT_low = plot_for_btagging::getPlot(B_ALL, "B_ALL_HLOC_LT_-0.7887");
    TH1 * plot_B_ALL_HLOC_LT_high = plot_for_btagging::getPlot(B_ALL, "B_ALL_HLOC_LT_0.4496");
    
    //LOC info for all C_hadrons
    TH1 * plot_C_ALL_HLOC_L = plot_for_btagging::getPlot(C_ALL, "C_ALL_PT_L");
    TH1 * plot_C_ALL_HLOC_LT_low = plot_for_btagging::getPlot(C_ALL, "C_ALL_HLOC_LT_-0.7887");
    TH1 * plot_C_ALL_HLOC_LT_high = plot_for_btagging::getPlot(C_ALL, "C_ALL_HLOC_LT_0.4496");
    
    //PT info for all B_hadrons Efficiency
    TH1 * plot_B_ALL_PT_Eff_low = plot_for_btagging::getEffPlot(plot_B_ALL_PT_LT_low, plot_B_ALL_PT_L, "B_ALL_PT_EFF_-0.7887");
    TH1 * plot_B_ALL_PT_Eff_high = plot_for_btagging::getEffPlot(plot_B_ALL_PT_LT_high, plot_B_ALL_PT_L, "B_ALL_PT_EFF_0.4496");
    
    std::vector<TString> legendsArrayEfficiency = {"MV_-0.7887", "MV_0.4496"};
    
    //ETA info for all B_hadrons Efficiency
    TH1 * plot_B_ALL_ETA_Eff_low = plot_for_btagging::getEffPlot(plot_B_ALL_ETA_LT_low, plot_B_ALL_ETA_L, "B_ALL_ETA_EFF_-0.7887");
    TH1 * plot_B_ALL_ETA_Eff_high = plot_for_btagging::getEffPlot(plot_B_ALL_ETA_LT_high, plot_B_ALL_ETA_L, "B_ALL_ETA_EFF_0.4496");
    
    //LOC info for all B_hadrons Efficiency
    TH1 * plot_B_ALL_HLOC_Eff_low = plot_for_btagging::getEffPlot(plot_B_ALL_HLOC_LT_low, plot_B_ALL_HLOC_L, "B_ALL_HLOC_EFF_-0.7887");
    TH1 * plot_B_ALL_HLOC_Eff_high = plot_for_btagging::getEffPlot(plot_B_ALL_HLOC_LT_high, plot_B_ALL_HLOC_L, "B_ALL_HLOC_EFF_0.4496");
    
    //PT info for all C_hadrons Efficiency
    TH1 * plot_C_ALL_PT_Eff_low = plot_for_btagging::getEffPlot(plot_C_ALL_PT_LT_low, plot_C_ALL_PT_L, "C_ALL_PT_EFF_-0.7887");
    TH1 * plot_C_ALL_PT_Eff_high = plot_for_btagging::getEffPlot(plot_C_ALL_PT_LT_high, plot_C_ALL_PT_L, "C_ALL_PT_EFF_0.4496");
    
    //ETA info for all C_hadrons Efficiency
    TH1 * plot_C_ALL_ETA_Eff_low = plot_for_btagging::getEffPlot(plot_C_ALL_ETA_LT_low, plot_C_ALL_ETA_L, "C_ALL_ETA_EFF_-0.7887");
    TH1 * plot_C_ALL_ETA_Eff_high = plot_for_btagging::getEffPlot(plot_C_ALL_ETA_LT_high, plot_C_ALL_ETA_L, "C_ALL_ETA_EFF_0.4496");
    
    //LOC info for all C_hadrons Efficiency
    TH1 * plot_C_ALL_HLOC_Eff_low = plot_for_btagging::getEffPlot(plot_C_ALL_HLOC_LT_low, plot_C_ALL_HLOC_L, "C_ALL_HLOC_EFF_-0.7887");
    TH1 * plot_C_ALL_HLOC_Eff_high = plot_for_btagging::getEffPlot(plot_C_ALL_HLOC_LT_high, plot_C_ALL_HLOC_L, "C_ALL_HLOC_EFF_0.4496");
    
//    //PT info for all C_hadrons Efficiency
//    // Is this meant to be here?
//    TH1 * plot_C_ALL_Eff_low = plot_for_btagging::getEffPlot(plot_C_ALL_PT_LT_low, plot_C_ALL_PT_L, "C_ALL_PT_Efficinecy_-0.7887");
//    TH1 * plot_C_ALL_Eff_high = plot_for_btagging::getEffPlot(plot_C_ALL_PT_LT_high, plot_C_ALL_PT_L, "C_ALL_PT_Efficinecy_0.4496");
    
    //Histograms of B hadron counts
    TH1 * plot_B_ALL_Count = plot_for_btagging::getPlot(B_PR, "B_PR_L");
    TH1 * plot_B_ALL_low_Count = plot_for_btagging::getPlot(B_PR, "B_PR_LT_-0.7887");
    TH1 * plot_B_ALL_high_Count = plot_for_btagging::getPlot(B_PR, "B_PR_LT_0.4496");
    TH1 * plot_B_ALL_Count_Eff_low = plot_for_btagging::getEffPlot(plot_B_ALL_low_Count, plot_B_ALL_Count, "B_PR_EFF_-0.7887");
    TH1 * plot_B_ALL_Count_Eff_high = plot_for_btagging::getEffPlot(plot_B_ALL_high_Count, plot_B_ALL_Count, "B_PR_EFF_0.4496");
    
    //Histograms of C hadron counts
    TH1 * plot_C_ALL_Count = plot_for_btagging::getPlot(C_PR, "C_PR_L");
    TH1 * plot_C_ALL_low_Count = plot_for_btagging::getPlot(C_PR, "C_PR_LT_-0.7887");
    TH1 * plot_C_ALL_high_Count = plot_for_btagging::getPlot(C_PR, "C_PR_LT_0.4496");
    TH1 * plot_C_ALL_Count_Eff_low = plot_for_btagging::getEffPlot(plot_C_ALL_low_Count, plot_C_ALL_Count, "C_PR_EFF_-0.7887");
    TH1 * plot_C_ALL_Count_Eff_high = plot_for_btagging::getEffPlot(plot_C_ALL_high_Count, plot_C_ALL_Count, "C_PR_EFF_0.4496");
    
    //B Hadron momentum vs Jet momentum
    TH1 * plot_B_PT_H_VS_J_L = plot_for_btagging::getPlot(B_ALL_HPT_VS_JPT, "B_PT_H_VS_J_L");
    TH1 * plot_B_PT_H_VS_J_LT_low = plot_for_btagging::getPlot(B_ALL_HPT_VS_JPT, "B_PT_H_VS_J_LT_-0.7887");
    TH1 * plot_B_PT_H_VS_J_LT_high = plot_for_btagging::getPlot(B_ALL_HPT_VS_JPT, "B_PT_H_VS_J_LT_0.4496");
    
    TH1 * plot_B_PT_H_VS_J_Eff_low = plot_for_btagging::getEffPlot(plot_B_PT_H_VS_J_LT_low, plot_B_PT_H_VS_J_L, "B_PT_H_VS_J_LT_EFF_-0.7887");
    TH1 * plot_B_PT_H_VS_J_Eff_high = plot_for_btagging::getEffPlot(plot_B_PT_H_VS_J_LT_high, plot_B_PT_H_VS_J_L, "B_PT_H_VS_J_LT_EFF_0.4496");
    
    //C Hadron momentum vs Jet momentum
    TH1 * plot_C_PT_H_VS_J_L = plot_for_btagging::getPlot(C_ALL_HPT_VS_JPT, "C_PT_H_VS_J_L");
    TH1 * plot_C_PT_H_VS_J_LT_low = plot_for_btagging::getPlot(C_ALL_HPT_VS_JPT, "C_PT_H_VS_J_LT_-0.7887");
    TH1 * plot_C_PT_H_VS_J_LT_high = plot_for_btagging::getPlot(C_ALL_HPT_VS_JPT, "C_PT_H_VS_J_LT_0.4496");
    
    TH1 * plot_C_PT_H_VS_J_Eff_low = plot_for_btagging::getEffPlot(plot_C_PT_H_VS_J_LT_low, plot_C_PT_H_VS_J_L, "C_PT_H_VS_J_LT_EFF_-0.7887");
    TH1 * plot_C_PT_H_VS_J_Eff_high = plot_for_btagging::getEffPlot(plot_C_PT_H_VS_J_LT_high, plot_C_PT_H_VS_J_L, "C_PT_H_VS_J_LT_EFF_0.4496");
    
    std::vector<TString> legends_B_hadrons = {"511", "521", "531", "541", "5122"};
    std::vector<TString> legends_C_hadrons = {"411", "421", "431", "4122"};
    
    //    *************************************************************
    //
    //    *************************************************************
    //
    //    *************************************************************
    
    std::string all_HadronsString = "RESULTS_"+s_name+"_H_All_.root";
    std::string b_InidividualString = "RESULTS_"+s_name+"_B_Individual.root";
    std::string c_InidividualString = "RESULTS_"+s_name+"_C_Individual.root";
    std::string all_pro_rateString = "RESULTS_"+s_name+"_H_Production_Rate.root";
    std::string all_hPT_vs_jPTString = "RESULTS_"+s_name+"_H_Momentum_Vs_J_Momentum.root";
    
    std::string eff_Plots_String = "EFFICIENCY_"+s_name;
    
    char const * all_Hadrons = all_HadronsString.c_str();
    char const * b_Inidividual = b_InidividualString.c_str();
    char const * c_Inidividual = c_InidividualString.c_str();
    char const * all_pro_rate = all_pro_rateString.c_str();
    char const * all_hPT_vs_jPT = all_hPT_vs_jPTString.c_str();
    
    char const * eff_Plots = eff_Plots_String.c_str();
    
    //Results files
    TFile * output_file = new TFile(all_Hadrons, "RECREATE");
    TFile * output_file_B = new TFile(b_Inidividual, "RECREATE");
    TFile * output_file_C = new TFile(c_Inidividual, "RECREATE");
    TFile * output_file_rate = new TFile(all_pro_rate, "RECREATE");
    TFile * output_file_pt_hPT_vs_jPT = new TFile(all_hPT_vs_jPT, "RECREATE");
    
    TFile * output_file_eff_Plots = new TFile(eff_Plots, "RECREATE");
    
    ///Momentum file
    
    output_file_pt_hPT_vs_jPT->cd();
    
    plot_for_btagging::overlayNPlots("PT between H and J: All B hadrons Labeled & (Lab' and Tag') by different MV2C20 cutoffs", legendsArrayAll, plot_B_PT_H_VS_J_L, plot_B_PT_H_VS_J_LT_low, plot_B_PT_H_VS_J_LT_high, NULL);
    
    plot_for_btagging::overlayNPlots("PT between H and J: All C hadrons Labeled & (Lab' and Tag') by different MV2C20 cutoffs", legendsArrayAll, plot_C_PT_H_VS_J_L, plot_C_PT_H_VS_J_LT_low, plot_C_PT_H_VS_J_LT_high, NULL);
    
    plot_for_btagging::overlayNPlots("PT between H and J: All B hadrons - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_PT_H_VS_J_Eff_low, plot_B_PT_H_VS_J_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("PT between H and J: All C hadrons - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_PT_H_VS_J_Eff_low, plot_C_PT_H_VS_J_Eff_high, NULL);
    
    output_file_pt_hPT_vs_jPT->Close();
    
    ///Rate file
    
    output_file_rate->cd();
    
    plot_for_btagging::overlayNPlots("Rate: All B hadrons Labeled & (Lab' and Tag') by different MV2C20 cutoffs", legendsArrayAll, plot_B_ALL_Count, plot_B_ALL_low_Count, plot_B_ALL_high_Count, NULL);
    
    plot_for_btagging::overlayNPlots("Rate: All C hadrons Labeled & (Lab' and Tag') by different MV2C20 cutoffs", legendsArrayAll, plot_C_ALL_Count, plot_C_ALL_low_Count, plot_C_ALL_high_Count, NULL);
    
    plot_for_btagging::overlayNPlots("Rate: All B hadrons - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_ALL_Count_Eff_low, plot_B_ALL_Count_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("Rate: All C hadrons - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_ALL_Count_Eff_low, plot_C_ALL_Count_Eff_high, NULL);
    
    output_file_rate->Close();
    
    ///All hadron file
    output_file->cd();
    
    plot_for_btagging::overlayNPlots("PT: All B hadrons - Labeled & (Lab' and Tag') by different MV2C20 cutoffs", legendsArrayAll,plot_B_ALL_PT_L, plot_B_ALL_PT_LT_low, plot_B_ALL_PT_LT_high, NULL);
    
    plot_for_btagging::overlayNPlots("PT: All C hadrons - Labeled & (Lab' and Tag') by different MV2C20 cutoffs", legendsArrayAll,plot_C_ALL_PT_L, plot_C_ALL_PT_LT_low, plot_C_ALL_PT_LT_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: All B hadrons - Labeled & (Lab' and Tag') by different MV2C20 cutoffs", legendsArrayAll,plot_B_ALL_ETA_L, plot_B_ALL_ETA_LT_low, plot_B_ALL_ETA_LT_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: All C hadrons - Labeled & (Lab' and Tag') by different MV2C20 cutoffs", legendsArrayAll,plot_C_ALL_ETA_L, plot_C_ALL_ETA_LT_low, plot_C_ALL_ETA_LT_high, NULL);
    
    plot_for_btagging::overlayNPlots("LOC: All B hadrons - Labeled & (Lab' and Tag') by different MV2C20 cutoffs", legendsArrayAll,plot_B_ALL_HLOC_L, plot_B_ALL_HLOC_LT_low, plot_B_ALL_HLOC_LT_high, NULL);
    
    plot_for_btagging::overlayNPlots("LOC: All C hadrons - Labeled & (Lab' and Tag') by different MV2C20 cutoffs", legendsArrayAll,plot_C_ALL_HLOC_L, plot_C_ALL_HLOC_LT_low, plot_C_ALL_HLOC_LT_high, NULL);
    
    plot_for_btagging::overlayNPlots("PT: All B hadrons - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_ALL_PT_Eff_low, plot_B_ALL_PT_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: All B hadrons - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_ALL_ETA_Eff_low, plot_B_ALL_ETA_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("LOC: All B hadrons - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_ALL_HLOC_Eff_low, plot_B_ALL_HLOC_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("PT: All C hadrons - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_ALL_PT_Eff_low, plot_C_ALL_PT_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: All C hadrons - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_ALL_ETA_Eff_low, plot_C_ALL_ETA_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("LOC: All C hadrons - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_ALL_HLOC_Eff_low, plot_C_ALL_HLOC_Eff_high, NULL);
    
    output_file->Close();
    
    ///Specific B_hadron efficiency
    output_file_B->cd();
    
    //B_511
    plot_for_btagging::overlayNPlots("PT: B_511 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_511_PT_Eff_low, plot_B_511_PT_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: B_511 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_511_ETA_Eff_low, plot_B_511_ETA_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("LOC: B_511 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_511_LOC_Eff_low, plot_B_511_LOC_Eff_high, NULL);
    
    //B_521
    plot_for_btagging::overlayNPlots("PT: B_521 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_521_PT_Eff_low, plot_B_521_PT_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: B_521 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_521_ETA_Eff_low, plot_B_521_ETA_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("LOC: B_521 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_521_LOC_Eff_low, plot_B_521_LOC_Eff_high, NULL);
    
    //B_531
    plot_for_btagging::overlayNPlots("PT: B_531 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_531_PT_Eff_low, plot_B_531_PT_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: B_531 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_531_ETA_Eff_low, plot_B_531_ETA_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("LOC: B_531 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_531_LOC_Eff_low, plot_B_531_LOC_Eff_high, NULL);
    
    //B_541
    plot_for_btagging::overlayNPlots("PT: B_541 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_541_PT_Eff_low, plot_B_541_PT_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: B_541 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_541_ETA_Eff_low, plot_B_541_ETA_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("LOC: B_541 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_541_LOC_Eff_low, plot_B_541_LOC_Eff_low, NULL);
    
    
    output_file_B->Close();
    
    ///Specific C_hadron efficiency
    output_file_C->cd();
    
    //C_411
    plot_for_btagging::overlayNPlots("PT: C_411 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_411_PT_Eff_low, plot_C_411_PT_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: C_411 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_411_ETA_Eff_low, plot_C_411_ETA_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("LOC: C_411 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_411_LOC_Eff_low, plot_C_411_LOC_Eff_high, NULL);
    
    //C_421
    plot_for_btagging::overlayNPlots("PT: C_421 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_421_PT_Eff_low, plot_C_421_PT_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: C_421 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_421_ETA_Eff_low, plot_C_421_ETA_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("LOC: C_421 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_421_LOC_Eff_low, plot_C_421_LOC_Eff_high, NULL);
    
    //C_431
    plot_for_btagging::overlayNPlots("PT: C_431 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_431_PT_Eff_low, plot_C_431_PT_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: C_431 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_431_ETA_Eff_low, plot_C_431_ETA_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("LOC: C_431 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_431_LOC_Eff_low, plot_C_431_LOC_Eff_high, NULL);
    
    //C_4122
    plot_for_btagging::overlayNPlots("PT: C_4122 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_4122_PT_Eff_low, plot_C_4122_PT_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: C_4122 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_4122_ETA_Eff_low, plot_C_4122_ETA_Eff_high, NULL);
    
    plot_for_btagging::overlayNPlots("LOC: C_4122 - Efficiency with respect to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_4122_LOC_Eff_low, plot_C_4122_LOC_Eff_high, NULL);
    
    output_file_B->Close();
    
    output_file_eff_Plots->cd();
    
    plot_B_511_PT_Eff_low->Write();
    plot_B_511_PT_Eff_high->Write();
    plot_B_511_ETA_Eff_low->Write();
    plot_B_511_ETA_Eff_high->Write();
    plot_B_511_LOC_Eff_low->Write();
    plot_B_511_LOC_Eff_high->Write();
    
    plot_B_521_PT_Eff_low->Write();
    plot_B_521_PT_Eff_high->Write();
    plot_B_521_ETA_Eff_low->Write();
    plot_B_521_ETA_Eff_high->Write();
    plot_B_521_LOC_Eff_low->Write();
    plot_B_521_LOC_Eff_high->Write();
    
    plot_B_531_PT_Eff_low->Write();
    plot_B_531_PT_Eff_high->Write();
    plot_B_531_ETA_Eff_low->Write();
    plot_B_531_ETA_Eff_high->Write();
    plot_B_531_LOC_Eff_low->Write();
    plot_B_531_LOC_Eff_high->Write();
    
    plot_B_541_PT_Eff_low->Write();
    plot_B_541_PT_Eff_high->Write();
    plot_B_541_ETA_Eff_low->Write();
    plot_B_541_ETA_Eff_high->Write();
    plot_B_541_LOC_Eff_low->Write();
    plot_B_541_LOC_Eff_high->Write();
    
    plot_B_5122_PT_Eff_low->Write();
    plot_B_5122_PT_Eff_high->Write();
    plot_B_5122_ETA_Eff_low->Write();
    plot_B_5122_ETA_Eff_high->Write();
    plot_B_5122_LOC_Eff_low->Write();
    plot_B_5122_LOC_Eff_high->Write();
    
    plot_C_411_PT_Eff_low->Write();
    plot_C_411_PT_Eff_high->Write();
    plot_C_411_ETA_Eff_low->Write();
    plot_C_411_ETA_Eff_high->Write();
    plot_C_411_LOC_Eff_low->Write();
    plot_C_411_LOC_Eff_high->Write();
    
    plot_C_421_PT_Eff_low->Write();
    plot_C_421_PT_Eff_high->Write();
    plot_C_421_ETA_Eff_low->Write();
    plot_C_421_ETA_Eff_high->Write();
    plot_C_421_LOC_Eff_low->Write();
    plot_C_421_LOC_Eff_high->Write();
    
    plot_C_431_PT_Eff_low->Write();
    plot_C_431_PT_Eff_high->Write();
    plot_C_431_ETA_Eff_low->Write();
    plot_C_431_ETA_Eff_high->Write();
    plot_C_431_LOC_Eff_low->Write();
    plot_C_431_LOC_Eff_high->Write();
    
    plot_C_4122_PT_Eff_low->Write();
    plot_C_4122_PT_Eff_high->Write();
    plot_C_4122_ETA_Eff_low->Write();
    plot_C_4122_ETA_Eff_high->Write();
    plot_C_4122_LOC_Eff_low->Write();
    plot_C_4122_LOC_Eff_high->Write();
    
    plot_B_ALL_PT_Eff_low->Write();
    plot_B_ALL_PT_Eff_high->Write();
    plot_B_ALL_ETA_Eff_low->Write();
    plot_B_ALL_ETA_Eff_high->Write();
    plot_B_ALL_HLOC_Eff_low->Write();
    plot_B_ALL_HLOC_Eff_high->Write();
    plot_B_PT_H_VS_J_Eff_low->Write();
    plot_B_PT_H_VS_J_Eff_high->Write();
    
    plot_C_ALL_PT_Eff_low->Write();
    plot_C_ALL_PT_Eff_high->Write();
    plot_C_ALL_ETA_Eff_low->Write();
    plot_C_ALL_ETA_Eff_high->Write();
    plot_C_ALL_HLOC_Eff_low->Write();
    plot_C_ALL_HLOC_Eff_high->Write();
    plot_C_PT_H_VS_J_Eff_low->Write();
    plot_C_PT_H_VS_J_Eff_high->Write();
    
    plot_B_ALL_Count_Eff_low->Write();
    plot_B_ALL_Count_Eff_high->Write();
    
    plot_C_ALL_Count_Eff_low->Write();
    plot_C_ALL_Count_Eff_high->Write();
    
    
    
    output_file_eff_Plots->Close();
}

void plot_for_btagging::overlayPlots(TH1* plot1, TH1* plot2, TString plotName, TString legend1, TString legend2) {
    
    TH1 * plot1_clone = (TH1F*) plot1->Clone();
    TH1 * plot2_clone = (TH1F*) plot2->Clone();
    
    plot1_clone->SetTitle(plotName);
    
    TLegend * legend = new TLegend(0.8,0.8,1,1, "", "NDC");
    legend->AddEntry(plot1_clone, legend1, "LEP");
    legend->AddEntry(plot2_clone, legend2, "LEP");
    
    TCanvas *c = new TCanvas();
    
    plot1_clone->SetLineColor(2);
    plot1_clone->DrawCopy();
    plot2_clone->SetLineColor(4);
    plot2_clone->DrawCopy("same");
    legend->Draw();
    
    c->Write();
    c->Update();
}

void plot_for_btagging::overlayNPlots(TString plotName, std::vector<TString> legendsVector, TH1* plot1,...) {
    
    std::vector<TH1*> clonePlotArray;
    
    TH1* currentPlot = plot1;
    
    va_list list;
    va_start(list, plot1);
    
    while (currentPlot != NULL) {
        
        TH1* currentClone = (TH1F*) currentPlot->Clone();
        
        if (currentPlot == plot1) {
            currentClone->SetTitle(plotName);
        }
        clonePlotArray.push_back(currentClone);
        
        // Step to the next plot
        currentPlot = va_arg(list, TH1*);
    }
    
    va_end(list);
    
    TLegend * legend = new TLegend(0.8,0.8,1,1, "", "NDC");
    for (int i=0; i<legendsVector.size(); i++) {
        legend->AddEntry(clonePlotArray.at(i), legendsVector.at(i), "LEP");
    }
    
    TCanvas * c = new TCanvas();
    
    int colourCounter = 1;
    
    for (TH1* histogram: clonePlotArray) {
        
        if (colourCounter == 1) {
            histogram->SetLineColor(colourCounter);
            histogram->DrawCopy();
        }
        else {
            histogram->SetLineColor(colourCounter);
            histogram->DrawCopy("same");
        }
        
        colourCounter+=1;
    }
    
    legend->Draw();
    
    c->Write();
    c->Update();
}

TH1* plot_for_btagging::getEffPlot(TH1* plot1, TH1* plot2, TString plotName) {
    
    TH1 * Eff = (TH1F*) plot1->Clone();
    Eff->SetTitle(plotName);
    Eff->SetName(plotName);
    Eff->Divide(plot1,plot2,1,1, "B");
    Eff->SetAxisRange(0, 1, "Y");
    return Eff;
}

void plot_for_btagging::EffPlots(TH1* plot1, TH1* plot2, TString plotName) {
    
    TH1 * Eff = (TH1F*) plot1->Clone();
    Eff->SetTitle(plotName);
    Eff->SetName(plotName);
    Eff->Divide(plot2);
    Eff->SetAxisRange(0, 1, "Y");
    Eff->Write();
}


TH1* plot_for_btagging::getPlot(TString fileName, TString plotName) {
    
    TFile * f = new TFile(fileName, "READ");
    f->cd();
    TH1 * plot = (TH1F*)gDirectory->Get(plotName);
    plot->SetDirectory(0);
    plot->SetStats(0);
    f->Close();
    
    return plot;
}
