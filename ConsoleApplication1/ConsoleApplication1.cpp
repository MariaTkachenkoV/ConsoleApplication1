
#include <iostream>

using namespace std;
void printArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
void print1D(int* a, int size) {
	for (int i = 0; i < size; i++) {
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
bool testOne(int num) {
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
			y *= 3;
		}
		if (i % 2 == 0) 
		{
			a[i] = x;
			x *= 2;
		}
		if (testOne(a[i]))
		{
			count++;
		}
	}
	printArray(a, 16);
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
		}
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
char* newStrncpy(char* S, const char* source, size_t num) {
	for (int i = 0; i < num; i++) {
		S[i] = source[i];
	}
	return S;
}

int main()
{
	cout << "Select number from 1-3" << endl;
	int number = 0;
	cin >> number;
	switch (number)
	{
	case 1: {
		int a[16] = {};
		for (int i = 0; i < 16; i++) {
			a[i] = 1;
		}
		int b[16] = {};
		int cnt = 0;
		printf("First array:\n");
		cnt = processArray(a,b);	
		printf("Second array:\n");
		printArray(b, 16);
		printf("cnt = %d",cnt);
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
	case 3: {
		char dest[50];
		const char src[50] = { "Hello10000011World10000011" };
		strncpy(dest, src, 10);
		printf(dest);
		newStrncpy(dest, src, 20);
		printf("\n");
		printf(dest);
	}
	 default:
		break;
	}
}
