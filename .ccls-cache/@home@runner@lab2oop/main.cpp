#include <iostream>
#include <cstring>
#include <iostream>
#include <limits>
#include <string>
#include "SignalState.h"

/*
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

class SignalState {
private:
  bool level;
  int time;
public:
  SignalState() : level(0), time(0) {}
  SignalState(bool level, int time){
    this->level = level;
    this->time = time;
  }
  SignalState(std::string signal){
    if (signal.find_first_not_of("01") != std::string::npos){
      throw std::invalid_argument("error: invalid characters in string");
    }
    else{
      int i;
      for (i = 0; i < signal.length(); i++) {
        if (signal[i] != signal[0]) {
          signal.erase(i);
          break;
        }
      }
      this->level = signal[0];
      this->time = i+1;
    }
  }

  /*SignalState(const bool *signal, int length){
    if (signal == nullptr || length <= 0){
      throw std::invalid_argument("error: invalid array of signal");
    }
    else{
      this->level = signal[0];
      this->time = 1;
      for (int i = 0; i < length; i++){
        if (this->level != signal[i]){ 
          (this->time)++;
          break; 
        }
      }
    }
  }/////

  void invertSignal(){
    level = !level;
  } 

  void elongateSignal(int duration){
    if (duration > 0){
      time += duration;
    }
    else{
      throw std::invalid_argument("error: invalid time value");
    }
  }

  void truncateSignal(int duration){
    if (duration > 0 && duration <= time){
      time -= duration;
    }
    else{
      throw std::invalid_argument("error: invalid time value");
    }
  }

  std::string formatSignal(){
    if (time == 0){ return "x"; }
    std::string chart;
    char symbol = (level ? '-' : '_'); 
    for (int i = 0; i < time; i++){
      chart += symbol;
    }
    return chart;
  }
  
};
*/





using namespace lab2; 

int main(){
  SignalState a;
  std::cout << a.formatSignal() << std::endl;
  std::cout << "=========================" << std::endl;
  SignalState b(0,10);
  std::cout << b.formatSignal() << std::endl;
  std::cout << "=========================" << std::endl;
  std::cout << "enter signal" << std::endl;
  std::string signal;
  std::cin >> signal;
  //std::cout << signal << std::endl;
  SignalState c(signal);
  std::cout << c.formatSignal() << std::endl;
}