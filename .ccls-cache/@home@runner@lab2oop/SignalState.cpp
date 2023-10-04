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
      for (int i = 0; i < (int)signal.length(); i++) {
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

  //BinarySignal::BinarySignal() : count(1), signal(new SignalState[this->count]) {}
  
  BinarySignal::BinarySignal(bool level, int time): count(1), signal(new SignalState[this->count]) {
    signal[0].time = time;
    signal[0].level = level;
  }
  
  BinarySignal::BinarySignal(std::string signal_str){
    if (signal_str.find_first_not_of("01") != std::string::npos){
      throw std::invalid_argument("error: invalid characters in string");
    }
    else {
      count = 1;
      char curr = signal_str[0];
      for (int i = 1; 1 < signal_str.length(); i++){
        if (signal_str[i] != curr){
          count++;
          curr = signal_str[i];
        }
      }
      signal = new SignalState[count];
      int index = 0;
      curr = signal_str[0];
      for (int i = 0; i < (int)signal_str.length(); i++){
        if (signal_str[i] != curr){
          signal[index++] = SignalState(signal_str);
          signal_str.erase(0, i + 1);
          i = 0;
        }
      }
      signal[index] = SignalState(signal_str);
    }
  }
  
  BinarySignal::BinarySignal(const BinarySignal& other) : count(other.count), signal(new SignalState[other.count]) {
    this->count = other.count;
    this->signal = new SignalState[count];
    for (int i = 0; i < count; i++) {
      this->signal[i] = other.signal[i]; 
    }
  }

  BinarySignal &BinarySignal::operator =(const BinarySignal &other){
    this->count = other.count;
    this->signal = new SignalState[count];
    for (int i = 0; i < count; i++) {
      this->signal[i] = other.signal[i]; 
    }
    return *this;
  }

  BinarySignal &BinarySignal::operator *=(int n){
    if (n <= 0){ 
      throw std::invalid_argument("error: not positive number");
    }    
    else{
      SignalState *result = new SignalState[n * count];
      int k = 0;
      for (int i = 0; i < n; i++){
        for (int j = 0; j < count; j++){
          result[k] = signal[j];
          k++;
        }
      }
      delete[] signal;
      this->signal = result;
      this->count = count * n;
    }
    return *this;
  }

  BinarySignal BinarySignal::operator *(int n) const{
    if (n <= 0) {
      throw std::invalid_argument("error: not positive number");
    }
    BinarySignal result(*this);
    result *= n;
    return result;
  }
  
  BinarySignal &BinarySignal::operator +=(const BinarySignal &other){
    if (other.count != 0){
      SignalState *result = new SignalState[count + other.count];
      int j = 0;
      for (int i = 0; i < count; i++){
        result[j] = signal[i];
        j++;
      }
      for (int i = 0; i < other.count; i++){
        result[j] = other.signal[i];
        j++;
      }
      delete[] signal;
      this->signal = result;
      this->count = count + other.count;
    }
    return *this;
  }

  BinarySignal &BinarySignal::operator +=(const SignalState &other){
    if (other.time != 0){
      SignalState *result = new SignalState[count + 1];
      for (int i = 0; i < count; i++){
        result[i] = signal[i];
      }
      result[count] = other;
      delete[] signal;
      this->signal = result;
      this->count = count + 1;
    }
    return *this;
  }

  bool BinarySignal::operator[](int time){
    int sum_time = 0;
    for (int i = 0; i < count; i++){
      sum_time += signal[i].time;
      if (sum_time > time){
        return signal[i].level;
      }
    }
    return 
  }

  
  void BinarySignal::invertSignal(){
    for (int i = 0; i < count; i++){
      signal[i].invertSignal();
    }
  }

  std::string BinarySignal::formatedSignal() const{
    std::string formated_signal;
    for (int i = 0; i < count; i++){
      formated_signal += signal[i].formatSignal();
    }
    for (int i = 1; i < (int)formated_signal.length(); i++){
      if (formated_signal[i-1] < formated_signal[i]){
        formated_signal.insert(i, 1, '\\');
        i++;
      }
      else if (formated_signal[i-1] > formated_signal[i]){
        formated_signal.insert(i, 1, '/');
        i++;
      }
    }
    return formated_signal;
  }

  BinarySignal &BinarySignal::insertSignal(const BinarySignal &other, int time){
    if (time < 0 || time > count){
      throw std::invalid_argument("error: invalid inseption time");
    }
    if (time == 0){
      BinarySignal result(other);
      result += *this;
      delete [] signal;
      *this = result;
    }
    else{
      BinarySignal result;
      int sum_time = 0;
      for (int i = 0; i < count; i++){
        if (sum_time > time){
          sum_time += signal[i + other.count].time;
          result += signal[i];
          continue;
        }
        if (sum_time + signal[i].time < time){
          sum_time += signal[i].time;
          result += signal[i];
          continue;
        }
        for (int j = 0; j < signal[i].time; j++){
          if (sum_time == time){
            result += signal[i];
            result.signal[count-1].time = j;
            result += other;
            break;
          }
          sum_time++;
        }
      }
      delete [] signal;
      *this = BinarySignal(result);
    }
    return *this;
  }

  BinarySignal &BinarySignal::removeSignal(int time, int duration){
    if (time < 0 || time >= count){
      throw std::invalid_argument("error: invalid time");
    }
    int start_time = time;
    int end_time = time + duration - 1;
    
    BinarySignal before_interval;
    BinarySignal after_interval;
    before_interval.count = 0;
    after_interval.count = 0;

    int sum_time = 0;
    for (int i = 0; i < count; i++){
      sum_time += signal[i].time;
      if (sum_time <= time){
        before_interval += signal[i];
      }
      else if (sum_time > end_time) {
        after_interval += signal[i];
      }
      else{
        SignalState before_signal(signal[i].level, start_time - sum_time + signal[i].time);
        before_interval += before_signal;
        SignalState after_signal(signal[i].level, sum_time - end_time - 1);
        after_interval += after_signal;
      }
    }

    delete[] signal;
    *this = before_interval;
    *this += after_interval;
    return *this;
  }

}

