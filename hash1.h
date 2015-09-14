/*
Author: cpriest, Caleb Priester
Filename: hash1.h
Description: The class declaration of a Hash Table with Sorted Lists and 
   the nodes used by the Hash Table.
*/

class hash1Node {

  friend class Hash1;

  private:
  long key;
  hash1Node *next;

  public:
  hash1Node() : key(0) { next = NULL; }
  hash1Node(long k, hash1Node *n) : key(k), next(n) {}
};

class Hash1 {

  private: 
  hash1Node** hash_table;
  int buckets;

  public:
  Hash1(int b) {
     buckets = b;
     hash_table = new hash1Node* [buckets];
     for(int i = 0; i < buckets; i++) hash_table[i] = new hash1Node(0, 0);
  }
  hash1Node* search(long key);
  void inset(long key);
  void remove(long key);
  void print(void);
};
