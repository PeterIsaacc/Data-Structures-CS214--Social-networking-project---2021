//
// Created by peter on 7/18/2021.
//
#include <iostream>
#include "UserManager.h"
#include <string>
#include <algorithm>

using namespace std;
UserManager* UserManager::UserManager_Instance;
UserManager::UserManager()
{
    if(!UserManager_Instance)
        UserManager_Instance = this;

    ifstream nameFileout;
    nameFileout.open(R"(../all-users.in)"); // TODO handle if file is not found
    while(!nameFileout.eof()){
        string userName;
        string name;
        string email;
        nameFileout >> userName;
        userName.erase(userName.end() - 1);
        getline(nameFileout, name, ',');
        name.erase(name.begin());
        nameFileout >> email;
        User user(userName, name, email);
        if(_userList.search(userName))
        {
            std::cout << "ERROR! user name already exists" << endl;
            continue;
        }
        _userList.insertAtHead(user);
    };

    nameFileout.close();
    ReadInputForRelations();
}

void UserManager::ReadInputForRelations()
{
    ifstream tmp;
    tmp.open("../all-users-relations.in");

    while(!tmp.eof())
    {
        string tmpFirstUser,tmpSecondUser;

        tmp >> tmpFirstUser;
        getline(tmp, tmpSecondUser, ',');

        User* firstUser = _userList.search(tmpFirstUser);
        User* secondUser = _userList.search(tmpSecondUser);

        if(firstUser && secondUser)
        {
            firstUser->AddFriend(*secondUser);
            secondUser->AddFriend(*firstUser);
        }
    }

    tmp.close();
}

User* UserManager::Login(const std::string& name)
{
    return _userList.search(name);
}

User* UserManager::Search(const std::string& name)
{
    return _userList.search(name);
}


