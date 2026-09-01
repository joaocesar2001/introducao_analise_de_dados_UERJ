#include "TFile.h"
#include "TTree.h"
#include "TCut.h"
#include "TH1F.h"
#include "TCanvas.h"


void exercicio_4() {

    TFile *f = TFile::Open("tree.root");
    TTree *tree = (TTree*)f->Get("tree1");

    TCut corte("abs(ebeam - 150) > 0.2"); // valor 150 obtido analisando a média através do histograma direto do terminal

    TH1F *h_ptot1 = new TH1F("h_ptot1", "Momento Total (fora da media)", 100, 0, 200);
    tree->Draw("sqrt(px*px +py*py + pz*pz) >> h_ptot", corte);

    TCanvas *c1 = new TCanvas("c1", "Momento Total", 800, 600);
    h_ptot->Draw();
    c1->SaveAs("exercicio4_momento_total.png");

}
    