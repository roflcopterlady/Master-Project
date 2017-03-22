//
//  compare_generators.hpp
//
//
//  Created by Kavushik Mohan Raj  on 28/02/2017.
//
//

#ifndef compare_generators_hpp
#define compare_generators_hpp

#include "TString.h"
#include "TFile.h"
#include "TH1.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "array"
#include <iostream>

#include "utils.hpp"

#include <stdio.h>

class compare_generators {
    
public: static TH1* getPlot(std::string fileName, TString plotName);
    
public: static TH1* getEffPlot(TH1* plot1, TH1* plot2, TString plotName);
    
public: static void overlaysForCategory(std::string fileName, std::vector<std::string> generators);
    
public: static void differenceBetweenEfficiencies(std::string generator1, std::string generator2, std::vector<std::string> fileNames);
    
public: static void ratioBetweenEfficiencies(std::string generator1, std::string generator2, std::vector<std::string> fileNames);
    
};


#endif /* compare_generators_hpp */
