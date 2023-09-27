#include <iostream>
#include <string>

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
    if (signal.find_first_not_of("01") == std::string::npos){
      std::cout << "fail" << std::endl;
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

  void invertSignal(){
    level = !level;
  } 

  void elongateSignal(int duration){
    if (duration > 0){
      time += duration;
    }
  }

  void truncateSignal(int duration){
    if (duration > 0 && duration <= time){
      time -= duration;
    }
  }

  std::string formatSignal(){
    std::string chart;
    char symbol = (level ? '-' : '_'); 
    for (int i = 0; i < time; i++){
      chart += symbol;
    }
  }
  
};

int main(){

}