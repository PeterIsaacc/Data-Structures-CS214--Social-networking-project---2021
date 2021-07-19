//
// Created by david on 7/12/2021.
//

#include "UserLinkedList.h"

UserLinkedList::UserLinkedList() {
    head = tail = nullptr;
    length = 0;
}
void UserLinkedList::insertAtHead(User data) {
    Node* newNode = new Node(data);
    newNode->info = data;
    newNode->next = head;
    head = newNode;
}

void UserLinkedList::insertAtTail(User data) {
    Node* newNode = new Node(data);
    newNode->info = data;

    if (tail)
        tail->next = newNode;
    tail = newNode;
    if (!head)
        head = newNode;

    length++;

}

User* UserLinkedList::search(string data) {
    Node* current = head;
    while (current != NULL)
    {
        if (current->info.getUsername() == data)
            break;
        current = current->next;
    }

    if(!current)
        return 0;

    return &current->info;
}

void UserLinkedList::printList() {
    Node* temp;
    temp=head;

    while (temp!= nullptr){
        cout<<temp->info<<" ";
        temp=temp->next;
    }

}

UserLinkedList UserLinkedList::TraverseLinkedList(User& user)
{
    Node* temp;
    temp = head;

    UserLinkedList _tempList;

    while (temp!= nullptr){
        if(user.IsAFriend(temp->info) || user == temp->info)
        {
            temp=temp->next;
            continue;
        }
        else
        {
            _tempList.insertAtHead(temp->info);
        }

        temp=temp->next;
    }

    return _tempList;
}


