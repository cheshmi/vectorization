// Created by SwiftWare Lab on 9/24.
// CE 4SP4 - High Performance Programming
// Copyright (c) 2024 SwiftWare Lab


#ifndef VECTORIZATION_VEC_ADD_H
#define VECTORIZATION_VEC_ADD_H
#include <vector>

namespace swiftware::hpp {

  /// \brief Adds two vectors
  /// \param a The first vector
  /// \param b The second vector
  /// \param c The result vector
  void vec_add(std::vector<float> a, std::vector<float> b, std::vector<float>& c);

  void vec_add_unrolled(std::vector<float> a, std::vector<float> b, std::vector<float>& c);

  void vec_add_unrolled_scalarized(std::vector<float> a, std::vector<float> b, std::vector<float>& c);

  void vec_add_unrolled_avx(std::vector<float> a, std::vector<float> b, std::vector<float>& c);

  void vec_add_unrolled8(std::vector<float> a, std::vector<float> b, std::vector<float>& c);

  void vec_add_unrolled8_scalarized(std::vector<float> a, std::vector<float> b, std::vector<float>& c);

}

#endif //VECTORIZATION_VEC_ADD_H
