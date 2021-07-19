#include "Treap.h"
#include "User.h"
#include <iostream>
#include <ctime>
using namespace std;

Treap::Treap()
{
    srand(time(0));
    this->_root = 0;
}

void Treap::inOrder(TreapNode *node)
{
    if (node != 0)
    {
        inOrder(node->left);
        cout << *(node->user);
        inOrder(node->right);
    }
}

User *Treap::find(string username)
{
    TreapNode *current = _root;
    while (current != 0)
    {
        if (username == current->username)
            return current->user;
        else if (username < current->username)
            current = current->left;
        else
            current = current->right;
    }
    //if not found, returns null
    return 0;
}

void Treap::insert(TreapNode *&node, string username, User *user)
{
    if (node == 0)
    {
        node = new TreapNode(username, user);
        return;
    }
    if (username > node->username) 
    {
        insert(node->right, username, user);
        if (node->right != 0 && node->priority < node->right->priority) {
            leftRotate(node);
        }
    }
    else
    {
        insert(node->left, username, user);
        if (node->left != 0 &&  node->priority < node->left->priority) {
            rightRotate(node);
        }
    }
}

void Treap::remove(TreapNode *&node, string username)
{
    if (node == 0)
        return;

    if (username < node->username)
        remove(node->left, username);

    else if (username > node->username)
        remove(node->right, username);

    else
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            node = nullptr;
        }
        else if (node->left && node->right)
        {
            if (node->left->priority > node->right->priority)
            {
                leftRotate(node);
                remove(node->left, username);
            }
            else
            {
                rightRotate(node);
                remove(node->right, username);
            }
        }
        else
        {
            TreapNode *child = (node->left) ? node->left : node->right;
            TreapNode *curr = node;
            node = child;
            delete curr;
        }
    }
}

void Treap::leftRotate(TreapNode *&node)
{
    TreapNode *rightSubTree = node->right;
    TreapNode *leftSubTreeOfChild = node->right->left;
    rightSubTree->left = node;
    node->right = leftSubTreeOfChild;
    node = rightSubTree;
}

void Treap::rightRotate(TreapNode *&node)
{
    TreapNode *leftSubTree = node->left;
    TreapNode *rightSubTreeOfChild = node->left->right;
    leftSubTree->right = node;
    node->left = rightSubTreeOfChild;
    node = leftSubTree;
}