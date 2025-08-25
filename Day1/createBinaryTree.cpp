// Creating Binary Tree
#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
int data;
Node *left,*right;
Node(int value){
  data = value;
  left = right = NULL;
}
};

int main(){
  int x;
  int first, second;
  cout << "Enter the root element value: ";
  cin >> x;
  queue<Node*>q;
  Node *root = new Node(x);
  q.push(root);
  // Building Binary Tree
  while(!q.empty()){
    Node *temp = q.front();
    q.pop();
    // left node ki value
    cout << "Enter the left child of " << temp->data << " : ";
    cin >> first;
    if(first != -1){
      temp->left = new Node(first);
      q.push(temp->left);
    }
    // right node ki value
    cout << "Enter the right child of " << temp->data << " : ";
    cin >> second;
    if(second != -1){
      temp->right = new Node(second);
      q.push(temp->right);
    }
  }
}

//                 1
//         2                3
//     4       5        6        7
//                           8      