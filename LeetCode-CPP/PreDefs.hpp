#ifndef LEETCODE_CPP_PREDEFS_HPP
#define LEETCODE_CPP_PREDEFS_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::tuple;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::prev;
using std::next;
using std::sort;

template<typename T>
void print(const T &obj) {
    cout << obj;
}

template<typename T>
void println(const T &obj) {
    print(obj);
    cout << endl;
}

template<typename T>
void println(const vector<T> &obj) {
    if (obj.size() == 0) {
        cout << "[ ]" << endl;
    } else {
        cout << "[" << obj.front();
        for (int i = 1; i < obj.size(); i++) {
            cout << ", ";
            print(obj[i]);
        }
        cout << "]" << endl;
    }
}

#endif //LEETCODE_CPP_PREDEFS_HPP
