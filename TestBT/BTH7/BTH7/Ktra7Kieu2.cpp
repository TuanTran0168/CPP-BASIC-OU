#include <iostream>
using namespace std;
int main()
{

	const int MAX=17;
	double VN[MAX] = {34.5, 35, 35.5, 36, 36.5, 37, 37.5, 38, 38.5, 39, 39.5, 40, 40.5, 41, 41.5, 42, 42.5};
	double US[MAX] = {4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10, 10.5, 11, 11.5, 12};
	double UK[MAX] = {2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10};
	double Inch[MAX] = {8.1875, 8.375, 8.5, 8.75, 8.875, 9.0625, 9.25, 9.375, 9.5, 9.6875, 9.875, 10, 10.1875, 10.3125, 10.5, 10.6875, 10.875};
	double Cm[MAX] = {20.8, 21.3, 21.6, 22.2, 22.5, 23, 23.5, 23.8, 24.1, 24.6, 25.1, 25.4, 25.9, 26.2, 26.7, 27.1, 27.6};
	int size;
	do
	{
		cout << "nhap size giay tieu chuan cua ban o Viet Nam"<<endl;
		cout<<"Hay chon tu size 34 toi size 43: ";
		cin >> size;
		if (size > 43 || size < 34)
		{
			cout << "nhap sai" << endl;
		}
	} while (size > 43 || size < 34);
	for (int i = 0; i < MAX; i++)
	{
		if (size == VN[i])
		{
			cout << "size giay cua My la: " << US[i] << " " << endl;
			cout << "size giay cua Anh la: " << UK[i] << " " << endl;
			cout<< "co so do ban chan la "<< Inch[i] << " inch"<<" va "<< Cm[i]<<" Cm\n";
		}
	}
	system("pause");
	return 0;
}