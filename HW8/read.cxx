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
        if (magnitude) {
            Double_t pxValue = magnitude->GetPx();
            Double_t pyValue = magnitude->GetPy();
            hist->Fill(pxValue, pyValue);
        }
    }

    TCanvas *c1 = new TCanvas("c1", "Canvas", 800, 600);
    hist->Draw("COL");
    c1->Draw();    
}
