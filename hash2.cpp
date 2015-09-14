/*
Author: cpriest, Caleb Priester
Filename: hash2.cpp
Description: The implementation of the methods declared in hash2.h
*/

#include <iostream>
#include <assert.h>
#include "hash2.h"

using namespace std;

/* Return true if key is in the set */
bstNode* Hash2::search(long key)
{
  int hash = key%buckets;
  BST *temp = hash_table[hash];
  return temp->search(key);
}

/* Inserts a new key.  It is an error if key is already in the set. */
void Hash2::inset(long key)
{
  //assert (!search(key));
  int hash = key%buckets;
  BST *temp = hash_table[hash];
  temp->inset(key);
}

/* Removes a key.  It is an error if key isn't in the set */
void Hash2::remove(long key)
{
  //assert (search(key));
  int hash = key%buckets;
  BST *curr = hash_table[hash];
  curr->remove(key);
}

void Hash2::print(void)
{
  BST *temp;
  for(int i = 0; i < buckets; i++) {
    cout << i << "   ";
    temp = hash_table[i];
    temp->print();
  }
  
}
