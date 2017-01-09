// Created by Garrett Wang on 01/05/17
// quick_sort_3.cpp
// running time: O(nlogn)
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void partition3(int left, int right, int &m1, int &m2, vector<int> &a) {
  int x = a[left];
  // Any elements in between [m1, m2] are equal
  m1 = m2 = left;
  // After this loop,
  // every element on the left of m2 is smaller or equal to the pivot
  // every element on the right of m2 is greater than the pivot
  for (int i = left + 1; i <= right; i++) {
    if (a[i] <= x) {
      m2++;
      swap(a[i], a[m2]);
    }
  }
  // After this loop,
  // every element on the left of m1 is smaller than the pivot
  // every element on the right of m2 is greater than the pivot
  for (int i = left + 1; i <= right; i++) {
    if (a[i] < x) {
      m1++;
      swap(a[i], a[m1]);
    }
  }
  // swap the left(pivot) element to the left of the middle segments
  swap(a[m1], a[left]);
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
  int m1, m2;
  partition3(left, right, m1, m2, a);
  // sort left part
  randomize(left, m1 - 1, a);
  // sort right part
  randomize(m2 + 1, right, a);
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
  // quick sort 3
  // similar technique as quick sort but partition into three segements
  randomize(0, a.size() - 1, a);
  // output
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
  return 0;
}
