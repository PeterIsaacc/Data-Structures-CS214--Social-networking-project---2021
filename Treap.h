#ifndef TREAP_H
#define TREAP_H

#include "User.h"
#include <iostream>
using namespace std;

class User; //forward definition

struct TreapNode
{
    string username;
    User *user;
    TreapNode *left, *right;
    int priority;

    TreapNode(string username, User *user, TreapNode *left = 0, TreapNode *right = 0)
    {
        this->username = username;
        this->user = user;
        this->left = left;
        this->right = right;
        this->priority = rand() % 150;
    }
};

class Treap
{
    private:
        TreapNode *_root;
        void inOrder(TreapNode *node);
        void leftRotate(TreapNode *&node);
        void rightRotate(TreapNode *&node);
        void insert(TreapNode *&node, string username, User *user);
        void remove(TreapNode *&node, string username);

    public:
        Treap();
        void add(string username, User *user){ insert(_root, username, user); };
        void remove(string username){ remove(_root, username); };
        User *find(string username);
        void printInOrder() {
            if(!_root)
                std::cout << "There's no friends in your friend list\n";
            inOrder(_root);
        };
};

#endif