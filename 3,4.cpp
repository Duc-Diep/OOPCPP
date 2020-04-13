#include <iostream>
#include<stdio.h>
#include<iomanip>

using namespace std;

class phongMay;

class quanLy{
private:
    int maQL;
    char hoTen[30];
public:
    void nhap();
    void xuat();
    friend class phongMay;
};

class may{
private:
    int maMay;
    char kieuMay[10];
    char tinhTrang[10];
public:
    void nhap();
    void xuat();
    friend class phongMay;
};

class phongMay{
private:
    int maPhong;
    char tenPhong[10];
    int dienTich;
    quanLy x;
    may y[100];
    int n;
public:
    void nhap();
    void xuat();
};

void quanLy::nhap(){
    cout<<"Nhap ma quan ly: ";		cin>>maQL;
                                    fflush(stdin);
    cout<<"Nhap ho ten: ";		    gets(hoTen);
}

void quanLy::xuat(){
    cout<<setw(10)<<maQL<<setw(10)<<hoTen;
}

void may::nhap(){
    cout<<"Nhap ma may: ";		    cin>>maMay;
                                    fflush(stdin);
    cout<<"Nhap kieu may: ";		gets(kieuMay);
    cout<<"Tinh trang may: ";		gets(tinhTrang);
}

void may::xuat(){
    cout<<setw(10)<<maMay<<setw(15)<<kieuMay<<setw(15)<<tinhTrang;
}

void phongMay::nhap(){
    cout<<"Nhap ma phong: ";		cin>>maPhong;
                                    fflush(stdin);
    cout<<"Nhap ten phong: ";		gets(tenPhong);
    cout<<"Nhap dien tich: ";		cin>>dienTich;
    x.nhap();
    cout<<"Nhap so may trong phong: ";	cin>>n;
    for(int i=0;i<n;i++){
        cout<<"May thu "<<i+1<<":"<<endl;
        y[i].nhap();
    }
}

void phongMay::xuat(){
    cout<<setw(10)<<maPhong<<setw(10)<<tenPhong<<setw(10)<<dienTich;
    x.xuat();
    cout<<setw(10)<<n<<endl;
    cout<<setw(10)<<"Ma May"<<setw(15)<<"Kieu May"<<setw(15)<<"Tinh Trang";
    cout<<endl;
    for(int i=0;i<n;i++){
        y[i].xuat();
        cout<<endl;
    }
}

int main()
{
	cout<<"\t-------------------Bai 3.4-------------------\n";
    phongMay p;
    p.nhap();
    cout<<"==========THONG TIN CUA PHONG MAY=========="<<endl;
    cout<<setw(10)<<"Ma Phong"<<setw(10)<<"Ten Phong"<<setw(10)<<"Dien Tich"<<setw(10)<<"Ma QL"<<setw(10)<<"Ho Ten"<<setw(10)<<"So May"<<endl;
    p.xuat();
    return 0;
}
