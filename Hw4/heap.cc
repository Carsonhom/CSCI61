 
#include <iostream>
#include "heap.h"

using namespace std;

Heap::Heap() {
  size = 0;
}

void Heap::Push(int n) {
  if (size >= MAX_SIZE) return;
  data[size] = n;
  // Sift up.
  int child = size;
  int parent = get_parent_index(child);
  // While not at top of heap and parent smaller than child, sift up.
  while ((child > 0) && (data[child] > data[parent])) {
    swap(parent, child);
    child = parent;
    parent = get_parent_index(child);
  }
  size++;
}

int Heap::Pop() {
  if (size == 0) return 0;
  int top = data[0];
  swap(0, size - 1);
  size--;
  sift_down(0);
  return top;
}

void Heap::Print() {
  for (int i = 0; i < size; i++) {
    cout << data[i] << " ";
  }
  cout << endl;
}

void Heap::PrintTree() 
{
  int index = 0;
  int nitems = 1;
  for(int i = 0; i < 4; ++i)
  {
    int spaces = 32 / (nitems + 1);
    int pos = 0;
    for(int j = 1; j <= 32; ++j)
    {
      if(pos < spaces)
      {
        cout << " ";
        pos++;
      }
      else 
      {
        cout << data[index];
        index++;
        pos = 0;
      }
    }
    cout << endl;
    nitems *= 2;
  }
}

int Heap::Find(int n)
{
  for(int i = 0; i < size; ++i)
  {
    if(data[i] == n)
    {
      return i;
    }
  }
  return -1;
}

void Heap::InsertIfNotFound(int n)
{
  if(Find(n) == -1)
  {
    Push(n);
  }
}

int Heap::get_parent_index(int i) {
  return (i - 1) / 2;
}

int Heap::get_left_child_index(int i) {
  return 2 * i + 1;
}

int Heap::get_right_child_index(int i) {
  return 2 * i + 2;
}

void Heap::swap(int i, int j) {
  int temp = data[i];
  data[i] = data[j];
  data[j] = temp;
}

void Heap::sift_down(int i) {
  cout << "sift down: " << i << endl;
  int parent = i;
  while (parent < size) {
    cout << "sift down parent: " << parent << endl;
    int left_child = get_left_child_index(parent);
    int right_child = get_right_child_index(parent);
    int left_child_val = 0;
    if (left_child < size) left_child_val = data[left_child];
    int right_child_val = 0;
    if (right_child < size) right_child_val = data[right_child];
    if ((left_child_val <= data[parent]) &&
        (right_child_val <= data[parent])) {
      break;
    }
    if (left_child_val > right_child_val) {
      swap(left_child, parent);
      parent = left_child;
    } else {
      swap(right_child, parent);
      parent = right_child;
    }
  }
  Print();
}
