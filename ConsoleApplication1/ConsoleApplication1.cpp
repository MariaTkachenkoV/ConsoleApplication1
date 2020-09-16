// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
void print1D(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void print2D(int** a, int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << a[i][j] << "     ";
		}
		cout << endl;
	}
}
bool test1(int num) {
	do {
		int tmp = num % 10;
		if (tmp == 1) {
			return true;
		}
		else
		{
			num /= 10;
		}
	} while (num != 0);
	return false;
}
int processArray(int a[], int b[])
{
	int x = 1;
	int y = 3;
	int count = 0;
	for (int i = 0; i < 16; ++i) 
	{
		if (i % 2 != 0) 
		{
			a[i] = y;
			y = y * 3;
		}
		if (i % 2 == 0) 
		{
			a[i] = x;
			x = x * 2;
		}
		if (test1(a[i]))
		{
			count++;
		}
		cout << a[i] << " ";
	}
	cout << endl;
		int j = 0;
		int tmp = 0;
		for (int i = 0; i < 16; i++) 
		{
			j = i;
			for (int k = i; k < 16; k++) {
				if (a[j] > a[k]) {
					j = k;
				}
			}
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			b[i] = a[i];
			cout << b[i] << " ";
		}
		cout << endl;
	return count;
}
void makeArray(int* a,int n) 
{
	for (int i = 0; i < n; i++) {
		a[i] = (i * i) - 1;
		if ((i+1) % 2 != 0)
		{
			a[i] *= -1;
		}
	}
	print1D(a, n);
}
void makeNew(int* a,int**b, int n) 
{
	int j, tmp = 0;
	for (int i = 0; i < n; i++)
	{
		j = i;
		for (int k = i; k < n; k++) {
			if (a[j] < a[k]) {
				j = k;
			}
		}
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	print1D(a, n);
	cout << endl;
	int k = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			b[i][j] = a[k];
			k++;
		}
	}
	print2D(b, 6, 3);
}

int main()
{
	cout << "Select number from 1-3" << endl;
	int number = 0;
	cin >> number;
	switch (number)
	{
	case 1: {
		int a[16] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
		int b[16] = {};
		int cnt = 0;
		cnt = processArray(a,b);
		cout << cnt << endl;
			break;
	}
	case 2: {
		cout << "Enter arrays lenght\n";
		int n = 0;
		cin >> n;
		int* a = new int[n];
		int** b = new int* [6];
		for (int i = 0; i < 6; i++) {
			b[i] = new int[3];
		}
		makeArray(a, n);
		makeNew(a, b, n);
	}
	 default:
		break;
	}
	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
