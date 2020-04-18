#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
class Date{
private:
    int D,M,Y;
public:
    void nhap();
    void xuat();
};
class NSX{
private:
    char TenNSX[20];
    char DiaChi[20];
public:
    void nhap();
    void xuat();
};
class Hang{
    char Tenhang[20];
    NSX x;
    float DonGia;
public:
    void nhap();
    void xuat();
    Hang(){};
};
class TIVI:public Hang{
private:
    int KichThuoc;
    Date NgayNhap;
public:
    void nhap();
    void xuat();
    TIVI(){};
};
void Date::nhap(){
    cout<<"Nhap ngay:";cin>>D;
    cout<<"Nhap thang:";cin>>M;
    cout<<"Nhap nam:";cin>>Y;
}
void Date::xuat(){
    cout<<setw(10)<<D<<"/"<<M<<"/"<<Y;
}
void NSX::nhap(){
    cout<<"Nhap ten nha san xuat: ";fflush(stdin);gets(TenNSX);
    cout<<"Nhap dia chi: ";         fflush(stdin);gets(DiaChi);
}
void NSX::xuat(){
    cout<<setw(15)<<TenNSX;
    cout<<setw(15)<<DiaChi;
}
void Hang::nhap(){
    cout<<"Nhap ten hang: "; fflush(stdin); gets(Tenhang);
    x.nhap();
    cout<<"Nhap don gia: ";cin>>DonGia;
}
void Hang::xuat(){
    cout<<setw(15)<<Tenhang;
    x.xuat();
    cout<<setw(15)<<DonGia;
}
void TIVI::nhap(){
    Hang::nhap();
    cout<<"Nhap kich thuoc: ";cin>>KichThuoc;
    cout<<"Nhap ngay nhap ve: \n";
    NgayNhap.nhap();
}
void TIVI::xuat(){
    Hang::xuat();
    cout<<setw(15)<<KichThuoc;
    NgayNhap.xuat();
}
void title(){
    cout<<setw(15)<<"Tenhang";
    cout<<setw(15)<<"TenNSX";
    cout<<setw(15)<<"DiaChi";
    cout<<setw(15)<<"DonGia";
    cout<<setw(15)<<"Kichthuoc";
    cout<<setw(15)<<"Ngaynhap\n";
}
int main()
{
    TIVI a;
    a.nhap();
    title();
    a.xuat();
    return 0;
}
