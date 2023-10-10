#include <iostream>
#include "SignalState.h"

namespace lab2{

  //SignalState::SignalState() : level(0), time(0) {}

  SignalState::SignalState(bool level, int time){
    this->level = level;
    this->time = time;
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
      this->time = i + 1;
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

  SignalState &SignalState::operator ~(){
    this->invertSignal();
    return *this;
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

  std::ostream &operator <<(std::ostream &output, const SignalState &signal){
    output << signal.formatSignal();
    return output;
  }

  std::istream &operator >>(std::istream& input, SignalState &signal) {
    char first_char;
    char second_char;
    first_char = input.get();
    second_char = input.get();
    input.putback(second_char);
    input.putback(first_char);
    if (second_char == ' ' && (first_char == '0' || first_char == '1')) {
      int lvl, time;
      input >> lvl >> time;
      signal = SignalState(lvl, time);
    } 
    else if (first_char == 's') {
      std::string input_str;
      input >> input_str;
      std::regex pattern("^str([01]+).*$");
      std::smatch match;
      if (std::regex_match(input_str, match, pattern)) {
        std::string binarySequence = match[1].str();
        signal = SignalState(binarySequence);
      } 
      else {
        throw std::invalid_argument("error: invalid input");
      }
    } 
    else {
      throw std::invalid_argument("error: invalid input");
    }
    return input;
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
      count = 0;
      signal = nullptr;

      for (int i = 0; i < (int)signal_str.length(); i++) {
        char current_level = signal_str[i];
        int current_time = 1;
        while (i < (int)signal_str.length() - 1 && signal_str[i + 1] == current_level) {
          current_time++;
          i++;
        }
        *this += SignalState(bool(current_level - '0'), current_time);
      }
    }
  }
  
  BinarySignal::BinarySignal(const BinarySignal& other) : count(other.count), signal(new SignalState[other.count]) {
    std::copy(other.signal, other.signal + count, this->signal);
  }

  BinarySignal::BinarySignal(BinarySignal&& other) : count(other.count), signal(other.signal) {
    other.count = 0;
    other.signal = nullptr;
  }

  /*BinarySignal& BinarySignal::operator =(BinarySignal&& other)  {
    if (this != &other) {
      delete[] signal;
      count = other.count;
      signal = other.signal;
      other.count = 0;
      other.signal = nullptr;
    }
    return *this;
  }*/

  BinarySignal &BinarySignal::operator =(const BinarySignal &other){
    if (this == &other) {
      return *this;
    }
    if (count != 0){ delete[] signal; }
    this->count = other.count;
    if (other.count != 0) {
      this->signal = new SignalState[count];
    }
    std::copy(other.signal, other.signal + count, this->signal);
    return *this;
  }

  BinarySignal &BinarySignal::operator *=(int n){
    if (n <= 0){ 
      throw std::invalid_argument("error: not positive number");
    }  
    else if (count == 0){
      return *this;
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
    if (count == 0){
      *this = other;
    }
    if (this->count == 1 && this->signal[0].time == 0){
      *this = other;
    }
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
    if (count == 0){
      signal = new SignalState[1];
      signal[0] = other;
      count = 1;
      return *this;
    }
    if (this->count == 1 && this->signal[0].time == 0){
      this->signal[0] = other;
    }
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

  bool BinarySignal::operator [](int time){
    int sum_time = 0;
    for (int i = 0; i < count; i++){
      sum_time += signal[i].time;
      if (sum_time > time){
        return signal[i].level;
      }
    }
    throw std::invalid_argument("error: strange error xD");
  }

  
  void BinarySignal::invertSignal(){
    for (int i = 0; i < count; i++){
      signal[i].invertSignal();
    }
  }

  BinarySignal &BinarySignal::operator ~(){
    for (int i = 0; i < count; i++){
      signal[i].invertSignal();
    }
    return *this;
  }

  int BinarySignal::totalTime(){
    int sum_time = 0;
    for (int i = 0; i < count; i++){
      sum_time += signal[i].time;
    }
    return sum_time;
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

  BinarySignal &BinarySignal::insertSignal(const BinarySignal &other, int time) {
    int total_time = this->totalTime();
    if (time < 0 || total_time < time) {
      throw std::invalid_argument("error: invalid insertion time");
    }
    if (total_time == time){
      *this += other;
      return *this;
    }
    int start_time = time;
    
    if (start_time == 0){
      BinarySignal result(other);
      result += *this;
      delete [] signal;
      *this = result;
      return *this;
    }
    
    BinarySignal before_interval;
    BinarySignal after_interval;
    //before_interval.count = 0;
    //after_interval.count = 0;

    int sum_time = 0;

    for (int i = 0; i < count; i++) {
      sum_time += signal[i].time;
      if (sum_time < time) {
        before_interval += signal[i];
      } 
      else if (sum_time == time) {
        before_interval += signal[i];
        before_interval += other;
      } 
      else if (sum_time - signal[i].time < time) {
        before_interval += SignalState(signal[i].level, start_time - sum_time + signal[i].time);
        before_interval += other;
        after_interval += SignalState(signal[i].level, sum_time - start_time);
      }
      if (sum_time - signal[i].time > time) {
        after_interval += signal[i];
      }
    }
    
    before_interval += after_interval;
    *this = before_interval;
    return *this;
  }
  
  BinarySignal &BinarySignal::removeSignal(int time, int duration) {
    int total_time = this->totalTime();
    if (time < 0 && total_time < time + duration) {
      throw std::invalid_argument("error: invalid time");
    }

    int start_time = time;
    int end_time = time + duration - 1;

    BinarySignal before_interval;
    BinarySignal after_interval;
    before_interval.count = 0;
    after_interval.count = 0;

    int sum_time = 0;
    for (int i = 0; i < count; i++) {
      sum_time += signal[i].time;
      if (sum_time <= start_time) {
        before_interval += signal[i];
      } 
      else if (sum_time - signal[i].time > end_time) {
          after_interval += signal[i];
      } 
      else {
        if (sum_time - signal[i].time < start_time) {
          before_interval += SignalState(signal[i].level, start_time - sum_time + signal[i].time);
        }
        if (end_time - sum_time <= signal[i].time) {
          after_interval += SignalState(signal[i].level, sum_time - end_time - 1);
        }
      }
    }

    before_interval += after_interval;
    *this = before_interval;

    return *this;
  }

  std::ostream &operator <<(std::ostream &output, const BinarySignal &signal){
    output << signal.formatedSignal();
    return output;
  }

  std::istream &operator >>(std::istream& input, BinarySignal& signal) {
    char first_char;
    char second_char;
    first_char = input.get();
    second_char = input.get();
    input.putback(second_char);
    input.putback(first_char);
    if (second_char == ' ' && (first_char == '0' || first_char == '1')) {
      int lvl, time;
      input >> lvl >> time;
      signal = BinarySignal(lvl, time);
    } 
    else if (first_char == 's') {
      std::string input_str;
      input >> input_str;
      std::regex pattern("^str([01]+).*$");
      std::smatch match;
      if (std::regex_match(input_str, match, pattern)) {
        std::string binary_sequence = match[1].str();
        signal = BinarySignal(binary_sequence);
      } 
      else {
        throw std::invalid_argument("error: invalid input");
      }
    } 
    else {
      throw std::invalid_argument("error: invalid input");
    }
    return input;
  }
}

