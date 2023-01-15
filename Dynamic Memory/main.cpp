#include<iostream>
using namespace std;

//TODO:
//� ������ DynamicMemory �������� ��������� ������� :
//? ? ? push_row_front(? ? ? );	//��������� ������ � ������ �������
//? ? ? insert_row(? ? ? );		//��������� ������ � ������ �� ���������� �������

//? ? ? pop_row_back(? ? ? );		//������� ��������� ������ �� ���������� �������
//? ? ? pop_row_front(? ? ? );		//������� ������� ������ �� ���������� �������
//? ? ? erase_row(? ? ? );			//������� ������ �� ���������� ������� �� ���������� �������

#define tab "\t"
#define delimiter "\n-----------------------------------------------------------------------\n"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
int* push_back(int* arr, int &n, int value);
int** push_row_back(int** arr, int& rows, const int cols);
int* push_front(int* arr, int& n, int value);
int** push_row_front(int** arr, int& rows, const int cols);			//��������� ������ � ������ �������
int* insert(int* arr, int& n, int value, int index);				//��������� � ������ ��������� �������� �� ���������� �������
int** insert_row(int** arr, int& rows, const int cols, int index);	//��������� � ������ ��������� �������� �� ���������� �������
int* pop_back(int* arr, int& n);									//������� ��������� ������� �� �������
int** pop_row_back(int** arr, int& rows, const int cols);			//������� ��������� ������ �� ���������� �������
int* pop_front(int* arr, int& n);									//������� ������� ������� �������
int** pop_row_front(int** arr, int& rows, const int cols);			//������� ������� ������ �� ���������� �������
int* erase(int* arr, int& n, int index);							//������� ������� �� ���������� �������
int** erase_row(int** arr, int& rpws, const int cols, int index);	//������� ������ �� ���������� ������� �� ���������� �������

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
	cout << "***�������� ��������� �������***\n";
	cout << "������� ���������� ���������: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
#endif

#ifdef PUSH_BACK
	cout << "\n***���������� �������� � ����� �������***\n";
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
#endif

#ifdef PUSH_FRONT
	cout << "\n***���������� �������� � ������ �������***\n";
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
#endif

#ifdef INSERT
	cout << "\n***���������� �������� �� ������ ������***\n";
	cout << "������� ����������� ��������: "; cin >> value;
	do
	{
		cout << "������� ������ ������ ��� ����� �������� (��������� � 0): "; cin >> index;
		if (index >= n) cout << "\n��������! ����� ������ �� ����������! ���������� ��� ���.\n";
	} while (index >= n);
	arr = insert(arr, n, value, index);
	Print(arr, n);
#endif

#ifdef POP_BACK
	cout << "\n***�������� ��������� ������ �������***\n";
	arr = pop_back(arr, n);
	Print(arr, n);
#endif

#ifdef POP_FRONT
	cout << "\n***�������� ������ ������ �������***\n";
	arr = pop_front(arr, n);
	Print(arr, n);
#endif

#ifdef ERASE
	cout << "\n***�������� ������ �� � ������***\n";
	do
	{
		cout << "\n������� ������ ������, ������� ����� ������� (��������� � 0): "; cin >> index;
		if (index >= n) cout << "\n��������! ����� ������ �� ����������! ���������� ��� ���.\n";
	} while (index >= n);
	arr = erase(arr, n, index);
	Print(arr, n);
#endif

	//delete[] arr;
	//Memory leak

#ifdef DYNAMIC_MEMORY_2
	int rows, cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;

	int** arr = new int* [rows]; // ������� ������ ����������
	for (int i = 0; i < rows; i++)
	{
		// ������� ������ ���������� �������
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
	cout << "������� ������ ������, ������� ����� �������� � ������: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "������� ������ ��������� ������: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	//������� ������ ���������� �������
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//������� ������ ����������
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
	//1) ������� ����� ������ ������� �������
	int* buffer = new int[n + 1];
	//2) �������� ��� ���������� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������:
	delete[] arr;
	//4) ��������� ����� � ��������� "arr" ������� ������ �������:
	arr = buffer;
	//5) ������ ����� ����� ����� � ����� ������� "arr" ����� �������� ��������:
	arr[n] = value;
	//6) ����� ���������� � ������ "arr" ��������, ���������� ��� ��������� ������������� �� 1
	n++;
	//7) Mission complete - ������� ��������
	return arr;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	// 1) ������� �������� ������ ����������:
	int** buffer = new int* [rows + 1];
	// 2) �������� ������ ����� � ����� ������ ����������:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) ������� �������� ������ ����������:
	delete[] arr;
	// 4) ��������� ����� ���������� 'arr' ������� ������ �������:
	arr = buffer;
	// 5) ������� ����� ������:
	buffer[rows] = new int [cols] {};
	// 6) ����� ���������� ������, ���������� ����� ������������� �� 1
	rows++;
	// 7) Mission complete - ������ ���������. ���������� ����� ������.
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
	int** buffer = new int* [rows + 1];		// 1) ������� �������� ������ ����������.
	for (int i = 0; i < rows; i++)			// 2) �������� ������ ����� � ����� ������ ����������.
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;							// 3) ������� �������� ������ ����������
	arr = buffer;							// 4) ��������� ����� ���������� 'arr' ������� ������ �������.
	buffer[0] = new int [cols] {};			// 5) ������� ����� ������.
	rows++;									// 6) ����� ���������� ������, ���������� ����� ������������� �� 1
	return arr;								// 7) Mission complete - ������ ���������. ���������� ����� ������.
}

int* insert(int* arr, int& n, int value, int index)		//��������� � ������ ��������� �������� �� ���������� �������
{
	int* buffer = new int[n + 1];				//������� ����� ����������� ������
	for (int i = 0; i < n + 1; i++)				//���� �������� ������ �� ��������� ������� � ���������
	{
		if (i < index) buffer[i] = arr[i];		//������� ������ �� ��������� �������
		else if (i == index) buffer[i] = value;	//���������� ������ � �������� ��������
		else buffer[i] = arr[i - 1];			//������� ������ ����� ��������� �������
	}
	delete[] arr;								//�������� ��������� �������
	arr = buffer;								//������������ ��������� ����� ������ �������
	n++;										//���������� ������� �������
	return arr;									//�������
}

int** insert_row(int** arr, int& rows, const int cols, int index)			//��������� � ������ ��������� �������� �� ���������� �������
{
	if (index > rows)				//���� ������ ������ ���������� �����, ������� �� �������.
	{
		cout << "��������! ��������� ������ ��������� ������ �������. ������ ������� ����������." << endl;
		return arr;
	}
	int** buffer = new int* [rows + 1];		// 1) ������� �������� ������ ����������.
	for (int i = 0; i < rows; i++)			// 2) �������� ������ ����� � ����� ������ ����������.
	{
		buffer[(i < index) ? i : i + 1] = arr[i];
	}
	delete[] arr;							// 3) ������� �������� ������ ����������.
	arr = buffer;							// 4) ��������� ����� ���������� 'arr' ������� ������ �������.
	buffer[index] = new int [cols] {};		// 5) ������� ����� ������.
	rows++;									// 6) ����������� ���������� ����� � �������.
	return arr;								// 7) ���������� ���������.
}

int* pop_back(int* arr, int& n)		//������� ��������� ������� �� �������
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

int* pop_front(int* arr, int& n)	//������� ������� ������� �������
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

int* erase(int* arr, int& n, int index)		//������� ������� �� ���������� �������
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
