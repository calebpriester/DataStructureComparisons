/*
Author: cpriest, Caleb Priester
Filename: hash2.h
Description: The class declaration of a Hash Table with Binary Search Trees.
*/

#include "bst.h"

class Hash2 {

  private: 
  BST** hash_table;
  int buckets;

  public:
  Hash2(int b) {
     buckets = b;
     hash_table = new BST* [buckets];
     for(int i = 0; i < buckets; i++) hash_table[i] = new BST();
  }
  bstNode* search(long key);
  void inset(long key);
  void remove(long key);
  void print(void);
};
