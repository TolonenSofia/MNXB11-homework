#include "Magnitude.h"
#include <TFile.h>
#include <TTree.h>
#include <TH2F.h>
#include <TCanvas.h>

void read() {
    TFile *file = TFile::Open("tree_file.root");
    TTree *tree = (TTree*)file->Get("tree");

    Magnitude *magnitude = nullptr;
    tree->SetBranchAddress("magnitude", &magnitude);
    Int_t N = tree->GetEntries();

    /////Plot of px vs py
    TH2F *hist = new TH2F("hist", "px vs py", 100, -0.07, 0.07, 100, -0.07, 0.07);
    for (Int_t i = 0; i < N; i++) {
        tree->GetEntry(i);
        Double_t pxValue = magnitude->GetPx();
        Double_t pyValue = magnitude->GetPy();
        hist->Fill(pxValue, pyValue);
    }
    TCanvas *c1 = new TCanvas("c1", "Canvas", 800, 600);
    hist->Draw("COL");
    c1->Draw();    

    /////Plot of px*py vs pz

    TH2F *hist2 = new TH2F("hist2", "px*py vs pz", 100, -0.003, 0.003, 100, -0.08, 0.08);
    for (Int_t i = 0; i < N; i++) {
        tree->GetEntry(i);
        Double_t pxValue = magnitude->GetPx();
        Double_t pyValue = magnitude->GetPy();
        Double_t pzValue = magnitude->GetPz();
        hist2->Fill(pxValue*pyValue, pzValue);
    }
    TCanvas *c2 = new TCanvas("c2", "Canvas", 800, 600);
    hist2->Draw("COL");
    c2->Draw();    

    /////Plot px*py vs pz with condition on Magnitude of momentum

    TH2F *hist3 = new TH2F("hist3", "px*py vs pz with con", 100, -0.003, 0.003, 100, -0.08, 0.08);
    for (Int_t i = 0; i < N; i++) {
        tree->GetEntry(i);
        Double_t pxValue = magnitude->GetPx();
        Double_t pyValue = magnitude->GetPy();
        Double_t pzValue = magnitude->GetPz();
        Double_t Magnitude = magnitude->CalculateMagnitude();
        if (Magnitude > 0.03 && Magnitude< 0.07){
            hist3->Fill(pxValue*pyValue, pzValue);
        }
    }
    TCanvas *c3 = new TCanvas("c3", "Canvas", 800, 600);
    hist3->Draw("COL");
    c3->Draw();    
}
