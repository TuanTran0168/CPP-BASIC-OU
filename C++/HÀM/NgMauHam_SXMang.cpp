#include <iostream>
using namespace std;

// KHAI BÁO NGUYEN MẪU HÀM
void ham_NhapMang(int a[], int &);
void ham_XuatMang(int a[], int);
void ham_SapXepTangDan(int a[], int);
void ham_SapXepGiamDan(int a[], int);

// ĐỊNH NGHĨA - CÀI DẶT CODE XỬ LÍ CÁC HÀM KHAI BÁO Ở TRÊN
int main()
{
    int a[1000];
    int Maxsize;
    ham_NhapMang(a, Maxsize);
    cout << "Sap xep cac phan tu tang dan: ";
    ham_SapXepTangDan(a, Maxsize);
    ham_XuatMang(a, Maxsize);
    cout << "Sap xep cac phan tu giam dan: ";
    ham_SapXepGiamDan(a, Maxsize);
    ham_XuatMang(a, Maxsize);
    system("pause");
    return 0;
}

// XÂY DỰNG HÀM DƯỚI HÀM MAIN (Vị trí hàm tùy ý)
void ham_XuatMang(int a[], int Maxsize)
{
    for (int i = 0; i < Maxsize; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void ham_NhapMang(int a[], int &Maxsize)
{
    do
    {
        cout << "Nhap do lon cua mang: ";
        cin >> Maxsize;
        if (Maxsize <= 0 || Maxsize > 1000)
        {
            cout << "Do lon cua mang khong hop le, vui long nhap lai !\t\t";
            system("pause");
        }
    } while (Maxsize <= 0 || Maxsize > 1000);
    for (int i = 0; i < Maxsize; i++)
    {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }
    cout << endl;
}

void ham_SapXepTangDan(int a[], int Maxsize)
{
    int thaythe;
    for (int i = 0; i < Maxsize; i++)
    {
        for (int j = i + 1; j < Maxsize; j++)
        {
            if (a[i] > a[j])
            {
                thaythe = a[i];
                a[i] = a[j];
                a[j] = thaythe;
            }
        }
    }
}

void ham_SapXepGiamDan(int a[], int Maxsize)
{
    int thaythe;
    for (int i = 0; i < Maxsize; i++)
    {
        for (int j = i + 1; j < Maxsize; j++)
        {
            if (a[i] < a[j])
            {
                thaythe = a[i];
                a[i] = a[j];
                a[j] = thaythe;
            }
        }
    }
}
