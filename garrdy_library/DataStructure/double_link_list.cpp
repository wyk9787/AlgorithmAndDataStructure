// TODO: Every function
#include <iostream>

struct node {
  int data;
  node *next;
  node *previous;
};

typedef sturct node Node;

void insert(int i, int data, Node &n) {
  Node temp;
  temp.data = data;
  while (i--) {
    n = n.next;
  }
  temp.next = n.next;
  temp.previous = n;
  n.next = temp;
}

void delete (int i, Node &n) {
  while (i--) {
    n = n.next;
  }
  n.next = n.next.next;
}

int main(int argc, char const *argv[]) {
  Node n;
  return 0;
}
