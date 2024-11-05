#ifndef _Magnitude_H_
#define _Magnitude_H_

#include <TObject.h>

class Magnitude : public TObject {
public:
    Magnitude();
    
    Magnitude(Double_t px, Double_t py, Double_t pz);
    
    virtual ~Magnitude();

    Double_t CalculateMagnitude() const;

    Double_t GetPx() const { return px; }
    Double_t GetPy() const { return py; }
    Double_t GetPz() const { return pz; }

private:
    Double_t px;
    Double_t py;
    Double_t pz; 

    ClassDef(Magnitude, 1);
};

#endif // __Magnitude_H_
