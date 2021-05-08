#include "BTreeNode.h"

// Constructor for BTreeNode class
BTreeNode::BTreeNode(int _t, bool _leaf)
{
    // Copy the given minimum degree and leaf property
    t = _t;
    leaf = _leaf;

    // Allocate memory for maximum number of possible keys
    // and child pointers
    keys = new index[2 * t - 1];
    C = new BTreeNode * [2 * t];

    // Initialize the number of keys as 0
    n = 0;
}

// Function to traverse all nodes in a subtree rooted with this node
void BTreeNode::traverse()
{
    // There are n keys and n+1 children, travers through n keys
    // and first n children
    int i;
    for (i = 0; i < n; i++)
    {
        // If this is not leaf, then before printing key[i],
        // traverse the subtree rooted with child C[i].
        if (leaf == false)
            C[i]->traverse();
        std::cout << " " << keys[i];
    }

    // Print the subtree rooted with last child
    if (leaf == false)
        C[i]->traverse();
}

// Function to search key k in subtree rooted with this node
BTreeNode* BTreeNode::search(char* k)
{
    // Find the first key greater than or equal to k
    int i = 0;
    while (i < n && k > keys[i].key) {
        i++;
    }

    // If the found key is equal to k, return this node
    if (keys[i].key == k) {
        return this;
    }

    // If the key is not found here and this is a leaf node
    if (leaf == true) {
        return NULL;
    }

    // Go to the appropriate child
    return C[i]->search(k);
}

index BTreeNode::_search(std::string k)
{
    // Find the first key greater than or equal to k
    int i = 0;
    while (i < n && k > keys[i].key) {
        i++;
    }

    // If the found key is equal to k, return this node
    if (keys[i].key == k) {
        return this->keys[i];
    }

    // If the key is not found here and this is a leaf node
    if (leaf == true) {
        return index();
    }

    // Go to the appropriate child
    return C[i]->_search(k);
}

// A utility function to insert a new key in this node
// The assumption is, the node must be non-full when this
// function is called
void BTreeNode::insertNonFull(index k)
{
    // Initialize index as index of rightmost element
    int i = n - 1;

    // If this is a leaf node
    if (leaf == true)
    {
        // The following loop does two things
        // a) Finds the location of new key to be inserted
        // b) Moves all greater keys to one place ahead
        while (i >= 0 && keys[i].key > k.key)
        {
            keys[i + 1] = keys[i];
            i--;
        }

        // Insert the new key at found location
        keys[i + 1] = k;
        n = n + 1;
    }
    else // If this node is not leaf
    {
        // Find the child which is going to have the new key
        while (i >= 0 && keys[i].key > k.key)
            i--;

        // See if the found child is full
        if (C[i + 1]->n == 2 * t - 1)
        {
            // If the child is full, then split it
            splitChild(i + 1, C[i + 1]);

            // After split, the middle key of C[i] goes up and
            // C[i] is splitted into two.  See which of the two
            // is going to have the new key
            if (keys[i + 1].key < k.key)
                i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

// A utility function to split the child y of this node
// Note that y must be full when this function is called
void BTreeNode::splitChild(int i, BTreeNode* y)
{
    // Create a new node which is going to store (t-1) keys
    // of y
    BTreeNode* z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    // Copy the last (t-1) keys of y to z
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    // Copy the last t children of y to z
    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    // Reduce the number of keys in y
    y->n = t - 1;

    // Since this node is going to have a new child,
    // create space of new child
    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    // Link the new child to this node
    C[i + 1] = z;

    // A key of y will move to this node. Find the location of
    // new key and move all greater keys one space ahead
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    // Copy the middle key of y to this node
    keys[i] = y->keys[t - 1];

    // Increment count of keys in this node
    n = n + 1;
}