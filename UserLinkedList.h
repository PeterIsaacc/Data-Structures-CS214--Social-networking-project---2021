//
// Created by david on 7/12/2021.
//

#ifndef PROJECT_USERLINKEDLIST_H
#define PROJECT_USERLINKEDLIST_H

#include "User.h"
#include <String>
using namespace std;

class UserLinkedList {

    struct Node {
        User info;
        Node* next;
         Node(User data){
            this->info=data;
            this->next = nullptr;
        }
    };


private:
    Node* head = nullptr, *tail = nullptr;
    int length;

public:
    UserLinkedList();
    void insertAtHead(User data);
    void insertAtTail(User data);
    User*  search(string username);
    void printList();
    UserLinkedList TraverseLinkedList(User& user);
};


#endif //PROJECT_USERLINKEDLIST_H
