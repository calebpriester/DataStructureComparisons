/*
Author: cpriest, Caleb Priester
Filename: bst.h
Description: The class declaration of a BST Tree and bstNodes.  This is 
   similar to avl.h, but with all balancing functionality removed.
*/
#ifndef BST_H
#define BST_H

class bstNode {
  long key;
  bstNode *left;
  bstNode *right;
  bstNode *parent;
  int leftHeight;
  int rightHeight;

  public:
  bstNode () : key(0), left(NULL), right(NULL), parent(NULL), leftHeight(0), rightHeight(0) {}
  bstNode (long k) : key(k), left(NULL), right(NULL), parent(NULL), leftHeight(0), rightHeight(0) {}
  bstNode (long k, bstNode *l, bstNode *r) : key(k), left(l), right(r), parent(NULL), leftHeight(0), rightHeight(0) {}
  bstNode (long k, bstNode *l, bstNode *r, bstNode *p) : key(k), left(l), right(r), parent(p), leftHeight(0), rightHeight(0) {}

  friend class BST;
};

class BST {
  bstNode* root;
  bool inset (bstNode* x, long key);
  bstNode* search (bstNode* x, long key);
  bool remove (bstNode* x, long key);
  bool checkForUpdates(bstNode* x, long key);
  bstNode* findSuccessor (bstNode* x);
  /*bstNode* rotateWithLeftChild(bstNode* x);
  bstNode* rotateWithRightChild(bstNode* x);
  bstNode* doubleWithLeftChild(bstNode* x);
  bstNode* doubleWithRightChild(bstNode* x);*/
  void inOrder (bstNode* x);
  /*bstNode* balance (bstNode* x);*/

  public:
  BST () : root(NULL) {}
  void inset (long key);
  bstNode* search (long key);
  void remove (long key);
  void print();
  bstNode* getRoot();
};

#endif
