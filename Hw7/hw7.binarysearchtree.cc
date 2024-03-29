#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node* left;
  Node* right;
  Node(int n) : data(n), left(nullptr), right(nullptr) {};
};

void Insert(Node*& tree, int n) {
  if (tree == nullptr) {
    tree = new Node(n);
    return;
  } else if (tree->data == n) {
    return;
  } else if (tree->data < n) {
    Insert(tree->right, n);
    return;
  } else {
    Insert(tree->left, n);
    return;
  }
}

int RemoveLargest(Node*& tree) {
  if (tree->right == nullptr) {
    int d = tree->data;
    tree = tree->left;
    return d;
  } else {
    return RemoveLargest(tree->right);
  }
}

int RemoveSmallest(Node*& tree) {
  if (tree->left == nullptr) {
    int d = tree->data;
    tree = tree->right;
    return d;
  } else {
    return RemoveSmallest(tree->left);
  }
}

void Remove(Node*& tree, int n) {
  if (tree == nullptr) {
    return;
  } else if (tree->data == n) {
    if (tree->left == nullptr) {
      cout << "left is null" << endl;
      Node* todelete = tree;
      tree = tree->right;
      delete todelete;
    } else if (tree->right == nullptr) {
      cout << "right is null" << endl;
      Node* todelete = tree;
      tree = tree->left;
      delete todelete;
    } else {
      cout << "need to remove largest" << endl;
      int i = RemoveLargest(tree->left);
      tree->data = i;
    }
    return;
  } else if (tree->data < n) {
    Remove(tree->right, n);
    return;
  } else {
    Remove(tree->left, n);
    return;
  }
}

void Print(Node* tree) {
  if (tree == nullptr) return;
  Print(tree->left);
  cout << tree->data << " ";
  Print(tree->right);
}

bool Find(Node* tree, int n) {
  if (tree == nullptr) {
    return false;
  } else if (tree->data == n) {
    return true;
  } else if (tree->data < n) {
    return Find(tree->right, n);
  } else {
    return Find(tree->left, n);
  }
}

// (a) [30 points] Given a sorted array as argument,
// return a balanced binary search tree.
Node* BalancedTreeFromArray(int arr[], int first, int last) {
  Node * root = new Node(arr[last / 2]);
  int lindex = (last / 2) - 1;
  int rindex = (last / 2) + 1;
  while (lindex >= first && rindex <= last)
  {
    Insert(root, arr[lindex]);
    Insert(root, arr[rindex]);
    lindex--;
    rindex++;
  }
  while(lindex >= first)
  {
    Insert(root, arr[lindex]);
    lindex--;
  }
  while(rindex <= last)
  {
    Insert(root, arr[rindex]);
    rindex++;
  }
  return root;
}

// (b) [10 points] Return depth of a tree. Empty tree has depth 0.
// Tree with only one node has depth 1.
int FindDepth(Node* tree) {
  if(tree == nullptr)
  {
    return 0;
  }
  else
  {
    return 1 + max(FindDepth(tree -> left), FindDepth(tree -> right));
  }
}

// (c) [20 points] Return true if tree is balanced, false otherwise.
// Tree is balanced if the number of nodes on left tree differs from the
// number of nodes on right tree by no more than 1,
// and both children are also balanced trees.
int NumNodes(Node * t)
{
  if(t == nullptr)
  {
    return 0;
  }
  else return NumNodes(t -> left) + NumNodes(t -> right) + 1;
}

// bool IsBalanced(Node* tree) {
//   int lnodes = NumNodes(tree -> left);
//   int rnodes = NumNodes(tree -> right);
//   cout << lnodes << endl;
//   cout << rnodes << endl;
//   if(abs(lnodes - rnodes) <= 1)
//   {
//     return true;
//   }
//   else return false;
// }

bool IsBalanced(Node* tree) {
  if(tree == nullptr)
  {
    return true;
  }
  int lnodes = NumNodes(tree -> left);
  int rnodes = NumNodes(tree -> right);
  if(abs(lnodes - rnodes) > 1)
  {
    return false;
  }
  else
  {
    IsBalanced(tree -> left);
    IsBalanced(tree -> right);
    return true;
  }
}

// (d) [40 points] Given a tree that is not necessarily balanced, move
// nodes, or move content of nodes, or insert or remove nodes to make the
// tree balanced. You are not allowed to use some other intermediate data
// structure. For example, you are not allowed to construct a sorted array
// and then call BalancedTreeFromArray.

Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  
    y->left = x;  
    x->right = T2;  
    return y;  
}  

Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;  
    x->right = y;  
    y->left = T2;  
    return x;  
}  

void BalanceTree(Node*& tree) {
  int ldepth = FindDepth(tree -> left);
  int rdepth = FindDepth(tree -> right);
  if(IsBalanced(tree) == true)
  {
    return;
  }
  else if(tree == nullptr)
  {
    return;
  }
  else if(tree -> left == nullptr || tree -> right == nullptr)
  {
    return;
  }
  else if(ldepth > rdepth && tree -> data < tree -> left -> data)  
  {
    rightRotate(tree);
    return;
  }
  else if(rdepth > ldepth && tree -> data > tree -> right -> data)
  {
    leftRotate(tree);
    return;
  }
  else if(ldepth > rdepth && tree -> data > tree -> left -> data)
  {
    tree -> left = leftRotate(tree -> left);
    rightRotate(tree);
    return;
  }
  else if(rdepth > ldepth && tree -> data < tree -> right -> data)
  {
    tree -> right = rightRotate(tree -> right);
    leftRotate(tree);
    return;
  }
}

// This has only two test cases. You may want to test more exhaustively.
int main() {

  int arr[] = { 2, 5, 7, 9, 10, 11, 16, 18 };
  Node* tree1 = BalancedTreeFromArray(arr, 0, 7);
  Print(tree1);
  cout << endl;
  if (IsBalanced(tree1)) {
    cout << "Tree is balanced" << endl;
  }

  Node* tree = nullptr;
  Insert(tree, 13);
  Insert(tree, 12);
  Insert(tree, 6);
  Insert(tree, 7);
  Insert(tree, 8);
  Insert(tree, 5);
  Insert(tree, 6);
  Insert(tree, 4);
  Insert(tree, 3);

  if (IsBalanced(tree)) {
    cout << "Tree is balanced." << endl;
  } else {
    cout << "Tree is not balanced." << endl;
  }

  BalanceTree(tree);

  if (IsBalanced(tree)) {
    cout << "Tree is balanced." << endl;
  } else {
    cout << "Tree is not balanced." << endl;
  }

  Print(tree);

  return 0;
}

/*

2 5 7 9 10 11 16 18
Tree is balanced
Tree is not balanced.
Tree is balanced.
3 4 5 6 7 8 12 13

*/
