#pragma warning(disable: 4996)
#pragma comment ( lib, "ws2_32.lib" )
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <stdint.h>
#include <string>


const int defaultItemSize = 4;

using namespace std;

char* getMatrixAsCharArray(int** matrix, int size)
{
	char * result = new char[0];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			char item[defaultItemSize];
			
			itoa(matrix[i][j], item, 10*1024);

			for (int k = 0; k<defaultItemSize; k++)
			{
				result[(i * size + j) * defaultItemSize + k] = item[k];
			}

		}
	}

	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	auto serverAddress = "127.0.0.1";
	int serverPort = 5150;
	
	WORD versionRequested = MAKEWORD(2, 2);
	WSADATA wsaData;
	WSAStartup(versionRequested, &wsaData);

	SOCKET currentSocket = socket(AF_INET, SOCK_DGRAM, 0);

	//HOSTENT* hostent;
	sockaddr_in destinationAddress;

	destinationAddress.sin_family = AF_INET;
	destinationAddress.sin_port = htons(serverPort);
	destinationAddress.sin_addr.s_addr = inet_addr(serverAddress);

	int size;
	cout << "Введите матрицу: " << endl;
	cout << "Размер: " << endl;
	cin >> size;

	int** matrix = new int*[size];

	for (int i = 0; i < size;i++)
	{
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			cin >> matrix[i][j];
		}
	}

	char * outgoingData = getMatrixAsCharArray(matrix, size);

	sendto(currentSocket, outgoingData, defaultItemSize*size*size, 0, (sockaddr*)(&destinationAddress), sizeof(destinationAddress));

	system("pause");
	closesocket(currentSocket);

	WSACleanup();
	return 0;
}