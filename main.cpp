#include <iostream>
#include "menus/MenuManager.h"
#include "UserManager.h"

using namespace std;

int main()
{
    UserManager user;
	MenuManager menuManager;
	menuManager.Run();
    return 0;
}