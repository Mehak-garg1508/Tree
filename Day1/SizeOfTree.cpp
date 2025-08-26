// Creating binary tree

#include<iostream>
using namespace std;

class Node{
public:
int data;
Node *left, *right;
Node(int value){
  data = value;
  left = right = NULL;
}
};

Node *BinaryTree(){
  int x;
  cin >> x;
  if(x == -1){
    return NULL;
  }
  Node *temp = new Node(x);
  // left side
  cout << "Enter the left child of " << x<< " : ";
  temp->left = BinaryTree();
  // right side
  cout << "Enter the right child of " << x<< " : ";
  temp->right = BinaryTree();
  return temp;
}

// Method 1
void calSize(Node *root, int &count){
if(root==NULL)
return;

count++;
calSize(root->left,count);
calSize(root->right,count);
}

int sizeBT(Node *root){
int count = 0;
calSize(root,count);
return count;
}

// Method2
int size(Node *root){
  if(root==NULL)
  return 0;
  
  return 1+size(root->left)+size(root->right);
}

int main(){
  cout << "Enter the root element: ";
  Node *root = BinaryTree();
  cout << "Size of Binary Search Tree by Method 1: " << sizeBT(root) << endl;
  cout << "Size of Binary Search Tree by Method 2: " << size(root) << endl;
}