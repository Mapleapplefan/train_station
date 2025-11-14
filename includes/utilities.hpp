#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <cmath>
#include <sstream>
#include <vector>

#include "train.hpp"

template <typename T>
std::ostream& operator<<(std::ostream& os, const Train<T>& train) {
  std::string white_space = "                            ";
  os << "Train (size " << train.size_ << "): \033[?7l \n";

  std::vector<TrainCar<T>*> nodes;
  TrainCar<T>* cur = train.head_;
  for (unsigned int k = 0; k < train.GetSize(); ++k) {
    nodes.push_back(cur);
    if (cur) cur = cur->next_;
  }
  unsigned int per_row = 4;
  unsigned int total = train.GetSize();
  if (total == 0) {
    for (unsigned int i = 0; i < 8; ++i) {
      if (i == 4)
        os << "     -------------------    ";
      else if (i == 5)
        os << "     |     nullptr     |    ";
      else if (i == 6)
        os << "     |                 |    ";
      else if (i == 7)
        os << "     -------------------    ";
      else
        os << "                            ";
      os << std::endl;
    }
    return os;
  }
  unsigned int groups = (total + per_row - 1) / per_row;
  for (unsigned int g = 0; g < groups; ++g) {
    unsigned int start_idx = g * per_row;
    unsigned int remaining = (total > start_idx) ? (total - start_idx) : 0;
    unsigned int group_size = (remaining >= per_row) ? per_row : remaining;

    for (unsigned int i = 0; i < 8; ++i) {
      for (unsigned int j = 0; j < group_size + 2; ++j) {
        std::stringstream id;
        std::stringstream capacity;
        bool is_internal = (j != 0 && j != group_size + 1);
        if (is_internal) {
          TrainCar<T>* node = nodes[start_idx + (j - 1)];
          id << white_space.substr(0, 9) << node->id_
             << white_space.substr(node->id_.size() + 9);
          capacity << white_space.substr(0, 9)
                   << std::to_string(node->capacity_)
                   << white_space.substr(
                          std::to_string(node->capacity_).size() + 9);
        }
        if (j == 0) {
          if (g == 0) {
            if (i == 4)
              os << "     -------------------    ";
            else if (i == 5)
              os << "     |     nullptr     |    ";
            else if (i == 6)
              os << "     |                 |    ";
            else if (i == 7)
              os << "     -------------------    ";
            else
              os << "                            ";
          } else {
            os << "                            ";
          }
          continue;
        }

        if (j == group_size + 1) {
          if (g == groups - 1) {
            if (i == 2)
              os << "     -------------------    ";
            else if (i == 3)
              os << "     |     nullptr     |    ";
            else if (i == 4)
              os << "     |                 |    ";
            else if (i == 5)
              os << "     -------------------    ";
            else
              os << "                            ";
          } else {
            os << "                            ";
          }
          continue;
        }
        if (i == 0 && is_internal) os << "         -----------        ";
        if (i == 1 && is_internal) os << "         |         |        ";
        if (i == 2 && is_internal) os << "     -------------------    ";
        if (i == 3 && is_internal) os << "                       |--->";
        if (i == 4 && is_internal) os << id.str();
        if (i == 5 && is_internal) os << capacity.str();
        if (i == 6 && is_internal) os << "<---|                       ";
        if (i == 7 && is_internal) os << "     -O----------------O-   ";
      }
      os << std::endl;
    }

    if (g != groups - 1) {
      os << "\n\n";
    }
  }

  return os;
}

#endif
