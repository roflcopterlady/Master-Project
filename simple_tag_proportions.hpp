
//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Oct 24 12:02:15 2014 by ROOT version 5.34/17
// from TTree plot/plot
// found on file: output.root
//////////////////////////////////////////////////////////

#ifndef simple_tag_proportions_h
#define simple_tag_proportions_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TVector2.h>
#include <string>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>    // std::sort
#include <math.h>

#include "utils.hpp"

using std::vector;
using std::pair;
using std::cout;
using std::endl;
using std::setw;


// Fixed size dimensions of array or collections stored in the TTree if any.

bool pairsortfirst (pair<int, int> i, pair<int, int> j) { return (i.first > j.first); }
bool pairsortsecond (pair<int, int> i, pair<int, int> j) { return (i.second > j.second); }


float DeltaR(float eta1, float phi1, float eta2, float phi2) {
    return hypot(TVector2::Phi_mpi_pi(phi2 - phi1), fabs(eta2 - eta1));
}

class simple_tag_proportions {
    
    //Can be used anytime we need to differentiate between the two hadron types.
    enum hadronTypes {bHadrons=0, cHadrons=1};
    
    public :
    TTree          *fChain;   //!pointer to the analyzed TTree or TChain
    Int_t           fCurrent; //!current Tree number in a TChain
    
    // Declaration of leaf types
    vector<float>   *jet_pT;
    vector<float>   *jet_eta;
    vector<float>   *jet_phi;
    vector<float>   *jet_m;
    vector<float>   *jet_MV2c20;
    vector<float>   *mchfpart_pt;
    vector<float>   *mchfpart_eta;
    vector<float>   *mchfpart_phi;
    vector<float>   *mchfpart_m;
    vector<int>     *mchfpart_pdgid;
    vector<int>     *mchfpart_status;
    vector<vector<int> > *mchfpart_decay_chain;
    vector<float>   *mc_pt;
    vector<float>   *mc_eta;
    vector<float>   *mc_phi;
    vector<float>   *mc_m;
    vector<int>     *mc_pdgid;
    vector<int>     *mc_hfd;
    
    
    // List of branches
    TBranch        *b_jet_pT;   //!
    TBranch        *b_jet_eta;   //!
    TBranch        *b_jet_phi;   //!
    TBranch        *b_jet_m;   //!
    TBranch        *b_jet_MV2c20;   //!
    TBranch        *b_mchfpart_pt;   //!
    TBranch        *b_mchfpart_eta;   //!
    TBranch        *b_mchfpart_phi;   //!
    TBranch        *b_mchfpart_m;   //!
    TBranch        *b_mchfpart_pdgid;   //!
    TBranch        *b_mchfpart_status;   //!
    TBranch        *b_mchfpart_decay_chain;   //!
    TBranch        *b_mc_pt;   //!
    TBranch        *b_mc_eta;   //!
    TBranch        *b_mc_phi;   //!
    TBranch        *b_mc_m;   //!
    TBranch        *b_mc_pdgid;   //!
    TBranch        *b_mc_hfd;   //!
    
    
    simple_tag_proportions(TString sample, TTree *tree=0);
    
    virtual ~simple_tag_proportions();
    virtual Int_t    Cut(Long64_t entry);
    virtual Int_t    GetEntry(Long64_t entry);
    virtual Long64_t LoadTree(Long64_t entry);
    virtual void     Init(TTree *tree);
    
    virtual void Loop(bool write);
    
    //virtual void overlayPlots(TH1* plot1, TH1* plot2, TString parameter);
   // void overlayNPlots(std::vector<TH1*> plotArray, TString plotName);
    //virtual void ratioPlots(TH1* plo1, TH1* plot2, TString parameter);
    void hadronCountPlot(std::string type);
    void test (hadronTypes type);
    void plot_all_properties();
    void hadron_count_plot();
    
    
    virtual Bool_t   Notify();
    virtual void     Show(Long64_t entry = -1);
    TH1 * MakePlot(TString name, int nbins, float xlow, float xhigh);
    TH1 * MakePlot(TString name, int nbins, double *xbins);
    TH2 * MakePlot(TString name, int nbinsx, double *xbins, int nbinsy, float ylow, float yhigh);
    TH2 * MakePlot(TString name, int nbinsx, float xlow, float xhigh, int nbinsy, float ylow, float yhigh);
    std::pair<int,int> Label(float eta, float phi, float mv1=0);
    void Relabel(TH1 *&plot, bool isb=false);
    
    TString m_sample;
    std::vector<int> abh, ach, bh, ch;
    bool IsB(int apdg);
    bool IsWeakB(int apdg);
    bool IsC(int apdg);
    bool IsWeakC(int apdg);
    float hadron_weight(int hlabel);
    double b_pT_reweight(Double_t pT);
    double c_pT_reweight(Double_t pT);
    double weight(TH1 * plot, double val);
    double weight(TH2 * plot, double valx, double valy);
    TH1 * Ratio(TH1 *plot1, TH1 * plot2);
    
    TH1 * h_hadron_pT_reweight[2];
    TH1 * h_pT_frac_reweight[2];
    TH2 * h_pT_frac_pT_reweight[2];
    TH2 * h_pT_frac_dR_reweight[2];
    TH2 * h_ntrk_pT_reweight[2];
    TH1 * h_dR_reweight[2];
    TH1 * h_eta_reweight[2];
    TH1 * h_pT_reweight[2];
    TH1 * h_ntrk_reweight[2];
    TH1 * h_trk_pT_reweight[2];
    
    TH1 * h_bhadron;
    TH1 * h_mv2c20;
    
    TH1 * h_jet_eta;
    
    //TH1 * h_jet_pT[2];
    //TH1 * h_pT_frac[2];
    
};

#endif

#ifdef simple_tag_proportions_cxx
simple_tag_proportions::simple_tag_proportions(TString sample, TTree *tree) : fChain(0)
{
    // if parameter tree is not specified (or zero), connect the file
    // used to generate this class and read the Tree.
    m_sample = sample;
    
    if (tree == 0) {
        TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("output.root");
        if (!f || !f->IsOpen()) {
            f = new TFile(m_sample);//"../files/merge_"+m_sample+".root");
        }
        f->GetObject("user",tree);
        
    }
    Init(tree);
    
    /*
     TFile * reweight_plots = new TFile("plots_for_reweighting.root", "READ");
     for(int i=0; i<2; i++) {
     h_hadron_pT_reweight[i] = (TH1*)gDirectory->Get("h_hadron_pT_"+hname[i]);
     h_pT_frac_reweight[i] = (TH1*)gDirectory->Get("h_pT_frac_"+hname[i]);
     h_pT_frac_pT_reweight[i] = (TH2*)gDirectory->Get("h_pT_frac_pT_"+hname[i]);
     h_pT_frac_dR_reweight[i] = (TH2*)gDirectory->Get("h_pT_frac_dR_"+hname[i]);
     h_dR_reweight[i] = (TH1*)gDirectory->Get("h_dR_"+hname[i]);
     h_eta_reweight[i] = (TH1*)gDirectory->Get("h_jet_eta_"+hname[i]);
     h_pT_reweight[i] = (TH1*)gDirectory->Get("h_jet_pT_"+hname[i]);
     h_ntrk_reweight[i] = (TH1*)gDirectory->Get("h_jet_ntrks_"+hname[i]+"_pT_frac_dR_rw");
     h_trk_pT_reweight[i] = (TH1*)gDirectory->Get("h_jet_trk_pT_"+hname[i]+"_pT_frac_dR_rw");
     h_ntrk_pT_reweight[i] = (TH2*)gDirectory->Get("h_jet_ntrks_pT_"+hname[i]);
     
     h_hadron_pT_reweight[i]->SetDirectory(0);
     h_pT_frac_reweight[i]->SetDirectory(0);
     h_pT_frac_pT_reweight[i]->SetDirectory(0);
     h_dR_reweight[i]->SetDirectory(0);
     h_pT_frac_dR_reweight[i]->SetDirectory(0);
     h_eta_reweight[i]->SetDirectory(0);
     h_pT_reweight[i]->SetDirectory(0);
     h_ntrk_reweight[i]->SetDirectory(0);
     h_trk_pT_reweight[i]->SetDirectory(0);
     h_ntrk_pT_reweight[i]->SetDirectory(0);
     }
     reweight_plots->Close();
     */
}

simple_tag_proportions::~simple_tag_proportions()
{
    if (!fChain) return;
    delete fChain->GetCurrentFile();
}

Int_t simple_tag_proportions::GetEntry(Long64_t entry)
{
    // Read contents of entry.
    if (!fChain) return 0;
    return fChain->GetEntry(entry);
}
Long64_t simple_tag_proportions::LoadTree(Long64_t entry)
{
    // Set the environment to read one entry
    if (!fChain) return -5;
    Long64_t centry = fChain->LoadTree(entry);
    if (centry < 0) return centry;
    if (fChain->GetTreeNumber() != fCurrent) {
        fCurrent = fChain->GetTreeNumber();
        Notify();
    }
    return centry;
}

void simple_tag_proportions::Init(TTree *tree)
{
    // The Init() function is called when the selector needs to initialize
    // a new tree or chain. Typically here the branch addresses and branch
    // pointers of the tree will be set.
    // It is normally not necessary to make changes to the generated
    // code, but the routine can be extended by the plot if needed.
    // Init() will be called many times when running on PROOF
    // (once per file to be processed).
    
    // Set object pointer
    jet_pT = 0;
    jet_eta = 0;
    jet_phi = 0;
    jet_m = 0;
    jet_MV2c20 = 0;
    mchfpart_pt = 0;
    mchfpart_eta = 0;
    mchfpart_phi = 0;
    mchfpart_m = 0;
    mchfpart_pdgid = 0;
    mchfpart_status = 0;
    mchfpart_decay_chain = 0;
    mc_pt = 0;
    mc_eta = 0;
    mc_phi = 0;
    mc_m = 0;
    mc_pdgid = 0;
    mc_hfd = 0;
    // Set branch addresses and branch pointers
    if (!tree) return;
    fChain = tree;
    fCurrent = -1;
    fChain->SetMakeClass(1);
    /*
     fChain->SetBranchStatus("mc_pt", 0);
     fChain->SetBranchStatus("mc_eta", 0);
     fChain->SetBranchStatus("mc_phi", 0);
     fChain->SetBranchStatus("mc_m", 0);
     fChain->SetBranchStatus("mc_pdgid", 0);
     fChain->SetBranchStatus("mc_hfd", 0);
     */
    fChain->SetBranchAddress("jet_pT", &jet_pT, &b_jet_pT);
    fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
    fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
    fChain->SetBranchAddress("jet_m", &jet_m, &b_jet_m);
    fChain->SetBranchAddress("jet_MV2c20", &jet_MV2c20, &b_jet_MV2c20);
    fChain->SetBranchAddress("mchfpart_pt", &mchfpart_pt, &b_mchfpart_pt);
    fChain->SetBranchAddress("mchfpart_eta", &mchfpart_eta, &b_mchfpart_eta);
    fChain->SetBranchAddress("mchfpart_phi", &mchfpart_phi, &b_mchfpart_phi);
    fChain->SetBranchAddress("mchfpart_m", &mchfpart_m, &b_mchfpart_m);
    fChain->SetBranchAddress("mchfpart_pdgid", &mchfpart_pdgid, &b_mchfpart_pdgid);
    fChain->SetBranchAddress("mchfpart_status", &mchfpart_status, &b_mchfpart_status);
    fChain->SetBranchAddress("mchfpart_decay_chain", &mchfpart_decay_chain, &b_mchfpart_decay_chain);
    
    /*
     fChain->SetBranchAddress("mc_pt", &mc_pt, &b_mc_pt);
     fChain->SetBranchAddress("mc_eta", &mc_eta, &b_mc_eta);
     fChain->SetBranchAddress("mc_phi", &mc_phi, &b_mc_phi);
     fChain->SetBranchAddress("mc_m", &mc_m, &b_mc_m);
     fChain->SetBranchAddress("mc_pdgid", &mc_pdgid, &b_mc_pdgid);
     fChain->SetBranchAddress("mc_hfd", &mc_hfd, &b_mc_hfd);
     */
    Notify();
}

Bool_t simple_tag_proportions::Notify()
{
    // The Notify() function is called when a new file is opened. This
    // can be either for a new TTree in a TChain or when when a new TTree
    // is started when using PROOF. It is normally not necessary to make changes
    // to the generated code, but the routine can be extended by the
    // plot if needed. The return value is currently not used.
    
    return kTRUE;
}

void simple_tag_proportions::Show(Long64_t entry)
{
    // Print contents of entry.
    // If entry is not specified, print current entry
    if (!fChain) return;
    fChain->Show(entry);
}
Int_t simple_tag_proportions::Cut(Long64_t entry)
{
    // This function may be called from Loop.
    // returns  1 if entry is accepted.
    // returns -1 otherwise.
    return 1;
}


TH1 * simple_tag_proportions::MakePlot(TString name, int nbins, float xlow, float xhigh) {
    TH1 *tmp = new TH1F(name, name, nbins, xlow, xhigh);
    tmp->Sumw2();
    return tmp;
}
TH1 * simple_tag_proportions::MakePlot(TString name, int nbins, double *xbins) {
    TH1 *tmp = new TH1F(name, name, nbins, xbins);
    tmp->Sumw2();
    return tmp;
}


TH2 * simple_tag_proportions::MakePlot(TString name, int nbinsx, float xlow, float xhigh, int nbinsy, float ylow, float yhigh) {
    TH2 *tmp = new TH2F(name, name, nbinsx, xlow, xhigh, nbinsy, ylow, yhigh);
    tmp->Sumw2();
    return tmp;
}
TH2 * simple_tag_proportions::MakePlot(TString name, int nbinsx, double *xbins, int nbinsy, float ylow, float yhigh) {
    TH2 *tmp = new TH2F(name, name, nbinsx, xbins, nbinsy, ylow, yhigh);
    tmp->Sumw2();
    return tmp;
}


//=================================================================================
//=================================================================================
//=================================================================================


bool simple_tag_proportions::IsB(int apdg) {
    
    apdg = abs(apdg);
    
    if(apdg>=500 && apdg <=599) return true;
    if(apdg>=10500 && apdg <=10599) return true;
    if(apdg>=20500 && apdg <=20599) return true;
    if(apdg>=5000 && apdg <=5999) return true;
    return false;
}

bool simple_tag_proportions::IsC(int apdg) {
    //don't count onia:
    
    apdg = abs(apdg);
    
    if(apdg ==443) return false;
    if(apdg ==441) return false;
    if(apdg ==445) return false;
    if(apdg == 10441) return false;
    if(apdg == 10443) return false;
    if(apdg == 20443) return false;
    
    if(apdg>=400 && apdg <=499) return true;
    if(apdg>=10400 && apdg <=10499) return true;
    if(apdg>=20400 && apdg <=20499) return true;
    if(apdg>=4000 && apdg <=4999) return true;
    return false;
}

bool simple_tag_proportions::IsWeakB(int apdg) {
    apdg=abs(apdg);
    if(apdg==511) return true;
    if(apdg==521) return true;
    if(apdg==531) return true;
    if(apdg==541) return true;
    
    if(apdg==5122) return true;
    if(apdg==5132) return true;
    //	if(apdg==5142) return true;
    if(apdg==5232) return true;
    //	if(apdg==5242) return true;
    if(apdg==5332) return true;
    return false;
}

bool simple_tag_proportions::IsWeakC(int apdg) {
    apdg=abs(apdg);
    
    if(apdg==411) return true;
    if(apdg==421) return true;
    if(apdg==431) return true;
    
    if(apdg==4122) return true;
    if(apdg==4132) return true;
    if(apdg==4232) return true;
    if(apdg==4332) return true;
    
    return false;
}


//=========================================================================================
//=========================================================================================
//=========================================================================================
//=========================================================================================

std::pair<int, int> simple_tag_proportions::Label(float eta, float phi, float mv1) {
    
    ach.clear();
    abh.clear();
    ch.clear();
    bh.clear();
    vector<float> bjet_dR, cjet_dR;
    bjet_dR.clear();
    cjet_dR.clear();
    float dRminb = 9999, dRminbc = 9999, dRminc=9999;
    for(int i=0; i<(*mchfpart_eta).size(); i++) {
        
        if( (*mchfpart_pt)[i] < 5) continue;
        if( (m_sample == "187003" || m_sample == "187007") && (*mchfpart_status)[i]==11) continue;
        
        float dR = DeltaR(eta, phi, (*mchfpart_eta)[i], (*mchfpart_phi)[i] );
        int apdg = abs((*mchfpart_pdgid)[i]);
        
        if( IsB(apdg) ) {
            if( IsWeakB(apdg) ) {
                //want to remove oscillations. Look for the opposite sign pdg id, and the same dR in another B hadron
                bool osc = false;
                for(int ibh=0; ibh<bjet_dR.size(); ibh++) {
                    if( fabs(dR - bjet_dR[ibh]) < 0.01 && (*mchfpart_pdgid)[i] == (int)(-1 * (*mchfpart_pdgid)[abh[ibh]]) ) osc = true;
                }
                if(osc) continue;
                if(dR<0.4) bh.push_back(i);
                else if(dR<dRminb) dRminb = dR;
                abh.push_back(i);
                bjet_dR.push_back(dR);
                if(dR<dRminbc) dRminbc = dR;
            }
        }
        
        if( IsC(apdg) ) {
            if( IsWeakC(apdg) ) {
                bool osc = false;
                for(int ich=0; ich<cjet_dR.size(); ich++) {
                    if( fabs(dR - cjet_dR[ich]) < 0.01 && (*mchfpart_pdgid)[i] == (int)(-1 * (*mchfpart_pdgid)[ach[ich]]) ) osc = true;
                }
                if(osc) continue;
                
                ach.push_back(i);
                cjet_dR.push_back(dR);
                if(dR<0.4) ch.push_back(i);
                else if(dR<dRminc) dRminc = dR;
                
            }
        }
        
    }//loop over hf hadrons
    
}



void simple_tag_proportions::Relabel(TH1 *&plot, bool isb) {
    
    for(int i=0; i<plot->GetNbinsX(); i++) {
        TString label = ""; label += map(i, isb);
        plot->GetXaxis()->SetBinLabel(i+1, label);
    }
    return;
}



//=================================================================================


float simple_tag_proportions::hadron_weight(int hlabel) {
    
    /*
     //evtgen samples:
     B^{0} 1.06674
     B^{+} 1.06363
     B_{s}^{0} 0.863318
     B_{c}^{+} 2.5479
     #Lambda_{b}^{0} 0.501637
     #Xi_{b}^{-} 1.49425
     #Xi_{b}^{0} 1.46053
     #Omega_{b}^{-} 0.636518
     
     D^{+} 1.08235
     D^{0} 1.02059
     D_{s}^{+} 0.969364
     #Lambda_{c}^{+} 0.540774
     #Xi_{c}^{0} 2.6074
     #Xi_{c}^{+} 2.64446
     #Omega_{c}^{0} 0.803643
     
     after jet pT reweighting:
     B^{0} 1.06831
     B^{+} 1.06306
     B_{s}^{0} 0.861173
     B_{c}^{+} 2.55416
     #Lambda_{b}^{0} 0.501101
     #Xi_{b}^{-} 1.4869
     #Xi_{b}^{0} 1.45339
     #Omega_{b}^{-} 0.630608
     
     D^{+} 1.08361
     D^{0} 1.02007
     D_{s}^{+} 0.969264
     #Lambda_{c}^{+} 0.540815
     #Xi_{c}^{0} 2.6118
     #Xi_{c}^{+} 2.63429
     #Omega_{c}^{0} 0.809736
     
     ///single hadron jets:
     B^{0} 1.06374
     B^{+} 1.05992
     B_{s}^{0} 0.859121
     B_{c}^{+} 3.0663
     #Lambda_{b}^{0} 0.498319
     #Xi_{b}^{-} 1.48806
     #Xi_{b}^{0} 1.44788
     #Omega_{b}^{-} 0.63735
     Info in <TCanvas::Print>: eps file figures/c_weak_hadrons.eps has been created
     
     Reweighting values:
     D^{+} 1.08122
     D^{0} 1.02146
     D_{s}^{+} 0.958363
     #Lambda_{c}^{+} 0.544555
     #Xi_{c}^{0} 2.90348
     #Xi_{c}^{+} 2.80593
     #Omega_{c}^{0} 1.06084
     Info in <TCanvas::Print>: eps file figures/b_weak_hadrons_rw.eps has been created
     
     Reweighting values:
     B^{0} 1.06554
     B^{+} 1.05926
     B_{s}^{0} 0.856262
     B_{c}^{+} 3.09244
     #Lambda_{b}^{0} 0.497709
     #Xi_{b}^{-} 1.48058
     #Xi_{b}^{0} 1.44034
     #Omega_{b}^{-} 0.629918
     Info in <TCanvas::Print>: eps file figures/c_weak_hadrons_rw.eps has been created
     
     Reweighting values:
     D^{+} 1.08243
     D^{0} 1.02089
     D_{s}^{+} 0.958314
     #Lambda_{c}^{+} 0.54481
     #Xi_{c}^{0} 2.91959
     #Xi_{c}^{+} 2.80152
     #Omega_{c}^{0} 1.07473
     
     
     
     */
    if(hlabel == 411) return  1.08235;
    if(hlabel == 421) return  1.02059;
    if(hlabel == 431) return  0.969364;
    if(hlabel == 4122) return 0.540774;
    if(hlabel == 4132) return 2.6074;
    if(hlabel == 4232) return 2.64446;
    if(hlabel == 4332) return 0.803643;
    
    if(hlabel == 511) return  1.06674;
    if(hlabel == 521) return  1.02059;
    if(hlabel == 531) return  0.863318;
    if(hlabel == 541) return  2.5479;
    if(hlabel == 5122) return 0.501637;
    if(hlabel == 5132) return 1.49425;
    if(hlabel == 5232) return 1.46053;
    if(hlabel == 5332) return 0.636518;
    
    return 1.0;
}




double simple_tag_proportions::b_pT_reweight(Double_t pT) {
    double par[3];
    par[0] = 0.874857;
    par[1] = 0.00374837;
    par[2] = -6.54698e-06;
    double xval = pT>200 ? 200 : pT;
    return par[0] +  par[1]*xval +  par[2]*xval*xval;
}

double simple_tag_proportions::c_pT_reweight(Double_t pT) {
    double par[3];
    par[0] = 1.05691;
    par[1] = 0.000752842;
    par[2] = 2.46003e-06;
    return par[0] +  par[1]*pT +  par[2]*pT*pT;
}


double simple_tag_proportions::weight(TH1 * plot, double val) {
    if(m_sample != "187007") return 1.0;	
    int bin = plot->FindBin(val);
    double weight = plot->GetBinContent(bin);
    return weight == 0 ? 0 : 1.0/weight;
}

double simple_tag_proportions::weight(TH2 * plot, double valx, double valy) {
    if(m_sample != "187007") return 1.0;	
    int bin = plot->FindBin(valx, valy);
    double weight = plot->GetBinContent(bin);
    //	cout<<valx<<" "<<valy<<" "<<bin<<" "<<weight<<endl;
    return weight == 0 ? 0 : 1.0/weight;
}

TH1* simple_tag_proportions::Ratio(TH1 * plot1, TH1*plot2) {
    
    TH1 * tmp = (TH1F*)plot1->Clone( (TString)(plot1->GetName())+"_eff");
    tmp->SetTitle( (TString)(plot1->GetName())+"_eff");
    tmp->Divide(plot1, plot2, 1, 1, "B");
    return tmp;
}

#endif // #ifdef simple_tag_proportions_cxx
