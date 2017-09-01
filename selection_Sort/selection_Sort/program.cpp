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


int KTNguyenTo(int soA)
{
	if (soA < 2)
		return false;

	for (int i = 2; i <= sqrt((float)soA); i++)
	{
		if (soA%i == 0)
		{
			return false;
		}
	}
	return true;
}

void sapXep(int n, int a[MAX]){
	for (int i = 0; i < n - 1; i++) {
		int chon = i;
		//tìm kiếm giá trị cho biến chọn 
		for (int j = i + 1; j < n; j++){
			if ((KTNguyenTo(a[j]) == true && KTNguyenTo(a[chon]) == false) ||
				(KTNguyenTo(a[j]) == true && KTNguyenTo(a[chon]) == true && a[j]<a[chon]) ||
				(KTNguyenTo(a[j]) == false && KTNguyenTo(a[chon]) == false && a[j]>a[chon])
				)
				chon = j;
		}
		if (chon != i) {
			HoanVi(a[i], a[chon]);
		}
	}
}

int main(){
	int n=5;
	int a[MAX];
	cout << endl << "Nhap vao so phan tu cua mang: ";
	cin >> n;
	NhapTuDongMang(n, a);
	cout << endl << "Xuat mang: ";
	XuatMang(n, a);
	sapXep(n, a);
	cout << endl << "ket qua sau khi sap xep: " << endl;
	XuatMang(n, a);
	system("pause");
}

