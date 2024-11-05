#include "Magnitude.h"
#include <cmath> 

ClassImp(Magnitude)

Magnitude::Magnitude() : px(0), py(0), pz(0) {}

Magnitude::Magnitude(Double_t px, Double_t py, Double_t pz) : px(px), py(py), pz(pz) {}

Magnitude::~Magnitude() {}

Double_t Magnitude::CalculateMagnitude() const {
    return sqrt(px * px + py * py + pz * pz);
}

ClassImp(Magnitude);
