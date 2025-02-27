﻿#include <iostream>
#include <algorithm>
#include "kata.h"
/*An Arithmetic Progression is defined as one in which there is a constant difference between the consecutive terms of a given series of numbers. You are provided with consecutive elements of an Arithmetic Progression. There is however one hitch: exactly one term from the original series is missing from the set of numbers which have been given to you. The rest of the given series is the same as the original AP. Find the missing term.

You have to write a function that receives a list, list size will always be at least 3 numbers. The missing term will never be the first or last one.

Example
findMissing([1, 3, 5, 9, 11]) == 7*/
using namespace std;

static long findMissing(std::vector<long> list) {

    //sum of aithmetic  
    //sum = n/2*(2*first element +(n -1) d
    // difference is not known so we can use n+1 formula
    // (n+1)* Average
    // (n+1)*(first+last)/2
    long long expectedSum = (list.front() + list.back()) * (list.size() + 1);
    long long actualSum = std::accumulate(list.begin(), list.end(), 0ll);

    return (expectedSum - 2 * actualSum) / 2;
}
int main() {
    std::vector<long> list{ 1, 3, 5, 9, 11 };
    std::cout<<findMissing(list);
    return 0;
}