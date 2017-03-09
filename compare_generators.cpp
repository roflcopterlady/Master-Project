//
//  compare_generators.cpp
//
//
//  Created by Kavushik Mohan Raj  on 28/02/2017.
//
//

#define compare_generators_cxx
#include "TString.h"
#include "TFile.h"
#include "TH1.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "array"
#include <iostream>
#include <string>
#include <map>

#include "compare_generators.hpp"

std::string hadron_type = "B";

int main() {
    
    //,"Sherpa.SLM.output.root","Sherpa.DL.output.root", "Sherpa.AllHadronic.output.root"
    //"MG5aMCPy8.AllHadronic.output.root",
    
    std::vector<std::string> generatorNames = {
        "PowhegPy8", "PowhegPy6",
        "PowhegHpp", "MG5aMCPy8",
        "MG5aMChpp", "aMCNLOhpp"};
    
    compare_generators::overlaysForCategory("EFFICIENCY", "_ALL_PT_low", hadron_type+"_ALL_PT_EFF_-0.7887", generatorNames, true);
    
    compare_generators::overlaysForCategory("EFFICIENCY",
                                            "_ALL_PT_high",
                                            hadron_type+"_ALL_PT_EFF_0.4496",
                                            generatorNames, true);
    
    compare_generators::overlaysForCategory("EFFICIENCY", "_ALL_ETA_low", hadron_type+"_ALL_ETA_EFF_-0.7887", generatorNames, true);
    compare_generators::overlaysForCategory("EFFICIENCY", "_ALL_ETA_high",hadron_type+"_ALL_ETA_EFF_0.4496", generatorNames, true);
    
    compare_generators::overlaysForCategory("EFFICIENCY", "_ALL_HLOC_low", hadron_type+"_ALL_HLOC_EFF_-0.7887", generatorNames, true);
    compare_generators::overlaysForCategory("EFFICIENCY", "_ALL_HLOC_high",hadron_type+"_ALL_HLOC_EFF_0.4496", generatorNames, true);
    
    compare_generators::overlaysForCategory("EFFICIENCY", "_ALL_PT_H_VS_J_low", hadron_type+"_PT_H_VS_J_LT_EFF_-0.7887", generatorNames, true);
    compare_generators::overlaysForCategory("EFFICIENCY", "_ALL_PT_H_VS_J_high",hadron_type+"_PT_H_VS_J_LT_EFF_0.4496", generatorNames, true);
    
    compare_generators::overlaysForCategory("EFFICIENCY", "_PR_low", hadron_type+"_PR_EFF_-0.7887", generatorNames, true);
    compare_generators::overlaysForCategory("EFFICIENCY", "_PR_high",hadron_type+"_PR_EFF_0.4496", generatorNames, true);
    
    if (hadron_type == "B") {
        compare_generators::overlaysForCategory("EFFICIENCY", "_511_PT_low", hadron_type+"_511_PT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_511_PT_high",hadron_type+"_511_PT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_511_ETA_low", hadron_type+"_511_ETA_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_511_ETA_high",hadron_type+"_511_ETA_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_511_PT_H_VS_J_low", hadron_type+"_511_PT_H_VS_J_LT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_511_PT_H_VS_J_high",hadron_type+"_511_PT_H_VS_J_LT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_511_LOC_low", hadron_type+"_511_HLOC_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_511_LOC_high",hadron_type+"_511_HLOC_EFF_0.4496", generatorNames, true);
        
        compare_generators::overlaysForCategory("EFFICIENCY", "_521_PT_low", hadron_type+"_521_PT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_521_PT_high",hadron_type+"_521_PT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_521_ETA_low", hadron_type+"_521_ETA_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_521_ETA_high",hadron_type+"_521_ETA_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_521_PT_H_VS_J_low", hadron_type+"_521_PT_H_VS_J_LT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_521_PT_H_VS_J_high",hadron_type+"_521_PT_H_VS_J_LT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_521_LOC_low", hadron_type+"_521_HLOC_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_521_LOC_high",hadron_type+"_521_HLOC_EFF_0.4496", generatorNames, true);
        
        compare_generators::overlaysForCategory("EFFICIENCY", "_531_PT_low", hadron_type+"_531_PT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_531_PT_high",hadron_type+"_531_PT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_531_ETA_low", hadron_type+"_531_ETA_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_531_ETA_high",hadron_type+"_531_ETA_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_531_PT_H_VS_J_low", hadron_type+"_531_PT_H_VS_J_LT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_531_PT_H_VS_J_high",hadron_type+"_531_PT_H_VS_J_LT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_531_LOC_low", hadron_type+"_531_HLOC_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_531_LOC_high",hadron_type+"_531_HLOC_EFF_0.4496", generatorNames, true);
        
        compare_generators::overlaysForCategory("EFFICIENCY", "_541_PT_low", hadron_type+"_541_PT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_541_PT_high",hadron_type+"_541_PT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_541_ETA_low", hadron_type+"_541_ETA_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_541_ETA_high",hadron_type+"_541_ETA_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_541_PT_H_VS_J_low", hadron_type+"_541_PT_H_VS_J_LT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_541_PT_H_VS_J_high",hadron_type+"_541_PT_H_VS_J_LT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_541_LOC_low", hadron_type+"_541_HLOC_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_541_LOC_high",hadron_type+"_541_HLOC_EFF_0.4496", generatorNames, true);
        
        compare_generators::overlaysForCategory("EFFICIENCY", "_5122_PT_low", hadron_type+"_5122_PT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_5122_PT_high",hadron_type+"_5122_PT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_5122_ETA_low", hadron_type+"_5122_ETA_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_5122_ETA_high",hadron_type+"_5122_ETA_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_5122_PT_H_VS_J_low", hadron_type+"_5122_PT_H_VS_J_LT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_5122_PT_H_VS_J_high",hadron_type+"_5122_PT_H_VS_J_LT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_5122_LOC_low", hadron_type+"_5122_HLOC_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_5122_LOC_high",hadron_type+"_5122_HLOC_EFF_0.4496", generatorNames, true);
    }
    else {
        compare_generators::overlaysForCategory("EFFICIENCY", "_411_PT_low", hadron_type+"_411_PT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_411_PT_high",hadron_type+"_411_PT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_411_ETA_low", hadron_type+"_411_ETA_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_411_ETA_high",hadron_type+"_411_ETA_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_411_PT_H_VS_J_low", hadron_type+"_411_PT_H_VS_J_LT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_411_PT_H_VS_J_high",hadron_type+"_411_PT_H_VS_J_LT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_411_LOC_low", hadron_type+"_411_HLOC_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_411_LOC_high",hadron_type+"_411_HLOC_EFF_0.4496", generatorNames, true);
        
        compare_generators::overlaysForCategory("EFFICIENCY", "_421_PT_low", hadron_type+"_421_PT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_421_PT_high",hadron_type+"_421_PT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_421_ETA_low", hadron_type+"_421_ETA_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_421_ETA_high",hadron_type+"_421_ETA_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_421_PT_H_VS_J_low", hadron_type+"_421_PT_H_VS_J_LT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_421_PT_H_VS_J_high",hadron_type+"_421_PT_H_VS_J_LT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_421_LOC_low", hadron_type+"_421_HLOC_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_421_LOC_high",hadron_type+"_421_HLOC_EFF_0.4496", generatorNames, true);
        
        compare_generators::overlaysForCategory("EFFICIENCY", "_431_PT_low", hadron_type+"_431_PT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_431_PT_high",hadron_type+"_431_PT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_431_ETA_low", hadron_type+"_431_ETA_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_431_ETA_high",hadron_type+"_431_ETA_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_431_PT_H_VS_J_low", hadron_type+"_431_PT_H_VS_J_LT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_431_PT_H_VS_J_high",hadron_type+"_431_PT_H_VS_J_LT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_431_LOC_low", hadron_type+"_431_HLOC_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_431_LOC_high",hadron_type+"_431_HLOC_EFF_0.4496", generatorNames, true);
        
        compare_generators::overlaysForCategory("EFFICIENCY", "_4122_PT_low", hadron_type+"_4122_PT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_4122_PT_high",hadron_type+"_4122_PT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_4122_ETA_low", hadron_type+"_4122_ETA_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_4122_ETA_high",hadron_type+"_4122_ETA_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_4122_PT_H_VS_J_low", hadron_type+"_4122_PT_H_VS_J_LT_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_4122_PT_H_VS_J_high",hadron_type+"_4122_PT_H_VS_J_LT_EFF_0.4496", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_4122_LOC_low", hadron_type+"_4122_HLOC_EFF_-0.7887", generatorNames, true);
        compare_generators::overlaysForCategory("EFFICIENCY", "_4122_LOC_high",hadron_type+"_4122_HLOC_EFF_0.4496", generatorNames, true);
    }
    
    return 0;
}


void compare_generators::overlaysForCategory(std::string categoryString, std::string output_name,
                                             TString fileName, std::vector<std::string> generators,
                                             bool effTest) {
    
    std::vector<TH1*> clones_to_overlay;
    
    for (std::string generator: generators) {
        
        std::string result_file_name;
        
        if (effTest) {
            result_file_name = categoryString+"_"+generator+".root";
            
        }else {
            result_file_name = generator+"_"+hadron_type+"_"+categoryString+".root";
        }
        
        TH1 * currentPlot = compare_generators::getPlot(result_file_name, fileName);
        TH1* currentClone = (TH1F*) currentPlot->Clone();
        
        clones_to_overlay.push_back(currentClone);
    }
    
    TLegend * legend = new TLegend(0.8,0.8,1,1, "", "NDC");
    for (int i=0; i<generators.size(); i++) {
        
        std::string legend_string = generators.at(i);
        
        char const * legend_char = legend_string.c_str();
        
        legend->AddEntry(clones_to_overlay.at(i), legend_char, "LEP");
    }
    
    TCanvas * c = new TCanvas();
    
    int colourCounter = 1;
    
    for (TH1* histogram: clones_to_overlay) {
        
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
    
    std::string output_file_string = "COMPARE_"+hadron_type+"_"+categoryString+output_name+".root";
    
    char const *output_file = output_file_string.c_str();
    
    TFile * test_compare =  new TFile("RESULTS.root", "UPDATE");
    
    test_compare->cd();
    
    c->SetName(output_file);
    c->Write();
    c->Update();
    
    test_compare->Close();
}

TH1* compare_generators::getPlot(std::string fileName, TString plotName) {
    
    std::string output_file_string = fileName;
    
    char const *output_file = output_file_string.c_str();
    
    TFile * f = new TFile(output_file, "READ");
    
    f->cd();
    TH1 * plot = (TH1F*)gDirectory->Get(plotName);
    plot->SetDirectory(0);
    plot->SetStats(0);
    f->Close();
    
    return plot;
}
