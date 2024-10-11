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

void printingValues(int checksum, int key, int expectedKey) {
  std::cout << "The checksum for the second argument is: " << checksum << std::endl;
  std::cout << "The calculated key is: " << key << std::endl;
  std::cout << "The expected key is: " << expectedKey << std::endl;
}

void printInputError(){
  std::cout << "Wrong number of arguments, input 3 arguments!" << std::endl;
  std::cout << "Example: <codeName> <secondArg> <thirdArg>" << std::endl;
}

int main(int nrOfArgs, char *args[]) {
  bool has3Args = (nrOfArgs == 3);
  if  (has3Args) { 
    std::string codeName{args[0]};  
    char firstCharSecArg{*(args[1])}; 
    std::size_t lenOfCodeName{codeName.size()}; 
    std::string secArg{args[1]}; 

    int valueOfThirdArg{std::atoi(args[2])}; //called expected key in output
    int sumCharsSecArg = computeChecksum(secArg); // called checksum in output
    int key = calculateKey(sumCharsSecArg, firstCharSecArg, lenOfCodeName);
    printingValues(sumCharsSecArg, key, valueOfThirdArg);

    if (key == valueOfThirdArg) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  } else {
    printInputError();
    }
}  


