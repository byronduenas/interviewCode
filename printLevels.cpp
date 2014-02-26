// Print every level of a binary tree on a new line
#include <iostream>
#include <map>
#include <queue>


using namespace std;

typedef struct Node{
  Node* left;
  Node* right;
  char val;
} Node;

void printLevels(Node* n) {
  queue<Node*> q, qTemp;
  q.push(n);
  while(n && (q.size() || qTemp.size())) {
    while(q.size() > 0) {
      n = q.front();
      cout << n-> val;
      q.pop();
      if(n->left)
        qTemp.push(n->left);
      if(n->right)
        qTemp.push(n->right);
    }
    cout << endl;
    swap(qTemp, q);
  }

}

Node* generateTree(int n) {
  Node* node = new Node;
  node->val = 'a' + n%26;
  if(n > 0)
    node->left = generateTree(n-1);
  else {
    node->left = NULL;
    node->right = NULL;
  }
  if(n > 0)
    node->right = generateTree(n-1);
  else {
    node->right = NULL;
  }
  n--;
  return node;
}

int main ()
{
  Node* a = generateTree(4);
  printLevels(a);

  return 0;
}
