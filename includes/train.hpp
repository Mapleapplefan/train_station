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
  TrainCar<T> curr = head_;
  while(curr) {
    TrainCar<T> next_car = curr->next_;
    delete curr;
    curr = next_car;
  }
  head_ = nullptr;
  tail_ = nullptr;
}


template <typename T>
void Train<T>::PushBack(const std::string& id, const T& capacity) {
  Train<T> new_car = Train<T>(id, capacity);
  if (head_ == nullptr) {
    head_ = new_car;
  }
  tail_-> prev_ = tail_;
  tail_->next_ = new_car;
  tail_ = new_car;
  size_++;
}

template <typename T>
void Train<T>::AddSegmentAfter(const std::string& id, TrainCar<T>* segment) {
  //if train empty
  if (head_ == nullptr){
    throw std::runtime_error("invalid arg");
  }
  TrainCar<T> curr = head_;
  while (curr){
    if (curr->id_ == id) {
      if (curr == tail_) {
        segment-> prev_ = tail_;
        tail_-> next_ = segment;
        tail_ = segment;
      } else {
        TrainCar<T> after = curr->next;
        segment-> prev_ = curr;
        curr->next_ = segment;
        after->prev_ = segment;
        segment->next_ = after;
      }
    }
  }
}

template <typename T>
void Train<T>::DropOff(std::set<std::string> ids, T count) {
  if (head_ == nullptr){
    throw std::runtime_error("invalid arg");
  }
  TrainCar<T> curr = head_;
  while (curr){
    for (std::string id: ids) {
       if (curr->id_ == id) {
        curr->capacity_ = curr->capacity_ -1;
        if (curr->capacity_ <= 0){
          if (curr = head_){
            head_ = curr->next_;
            delete curr;
          } else if (curr = tail_){
            curr->prev_ = curr;
            tail_ = curr->prev_;
            delete curr;
          }else {
          //remove deallocated 
          TrainCar<T> train = curr->next_;
          curr->prev_ = train;
          curr->next_ = train->prev_;
          delete curr;
          }
        }
       }
    }
  }
}

//Swaps the train car with the specifed id with the train car segment passed in.
  //Ensure that prev_ and next_ pointers are updated accordingly for all train cars involved.
  // Update head_ and tail_ if the previous train car at that location was replaced.
  //Properly deallocate the train car that was swapped out once pointers have been updated.
  //Handle cases where the car with the specified id does not exist in the train, or no cars are in the train by throwing an std::runtime_error.
template <typename T>
void Train<T>::SwapOutSegment(const std::string& id, TrainCar<T>* car) {
  if (head_ == nullptr){
    throw std::runtime_error("invalid arg");
  }
  TrainCar<T> curr = head_;
  while (curr){
    if (curr->id_ == id) {
      if (curr == head_) {
        car->next_ = head_->next_;
        head_->next_->prev_ = car;
        head_ = car;
      } else if (curr == tail_) {
        car->prev_ = tail_->prev_;
        tail_->prev_->next_ = car;
        tail_ = car;
      } else {
        car->prev_ = curr->prev_;
        car->next_ = curr->next_;
        curr->prev_->next_ = car;
        curr->next_->prev_ = car;
      }
      delete curr;
      return;
    }
    curr = curr->next_;
  }
  throw std::runtime_error("invalid arg");
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