#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
using namespace std;
class NhanVien;
class Date
{
private:
    int day,month,year;
public:
    friend class NhanVien;
};
class PhongBan
{
private:
    int maPb;
    char tenPb[50];
    char truongPhong[10];
    int soNv;
public:
    friend class NhanVien;
    friend void ShowTaiChinh(NhanVien a[],int n);
};
class NhanVien
{
private:
    int maNv;
    char hoDem[25];
    char ten[10];
    Date ngaySinh;
    PhongBan phong;
public:
    void nhap();
    void xuat();
    friend void ShowTaiChinh(NhanVien a[],int n);
    friend void SortByName(NhanVien a[],int n);
    friend void InsertNewNV(NhanVien a[],int &n,int k,NhanVien x);
    friend void DeleteCode123(NhanVien a[],int &n);
};

void NhanVien::nhap()
{
    cout<<"\nNhap ma nv: ";
    cin>>maNv;
    cout<<"Nhap ho dem: ";
    fflush(stdin);
    gets(hoDem);
    cout<<"Nhap ten: ";
    fflush(stdin);
    gets(ten);
    cout<<"Nhap ngay sinh: \n";
    cout<<"Nhap ngay: ";
    cin>>ngaySinh.day;
    cout<<"Nhap thang: ";
    cin>>ngaySinh.month;
    cout<<"Nhap nam: ";
    cin>>ngaySinh.year;
    cout<<"Nhap thong tin phong ban: \n";
    cout<<"Nhap ma phong ban: ";
    cin>>phong.maPb;
    cout<<"Nhap ten pb: ";
    fflush(stdin);
    gets(phong.tenPb);
    cout<<"Nhap ten truong phong: ";
    fflush(stdin);
    gets(phong.truongPhong);
    cout<<"Nhap so nhan vien: ";
    cin>>phong.soNv;
}
void NhanVien::xuat()
{
    cout<<setw(10)<<maNv;
    cout<<setw(10)<<hoDem;
    cout<<setw(10)<<ten;
    cout<<setw(10)<<ngaySinh.day<<"/"<<ngaySinh.month<<"/"<<ngaySinh.year;
    cout<<setw(10)<<phong.maPb;
    cout<<setw(15)<<phong.tenPb;
    cout<<setw(15)<<phong.truongPhong;
    cout<<setw(15)<<phong.soNv<<endl;
}
void title()
{
    cout<<setw(10)<<"maNv";
    cout<<setw(10)<<"hoDem";
    cout<<setw(10)<<"ten";
    cout<<setw(17)<<"NgaySinh";
    cout<<setw(10)<<"MaPb";
    cout<<setw(15)<<"TenPb";
    cout<<setw(15)<<"TruongPhong";
    cout<<setw(15)<<"SoNv"<<endl;
}
void ShowTaiChinh(NhanVien a[],int n)
{
    int dem=0;
    for(int i=0; i<n; i++)
    {
        if(stricmp(a[i].phong.tenPb,"Tai chinh")==0)
        {
            dem++;
        }
    }
    if(dem!=0)
    {
        title();
        for(int i=0; i<n; i++)
        {
            if(stricmp(a[i].phong.tenPb,"Tai chinh")==0)
            {
                a[i].xuat();
            }
        }
    }
    else
    {
        cout<<"Khong co nhan vien nao phong tai chinh !!\n\n";
    }
}
void SortByName(NhanVien a[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(stricmp(a[i].ten,a[j].ten)>0)
            {
                NhanVien temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    title();
    for(int i =0; i<n; i++)
    {
        a[i].xuat();
    }
}
void InsertNewNV(NhanVien a[],int &n,int k,NhanVien x)
{

    n++;
    for(int i=n; i>=k; i--)
    {
        a[i]=a[i-1];
    }
    a[k-1]=x;
    title();
    for(int i =0; i<n; i++)
    {
        a[i].xuat();
    }
}
void DeleteCode123(NhanVien a[],int &n)
{
    int i=0;
    while(i<n)
    {
        if(a[i].maNv==123)
        {
            for(int j=i; j<n; j++)
            {
                a[j]=a[j+1];
            }
            n--;
        }
        else
            i++;
    }
    title();
    for(int i =0; i<n; i++)
    {
        a[i].xuat();
    }
}
int main()
{
    NhanVien a[100];
    int n;
    cout<<"Nhap so luong nhan vien: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin nhan vien thu "<<i+1;
        a[i].nhap();
    }
    cout<<"Thong tin sinh vien phong tai chinh: \n";
    ShowTaiChinh(a,n);
    cout<<"Thong tin sau khi sap xep:\n";
    SortByName(a,n);
    int k;
    NhanVien x;
    cout<<"Nhap thong tin cua nhan vien moi: ";
    x.nhap();
    cout<<"Nhap vi tri k: ";
    cin>>k;
    cout<<"Sau khi chen them 1 nhan vien vao vi tri "<<k<<endl;
    InsertNewNV(a,n,k,x);
    cout<<"Sau khi xoa nhan vien co ma 123: \n";
    DeleteCode123(a,n);
    return 0;
}
