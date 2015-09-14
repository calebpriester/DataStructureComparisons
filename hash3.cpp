/*
Author: cpriest, Caleb Priester
Filename: hash3.cpp
Description: The implementation of the methods declared in hash3.h
*/

#include <iostream>
#include <assert.h>
#include "hash3.h"

using namespace std;

/* Return true if key is in the set */
hash3Node* Hash3::search(long key)
{
  int hash1 = key%buckets1;
  int hash2 = key%buckets2;
  hash3Node *temp = hash_table[hash1][hash2];
  temp = temp->next;
  while(temp != NULL) {
    if(temp->key == key) return temp;
    temp = temp->next;
  }
  return NULL;
}

/* Inserts a new key.  It is an error if key is already in the set. */
void Hash3::inset(long key)
{
  //assert (!search(key));
  int hash1 = key%buckets1;
  int hash2 = key%buckets2;
  hash3Node *temp = hash_table[hash1][hash2];

  while(temp->next != NULL && (temp->next)->key < key) {
    temp = temp->next;
  }

  if(temp->next != NULL && (temp->next)->key == key) {
     //cout << key << " is already in the table." << endl;
     return;
  }
  hash3Node *n = new hash3Node();
  n->key = key;
  n->next = temp->next;
  temp->next = n;
}

/* Removes a key.  It is an error if key isn't in the set */
void Hash3::remove(long key)
{
  //assert (search(key));
  int hash1 = key%buckets1;
  int hash2 = key%buckets2;
  hash3Node *curr = hash_table[hash1][hash2];
  hash3Node *prev = curr;
  hash3Node *temp;
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

void Hash3::print(void)
{
  hash3Node *temp;
  for(int i = 0; i < buckets1; i++) {
    cout << i << "   ";
    for(int j = 0; j < buckets2; j++) {
      cout << j << "   ";
      temp = hash_table[i][j]->next;
      while(temp != NULL) {
        cout << temp->key << " ";
        temp = temp->next;
      }
      cout << endl;
    }
    cout << endl;
  }
  cout << endl;
}
