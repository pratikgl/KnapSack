# KnapSack

A genetic algorithm (Local search) approach to solve the 0/1 Knapsack Problem.

The genetic algorithm is implemented in the header file [utility.hpp](https://github.com/pratikgl/KnapSack/blob/master/utility.hpp). The program after solving Knapsack using genetic algorithm compares the result with the optimal answer calculated using dynamic programming. This dynamic programming algorithm is implemented in [dp.hpp](https://github.com/pratikgl/KnapSack/blob/master/dp.hpp).

## Installation

1. Clone the whole repo on your local machine using
```bash
git clone https://github.com/pratikgl/KnapSack.git
```

2. The project is tested on g++ (GCC) 9.3.0. Check your GCC version using
```shell
g++ --version
```

3. Compile main.cpp
```bash
g++ -o KnapSack.exe main.cpp
```

4. Run the compiled program
```bash
./KnapSack.exe
```

## Contributing
The implementation is simple and straightforward. However, the efficiency of the implementation can be improved. Please feel free to contribute.
