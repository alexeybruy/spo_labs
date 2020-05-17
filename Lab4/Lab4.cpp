#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <functional>
#define MEMORY_SIZE 12000

using namespace std;

class Item {
public:
	int Data;
	Item* Next;

	Item()
	{
		Next = NULL;
	}

	void FillFromConsole() {
		int val = 0;
		while (true)
		{
			cout << "Введите значение: ";

			try {
				cin >> val;
				break;
			}
			catch (...) {
				cout << "Ошибка!";
			}
		}

		Data = val;
	}
};


Item * firstItem = NULL;
Item * currentItem = NULL;

void isEmpty() {
	if (firstItem == NULL) {
		cout << "Список пуст" << endl;
	}
	else {
		auto local = firstItem;

		do {
			cout << local->Data << endl;
			local = local->Next;
		} while (local != NULL);
	}
}

void resetPointer() {
	currentItem = firstItem;
}

void addAfterPointer() {
	Item* itemToAdd = new Item();
	itemToAdd->FillFromConsole();

	VirtualAlloc(NULL, MEMORY_SIZE, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);

	if (currentItem == NULL) {
		firstItem = itemToAdd;
		currentItem = itemToAdd;
	}
	else {
		Item* nextItem = currentItem->Next;
		currentItem->Next = itemToAdd;
		itemToAdd->Next = nextItem;
	}
}

void deleteAfterPointer() {
	Item* itemToDelete = currentItem->Next;

	currentItem->Next = itemToDelete->Next;

	delete itemToDelete;

	VirtualFree(itemToDelete, MEMORY_SIZE, MEM_RESERVE | MEM_COMMIT);
}

void getNext() {
	cout << currentItem->Data;
}

void movePointerNext() {
	currentItem = currentItem->Next;
}

void switchWithLast() {
	Item* local = currentItem;

	while (local->Next != NULL) {
		local = local->Next;
	}

	auto temp = local->Data;
	local->Data = currentItem->Data;
	currentItem->Data = temp;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SYSTEM_INFO SysInfo;
	GetSystemInfo(&SysInfo);

	cout << "Команды" << endl;
	cout << "[1] Проверить, список пуст/не пуст" << endl;
	cout << "[2] Установить указатель в начало списка" << endl;
	cout << "[3] Добавить элемент за указателем" << endl;
	cout << "[4] Удалить элемент за указателем" << endl;
	cout << "[5] Просмотреть элемент за указателем" << endl;
	cout << "[6] Переместить указатель вправо" << endl;
	cout << "[7] Обменять значения конца списка и элемента за указателем" << endl << endl;

	while (true) {
		int n;
		cout << endl;
		cout << "Введите команду: ";
		cin >> n;

		switch (n)
		{
		case 1:
		{
			isEmpty();
			break;
		}
		case 2:
		{
			resetPointer();
			break;
		}
		case 3:
		{
			addAfterPointer();
			break;
		}
		case 4:
		{
			deleteAfterPointer();
			break;
		}
		case 5:
		{
			getNext();
			break;
		}
		case 6:
		{
			movePointerNext();
			break;
		}
		case 7:
		{
			switchWithLast();
			break;
		}
		}
	}
}