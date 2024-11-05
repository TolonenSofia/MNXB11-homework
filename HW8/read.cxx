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

/////second plot

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

}
