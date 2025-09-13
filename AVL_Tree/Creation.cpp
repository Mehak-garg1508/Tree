#include <iostream>
using namespace std;

class Node{
public:
int data, height;
Node *left, *right;
Node(int val){
  data = val;
  height = 1;
  left = right = NULL;
}
};

int getHeight(Node *root){
  if(!root)
  return 0;
  
  return root->height;
}

Node *rightRotate(Node *root){
  Node *child = root->left;
  Node *childRight = child->right;
  child->right = root;
  root->left = childRight;
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  child->height = 1 + max(getHeight(child->left), getHeight(child->right));
  return child;
}

Node *leftRotate(Node *root){
  Node *child = root->right;
  Node *childLeft = child->left;
  child->left = root;
  root->right = childLeft;
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  child->height = 1 + max(getHeight(child->left), getHeight(child->right));
  return child;
}

Node *insert(Node *root, int key){
  // Doesn't Exist
  if(!root)
  return new Node(key);
  // Does Exist
  //1. Kaha dalna hai
  if(root->data > key)
  root->left = insert(root->left,key);
  else if(root->data < key)
  root->right = insert(root->right, key);
  else
  return root;  //Duplicates not allowed
  //2. Height check karna
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  //3. Balance check karna
  int balance = getHeight(root->left) - getHeight(root->right);
  //4. Which rotation to perform
  // For Left Left Rotation
  if(balance > 1 && root->left->data > key)
  return rightRotate(root);
  // For Right Right Rotation
  else if(balance < -1 && root->right->data < key)
  return leftRotate(root);
  // For Left Right Rotation
  else if(balance > 1 && root->left->data < key){
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  // right left
  else if(balance < -1 && root->right->data > key){
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  else
  return root;
}

void inorder(Node *root){
  if(!root)
  return;
  
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

int main(){
 Node *root = NULL;
 root = insert(root, 20);
 root = insert(root, 25);
 root = insert(root, 15);
 root = insert(root, 5);
 root = insert(root, 10);
 root = insert(root, 30);
 root = insert(root, 35);
 root = insert(root, 8);
 root = insert(root, 29);

 inorder(root);
}