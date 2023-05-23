#include "KthLargest.h"

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest* kth = new KthLargest(3, nums);
    int first = kth->add(3);
    int second = kth->add(5);
    int third = kth->add(10);
    int forth = kth->add(9);
    int fifth = kth->add(4);

    cout<< first << "\t" << second << "\t" << third << "\t" << forth << "\t" << fifth; 
}