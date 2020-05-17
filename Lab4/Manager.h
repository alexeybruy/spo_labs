#pragma once
#include "Item.h"
#include <windows.h>

class Manager
{
	bool Empty();
	Item GetBegin();
	void AddAfter(Item current, Item toAdd);
	void DeleteAfter(Item current);
	void GetNext(Item current);
	void SwapRight(Item current);
	void SwapWithLast(Item current);
};

