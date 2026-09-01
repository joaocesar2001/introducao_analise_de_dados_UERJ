#define minhaAnalise_cxx
#include "minhaAnalise.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void minhaAnalise::Loop()
{
//   In a ROOT session, you can do:
//      root> .L minhaAnalise.C
//      root> minhaAnalise t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

    //criando histograma antes do loop
    TH1F *h_pt = new TH1F("h_pt", "pT dos muons", 100, 0, 100); 
    TH1F *h_eta = new TH1F("h_eta", "eta dos muons", 100, -3, 3); 
    TH1F *h_phi = new TH1F("h_phi", "phi dos muons", 100, -3.2, 3.2); 

    
   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

       for (int i = 0; i < nMuon; i++) {
           h_pt->Fill(Muon_pt[i]);
           h_eta->Fill(Muon_eta[i]);
           h_phi->Fill(Muon_phi[i]);
       }
       
   }


    TCanvas *c1 = new TCanvas("c1", "pT dos muons", 800, 600);
    h_pt->Draw();
    c1->SaveAs("pT_muons.png");

    TCanvas *c2 = new TCanvas("c2", "eta dos muons", 800, 600);
    h_eta->Draw();
    c2->SaveAs("eta_muons.png");

    TCanvas *c3 = new TCanvas("c3", "phi dos muons", 800, 600);
    h_phi->Draw();
    c3->SaveAs("phi_muons.png");
}
