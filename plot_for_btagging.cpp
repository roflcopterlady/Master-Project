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
#include "utils.hpp"

int hadron_number;
float mv_value;

TString hadron_type = "B"; 

int main() {

  //Initialise TString with histograms we need from output_plots
  TString storeRootFileName = "output_plots.root";

  std::array<TString,2> plotnames = {"desiredplotname1","desiredplotname2"};

  for (int i=0; i<2; i++) { 

    TString plotname = plotnames[i];
    
  // Access this rootfile, read it
  TFile * f = new TFile(storeRootFileName, "READ");
  f->cd();

  //gDirectory is current directory, get the file from cd
  TH1 * plot1 = (TH1F*)gDirectory->Get(storeRootFileName);
  plot1->SetDirectory(0);
  plot1->SetStats(0);
  f->Close();

  std::cout<<"Reading Plots From: "<<storeRootFileName;
  }
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
    system("mkdir Overlays C-Hadron");
    
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

void plot_for_btagging::ratioPlots(TH1* plot1, TH1* plot2, TString parameter) {
    
    TH1 * ratio = (TH1F*) plot1->Clone();
    ratio->SetTitle(hadron_type+" - "+parameter+" - Ratio"+" - Hadron: "+std::to_string(hadron_number)+" MV:"+std::to_string(mv_value));
    ratio->SetName(hadron_type+" - "+parameter+" - Ratio"+" - Hadron: "+std::to_string(hadron_number)+" MV:"+std::to_string(mv_value));
    ratio->Divide(plot2);
    ratio->Write();
}
