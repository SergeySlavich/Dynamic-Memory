#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n-------------------------------------\n"

template<typename T>T** allocate(const int);
template<typename T>clear();

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);

template<typename T>void Print(T* arr, const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* push_back(T* arr, int& n, int value);
template<typename T>T* push_front(T* arr, int& n, int value);
template<typename T>T* insert(T* arr, int& n, T value, int index);

template<typename T>T* pop_back(T* arr, int& n);
template<typename T>T* pop_front(T* arr, int& n);


template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T>T* insert_row(T* arr, int& rows, const int cols, const int index);


template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T>void push_col_back(T** arr, const int rows, int& cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "������� ���������� ���������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	int index;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	delete[] arr;
	//Memory leak  
#endif // DYNAMIC_MEMORY_1

	int rows;	//���������� �����
	int cols;	//���������� �������� (���������� ��������� ������)
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;

	int** arr = new int* [rows];	//������� ������ ����������
	for (int i = 0; i < rows; i++)
	{
		//������� ������ ���������� �������:
		arr[i] = new int[cols];
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	//1) ������� ������ ���������� �������:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2) ������� ������ ����������:
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++)
	{
		//����� ���������� ���������� � �������� �������������:
		*(arr + i) = rand() % 100;
	}
}
void FillRand(double arr[], const int n)
{
	cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++)
	{
		//����� ���������� ���������� � �������� �������������:
		*(arr + i) = rand() % 10000;
		*(arr + i) /= 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)	//i - �������� ������
	{
		for (int j = 0; j < cols; j++)	//j - �������� �������� ������
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)	//i - �������� ������
	{
		for (int j = 0; j < cols; j++)	//j - �������� �������� ������
		{
			arr[i][j] = rand() % 10000;
			arr[i][j] /= 100;
		}
	}
}

template<typename T>void Print(T arr[], const int n)
{
	cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++)
	{
		//����� �������� ��������������
		//[] - �������� �������������� (Subscript operator)
		cout << arr[i] << tab;
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
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

template<typename T>T* push_back(T* arr, int& n, T value)
{
	//1) ������� ����� ������ ������� �������:
	T* buffer = new T[n + 1];
	//2) �������� ��� ���������� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������:
	delete[] arr;
	//4) ��������� ����� � ��������� 'arr' ������� ������ �������:
	arr = buffer;
	//5) ������ ����� ����� ����� � ����� ������� 'arr' ����� �������� ��������:
	arr[n] = value;
	//6) ����� ���������� � ������ 'arr' ��������, ���������� ��� ��������� ������������� �� 1:
	n++;
	//7) Mission complete - ������� ��������!
	return arr;
}

template<typename T>T* push_front(T* arr, int& n, T value)
{
	T* buffer = new T[n + 1];
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
template<typename T>
T* insert(T* arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1];
	/*for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];*/
	for (int i = 0; i < n; i++)
	{
		//if (i < index)buffer[i] = arr[i];
		//else buffer[i + 1] = arr[i];
		//(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
		buffer[i < index ? i : i + 1] = arr[i];
	}
	buffer[index] = value;
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}

template<typename T>T* pop_back(T* arr, int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

template<typename T>T* pop_front(T* arr, int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	//1) ������� �������� ������ ����������:
	T** buffer = new T* [rows + 1];
	//2) �������� ������ ����� � ����� ������ ����������:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������ ����������:
	delete[] arr;
	//4) ��������� ����� � ��������� 'arr' ������� ������ �������:
	arr = buffer;
	//5) ������� ����� ������:
	arr[rows] = new T[cols] {};
	//6) ����� ���������� ������, ���������� ����� ������������� �� 1:
	rows++;
	//7) Mission complete - ������ ���������. ���������� ����� ������:
	return arr;
}

template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	//1) ������� �������� ������ ����������:
	T** buffer = new T * [rows + 1];
	//2) �������� ������ ����� � ����� ������ ����������:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������ ����������:
	delete[] arr;
	//4) ��������� ����� � ��������� 'arr' ������� ������ �������:
	arr = buffer;
	//5) ������� ����� ������:
	arr[rows] = new T[cols]{};
	//6) ����� ���������� ������, ���������� ����� ������������� �� 1:
	rows++;
	//7) Mission complete - ������ ���������. ���������� ����� ������:
	return arr;
}

template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	// ������� ��������� ������ �� ������
	delete[] arr[rows - 1];
	//�������������� ������ ����������
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

template<typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}