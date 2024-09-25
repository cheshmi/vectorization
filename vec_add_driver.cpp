//
// Created by Kazem on 2024-09-25.
//


#include <iostream>
#include <benchmark/benchmark.h>
#include "vec_add.h"


static void BM_VECADD(benchmark::State &state,
                    void (*vecImpl1)(std::vector<float> a, std::vector<float> b, std::vector<float> &c)) {
  int m = state.range(0);
  std::vector<float> A(m);
  std::vector<float> B(m);
  std::vector<float> C(m);
  for (int i = 0; i < m; ++i) {
    A[i] = 1.0;
  }
  for (int i = 0; i < m; ++i) {
    B[i] = 1.0;
  }

  for (auto _: state) {
    vecImpl1(A, B, C);
  }

}

BENCHMARK_CAPTURE(BM_VECADD, baseline_vec_add, swiftware::hpp::vec_add)->Args({2048})->Args({4096})->Args({8192});
BENCHMARK_CAPTURE(BM_VECADD, unrolled_vec_add, swiftware::hpp::vec_add_unrolled)->Args({2048})->Args({4096})->Args({8192});
BENCHMARK_CAPTURE(BM_VECADD, unrolled_scalarized_vec_add, swiftware::hpp::vec_add_unrolled_scalarized)->Args({2048})->Args({4096})->Args({8192});
BENCHMARK_CAPTURE(BM_VECADD, unrolled8_vec_add, swiftware::hpp::vec_add_unrolled8)->Args({2048})->Args({4096})->Args({8192});
BENCHMARK_CAPTURE(BM_VECADD, unrolled8_scalarized_vec_add, swiftware::hpp::vec_add_unrolled8_scalarized)->Args({2048})->Args({4096})->Args({8192});


BENCHMARK_MAIN();
