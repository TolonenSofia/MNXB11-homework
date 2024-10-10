#include <iostream>
#include <string>
int main(int nrOfArgs, char *args[]) {
  bool has3Args = (nrOfArgs == 3);
  if  (has3Args) { //if true it continues, if false code stoppes
    std::string codeName{args[0]};  //codeName = var2
    char firstCharSecArg{*(args[1])}; // firstCharSecArg = var3
    std::size_t lenOfCodeName{codeName.size()}; //lenOfCodeName=var4
    int valueOfThirdArg{std::atoi(args[2])}; //valueOfThirdArg = var5
    int sumCharsSecArg{0}; // var6 
    int index{0}; //var7
    std::string secArg{args[1]}; //secArg=var8
    
    while (true) {
      sumCharsSecArg += secArg[index++];
      if (index >= static_cast<int>(secArg.size())) {
        break;
      }
    }
    if ((sumCharsSecArg ^ firstCharSecArg * 3) << (lenOfCodeName & 0x1f) == valueOfThirdArg) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}