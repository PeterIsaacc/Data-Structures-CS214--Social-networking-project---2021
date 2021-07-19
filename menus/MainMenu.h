#pragma once
#include "IMenu.h"

class MainMenu : public IMenu
{
private:
    void Login();
public:
	void Show() override;
	bool Handle() override;
};
