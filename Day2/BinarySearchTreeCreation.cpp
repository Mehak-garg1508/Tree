// Creating Binary Search Tree

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

Node *insert(Node *root, int target){
  if(!root){
    Node *temp = new Node(target);
    return temp;
  }
  if(target<root->data){
    root->left = insert(root->left,target);
  }
  else{
    root->right = insert(root->right,target);
  }
  return root;
}

void inorder(Node *root){
  if(!root)
  return;
  
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

bool search(Node *root, int target){
  if(!root)
  return 0;
  if(root->data==target)
  return 1;
  if(root->data>target)
  return search(root->left, target);
  else
  return search(root->right, target);
}

int main(){
  int arr[10] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};
  int n = 10;
  Node *root = NULL;
  for(int i = 0; i < n; i++){
    root = insert(root,arr[i]);
  }

  // Traverse
  cout << "Inorder traversal of binary search tree:  " << endl;
  inorder(root);
  cout << endl;

  // Search
  int x;
  cout << "Enter the element you want to search in tree: " << endl;
  cin >> x;
  if(search(root,x)){
    cout << "Element is found" << endl;
  }
  else{
    cout << "Element not found" << endl;
  }
  return 0; 
}