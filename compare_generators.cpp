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

    std::vector<std::string> generatorNames = {
        "PowhegPy8", "PowhegPy6",
        "PowhegHpp", "MG5aMCPy8",
        "MG5aMChpp", "aMCNLOhpp"
};

    std::vector<std::string> b_hadron_eff_files = {
        "B_ALL_PT_EFF_-0.7887","B_ALL_PT_EFF_0.4496",
        "B_ALL_ETA_EFF_-0.7887","B_ALL_ETA_EFF_0.4496",
        "B_ALL_DR_EFF_-0.7887","B_ALL_DR_EFF_0.4496",
        "B_ALL_PT_H_VS_J_LT_EFF_-0.7887","B_ALL_PT_H_VS_J_LT_EFF_0.4496",
        "B_PR_EFF_0.4496","B_PR_EFF_-0.7887",
        "B_511_PT_EFF_-0.7887","B_511_PT_EFF_0.4496",
        "B_511_ETA_EFF_-0.7887","B_511_ETA_EFF_0.4496",
        "B_511_PT_H_VS_J_LT_EFF_-0.7887","B_511_PT_H_VS_J_LT_EFF_0.4496",
        "B_511_HLOC_EFF_-0.7887","B_511_HLOC_EFF_0.4496",
        "B_521_PT_EFF_-0.7887","B_521_PT_EFF_0.4496",
        "B_521_ETA_EFF_-0.7887","B_521_ETA_EFF_0.4496",
        "B_521_PT_H_VS_J_LT_EFF_-0.7887","B_521_PT_H_VS_J_LT_EFF_0.4496",
        "B_521_HLOC_EFF_-0.7887","B_521_HLOC_EFF_0.4496",
        "B_531_PT_EFF_-0.7887","B_531_PT_EFF_0.4496",
        "B_531_ETA_EFF_-0.7887","B_531_ETA_EFF_0.4496",
        "B_531_PT_H_VS_J_LT_EFF_-0.7887","B_531_PT_H_VS_J_LT_EFF_0.4496",
        "B_531_HLOC_EFF_-0.7887","B_531_HLOC_EFF_0.4496",
        "B_541_PT_EFF_-0.7887","B_541_PT_EFF_0.4496",
        "B_541_ETA_EFF_-0.7887","B_541_ETA_EFF_0.4496",
        "B_541_PT_H_VS_J_LT_EFF_-0.7887","B_541_PT_H_VS_J_LT_EFF_0.4496",
        "B_541_HLOC_EFF_-0.7887","B_541_HLOC_EFF_0.4496",
        "B_5122_PT_EFF_-0.7887","B_5122_PT_EFF_0.4496",
        "B_5122_ETA_EFF_-0.7887","B_5122_ETA_EFF_0.4496",
        "B_5122_PT_H_VS_J_LT_EFF_-0.7887","B_5122_PT_H_VS_J_LT_EFF_0.4496",
        "B_5122_HLOC_EFF_-0.7887","B_5122_HLOC_EFF_0.4496"
    };

    std::vector<std::string> c_hadron_eff_files = {

        "C_ALL_PT_EFF_-0.7887","C_ALL_PT_EFF_0.4496",
        "C_ALL_ETA_EFF_-0.7887", "C_ALL_ETA_EFF_0.4496",
        "C_ALL_DR_EFF_-0.7887", "C_ALL_DR_EFF_0.4496",
        "C_ALL_PT_H_VS_J_LT_EFF_-0.7887", "C_ALL_PT_H_VS_J_LT_EFF_0.4496",
        "C_PR_EFF_0.4496", "C_PR_EFF_-0.7887",
        "C_411_PT_EFF_-0.7887", "C_411_PT_EFF_0.4496",
        "C_411_ETA_EFF_-0.7887", "C_411_ETA_EFF_0.4496",
        "C_411_PT_H_VS_J_LT_EFF_-0.7887", "C_411_PT_H_VS_J_LT_EFF_0.4496",
        "C_411_HLOC_EFF_-0.7887", "C_411_HLOC_EFF_0.4496",
        "C_421_PT_EFF_-0.7887", "C_421_PT_EFF_0.4496",
        "C_421_ETA_EFF_-0.7887", "C_421_ETA_EFF_0.4496",
        "C_421_PT_H_VS_J_LT_EFF_-0.7887","C_421_PT_H_VS_J_LT_EFF_0.4496",
        "C_421_HLOC_EFF_-0.7887","C_421_HLOC_EFF_0.4496",
        "C_431_PT_EFF_-0.7887","C_431_PT_EFF_0.4496",
        "C_431_ETA_EFF_-0.7887","C_431_ETA_EFF_0.4496",
        "C_431_PT_H_VS_J_LT_EFF_-0.7887","C_431_PT_H_VS_J_LT_EFF_0.4496",
        "C_431_HLOC_EFF_-0.7887","C_431_HLOC_EFF_0.4496",
        "C_4122_PT_EFF_-0.7887","C_4122_PT_EFF_0.4496",
        "C_4122_ETA_EFF_-0.7887", "C_4122_ETA_EFF_0.4496",
        "C_4122_PT_H_VS_J_LT_EFF_-0.7887", "C_4122_PT_H_VS_J_LT_EFF_0.4496",
        "C_4122_HLOC_EFF_-0.7887", "C_4122_HLOC_EFF_0.4496"
    };

    return 0;
}


void compare_generators::ratioBetweenEfficiencies(std::string generator1,
                                                  std::string generator2,
                                                  std::vector<std::string> fileNames) {

    std::string result_file_name1 = "EFFICIENCY_"+generator1+".root";
    std::string result_file_name2 = "EFFICIENCY_"+generator2+".root";

    for (std::string fileName: fileNames) {

        TH1 * currentPlot1 = compare_generators::getPlot(result_file_name1, fileName);
        TH1* currentClone1 = (TH1F*) currentPlot1->Clone();

        TH1 * currentPlot2 = compare_generators::getPlot(result_file_name2, fileName);
        TH1* currentClone2 = (TH1F*) currentPlot2->Clone();

        TH1 * ratio_plot = compare_generators::getEffPlot(currentClone1, currentClone2, fileName);
        ratio_plot->SetAxisRange(0,2,"Y");
        ratio_plot->SetYTitle("Ratio");
        ratio_plot->SetAxisRange(0.8,1.4,"Y");

        std::string output_name = "RATIO_BETWEEN_"+hadron_type+"_"+generator1+"_"+generator2+".root";
        char const * output_name_char = output_name.c_str();

        TFile * compare_file =  new TFile(output_name_char, "RECREATE");

        compare_file->cd();

        ratio_plot->Write();

        compare_file->Close();

    }
}

void compare_generators::overlaysForCategory(std::string fileName, std::vector<std::string> generators, std::string prefix) {

    std::vector<TH1*> clones_to_overlay;

    for (std::string generator: generators) {

        std::string result_file_name;

        result_file_name = std::string("EFFICIENCY")+"_"+generator+".root";

        char const *file_name_char = fileName.c_str();

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

    char const * output_file = fileName.c_str();

    std::string result_file_name_string = prefix+"_COMPARING_GENERATORS.root";
    char const * result_file_name = result_file_name_string.c_str();

    TFile * test_compare =  new TFile(result_file_name, "RECREATE");

    test_compare->cd();

    c->SetName(output_file);
    c->Write();
    c->Update();

    test_compare->Close();
}

void compare_generators::differenceBetweenEfficiencies(std::string generator1,
                                                       std::string generator2,
                                                       std::vector<std::string> fileNames) {

    std::string result_file_name1 = "EFFICIENCY_"+generator1+".root";
    std::string result_file_name2 = "EFFICIENCY_"+generator2+".root";

    for (std::string fileName: fileNames) {

        TH1 * currentPlot1 = compare_generators::getPlot(result_file_name1, fileName);
        TH1* currentClone1 = (TH1F*) currentPlot1->Clone();

        TH1 * currentPlot2 = compare_generators::getPlot(result_file_name2, fileName);
        TH1* currentClone2 = (TH1F*) currentPlot2->Clone();

        currentClone1->Add(currentClone2, -1);

        std::string output_name = "DIFF_BETWEEN_"+generator1+"_"+generator2+".root";
        char const * output_name_char = output_name.c_str();

        TFile * compare_file =  new TFile(output_name_char, "RECREATE");

        compare_file->cd();

        currentClone1->Write();

        compare_file->Close();

    }
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

TH1* compare_generators::getEffPlot(TH1* plot1, TH1* plot2, TString plotName) {

    TH1 * Eff = (TH1F*) plot1->Clone();
    Eff->SetTitle(plotName);
    Eff->SetName(plotName);
    Eff->Divide(plot1,plot2,1,1, "B");
    Eff->SetAxisRange(0, 1, "Y");
    return Eff;
}
