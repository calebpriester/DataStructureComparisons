/*
Author: cpriest, Caleb Priester
Filename: hash1.cpp
Description: The implementation of the methods declared in hash1.h
*/

#include <iostream>
#include <assert.h>
#include "hash1.h"

using namespace std;

/* Return true if key is in the set */
hash1Node* Hash1::search(long key)
{
  int hash = key%buckets;
  hash1Node *temp = hash_table[hash];
  temp = temp->next;
  while(temp != NULL) {
    if(temp->key == key) return temp;
    temp = temp->next;
  }
  return NULL;
}

/* Inserts a new key.  It is an error if key is already in the set. */
void Hash1::inset(long key)
{
  //assert (!search(key));
  int hash = key%buckets;
  hash1Node *temp = hash_table[hash];

  while(temp->next != NULL && (temp->next)->key < key) {
     temp = temp->next;
  }
  
  if(temp->next != NULL && (temp->next)->key == key) {
     //cout << key << " is already in the table." << endl;
     return;
  }
  hash1Node *n = new hash1Node();
  n->key = key;
  n->next = temp->next;
  temp->next = n;
}

/* Removes a key.  It is an error if key isn't in the set */
void Hash1::remove(long key)
{
  //assert (search(key));
  int hash = key%buckets;
  hash1Node *curr = hash_table[hash];
  hash1Node *prev = curr;
  hash1Node *temp;
  curr = curr->next;
  while(curr != NULL && curr->key != key) {
     prev = curr;
     curr = curr->next;
  }

  if(curr == NULL) {
     //cout << key << " is not contained in the table." << endl;
     return;
  }
  temp = curr;
  curr = curr->next;
  prev->next = curr;
  delete temp;
}

void Hash1::print(void)
{
  hash1Node *temp;
  for(int i = 0; i < buckets; i++) {
    cout << i << "   ";
    temp = hash_table[i]->next;
    while(temp != NULL) {
      cout << temp->key << " ";
      temp = temp->next;
    }
    cout << endl;
  }
  cout << endl;
}
