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
    
    //Initialise TString with histograms we need from output_plots
    TString storeRootFileName = "output_plots.root";
    
    TH1* plot1 = plot_for_btagging::getPlot(storeRootFileName, "B_511_PT_L");
    TH1* plot2 = plot_for_btagging::getPlot(storeRootFileName, "B_531_PT_L");
    
    TFile * output_file = new TFile("output_plots_test.root", "UPDATE");
    
    output_file->cd();
    
    plot_for_btagging::ratioPlots(plot1, plot2, "PT");

    output_file->Close();
    
    return 0;
}

// RAM'S SENT STUFF
//TString [2] plotsToOverlay;
//plotsToOverlay = {"PT Labled","PT Labled and Tagged"};

//for (int i = 0, i<2, i++) {

//Acessing a rootfile and setting it up for reading using option: "READ"
//TFile storeRootFile = TFile(storeRootFileName, "READ");
//if (storeRootFile.cd()) {
//TH1 * plot1 =
//}

//cout<<"Reading plots from: "<<storeRootFileName
//}

//return 0;


void plot_for_btagging::overlayPlots(TH1* plot1, TH1* plot2, TString parameter) {
    
    TString plotname = hadron_type+" - "+parameter+" - Overlay"+" - Hadron: "+std::to_string(hadron_number)+" MV:"+std::to_string(mv_value);
    
    //Cretes a directory
    system("mkdir Overlays");
    
    TH1 * plot1_clone = (TH1F*) plot1->Clone();
    TH1 * plot2_clone = (TH1F*) plot2->Clone();
    
    plot1_clone->SetTitle(plotname);
    
    TLegend * legend = new TLegend(0.8,0.8,1,1, "", "NDC");
    legend->AddEntry(plot1_clone, "Labeled", "LEP");
    legend->AddEntry(plot2_clone, "L' and Tagged", "LEP");
    
    TCanvas *c = new TCanvas();
    
    plot1_clone->SetLineColor(2);
    plot1_clone->DrawCopy();
    plot2_clone->SetLineColor(4);
    plot2_clone->DrawCopy("same");
    legend->Draw();
    
    c->Print("Overlays/"+plotname+".eps");
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
