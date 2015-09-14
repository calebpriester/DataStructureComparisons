#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <cstdio>
#include <time.h>
#include <cstdlib>

using namespace std;

#include "avl.h"

#define SIZE	25

int main() {
  AVL s;
  int vals[SIZE];
  int temp;
  int rand1;
  int rand2;
  long key;

  s.inset(10);
  s.inset(3);
  s.inset(15);
  s.inset(1);
  s.inset(5);
  s.inset(12);
  s.inset(20);
  s.inset(0);
  s.inset(4);
  s.inset(6);
  s.inset(13);
  s.inset(16);
  s.inset(23);
  s.inset(7);
  s.print();
cout << "REMOVING 3!" << endl;
  s.remove(3);
  s.print();
  cout << endl;
cout << "REMOVING 6!" << endl;
  s.remove(6);
  s.print();
cout << "REMOVING 4!" << endl;
  s.remove(4);
  s.print();
cout << "REMOVING 13!" << endl;
  s.remove(13);
  s.print();
  cout << endl;
cout << "REMOVING 5!" << endl;
  s.remove(5);
  s.print();
  cout << endl;
cout << "REMOVING 1!" << endl;
  s.remove(1);
  s.print();
  cout << endl;
cout << "REMOVING 12!" << endl;
  s.remove(12);
  s.print();
  cout << endl;
cout << "REMOVING 10!" << endl;
  s.remove(10);
  s.print();
  cout << endl;
cout << "REMOVING 16!" << endl;
  s.remove(16);
  s.print();
  cout << endl;
cout << "REMOVING 0!" << endl;
  s.remove(0);
  s.print();
  cout << endl;
cout << "REMOVING 23!" << endl;
  s.remove(23);
  s.print();
  cout << endl;
cout << "REMOVING 7!" << endl;
  s.remove(7);
  s.print();
  cout << endl;
cout << "REMOVING 20!" << endl;
  s.remove(20);
  s.print();
  cout << endl;
cout << "REMOVING 15!" << endl;
  s.remove(15);
  s.print();
  cout << endl;
  s.print();
}
