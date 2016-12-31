// Created by Garrett Wang on 12/30/16
// binary-search.cpp
// running time: O(logn)
#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &a, int key) {
  int left = 0;
  int right = a.size() - 1;
  int middle = (left + right) / 2;
  while (left <= right) {
    if (key == a[middle])
      return middle;
    else if (key > a[middle]) {
      left = middle + 1;
      middle = (left + right) / 2;
    } else {
      right = middle - 1;
      middle = (left + right) / 2;
    }
  }
  return -1;
}

int main(int argc, char const *argv[]) {
  // input n, key and the whole array
  int n, key;
  cin >> n >> key;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  // output the 1-based index of the key in this array
  cout << binary_search(a, key) + 1 << endl;
  return 0;
}
