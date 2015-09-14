#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "bst.h"

#include <cstdio>
#include <time.h>
#include <cstdlib>

#define SIZE 10000
#define START1 100
#define START2 1000
#define END 10000
#define STEP1 100
#define STEP2 1000

int main() {
  int key;
  BST s;
  timespec ts;
  int values[SIZE];
  int temp;
  int rand1;
  int rand2;
  unsigned long long nano;
  unsigned long long milli;

  for (int i = 0; i < SIZE; i++) values[i] = i;

  for(int i = 0; i < 50000; i++) {
    rand1 = rand() % 10000;
    rand2 = rand() % 10000;
    temp = values[rand1];
    values[rand1] = values[rand2];
    values[rand2] = temp;
  }	

  cout << "Inserting " << SIZE << " elements" << endl;
  for (int i = 0; i < SIZE; ++i) s.inset(values[i]);		// Insert about 100000 keys.

  for (int i = START2; i <= END; ) {
    ts.tv_sec = 0;
    ts.tv_nsec = 0;
    clock_settime(CLOCK_PROCESS_CPUTIME_ID, &ts);

    for (int j = 0; j < i; ++j) {			// Find a random key for i times.
      s.search(rand() % SIZE);
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
    nano = (unsigned long long) (ts.tv_sec * 1000000000) + (unsigned long long) ts.tv_nsec;
    milli = nano / 1000000;

    cout << i << " find operations " << milli  << " milli seconds" << endl;

    i += 1000 ;
  }
  return 0;
}
