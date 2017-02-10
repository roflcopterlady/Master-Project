#include "TPaveText.h"
#include "TString.h"

using std::cout;
using std::endl;


//=================================================================================

TString hname[2] = {"521", "421"};
TString tname[4] = {"85", "80", "70", "60"};

//float tag[4] = {-0.7887, -0.5911, -0.0436, 0.4496}; OLD ARRAY
float tag[2] = {-0.7887, 0.4496};

std::vector<float> b_hadrons = {511, 521, 531, 541, 5122, 5132, 5232, 5332, 5142, 5242};
std::vector<float> c_hadrons = {411, 421, 431, 4122, 4132, 4232, 4332};

//====================================================h_bdR_min
int map(int ihlabel, bool isb = false) {
    
    ///C-Hadrons
	int hlabel = abs(ihlabel);
	if(hlabel == 411) return 0;
	if(hlabel == 421) return 1;
	if(hlabel == 431) return 2;
	if(hlabel == 4122) return 3;
	if(hlabel == 4132) return 4;
	if(hlabel == 4232) return 5;
	if(hlabel == 4332) return 6;

	if(isb) {
		if(hlabel == 0) return 511;
		if(hlabel == 1) return 521;
		if(hlabel == 2) return 531;
		if(hlabel == 3) return 541;
		if(hlabel == 4) return 5122;
		if(hlabel == 5) return 5132;
		if(hlabel == 6) return 5232;
		if(hlabel == 7) return 5332;
		if(hlabel == 8) return 5142;
		if(hlabel == 9) return 5242;
	}
	if(hlabel == 0) return 411;
	if(hlabel == 1) return 421;
	if(hlabel == 2) return 431;
	if(hlabel == 3) return 4122;
	if(hlabel == 4) return 4132;
	if(hlabel == 5) return 4232;
	if(hlabel == 6) return 4332;

    
    ///B-Hadrons
	if(hlabel==511) return 0;
	if(hlabel==521) return 1;
	if(hlabel==531) return 2;
	if(hlabel==541) return 3;
	if(hlabel==5122) return 4;
	if(hlabel==5132) return 5;
	if(hlabel==5232) return 6;
	if(hlabel==5332) return 7;

	if(hlabel==5142) return 8;
	if(hlabel==5242) return 9;

	cout<<"unknown hadron in map: "<<hlabel<<" ! Returning -1"<<endl;
	return -1;

}



//====================================================================================


TString relabel(TString label) {

	if(!label.CompareTo("411")) return "D^{+}";
	else if(!label.CompareTo("421")) return "D^{0}";
	else if(!label.CompareTo("431")) return "D_{s}^{+}";
	else if(!label.CompareTo("4122")) return "#Lambda_{c}^{+}";
	else if(!label.CompareTo("4132")) return "#Xi_{c}^{0}";
	else if(!label.CompareTo("4232")) return "#Xi_{c}^{+}";
	else if(!label.CompareTo("4332")) return "#Omega_{c}^{0}";
	
	if(!label.CompareTo("511")) return "B^{0}";
	if(!label.CompareTo("521")) return "B^{+}";
	if(!label.CompareTo("531")) return "B_{s}^{0}";
	if(!label.CompareTo("541")) return "B_{c}^{+}";
	if(!label.CompareTo("5122")) return "#Lambda_{b}^{0}";
	if(!label.CompareTo("5132")) return "#Xi_{b}^{-}";
	if(!label.CompareTo("5142")) return "#Xi_{bc}^{0}";
	if(!label.CompareTo("5232")) return "#Xi_{b}^{0}";
	if(!label.CompareTo("5242")) return "#Xi_{bc}^{+}";
	if(!label.CompareTo("5332")) return "#Omega_{b}^{-}";
	
	/*
	//strong decays:
	else if(!label.CompareTo("413")) return "D*^{+}";
	else if(!label.CompareTo("423")) return "D*^{0}";
	else if(!label.CompareTo("433")) return "D*_{s}^{+}";
	else if(!label.CompareTo("415")) return "D*_{2}^{+}";
	else if(!label.CompareTo("425")) return "D*_{2}^{0}";
	else if(!label.CompareTo("435")) return "D*_{s2}^{+}";
	
	else if(!label.CompareTo("10411")) return "D*_{0}^{+}";
	else if(!label.CompareTo("10413")) return "D_{1}^{+}";
	else if(!label.CompareTo("10421")) return "D*_{0}^{0}";
	else if(!label.CompareTo("10423")) return "D_{1}^{0}";
	else if(!label.CompareTo("10431")) return "D*_{s0}^{+}";
	else if(!label.CompareTo("10433")) return "D_{s1}^{+}";
	
	else if(!label.CompareTo("20413")) return "D_{1}(H)^{+}";
	else if(!label.CompareTo("20423")) return "D_{1}(H)^{0}";
	else if(!label.CompareTo("20433")) return "D_{s1}(H)^{+}";
	
	else if(!label.CompareTo("4112")) return "#Sigma_{c}^{0}";
	else if(!label.CompareTo("4114")) return "#Sigma*_{c}^{0}";
	else if(!label.CompareTo("4212")) return "#Sigma_{c}^{+}";
	else if(!label.CompareTo("4214")) return "#Sigma*_{c}^{+}";
	else if(!label.CompareTo("4222")) return "#Sigma_{c}^{++}";
	else if(!label.CompareTo("4224")) return "#Sigma*_{c}^{++}";
	
	else if(!label.CompareTo("4312")) return "#Xi'_{c}^{0}";
	else if(!label.CompareTo("4322")) return "#Xi'_{c}^{+}";
	else if(!label.CompareTo("4314")) return "#Xi*_{c}^{0}";
	else if(!label.CompareTo("4324")) return "#Xi*_{c}^{+}";
	
	else if(!label.CompareTo("4334")) return "#Omega*_{c}^{0}";
	
	else if(!label.CompareTo("4124")) return "#Lambda*_{c}^{+}";
	*/
    return "No value";
}



void relabel(TH1 * plot) {
	plot->SetXTitle("Hadron type");
	plot->GetXaxis()->SetLabelSize(0.09);	
	for(int i=1; i<plot->GetNbinsX()+1; i++) {
		TString label = plot->GetXaxis()->GetBinLabel(i);
		plot->GetXaxis()->SetBinLabel(i, relabel(label) );
	}
}

TPaveText *HadronLabel(TString name) {
	TString ss="";
	if( name.Contains("_4")) {
		TString s1 ( name( name.First("4"), name.Sizeof() ) );
		ss = s1;
	}
	else if( name.Contains("_5")) {
		TString s1 ( name( name.First("5"), name.Sizeof() ) );
		ss = s1;
	}
	else return 0;
	if( ss.Contains("_")) {
		TString s2 = ( ss( 0, ss.First("_") ) );
		ss = s2;
	}
	TPaveText *pave = new TPaveText(0.73, 0.75, 0.795, 0.93, "BT NDC");
	pave->SetFillColor(0);
	pave->AddText(relabel(ss));
	return pave;
}


//============================================================================
