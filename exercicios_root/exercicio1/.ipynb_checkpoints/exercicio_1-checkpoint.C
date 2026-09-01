#include "TF1.h"
#include "TCanvas.h"
#include <iostream>


void exercicio_1() {



TF1 *f = new TF1( "f1", "[0]*sin([1]*x)/x", -10, 10);
f-> SetParameters(1,2);
f-> SetLineColor(kBlue);
f->Draw();

TCanvas *c1 = new TCanvas("c1", "Funcao com parametros diferentes", 800, 600);

TF1 *f1 = new TF1("f1", "[0]*sin([1]*x)/x", -10, 10);
f1->SetParameters(1, 2);
f1->SetLineColor(kBlue);
f1->Draw();

TF1 *f2 = new TF1("f2", "[0]*sin([1]*x)/x", -10, 10);
f2->SetParameters(2, 1);
f2->SetLineColor(kRed);
f2->Draw("same");

TF1 *f3 = new TF1("f3", "[0]*sin([1]*x)/x", -10, 10);
f3->SetParameters(0.5, 3);
f3->SetLineColor(kGreen+2);
f3->Draw("same");

c1->SaveAs("funcao_parametros.png");

f1->SetParameters(1, 2);
double valor = f1->Eval(1);
double derivada = f1->Derivative(1);
double integral = f1->Integral(0,3);

cout << "Valor em x=1: " << valor << endl;
cout << "Derivada em x=1: " << derivada << endl;
cout << "Integral de 0 a 3: " << integral << endl;




















}