#include <iostream>
#include "MainMenu.h"
#include "MenuManager.h"
#include "MenuUtil.h"
#include "UserMenu.h"
#include "User.h"
#include "UserManager.h"

void MainMenu::Show()
{
	std::cout << "Choose an option:\n1. Login\n2. Exit";
}

bool MainMenu::Handle()
{
	switch (MenuUtil::GetValidIntInput(1, 2))
	{
		case 1: // Login
			Login();
			return false;
		case 2: // Exit
			return true;
		default:
			MenuUtil::Print("Unknown error.\n");
			return false;
	}
}

void MainMenu::Login() {
    MenuUtil::Print("Enter your name:\n");
    User* currentUser = UserManager::UserManager_Instance->Login(MenuUtil::GetValidStringInput());
    if(currentUser)
        MenuManager::MenuManager_Instance->ExecuteMenu(new UserMenu(currentUser));
    else
        MenuUtil::Print("Not a valid username.\n");
}