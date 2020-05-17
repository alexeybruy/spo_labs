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
			cout << "������� ��������: ";

			try {
				cin >> val;
				break;
			}
			catch (...) {
				cout << "������!";
			}
		}

		Data = val;
	}
};


Item * firstItem = NULL;
Item * currentItem = NULL;

void isEmpty() {
	if (firstItem == NULL) {
		cout << "������ ����" << endl;
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

	cout << "�������" << endl;
	cout << "[1] ���������, ������ ����/�� ����" << endl;
	cout << "[2] ���������� ��������� � ������ ������" << endl;
	cout << "[3] �������� ������� �� ����������" << endl;
	cout << "[4] ������� ������� �� ����������" << endl;
	cout << "[5] ����������� ������� �� ����������" << endl;
	cout << "[6] ����������� ��������� ������" << endl;
	cout << "[7] �������� �������� ����� ������ � �������� �� ����������" << endl << endl;

	while (true) {
		int n;
		cout << endl;
		cout << "������� �������: ";
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