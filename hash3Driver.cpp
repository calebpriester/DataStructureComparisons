#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <cstdio>
#include <time.h>
#include <cstdlib>

using namespace std;

#include "hash3.h"

#define SIZE	10000

int main() {
  Hash3 s(499, 267);
  int vals[SIZE];
  int temp;
  int rand1;
  int rand2;
  long key;

  srand(time(NULL));

  for(int i = 0; i < SIZE; i++) vals[i] = i;
  
  for(int i = 0; i < 10000; i++) {
    rand1 = rand()%SIZE;
    rand2 = rand()%SIZE;

    temp = vals[rand1];
    vals[rand1] = vals[rand2];
    vals[rand2] = temp;
  }

  for(int i = 0; i < SIZE; i++) s.inset(vals[i]);
  //s.print();
  cout << endl;
for(int i = 0; i < 10000; i++) {
    rand1 = rand()%SIZE;
    rand2 = rand()%SIZE;

    temp = vals[rand1];
    vals[rand1] = vals[rand2];
    vals[rand2] = temp;
  }

  for(int i = 0; i < SIZE; i++) {
    //cout << "REMOVING " << vals[i] << endl;
    s.remove(vals[i]);
    //s.print();
    //cout << endl;
  }
  //s.print();
}
