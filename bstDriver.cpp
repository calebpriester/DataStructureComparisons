#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <cstdio>
#include <time.h>
#include <cstdlib>

using namespace std;

#include "bst.h"

#define SIZE	50000

int main() {
  BST s;
  int vals[SIZE];
  int temp;
  int rand1;
  int rand2;
  long key;

  srand(time(NULL));

  for(int i = 0; i < SIZE; i++) vals[i] = i;
  
  for(int i = 0; i < 100000; i++) {
    rand1 = rand()%SIZE;
    rand2 = rand()%SIZE;

    temp = vals[rand1];
    vals[rand1] = vals[rand2];
    vals[rand2] = temp;
  }

  for(int i = 0; i < SIZE; i++) s.inset(vals[i]);
  //s.print();
  //cout << endl;
for(int i = 0; i < 100000; i++) {
    rand1 = rand()%SIZE;
    rand2 = rand()%SIZE;

    temp = vals[rand1];
    vals[rand1] = vals[rand2];
    vals[rand2] = temp;
  }

  for(int i = 5; i < SIZE; i++) {
    //cout << "REMOVING " << vals[i] << endl;
    s.remove(vals[i]);
    //s.print();
    //cout << endl;
  }
  s.print();
}
