#ifndef TRAIN_CAR_HPP
#define TRAIN_CAR_HPP

#include <iostream>

template <typename T>
class Train;

template <typename T>
class TrainCar {
public:
  TrainCar(const std::string& id, const T& capacity):
      id_(id), capacity_(capacity), next_(nullptr), prev_(nullptr) {}

private:
  std::string id_;
  T capacity_;
  TrainCar* next_;
  TrainCar* prev_;

  // DO NOT MODIFY
  template <typename U>
  friend class Train;
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const Train<U>& train);
};

#endif