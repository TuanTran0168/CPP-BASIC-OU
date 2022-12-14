#include <iostream>
#include <cmath>
const double pi = 3.1415;
using namespace std;
int ham_Tong(int n);
int ham_TongBinhPhuong(int n);
double ham_TongPhanSoMauLe(int n);
int ham_TongGiaiThua(int n);
int ham_GiaiThua(int n);
int ham_Fibonacci(int n);
int ham_LuyThua(int x, int n);
int ham_DemSoChuSo(int n);
int ham_DaoNguocSo(int n);
int ham_TongCacChuSoChan(int n);
int ham_TongCacChuSoLe(int n);
long long ham_ThapPhanSangNhiPhan(int n);
int ham_USCLN(int a, int b);
int ham_KySoLonNhat(int n);
int ham_DemSoLeTrongMotSoNguyen(int n);
int ham_DemSoLeTuMotToiN(int n);
double ham_TongPhanSo(int n);
int ham_CapSoCong(int n, int a, int d);
int ham_CapSoNhan(int n, int a, int q);
long long ham_NhiPhanSangThapPhan(long long n, double a);
double ham_DienTichHinhVuongHinhTronLongNhau(int n, double a);
int ham_TinhTongMang(int a[], int n);
double ham_TimSoLonNhatTrongMang(int a[], int n);
int ham_SoNgayLayCovid(int Q, int N, int M);

int main()
{
    system("cls");
    int b[] = {1, 2, 3, 4, 5, 6};
    int c[] = {9, 6, 5, 3, 4};
    int n = 4;
    int a = 2;
    int R = 3;
    /*cout << "\nCau 1: " << ham_Tong(5);
    cout << "\nCau 2: " << ham_GiaiThua(5);
    cout << "\nCau 3: " << ham_Fibonacci(5);
    cout << "\nCau 4: " << ham_USCLN(125, 20);
    cout << "\nCau 5: " << ham_DemSoChuSo(1230456);
    cout << "\nCau 6: " << ham_KySoLonNhat(813456963);
    cout << "\nCau 7: " << ham_DemSoLeTrongMotSoNguyen(123456789);
    cout << "\nCau 8: " << ham_DemSoLeTuMotToiN(20);
    cout << "\nCau 9: " << ham_TongPhanSo(5);
    cout << "\nCau 10: " << ham_CapSoCong(3, 10, 3);
    cout << "\ncau 11: " << ham_CapSoNhan(5, 2, 3);*/
    cout << ham_NhiPhanSangThapPhan(10011, 0);
    //cout << ham_ThapPhanSangNhiPhan(19);

    //cout << ham_DienTichHinhVuongHinhTronLongNhau(n, a);
    // cout << "\nTong mang: " << ham_TinhTongMang(b, sizeof(b) / sizeof(b[0]) - 1);
    // cout << "\nSo lon nhat trong mang: " << ham_TimSoLonNhatTrongMang(c, sizeof(c) / sizeof(c[0]));
    // cout << "\nSo ngay: " << ham_SoNgayLayCovid(1, 1, 8);

    cout << endl;
    system("pause");
    return 0;
}

// S1 = 1 + 2 + 3 + 4 + .... + n (n l?? s??? nguy??n d????ng)
int ham_Tong(int n)
{
    if (n == 1)
        return 1;
    else
        return n + ham_Tong(n - 1);
}

// S2 = 1^2 + 2^2 + 3^2 + ... + n^2 (n l?? s??? nguy??n d????ng)
int ham_TongBinhPhuong(int n)
{
    if (n == 1)
        return 1;
    else
        return n * n + ham_TongBinhPhuong(n - 1);
}

//S3 = 1 + 1/3 + 1/5 + ... + 1/n (n l?? s??? nguy??n d????ng v?? l?? s??? l???)
double ham_TongPhanSoMauLe(int n)
{
    if (n == 1)
        return 1;
    else
        return (1 * 1.0) / n + ham_TongPhanSoMauLe(n - 2);
}

// S4 = 1! + 2! + 3! + ... + n!
int ham_TongGiaiThua(int n)
{
    if (n == 1)
        return 1;
    else
    {
        int gt = 1;
        for (int i = 1; i <= n; i++)
        {
            gt = gt * i;
        }
        return gt + ham_TongGiaiThua(n - 1);
    }
}

// C??u 2: T??nh giai th???a
int ham_GiaiThua(int n)
{
    if (n == 1)
        return 1;
    else
        return n * ham_GiaiThua(n - 1);
}

// C??u 3: T??nh d??y Fibonancci
int ham_Fibonacci(int n)
{
    if (n == 1 || n == 0)
        return 1;
    else
        return ham_Fibonacci(n - 2) + ham_Fibonacci(n - 1);
}

// C??u 4: T??nh l??y th???a x^n
int ham_LuyThua(int x, int n)
{
    if (n == 1)
        return x;
    else
        return x * ham_LuyThua(x, n - 1);
}

// C??u 5: ?????m s??? ch??? s??? c???a m???t s??? nguy??n kh??ng ??m
int ham_DemSoChuSo(int n)
{
    if (n < 10)
        return 1;
    else
        return 1 + ham_DemSoChuSo(n / 10);
    /* ham_DemChuSo(3260) = 4
        return 1 + ham_DemChuSo(326) = 1 + 3 = 4
                    return 1 + ham_DemChuSo(32) = 1 + 2 = 3
                                 return 1 + ham_DemChuSo(3) = 1 + 1 = 2
                                            return 1;  = 1      */
}

// C??u 6: ?????o ng?????c 1 s??? nguy??n kh??ng ??m
int ham_DaoNguocSo(int n)
{
    if (n < 10)
        return n;
    else
    {
        int sl = 0;
        int x = n % 10; // T??ch s??? cu???i ????? nh??n t????ng ???ng
        int n1 = n;
        while (n1 != 0) // ?????m s??? l?????ng ch??? s???
        {
            n1 /= 10;
            sl++;
        }
        for (int i = 0; i < sl - 1; i++) // Nh??n t????ng ???ng v???i h??ng tr??m, h??ng ch???c, h??ng ????n v???
        {
            x *= 10;
        }
        return x + ham_DaoNguocSo(n / 10);
        /*
               ham_DaoNguocSo(3293)
                return 3000 +  ham_DaoNguocSo(329)
                                return 900 +  ham_DaoNguocSo(29)
                                                return 20 + ham_DaoNguocSo(2)
                                                             return  3    
        */
    }
}

//C??u 7: T??nh t???ng c??c ch??? s??? ch???n / l??? c???a m???t s??? nguy??n kh??ng ??m
int ham_TongCacChuSoChan(int n)
{
    if (n < 10)
    {
        if (n % 2 == 0)
            return n;
        else
            return 0;
    }
    else
    {
        int x = (n % 10);
        if (x % 2 == 0)
            return x + ham_TongCacChuSoChan(n / 10); // S??? ch???n th?? c???ng v??o
        else
            return ham_TongCacChuSoChan(n / 10); // S??? l??? b??? qua
    }
}

int ham_TongCacChuSoLe(int n)
{
    if (n < 10)
    {
        if (n % 2 != 0)
            return n;
        else
            return 0;
    }
    else
    {
        int x = n % 10;
        if (x % 2 != 0)
            return x + ham_TongCacChuSoLe(n / 10); // S??? l??? th?? c???ng v??o
        else
            return ham_TongCacChuSoLe(n / 10); // S??? ch???n b??? qua
    }
}

//C??u 8: h??m chuy???n s??? th???p ph??n sang nh??? ph??n
long long ham_ThapPhanSangNhiPhan(int n)
{
    if (n == 0) // Chia l???n cu???i = 0 th?? tr??? v??? s??? d??
        return n % 2;
    else
        return (n % 2) + ham_ThapPhanSangNhiPhan(n / 2) * 10;
    /*

    ThapPhanSangNhiPhan(10)
      return 0 + ThapPhanSangNhiPhan(5) * 10  = 1010
                    return 1 + ThapPhanSangNhiPhan(2) * 10  = 101
                                return 0 + ThapPhanSangNhiPhan(1) * 10  = 10
                                             return 1;

      1010 = 1 * 1000 + 0 * 100 + 1 * 10 + 0
      n = 10 (h??? 10) = 1010 (h??? 2)
      10 / 2 = 5 d?? 0	n = 5
      5 / 2 = 2  d?? 1	n = 2
      2 / 2 = 1  d?? 0	n = 1
      1 / 2 = 0  d?? 1	n = 0 (??i???u ki???n d???ng (n = 0) v?? tr??? v??? s??? d??)
      ==> 1010 ( h??? 2)
  */
}

//C??u 9: Chuy???n t??? nh??? ph??n sang th???p ph??n
long long ham_NhiPhanSangThapPhan(long long n, double a)
{
    if (n == 0)
        return 0;
    else
    {
        return (n % 10) * pow(double(2), double(a)) + ham_NhiPhanSangThapPhan(n / 10, a + 1);
    }
    /*
	NhiPhanSangThapPhan(10111)
	  return 1 * 2^0 + NhiPhanSangThapPhan(1011)
						return 1 + 2^1 + NhiPhanSangThapPhan(101)
											return 1 * 2^2 + NhiPhanSangThapPhan(10)
																return 0 * 2^3 + NhiPhanSangThapPhan(1)
																					return 1 * 2^4 + NhiPhanSangThapPhan(0)
																										return 0;
	10111 = 1 * 2^4 + 0 * 2^3 + 1 * 2^2 + 1 * 2^1 + 1 * 2^0 = 23
	10111 (h??? 2) = 23 (h??? 10)
	10111 / 10 = 1011 d?? 1	n = 1011	a = 0
	1011  / 10 = 101  d?? 1	n = 101		a = 1
	101   / 10 = 10   d?? 1	n = 10		a = 2
	10    / 10 = 1    d?? 0  n = 1		a = 3
	1     / 10 = 0    d?? 1	n = 0		a = 4 (??i???u ki???n d???ng (n = 0) v?? tr??? v??? s??? 0)
	
	*/
}

// C??u 10: T??nh t???ng gi?? tr??? trong m???ng 1 chi???u c?? n ph???n t???
int ham_TinhTongMang(int a[], int n)
{
    if (n == 0)
        return a[n];
    else
        return a[n] + ham_TinhTongMang(a, n - 1);
}

//C??u 11: T??m s??? l???n nh???t trong m???ng
double ham_TimSoLonNhatTrongMang(int a[], int n)
{
    if (n == 0)
        return a[n];
    else
    {
        if (a[n] > ham_TimSoLonNhatTrongMang(a, n - 1))
            return a[n];
        else
            return ham_TimSoLonNhatTrongMang(a, n - 1);
    }
}

/* C??u 12: T??nh s??? ng??y l??y lan covid 19:

		   T???c ????? l??y covid l?? Q ng?????i / ng??y
		   Ngh??a l?? 1 ng?????i c?? th??? l??y lan cho Q ng?????i kh??c
		   So ng?????i ban ?????u l?? N
		   S??? ng?????i b??? l??y nhi???m l?? M
		   T??nh s??? ng??y ????? l??y ???????c t??? N ng?????i l??n M ng?????i
*/
int ham_SoNgayLayCovid(int Q, int N, int M)
{
    if (N >= M)
        return 0;
    else
        return 1 + ham_SoNgayLayCovid(Q, (N * Q) + N, M);
}

// ================================*****C??U L??M TR??N L???P*****=======================================
int ham_USCLN(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return ham_USCLN(b, a % b);
}

int ham_KySoLonNhat(int n)
{
    if (n < 10)
        return n;
    else
    {
        if (n % 10 > ham_KySoLonNhat(n / 10))
            return n % 10;
        else
            return ham_KySoLonNhat(n / 10);
    }
}

int ham_DemSoLeTrongMotSoNguyen(int n)
{
    if (n < 10)
    {
        if (n % 2 != 0)
            return 1;
    }
    else
    {
        if ((n % 10) % 2 != 0)
            return 1 + ham_DemSoLeTrongMotSoNguyen(n / 10);
        else
            return ham_DemSoLeTrongMotSoNguyen(n / 10);
    }
}

int ham_DemSoLeTuMotToiN(int n)
{
    if (n == 1)
        return 1;
    else
    {
        if (n % 2 != 0)
            return 1 + ham_DemSoLeTuMotToiN(n - 1);
        else
            return ham_DemSoLeTuMotToiN(n - 1);
    }
}

// S = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n
double ham_TongPhanSo(int n)
{
    if (n == 1)
        return 1;
    else
        return (1 * 1.0) / n + ham_TongPhanSo(n - 1);
}

// S = a + (a + d) + (a + 2d) + (a+ 3d) + ... + (a + nd) C???p s??? c???ng
int ham_CapSoCong(int n, int a, int d)
{
    if (n == 1)
        return a;
    else
        return (a + (n - 1) * d) + ham_CapSoCong(n - 1, a, d);
}

// S = a + a*q + a*q^2 + a*q^3 + ... + a*q^n
int ham_CapSoNhan(int n, int a, int q)
{
    if (n == 1)
        return a;
    else
    {
        int q1 = 1;
        for (int i = 1; i < n; i++)
        {
            q1 = q1 * q;
        }
        return a * q1 + ham_CapSoNhan(n - 1, a, q);
    }
}

double ham_DienTichHinhVuongHinhTronLongNhau(int n, double a)
{
    if (n % 2 != 0)
    {
        if (n == 1)
            return a * a;
        else
            return ham_DienTichHinhVuongHinhTronLongNhau(n - 2, a / sqrt(double(2)));
            //return ham_DienTichHinhVuongHinhTronLongNhau(n - 2, a) / 2;
    }
    else
    {
        if (n == 2)
            return pi * (a / 2) * (a / 2);
        else
            return ham_DienTichHinhVuongHinhTronLongNhau(n - 2, a / sqrt(double(2)));
    }
}
//============================================================================================================