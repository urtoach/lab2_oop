#ifndef BINARY_SIGNAL_H
#define BINARY_SIGNAL_H

#include "SignalState.h"

namespace lab2{

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

#endif //BINARY_SIGNAL_H