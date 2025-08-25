// Traversing binary tree

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

void preOrder(Node *root){
  if(root==NULL)
  return;
// Node
  cout << root->data<<" ";
  // left
  preOrder(root->left);
  // right
  preOrder(root->right);
}

void inOrder(Node *root){
  if(root==NULL)
  return;
  
  // left
  inOrder(root->left);
  // Node
  cout << root->data<< " ";
  // right
  inOrder(root->right);
}

void postOrder(Node *root){
  if(root==NULL)
  return;
  // left
  postOrder(root->left);
  // right
  postOrder(root->right);
  // Node
  cout << root->data << " ";
}

int main(){
  cout << "Enter the root element: ";
  // Tree Creation
  Node *root = BinaryTree();
  // PreOrder Print
  cout << "Pre Order: " << endl;
  preOrder(root);
  cout << endl;
  // Inorder Print
  cout << "In Order: " << endl;
  inOrder(root);
  cout << endl;
  // Postorder Print
  cout << "Post Order: " << endl;
  postOrder(root);
  cout << endl;
}