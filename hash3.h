/*
Author: cpriest, Caleb Priester
Filename: hash3.h
Description: The class declaration of a Two-Level Hash Table with Sorted 
   Lists and the nodes used by the Hash Table.
*/

class hash3Node {

  friend class Hash3;

  private:
  long key;
  hash3Node *next;

  public:
  hash3Node() : key(0) { next = NULL; }
  hash3Node(long k, hash3Node *n) : key(k), next(n) {}
};

class Hash3 {
  private:
  int buckets1;
  int buckets2;
  hash3Node ***hash_table;

  public:
  Hash3 (int b1, int b2) {
    buckets1 = b1;
    buckets2 = b2;

    hash_table = new hash3Node**[buckets1];
    for (int i = 0; i < buckets1; ++i) {
      hash_table[i] = new hash3Node*[buckets2];
      for(int j = 0; j < buckets2; ++j) {
        hash_table[i][j] = new hash3Node(0, 0);		// Dummy hash3Nodes
      }
    }
  }
  hash3Node* search(long key);
  void inset(long key);
  void remove(long key);
  void print(void);
};
