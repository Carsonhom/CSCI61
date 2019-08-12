#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include "heap.h"

int main()
{
Heap max = Heap();
std::cout << "Hello World" << std::endl;
max.Push(3);
max.Push(5);
max.Push(12);
max.Push(1);
max.Push(22);
max.PrintTree();
std::cout << max.Find(12) << std::endl;
max.InsertIfNotFound(4);
max.PrintTree();
return 0;
}