#pragma once

#include "BTreeNode.h"

class BTree
{
    BTreeNode* root; // Pointer to root node
    int t;  // Minimum degree
    /*
    * every node, other than root, must have at least t-1 keys
    * every internal node, other than root, must have at least t children
    * every node must have at most 2t-1 keys, therefore has at most 2t children
    */

public:

    // Constructor (Initializes tree as empty)
    BTree(int _t);

    //needs destructor

    // function to traverse the tree
    void traverse();

    // function to search a key in this tree
    BTreeNode* search(char* k);

    index _search(std::string k);

    // The main function that inserts a new key in this B-Tree
    void insert(index k);

    // The main function that removes a new key in thie B-Tree
    void remove(index k);

    void _export(std::string _filename);

    void _printLevels();
};