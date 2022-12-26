#include <iostream>
#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
struct Record
{
    int key;
	int mau;
};
void Swap(Record &a, Record &b)
{
	Record temp = a;
	a = b;
	b = temp;
}

void ComparisionCounting(Record M[], int N)
{
	cout << "Nhap n: "; cin >> N;
	cout << "Nhap Key[]: ";
	for (int i = 0; i < N; i++)
	{
		cin >> M[i].key;
	}
	system("cls");
	Sleep(500);
	gotoxy(0, 1); printf("KEY: ");
	Sleep(500);
	for (int i = 0; i < N; i++)
	{
		box((i + 1) * 15, 0, 2, 11, M[i].key, 0, 0);
		Sleep(200);
		/*printf("%d ", M[i].key);*/
	}

	int* COUNT = (int*)malloc(sizeof(int));
	for (int i = 0; i < N; i++)
	{
		COUNT[i] = 0;
	}
	gotoxy(0, 8); printf("COUNT: ");
	Sleep(500);
	for (int k = 0; k < N; k++)
	{
		box((k + 1) * 15, 7, 2, k + 4, COUNT[k], 0, 0);
		Sleep(200);
		/*printf("%d ", COUNT[k]);*/
	}
	for (int i = N - 1; i >= 1; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			box((i + 1) * 15, 0, 2, 11, M[i].key, 1, 1);
			Sleep(200);
			box((j + 1) * 15, 0, 2, 11, M[j].key, 1, 0);
			Sleep(200);
			if (M[i].key <= M[j].key)
			{
				Sleep(500);
				gotoxy(15, 12);
				printf("%d <= %d", M[i].key, M[j].key);
				Sleep(800);
				gotoxy(15, 13);
				printf("COUNT[j] = COUNT[j] + 1");
				Sleep(500);
				COUNT[j]++;
				box((j + 1) * 15, 7, 2, j + 4, COUNT[j], 1, 0);
				Sleep(200);
			}
			else
			{
				Sleep(500);
				gotoxy(15, 12);
				printf("%d >  %d", M[i].key, M[j].key);
				Sleep(500);
				gotoxy(15, 13);
				printf("=> COUNT[i] = COUNT[i] + 1");
				Sleep(700);
				COUNT[i]++;
				box((i + 1) * 15, 7, 2, i + 4, COUNT[i], 1, 1);
				Sleep(500);
			}
			box((i + 1) * 15, 0, 2, 11, M[i].key, 0, 1);
			box((j + 1) * 15, 0, 2, 11, M[j].key, 0, 0);
			box((j + 1) * 15, 7, 2, j + 4, COUNT[j], 0, 0);
			box((i + 1) * 15, 7, 2, i + 4, COUNT[i], 0, 0);
			gotoxy(15, 12);
			printf("                                       ");
			gotoxy(15, 13);
			printf("                                       ");
			Sleep(200);
		}
		//for (int k = 0; k < N; k++)
		//{
		//    box((k + 1) * 10, 5, 2, k+5, COUNT[k]);
		//    Sleep(200);
		//    /*printf("%d ", COUNT[k]);*/
		//}
	}
	Sleep(1000);
	for (int k = 0; k < N; k++)
	{
		box((k + 1) * 15, 7, 2, 4, COUNT[k], 0, 0);
		Sleep(200);
		/*printf("%d ", COUNT[k]);*/
	}
	// di chuyen box
	gotoxy(0, 8); printf("       ");
	Sleep(500);
	for (int k = 0; k < N; k++)
	{
		int i, j;
		for (i = 0; i < 4; i++)
		{
			box((k + 1) * 15, 7 - i, 2, 4, COUNT[k], 0, 0);
			Sleep(100);
			/*printf("%d ", COUNT[k]);*/
		}
		for (j = 0; j < 3; j++)
		{
			box((k + 1) * 15 - j, 7 - i, 2, 4, COUNT[k], 0, 0);
			Sleep(100);
			xoabox((k + 1) * 15 - j, 7 - i, 2, COUNT[k]);
			/*printf("%d ", COUNT[k]);*/
		}
		for (i = 0; i < 4; i++)
		{
			box((k + 1) * 15 - j, 3 - i, 2, 4, COUNT[k], 0, 0);
			Sleep(100);
			/*printf("%d ", COUNT[k]);*/
		}
	}
	int A[100];
	for (int i = 0; i < N; i++)
	{
		A[COUNT[i]] = M[i].key;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (COUNT[j] == i)
			{
				for (int k = 0; k < 3; k++)
				{
					gotoxy(0, 10); printf("KQ: ");
					xoabox((j + 1) * 15, 0, 2, M[j].key);
					xoabox((i + 1) * 15, 9, 2, A[i]);
					Sleep(200);
					box((j + 1) * 15, 0, 2, 8, M[j].key, 0, 0);
					box((i + 1) * 15, 9, 2, 8, A[i], 0, 0);
					Sleep(200);
				}
			}
		}
	}

	/*Sleep(200);
	gotoxy(0, 10); printf("KQ: ");
	Sleep(500);
	int A[100];
	for (int i = 0; i < N; i++)
	{
		A[COUNT[i]] = M[i].key;
	}*/
	Sleep(200);
	gotoxy(0, 10); textcolor(7); printf("KQ: ");
	Sleep(500);
	for (int i = 0; i < N; i++)
	{
		box((i + 1) * 15, 9, 2, 5, A[i], 0, 0);
		Sleep(100);
	}
	Sleep(1000);
	system("cls");
	Sleep(500);
	for (int i = 0; i < N; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, A[i], 15, (i + 1) * 25);
		Sleep(100);
		xoabox_ShellSort((i + 3) * 7, 25, 5, A[i]);
		Sleep(100);
	}
	for (int i = 0; i < N; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, A[i], 15, (i + 1) * 25);
		Sleep(100);
		xoabox_ShellSort((i + 3) * 7, 25, 5, A[i]);
		Sleep(100);
	}
	for (int i = 0; i < N; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, A[i], 15, (i + 1) * 25);
	}
}


void ShellSort(Record A[], int N)
{
	cout << "Nhap n: "; cin >> N;
	cout << "Nhap Key[]: ";
	for (int i = 0; i < N; i++)
	{
		cin >> A[i].key;
	}
	system("cls");
	Sleep(500);
	for (int i = 0; i < N; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, A[i].key, 15, (i + 1) * 25);
	}
	for (int i = 0; i < N; i++)
	{
		A[i].mau = (i + 1) * 25;
	}
	Sleep(500);
	int i, s, j, h, K, t = N - 1;
	int arrH[100];
	Record R;

	for (i = t - 1; i >= 0; i--)
	{
		arrH[i] = i;
	}
	/*int dem = 0;
	i = 1;
	while (i <= t)
	{
		arrH[dem] = i;
		dem++;
		i = i * 2;
	}*/
	for (s = t -1; s >= 1; s--)
	{
		h = arrH[s];
		gotoxy(100, 27); cout << "h = " << h;
		for (j = h; j < N; j++)
		{
			i = j - h;
			K = A[j].key;
			R = A[j];
			bool flag = false;
			for (int k = 0; k < 2; k++)
			{
				xoabox_ShellSort((i + 3) * 7, 25, 5, A[i].key);
				xoabox_ShellSort((j + 3) * 7, 25, 5, A[j].key);
				Sleep(200);
				box_ShellSort((i + 3) * 7, 25, 5, A[i].key, 15, A[i].mau);
				box_ShellSort((j + 3) * 7, 25, 5, A[j].key, 15, A[j].mau);
				Sleep(200);
			}
			while (K < A[i].key && i >= 0)
			{
				gotoxy(100, 28); cout << "              ";
				flag = true;
				A[i + h] = A[i];
				for (int k = 0; k < 2; k++)
				{
					xoabox_ShellSort((i + h + 3) * 7, 25, 5, A[i+h+h].key);
					Sleep(200);
					box_ShellSort((i + h + 3) * 7, 25, 5, A[i].key, 15, A[i].mau);
					Sleep(200);
				}
				i = i - h;
				gotoxy(100, 28); cout << "i = " << i;
				Sleep(1000);
			}
			A[i + h] = R;
			if (flag) {
				for (int k = 0; k < 2; k++)
				{
					xoabox_ShellSort((i + h + 3) * 7, 25, 5, A[i + h + h].key);
					Sleep(200);
					box_ShellSort((i + h + 3) * 7, 25, 5, R.key, 15, R.mau);
					Sleep(200);
				}
			}
			gotoxy(100, 28); cout << "              ";
		}
		for (int i = 0; i < N; i++)
		{
			box_ShellSort((i + 3) * 7, 25, 5, A[i].key, 15, A[i].mau);
		}
	}
	for (int i = 0; i < N; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, A[i].key, 15, A[i].mau);
	}
}

void SelectionSort(Record A[], int N)
{
	cout << "Nhap n: "; cin >> N;
	cout << "Nhap Key[]: ";
	for (int i = 0; i < N; i++)
	{
		cin >> A[i].key;
	}
	system("cls");
	Sleep(500);
	int i, j;
	Record temp;
	for (int i = 0; i < N; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, A[i].key, 15, (i + 1) * 25);
		Sleep(100);
	}
	for (int i = 0; i < N; i++)
	{
		A[i].mau = (i + 1) * 25;
	}
	Sleep(500);
	for (j = N - 1; j >= 1; j--)
	{
		int max = A[j].key;
		int vt = j;
		for (i = j-1; i >= 0; i--)
		{
			if (max < A[i].key)
			{
				max = A[i].key;
				vt = i;
			}
		}
		for (int h = 0; h < 3; h++)
		{
			xoabox_ShellSort((vt + 3) * 7, 25, 5, A[vt].key);
			Sleep(200);
			box_ShellSort((vt + 3) * 7, 25, 5, A[vt].key, 15, A[vt].mau);
			Sleep(200);
		}
		for (int h = 0; h < 3; h++)
		{
			xoabox_ShellSort((vt + 3) * 7, 25, 5, A[vt].key);
			Sleep(200);
			box_ShellSort((vt + 3) * 7, 25, 5, A[vt].key, 15, A[vt].mau);
			box_ShellSort((j + 3) * 7, 25, 5, A[j].key, 15, A[j].mau);
			Sleep(200);
			xoabox_ShellSort((vt + 3) * 7, 25, 5, A[vt].key);
			xoabox_ShellSort((j + 3) * 7, 25, 5, A[j].key);
		}
		/*temp = A[j];
		A[j] = A[vt];
		A[vt] = temp;*/
		Swap(A[j], A[vt]);
		for (int h = 0; h < 5; h++)
		{
			xoabox_ShellSort((j + 3) * 7, 25, 5, A[j].key);
			xoabox_ShellSort((vt + 3) * 7, 25, 5, A[vt].key);
			Sleep(200);
			box_ShellSort((j + 3) * 7, 25, 5, A[j].key, 15, A[j].mau);
			box_ShellSort((vt + 3) * 7, 25, 5, A[vt].key, 15, A[vt].mau);
			Sleep(200);
		}
	}
	system("cls");
	for (int i = 0; i < N; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, A[i].key, 15, A[i].mau);
		Sleep(100);
		xoabox_ShellSort((i + 3) * 7, 25, 5, A[i].key);
		Sleep(100);
	}
	for (int i = 0; i < N; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, A[i].key, 15, A[i].mau);
		Sleep(100);
		xoabox_ShellSort((i + 3) * 7, 25, 5, A[i].key);
		Sleep(100);
	}
	for (int i = 0; i < N; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, A[i].key, 15, A[i].mau);
	}
	_getch();
}


void merge(int arr[], int l, int m, int r, int size)
{
	for (int i = 0; i < 2; i++)
	{
		for (int i = l; i <= r; i++)
		{
			xoabox_ShellSort((i + 3) * 7, 25, 5, arr[i]);
		}Sleep(200);
		for (int i = l; i <= m; i++)
		{
			box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, 25 * (m + 2));
		}
		for (int i = m+1; i <= r; i++)
		{
			box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, 25 * (m + 2));
		}
		Sleep(200);
	}
	//for (int i = 0; i <= size - 1; i++)
	//{
	//	box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, (i + 1) * 25);
	//}

	// Create L ← A[p..q] and M ← A[q+1..r]
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[100], M[100];

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int i = l; i <= m; i++)
	//	{
	//		xoabox_ShellSort((i + 3) * 7, 25, 5, arr[i]);
	//	}
	//	Sleep(200);
	//	for (int i = l; i <= m; i++)
	//	{
	//		box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, 25 * (m + 3));
	//	}
	//	Sleep(200);
	//}


	for (int j = 0; j < n2; j++)
		M[j] = arr[m + 1 + j];
	/*for (int i = 0; i < 3; i++)
	{
		for (int i = m + 1; i <= r; i++)
		{
			xoabox_ShellSort((i + 3) * 7, 25, 5, arr[i]);
		}Sleep(200);
		for (int i = m+1; i <= r; i++)
		{
			box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, 25 * (m + 3));
		}Sleep(200);
	}*/

	// Maintain current index of sub-arrays and main array
	int i, j, k;
	i = 0;
	j = 0;
	k = l;

	// Until we reach either end of either L or M, pick larger among
	// elements L and M and place them in the correct position at A[p..r]
	while (i < n1 && j < n2) {
		if (L[i] <= M[j]) {
			xoabox_ShellSort((k + 3) * 7, 25, 5, arr[k]);
			arr[k] = L[i];
			box_ShellSort((k + 3) * 7, 25, 5, arr[k], 15, 25 * (m + 2));
			i++;
		}
		else {
			xoabox_ShellSort((k + 3) * 7, 25, 5, arr[k]);

			arr[k] = M[j];
			box_ShellSort((k + 3) * 7, 25, 5, arr[k], 15, 25 * (m + 2));

			j++;
		}
		k++;
	}
	// When we run out of elements in either L or M,
	// pick up the remaining elements and put in A[p..r]
	while (i < n1) {
		xoabox_ShellSort((k + 3) * 7, 25, 5, arr[k]);

		arr[k] = L[i];
		box_ShellSort((k + 3) * 7, 25, 5, arr[k], 15, 25 * (m + 2));

		i++;
		k++;
	}

	while (j < n2) {
		xoabox_ShellSort((k + 3) * 7, 25, 5, arr[k]);

		arr[k] = M[j];
		box_ShellSort((k + 3) * 7, 25, 5, arr[k], 15, 25 * (m + 2));

		j++;
		k++;
	}
	//for (int i = l; i <= r; i++)
	//{
	//	cout << arr[i] << " ";
	//}
	for (int i = 0; i < 2; i++)
	{
		for (int i = l; i <= r; i++)
		{
			xoabox_ShellSort((i + 3) * 7, 25, 5, arr[i]);
		}Sleep(200);
		for (int i = l; i <= r; i++)
		{
			box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, 25 * (m + 2));
		}Sleep(200);
	}
	Sleep(1000);
}
// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r, int size) {
	if (l < r) {
		// m is the point where the array is divided into two subarrays
		int m = l + (r - l) / 2;
		for (int i = 0; i < 2; i++)
		{
			for (int i = l; i <= m; i++)
			{
				xoabox_ShellSort((i + 3) * 7, 25, 5, arr[i]);
			}Sleep(200);
			for (int i = l; i <= m; i++)
			{
				box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, 25*(m+2));
			}Sleep(200);
		}
		for (int i = 0; i < 2; i++)
		{
			for (int i = m+1; i <= r; i++)
			{
				xoabox_ShellSort((i + 3) * 7, 25, 5, arr[i]);
			}Sleep(200);
			for (int i = m+1; i <= r; i++)
			{
				box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, 25*(r+4));
			}Sleep(200);
		}
		mergeSort(arr, l, m, size);

		mergeSort(arr, m + 1, r, size);

		// Merge the sorted subarrays
		merge(arr, l, m, r, size);
	}
}

void MERGE()
{
	//int arr[] = { 6, 3, 12, 10, 9, 14,5,4};
	//int size = sizeof(arr) / sizeof(arr[0]);
	int arr[100];
	int size;
	cout << "Nhap n:"; cin >> size;
	cout << "Nhap KEY[]: ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	system("cls");
	Sleep(500);
	ShowCur(0);
	for (int i = 0; i <= size - 1; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, (i + 2) * 25);
		Sleep(50);
		xoabox_ShellSort((i + 3) * 7, 25, 5, arr[i]);
		Sleep(50);
	}
	for (int i = 0; i <= size - 1; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, (i + 2) * 25);
		Sleep(50);
		xoabox_ShellSort((i + 3) * 7, 25, 5, arr[i]);
		Sleep(50);
	}
	for (int i = 0; i <size; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, (i + 2) * 25);
	}Sleep(2000);

	mergeSort(arr, 0, size - 1, size);

	//for (int i = 0; i < size; i++)
	//	cout << arr[i] << " ";
	//cout << endl;
	for (int i = 0; i <= size - 1; i++)
	{
		xoabox_ShellSort((i + 3) * 7, 25, 5, arr[i]);
	}

	for (int i = 0; i <= size - 1; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, (i + 2) * 25);
		Sleep(100);
		xoabox_ShellSort((i + 3) * 7, 25, 5, arr[i]);
		Sleep(100);
	}
	for (int i = 0; i <= size - 1; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, (i + 2) * 25);
	}
}

void MERGE_hopnhat()
{
	int X[100];
	int m;
	int Y[100];
	int n;
	int Z[200];
	cout << "Nhap m:"; cin >> m;
	cout << "Nhap mang X: ";
	for (int i = 0; i < m; i++) cin >> X[i];
	cout << "Nhap n:"; cin >> n;
	cout << "Nhap mang Y: ";
	for (int i = 0; i < n; i++) cin >> Y[i];
	system("cls");
	Sleep(500);
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	gotoxy(0, 1); 
	textcolor(7);
	cout << "Mang X:"; 
	Sleep(200); 
	textcolor(7);
	for (int i = 0; i < m; i++)
	{
		box((i + 1) * 15, 0, 2, 11, X[i], 0, 1);
		Sleep(200);
	}
	gotoxy(0, 8); 
	textcolor(7);
	cout << "Mang Y:";
	Sleep(200);
	textcolor(7);
	for (int j = 0; j < n; j++)
	{
		box((j + 1) * 15, 7, 2, 11, Y[j], 0, 1);
		Sleep(200);
	}


	while (i < m && j < n) {
		if (X[i] <= Y[j]) {
			Z[k] = X[i];
			for (int dem = 0; dem < 4; dem++)
			{
				box((i + 1) * 15, 0, 2, 11, X[i], 0, 1);
				box((j + 1) * 15, 7, 2, 11, Y[j], 0, 0);
				Sleep(200);
				xoabox((i + 1) * 15, 0, 2, X[i]);
				xoabox((j + 1) * 15, 7, 2, Y[j]);
				Sleep(200);
			}
			box((i + 1) * 15, 0, 2, 11, X[i], 0, 1);
			box((j + 1) * 15, 7, 2, 11, Y[j], 0, 0);

			Sleep(500);
			gotoxy(15, 12);
			printf("%d <= %d", X[i] , Y[j]);
			Sleep(500);
			gotoxy(15, 13);
			printf("Z[k] = X[i]");
			Sleep(500);
			gotoxy(15, 12);
			printf("                                       ");
			gotoxy(15, 13);
			printf("                                       ");
			box((i + 1) * 15, 0, 2, 11, X[i], 0, 0);
			box((k + 1) * 15, 16, 2, 11, Z[k], 0, 0);
			for (int dem = 0; dem < 4; dem++)
			{
				box((i + 1) * 15, 0, 2, 11, X[i], 0, 0);
				box((k + 1) * 15, 16, 2, 11, Z[k], 0, 0);
				Sleep(200);
				xoabox((i + 1) * 15, 0, 2, X[i]);
				xoabox((k + 1) * 15, 16, 2, Z[k]);
				Sleep(200);
			}
			box((i + 1) * 15, 0, 2, 11, X[i], 1, 1);
			box((k + 1) * 15, 16, 2, 11, Z[k], 1, 1);
			i++;
		}
		else {
			Z[k] = Y[j];
			for (int dem = 0; dem < 4; dem++)
			{
				box((i + 1) * 15, 0, 2, 11, X[i], 0, 1);
				box((j + 1) * 15, 7, 2, 11, Y[j], 0, 0);
				Sleep(200);
				xoabox((i + 1) * 15, 0, 2, X[i]);
				xoabox((j + 1) * 15, 7, 2, Y[j]);
				Sleep(200);
			}
			box((i + 1) * 15, 0, 2, 11, X[i],0, 1);
			box((j + 1) * 15, 7, 2, 11, Y[j], 0, 0);
			Sleep(500);
			gotoxy(15, 12);
			printf("%d > %d", X[i], Y[j]);
			Sleep(500);
			gotoxy(15, 13);
			printf("Z[k] = Y[j] ");
			Sleep(500);
			box((j + 1) * 15, 7, 2, 11, Y[j], 0, 0);
			box((k + 1) * 15, 16, 2, 11, Z[k], 0, 0);
			for (int dem = 0; dem < 4; dem++)
			{
				box((j + 1) * 15, 7, 2, 11, Y[j], 0, 0);
				box((k + 1) * 15, 16, 2, 11, Z[k], 0, 0);
				Sleep(200);
				xoabox((j + 1) * 15,7, 2, Y[j]);
				xoabox((k + 1) * 15, 16, 2, Z[k]);
				Sleep(200);
			}
			box((j + 1) * 15, 7, 2, 11, Y[j], 1, 0);
			box((k + 1) * 15, 16, 2, 11, Z[k], 1, 0);
			j++;
		}
		k++;
	}

	// When we run out of elements in either L or M,
	// pick up the remaining elements and put in A[p..r]
	while (i < m) {
		Z[k] = X[i];
		for (int dem = 0; dem < 3; dem++)
		{
			box((i + 1) * 15, 0, 2, 11, X[i], 0, 0);
			box((k + 1) * 15, 16, 2, 11, Z[k], 0, 0);
			Sleep(100);
			xoabox((i + 1) * 15, 0, 2, X[i]);
			xoabox((k + 1) * 15, 16, 2, Z[k]);
			Sleep(100);
		}
		box((i + 1) * 15, 0, 2, 11, X[i], 1, 1);
		box((k + 1) * 15, 16, 2, 11, Z[k], 1, 1);
		i++;
		k++;
	}
	while (j < n) {
		Z[k] = Y[j];
		for (int dem = 0; dem < 3; dem++)
		{
			box((j + 1) * 15, 7, 2, 11, Y[j], 0, 0);
			box((k + 1) * 15, 16, 2, 11, Z[k], 0, 0);
			Sleep(100);
			xoabox((j + 1) * 15, 7, 2, Y[j]);
			xoabox((k + 1) * 15, 16, 2, Z[k]);
			Sleep(100);
		}
		box((j + 1) * 15, 7, 2, 11, Y[j], 1, 0);
		box((k + 1) * 15, 16, 2, 11, Z[k], 1, 0);
		j++;
		k++;
	}
	Sleep(10000);
	system("cls");
}

int partition(int arr[], int low, int high, int pivot) {
	int PIndex = low;

	// Traverse the array from low to high
	for (int i = low; i <= high; i++) {
		// If the current element is smaller than the pivot element
		if (arr[i] <= pivot) {
			// Swap PIndex element with current element.
			for (int h = 0; h < 2; h++)
			{
				Sleep(200);
				box_ShellSort((PIndex + 3) * 7, 25, 5, arr[PIndex], 15, 25 * (PIndex + 1));
				box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, 25 * (i + 1));
				Sleep(200);
				xoabox_ShellSort((PIndex + 3) * 7, 25, 5, arr[PIndex]);
				xoabox_ShellSort((i + 3) * 7, 25, 5, arr[i]);
			}
			swap(arr[PIndex], arr[i]);
			for (int h = 0; h < 2; h++)
			{
				xoabox_ShellSort((PIndex + 3) * 7, 25, 5, arr[PIndex]);
				xoabox_ShellSort((i + 3) * 7, 25, 5, arr[i]);
				Sleep(200);
				box_ShellSort((PIndex + 3) * 7, 25, 5, arr[PIndex], 15, 25 * (PIndex + 1));
				box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, 25 * (i + 1));
				Sleep(200);
			}
			PIndex++;
		}
	}

	PIndex--;

	return PIndex;
}

// We divide the array into two subarrays around 
// the pivot and recursively call for them separately.
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = arr[high];

		//Rearrange and get the actual pivot index
		int PIndex = partition(arr, low, high, pivot);


		// solve for the left and right subarrays
		quickSort(arr, low, PIndex - 1);

		/*for (int i = 0; i < n; i++)
		{
			xoabox_ShellSort((i + 3) * 7, 25, 5, arr[i]);
		}
		Sleep(200);
		for (int i = 0; i < n; i++)
		{
			box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, 25 * (i + 1));
		}*/

		quickSort(arr, PIndex + 1, high);
	}
}
void QUICKSORT()
{
	int arr[100]; int n;
	cout << "Nhap n: "; cin >> n;
	cout << "Nhap Key[]: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	system("cls");
	Sleep(500);

	for (int i = 0; i < n; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, 25 * (i + 1));
	}
	Sleep(500);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, arr[i], 15, 25 * (i + 1));
	}
	/*cout << "The sorted array is: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}*/
}


struct Data
{
	int l, r;
	Data* next;
};
void swap(Record& a, Record& b)
{
	Record temp = a;
	a = b;
	b = temp;
}
struct STACK {
	Data* top;

	void init() { top = nullptr; }
	bool isEmpty() { return top == nullptr; }
	bool insertNode(int l, int r) {
		Data* x = new Data();
		x->l = l;
		x->r = r;
		x->next = nullptr;
		if (top == nullptr) {
			top = x;
			return true;
		}
		x->next = top;
		top = x;
		return true;
	}
	Data* deleteNode() {
		if (top == nullptr) return nullptr;

		Data* result = new Data();
		result->l = top->l;
		result->r = top->r;
		result->next = nullptr;

		Data* temp = top->next;
		delete top;
		top = temp;

		return result;
	}
};

bool check(Record R[], int N) {
	for (int i = 2; i <= N; ++i)
		if (R[i - 1].key > R[i].key) return false;
	return true;
}


void QuickSort(Record R[], int N)
{
	cout << "Nhap n: "; cin >> N;
	cout << "Nhap Key[]: ";
	for (int i = 1; i <= N; i++)
	{
		cin >> R[i].key;
	}
	system("cls");
	Sleep(500);
	//draw2(R, N, -1, -1, -1);
	for (int i = 1; i <= N; i++)
	{
		R[i].mau = (i + 1)*25 ;
	}
	for (int i = 1; i <=N; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, R[i].key, 15, R[i].mau);
	}
	int M = 1, l = 1, r = N;
	/*gotoxy(95, 20); cout << "l = " << l << "    ";
	gotoxy(95, 21); cout << "r = " << r << "    ";
	Sleep(500);*/
	STACK s; s.init();
	s.insertNode(1, N);

	int dem = 0;
	while (!s.isEmpty())
	{
		int i = l, j = r + 1;
		/*gotoxy(95, 25); cout << "i = " << i <<"    ";
		gotoxy(95, 26); cout << "j = " << j << "    ";
		Sleep(500);*/
		Record P = R[l];

		while (j > i)
		{
			//gotoxy(95, 27); cout << "i < j "; Sleep(1000);
			i++;
			//gotoxy(95, 25); cout << "i = " << i << "    "; Sleep(500);

			//draw2(R, N, l, -1, i);
			/*if (R[i].key < P.key)
			{
				gotoxy(95, 28); cout << "P.key < R[j].key"; Sleep(1000);
			}
			gotoxy(95, 28); cout << "                      "; Sleep(500);*/

			while (R[i].key < P.key)
			{
				i++;

				//if (i >= 1 && i <= N)
				//{
				////	//draw2(R, N, l, -1, i);
				//	gotoxy(95, 25); cout << "i = " << i << "    "; Sleep(500);
				//}
			}

			j--;
			//gotoxy(95, 26); cout << "j = " << j << "    "; Sleep(500);
			//draw2(R, N, l, j, -1);
			/*if (P.key < R[j].key)
			{
				gotoxy(95, 28); cout << "P.key < R[j].key";
				Sleep(2000);
			}
			gotoxy(95, 28); cout << "                      "; Sleep(500);*/

			while (P.key < R[j].key)
			{
				j--;
				//gotoxy(95, 26); cout << "j = " << j << "    "; Sleep(500);
				//draw2(R, N, l, j, -1);
			}

			if (j > i)
			{
				//gotoxy(95, 27); cout << "i < j "; Sleep(500);
				for (int h = 0; h < 3; h++)
				{

					box_ShellSort((i + 3) * 7, 25, 5, R[i].key, 15, R[i].mau);
					box_ShellSort((j + 3) * 7, 25, 5, R[j].key, 15, R[j].mau);
					Sleep(200);
					xoabox_ShellSort((i + 3) * 7, 25, 5, R[i].key);
					xoabox_ShellSort((j + 3) * 7, 25, 5, R[j].key);
					Sleep(200);
				}
				/*temp = A[j];
				A[j] = A[vt];
				A[vt] = temp;*/
				//draw2(R, N, l, j, i);
				swap(R[i], R[j]);
				//draw2(R, N, l, j, i);
				for (int h = 0; h < 3; h++)
				{
					xoabox_ShellSort((j + 3) * 7, 25, 5, R[j].key);
					xoabox_ShellSort((i + 3) * 7, 25, 5, R[i].key);
					Sleep(200);
					box_ShellSort((j + 3) * 7, 25, 5, R[j].key, 15, R[j].mau);
					box_ShellSort((i + 3) * 7, 25, 5, R[i].key, 15, R[i].mau);
					Sleep(200);
				}
				//gotoxy(95, 27); cout << "           "; Sleep(500);

			}
			/*gotoxy(95, 25); cout << "i = " << i << "    ";
			gotoxy(95, 26); cout << "j = " << j << "    ";
			gotoxy(95, 27); cout << "           "; Sleep(500);*/
		}
		//gotoxy(95, 27); cout << "i >= j "; Sleep(1000);


		//if (l != j)
		//
		//{
		//	//draw2(R, N, l, j, -1);
		//}
		//gotoxy(95, 26); cout << "l = " << l << "    ";
		//gotoxy(95, 27); cout << "r = " << r << "    ";
		//Sleep(500);
		for (int h = 0; h < 3; h++)
		{

			box_ShellSort((l + 3) * 7, 25, 5, R[l].key, 15, R[l].mau);
			box_ShellSort((j + 3) * 7, 25, 5, R[j].key, 15, R[j].mau);
			Sleep(200);
			xoabox_ShellSort((l + 3) * 7, 25, 5, R[l].key);
			xoabox_ShellSort((j + 3) * 7, 25, 5, R[j].key);
			Sleep(200);
		}
		
		swap(R[l], R[j]);
		for (int h = 0; h < 3; h++)
		{
			xoabox_ShellSort((j + 3) * 7, 25, 5, R[j].key);
			xoabox_ShellSort((l + 3) * 7, 25, 5, R[l].key);
			Sleep(200);
			box_ShellSort((j + 3) * 7, 25, 5, R[j].key, 15, R[j].mau);
			box_ShellSort((l + 3) * 7, 25, 5, R[l].key, 15, R[l].mau);
			Sleep(200);
		}
		//if (l != j)
		//{
		//	//draw2(R, N, l, j, -1);
		//}
		for (int i = 1; i <= N; i++)
		{
			box_ShellSort((i + 3) * 7, 25, 5, R[i].key, 15, R[i].mau);
		}


		//gotoxy(95, 27); cout << "          "; Sleep(1000);

		if (r - j >= j - l && j - l > M) {
			s.insertNode(j + 1, r);
			r = j - 1;
			continue;
		}
		if (j - l > r - j && r - j > M) {
			s.insertNode(l, j - 1);
			l = j + 1;
			continue;
		}
		if (r - j > M && M >= j - l) {
			l = j + 1;
			continue;
		}
		if (j - l > M && M >= r - j) {
			r = j - 1;
			continue;
		}

		if (s.isEmpty()) break;

		Data* top = s.deleteNode();
		l = top->l, r = top->r;
		delete top;
	}
	system("cls");
	for (int i = 1; i <=N; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, R[i].key, 15, R[i].mau);
		Sleep(100);
		xoabox_ShellSort((i + 3) * 7, 25, 5, R[i].key);
		Sleep(100);
	}
	for (int i = 1; i <= N; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, R[i].key, 15, R[i].mau);
		Sleep(100);
		xoabox_ShellSort((i + 3) * 7, 25, 5, R[i].key);
		Sleep(100);
	}
	for (int i = 1; i <= N; i++)
	{
		box_ShellSort((i + 3) * 7, 25, 5, R[i].key, 15, R[i].mau);
	}
}

void Menu()
{
	int N = 10;
	Record MANG[10];
	int x = 40;
	int y = 12;
	int w = 40;
	int h = 2;
	int t_color = 12;
	int b_color = 3;
	int b_color_sang = 112;//63;// 180;//79;// 135;
	string nd = "";
	int sl = 5;
	gotoxy(15, 4);
	textcolor(15);
	cout << endl << "    	 				    ____             _   _";
	cout << endl << " 	    				   / ___|  ___  _ __| |_(_)_ __   ___";
	cout << endl << " 	 	   			   \\___ \\ / _ \\| '__| __| | '_ \\ / _ \\ ";
	cout << endl << " 	 		   		    ___) | (_) | |  | |_| | | | | (_) |";
	cout << endl << "  				   	   |____/ \\___/|_|   \\__|_|_| |_|\\__, | ";
	cout << endl << "                                                                         |___/";
	Khung_Menu(x, y, w, h, t_color, b_color, nd, sl);
	textcolor(7);
	int xp = x;
	int yp = y;
	int xcu = xp;
	int ycu = yp;
	bool flag = true;
	while (true)
	{
		if (flag == true)
		{
			if ((ycu - y) / 2 == 0) nd = "ComparisonCounting";
			if ((ycu - y) / 2 == 1) nd = "ShellSort";
			if ((ycu - y) / 2 == 2) nd = "QuickSort";
			if ((ycu - y) / 2 == 3) nd = "SelectionSort";
			if ((ycu - y) / 2 == 4) nd = "MergeSort";
			gotoxy(xcu, ycu);
			thanh_sang(xcu, ycu, w, h, b_color, nd);
			xcu = xp; ycu = yp;

			//----------------
			if ((yp - y) / 2 == 0) nd = "ComparisonCounting";
			if ((yp - y) / 2 == 1) nd = "ShellSort";
			if ((yp - y) / 2 == 2) nd = "QuickSort";
			if ((yp - y) / 2 == 3) nd = "SelectionSort";
			if ((yp - y) / 2 == 4) nd = "MergeSort";
			thanh_sang(xp, yp, w, h, b_color_sang, nd);
			flag = false;
		}
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				flag = true;
				c = _getch();
				if (c == 72)
				{
					if (yp != y)
						yp -= 2;
					else
						yp = y + h * (sl - 1);
				}
				else if (c == 80)
				{
					if (yp != y + h * (sl - 1))
						yp += 2;
					else
						yp = y;
				}
			}
			if (c == '\r')//enter
			{
				setcolor(7);
				textcolor(7);
				SetColor(7);
				if ((yp - y) / 2 == 0)
				{
					system("cls");
					ComparisionCounting(MANG, N);
					_getch();
					system("cls");
					Menu();
				}
				if ((yp - y) / 2 == 1)
				{
					system("cls");
					ShellSort(MANG, N);
					_getch();
					system("cls");
					Menu();
				}
				if ((yp - y) / 2 == 2)
				{
					system("cls");
					/*QUICKSORT();
					_getch();
					system("cls");*/
					QuickSort(MANG, N);
					_getch();
					system("cls");
					Menu();
				}
				
				if ((yp - y) / 2 == 3)
				{
					system("cls");
					SelectionSort(MANG, N);
					_getch();
					system("cls");
					Menu();
				}
				if ((yp - y) / 2 == 4)
				{
					system("cls");
					MERGE_hopnhat();
					_getch();
					system("cls");
					MERGE();
					_getch();
					system("cls");
					Menu();
				}
			}
		}

	}
}

void batdau()
{
	ShowCur(0);
	for (int i = 0; i < 15; i++)
	{
		gotoxy(15, 9);
		textcolor(i);
		cout << endl << "    	 				    ____             _   _";
		cout << endl << " 	    				   / ___|  ___  _ __| |_(_)_ __   ___";
		cout << endl << " 	 	   			   \\___ \\ / _ \\| '__| __| | '_ \\ / _ \\ ";
		cout << endl << " 	 		   		    ___) | (_) | |  | |_| | | | | (_) |";
		cout << endl << "  				   	   |____/ \\___/|_|   \\__|_|_| |_|\\__, | ";
		cout << endl << "                                                                         |___/";
	}
	for (int i = 0; i < 15; i++)
	{
		gotoxy(15, 9);
		textcolor(i);
		cout << endl << "    	 				    ____             _   _";
		cout << endl << " 	    				   / ___|  ___  _ __| |_(_)_ __   ___";
		cout << endl << " 	 	   			   \\___ \\ / _ \\| '__| __| | '_ \\ / _ \\ ";
		cout << endl << " 	 		   		    ___) | (_) | |  | |_| | | | | (_) |";
		cout << endl << "  				   	   |____/ \\___/|_|   \\__|_|_| |_|\\__, | ";
		cout << endl << "                                                                         |___/";
		Sleep(200);
	}
	Sleep(300);
	system("cls");
	Sleep(300);
}

int main()
{
	//cout << "Nhom 6-Chatter7 Lop 08 DETAI2";



    char ini[] = "C:\\TURBOC3\\BGI";
    initgraph();

	batdau();
	Menu();
    _getch();
    return 0;
}






























/*int n;
    cout << "Nhap n: ";
    cin >> n;
    Record* MANG = (Record*)malloc(sizeof(Record));
    for (int i = 0; i < n; i++)
    {
        cout << "M['" << i << "'].key = ";
        cin >> MANG[i].key;
    }
    system("cls");
    ComparisionCounting(MANG, n);*/
//int i = 1;
    //int x = 10, y = 0;
    //int check = 0;
    //while (true)
    //{
    //    system("cls");
    //    textcolor(i++);
    //    if (i == 16)
    //    {
    //        i = 1;
    //    }
    //    gotoxy(x, y);
    //    cout << "Phap DEP TRAI!!!";
    //    if (check == 0)
    //    {
    //        y++;
    //    }
    //    else if (check == 1)
    //    {
    //        y--;
    //    }
    //    // KT Bien
    //    if (y == 28)
    //    {
    //        check = 1;
    //    }
    //    else if (y == 0)
    //    {
    //        check = 0;
    //    }
    //    Sleep(100);
    //}