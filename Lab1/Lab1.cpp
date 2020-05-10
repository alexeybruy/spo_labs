#include <iostream>
#include <Windows.h>
#include <stdio.h>
using namespace std;


int** matrix;
int n, m;

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

	cout << endl << "—умма крайних элементов: "  << result << endl << endl;

	return 0;
}

	void StartUp() 
	{
		while (true)
		{
			cout << "¬ведите размер матрицы (строк, колонок): ";
				cin >> n >> m;

				if (!cin) {
					cin.clear();
					while (getchar() != '\n');
					continue;
				}

				matrix = new int* [n];

				cout << endl << "¬ведите матрицу: " << endl;

				for (int i = 0; i < n; i++) {
					matrix[i] = new int[m];

					for (int j = 0; j < m; j++) {
						cin >> matrix[i][j];
					}
				}

				HANDLE hThread1 = CreateThread(NULL, 0, Thread, NULL, 0, NULL);
				WaitForSingleObject(hThread1, INFINITE);
				CloseHandle(hThread1);		

		}
	}


int main()
{
	setlocale(LC_ALL, "Ru");
	StartUp();
}