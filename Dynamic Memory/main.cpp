#include<iostream>
using namespace std;

//TODO:
//1. ������� ������ �� ����������.
//2. � ������ DynamicMemory �������� ��������� ������� :
//? ? ? insert(? ? ? );		//��������� � ������ ��������� �������� �� ���������� �������
//? ? ? pop_back(? ? ? );	//������� ��������� ������� �� �������
//? ? ? pop_front(? ? ? );	//������� ������� ������� �������
//? ? ? erase(? ? ? );		//������� ������� �� ���������� �������

#define tab "\t"
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int* arr, int &n, int value);
int* push_front(int* arr, int& n, int value);
int* insert(int* arr, int& n, int value, int index);	//��������� � ������ ��������� �������� �� ���������� �������
int* pop_back(int* arr, int& n);						//������� ��������� ������� �� �������
int* pop_front(int* arr, int& n);						//������� ������� ������� �������
int* erase(int* arr, int& n, int index);				//������� ������� �� ���������� �������

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
	cout << "***�������� ��������� �������***\n";
	cout << "������� ���������� ���������: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

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
	//6) ����� ���������� � ������ "arr" ��������, ����������
	n++;
	//7) Mission complete - ������� ��������
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