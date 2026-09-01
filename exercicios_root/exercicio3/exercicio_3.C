#include "TH1F.h"
#include "TRandom.h"   
#include "TCanvas.h"
#include "TStyle.h"   


void exercicio_3() {

    TRandom *rand = new TRandom();
    TH1F *h = new TH1F("h", "Exercicio 3 - Gaussiana", 50, 0, 10);

    for (int i = 0; i < 10000; i++) {
        double valor = rand->Gaus(5,2);
        h->Fill(valor);

    }

    gStyle->SetOptStat("nemruoks");

    TCanvas *c1 = new TCanvas("c1", "Histograma Gaussiano", 800, 600);
    h->Draw();
    c1->SaveAs("exercicio3_gaussiana.png");

















}