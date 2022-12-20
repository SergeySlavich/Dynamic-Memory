#include<iostream>
using namespace std;

//TODO:
//1. Выучить теорию по указателям.
//2. В проект DynamicMemory добавить следующие функции :
//? ? ? insert(? ? ? );		//вставляет в массив указанное значение по указанному индексу
//? ? ? pop_back(? ? ? );	//удаляет последний элемент из массива
//? ? ? pop_front(? ? ? );	//удаляет нудевой элемент массива
//? ? ? erase(? ? ? );		//удаляет элемент по указанному индексу

#define tab "\t"
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int* arr, int &n, int value);
int* push_front(int* arr, int& n, int value);
int* insert(int* arr, int& n, int value, int index);	//вставляет в массив указанное значение по указанному индексу
int* pop_back(int* arr, int& n);						//удаляет последний элемент из массива
int* pop_front(int* arr, int& n);						//удаляет нудевой элемент массива
int* erase(int* arr, int& n, int index);				//удаляет элемент по указанному индексу

//#define PUSH_BACK
//#define PUSH_FRONT
#define INSERT
#define POP_BACK
#define POP_FRONT
#define ERASE

void main()
{
	setlocale(LC_ALL, "Russian");
	int n, value, index;
	cout << "***Создание исходного массива***\n";
	cout << "Введите количество элементов: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

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

	delete[] arr;
	//Memory leak
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
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
	//6) После добавления в массив "arr" элемента, количество
	n++;
	//7) Mission complete - элемент добавлен
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