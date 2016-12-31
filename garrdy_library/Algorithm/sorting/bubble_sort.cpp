// Created by Garrett Wang on 12/30/16
// bubble_sort.cpp
// running time: O(n^2)
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int> &a) {
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < a.size() - 1; j++) {
      if (a[j + 1] < a[j])
        swap(a[j + 1], a[j]);
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
  bubble_sort(a);
  // output
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
  return 0;
}
