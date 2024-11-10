#include <iostream>
#include <chrono>
#include "BSTLL.h"
#include "RNG.h"
#include "CHRONO.h"

// Helper function to populate with random data
void populateRandomData(BST &bst, LinkedList &ll, int count, int min, int max) {
    RNG rng(min, max);
    std::vector<int> randomValues = rng.generateRandomNumbers(count);
    for (int val : randomValues) {
        bst.insert(val);    // Add to BST
        ll.append(val);     // Add to LL (using append as we discussed)
    }
}

// Helper function to populate with sequential data
void populateSequentialData(BST &bst, LinkedList &ll, int start, int end, bool reverse) {
    RNG rng(0, 0);  // min and max are not needed for sequential
    std::vector<int> sequentialValues = rng.generateSequentialNumbers(start, end, reverse);
    for (int val : sequentialValues) {
        bst.insert(val);    // Add to BST
        ll.append(val);     // Add to LL
    }
}

// Function to measure search time and output results
void measureSearch(BST &bst, LinkedList &ll, int searchValue, const std::string& datasetName) {
    Chrono chrono;
    // Search in BST
    chrono.start();
    bool bstFound = bst.search(searchValue);
    double BSTtime = chrono.stop();

    std::cout << datasetName << " - BST search for value " << searchValue << " " << std::boolalpha << bstFound << std::endl;
    std::cout << "time = " << BSTtime << " ms\n";

    // Search in Linked List
    chrono.start();
    bool llFound = ll.search(searchValue);
    double LLtime = chrono.stop();

    std::cout << datasetName << " - LL search for value " << searchValue << " " << std::boolalpha << llFound << std::endl;
    std::cout << "time = " << LLtime << " ms\n";
}

int main() {
    // Create BST and LL instances
    BST bst;
    LinkedList ll;

    // Random number generator for search values
    RNG searchRng(1, 2000);
    RNG searchRngSeq(1, 20000);

    // 1. Random dataset with 500,000 elements
    populateRandomData(bst, ll, 500000, 1, 1000);
    int searchValue1 = searchRng.generateRandomNumbers(1)[0];
    measureSearch(bst, ll, searchValue1, "Random 500,000");

    bst.clear();  // Clear after each dataset
    ll.clear();

    // 2. Random dataset with 1,000,000 elements
    populateRandomData(bst, ll, 1000000, 1, 1000);
    int searchValue2 = searchRng.generateRandomNumbers(1)[0];
    measureSearch(bst, ll, searchValue2, "Random 1,000,000");
    bst.clear();
    ll.clear();

    // 3. Random dataset with 2,000,000 elements
    populateRandomData(bst, ll, 2000000, 1, 1000);
    int searchValue3 = searchRng.generateRandomNumbers(1)[0];
    measureSearch(bst, ll, searchValue3, "Random 2,000,000");
    bst.clear();
    ll.clear();

    // 4. Sequential dataset (1 to 10,000 forward)
    populateSequentialData(bst, ll, 1, 10000, false);
    int searchValue4 = searchRngSeq.generateRandomNumbers(1)[0];
    measureSearch(bst, ll, searchValue4, "Sequential Forward 1-10,000");
    bst.clear();
    ll.clear();

    // 5. Sequential dataset (10,000 to 1 backward)
    populateSequentialData(bst, ll, 1, 10000, true);
    int searchValue5 = searchRngSeq.generateRandomNumbers(1)[0];
    measureSearch(bst, ll, searchValue5, "Sequential Backward 10,000-1");
    bst.clear();
    ll.clear();

    return 0;
}
