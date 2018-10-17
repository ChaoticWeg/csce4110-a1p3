#include <iostream>
#include "bst.hpp"


/*
    NODE
*/


Node::Node(int value)
{
    _left = nullptr;
    _right = nullptr;
    _value = value;
}

Node::~Node()
{
    delete _left;
    _left = nullptr;

    delete _right;
    _right = nullptr;
}

bool Node::Insert(int value)
{
    if (value == _value)
        return false;
    
    if (value < _value)
    {
        if (_left != nullptr)
        {
            return _left->Insert(value);
        }

        else
        {
            _left = new Node(value);
            return true;
        }
    }

    else
    {
        if (_right != nullptr)
            return _right->Insert(value);
        
        else
        {
            _right = new Node(value);
            return true;
        }
    }
}



/*
    TREE
*/

BinaryTree::~BinaryTree()
{
    delete _head;
}

bool BinaryTree::Insert(int value)
{
    if (_head != nullptr)
    {
        // head exists

        if (_head->Insert(value))
        {
            _size += 1;
            return true;
        }

        else return false;
    }

    else
    {
        // head does not exist

        _head = new Node(value);
        _size += 1;
        return true;
    }
}
