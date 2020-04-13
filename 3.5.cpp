#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
using namespace std;

class Nhansu;
class Date{
private:
    int ngay,thang,nam;
public:
    void nhap();
    void xuat();
    friend class Nhansu;
};
class Nhansu{
private:
    char hoTen[30];
    Date ngaysinh;
    char cmt[14];
public:
    void nhap();
    void xuat();
    friend void sortbyName(Nhansu ns[],int n);
};
void Date::nhap(){
cout<<"Nhap ngay: ";        cin>>ngay;
cout<<"Nhap thang: ";       cin>>thang;
cout<<"Nhap nam: ";         cin>>nam;
}
void Date::xuat(){
cout<<setw(15)<<ngay<<"/"<<thang<<"/"<<nam;
}
void Nhansu::nhap(){
cout<<"Nhap ho ten: ";      fflush(stdin);gets(hoTen);
cout<<"Nhap ngay sinh:\n";  ngaysinh.nhap();
cout<<"Nhap so cmt: ";      fflush(stdin);gets(cmt);
}
void Nhansu::xuat(){
cout<<setw(20)<<hoTen;
ngaysinh.xuat();
cout<<setw(20)<<cmt;
}
void sortbyName(Nhansu ns[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(ns[i].hoTen,ns[j].hoTen)>0){
                Nhansu tg = ns[i];
                ns[i]=ns[j];
                ns[j]=tg;
            }
        }
    }
}
int main()
{
	cout<<"\t-------------------Bai 3.5-------------------\n";
    Nhansu ns[100];
    int n;
    cout << "Nhap so nhan su : "; cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin nhan su thu "<<i+1<<": \n";
        ns[i].nhap();
    }
    sortbyName(ns,n);
    cout<<"\n=======Thong tin cac nhan su duoc sap xep theo ten==========\n";
    cout<<setw(20)<<"Ho ten"<<setw(20)<<"Ngay sinh"<<setw(20)<<"So cmt"<<endl;
    for(int i=0;i<n;i++){
        ns[i].xuat();
        cout<<endl;
    }

    return 0;
}
