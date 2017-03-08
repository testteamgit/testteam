// NguoiDuLich_ThamLam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#define max 100

using namespace std;

int GTS(int a[5][5], int n, int TOUR[max], int DiemDau)
{
	int dangxet, // dinh dang xet
		duyetqua, // duyet qua n dinh de chon
		chon, // dinh duoc choose trong moi buoc
		gtnn, // chon canh' cung min trong moi buoc
		cost, // gia tri cua cung min duoc chon
		daxet[max]; // danh dau cac dinh da duoc su dung

	for (duyetqua = 1;duyetqua <= n; duyetqua++)
	{
		daxet[duyetqua] = 0;  // chua dinh nao duoc xet
		cost = 0; //luc dau, gia tri cost = 0
		int i; // bien dem, dem den du n dinh thi dung.
		dangxet = DiemDau; //chon dinh xuat phat la 1 .
		i = 1;
		TOUR[i] = dangxet; //dua dangxet vao chu trinh
		daxet[dangxet] = 1; //dua  dangxet vao daxet
		
		while (i < n)
		{
			for (dangxet = 1; dangxet <= n;dangxet++)
			{
				if (!daxet[dangxet])
				{
					if (gtnn > a[dangxet][duyetqua])
					{
						gtnn = a[dangxet][duyetqua];
						chon = duyetqua;
					}
					dangxet = duyetqua;
					i++;
					TOUR[i] = 1;
					daxet[dangxet] = 1;
					cost = cost + gtnn;
				}
				cost = cost + a[dangxet][DiemDau];
			}
		}
		return cost;
	}
}

int main()
{
	int t[max];
	int  a[5][5] = { {0,1,2,7,5} ,{1,0,4,4,3},{2,4,0,1,2},{7,4,1,0,3},{5,3,2,3,0} };
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0;j < 5; j++)
		{
			cout << a[i][j];
			cout << " ";
		}
		cout << "\n";
	}
	cout << GTS(a, 5, t, 0);
	system("pause");
	return 0;

}

