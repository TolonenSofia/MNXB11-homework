#ifndef _My_Class_H_
#define _My_Class_H_

#include <TObject.h>

class MyClass : public TObject {
public:
    MyClass();
    MyClass(Int_t variable);
    virtual ~MyClass();

private:

    ClassDef(MyClass, 1);
};

#endif // _My_Class_H_
