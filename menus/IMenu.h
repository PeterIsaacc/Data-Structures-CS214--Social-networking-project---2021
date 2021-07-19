#pragma once

class IMenu
{
public:
	// Show the context of the menu 
	virtual void Show() = 0;
	// Return true to exit, otherwise false
	virtual bool Handle() = 0;
};