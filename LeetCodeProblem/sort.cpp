#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

using Iter = vector<int>::iterator;

void mergeSort(Iter begin, Iter end) {
    if (end == begin || end - begin == 1) return;
    auto mid = begin + (end - begin) / 2;
    mergeSort(begin, mid);
    mergeSort(mid, end);
    auto a = begin, b = mid;
    vector<int> res;
    res.reserve(end - begin);
    while (a != mid && b != end) {
        if (*a < *b) res.push_back(*a++);
        else res.push_back(*b++);
    }
    if (a == mid) {
        while (b != end) res.push_back(*b++);
    }
    else if (b == end) {
        while (a != mid) res.push_back(*a++);
    }
    auto p = res.begin();
    while (begin != end) {
        *begin++ = *p++;
    }
}

Iter part(Iter begin, Iter end) {
    auto p = begin + 1, q = end - 1;
    while (p < q) {
        if (*p > *begin) swap(p, q--);
        else p++;
    }
    if (*p > *begin) p--;
    swap(begin, p);
    return p;
}

void quickSort(Iter begin, Iter end) {
    if (end == begin || end - begin == 1) return;
    Iter p = part(begin, end);
    quickSort(begin, p);
    quickSort(p + 1, end);
}

//int main() {
//    default_random_engine e(100);
//    uniform_int_distribution<int> u(-9999, 9999);
//    for (int len : {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 5000, 10000}) {
//        clock_t time1 = 0;
//        clock_t time2 = 0;
//        for (int i = 0; i < 10; i++) {
//            vector<int> arr;
//            arr.reserve(len);
//            for (int j = 0; j < len; ++j) {
//                arr.push_back(u(e));
//            }
//            auto start = clock();
//            mergeSort(arr.begin(), arr.end());
//            auto end = clock();
//            time1 += end - start;
//            shuffle(arr.begin(), arr.end(), e);
//            start = clock();
//            quickSort(arr.begin(), arr.end());
//            end = clock();
//            time2 += end - start;
//        }
//        cout << "array length " << len << " * 10" << endl;
//        cout << "merge sort: " << double(time1) / 1000 << endl;
//        cout << "quick sort: " << double(time2) / 1000 << endl;
//
//    }
//    return 0;
//}