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
    BTree();

    //needs destructor

    // function to traverse the tree
    void traverse();

    // function to search a key in this tree
    BTreeNode* search(char* k);

    index _search(std::string k);

    std::vector<index> _find(std::string k);

    // The main function that inserts a new key in this B-Tree
    void insert(index k);

    // The main function that removes a new key in thie B-Tree
    void remove(index k);

    // Main function to export a tree to a file
    void _export(std::string _filename);

    // Main function to import a file to the tree
    void _import(std::string _filename); //broken

    // Main function to print the tree to the console, top -> down, left -> right
    void _printLevels();

    //Indexes file to BTree by id, type, title, director, cast, country, year
    void _index(std::string _filename, std::string type);
};