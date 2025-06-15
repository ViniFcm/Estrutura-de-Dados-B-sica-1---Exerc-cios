//
//  main.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include <iostream>
#include <iostream>
#include <cassert>
#include "Set.h"

using namespace std;

bool twoSum(int array[], int arraySize, int k){
    
}

int main(int argc, const char * argv[]) {

    int array[] = {1, 2, 4, 5, 10, 8, 9, 11, 7, 3};
    int arraySize = 10;

    assert(twoSum(array, arraySize, 0) == false);
    assert(twoSum(array, arraySize, 1) == false);
    assert(twoSum(array, arraySize, 2) == true);// 1 + 1
    assert(twoSum(array, arraySize, 3) == true);// 1 + 2
    assert(twoSum(array, arraySize, 4) == true);// 1 + 3
    assert(twoSum(array, arraySize, 5) == true);// 1 + 4
    assert(twoSum(array, arraySize, 6) == true);// 1 + 5
    assert(twoSum(array, arraySize, 7) == true);// 2 + 5
    assert(twoSum(array, arraySize, 8) == true);// 3 + 5
    assert(twoSum(array, arraySize, 9) == true);// 1 + 8
    assert(twoSum(array, arraySize, 10) == true);// 1 + 9
    assert(twoSum(array, arraySize, 11) == true);// 1 + 10
    assert(twoSum(array, arraySize, 12) == true);// 1 + 11
    assert(twoSum(array, arraySize, 13) == true);// 3 + 10
    assert(twoSum(array, arraySize, 14) == true);// 4 + 10
    assert(twoSum(array, arraySize, 15) == true);// 5 + 10
    assert(twoSum(array, arraySize, 16) == true);// 7 + 9
    assert(twoSum(array, arraySize, 17) == true);// 10 + 7
    assert(twoSum(array, arraySize, 18) == true);// 10 + 8
    assert(twoSum(array, arraySize, 19) == true);// 10 + 9
    assert(twoSum(array, arraySize, 20) == true);// 10 + 10
    assert(twoSum(array, arraySize, 21) == true);// 10 + 11
    assert(twoSum(array, arraySize, 22) == true);// 11 + 11
    assert(twoSum(array, arraySize, 23) == false);
    assert(twoSum(array, arraySize, 50) == false);
    assert(twoSum(array, arraySize, 100) == false);
    

    std::cout << "Teste OK!" << std::endl;
}
