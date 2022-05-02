#include <iostream>
#include <random>
#include <chrono>
#include "SingleHash.h"
#include "FourLevelHash.h"


int main() {
    SingleHash H(17);
    vector<int> primes = { 5, 7, 17, 29 };
    FourLevelHash H4(primes);


    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 1000000000.0);

    std::cout << "Hashing With Chaining!!" << std::endl;

    int size = 1000000;
    long long find;
    auto start1 = std::chrono::high_resolution_clock::now();

    cout << "Allocating Items" << endl;
    for (auto i = 0; i < size; i++) {
        auto temp = (long long)(dist(mt));
        if (i == 70000)
            find = temp;
        H.insertItem(temp);
        H4.insertItem(temp);
    }
    cout << "Items Allocated" << endl;
    auto stop1 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::seconds>(stop1 - start1);
    cout << "Item Allocation Duration: " << duration1.count() << " seconds" << endl;

    H.displaySizes();
    //H4.displaySizes();

    auto start2 = std::chrono::high_resolution_clock::now();
    H.findNumber(find);
    auto stop2 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);
    cout << "Single Hash Function completed searching in " << duration2.count() << " microseconds" << endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    H4.findNumber(find);
    auto stop3 = std::chrono::high_resolution_clock::now();

    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(stop3 - start3);
    cout << "Four Level Hash Function completed searching in " << duration3.count() << " microseconds" << endl;

    return 0;
}
