#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <chrono> 
using namespace std::chrono;
using namespace std;


int** matrix;
int n, m;

bool isThreadFree = true;

DWORD WINAPI Thread(void* pParams)
{

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
			{
				result += matrix[i][j];
			}
		}
	}

	cout << "Сумма крайних элементов: " << result << endl;

	isThreadFree = true;

	return 0;
}

void RunThreadWithPriority(int priority) {
	while (true) {
		if (isThreadFree) {
			isThreadFree = false;

			auto start = high_resolution_clock::now();

			HANDLE threadHandler = CreateThread(NULL, 0, Thread, NULL, 0, NULL);
			SetThreadPriority(threadHandler, priority);
			WaitForSingleObject(threadHandler, INFINITE);
			CloseHandle(threadHandler);

			auto stop = high_resolution_clock::now();

			cout << "Длительность: " << duration_cast<microseconds>(stop - start).count() << " микросекункд" << endl << endl;

			break;
		}
	}
}

void StartUp()
{
	while (true) {
		cout << "Введите размер матрицы (строк, колонок): ";
		cin >> n >> m;

		if (!cin) {
			cin.clear();
			while (getchar() != '\n');
			continue;
		}

		matrix = new int* [n];

		cout << endl << "Введите матрицу: " << endl;

		for (int i = 0; i < n; i++) {
			matrix[i] = new int[m];

			for (int j = 0; j < m; j++) {
				cin >> matrix[i][j];
			}
		}

		cout << endl << "Высокий приоритет: " << endl;
		RunThreadWithPriority(THREAD_PRIORITY_ABOVE_NORMAL);

		cout << endl << "Низкий приоритет: " << endl;
		RunThreadWithPriority(THREAD_PRIORITY_LOWEST);
	}
}

int main()
{
	setlocale(LC_ALL, "Ru");
	StartUp();
}