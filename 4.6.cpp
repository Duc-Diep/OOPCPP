#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
using namespace std;
class XeHoi{
private:
    char NhanHieu[10];
    char HangSx[10];
    char KieuDang[10];
    char MauSon[10];
    int NamSx;
    char XuatXu[10];
    long GiaBan;
public:
    void nhap();
    void xuat();
    friend void findToyota(XeHoi x[],int n);
    friend void SortByPrice(XeHoi x[],int n);
};
void XeHoi::nhap(){
    cout<<"\nNhap nhan hieu: ";     fflush(stdin);   gets(NhanHieu);
    cout<<"Nhap hang sx: ";         fflush(stdin);   gets(HangSx);
    cout<<"Nhap kieu dang: ";       fflush(stdin);   gets(KieuDang);
    cout<<"Nhap mau son: ";         fflush(stdin);   gets(MauSon);
    cout<<"Nhap nam sx: " ;            cin>>NamSx;
    cout<<"Nhap xuat xu: ";         fflush(stdin);   gets(XuatXu);
    cout<<"nhap gia ban: " ;         cin>>GiaBan;
}
void XeHoi::xuat(){
    cout<<setw(15)<<NhanHieu;
    cout<<setw(15)<<HangSx;
    cout<<setw(15)<<KieuDang;
    cout<<setw(15)<<MauSon;
    cout<<setw(15)<<NamSx;
    cout<<setw(15)<<XuatXu;
    cout<<setw(15)<<GiaBan<<endl;
}
void title(){
    cout<<setw(15)<<"NhanHieu";
    cout<<setw(15)<<"HangSx";
    cout<<setw(15)<<"KieuDang";
    cout<<setw(15)<<"MauSon";
    cout<<setw(15)<<"NamSx";
    cout<<setw(15)<<"XuatXu";
    cout<<setw(15)<<"GiaBan"<<endl;
}
void findToyota(XeHoi x[],int n){
    int dem=0;
    for(int i=0; i<n; i++)
    {
        if(strcmp(x[i].HangSx,"Toyota")==0)
        {
            dem++;
        }
    }
    if(dem!=0)
    {
        title();
        for(int i=0; i<n; i++)
        {
            if(strcmp(x[i].HangSx,"Toyota")==0)
            {
                x[i].xuat();
            }
        }
    }
    else
    {
        cout<<"Khong co Xe nao hang sx la Toyota !!\n\n";
    }
}
void SortByPrice(XeHoi x[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(x[i].GiaBan>x[j].GiaBan){
                XeHoi temp = x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
    }
    title();
    for(int i =0;i<n;i++){
        x[i].xuat();
    }
}

int main()
{
    XeHoi a[100];
    int n;
    cout<<"Nhap so luong xe: "; cin>>n;
    for(int i=0;i<n;i++){
        cout<<"nhap thong tin xe thu "<<i+1;
        a[i].nhap();
    }
    title();
    for(int i =0;i<n;i++){
        a[i].xuat();
    }
    cout<<"\n-------------Thong tin nhung xe cua hang Toyota---------------\n\n";
    findToyota(a,n);
    cout<<"-------------Thong tin cac xe sau khi sap xep-------------\n\n";
    SortByPrice(a,n);
    return 0;
}
