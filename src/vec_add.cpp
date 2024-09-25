// Created by SwiftWare Lab on 9/24.
// CE 4SP4 - High Performance Programming
// Copyright (c) 2024 SwiftWare Lab

#include "vec_add.h"

#include "immintrin.h"


namespace swiftware::hpp {

  void vec_add(std::vector<float> a, std::vector<float> b, std::vector<float> &c) {
    int n = a.size();
    c.resize(n);
    for (int i = 0; i < n; ++i) {
      c[i] = a[i] + b[i];
    }
  }

  void vec_add_unrolled(std::vector<float> a, std::vector<float> b, std::vector<float>& c){
    int n = a.size();
    c.resize(n);
    auto bnd1 = n - n % 4;
    for (int i = 0; i < bnd1; i+=4) {
      c[i] = a[i] + b[i];
      c[i+1] = a[i+1] + b[i+1];
      c[i+2] = a[i+2] + b[i+2];
      c[i+3] = a[i+3] + b[i+3];
    }
    for (int i = bnd1; i < n; ++i) {
      c[i] = a[i] + b[i];
    }
  }

  void vec_add_unrolled_sse(std::vector<float> a, std::vector<float> b, std::vector<float>& c){
    int n = a.size();
    c.resize(n);
    auto bnd1 = n - n % 4;
    for (int i = 0; i < bnd1; i+=4) {
      auto a_vec = _mm_loadu_ps(&a[i]);
      auto b_vec = _mm_loadu_ps(&b[i]);
      auto c_vec = _mm_add_ps(a_vec, b_vec);
      _mm_storeu_ps(&c[i], c_vec);
    }
    for (int i = bnd1; i < n; ++i) {
      c[i] = a[i] + b[i];
    }
  }


  void vec_add_unrolled_scalarized(std::vector<float> a, std::vector<float> b, std::vector<float>& c){
    int n = a.size();
    c.resize(n);
    auto bnd1 = n - n % 4;
    for (int i = 0; i < bnd1; i+=4) {
      auto a0 = a[i];
      auto a1 = a[i+1];
      auto a2 = a[i+2];
      auto a3 = a[i+3];
      auto b0 = b[i];
      auto b1 = b[i+1];
      auto b2 = b[i+2];
      auto b3 = b[i+3];
      c[i] = a0 + b0;
      c[i+1] = a1 + b1;
      c[i+2] = a2 + b2;
      c[i+3] = a3 + b3;
    }
    for (int i = bnd1; i < n; ++i) {
      c[i] = a[i] + b[i];
    }
  }

  void vec_add_unrolled8(std::vector<float> a, std::vector<float> b, std::vector<float>& c){
    int n = a.size();
    c.resize(n);
    auto bnd1 = n - n % 8;
    for (int i = 0; i < bnd1; i+=8) {
      c[i] = a[i] + b[i];
      c[i+1] = a[i+1] + b[i+1];
      c[i+2] = a[i+2] + b[i+2];
      c[i+3] = a[i+3] + b[i+3];
      c[i+4] = a[i+4] + b[i+4];
      c[i+5] = a[i+5] + b[i+5];
      c[i+6] = a[i+6] + b[i+6];
      c[i+7] = a[i+7] + b[i+7];
    }
    for (int i = bnd1; i < n; ++i) {
      c[i] = a[i] + b[i];
    }
  }

  void vec_add_unrolled8_scalarized(std::vector<float> a, std::vector<float> b, std::vector<float>& c){
    int n = a.size();
    c.resize(n);
    auto bnd1 = n - n % 8;
    for (int i = 0; i < bnd1; i+=8) {
      auto a0 = a[i];
      auto a1 = a[i+1];
      auto a2 = a[i+2];
      auto a3 = a[i+3];
      auto a4 = a[i+4];
      auto a5 = a[i+5];
      auto a6 = a[i+6];
      auto a7 = a[i+7];
      auto b0 = b[i];
      auto b1 = b[i+1];
      auto b2 = b[i+2];
      auto b3 = b[i+3];
      auto b4 = b[i+4];
      auto b5 = b[i+5];
      auto b6 = b[i+6];
      auto b7 = b[i+7];
      c[i] = a0 + b0;
      c[i+1] = a1 + b1;
      c[i+2] = a2 + b2;
      c[i+3] = a3 + b3;
      c[i+4] = a4 + b4;
      c[i+5] = a5 + b5;
      c[i+6] = a6 + b6;
      c[i+7] = a7 + b7;
    }
    for (int i = bnd1; i < n; ++i) {
      c[i] = a[i] + b[i];
    }
  }

  void vec_add_unrolled_avx(std::vector<float> a, std::vector<float> b, std::vector<float>& c){
    int n = a.size();
    c.resize(n);
    auto bnd1 = n - n % 8;
    for (int i = 0; i < bnd1; i+=8) {
      auto a_vec = _mm256_loadu_ps(&a[i]);
      auto b_vec = _mm256_loadu_ps(&b[i]);
      auto c_vec = _mm256_add_ps(a_vec, b_vec);
      _mm256_storeu_ps(&c[i], c_vec);
    }
    for (int i = bnd1; i < n; ++i) {
      c[i] = a[i] + b[i];
    }
  }
}
