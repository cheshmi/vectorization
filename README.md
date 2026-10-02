# vectorization

This tutorial teaches vectorization in CE 4SP4 using two simple examples: vector addition and matrix-vector multiplication.

### Logging in to the server
Use``ssh <username>@srv-cad.ece.mcmaster.ca`` to login to the server.
* `username` and password is provided to you.


### Cloning and Buidling the repository
* Use `git clone https://github.com/cheshmi/vectorization.git` to clone the repository in your scratch directory

### Running the code
* Use `sbatch build_run.sh` to run the code on a compute node of the teach cluster.
* The script runs both examples and generates performance benchmarks.

# Vectorization Examples

SIMD optimization techniques using AVX-256.

## Examples

### 1. Vector Addition (vec_add)

Basic SIMD vectorization example demonstrating:
- Base unvectorized implementation
- AVX-256 vectorized version
- Performance benchmarking

**File:** `src/vec_add.cpp`


### 2. Matrix-Vector Multiplication (matrix_vec)

Three levels of vectorization:
- **Base:** Unvectorized scalar implementation
- **Inner Loop:** SIMD vectorization on inner loop (8 elements at a time)
- **2D Vectorization:** SIMD on both row and column dimensions

**File:** `src/matrix_vec.cpp`



## TODO

Finish the 2D vectorization implementation in `matrix_vec.cpp` and add performance benchmarks.
