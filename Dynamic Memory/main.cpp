#include<iostream>
using namespace std;

//TODO:
//В проект DynamicMemory добавить следующие функции :
//? ? ? push_row_front(? ? ? );	//добавляет строку в начало массива
//? ? ? insert_row(? ? ? );		//вставляет строку в массив по указанному индексу

//? ? ? pop_row_back(? ? ? );		//удаляет последнюю строку из двумерного массива
//? ? ? pop_row_front(? ? ? );		//удаляет нулевую строку из двумерного массива
//? ? ? erase_row(? ? ? );			//удаляет строку из двумерного массива по указанному индексу

#define tab "\t"
#define delimiter "\n-----------------------------------------------------------------------\n"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
int* push_back(int* arr, int &n, int value);
int** push_row_back(int** arr, int& rows, const int cols);
int* push_front(int* arr, int& n, int value);
int** push_row_front(int** arr, int& rows, const int cols);			//добавляет строку в начало массива
int* insert(int* arr, int& n, int value, int index);				//вставляет в массив указанное значение по указанному индексу
int** insert_row(int** arr, int& rows, const int cols, int index);	//вставляет в массив указанное значение по указанному индексу
int* pop_back(int* arr, int& n);									//удаляет последний элемент из массива
int** pop_row_back(int** arr, int& rows, const int cols);			//удаляет последнюю строку из двумерного массива
int* pop_front(int* arr, int& n);									//удаляет нудевой элемент массива
int** pop_row_front(int** arr, int& rows, const int cols);			//удаляет нулевую строку из двумерного массива
int* erase(int* arr, int& n, int index);							//удаляет элемент по указанному индексу
int** erase_row(int** arr, int& rpws, const int cols, int index);	//удаляет строку из двумерного массива по указанному индексу

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define PUSH_BACK
//#define PUSH_FRONT
//#define INSERT
//#define POP_BACK
//#define POP_FRONT
//#define ERASE

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef DYNAMIC_MEMORY_1
	int n, value, index;
	cout << "***Создание исходного массива***\n";
	cout << "Введите количество элементов: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
#endif

#ifdef PUSH_BACK
	cout << "\n***Добавление элемента в конец массива***\n";
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
#endif

#ifdef PUSH_FRONT
	cout << "\n***Добавление элемента в начало массива***\n";
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
#endif

#ifdef INSERT
	cout << "\n***Добавление элемента по номеру ячейки***\n";
	cout << "Введите добавляемое значение: "; cin >> value;
	do
	{
		cout << "Введите индекс ячейки для этого значения (нумерация с 0): "; cin >> index;
		if (index >= n) cout << "\nВНИМАНИЕ! Такой ячейки не существует! Попробуйте ещё раз.\n";
	} while (index >= n);
	arr = insert(arr, n, value, index);
	Print(arr, n);
#endif

#ifdef POP_BACK
	cout << "\n***Удаление последней ячейки массива***\n";
	arr = pop_back(arr, n);
	Print(arr, n);
#endif

#ifdef POP_FRONT
	cout << "\n***Удаление первой ячейки массива***\n";
	arr = pop_front(arr, n);
	Print(arr, n);
#endif

#ifdef ERASE
	cout << "\n***Удаление ячейки по её номеру***\n";
	do
	{
		cout << "\nВведите индекс ячейки, которую нужно удалить (нумерация с 0): "; cin >> index;
		if (index >= n) cout << "\nВНИМАНИЕ! Такой ячейки не существует! Попробуйте ещё раз.\n";
	} while (index >= n);
	arr = erase(arr, n, index);
	Print(arr, n);
#endif

	//delete[] arr;
	//Memory leak

#ifdef DYNAMIC_MEMORY_2
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** arr = new int* [rows]; // создаем массив указателей
	for (int i = 0; i < rows; i++)
	{
		// создаем строки двумерного массива
		arr[i] = new int[cols];
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	int index;
	cout << "Введите индекс строки, которую нужно вставить в массив: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "Введите индекс удаляемой строки: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	//удаляем строки двумерного массива
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//удаляем массив указателей
	delete[] arr;

#endif
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}

int* push_back(int* arr, int &n, int value)
{
	//1) Создаем новый массив нужного размера
	int* buffer = new int[n + 1];
	//2) Копируем все содержимое исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив:
	delete[] arr;
	//4) Подменяем адрес в указателе "arr" адресом нового массива:
	arr = buffer;
	//5) Только после всего этого в конец массива "arr" можно добавить значение:
	arr[n] = value;
	//6) После добавления в массив "arr" элемента, количество его элементов увеличивается на 1
	n++;
	//7) Mission complete - элемент добавлен
	return arr;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	// 1) Создаем буферный массив указателей:
	int** buffer = new int* [rows + 1];
	// 2) Копируем адреса строк в новый массив указателей:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) Удаляем исходный массив указателей:
	delete[] arr;
	// 4) Подменяем адрес указателей 'arr' адресом нового массива:
	arr = buffer;
	// 5) Создаем новую строку:
	buffer[rows] = new int [cols] {};
	// 6) После добавления строки, количество строк увеличивается на 1
	rows++;
	// 7) Mission complete - строка добавлена. Возвращаем новый массив.
	return arr;
}

int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}

int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];		// 1) Создаем буферный массив указателей.
	for (int i = 0; i < rows; i++)			// 2) Копируем адреса строк в новый массив указателей.
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;							// 3) Удаляем исходный массив указателей
	arr = buffer;							// 4) Подменяем адрес указателей 'arr' адресом нового массива.
	buffer[0] = new int [cols] {};			// 5) Создаем новую строку.
	rows++;									// 6) После добавления строки, количество строк увеличивается на 1
	return arr;								// 7) Mission complete - строка добавлена. Возвращаем новый массив.
}

int* insert(int* arr, int& n, int value, int index)		//вставляет в массив указанное значение по указанному индексу
{
	int* buffer = new int[n + 1];				//создаем новый увеличенный массив
	for (int i = 0; i < n + 1; i++)				//цикл переноса данных из исходного массива в созданный
	{
		if (i < index) buffer[i] = arr[i];		//перенос данных до заданного индекса
		else if (i == index) buffer[i] = value;	//заполнение ячейки с заданным индексом
		else buffer[i] = arr[i - 1];			//перенос данных после заданного индекса
	}
	delete[] arr;								//удаление исходного массива
	arr = buffer;								//присваивание исходного имени новому массиву
	n++;										//увеличение размера массива
	return arr;									//возврат
}

int** insert_row(int** arr, int& rows, const int cols, int index)			//вставляет в массив указанное значение по указанному индексу
{
	if (index > rows)				//Если индекс больше количества строк, выходим из функции.
	{
		cout << "ВНИМАНИЕ! Введенный индекс превышает размер массива. Работа функции невозможна." << endl;
		return arr;
	}
	int** buffer = new int* [rows + 1];		// 1) Создаем буферный массив указателей.
	for (int i = 0; i < rows; i++)			// 2) Копируем адреса строк в новый массив указателей.
	{
		buffer[(i < index) ? i : i + 1] = arr[i];
	}
	delete[] arr;							// 3) Удаляем исходный массив указателей.
	arr = buffer;							// 4) Подменяем адрес указателей 'arr' адресом нового массива.
	buffer[index] = new int [cols] {};		// 5) Создаем новую строку.
	rows++;									// 6) Увеличиваем количество строк в массиве.
	return arr;								// 7) Возвращаем результат.
}

int* pop_back(int* arr, int& n)		//удаляет последний элемент из массива
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int*[rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}

int* pop_front(int* arr, int& n)	//удаляет нулевой элемент массива
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}

int* erase(int* arr, int& n, int index)		//удаляет элемент по указанному индексу
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		if (i < index) buffer[i] = arr[i];
		else buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

int** erase_row(int** arr, int& rows, const int cols, int index)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
