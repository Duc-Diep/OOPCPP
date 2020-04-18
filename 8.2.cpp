#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
class Phieu;
class SinhVien{
private:
    char MaSv[10];
    char TenSv[20];
    char Lop[20];
    int Khoa;
public:
    void nhap();
    void xuat();
};
class MonHoc{
private:
    char TenMon[20];
    int SoTrinh;
    float Diem;
public:
    void nhap();
    void xuat();
    friend class Phieu;
    friend float DiemTrungBinh(MonHoc *y,int n);
};
class Phieu{
private:
    SinhVien x;
    MonHoc *y;
    int n;
    friend float DiemTrungBinh(MonHoc *y,int n);
public:
    void nhap();
    void xuat();
};
void SinhVien::nhap(){
    cout<<"Nhap ma sinh vien: ";fflush(stdin);gets(MaSv);
    cout<<"Nhap ten sinh vien: ";fflush(stdin);gets(TenSv);
    cout<<"Nhap ma sinh vien: ";fflush(stdin);gets(Lop);
    cout<<"Nhap khoa: "; cin>>Khoa;
}
void SinhVien::xuat(){
    cout<<"Ma sinh vien: "<<MaSv<<"\t\tTen sinh vien: "<<TenSv<<endl;
    cout<<"Lop: "<<Lop<<"\t\tKhoa: "<<Khoa;
}
void MonHoc::nhap(){
    cout<<"Nhap ten mon hoc: ";fflush(stdin);gets(TenMon);
    cout<<"Nhap so trinh: ";cin>>SoTrinh;
    cout<<"Nhap diem: ";cin>>Diem;
}
void MonHoc::xuat(){
    cout<<setw(15)<<TenMon;
    cout<<setw(10)<<SoTrinh;
    cout<<setw(15)<<Diem<<endl;
}
void Phieu::nhap(){
    x.nhap();
    cout<<"nhap so luong mon hoc: ";cin>>n;
    y = new MonHoc[n];
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin mon hoc thu "<<i+1<<endl;
        y[i].nhap();
    }
}
void title(){
    cout<<setw(15)<<"TenMon";
    cout<<setw(10)<<"SoTrinh";
    cout<<setw(15)<<"Diem"<<endl;
}
float DiemTrungBinh(MonHoc *y,int n){
    float sumdiem=0,sumsotrinh=0;
    for(int i=0;i<n;i++){
        sumdiem+=y[i].Diem*y[i].SoTrinh;
        sumsotrinh+=y[i].SoTrinh;
    }
    return sumdiem/sumsotrinh;
}
void Phieu::xuat(){
    x.xuat();
    cout<<"\nBang diem"<<endl;
    title();
    for(int i=0;i<n;i++){
        y[i].xuat();
    }
    cout<<setw(40)<<"Diem trung binh: "<<DiemTrungBinh(y,n);
}
int main()
{
    Phieu x;
    x.nhap();
    x.xuat();
    return 0;
}
