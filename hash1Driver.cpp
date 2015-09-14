#include <iostream>
#include <stdlib.h>
#include <cassert>

using namespace std;

#include "hash1.h"

#define SIZE	1010

int main() {
  Hash1 s(13);
  long key;

  while(cin >> key) {
    s.inset(key);
  }
  //s.remove(8648278936);
  s.print();
}
