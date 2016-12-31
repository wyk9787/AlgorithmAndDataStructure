// Created by Garrett Wang on 12/30/16
// selection_sort.cpp
// running time: O(n^2)
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
    int min_index = i;
    for (int j = i; j < a.size(); j++) {
      if (a[j] < a[min_index]) {
        min_index = j;
      }
    }
    swap(a[min_index], a[i]);
  }
}

int main(int argc, char const *argv[]) {
  // n is how many elements are there in the list
  int n;
  cin >> n;
  vector<int> a(n);
  // input
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  // quick sort
  selection_sort(a);
  // output
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
  return 0;
}
