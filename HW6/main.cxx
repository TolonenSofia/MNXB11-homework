#include <iostream>
#include <string>

int computeChecksum(const std::string& secArg) {
    int checksum = 0;
    for (char characters : secArg) {
        checksum += characters; 
    }
    return checksum;
}

int calculateKey(int sumCharsSecArg, char firstCharSecArg, std::size_t lenOfCodeName) {
    return (sumCharsSecArg ^ firstCharSecArg * 3) << (lenOfCodeName & 0x1f);
}

int main(int nrOfArgs, char *args[]) {
  bool has3Args = (nrOfArgs == 3);
  if  (has3Args) { 
    std::string codeName{args[0]};  
    char firstCharSecArg{*(args[1])}; 
    std::size_t lenOfCodeName{codeName.size()}; 
    int valueOfThirdArg{std::atoi(args[2])}; 
    std::string secArg{args[1]}; 

    int sumCharsSecArg = computeChecksum(secArg);
    int key = calculateKey(sumCharsSecArg, firstCharSecArg, lenOfCodeName);

    if (key == valueOfThirdArg) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  } 
}  


