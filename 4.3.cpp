#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
class Hang;
class Date
{
private:
    int D,M,Y;
public:
    void nhap();
    void xuat();
    friend class Hang;
    friend void searchByYear(Hang h[],int n);
};
class Hang
{
private:
    int maHang;
    char tenHang[30];
    Date Ngaysx;
public:
    void nhap();
    void xuat();
    friend void searchByYear(Hang h[],int n);
};
void Date::nhap()
{
    cout<<"Nhap ngay: ";
    cin>>D;
    cout<<"Nhap thang: ";
    cin>>M;
    cout<<"Nhap nam: ";
    cin>>Y;
}
void Date::xuat()
{
    cout<<setw(13)<<D<<"/"<<M<<"/"<<Y;
}
void Hang::nhap()
{
    cout<<"Nhap ma hang: ";
    cin>>maHang;
    cout<<"Nhap ten hang: ";
    fflush(stdin);
    gets(tenHang);
    cout<<"Nhap ngay sx: \n";
    Ngaysx.nhap();
};
void Hang::xuat()
{
    cout<<setw(15)<<maHang<<setw(15)<<tenHang;
    Ngaysx.xuat();
}
void searchByYear(Hang h[],int n)
{
    for(int i=0; i<n; i++)
    {
        if(h[i].Ngaysx.Y==2017){
            h[i].xuat();
            cout<<endl;
        }
    }
}
int main()
{
	cout<<"\t-------------------Bai 4.3-------------------\n";
    Hang h[100];
    int n;
    cout<<"Nhap so luong hang: "; cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin cua hang thu "<<i+1<<": \n";
        h[i].nhap();
    }
    cout<<"\n ============Thong tin cac mat hang==============\n";
    cout<<setw(15)<<"Ma Hang"<<setw(15)<<"Ten Hang"<<setw(20)<<"Ngay sx\n";
    for(int i=0;i<n;i++){
        h[i].xuat();
        cout<<endl;
    }
    cout<<"============Thong tin nhung mat hang san xuat nam 2017=============\n";
    cout<<setw(15)<<"Ma Hang"<<setw(15)<<"Ten Hang"<<setw(20)<<"Ngay sx\n";
    searchByYear(h,n);
    return 0;
}
