// Created by Garrett Wang on 01/01/17
// priority_queue.cpp
// push = insert, top = get_min, pop = extract_min()
// size = get_size, empty = empty

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Priority_Queue {
private:
  vector<int> data;
  int size;

  int parent(int i) { return floor((i - 1) / 2); }

  int left_child(int i) { return 2 * i + 1; }

  int right_child(int i) { return 2 * i + 2; }

  void sift_down(int i) {
    int max_index = i;
    int l = left_child(i);
    if (l < size && data[l] < data[max_index])
      max_index = l;
    int r = right_child(i);
    if (r < size && data[r] < data[max_index])
      max_index = r;
    if (i != max_index) {
      swap(data[i], data[max_index]);
      sift_down(max_index);
    }
  }

  void sift_up(int i) {
    while (i > 0 && data[parent(i)] > data[i]) {
      swap(data[parent(i)], data[i]);
      i = parent(i);
    }
  }

public:
  Priority_Queue() {
    size = 0;
    //        for (int i = floor(size / 2); i >= 0; i--) {
    //            sift_down(i);
    //        }
  }
  int get_size() { return size; }
  void get_element(int p) { data.push_back(p); }
  bool empty() {
    if (size > 0)
      return false;
    else
      return true;
  }
  int get_min() { return data[0]; }

  void insert(int p) {
    size++;
    if (data.size() < size)
      data.push_back(p);
    else
      data[size - 1] = p;
    sift_up(size - 1);
  }

  int extract_min() {
    int result = data[0];
    data[0] = data[size - 1];
    size--;
    sift_down(0);
    return result;
  }

  void change_priority(int i, int p) {
    int old_p = data[i];
    data[i] = p;
    if (p < old_p)
      sift_up(i);
    else
      sift_down(i);
  }

  void remove(int i) {
    data[i] = INT_MIN;
    sift_up(i);
    extract_min();
  }
};

int main(int argc, char const *argv[]) {
  // n is how many elements are there in the list
  int n;
  cin >> n;
  Priority_Queue heap;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    heap.insert(temp);
  }

  // test
  heap.change_priority(4, 10);
  heap.remove(2);
  heap.insert(19);
  cout << "size: " << heap.get_size() << endl;
  int size = heap.get_size();
  for (int i = 0; i < size; i++) {
    cout << heap.extract_min() << ' ';
  }
  cout << endl;

  return 0;
}
