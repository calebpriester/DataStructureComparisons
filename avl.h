/*
Author: cpriest, Caleb Priester
Filename: avl.h
Description: The class declaration of a AVL Tree and avlNodes.
*/

class avlNode {
  long key;
  avlNode *left;
  avlNode *right;
  avlNode *parent;
  int leftHeight;
  int rightHeight;

  public:
  avlNode () : key(0), left(NULL), right(NULL), parent(NULL), leftHeight(0), rightHeight(0) {}
  avlNode (long k) : key(k), left(NULL), right(NULL), parent(NULL), leftHeight(0), rightHeight(0) {}
  avlNode (long k, avlNode *l, avlNode *r) : key(k), left(l), right(r), parent(NULL), leftHeight(0), rightHeight(0) {}
  avlNode (long k, avlNode *l, avlNode *r, avlNode *p) : key(k), left(l), right(r), parent(p), leftHeight(0), rightHeight(0) {}

  friend class AVL;
};

class AVL {
  avlNode* root;
  bool inset (avlNode* x, long key);
  avlNode* search (avlNode* x, long key);
  bool remove (avlNode* x, long key);
  bool checkForUpdates(avlNode* x, long key);
  avlNode* findSuccessor (avlNode* x);
  avlNode* rotateWithLeftChild(avlNode* x);
  avlNode* rotateWithRightChild(avlNode* x);
  avlNode* doubleWithLeftChild(avlNode* x);
  avlNode* doubleWithRightChild(avlNode* x);
  void inOrder (avlNode* x);
  avlNode* balance (avlNode* x);

  public:
  AVL () : root(NULL) {}
  void inset (long key);
  avlNode* search (long key);
  void remove (long key);
  void print();
  avlNode* getRoot();
};
