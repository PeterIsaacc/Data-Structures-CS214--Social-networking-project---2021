#pragma once
#include "IMenu.h"

class User;
class UserMenu : public IMenu
{
private:
    User* _currentUser;
    void ListAllFriends();
    void SearchByUsername();
    void AddFriend();
    void RemoveFriend();
    void ShowPeopleYouMayKnow();
public:
    UserMenu(User* currentUser);
    void Show() override;
    bool Handle() override;
};
