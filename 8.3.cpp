#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
class NhanVien{
private:
    char TenNv[20];
    char ChucVu[20];
public:
    void nhap();
    void xuat();
};
class Phong{
private:
    char TenPhong[20];
    char MaPhong[20];
    char TruongPhong[20];
public:
    void nhap();
    void xuat();
};
class TaiSan{
private:
    char TenTaiSan[20];
    int SoLuong;
    char TinhTrang[20];
public:
    void nhap();
    void xuat();
    friend int TongSoLuong(TaiSan a[],int n);
};
class Phieu{
private:
    char MaPhieu[20];
    char NgayKiemKe[20];
    NhanVien nv;
    Phong p;
    TaiSan a[100];
    int n;
public:
    void nhap();
    void xuat();
    friend int TongSoLuong(TaiSan a[],int n);
};
void NhanVien::nhap(){
    cout<<"Nhap ten nhan vien: ";fflush(stdin);gets(TenNv);
    cout<<"Nhap chuc vu: ";fflush(stdin);gets(ChucVu);
}
void NhanVien::xuat(){
    cout<<"Nhan vien kiem ke: "<<TenNv<<"\tChuc vu: "<<ChucVu<<endl;
}
void Phong::nhap(){
    cout<<"Nhap ten phong: ";fflush(stdin);gets(TenPhong);
    cout<<"Nhap ma phong: ";fflush(stdin);gets(MaPhong);
    cout<<"Nhap ten truong phong: ";fflush(stdin);gets(TruongPhong);
}
void Phong::xuat(){
    cout<<"Kiem ke tai phong: "<<TenPhong<<"\tMa phong: "<<MaPhong<<endl<<"Truong phong: "<<TruongPhong<<endl;
}
void TaiSan::nhap(){
    cout<<"Nhap ten tai san: ";fflush(stdin);gets(TenTaiSan);
    cout<<"Nhap so luong: "; cin>>SoLuong;
    cout<<"Nhap tinh trang; ";fflush(stdin);gets(TinhTrang);
}
void TaiSan::xuat(){
    cout<<setw(15)<<TenTaiSan;
    cout<<setw(15)<<SoLuong;
    cout<<setw(15)<<TinhTrang<<endl;
}
void Phieu::nhap(){
    cout<<"Nhap ma phieu: ";fflush(stdin); gets(MaPhieu);
    cout<<"Nhap ngay kiem ke: ";fflush(stdin); gets(NgayKiemKe);
    nv.nhap();
    p.nhap();
    cout<<"Nhap so tai san: ";cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin tai san thu "<<i+1<<endl;
        a[i].nhap();
    }
}
int TongSoLuong(TaiSan a[],int n){
    int sum =0;
    for(int i=0;i<n;i++){
        sum+=a[i].SoLuong;
    }
    return sum;
}
void Phieu::xuat(){
    cout<<"\tPHIEU KIEM KE TAI SAN\n";
    cout<<"Ma phieu: "<<MaPhieu<<"\tNgay kiem ke: "<<NgayKiemKe<<endl;
    nv.xuat();
    p.xuat();
    cout<<setw(15)<<"TenTaiSan"<<setw(15)<<"SoLuong"<<setw(15)<<"TinhTrang\n";
    for(int i=0;i<n;i++){
        a[i].xuat();
    }
    cout<<setw(20)<<"So tai san da kiem ke: "<<n<<setw(20)<<"Tong so luong: "<<TongSoLuong(a,n);
}
int main()
{
    Phieu x;
    x.nhap();
    x.xuat();
    return 0;
}
