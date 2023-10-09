#include <iostream>
#include <cstring>
#include <iostream>
#include <limits>
#include <string>
#include "SignalState.h"

template <class T>

T getNum(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max()) {
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


using namespace lab2; 

int main(){

  /*std::cout << "enter str5:" << std::endl;
  std::string str5;
  std::cin >> str5;
  BinarySignal signal5(str5);
  std::cout << "ur str5:" << std::endl;
  std::cout << signal5.formatedSignal() << std::endl;
  signal5.removeSignal(2, 4);
  std::cout << signal5.formatedSignal() << std::endl;*/
  
  /*
  std::cout << "enter str1:" << std::endl;
  std::string str1;
  std::cin >> str1;
  BinarySignal signal1(str1);
  std::cout << "ur str1:" << std::endl;
  std::cout << signal1.formatedSignal() << std::endl;
  
  std::cout << "enter str2:" << std::endl;
  std::string str2;
  std::cin >> str2;
  BinarySignal signal2(str2);
  std::cout << "ur str2:" << std::endl;
  std::cout << signal2.formatedSignal() << std::endl;

  BinarySignal signal3 = signal1 * 3;
  std::cout << "\nur str3:" << std::endl;
  std::cout << signal3.formatedSignal() << std::endl;

  signal2 += signal1;
  std::cout << "\nur new str2 += str1:" << std::endl;
  std::cout << signal2.formatedSignal() << std::endl;*/

  std::cout << "\nenter signal4:" << std::endl;
  BinarySignal signal4;
  std::cin >> signal4;
  std::cout << "\nur signal4:" << std::endl;
  std::cout << signal4 << std::endl;
  std::cout << "enter time to insert str" << std::endl;
  int n = 3;//getNum(0);
  
  std::cout << "\nenter signal5 to insert" << std::endl;
  BinarySignal signal5;
  std::cin >> signal5;
  std::cout << "\nur signal5:" << std::endl;
  std::cout << signal5 << std::endl;

  signal4.insertSignal(signal5, n);
  std::cout << "\nur new str4, str5 in str4:" << std::endl;
  std::cout << signal4 << std::endl;
  
}