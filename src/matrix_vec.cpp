#include <immintrin.h>
#include "matrix_vec.h"

// Base unvectorized implementation
void matmul_base(const float* A, const float* x, float* y, int m, int n) {
    for (int i = 0; i < m; i++) {
        y[i] = 0.0f;
        for (int j = 0; j < n; j++) {
            y[i] += A[i * n + j] * x[j];
        }
    }
}

// Inner loop vectorization (SIMD on j loop)
void matmul_inner_vec(const float* A, const float* x, float* y, int m, int n) {
    for (int i = 0; i < m; i++) {
        __m256 sum = _mm256_setzero_ps();
        int j = 0;

        // Process 8 floats at a time
        for (; j <= n - 8; j += 8) {
            __m256 a_vec = _mm256_loadu_ps(&A[i * n + j]);
            __m256 x_vec = _mm256_loadu_ps(&x[j]);
            __m256 prod = _mm256_mul_ps(a_vec, x_vec);
            sum = _mm256_add_ps(sum, prod);
        }

        // Horizontal sum of 8 elements
        __m256 t = _mm256_hadd_ps(sum, sum);
        t = _mm256_hadd_ps(t, t);
        y[i] = _mm_cvtss_f32(_mm256_castps256_ps128(t));

        // Scalar remainder
        for (; j < n; j++) {
            y[i] += A[i * n + j] * x[j];
        }
    }
}

// 2D vectorization (SIMD on both i and j)
void matmul_2d_vec(const float* A, const float* x, float* y, int m, int n) {
  // TODO: Implement 2D vectorization using AVX2  intrinsics
}
