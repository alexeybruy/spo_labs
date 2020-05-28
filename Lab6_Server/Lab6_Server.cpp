#pragma warning(disable: 4996)
#pragma comment ( lib, "ws2_32.lib" )
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <iostream>
#include <conio.h>

using namespace std;

const int defaultItemSize = 4;


int getMatrixSum(int ** matrix, int matrixSize)
{
	int sum = 0;
	
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if (i == 0 || i == matrixSize - 1 || j == 0 || j == matrixSize - 1)
			{
				sum += matrix[i][j];
			}
		}
	}

	return sum;
}

int** parseIncomingData(char* array, int matrixSize)
{
	int** matrix = new int* [matrixSize];

	for (int i = 0; i < matrixSize; i++)
	{
		matrix[i] = new int[matrixSize];

		
		for (int j = 0; j < matrixSize; j++)
		{
			
			char item[defaultItemSize];

			for (int k = 0; k < defaultItemSize; k++)
			{
				item[k] = array[(i * matrixSize + j) * defaultItemSize + k];
			}
			
			matrix[i][j]= atoi(item);
		}
	}

	return matrix;
}

int getMatrixSize(int arraySize)
{
	return sqrt(arraySize/ defaultItemSize) ;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	auto serverAddress = "127.0.0.1";
	auto serverPort = 5150;

	cout << "Server Port: " << serverPort << endl;
	int incomingSize = SOCKET_ERROR;

	WSADATA wsaData;

	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET currentSocket = socket(AF_INET, SOCK_DGRAM, 0);

	cout << "Server IP: " << serverAddress << endl;

	sockaddr_in socketAddressIn;
	
	socketAddressIn.sin_family = AF_INET;
	socketAddressIn.sin_addr.s_addr = inet_addr(serverAddress);
	socketAddressIn.sin_port = htons(serverPort);

	bind(currentSocket, (sockaddr*)(&socketAddressIn), sizeof(socketAddressIn));

	
	char  buffer[10*1024];

		sockaddr_in clientAddress;
		int clientAddressSize = sizeof(clientAddress);
		incomingSize = recvfrom(currentSocket, buffer, sizeof(buffer), 0, (sockaddr*)&clientAddress, &clientAddressSize);

		int** incomingData = parseIncomingData(buffer, getMatrixSize(incomingSize));

	cout << "Сумма крайних элементов матрицы:" << getMatrixSum(incomingData, getMatrixSize(incomingSize)) << endl << endl;

	
	system("pause");
	closesocket(currentSocket);
	exit(0);
}