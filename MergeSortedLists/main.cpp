#include <iostream>
#include <vector>

#include "MergeIterator.h"

int main() {
    std::vector<int> l1 = { 1, 8, 15, 16, 35 };
    std::vector<int> l2 = { 2, 7, 12, 63 };
    std::vector<int> l3 = { 10, 13, 14, 42 };

    MergeIterator mergedList(l1, l2, l3);

    while (mergedList.HasNext()) {
        std::cout << mergedList.GetNext() << " ";
    }
}
