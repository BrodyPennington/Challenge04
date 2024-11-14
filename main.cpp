#include <iostream>
#include <chrono>
#include "BSTLL.h"
#include "RNG.h"
#include "CHRONO.h"


/*
    This code will break on shit operating systems (windows) for some reason. 
    I can optimise it if needed for the sake of my grade.
    Can also provide video of testing if helps.
*/
void populateRandomData(BST &bst, LinkedList &ll, int count, int min, int max, const std::string& datasetName) {

    Chrono chrono;
    RNG rng(min, max);

    chrono.start();

    std::vector<int> randomValuesBST = rng.generateRandomNumbersBST(count);
    std::vector<int> randomValuesLL = rng.generateRandomNumbersLL(count);

    for (int val : randomValuesBST) {
        bst.insert(val);     
    }

    for (int val : randomValuesLL) {
        ll.append(val);
    }

    double genTime = chrono.stop();


    std::cout << std::endl;
    std::cout << "Data Set: " << datasetName << std::endl;
    std::cout << "Time to generate lists: " << genTime << "ms" << std::endl;
}

// populate with sequential data
void populateSequentialData(BST &bst, LinkedList &ll, int start, int end, bool reverse, const std::string& datasetName) {
    Chrono chrono;
    RNG rng(0, 0);

    chrono.start();
    std::vector<int> sequentialValuesBST = rng.generateSequentialNumbersBST(start, end, reverse);
    std::vector<int> sequentialValuesLL = rng.generateSequentialNumbersLL(start, end, reverse);

    for (int val : sequentialValuesBST) {
        bst.insert(val);      
    }

    for (int val : sequentialValuesLL) {
        ll.append(val);
    }

    double genTime = chrono.stop();

    std::cout << std::endl;
    std::cout << "Data Set: " << datasetName << std::endl;
    std::cout << "Time to generate lists: " << genTime << "ms" << std::endl;
}

// Function to measure search time and output results
void measureSearch(BST &bst, LinkedList &ll, int searchValue) {
    Chrono chrono;
    // Search in BST
    chrono.start();
    bool bstFound = bst.search(searchValue);
    double BSTtime = chrono.stop();

    std::cout << "Binary Tree search value: " << searchValue << " -> " << std::boolalpha << bstFound << std::endl;
    std::cout << "Time to find: " << BSTtime << "ms" << std::endl;


    // Search in Linked List
    chrono.start();
    bool llFound = ll.search(searchValue);
    double LLtime = chrono.stop();

    std::cout << "Linked List search value: " << searchValue << " -> " << std::boolalpha << llFound << std::endl;
    std::cout << "Time to find: " << LLtime << "ms" << std::endl;
    std::cout << std::endl;
}

int main() {
    // Create BST and LL instances
    BST bst;
    LinkedList ll;

    // Random number generator for search values
    RNG searchRng(1, 2000);
    RNG searchRngSeq(1, 20000);

    // 1. Random dataset with 500,000 elements
    populateRandomData(bst, ll, 500000, 1, 1000, "500,000");
    int searchValue1 = searchRng.generateRandomNumbers(1)[0];
    measureSearch(bst, ll, searchValue1);

    bst.clear();  // Clear after each dataset
    ll.clear();

    // 2. Random dataset with 1,000,000 elements
    populateRandomData(bst, ll, 1000000, 1, 1000, "1,000,000");
    int searchValue2 = searchRng.generateRandomNumbers(1)[0];
    measureSearch(bst, ll, searchValue2);
    bst.clear();
    ll.clear();

    // 3. Random dataset with 2,000,000 elements
    populateRandomData(bst, ll, 2000000, 1, 1000, "2,000,000");
    int searchValue3 = searchRng.generateRandomNumbers(1)[0];
    measureSearch(bst, ll, searchValue3);
    bst.clear();
    ll.clear();

    // 4. Sequential dataset (1 to 10,000 forward)
    populateSequentialData(bst, ll, 1, 10000, false, "Sequential Forward 1-10,000");
    int searchValue4 = searchRngSeq.generateRandomNumbers(1)[0];
    measureSearch(bst, ll, searchValue4);
    bst.clear();
    ll.clear();

    // 5. Sequential dataset (10,000 to 1 backward)
    populateSequentialData(bst, ll, 1, 10000, true, "Sequential Backward 10,000-1");
    int searchValue5 = searchRngSeq.generateRandomNumbers(1)[0];
    measureSearch(bst, ll, searchValue5);
    bst.clear();
    ll.clear();

    return 0;
}
