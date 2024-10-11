#include <iostream>
#include <string>

int computeChecksum(const std::string& secArg) {
    int checksum = 0;
    for (char characters : secArg) {
        checksum += characters; 
    }
    return checksum;
}

int main(int nrOfArgs, char *args[]) {
  bool has3Args = (nrOfArgs == 3);
  if  (has3Args) { 
    std::string codeName{args[0]};  //codeName before var2
    char firstCharSecArg{*(args[1])}; // firstCharSecArg before var3
    std::size_t lenOfCodeName{codeName.size()}; //lenOfCodeName  before var4
    int valueOfThirdArg{std::atoi(args[2])}; //valueOfThirdArg before var5
    std::string secArg{args[1]}; //secArg before var8
    
    int sumCharsSecArg = computeChecksum(secArg);

    if ((sumCharsSecArg ^ firstCharSecArg * 3) << (lenOfCodeName & 0x1f) == valueOfThirdArg) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  } 
}  


