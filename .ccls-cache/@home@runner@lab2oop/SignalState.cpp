#include <iostream>
#include "SignalState.h"

namespace lab2{

  //SignalState::SignalState() : level(0), time(0) {}

  SignalState::SignalState(bool level, int time){
    this->level = level;
    this->time = time;
  }
  SignalState::SignalState(std::string &signal){
    if (signal.find_first_not_of("01") != std::string::npos){
      throw std::invalid_argument("error: invalid characters in string");
    }
    else{
      for (int i = 0; i < signal.length(); i++) {
        if (signal[i] != signal[0]) {
          signal.erase(i);
          break;
        }
      }
      this->level = signal[0];
      this->time = signal.length();
    }
  }
  SignalState::SignalState(std::vector<int> &signal) {
    if (signal.empty()) {
      throw std::invalid_argument("error: empty signal vector");
    }
    int count = 0;
    this->level = (signal[0] != 0);
    for (int i = 0; i < signal.size(); i++){
      if (signal[i] != this->level){
        break;
      }
      count++;
    }
    this->time = count;
  }

  SignalState::SignalState(const SignalState &other){
    this->level = other.level;
    this->time = other.time;
  }

  void SignalState::invertSignal(){
    level = !level;
  } 

  void SignalState::elongateSignal(int duration){
    if (duration > 0){
      time += duration;
    }
    else{
      throw std::invalid_argument("error: invalid time value");
    }
  }

  void SignalState::truncateSignal(int duration){
    if (duration > 0 && duration <= time){
      time -= duration;
    }
    else{
      throw std::invalid_argument("error: invalid time value");
    }
  }

  std::string SignalState::formatSignal(){
    if (time == 0){ return "x"; }
    std::string chart;
    char symbol = (level ? '-' : '_'); 
    for (int i = 0; i < time; i++){
      chart += symbol;
    }
    return chart;
  }

}

