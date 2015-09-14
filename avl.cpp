/*
Author: cpriest, Caleb Priester
Filename: avl.cpp
Description: The implementation of the methods declared in avl.h
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

#include <cassert>

#include "avl.h"

// Inserts key into a tree represented by x.
bool AVL::inset (avlNode* x, long key) {
   bool needsUpdate;
   //If the tree is empty, make x the root.
   if(x == NULL) {
      avlNode *n = new avlNode(key);
      root = n;
      return false;
   }
   if(key == x->key) {
      cout << key << " is already contained in tree." << endl;
      return false;
   }
   //If key is less than the root, then call this method with the left.
   if(key < x->key) {
      if(x->left != NULL) {
         needsUpdate = inset(x->left, key);
         if(needsUpdate) x->leftHeight++;
	 if(x->leftHeight-x->rightHeight > 1) balance(x);
         return (needsUpdate && x->leftHeight > x->rightHeight);
      }
      else {
         avlNode *n = new avlNode(key, NULL, NULL, x);
	 x->left = n;
	 x->leftHeight++;
         return (x->right == NULL);
      }
      
   }
   //If key is greater than the root, then call this method with the right.
   else{
      if(x->right != NULL) {
         needsUpdate = inset(x->right, key);
         if(needsUpdate) x->rightHeight++;
	 if(x->rightHeight-x->leftHeight > 1) balance(x);
         return (needsUpdate && x->rightHeight > x->leftHeight);
      }
      else {
         avlNode *n = new avlNode(key, NULL, NULL, x);
	 x->right = n;
	 x->rightHeight++;
	 return (x->left==NULL);
      }
   }
}

// This is a wrapper function that calls the actual insert routine. It is an error to call this function
// with a duplicate key.
void AVL::inset (long key) {
  //assert(search(key) == NULL);
  inset(root, key);
}

// Searches for key in tree represented by x.
avlNode* AVL::search (avlNode *x, long key) {
   if(x == NULL) return NULL;
   else if(key == x->key) return x;
   else if(key < x->key) return search(x->left, key);
   else return search(x->right, key);
}

// This is a wrapper function that calls the actual find routine.
avlNode* AVL::search (long key) {
  return search (root, key);
}

bool AVL::remove(avlNode *x, long key) {
   bool needsUpdate;
   if(x == NULL) {
     cout << key << " is not contained in the tree.";
     return false;
   }
   else if(key < x->key) {
      needsUpdate = remove(x->left, key);
      if(needsUpdate) x->leftHeight--;
      if(x->rightHeight-x->leftHeight>1) {
         x = balance(x);
         if(x->parent != NULL && (x->parent)->left==x) {
            if(x->leftHeight > x->rightHeight) return (needsUpdate && x->leftHeight != (x->parent)->leftHeight-1);
            else  return (needsUpdate && x->rightHeight != (x->parent)->leftHeight-1);
         }
         else if(x->parent != NULL && (x->parent)->right==x) {
            if(x->leftHeight > x->rightHeight) return (needsUpdate && x->leftHeight != (x->parent)->rightHeight-1);
            else  return (needsUpdate && x->rightHeight != (x->parent)->rightHeight-1);
         }
         else return true;
      }
      return (needsUpdate && x->leftHeight+1 > x->rightHeight);
   }
   else if(key > x->key) {
      needsUpdate = remove(x->right, key);
      if(needsUpdate) x->rightHeight--;
      if(x->leftHeight-x->rightHeight>1) {
         x = balance(x);
         if(x->parent != NULL && (x->parent)->left==x) {
            if(x->leftHeight > x->rightHeight) return (needsUpdate && x->leftHeight != (x->parent)->leftHeight-1);
            else  return (needsUpdate && x->rightHeight != (x->parent)->leftHeight-1);
         }
         else if(x->parent != NULL && (x->parent)->right==x) {
            if(x->leftHeight > x->rightHeight) return (needsUpdate && x->leftHeight != (x->parent)->rightHeight-1);
            else  return (needsUpdate && x->rightHeight != (x->parent)->rightHeight-1);
         }
         else return true;
      }
      return (needsUpdate && x->rightHeight+1 > x->leftHeight);
   }
   else {
      //If the node has two children, replace it with it's successor.
      if(x->right != NULL && x->left != NULL) {
         avlNode *successor = findSuccessor(x);
	 needsUpdate = checkForUpdates(x, successor->key);
         if(successor->parent != x) {
	    if(successor->right != NULL) {
               (successor->right)->parent = successor->parent;
               (successor->parent)->left = successor->right;
	    }
	    else (successor->parent)->left = NULL;
	    successor->right = x->right;
	    (x->right)->parent = successor;
	 }
	 successor->left = x->left;
	 successor->leftHeight = x->leftHeight;
	 successor->rightHeight = x->rightHeight;
	 (x->left)->parent = successor;
	 if(x == root) {
	    successor->parent = NULL;
	    root = successor;
	 }
	 else if((x->parent)->left == x) {
	    successor->parent = x->parent;
	    (x->parent)->left = successor;
	 }
	 else {
	    successor->parent = x->parent;
	    (x->parent)->right = successor;
	 }
	 free(x);
	 if(successor->leftHeight-successor->rightHeight > 1) {
	    successor = balance(successor);
            if(successor->parent != NULL && (successor->parent)->left == successor) {
               if(successor->leftHeight > successor->rightHeight) return (successor->leftHeight != (successor->parent)->leftHeight-1);
               else return (successor->rightHeight != (successor->parent)->leftHeight-1);
            }
            if(successor->parent != NULL && (successor->parent)->right == successor) {
               if(successor->leftHeight > successor->rightHeight) return (successor->rightHeight != (successor->parent)->rightHeight-1);
               else return (successor->rightHeight != (successor->parent)->rightHeight-1);
            }
	 }
	 return (needsUpdate && successor->rightHeight+1 > successor->leftHeight);
      }
      //If x has one child, it's child can replace it in the tree.
      else if(x->right == NULL && x->left != NULL) {
         if(x->parent != NULL) {
	    if((x->parent)->right == x) {
	       (x->parent)->right = x->left;
	       (x->left)->parent = x->parent;
	    }
	    else {
	       (x->parent)->left = x->left;
	       (x->left)->parent = x->parent;
	    }
	    free(x);
	    return true;
	 }
	 else {
	    root = x->left;
	    (x->left)->parent = NULL;
	    free(x);
	    return true;
         }
      }
      else if(x->right != NULL && x->left == NULL) {
         if(x->parent != NULL) {
	    if((x->parent)->right == x) {
	       (x->parent)->right = x->right;
	       (x->right)->parent = x->parent;
	    }
	    else {
	       (x->parent)->left = x->right;
	       (x->right)->parent = x->parent;
	    }
	    free(x);
	    return true;
	 }
	 else {
	    root = x->right;
	    (x->right)->parent = NULL;
	    free(x);
	    return true;
	 }
      }
      //If x has no children, it is a leaf and should simply be deleted.
      else {
         if(x->parent == NULL) root = NULL;
         else if((x->parent)->right == x) {
	    (x->parent)->right = NULL;
	    free(x);
	    return true;
	 }
	 else {
	    (x->parent)->left = NULL;
	    free(x);
	    return true;
	 }
      }
   }
}

void AVL::remove(long key) {
   //assert(search(key) != NULL);
   remove(root, key);
}

avlNode* AVL::findSuccessor(avlNode *x){
   x = x->right;
   while(x->left != NULL) {
      x = x->left;
   }
   return x;
}

bool AVL::checkForUpdates(avlNode *x, long key) {
   bool needsUpdate;
   if(key < x->key) {
      needsUpdate = checkForUpdates(x->left, key);
      if(needsUpdate) x->leftHeight--;
      if(x->rightHeight-x->leftHeight>1) {
         x = balance(x);
         if(x->parent != NULL && (x->parent)->left==x) {
            if(x->leftHeight > x->rightHeight) return (needsUpdate && x->leftHeight != (x->parent)->leftHeight-1);
            else  return (needsUpdate && x->rightHeight != (x->parent)->leftHeight-1);
         }
         else if(x->parent != NULL && (x->parent)->right==x) {
            if(x->leftHeight > x->rightHeight) return (needsUpdate && x->leftHeight != (x->parent)->rightHeight-1);
            else  return (needsUpdate && x->rightHeight != (x->parent)->rightHeight-1);
         }
         else return true;
      }
      return (needsUpdate && x->leftHeight+1 > x->rightHeight);
   }
   else if(key > x->key) {
      needsUpdate = checkForUpdates(x->right, key);
      if(needsUpdate) x->rightHeight--;
      return needsUpdate;
   }
   else return true;

}

avlNode* AVL::balance(avlNode *x) {
   if(x->leftHeight > x->rightHeight) {
      if((x->left)->leftHeight >= (x->left)->rightHeight) {
	 x = rotateWithLeftChild(x);
      }
      else {
         x = doubleWithLeftChild(x);
      }
   }
   else {
      if((x->right)->rightHeight >= (x->right)->leftHeight) {
         x = rotateWithRightChild(x);
      }
      else {
         x = doubleWithRightChild(x);
      }
   }
   return x;
}

avlNode* AVL::rotateWithLeftChild(avlNode *x) {
   avlNode *child = x->left;
   x->left = child->right;
   if(child->right != NULL) (child->right)->parent = x;
   child->right = x;
   if(x->parent != NULL) {
      child->parent = x->parent;
      if((x->parent)->right == x) (x->parent)->right = child;
      else (x->parent)->left = child;
   }
   else {
      child->parent = NULL;
      root = child;
   }
   x->parent = child;
   x->leftHeight = child->rightHeight;
   if(x->leftHeight > x->rightHeight) child->rightHeight = x->leftHeight+1;
   else child->rightHeight = x->rightHeight+1;
   return child;
}

avlNode* AVL::rotateWithRightChild(avlNode *x) {
   avlNode *child = x->right;
   x->right = child->left;
   if(child->left != NULL) (child->left)->parent = x;
   child->left = x;
   if(x->parent != NULL) {
      child->parent = x->parent;
      if((x->parent)->right == x) (x->parent)->right = child;
      else (x->parent)->left = child;
   }
   else {
      child->parent = NULL;
      root = child;
   }
   x->parent = child;
   x->rightHeight = child->leftHeight;
   if(x->rightHeight > x->leftHeight) child->leftHeight = x->rightHeight+1;
   else child->leftHeight = x->leftHeight+1;
   return child;
}

avlNode* AVL::doubleWithLeftChild(avlNode *x) {
   avlNode *val = (x->left)->right;
   rotateWithRightChild(x->left);
   rotateWithLeftChild(x);
   return val;
}

avlNode* AVL::doubleWithRightChild(avlNode *x) {
   avlNode *val = (x->right)->left;
   rotateWithLeftChild(x->right);
   rotateWithRightChild(x);
   return val;
}
// Performs an in-order traversal.
void AVL::inOrder (avlNode *x) {
   if(x->left != NULL) inOrder(x->left);
   cout << x->key << " " << x->leftHeight << x->rightHeight <<endl;
   if(x->right != NULL) inOrder(x->right);

}

// This is a wrapper function that calls the inorder routine to enumerate contents of the set.
void AVL::print() {
  if(root != NULL) inOrder(root);
  cout << endl;
}

avlNode* AVL::getRoot() {
   return root;
}
