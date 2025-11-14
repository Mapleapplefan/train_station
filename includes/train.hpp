#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <iomanip>
#include <iostream>
#include <ostream>
#include <set>
#include <sstream>
#include <stdexcept>

#include "train_car.hpp"

template <typename T>
class Train {
public:
  Train();

  ~Train();  // TODO

  Train(const Train& other) = delete;

  Train& operator=(const Train& other) = delete;

  void DropOff(std::set<std::string> ids, T count);  // TODO

  void SwapOutSegment(const std::string& id, TrainCar<T>* car);  // TODO

  void AddSegmentAfter(const std::string& id, TrainCar<T>* segment);  // TODO

  void PushBack(const std::string& id, const T& capacity);  // TODO

  bool IsEmpty() const;
  size_t GetSize() const;

  // DO NOT MODIFY
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const Train<U>& train);

private:
  TrainCar<T>* head_;
  TrainCar<T>* tail_;
  size_t size_;
};

template <typename T>
Train<T>::Train(): head_(nullptr), tail_(nullptr), size_(0) {}

template <typename T>
Train<T>::~Train() {
  // TODO
}

template <typename T>
void Train<T>::PushBack(const std::string& id, const T& capacity) {
  // TODO
}

template <typename T>
void Train<T>::AddSegmentAfter(const std::string& id, TrainCar<T>* segment) {
  // TODO
}

template <typename T>
void Train<T>::DropOff(std::set<std::string> ids, T count) {
  // TODO
}

template <typename T>
void Train<T>::SwapOutSegment(const std::string& id, TrainCar<T>* car) {
  // TODO
}

// GIVEN
template <typename T>
bool Train<T>::IsEmpty() const {
  return size_ == 0;
}

template <typename T>
size_t Train<T>::GetSize() const {
  return size_;
}

#endif