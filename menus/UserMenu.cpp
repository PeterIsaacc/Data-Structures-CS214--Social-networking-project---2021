#include "UserMenu.h"
#include "User.h"
#include "MenuUtil.h"
#include "UserManager.h"
#include <iostream>

UserMenu::UserMenu(User* user) {
    if(user)
        _currentUser = user;
    std::cout << _currentUser->getUsername() << std::endl; // TODO Cleanup
}

void UserMenu::Show() {
	MenuUtil::Print("1. List all friends\n2. Search by username\n");
	MenuUtil::Print("3. Add Friend\n4. Remove friend\n");
	MenuUtil::Print("5. People you may know\n6. Logout\n");
}

bool UserMenu::Handle() {
	switch(MenuUtil::GetValidIntInput(1, 6))
	{
	case 1: // List all friends
	    ListAllFriends();
		return false;
	case 2: // Search by username
	    SearchByUsername();
		return false;
	case 3: // Add friend
	    AddFriend();
		return false;
	case 4: // Remove friend
	    RemoveFriend();
		return false;
	case 5: // People you may know
	    ShowPeopleYouMayKnow();
		return false;
	case 6:
		// Logout
		return true;
	default:
		MenuUtil::Print("Unknown error.");
		return true;
	}
}

void UserMenu::ListAllFriends() {
    _currentUser->ListFriends();
}

void UserMenu::SearchByUsername() {
    MenuUtil::Print("Enter username:\n");
    User* user = UserManager::UserManager_Instance->Search(MenuUtil::GetValidStringInput());
    if(!user)
    {
        MenuUtil::Print("Not a valid user.\n");
        return;
    }
    MenuUtil::Print(user->toString());
}

void UserMenu::AddFriend() {
    MenuUtil::Print("Enter username:\n");
    User* user = UserManager::UserManager_Instance->Search(MenuUtil::GetValidStringInput());
    if(!user)
    {
        MenuUtil::Print("Not a valid user.\n");
        return;
    }

    if(_currentUser->IsAFriend(*user))
    {
        MenuUtil::Print("This user is already a friend.\n");
        return;
    }

    _currentUser->AddFriend(*user);
}

void UserMenu::RemoveFriend() {
    MenuUtil::Print("Enter username:\n");
    User* user = UserManager::UserManager_Instance->Search(MenuUtil::GetValidStringInput());
    if(!user)
    {
        MenuUtil::Print("Not a valid user.\n");
        return;
    }
    MenuUtil::Print("Friend removed successfully.\n");
    _currentUser->RemoveFriend(*user);
}


void UserMenu::ShowPeopleYouMayKnow()
{
    MenuUtil::Print("People you may know\n");
    UserManager::UserManager_Instance->GetUserRecommendation(*_currentUser).printList();
}
