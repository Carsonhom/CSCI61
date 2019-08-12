#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
  string data;
  Node* left;
  Node* right;
  Node(string d) : data(d), left(nullptr), right(nullptr) { };
};

Node* ParsePrefix(const vector<string>& expr, int& ind)
{
  if(ind >= expr.size())
  {
    return nullptr;
  }
  else if(expr[ind].at(0) - '0' < 0 || expr[ind].at(0) - '0' > 9)
  {
    Node * newnode = new Node(expr[ind]);
    ind++;
    newnode -> left = ParsePrefix(expr, ind);
    newnode -> right = ParsePrefix(expr, ind);
    return newnode;
  }
  else if(expr[ind].at(0) - '0' >= 0 && expr[ind].at(0) - '0' < 9)
  {
    Node * op = new Node(expr[ind]);
    ind++;
    return op;
  }
}

void PrintPrefix(Node* t)
{
  if(t == nullptr) return;
  cout << t -> data << " ";
  PrintPrefix(t -> left);
  PrintPrefix(t -> right);
}

void PrintPostfix(Node* t)
{
  if(t == nullptr) return;
  PrintPostfix(t -> left);
  PrintPostfix(t -> right);
  cout << t -> data << " ";
}

void PrintInfix(Node* t)
{
  if(t == nullptr) return;
  if(t -> left == nullptr && t -> right == nullptr)
  {
    cout << t -> data << " ";
    return;
  }
   else if((t -> left -> data)[0] - '0' >= 0 && (t -> left -> data)[0] - '0' < 9 && (t -> right -> data)[0] - '0' >= 0 && (t -> right -> data)[0] - '0' < 9)
  {
    cout << "( ";
    PrintInfix(t -> left);
    cout << t -> data << " ";
    PrintInfix(t -> right);
    cout << ") ";
    return;
  }
  else if(((t -> left -> data)[0] - '0' >= 0 && (t -> left -> data)[0] - '0' < 9) || ((t -> right -> data)[0] - '0' >= 0 && (t -> right -> data)[0] - '0' < 9))
  {
    cout << "( ";
    PrintInfix(t -> left);
    cout << t -> data << " ";
    PrintInfix(t -> right);
    cout << ") ";
    return;
  }

  PrintInfix(t -> left);
  cout << t -> data << " ";
  PrintInfix(t -> right);
  
}

int main() {
  vector<string> expr = { "+", "-", "3", "2", "/", "*", "5", "7", "8" };
  int index = 0;
  Node* t = ParsePrefix(expr, index);
  PrintPrefix(t);
  cout << endl;
  PrintPostfix(t);
  cout << endl;
  PrintInfix(t);
  cout << endl;
  return 0;
}

/*
+ - 3 2 / * 5 7 8
3 2 - 5 7 * 8 / +
( ( 3 - 2 ) + ( ( 5 * 7 ) / 8 ) )
 */
