#include <iostream>
#include<stdio.h>
#include<iomanip>

using namespace std;
class VEHICLE{
protected:
    char nhanHieu[20];
    int namSx;
    char Hang[20];
public:
    void nhap();
    void xuat();
};
class OTO:private VEHICLE{
private:
    int soChoNgoi;
    int dungTich;
public:
    void nhap();
    void xuat();
};
class MOTO:private VEHICLE{
private:
    int phanKhoi;
public:
    void nhap();
    void xuat();
};
void VEHICLE::nhap(){
    cout<<"Nhap nhan hieu: ";           fflush(stdin); gets(nhanHieu);
    cout<<"Nhap nam san xuat: ";        cin>>namSx;
    cout<<"Nhap hang: ";                fflush(stdin); gets(Hang);
}
void VEHICLE::xuat(){

    cout<<setw(20)<<nhanHieu<<setw(20)<<namSx<<setw(20)<<Hang;
}
void OTO::nhap(){
    VEHICLE::nhap();
    cout<<"Nhap so cho ngoi: ";     cin>>soChoNgoi;
    cout<<"Nhap dung tich: ";       cin>>dungTich;
}
void OTO::xuat(){
    VEHICLE::xuat();
    cout<<setw(20)<<soChoNgoi<<setw(20)<<dungTich;
}
void MOTO::nhap(){
    VEHICLE::nhap();
    cout<<"Nhap phan khoi: ";cin>>phanKhoi;
}
void MOTO::xuat(){
    VEHICLE::xuat();
    cout<<setw(20)<<phanKhoi;
}
void titleofOTO(){
cout<<endl<<setw(20)<<"OTO:\tNhanHieu"<<setw(20)<<"namSx"<<setw(20)<<"Hang"<<setw(20)<<"SoChoNgoi"<<setw(20)<<"DungTich\n";
}
void titleofMOTO(){
cout<<endl<<setw(20)<<"MOTO:\tNhanHieu"<<setw(20)<<"namSx"<<setw(20)<<"Hang"<<setw(20)<<"phanKhoi\n";
}
int main()
{
    OTO x;
    MOTO y;
    cout<<"Nhap thong tin cua OTO:\n";
    x.nhap();
    cout<<"Nhap thong tin cua MOTO:\n";
    y.nhap();
    titleofOTO();
    x.xuat();
    titleofMOTO();
    y.xuat();
    return 0;
}
