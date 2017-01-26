//
//  plot_for_btagging.hpp
//
//
//  Created by Kavushik Mohan Raj  on 15/01/2017.
//
//

#ifndef plot_for_btagging_h
#define plot_for_btagging_h

#include "TString.h"
#include "TFile.h"
#include "TH1.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "array"
#include <iostream>

#include "utils.hpp"

class plot_for_btagging {
    
public: static void overlayPlots(TH1* plot1, TH1* plot2, TString parameter);
public: static void ratioPlots(TH1* plo1, TH1* plot2, TString plotName);
public: static TH1* getPlot(TString fileName, TString plotName);
    
};


#endif /* plot_for_btagging_h */



