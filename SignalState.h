#ifndef SIGNAL_STATE_H
#define SIGNAL_STATE_H

#include <cstring>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "GetNum.h"

namespace lab2{

#define NUMBER_FORMAT 0
#define STRING_FORMAT 1
#define VECTOR_FORMAT 2

class BinarySignal;
  
class SignalState {
  friend class BinarySignal;
  friend std::ostream &operator <<(std::ostream &output, const SignalState &signal);
  friend std::istream &operator >>(std::istream &input, SignalState &signal);
private:
  bool level;
  int time;
public:
  SignalState() : level(0), time(0) {}
  SignalState(int level, int time);
  SignalState(const std::string &signal);
  SignalState(std::vector<int> &signal);
  SignalState(const SignalState &other);
  SignalState &operator =(const SignalState &other);
  SignalState operator ~();

  bool getLevel() const;
  int getTime() const;
  void setLevel(bool level);
  void setTime(int time);
  
  void input(int input_format);
  void output(int output_format);
  void invertSignal();
  void elongateSignal(int duration);
  void truncateSignal(int duration);
  std::string formatSignal() const;
};
  
}

#endif //SIGNAL_STATE_H