#include <benchmark/benchmark.h>
#include <vector>
#include "matrix_vec.h"

// Benchmark for base implementation
static void BM_matmul_base(benchmark::State& state) {
    int m = state.range(0);
    int n = state.range(1);
    std::vector<float> A(m * n), x(n), y(m);

    // Initialize
    for (int i = 0; i < m * n; i++) A[i] = 1.5f;
    for (int i = 0; i < n; i++) x[i] = 2.0f;

    for (auto _ : state) {
        matmul_base(A.data(), x.data(), y.data(), m, n);
    }
    state.counters["FLOPs"] = benchmark::Counter(2.0 * m * n, benchmark::Counter::kIsRate);
}

// Benchmark for inner loop vectorization
static void BM_matmul_inner_vec(benchmark::State& state) {
    int m = state.range(0);
    int n = state.range(1);
    std::vector<float> A(m * n), x(n), y(m);

    // Initialize
    for (int i = 0; i < m * n; i++) A[i] = 1.5f;
    for (int i = 0; i < n; i++) x[i] = 2.0f;

    for (auto _ : state) {
        matmul_inner_vec(A.data(), x.data(), y.data(), m, n);
    }
    state.counters["FLOPs"] = benchmark::Counter(2.0 * m * n, benchmark::Counter::kIsRate);
}

// Benchmark for 2D vectorization
static void BM_matmul_2d_vec(benchmark::State& state) {
    int m = state.range(0);
    int n = state.range(1);
    std::vector<float> A(m * n), x(n), y(m);

    // Initialize
    for (int i = 0; i < m * n; i++) A[i] = 1.5f;
    for (int i = 0; i < n; i++) x[i] = 2.0f;

    for (auto _ : state) {
        matmul_2d_vec(A.data(), x.data(), y.data(), m, n);
    }
    state.counters["FLOPs"] = benchmark::Counter(2.0 * m * n, benchmark::Counter::kIsRate);
}

// Register benchmarks with different matrix sizes
BENCHMARK(BM_matmul_base)->Args({1000, 1000});
BENCHMARK(BM_matmul_inner_vec)->Args({1000, 1000});
BENCHMARK(BM_matmul_2d_vec)->Args({1000, 1000});

BENCHMARK_MAIN();
