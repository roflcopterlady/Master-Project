//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Aug 30 10:52:14 2016 by ROOT version 5.34/17
// from TTree user/user
// found on file: user.hesketh.PowhegPy8.AOD_output.root.93241882/user.hesketh.9246864._000059.output.root
//////////////////////////////////////////////////////////

#ifndef user_h
#define user_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class user {
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

   user(TTree *tree=0);
   virtual ~user();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef user_cxx
user::user(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("user.hesketh.PowhegPy8.AOD_output.root.93241882/user.hesketh.9246864._000059.output.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("user.hesketh.PowhegPy8.AOD_output.root.93241882/user.hesketh.9246864._000059.output.root");
      }
      f->GetObject("user",tree);

   }
   Init(tree);
}

user::~user()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t user::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t user::LoadTree(Long64_t entry)
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

void user::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
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
   fChain->SetBranchAddress("mc_pt", &mc_pt, &b_mc_pt);
   fChain->SetBranchAddress("mc_eta", &mc_eta, &b_mc_eta);
   fChain->SetBranchAddress("mc_phi", &mc_phi, &b_mc_phi);
   fChain->SetBranchAddress("mc_m", &mc_m, &b_mc_m);
   fChain->SetBranchAddress("mc_pdgid", &mc_pdgid, &b_mc_pdgid);
   fChain->SetBranchAddress("mc_hfd", &mc_hfd, &b_mc_hfd);
   Notify();
}

Bool_t user::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void user::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t user::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef user_cxx
