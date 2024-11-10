#include <iostream>
#include <algorithm>
#include <chrono>
#include "BSTLL.h"
#include "RNG.h"


RNG::RNG(int min, int max) : gen(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count())), dis(min, max) {}

std::vector<int> RNG::generateRandomNumbers(int count) {
    std::vector<int> numbers(count);

    for (int &num : numbers) {
        num = dis(gen);  // Generate a random number in range
    }

    return numbers;
}

std::vector<int> RNG::generateSequentialNumbers(int start, int end, bool reverse) {
    std::vector<int> numbers;
    for (int i = start; i <= end; ++i) {
        numbers.push_back(i);
    }

    if (reverse) {
        std::reverse(numbers.begin(), numbers.end());
    }

    return numbers;
}