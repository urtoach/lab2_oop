#ifndef SIGNAL_STATE_H
#define SIGNAL_STATE_H

#include <iostream>
#include <cstring>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

namespace lab2{

class BinarySignal;
  
class SignalState {
  friend class BinarySignal;
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
  size_t count;
  SignalState *signal;
public:
  BinarySignal() : count(1), signal(new SignalState[this->count]) {}
  BinarySignal(bool level, int time): count(1), signal(new SignalState[this->count]) {}
  
  BinarySignal(std::string signal_str);
  
  BinarySignal(const BinarySignal& other) : count(other.count), signal(new SignalState[other.count]) {
    for (size_t i = 0; i < count; i++) {
      signal[i] = other.signal[i]; 
    }
  }
  ~BinarySignal(){
    delete[] signal;
  }

  BinarySignal &operator *=(int n);
  BinarySignal operator *(int n) const;
  BinarySignal &operator +=(const BinarySignal &other);
  BinarySignal &operator +=(const SignalState &other);

  bool operator[](int time);
  void invertSignal();
  std::string formatedSignal() const;
  BinarySignal &insertSignal(const BinarySignal &other, int time);
  BinarySignal &removeSignal(int time, int duration);
  
};

  
}

#endif //SIGNAL_STATE_H