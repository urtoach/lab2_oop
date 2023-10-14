#include "GetNum.h"

template <class T>

T getNum(T min, T max){
  T val;
  while (true) {
    std::cin >> val;
    if (std::cin.eof()) {
      throw std::runtime_error("find eof");
    } 
    else if (std::cin.bad()) {
      throw std::runtime_error(std::string("failed to read number: ") + strerror(errno));
    } 
    else if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "error. repeat" << std::endl;
    } 
    else if (val >= min && val <= max) {
      return val;
    }
    else{
      std::cin.clear();
      std::cin.ignore();
      std::cout << "error. repeat" << std::endl;
    }
  }
}