#ifndef SIGNAL_STATE_H
#define SIGNAL_STATE_H

#include <iostream>
#include <cstring>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

namespace lab2{

class SignalState {
private:
  bool level;
  size_t time;
public:
  SignalState() : level(0), time(0) {}
  SignalState(bool level, int time);
  SignalState(std::string &signal);
  SignalState(std::vector<int> &signal);
  SignalState(const SignalState &other);
  void invertSignal();
  void elongateSignal(int duration);
  void truncateSignal(int duration);
  std::string formatSignal();
};

class BinarySignal{
private:
  size_t time;
  SignalState *signal;
public:
  BinarySignal() : time(1), signal(new SignalState[this->time]) {}
  BinarySignal(std::string signal_str){
    if (signal_str.find_first_not_of("01") != std::string::npos){
      throw std::invalid_argument("error: invalid characters in string");
    }
    else {
      this->time = signal_str.length();
      signal = new SignalState[this->time];
      for (int i = 0; i < this->time; i++){
        signal[i] = SignalState(signal_str[i], 1);
      }
    }
  }
  BinarySignal(const BinarySignal& other) : time(other.time), signal(new SignalState[other.time]) {
    for (size_t i = 0; i < time; i++) {
      signal[i] = other.signal[i]; 
    }
  }

  ~BinarySignal(){
    delete[] signal;
  }

  BinarySignal &operator *(int n){
    if (n <= 0){ 
      throw std::invalid_argument("error: not positive number");
    }    
    else{
      SignalState *result = new SignalState[n * time];
      int k = 0;
      for (int i = 0; i < n; i++){
        for (int j = 0; j < time; j++){
          result[k] = signal[j];
          k++;
        }
      }
      delete[] signal;
      this->signal = result;
      this->time = time*n;
    }
  }
  
  BinarySignal &operator +=(const BinarySignal &other){
    if (other.time != 0){
      SignalState *result = new SignalState[time + other.time];
      int j = 0;
      for (int i = 0; i < time; i++){
        result[j] = signal[i];
        j++;
      }
      for (int i = 0; i < other.time; i++){
        result[j] = other.signal[i];
        j++;
      }
      delete[] signal;
      this->signal = result;
      this->time = time + other.time;
    }
  }
  
  void invertSignal(){
    
  }

}

  
}

#endif //SIGNAL_STATE_H