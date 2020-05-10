#include <iostream>
#include <windows.h>
#include <queue>

using namespace std;

int DurationBase = -10000000LL;

int BarberDuration = 3;

int Counter = 0; // Номер пришедшего клиента

class Clients {
public:
	int Max;
	queue<int> Query;

	Clients(int max) {
		Max = max;
	}

	int Number() {
		return Query.size();
	}
};

Clients Simple(3);
Clients Special(2);

HANDLE BarberEvent; // Событие: парикмахер свободен

void StartBarber() {
	LARGE_INTEGER * barberTime = new LARGE_INTEGER();
	barberTime->QuadPart = DurationBase * BarberDuration;

	SetWaitableTimer(BarberEvent, barberTime, 0, NULL, NULL, 0);
}

DWORD WINAPI Client(PVOID Parametr)
{
	bool wasEmpty = Special.Number() == 0 && Simple.Number() == 0;

	Clients* clients = NULL;

	if (Special.Number() < Special.Max) {
		clients = &Special;
	}
	else if (Simple.Number() < Simple.Max) {
		clients = &Simple;
	}

	Counter++;

	if (clients != NULL) {
		clients->Query.push(Counter);
		cout << "Клиент пришел " << Counter << endl;

		if (wasEmpty) {
			StartBarber();
		}
	}
	else
	{
		cout << "Не было места для " << Counter << endl;
	}

	return 0;
}

DWORD WINAPI Barber(PVOID Parametr)
{
	while (true)
	{
		if (WaitForSingleObject(BarberEvent, INFINITE) == WAIT_OBJECT_0) {
			Clients* clients = NULL;

			string status = "";

			if (Special.Number() > 0) {
				clients = &Special;
				status = "VIP";
			}
			else if (Simple.Number() > 0) {
				clients = &Simple;
			}

			if (clients != NULL) {
				auto first = clients->Query.front();
				clients->Query.pop();

				cout << endl << "Клиент обслужен " << first << " " << status << endl;

				if (Special.Number() > 0 || Simple.Number() > 0) {
					StartBarber();
				}
				else {
					CancelWaitableTimer(BarberEvent);
					cout << endl << "Барбер спит" << endl;
				}
			}
		}
	}
	return 0;
}
int main()
{
	setlocale(LC_ALL, "Ru");

	cout << "Обычных мест: " << Simple.Max << endl;
	cout << "VIP мест: " << Special.Max << endl;

	cout << "Барбер спит" << endl;

	BarberEvent = CreateWaitableTimer(NULL, TRUE, NULL);
	HANDLE Th1 = CreateThread(NULL, 0, Barber, NULL, 0, NULL);

	while (true)
	{
		while (cin.get() != '\n'); // При нажатии на Enter добавляется клиент

		CreateThread(NULL, 0, Client, NULL, 0, NULL);
	}
}