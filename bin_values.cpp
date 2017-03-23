//
//  bin_values.cpp
//  
//
//  Created by Kavushik Mohan Raj  on 23/03/2017.
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

#include "bin_values.hpp"

int main() {
    
    std::string powhegPy8 = "EFFICIENCY_PowhegPy8.root";
    std::string powhegPy6 = "EFFICIENCY_PowhegPy8.root";
    std::string powhegHpp = "EFFICIENCY_PowhegHpp.root";
    std::string MG5Py8 = "EFFICIENCY_MG5aMCPy8.root";
    std::string MG5Hpp = "EFFICIENCY_MG5aMCHpp.root";
    std::string MCnloHpp = "EFFICIENCY_aMCNLOhpp.root";
    
    TH1 * B_511_ETA_MG5Py8 = bin_values::getPlot(MG5Py8, "B_511_ETA_EFF_-0.7887");
    
    Double_t test = B_511_ETA_MG5Py8->GetBinContent(50);
    
};

TH1* bin_values::getPlot(std::string fileName, TString plotName) {
    
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

