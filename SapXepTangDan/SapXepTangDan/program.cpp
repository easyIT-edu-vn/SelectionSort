#include <iostream>
#include <conio.h>
#include <ctime>
#define MAX 100
using namespace std;

void NhapTuDongMang(int n, int a[MAX]){     //tự động nhập các phần tử trong mảng
	srand(time(NULL));
	for (int i = 0; i < n; i++){
		a[i] = rand() % 20 + 1;
	}
}

void XuatMang(int n, int a[MAX]){          //xuất các phần tử của mảng
	for (int i = 0; i < n; i++){
		cout << a[i] << "\t";
	}
	cout << endl;
}

void HoanVi(int &a, int &b){
	int tam = a;
	a = b;
	b = tam;
}

void sapXepTang(int n, int a[MAX]){
	for (int i = 0; i < n - 1; i++) {
		int chon = i;
		//tìm kiếm giá trị 
		for (int j = i + 1; j < n; j++){
			if (a[chon]>a[j]
				)
				chon = j;
		}
		if (chon != i) {
			HoanVi(a[i], a[chon]);
		}
	}
}



int main(){
	int n = 5;
	int a[MAX];
	cout << endl << "Nhap vao so phan tu cua mang: ";
	cin >> n;
	NhapTuDongMang(n, a);
	cout << endl << "Xuat mang: ";
	XuatMang(n, a);
	sapXepTang(n, a);
	cout << endl << "ket qua sau khi sap xep tang dan: " << endl;
	XuatMang(n, a);
	system("pause");
}

