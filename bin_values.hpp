//
//  bin_values.hpp
//  
//
//  Created by Kavushik Mohan Raj  on 23/03/2017.
//
//

#ifndef bin_values_hpp
#define bin_values_hpp

#include "TString.h"
#include "TFile.h"
#include "TH1.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "array"
#include <iostream>

#include "utils.hpp"


#include <stdio.h>

#endif /* bin_values_hpp */

class bin_values {
    
public: static TH1* getPlot(std::string fileName, TString plotName);
    
};



