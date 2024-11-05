#include "Magnitude.h"
#include <TFile.h>
#include <TTree.h>
#include <TRandom.h>
#include <iostream> 

void write() {
    Magnitude *magnitude{nullptr};
    Double_t px, py, pz;

    TFile *file = TFile::Open("tree_file.root", "RECREATE");
    TTree *tree = new TTree("tree", "magnitude_tree");
    tree->Branch("magnitude", &magnitude);

    Int_t nEvents = 10000; 

    for (Int_t i = 0; i < nEvents; i++) {
        px = gRandom->Gaus(0, 0.02);
        py = gRandom->Gaus(0, 0.02);
        pz = gRandom->Gaus(0, 0.02);

        magnitude = new Magnitude(px, py, pz);

        tree->Fill();
        delete magnitude;
    }
    
    tree->Write();
    file->Close();
}
