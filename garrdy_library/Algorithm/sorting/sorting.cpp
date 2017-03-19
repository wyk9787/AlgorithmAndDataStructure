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

void insertion_sort(vector<int> &a) {
  for (int i = 0; i < a.size(); i++)
    for (int j = i; j > 0; j--) {
        if(a[j - 1] > a[j]) {
            swap(a[j-1] ,a[j]);
        }
    }
}

void bubble_sort(vector<int> &a) {
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < a.size() - 1; j++) {
      if (a[j + 1] < a[j])
        swap(a[j + 1], a[j]);
    }
}

void merge(int left, int mid, int right, vector<int> &a) {
    vector<int> temp;
    int l = left;
    int r = mid + 1;
    while(l <= mid && r <= right) {
        if(a[l] < a[r]) {
            temp.push_back(a[l++]);
        } else {
            temp.push_back(a[r++]);
        }
    }
    while(l <= mid) {
        temp.push_back(a[l++]);
    }
    while(r <= right) {
        temp.push_back(a[r++]);
    }
    int j = 0;
    for(int i = left; i <= right; i++) {
        a[i] = temp[j++];
    }
}

void merge_sort_helper(int left, int right, vector<int> &a) {
    // base case
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    merge_sort_helper(left , mid, a);
    merge_sort_helper(mid + 1, right, a);
    merge(left, mid, right, a);
}

void merge_sort(vector<int> &a) {
    merge_sort_helper(0, a.size() - 1, a);
}

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

void quick_sort(vector<int> &a) {
    randomize(0, a.size() - 1, a);
}

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

void randomize3(int left, int right, vector<int> &a) {
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
  randomize3(left, m1 - 1, a);
  // sort right part
  randomize3(m2 + 1, right, a);
}

void quick_sort_3(vector<int> &a) {
    randomize3(0, a.size() - 1, a);
}

int main(int argc, char const *argv[]) {
  vector<int> a1 = {1, 8, 9, 10, 2, 3, 6, 5, 7, 4};
  vector<int> a2 = {11, 38, 39, 20, -2, -32, 16, 35, -7, 400};
  vector<int> a3 = {9, 8, 8, 10, 9, 12, 4, 12, 4, 8, 100, 9, 11 ,100};

  // insertion_sort(a1);
  // selection_sort(a2);
  // bubble_sort(a3);
  merge_sort(a1);
  quick_sort(a2);
  quick_sort_3(a3);

  cout << "a1: ";
  for (int i = 0; i < a1.size(); i++) {
    cout << a1[i] << ' ';
  }
  cout << endl;

  cout << "a2: ";
  for (int i = 0; i < a2.size(); i++) {
    cout << a2[i] << ' ';
  }
  cout << endl;

  cout << "a3: ";
  for (int i = 0; i < a3.size(); i++) {
    cout << a3[i] << ' ';
  }
  cout << endl;
  return 0;
}
