#include <vector>
#include <random>
#include <iostream>

class RNG {
public:
    // Constructor to initialize RNG with a range
    RNG(int min, int max);

    // Function to generate a specified number of random numbers
    std::vector<int> generateRandomNumbersBST(int count);
    std::vector<int> generateRandomNumbersLL(int count);
    std::vector<int> generateRandomNumbers(int count);

    // function to generate sequential numbers
    std::vector<int> generateSequentialNumbersBST(int start, int end, bool reverse = false);
    std::vector<int> generateSequentialNumbersLL(int start, int end, bool reverse = false);

private:
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
};