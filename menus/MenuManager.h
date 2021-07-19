#pragma once
#include "stack"

class IMenu;
class MenuManager
{
public:
	static MenuManager* MenuManager_Instance;
private:
	static std::stack<IMenu*> _currentMenus;
public:
	MenuManager(); 
	static bool Run();
	static void ExecuteMenu(IMenu* menu);
};
