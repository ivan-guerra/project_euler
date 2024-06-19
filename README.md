# Project Euler

Project Euler solutions in C++.

### Building Solutions and Benchmarks

To build this project you'll need CMake3.28+ and LLVM's clang18 compiler.

To confgiure the project run 

```bash
cmake --preset <PRESET>
```

where `<PRESET>` is anyone of `release`, `debug`, and `debug-valgrind`.

To build and install the binaries run

```bash 
cmake --build --preset <PRESET> --target install
```

On success, CMake will install all binaries to `project_euler/bin/<PRESET>/`.

### Running a Solution

To execute a solution, call the `euler` executable with the problem's ID as the
first argument followed by all problem specific arguments. For example, to
compute the answer to problem 1:

```bash
./euler 1 1000
```

In general, the program usage is

```bash 
euler PROBLEM_ID [ARGS...]
```

### Running a Benchmark

Each solution includes a GoogleBenchmark benchmark executable. The benchmark
executables can be found under `project_euler/bin/<PRESET>/benchmarks`. Simply
run the executable of the solution you would like to benchmark.

If you see a warning regarding CPU scaling, use a utility like `cpupower` to
change your CPU mode governor:

```bash
sudo cpupower frequency-set --governor performance
./soln_1_benchmark
sudo cpupower frequency-set --governor powersave
```
