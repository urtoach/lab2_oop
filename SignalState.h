#ifndef SIGNAL_STATE_H
#define SIGNAL_STATE_H

#include <iostream>
#include <cstring>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <regex>

namespace lab2{

template <class T>
T getNum(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max());

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

#define NUMBER_FORMAT 0
#define STRING_FORMAT 1
#define VECTOR_FORMAT 2
  
class BinarySignal{
  friend std::ostream &operator <<(std::ostream &output, const BinarySignal &signal);
  friend std::istream &operator >>(std::istream &input, BinarySignal &signal);
private:
  int count;
  SignalState *signal;
public:
  BinarySignal() : count(0) {}
  BinarySignal(int level, int time);
  BinarySignal(std::string signal_str);
  BinarySignal(const BinarySignal& other);
  ~BinarySignal(){
    delete[] signal;
  }
  BinarySignal(BinarySignal&& other);

  BinarySignal& operator =(BinarySignal&& other);

  BinarySignal operator ~();
  BinarySignal &operator =(const BinarySignal &other);
  BinarySignal &operator *=(int n);
  BinarySignal operator *(int n) const;
  BinarySignal &operator +=(const BinarySignal &other);
  BinarySignal &operator +=(const SignalState &other);
  bool operator[](int time);

  void input(int input_format);
  void output() const;
  int totalTime();
  void invertSignal();
  std::string formatedSignal() const;
  BinarySignal &insertSignal(const BinarySignal &other, int time);
  BinarySignal &removeSignal(int time, int duration);
};

  
}

#endif //SIGNAL_STATE_H