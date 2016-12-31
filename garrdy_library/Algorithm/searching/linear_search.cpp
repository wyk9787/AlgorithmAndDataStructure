// Created by Garrett Wang on 12/30/16
// linear_search.cpp
// Running time: O(n)

#include <iostream>
#include <vector>

using namespace std;

int linear_search(vector<int> &a, int key) {
  for (int i = 0; i < a.size(); i++)
    if (a[i] == key)
      return i;
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
  cout << linear_search(a, key) + 1 << endl;
  return 0;
}
