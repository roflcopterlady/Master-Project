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
    
    //PT info for 511
    TH1 * plot_B_511_PT_L = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_PT_L");
    TH1 * plot_B_511_PT_LT_low = plot_for_btagging::getPlot(B_HADRONS_INFO, "B_511_PT_LT_-0.788700");
    TH1 * plot_B_511_PT_Ratio = plot_for_btagging::getRatioPlot(plot_B_511_PT_LT_low, plot_B_511_PT_L, "B_511_PT_Ratio");
    
    //PT infor for all B_hadrons
    TH1 * plot_B_ALL_PT_L = plot_for_btagging::getPlot(B_ALL, "B_ALL_PT_L");
    TH1 * plot_B_ALL_PT_LT_low = plot_for_btagging::getPlot(B_ALL, "B_ALL_PT_LT_-0.7887");
    TH1 * plot_B_ALL_Ratio = plot_for_btagging::getRatioPlot(plot_B_ALL_PT_LT_low, plot_B_ALL_PT_L, "B_ALL_PT_Ratio");
    
    //Histograms of hadron counts
    TH1 * plot_B_ALL_Count = plot_for_btagging::getPlot(B_COUNT, "B_Hadron_count");
    TH1 * plot_B_ALL_low_Count = plot_for_btagging::getPlot(B_COUNT, "B_Hadron_count_mv_low");
    
    TFile * output_file = new TFile("RESULTS.root", "UPDATE");
    
    output_file->cd();
    plot_B_511_PT_Ratio->Write();
    plot_B_ALL_Ratio->Write();
    
    plot_for_btagging::overlayPlots(plot_B_511_PT_Ratio, plot_B_ALL_Ratio,
                                    "All B hadrons and B_511 PT ratios for MV_-0.7887" ,
                                    "B_511_PT: LT to L ratio",
                                    "B_ALL_PT: LT to L ratio");
    plot_for_btagging::overlayPlots(plot_B_ALL_Count, plot_B_ALL_low_Count,
                                    "All B hadrons count for MV_-0.7887" ,
                                    "ALL",
                                    "Tagged by MV_-0.7887");
    
    output_file->Close();
    
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
    
    //colour = kRed , kBlue
    
    //c->Print("Overlays/"+plotname+".eps");
    c->Write();
    c->Update();
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

void plot_for_btagging::overlayNPlots(TString plotName, TH1* plot1,...) {
    
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
    
    TCanvas * c = new TCanvas();
    
    int colourCounter = 1;
    
    for (TH1* histogram: clonePlotArray) {
        
        if (colourCounter == 1) {
            histogram->DrawCopy();
        }
        else {
            histogram->DrawCopy("same");
        }
        
        histogram->SetLineColor(colourCounter);
        colourCounter+=1;
    }
    
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
