#include "TGraph.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include <fstream>


void exercicio_2() {

    TGraph *g1 = new TGraph("graphdata.txt", "%lg %lg");

    g1->SetMarkerStyle(21);
    g1->SetMarkerColor(kBlack);
    g1->SetTitle("Exercicio 2 - TGraph");
    g1->GetXaxis()->SetTitle("Eixo X");
    g1->GetYaxis()->SetTitle("Eixo Y");

    TCanvas *c1 = new TCanvas("c1", "TGraph com linha", 800, 600);
    g1->Draw("APL");
    c1->SaveAs("exercicio2_tgraph.png");


    TGraphErrors *g2 = new TGraphErrors("graphdata_error.txt", "%lg %lg %lg %lg");

    g2->SetMarkerStyle(21);
    g2->SetMarkerColor(kBlack);
    g2->SetTitle("Exercicio 2 - TGraphErrors");
    g2->GetXaxis()->SetTitle("Eixo X");
    g2->GetYaxis()->SetTitle("Eixo Y");

    TCanvas *c2 = new TCanvas("c2", "TGraphErrors", 800, 600);
    g2->Draw("APL");
    c2->SaveAs("exercicio2_tgrapherrors.png");

        }
