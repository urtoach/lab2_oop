#include <iostream>

#include "SignalState.h"

namespace lab2{

  //SignalState::SignalState() : level(0), time(0) {}

  SignalState::SignalState(int level, int time){
    if (!(level < 0 && level > 1) && time > 0){
      this->level = level;
      this->time = time;
    }
    else{
      throw std::invalid_argument("error: invalid signal state");
    }
  }
  
  SignalState::SignalState(const std::string &signal){
    if (signal.find_first_not_of("01") != std::string::npos){
      throw std::invalid_argument("error: invalid characters in string");
    }
    else{
      int i;
      for (i = 0; i < (int)signal.length(); i++) {
        if (signal[i] != signal[0]) {
          break;
        }
      }
      this->level = signal[0];
      this->time = i;
    }
  }
  SignalState::SignalState(std::vector<int> &signal) {
    if (signal.empty()) {
      throw std::invalid_argument("error: empty signal vector");
    }
    int count = 0;
    this->level = (signal[0] != 0);
    for (int i = 0; i < (int)signal.size(); i++){
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

  SignalState &SignalState::operator =(const SignalState &other){
    this->level = other.level;
    this->time = other.time;
    return *this;
  }
  
  bool SignalState::getLevel() const{
    return level;
  }

  int SignalState::getTime() const{
    return time;
  }

  void SignalState::setLevel(bool level){
    this->level = level;
  }

  void SignalState::setTime(int time){
    if (time <= 0){
      this->time = time;
    }
    else{
      throw std::invalid_argument("error: time must be positive");
    }
  }
  

  void SignalState::invertSignal(){
    level = !level;
  } 

  SignalState SignalState::operator ~(){
    SignalState result = *this;
    result.invertSignal();
    return result;
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

  std::string SignalState::formatSignal() const{
    if (time == 0){ return "x"; }
    std::string chart;
    char symbol = (level ? '\'' : '.'); 
    for (int i = 0; i < time; i++){
      chart += symbol;
    }
    return chart;
  }

  void SignalState::input(int input_format){
    switch(input_format){
      case NUMBER_FORMAT:{
        bool lvl = getNum(0, 1);
        int time = getNum(1);
        *this = SignalState(lvl, time);
        break;
      }
      case STRING_FORMAT:{
        std::string signal_str;
        std::cin >> signal_str;
        *this = SignalState(signal_str);
        break;
      }
      default:{
       throw std::invalid_argument("error: invalid input format"); 
      }
    }
    if (std::cin.eof()){
      throw std::runtime_error("find eof");
    }
  }

  void SignalState::output(int output_format){
    switch(output_format){
      case NUMBER_FORMAT:{
        std::cout << level << " " << time << std::endl;
        break;
      }
      case STRING_FORMAT:{
        char ch_lvl = level ? '1' : '0';
        std::cout << std::string(time, ch_lvl) << std::endl;
        break;
      }
      default:{
        throw std::invalid_argument("error: invalid output format");
      }
    }
  }

  std::ostream &operator <<(std::ostream &output, const SignalState &signal){
    char ch_lvl = signal.level ? '1' : '0';
    output << ch_lvl << " " << signal.time;
    return output;
  }

  std::istream &operator >>(std::istream &input, SignalState &signal) {
    int lvl, time;
    input >> lvl >> time;
    if (input.fail()) {
      input.setstate(std::ios_base::failbit);
    } 
    else if (input.eof()) {
      input.setstate(std::ios_base::eofbit);
    } 
    else if (input.bad()) {
      input.setstate(std::ios_base::badbit);
    } 
    else {
      try{
        signal = SignalState(lvl, time);
      }
      catch(...){
        input.setstate(std::ios_base::failbit);    
      }
    }
    return input;
  }

}

