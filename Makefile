all: driver.cpp bst.cpp avl.cpp hash1.cpp hash2.cpp hash3.cpp
	g++ driver.cpp -o driver avl.cpp hash1.cpp hash2.cpp hash3.cpp bst.cpp
