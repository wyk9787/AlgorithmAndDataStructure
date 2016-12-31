// Created by Garrett Wang on 12/30/16
// quick_sort.cpp
// running time: O(nlogn)
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int partition(int left, int right, vector<int> &a) {
  int x = a[left];
  int j = left;
  // go through every element
  // partition them into two segments
  for (int i = left + 1; i <= right; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  // swap the left(pivot) element to the middle of the two segments
  swap(a[j], a[left]);
  return j;
}

void randomize(int left, int right, vector<int> &a) {
  // base case
  if (left > right)
    return;
  // find a random pivot
  int k = left + rand() % (right - left + 1);
  swap(a[left], a[k]);
  // partition to two segments
  // one all larger than piviot elements
  // one all smaller than piviot elements
  int m = partition(left, right, a);
  // sort left part
  randomize(left, m - 1, a);
  // sort right part
  randomize(m + 1, right, a);
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
  randomize(0, a.size() - 1, a);
  // output
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
  return 0;
}
