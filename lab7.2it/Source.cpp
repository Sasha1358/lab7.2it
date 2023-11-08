#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>
using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void Sort(int** a, const int n);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];

	Create(a, n, Low, High);
	cout << "Початковий масив:" << endl;
	Print(a, n);
	Sort(a, n);
	cout << "Відсортований масив:" << endl;
	Print(a, n);
		
		for (int i = 0; i < n; i++)
			delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** a, const int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			// Порівнюємо два сусідніх елементи
			if (a[j][j] > a[j + 1][j + 1]) {
				// Міняємо місцями елементи
				int temp = a[j][j];
				a[j][j] = a[j + 1][j + 1];
				a[j + 1][j + 1] = temp;
			}
		}
	}
}