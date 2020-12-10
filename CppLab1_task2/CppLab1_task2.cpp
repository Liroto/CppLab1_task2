#include <iostream>
#include <string>
#include <array>
using namespace std;


int *initializationArray(int LENGTH) //функция принимает ТОЛЬКО длину массива из функции main()
{
	int *arr = new int[LENGTH];

	for (int i = 0; i < LENGTH; i++)
	{
		arr[i] = pow(i, 2) + 1;
		if (i % 2 == 0) arr[i] *= -1;
		cout << arr[i] << " ";
	}
	cout << "Initialization function is finished.\n" << endl;
	return arr;
	delete[] arr;
}

void transformationArray(int arr[], int LENGTH, int rows, int columns) //функция принимает массив из функции initializationArray()
{
	//ЭТАП 1: Сортировка входящего массива в порядке убывания
	int temp = 0;

	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = i + 1; j < LENGTH; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		cout << arr[i] << " ";
	}

	cout << "Sorting is finished.\n" << endl;

	//ЭТАП 2: 1D -> 2D

	int **twoDimensional = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		twoDimensional[i] = new int[columns];
	}

	
	int helper = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			twoDimensional[i][j] = arr[helper];
			helper++;
			printf("%5i", twoDimensional[i][j]);
		}
		cout << endl;
	}


	for (int i = 0; i < rows; i++)
	{
		delete[] twoDimensional[i];
	}
	delete[] twoDimensional;

	cout << "Transformation function is finished.\n" << endl;
}

int main()
{
	int initLENGTH = 18, initRows = 9, initColumns = 2;

	transformationArray(initializationArray(initLENGTH), initLENGTH, initRows, initColumns);

	cout << "Main function is finished." << endl;
}
