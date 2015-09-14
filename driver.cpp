/*
Author: cpriest, Caleb Priester
Filename: driver.cpp
Description: This driver asks the user which dictionary that they want to
use, then asks the user to choose from three methods (search, delete, and 
inset). After this, the driver asks the user for the name of the file 
containing the data that the method will be used with.  It repeats this 
process until told to stop.
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cassert>

using namespace std;

#include "bst.h"
#include "avl.h"
#include "hash1.h"
#include "hash2.h"
#include "hash3.h"

#define SIZE	1010

int main() {
  long key;
  int selection;
  int buckets;
  int buckets2;
  int option = -1;
  string fileName;
  ifstream myFile;

  cout << "Choose a dictionary:" << endl;
  cout << "1: Binary Search Tree" << endl;
  cout << "2: AVL Tree" << endl;
  cout << "3: Hash Table with Sorted Lists" << endl;
  cout << "4: Hash Table with Binary Search Trees" << endl;
  cout << "5: Two-Level Hash Table with Sorted Lists" << endl;
  cin >> selection;

  if(selection == 1) {
     cout << endl << "You've selected Binary Search Tree." << endl;
     BST dictionary;
     while(option != 0) {
        cout << "Choose an Option:" << endl;
        cout << "1: Search" << endl;
        cout << "2: Delete" << endl;
        cout << "3: Inset" << endl;
        cout << "0: Exit Program" << endl;
	cin >> option;
        if(option != 0) {
	   cout << "Enter File Name:" << endl;
	   cin >> fileName;
	   myFile.open(fileName.c_str());
	   if(option == 1) {
	      while(myFile >> key) {
	         if(dictionary.search(key)) 
		    cout << key << " TRUE" << endl;
		 else
		    cout << key << " FALSE" << endl;
              }
	   }
	   else if(option == 2) {
	      while(myFile >> key) dictionary.remove(key);
	   }
	   else if(option == 3) {
	      while(myFile >> key) dictionary.inset(key);
	   }
	   myFile.close();
	}
     }
  }
  else if(selection == 2) {
     cout << endl << "You've selected AVL Tree." << endl;
     AVL dictionary;
     while(option != 0) {
        cout << "Choose an Option:" << endl;
        cout << "1: Search" << endl;
        cout << "2: Delete" << endl;
        cout << "3: Inset" << endl;
        cout << "0: Exit Program" << endl;
	cin >> option;
        if(option != 0) {
	   cout << "Enter File Name:" << endl;
	   cin >> fileName;
	   myFile.open(fileName.c_str());
	   if(option == 1) {
	      while(myFile >> key) {
	         if(dictionary.search(key)) 
		    cout << key << " TRUE" << endl;
		 else
		    cout << key << " FALSE" << endl;
              }
	   }
	   else if(option == 2) {
	      while(myFile >> key) dictionary.remove(key);
	   }
	   else if(option == 3) {
	      while(myFile >> key) dictionary.inset(key);
	   }
	   myFile.close();
	}
     }
  }
  else if(selection == 3) {
     cout << endl << "You've selected Hash Table with Sorted Lists" << endl;
     cout << "Enter Number of Buckets:" << endl;
     cin >> buckets;
     cout << endl;
     Hash1 dictionary(buckets);
     while(option != 0) {
        cout << "Choose an Option:" << endl;
        cout << "1: Search" << endl;
        cout << "2: Delete" << endl;
        cout << "3: Inset" << endl;
        cout << "0: Exit Program" << endl;
	cin >> option;
        if(option != 0) {
	   cout << "Enter File Name:" << endl;
	   cin >> fileName;
	   myFile.open(fileName.c_str());
	   if(option == 1) {
	      while(myFile >> key) {
	         if(dictionary.search(key)) 
		    cout << key << " TRUE" << endl;
		 else
		    cout << key << " FALSE" << endl;
              }
	   }
	   else if(option == 2) {
	      while(myFile >> key) dictionary.remove(key);
	   }
	   else if(option == 3) {
	      while(myFile >> key) dictionary.inset(key);
	   }
	   myFile.close();
	}
     }
  }
  else if(selection == 4) {
     cout << endl << "You've selected Hash Table with Binary Search Trees." << endl;
     cout << "Enter Number of Buckets:" << endl;
     cin >> buckets;
     cout << endl;
     Hash2 dictionary(buckets);
     while(option != 0) {
        cout << "Choose an Option:" << endl;
        cout << "1: Search" << endl;
        cout << "2: Delete" << endl;
        cout << "3: Inset" << endl;
        cout << "0: Exit Program" << endl;
	cin >> option;
        if(option != 0) {
	   cout << "Enter File Name:" << endl;
	   cin >> fileName;
	   myFile.open(fileName.c_str());
	   if(option == 1) {
	      while(myFile >> key) {
	         if(dictionary.search(key)) 
		    cout << key << " TRUE" << endl;
		 else
		    cout << key << " FALSE" << endl;
              }
	   }
	   else if(option == 2) {
	      while(myFile >> key) dictionary.remove(key);
	   }
	   else if(option == 3) {
	      while(myFile >> key) dictionary.inset(key);
	   }
	   myFile.close();
	}
     }
  }
  else if(selection == 5) {
     cout << endl << "You've selected Two-Level Hash Table with Sorted Lists." << endl;
     cout << "Enter Number of Buckets for First Hash:" << endl;
     cin >> buckets;
     cout << "Enter Number of Buckets for Second Hash:" << endl;
     cin >> buckets2;
     cout << endl;
     Hash3 dictionary(buckets, buckets2);
     while(option != 0) {
        cout << "Choose an Option:" << endl;
        cout << "1: Search" << endl;
        cout << "2: Delete" << endl;
        cout << "3: Inset" << endl;
        cout << "0: Exit Program" << endl;
	cin >> option;
        if(option != 0) {
	   cout << "Enter File Name:" << endl;
	   cin >> fileName;
	   myFile.open(fileName.c_str());
	   if(option == 1) {
	      while(myFile >> key) {
	         if(dictionary.search(key)) 
		    cout << key << " TRUE" << endl;
		 else
		    cout << key << " FALSE" << endl;
              }
	   }
	   else if(option == 2) {
	      while(myFile >> key) dictionary.remove(key);
	   }
	   else if(option == 3) {
	      while(myFile >> key) dictionary.inset(key);
	   }
	   myFile.close();
	}
     }
  }
  else {
     cout << "ERROR: Invalid Selection!" << endl;
     exit(-1);
  }


}
