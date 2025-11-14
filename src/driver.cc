#include <iostream>
#include <string>

#include "train.hpp"
#include "utilities.hpp"

int main() {
  // Test with integers
  std::cout << "\n=== Testing with integers ===" << std::endl;
  Train<int> train1;

  std::cout << "\nTesting PushBack:" << std::endl;
  train1.PushBack("one", 100);
  train1.PushBack("two", 200);
  train1.PushBack("three", 300);
  std::cout << train1 << std::endl;

  std::cout << "\nTesting AddSegmentAfter:" << std::endl;
  train1.AddSegmentAfter("one", new TrainCar("front", 300));
  train1.AddSegmentAfter("two", new TrainCar("mid", 350));
  train1.AddSegmentAfter("three", new TrainCar("end", 350));
  std::cout << train1 << std::endl;

  std::cout << "\nTesting DropOff:" << std::endl;
  train1.DropOff({"one", "two", "three"}, 100);
  train1.DropOff({"mid", "end"}, 250);
  std::cout << train1 << std::endl;

  std::cout << "\nTesting SwapOutSegment:" << std::endl;
  train1.SwapOutSegment("front", new TrainCar("top", 200));
  train1.SwapOutSegment("two", new TrainCar("back", 400));
  std::cout << train1 << std::endl;
}