#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <TCanvas.h>
#include <TH2F.h>
#include <TH1F.h>
#include <TTree.h>
#include <TFile.h>
#include <TStyle.h>
#include "TROOT.h"
#include <time.h>
#include <math.h>

#define Pi 3.1415 // so pi

using namespace std;

double radiantodeg(double t){
  double r;
  r = t*180/Pi;
  return(r);
}
double degtoradian(double t){
  double r;
  r = t*Pi/180;
return(r);
}


int main(int argc, char **argv){
// read file output
  char rootFileDir[1000]="";
  std::strcpy(rootFileDir,argv[1]);
  cout<<rootFileDir<<endl;
  char rootFileName[1000]="";
  std::strcpy(rootFileName,rootFileDir);

TFile *my= new TFile("d6-r4-a3-b9-20s-4.root");
// read trre of file output
TTree *Coincidences = (TTree*)gDirectory->Get("Coincidences");

    Float_t s;
    Float_t phi;


    Coincidences->SetBranchAddress("sinogramS",&s);
    Coincidences->SetBranchAddress("sinogramTheta",&phi);
    Int_t nentriesCoincidences = Coincidences->GetEntries();

TH2F *h2=new TH2F("h2","sinogram",80,-2,2,20,0,180);
h2->SetStats(0);

for(int i=0; i<nentriesCoincidences; i++){
     Coincidences->GetEntry(i);
     Float_t Phi, S;
     Phi = radiantodeg(phi);
     S = s/10;
    h2->Fill(S,Phi);
}
TH2F *h22=new TH2F("h22","position sources",100,-2,2,100,-2,2);
ofstream ProjectionsFile;
ProjectionsFile.open("Projections.sinogram");
//cout<<"Number of Bins = "<<h2->GetNbinsY()<<endl;

for(Int_t j = 1; j <= h2->GetNbinsX(); j++) {
  for(Int_t i = 1; i <= h2->GetNbinsY(); i++) {
    Int_t bin = h2->GetBin(j,i);
    Float_t value = h2->GetBinContent(bin);
    ProjectionsFile<<value<< " ";
    }
      ProjectionsFile<<endl;
}
ProjectionsFile.close();

for(Int_t j = 1; j <= h2->GetNbinsY(); j++) {
  for(Int_t i = 1; i <= h2->GetNbinsX(); i++) {
    Int_t bin = h2->GetBin(i,j);
    Float_t value = h2->GetBinContent(bin);
    int binphi = 9;
    float bins = 0.05;
    float a = sin(degtoradian(j*binphi))/cos(degtoradian(j*binphi));
    float b = (bins*i-2)/cos(degtoradian(j*binphi));
    for (Int_t t =1;  t <=h22->GetNbinsX(); t++){
    Double_t x = h22->GetXaxis()->GetBinCenter(t);
    Double_t y =(a*x+b);
    h22->Fill(x,y,value);
  }
  }
}

TH2D *h23=new TH2D("h23","position sources",100,-2,2,100,-2,2);
Float_t max = h22->GetMaximum();
cout<<max;

for(Int_t j = 1; j <= h22->GetNbinsY(); j++) {
  for(Int_t i = 1; i <= h22->GetNbinsX(); i++) {
    Int_t bin = h22->GetBin(i,j);
    Float_t value = h22->GetBinContent(bin);

    if (value < 500){ value =0;}
    //else {value = value}

    h23->SetBinContent(bin,value);
  }
  }

TCanvas *c1=new TCanvas("c1","image",100,10,400,400);
h23->Draw("CONT4Z");
c1->Print("image+"<<rootFileName<<".png");

TCanvas *c2=new TCanvas("c2","sinogram",500,10,400,400);
h2->Draw("CONT4Z");
c2->Print("sinogram"<<rootFileName<<".png");
*/
return 0;
}
