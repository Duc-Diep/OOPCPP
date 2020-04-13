#include <iostream>
#include<stdio.h>
#include<iomanip>

using namespace std;

class person
{
protected:
    char hoTen[30];
    char ngaySinh[15];
    char queQuan[30];
};

class kySu:private person
{
private:
    char nganh[10];
    int namTN;
public:
    void nhap();
    void xuat();
    friend void ShowByYear(kySu x[],int n);
};

void kySu::nhap()
{
    cout<<"Nhap ho ten: ";
    fflush(stdin);
    gets(hoTen);
    cout<<"Nhap ngay sinh: ";
    fflush(stdin);
    gets(ngaySinh);
    cout<<"Nhap que quan: ";
    fflush(stdin);
    gets(queQuan);
    cout<<"Nhap nganh: ";
    fflush(stdin);
    gets(nganh);
    cout<<"Nhap nam tot nghiep: ";
    cin>>namTN;
    cout<<endl;
}

void kySu::xuat()
{
    cout<<setw(20)<<hoTen<<setw(15)<<ngaySinh<<setw(10)<<queQuan<<setw(10)<<nganh<<setw(10)<<namTN<<endl;
}
void title()
{
    cout<<setw(20)<<"HoTen"<<setw(15)<<"NgaySinh"<<setw(10)<<"QueQuan"<<setw(10)<<"Nganh"<<setw(10)<<"NamTN"<<endl;
}
void ShowByYear(kySu x[],int n)
{
    int max = x[0].namTN;
    for(int i=1; i<n; i++)
    {
        if(x[i].namTN>max)
        {
            max=x[i].namTN;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(x[i].namTN==max)
        {
            x[i].xuat();
        }
    }
}
int main()
{
    int n;
    kySu x[100];
    cout<<"Nhap so ky su: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Nhap thong tin ky su thu "<<i+1<<": "<<endl;
        x[i].nhap();
    }
    cout<<"\t\t==========THONG TIN VUA NHAP=========="<<endl;

    for(int i=0; i<n; i++)
    {
        x[i].xuat();
    }
    cout<<"\nThong tin cua ky su co nam tot nghiep gan nhat la: \n";
    title();
    ShowByYear(x,n);
    return 0;
}
