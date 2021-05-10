#include "BTree.h"

// Constructor (Initializes tree as empty)
BTree::BTree(int _t)
{
	root = NULL;  t = _t;
}

// function to traverse the tree
void BTree::traverse()
{
	if (root != NULL) { root->traverse(); }
}

// function to search a key in this tree
BTreeNode* BTree::search(char* k)
{
	return (root == NULL) ? NULL : root->search(k);
}

index BTree::_search(std::string k)
{
    if (root == NULL) {
        return index();
    }
    else {
        return root->_search(k);
    }
}

// The main function that inserts a new key in this B-Tree
void BTree::insert(index k)
{
    // If tree is empty
    if (root == NULL)
    {
        // Allocate memory for root
        root = new BTreeNode(t, true);
        root->keys[0] = k;  // Insert key
        root->n = 1;  // Update number of keys in root
    }
    else // If tree is not empty
    {
        // If root is full, then tree grows in height
        if (root->n == 2 * t - 1)
        {
            // Allocate memory for new root
            BTreeNode* s = new BTreeNode(t, false);

            // Make old root as child of new root
            s->C[0] = root;

            // Split the old root and move 1 key to the new root
            s->splitChild(0, root);

            // New root has two children now.  Decide which of the
            // two children is going to have new key
            int i = 0;
            if (s->keys[0].key < k.key)
                i++;
            s->C[i]->insertNonFull(k);

            // Change root
            root = s;
        }
        else  // If root is not full, call insertNonFull for root
            root->insertNonFull(k);
    }
}

void BTree::remove(index k)
{
    if (!root)
    {
        std::cout << "The tree is empty\n";
        return;
    }

    // Call the remove function for root
    root->remove(k);

    // If the root node has 0 keys, make its first child as the new root
    //  if it has a child, otherwise set root as NULL
    if (root->n == 0)
    {
        BTreeNode* tmp = root;
        if (root->leaf)
            root = NULL;
        else
            root = root->C[0];

        // Free the old root
        delete tmp;
    }
    return;
}

// function to export the tree
void BTree::_export(std::string _filename)
{
    if (root != NULL) { 
        int counter = 1;
        std::fstream _file;

        _file.open(_filename, std::ios::out);//| std::ios::app | std::ios::trunc);

        if (!_file.is_open()) { std::cout << _filename + " could not be opened" << std::endl; return; }
        _file << counter << std::endl;
        if (root->leaf) { counter = -1; root->_exportNode(_file, counter); }
        else { counter++; root->_exportNode(_file, counter); root->_export(_file, counter); }
        _file.close();
    }
}

void BTree::_printLevels()
{
    if (root->leaf) { root->_printLevel(); }
    else { root->_printLevel(); root->_printLevels(); }
}