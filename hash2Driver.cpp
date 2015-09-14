#include <iostream>
#include <stdlib.h>
#include <cassert>

using namespace std;

#include "hash2.h"

#define SIZE	1010

int main() {
  Hash2 s(7);
  long key;

  while(cin >> key) {
    s.inset(key);
  }
  //s.remove(8648678239);
  s.print();
}
