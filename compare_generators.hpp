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
    
public: static void compareGenerators(std::vector<TString> generatorNames);
    
public: static TH1* getPlot(std::string fileName, TString plotName);
    
public: static void overlayNPlots(TString plotName, std::vector<TString> legendsVector, TH1* plot1,...);
    
public: static TH1* getEffPlot(TH1* plot1, TH1* plot2, TString plotName);
    
public: static void compareHadronProdcutionRate(std::vector<TString> generators);
    
public: static void overlaysForCategory(std::string categoryString, std::string output_name, TString fileName, std::vector<std::string> generators, bool effTest);

};


#endif /* compare_generators_hpp */
