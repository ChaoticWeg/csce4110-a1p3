#pragma once

/* BST node */
class Node
{

private:
    Node *_left;
    Node *_right;
    int _value;

public:
    Node(int);
    ~Node();

    bool Insert(int);

    inline int GetValue() { return _value; }

};


/* BST */
class BinaryTree
{

private:
    Node *_head = nullptr;
    int _size = 0;

public:
    ~BinaryTree();
    
    bool Insert(int);

    inline int GetSize() { return _size; }

};
