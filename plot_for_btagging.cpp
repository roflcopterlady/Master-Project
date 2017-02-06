//Plotcode for B-Taggging
#define plot_for_btagging_cxx
#include "TString.h"
#include "TFile.h"
#include "TH1.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "array"
#include <iostream>

#include "plot_for_btagging.hpp"

int hadron_number;
float mv_value;

TString hadron_type = "B";

int main() {
    
    std::vector<TH1* > testVector;
    
    //Initialise TString with histograms we need from output_plots
    
    TString B_COUNT = "output_plots_count_B.root";
    TString C_COUNT = "output_plots_count_C.root";
    
    TString B_ALL = "output_plots_all_B.root";
    TString C_ALL = "output_plots_all_C.root";
    
    TString B_HADRONS_INFO = "output_plots_B_HADRONS.root";
    TString C_HADRONS_INFO = "output_plots_C_HADRONS.root";
    
    //B_511 info
    TH1 * plot_B_511_PT_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_PT_L");
    TH1 * plot_B_511_ETA_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_ETA_L");
    
    TH1 * plot_B_511_PT_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_PT_LT_-0.788700");
    TH1 * plot_B_511_PT_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_PT_LT_0.449600");
    
    TH1 * plot_B_511_ETA_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_ETA_LT_-0.788700");
    TH1 * plot_B_511_ETA_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_ETA_LT_0.449600");
    
    TH1 * plot_B_511_PT_Ratio_low = plot_for_btagging::getRatioPlot(plot_B_511_PT_LT_low, plot_B_511_PT_L, "B_511_PT_Efficinecy_-0.7887");
    TH1 * plot_B_511_PT_Ratio_high = plot_for_btagging::getRatioPlot(plot_B_511_PT_LT_high, plot_B_511_PT_L, "B_511_PT_Efficinecy_0.4496");
    
    TH1 * plot_B_511_ETA_Ratio_low = plot_for_btagging::getRatioPlot(plot_B_511_ETA_LT_low, plot_B_511_ETA_L, "B_511_PT_Efficinecy_-0.7887");
    TH1 * plot_B_511_ETA_Ratio_high = plot_for_btagging::getRatioPlot(plot_B_511_ETA_LT_high, plot_B_511_ETA_L, "B_511_PT_Efficinecy_0.4496");
    
    //B_521 info
    TH1 * plot_B_521_PT_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_521_PT_L");
    TH1 * plot_B_521_ETA_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_521_ETA_L");
    
    TH1 * plot_B_521_PT_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_521_PT_LT_-0.788700");
    TH1 * plot_B_521_PT_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_521_PT_LT_0.449600");
    
    TH1 * plot_B_521_ETA_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_521_ETA_LT_-0.788700");
    TH1 * plot_B_521_ETA_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_521_ETA_LT_0.449600");
    
    TH1 * plot_B_521_PT_Ratio_low = plot_for_btagging::getRatioPlot(plot_B_521_PT_LT_low, plot_B_521_PT_L, "B_521_PT_Efficinecy_-0.7887");
    TH1 * plot_B_521_PT_Ratio_high = plot_for_btagging::getRatioPlot(plot_B_521_PT_LT_high, plot_B_521_PT_L, "B_521_PT_Efficinecy_0.4496");
    
    TH1 * plot_B_521_ETA_Ratio_low = plot_for_btagging::getRatioPlot(plot_B_521_ETA_LT_low, plot_B_521_ETA_L, "B_521_PT_Efficinecy_-0.7887");
    TH1 * plot_B_521_ETA_Ratio_high = plot_for_btagging::getRatioPlot(plot_B_521_ETA_LT_high, plot_B_521_ETA_L, "B_521_PT_Efficinecy_0.4496");
    
    //B_531 info
    TH1 * plot_B_531_PT_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_531_PT_L");
    TH1 * plot_B_531_ETA_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_531_ETA_L");
    
    TH1 * plot_B_531_PT_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_531_PT_LT_-0.788700");
    TH1 * plot_B_531_PT_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_531_PT_LT_0.449600");
    
    TH1 * plot_B_531_ETA_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_531_ETA_LT_-0.788700");
    TH1 * plot_B_531_ETA_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_531_ETA_LT_0.449600");
    
    TH1 * plot_B_531_PT_Ratio_low = plot_for_btagging::getRatioPlot(plot_B_531_PT_LT_low, plot_B_531_PT_L, "B_531_PT_Efficinecy_-0.7887");
    TH1 * plot_B_531_PT_Ratio_high = plot_for_btagging::getRatioPlot(plot_B_531_PT_LT_high, plot_B_531_PT_L, "B_531_PT_Efficinecy_0.4496");
    
    TH1 * plot_B_531_ETA_Ratio_low = plot_for_btagging::getRatioPlot(plot_B_531_ETA_LT_low, plot_B_531_ETA_L, "B_531_PT_Efficinecy_-0.7887");
    TH1 * plot_B_531_ETA_Ratio_high = plot_for_btagging::getRatioPlot(plot_B_531_ETA_LT_high, plot_B_531_ETA_L, "B_531_PT_Efficinecy_0.4496");
    
    //B_541 info
    TH1 * plot_B_541_PT_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_541_PT_L");
    TH1 * plot_B_541_ETA_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_541_ETA_L");
    
    TH1 * plot_B_541_PT_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_541_PT_LT_-0.788700");
    TH1 * plot_B_541_PT_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_541_PT_LT_0.449600");
    
    TH1 * plot_B_541_ETA_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_541_ETA_LT_-0.788700");
    TH1 * plot_B_541_ETA_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_541_ETA_LT_0.449600");
    
    TH1 * plot_B_541_PT_Ratio_low = plot_for_btagging::getRatioPlot(plot_B_541_PT_LT_low, plot_B_541_PT_L, "B_541_PT_Efficinecy_-0.7887");
    TH1 * plot_B_541_PT_Ratio_high = plot_for_btagging::getRatioPlot(plot_B_541_PT_LT_high, plot_B_541_PT_L, "B_541_PT_Efficinecy_0.4496");
    
    TH1 * plot_B_541_ETA_Ratio_low = plot_for_btagging::getRatioPlot(plot_B_541_ETA_LT_low, plot_B_541_ETA_L, "B_541_PT_Efficinecy_-0.7887");
    TH1 * plot_B_541_ETA_Ratio_high = plot_for_btagging::getRatioPlot(plot_B_541_ETA_LT_high, plot_B_541_ETA_L, "B_541_PT_Efficinecy_0.4496");
    
    //B_5122 info
    TH1 * plot_B_5122_PT_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_5122_PT_L");
    TH1 * plot_B_5122_ETA_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_5122_ETA_L");
    
    TH1 * plot_B_5122_PT_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_5122_PT_LT_-0.788700");
    TH1 * plot_B_5122_PT_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_5122_PT_LT_0.449600");
    
    TH1 * plot_B_5122_ETA_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_5122_ETA_LT_-0.788700");
    TH1 * plot_B_5122_ETA_LT_high = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_5122_ETA_LT_0.449600");
    
    TH1 * plot_B_5122_PT_Ratio_low = plot_for_btagging::getRatioPlot(plot_B_5122_PT_LT_low, plot_B_5122_PT_L, "B_5122_PT_Efficinecy_-0.7887");
    TH1 * plot_B_5122_PT_Ratio_high = plot_for_btagging::getRatioPlot(plot_B_5122_PT_LT_high, plot_B_5122_PT_L, "B_5122_PT_Efficinecy_0.4496");
    
    TH1 * plot_B_5122_ETA_Ratio_low = plot_for_btagging::getRatioPlot(plot_B_5122_ETA_LT_low, plot_B_5122_ETA_L, "B_5122_PT_Efficinecy_-0.7887");
    TH1 * plot_B_5122_ETA_Ratio_high = plot_for_btagging::getRatioPlot(plot_B_5122_ETA_LT_high, plot_B_5122_ETA_L, "B_5122_PT_Efficinecy_0.4496");
    
    //C_411 info
    TH1 * plot_C_411_PT_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_411_PT_L");
    TH1 * plot_C_411_ETA_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_411_ETA_L");
    
    TH1 * plot_C_411_PT_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_411_PT_LT_-0.788700");
    TH1 * plot_C_411_PT_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_411_PT_LT_0.449600");
    
    TH1 * plot_C_411_ETA_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_411_ETA_LT_-0.788700");
    TH1 * plot_C_411_ETA_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_411_ETA_LT_0.449600");
    
    TH1 * plot_C_411_PT_Ratio_low = plot_for_btagging::getRatioPlot(plot_C_411_PT_LT_low, plot_C_411_PT_L, "C_411_PT_Efficinecy_-0.7887");
    TH1 * plot_C_411_PT_Ratio_high = plot_for_btagging::getRatioPlot(plot_C_411_PT_LT_high, plot_C_411_PT_L, "C_411_PT_Efficinecy_0.4496");
    
    TH1 * plot_C_411_ETA_Ratio_low = plot_for_btagging::getRatioPlot(plot_C_411_ETA_LT_low, plot_C_411_ETA_L, "C_411_PT_Efficinecy_-0.7887");
    TH1 * plot_C_411_ETA_Ratio_high = plot_for_btagging::getRatioPlot(plot_C_411_ETA_LT_high, plot_C_411_ETA_L, "C_411_PT_Efficinecy_0.4496");
    
    //C_421 info
    TH1 * plot_C_421_PT_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_421_PT_L");
    TH1 * plot_C_421_ETA_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_421_ETA_L");
    
    TH1 * plot_C_421_PT_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_421_PT_LT_-0.788700");
    TH1 * plot_C_421_PT_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_421_PT_LT_0.449600");
    
    TH1 * plot_C_421_ETA_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_421_ETA_LT_-0.788700");
    TH1 * plot_C_421_ETA_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_421_ETA_LT_0.449600");
    
    TH1 * plot_C_421_PT_Ratio_low = plot_for_btagging::getRatioPlot(plot_C_421_PT_LT_low, plot_C_421_PT_L, "C_421_PT_Efficinecy_-0.7887");
    TH1 * plot_C_421_PT_Ratio_high = plot_for_btagging::getRatioPlot(plot_C_421_PT_LT_high, plot_C_421_PT_L, "C_421_PT_Efficinecy_0.4496");
    
    TH1 * plot_C_421_ETA_Ratio_low = plot_for_btagging::getRatioPlot(plot_C_421_ETA_LT_low, plot_C_421_ETA_L, "C_421_PT_Efficinecy_-0.7887");
    TH1 * plot_C_421_ETA_Ratio_high = plot_for_btagging::getRatioPlot(plot_C_421_ETA_LT_high, plot_C_421_ETA_L, "C_421_PT_Efficinecy_0.4496");
    
    //C_431 info
    TH1 * plot_C_431_PT_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_431_PT_L");
    TH1 * plot_C_431_ETA_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_431_ETA_L");
    
    TH1 * plot_C_431_PT_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_431_PT_LT_-0.788700");
    TH1 * plot_C_431_PT_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_431_PT_LT_0.449600");
    
    TH1 * plot_C_431_ETA_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_431_ETA_LT_-0.788700");
    TH1 * plot_C_431_ETA_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_431_ETA_LT_0.449600");
    
    TH1 * plot_C_431_PT_Ratio_low = plot_for_btagging::getRatioPlot(plot_C_431_PT_LT_low, plot_C_431_PT_L, "C_431_PT_Efficinecy_-0.7887");
    TH1 * plot_C_431_PT_Ratio_high = plot_for_btagging::getRatioPlot(plot_C_431_PT_LT_high, plot_C_431_PT_L, "C_431_PT_Efficinecy_0.4496");
    
    TH1 * plot_C_431_ETA_Ratio_low = plot_for_btagging::getRatioPlot(plot_C_431_ETA_LT_low, plot_C_431_ETA_L, "C_431_PT_Efficinecy_-0.7887");
    TH1 * plot_C_431_ETA_Ratio_high = plot_for_btagging::getRatioPlot(plot_C_431_ETA_LT_high, plot_C_431_ETA_L, "C_431_PT_Efficinecy_0.4496");
    
    //C_4122 info
    TH1 * plot_C_4122_PT_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_4122_PT_L");
    TH1 * plot_C_4122_ETA_L = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_4122_ETA_L");
    
    TH1 * plot_C_4122_PT_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_4122_PT_LT_-0.788700");
    TH1 * plot_C_4122_PT_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_4122_PT_LT_0.449600");
    
    TH1 * plot_C_4122_ETA_LT_low = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_4122_ETA_LT_-0.788700");
    TH1 * plot_C_4122_ETA_LT_high = plot_for_btagging::getPlot(C_HADRONS_INFO, "C_4122_ETA_LT_0.449600");
    
    TH1 * plot_C_4122_PT_Ratio_low = plot_for_btagging::getRatioPlot(plot_C_4122_PT_LT_low, plot_C_4122_PT_L, "C_4122_PT_Efficinecy_-0.7887");
    TH1 * plot_C_4122_PT_Ratio_high = plot_for_btagging::getRatioPlot(plot_C_4122_PT_LT_high, plot_C_4122_PT_L, "C_4122_PT_Efficinecy_0.4496");
    
    TH1 * plot_C_4122_ETA_Ratio_low = plot_for_btagging::getRatioPlot(plot_C_4122_ETA_LT_low, plot_C_4122_ETA_L, "C_4122_PT_Efficinecy_-0.7887");
    TH1 * plot_C_4122_ETA_Ratio_high = plot_for_btagging::getRatioPlot(plot_C_4122_ETA_LT_high, plot_C_4122_ETA_L, "C_4122_PT_Efficinecy_0.4496");
    
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
    
    //PT info for all B_hadrons Efficiency
    TH1 * plot_B_ALL_PT_Ratio_low = plot_for_btagging::getRatioPlot(plot_B_ALL_PT_LT_low, plot_B_ALL_PT_L, "B_ALL_PT_Efficinecy_-0.7887");
    TH1 * plot_B_ALL_PT_Ratio_high = plot_for_btagging::getRatioPlot(plot_B_ALL_PT_LT_high, plot_B_ALL_PT_L, "B_ALL_PT_Efficinecy_0.4496");
    
    std::vector<TString> legendsArrayEfficiency = {"MV_-0.7887", "MV_0.4496"};
    
    //ETA info for all B_hadrons Efficiency
    TH1 * plot_B_ALL_ETA_Ratio_low = plot_for_btagging::getRatioPlot(plot_B_ALL_ETA_LT_low, plot_B_ALL_ETA_L, "B_ALL_ETA_Efficinecy_-0.7887");
    TH1 * plot_B_ALL_ETA_Ratio_high = plot_for_btagging::getRatioPlot(plot_B_ALL_ETA_LT_high, plot_B_ALL_ETA_L, "B_ALL_ETA_Efficinecy_0.4496");
    
    //PT info for all C_hadrons Efficiency
    TH1 * plot_C_ALL_PT_Ratio_low = plot_for_btagging::getRatioPlot(plot_C_ALL_PT_LT_low, plot_C_ALL_PT_L, "C_ALL_PT_Efficinecy_-0.7887");
    TH1 * plot_C_ALL_PT_Ratio_high = plot_for_btagging::getRatioPlot(plot_C_ALL_PT_LT_high, plot_C_ALL_PT_L, "C_ALL_PT_Efficinecy_0.4496");
    
    //ETA info for all C_hadrons Efficiency
    TH1 * plot_C_ALL_ETA_Ratio_low = plot_for_btagging::getRatioPlot(plot_C_ALL_ETA_LT_low, plot_C_ALL_ETA_L, "C_ALL_ETA_Efficinecy_-0.7887");
    TH1 * plot_C_ALL_ETA_Ratio_high = plot_for_btagging::getRatioPlot(plot_C_ALL_ETA_LT_high, plot_C_ALL_ETA_L, "C_ALL_ETA_Efficinecy_0.4496");
    
    //PT info for all C_hadrons Efficiency
    TH1 * plot_C_ALL_Ratio_low = plot_for_btagging::getRatioPlot(plot_C_ALL_PT_LT_low, plot_C_ALL_PT_L, "C_ALL_PT_Efficinecy_-0.7887");
    TH1 * plot_C_ALL_Ratio_high = plot_for_btagging::getRatioPlot(plot_C_ALL_PT_LT_high, plot_C_ALL_PT_L, "C_ALL_PT_Efficinecy_0.4496");
    
    //Histograms of B hadron counts
    TH1 * plot_B_ALL_Count = plot_for_btagging::getPlot(B_COUNT, "B_Hadron_count");
    TH1 * plot_B_ALL_low_Count = plot_for_btagging::getPlot(B_COUNT, "B_Hadron_count_mv_low");
    TH1 * plot_B_ALL_high_Count = plot_for_btagging::getPlot(B_COUNT, "B_Hadron_count_mv_high");
    
    //Histograms of C hadron counts
    TH1 * plot_C_ALL_Count = plot_for_btagging::getPlot(C_COUNT, "C_Hadron_count");
    TH1 * plot_C_ALL_low_Count = plot_for_btagging::getPlot(C_COUNT, "C_Hadron_count_mv_low");
    TH1 * plot_C_ALL_high_Count = plot_for_btagging::getPlot(C_COUNT, "C_Hadron_count_mv_high");
    
    //Labeled momentum
    TH1 * plot_B_511_PT_RATIO_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_PT_RATIO_L");
    TH1 * plot_B_521_PT_RATIO_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_521_PT_RATIO_L");
    TH1 * plot_B_531_PT_RATIO_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_531_PT_RATIO_L");
    TH1 * plot_B_541_PT_RATIO_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_541_PT_RATIO_L");
    TH1 * plot_B_5122_PT_RATIO_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_5122_PT_RATIO_L");
    
    TH1 * plot_C_411_PT_RATIO_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "C_411_PT_RATIO_L");
    TH1 * plot_C_421_PT_RATIO_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "C_421_PT_RATIO_L");
    TH1 * plot_C_431_PT_RATIO_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "C_431_PT_RATIO_L");
    TH1 * plot_C_441_PT_RATIO_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "C_441_PT_RATIO_L");
    TH1 * plot_C_4122_PT_RATIO_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "C_4122_PT_RATIO_L");
    
    std::vector<TString> legends_B_hadrons = {"511", "521", "531", "541", "5122"};
    std::vector<TString> legends_C_hadrons = {"411", "421", "431", "441", "4122"};

//    *************************************************************
//    
//    *************************************************************
//    
//    *************************************************************
    
    //Results files
    TFile * output_file = new TFile("ALL_H_RESULTS.root", "UPDATE");
    TFile * output_file_B = new TFile("B_RESULTS.root", "UPDATE");
    TFile * output_file_C = new TFile("C_RESULTS.root", "UPDATE");
    TFile * output_file_rate = new TFile("H_PRODUCTION_RATE.root", "UPDATE");
    TFile * output_file_pt_ratio = new TFile("MOMENTUM_RATIO.root", "UPDATE");
    
    output_file_pt_ratio->cd();
    
    plot_for_btagging::overlayNPlots("Hadron to jet momentum_B: 511, 521, 531, 541 and 5122", legends_B_hadrons, plot_B_511_PT_RATIO_L, plot_B_521_PT_RATIO_L, plot_B_531_PT_RATIO_L, plot_B_541_PT_RATIO_L, plot_B_5122_PT_RATIO_L, NULL);
    
    plot_for_btagging::overlayNPlots("Hadron to jet momentum_C: 411, 421, 431, 441 and 4122", legends_C_hadrons, plot_C_411_PT_RATIO_L, plot_C_421_PT_RATIO_L, plot_C_431_PT_RATIO_L, plot_C_441_PT_RATIO_L, plot_C_4122_PT_RATIO_L, NULL);
    
    output_file_pt_ratio->Close();
    
    output_file_rate->cd();
    
    plot_for_btagging::overlayNPlots("Rate: All B hadrons Labeled & (Lab' and Tag') by different MV2C20 cutoffs", legendsArrayAll, plot_B_ALL_Count, plot_B_ALL_low_Count, plot_B_ALL_high_Count, NULL);
    
    plot_for_btagging::overlayNPlots("Rate: All C hadrons Labeled & (Lab' and Tag') by different MV2C20 cutoffs", legendsArrayAll, plot_C_ALL_Count, plot_C_ALL_low_Count, plot_C_ALL_high_Count, NULL);
    
    output_file_rate->Close();
    
    output_file->cd();
    
    plot_for_btagging::overlayNPlots("PT: All B hadrons - Labeled & (Lab' and Tag') by different MV2C20 cutoffs", legendsArrayAll,plot_B_ALL_PT_L, plot_B_ALL_PT_LT_low, plot_B_ALL_PT_LT_high, NULL);
    
    plot_for_btagging::overlayNPlots("PT: All C hadrons - Labeled & (Lab' and Tag') by different MV2C20 cutoffs", legendsArrayAll,plot_C_ALL_PT_L, plot_C_ALL_PT_LT_low, plot_C_ALL_PT_LT_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: All B hadrons - Labeled & (Lab' and Tag') by different MV2C20 cutoffs", legendsArrayAll,plot_B_ALL_ETA_L, plot_B_ALL_ETA_LT_low, plot_B_ALL_ETA_LT_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: All C hadrons - Labeled & (Lab' and Tag') by different MV2C20 cutoffs", legendsArrayAll,plot_C_ALL_ETA_L, plot_C_ALL_ETA_LT_low, plot_C_ALL_ETA_LT_high, NULL);
    
    plot_for_btagging::overlayNPlots("PT: All B hadrons - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_ALL_PT_Ratio_low, plot_B_ALL_PT_Ratio_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: All B hadrons - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_ALL_ETA_Ratio_low, plot_B_ALL_ETA_Ratio_high, NULL);
    
    plot_for_btagging::overlayNPlots("PT: All C hadrons - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_ALL_PT_Ratio_low, plot_C_ALL_PT_Ratio_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: All C hadrons - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_ALL_ETA_Ratio_low, plot_C_ALL_ETA_Ratio_high, NULL);
    
    output_file->Close();
    
    ///Specific B_hadron efficiency
    output_file_B->cd();
    
    //B_511
    plot_for_btagging::overlayNPlots("PT: B_511 - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_511_PT_Ratio_low, plot_B_511_PT_Ratio_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: B_511 - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_511_ETA_Ratio_low, plot_B_511_ETA_Ratio_high, NULL);
    
    //B_521
    plot_for_btagging::overlayNPlots("PT: B_521 - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_521_PT_Ratio_low, plot_B_521_PT_Ratio_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: B_521 - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_521_ETA_Ratio_low, plot_B_521_ETA_Ratio_high, NULL);
    
    //B_531
    plot_for_btagging::overlayNPlots("PT: B_531 - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_531_PT_Ratio_low, plot_B_531_PT_Ratio_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: B_531 - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_531_ETA_Ratio_low, plot_B_531_ETA_Ratio_high, NULL);
    
    //B_541
    plot_for_btagging::overlayNPlots("PT: B_541 - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_541_PT_Ratio_low, plot_B_541_PT_Ratio_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: B_541 - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_B_541_ETA_Ratio_low, plot_B_541_ETA_Ratio_high, NULL);
    
    output_file_B->Close();
    
    ///Specific C_hadron efficiency
    output_file_C->cd();
    
    //C_411
    plot_for_btagging::overlayNPlots("PT: C_411 - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_411_PT_Ratio_low, plot_C_411_PT_Ratio_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: C_411 - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_411_ETA_Ratio_low, plot_C_411_ETA_Ratio_high, NULL);
    
    //C_421
    plot_for_btagging::overlayNPlots("PT: C_421 - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_421_PT_Ratio_low, plot_C_421_PT_Ratio_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: C_421 - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_421_ETA_Ratio_low, plot_C_421_ETA_Ratio_high, NULL);
    
    //C_431
    plot_for_btagging::overlayNPlots("PT: C_431 - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_431_PT_Ratio_low, plot_C_431_PT_Ratio_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: C_431 - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_431_ETA_Ratio_low, plot_C_431_ETA_Ratio_high, NULL);
    
    //C_4122
    plot_for_btagging::overlayNPlots("PT: C_4122 - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_4122_PT_Ratio_low, plot_C_4122_PT_Ratio_high, NULL);
    
    plot_for_btagging::overlayNPlots("ETA: C_4122 - Efficiency with respects to different MV2C20 cutoffs", legendsArrayEfficiency, plot_C_4122_ETA_Ratio_low, plot_C_4122_ETA_Ratio_high, NULL);
    
    output_file_B->Close();
    
    return 0;
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

TH1* plot_for_btagging::getRatioPlot(TH1* plot1, TH1* plot2, TString plotName) {
    
    TH1 * ratio = (TH1F*) plot1->Clone();
    ratio->SetTitle(plotName);
    ratio->SetName(plotName);
    ratio->Divide(plot1,plot2,1,1, "B");
    return ratio;
}

void plot_for_btagging::ratioPlots(TH1* plot1, TH1* plot2, TString plotName) {
    
    TH1 * ratio = (TH1F*) plot1->Clone();
    ratio->SetTitle(plotName);
    ratio->SetName(plotName);
    ratio->Divide(plot2);
    ratio->Write();
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
