#include <iostream>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	std::cout << "1 задание:\n";
	int rows;
	std::cout << "Введите размер матрицы: ";
	std::cin >> rows;
	int cols = rows;

	int** ptr_arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		ptr_arr[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = i; j < cols; j++)
		{
			if (i == j)
			{
				ptr_arr[i][j] = 0;
			}
			else
			{
				ptr_arr[i][j] = rand() % 2;
				ptr_arr[j][i] = ptr_arr[i][j];
			}
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << ptr_arr[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\nЗадание 2:" << std::endl;
	int ptr_arr_size = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (ptr_arr[i][j] == 1)
			{
				ptr_arr_size++;
			}
		}
	}
	std::cout << "Размер графа: " << ptr_arr_size / 2 << std::endl;

	std::cout << "\nЗадание 3:\n" << std::endl;
	int deg = rows;
	int* ptr_deg = new int[deg];

	for (int i = 0; i < rows; i++)
	{
		ptr_deg[i] = 0;
	}

	int znach = 1;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (ptr_arr[i][j] == 1)
			{
				ptr_deg[i]++;
			}
		}
		printf("Степень вершины %d = %d \n", znach, ptr_deg[i]);
		znach++;
	}

	znach = 1;
	for (int i = 0; i < rows; i++)
	{
		if (ptr_deg[i] == 0)
		{
			printf("Вершина %d изолированная\n", znach);
		}
		if (ptr_deg[i] == 1)
		{
			printf("Вершина %d концевая\n", znach);
		}
		else
		{
			printf("Вершина %d доминирующая\n", znach);
		}
		znach++;
	}

	delete[]ptr_deg;
	for (int i = 0; i < rows; i++)
	{
		delete[]ptr_arr[i];
	}
	delete[]ptr_arr;

	return 0;
}