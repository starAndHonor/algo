#include <bits/stdc++.h>
using namespace std;
int n;
string s;
struct node {
  char date;
  node *leftChild = nullptr;
  node *rightChild = nullptr;
};
typedef node *Btree;
char getVal(string s) {
  int num1 = count(s.begin(), s.end(), '0');
  if (num1 == s.size())
    return 'B';
  else if (num1 == 0)
    return 'I';
  else
    return 'F';
}
void build(Btree &tree, string s) {
  tree = new node;
  tree->date = getVal(s);
  if (s.size() == 1) {
    return;
  }
  build(tree->leftChild, s.substr(0, (s.size() / 2)));
  build(tree->rightChild, s.substr((s.size()) / 2, (s.size() / 2)));
}
void print(Btree tree) {
  if (tree != nullptr) {
    print(tree->leftChild);
    print(tree->rightChild);
    cout << tree->date;
  }
}
int main() {
  cin >> n >> s;
  Btree tree;
  build(tree, s);
  print(tree);
  return 0;
}