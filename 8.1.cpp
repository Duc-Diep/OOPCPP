#include <iostream>
#include<iomanip>
#include<stdio.h>

using namespace std;

class Phieu;

class hang{
private:
    char tenHang[10];
    float donGia;
    int soLuong;
public:
    void nhap();
    void xuat();
    float thanhTien();
    friend float tongTT(hang a[],int n);
    friend class phieu;
};
class NhaCc{
private:
    char tenNCC[20];
    char maNCC[10];
    char DC[20];
public:
    void nhap();
    void xuat();
    friend class phieu;
};
class phieu{
private:
    char maPhieu[10];
    char ngayLap[12];
    NhaCc nhaCc;
    hang a[100];
    int n;
public:
    void nhap();
    void xuat();
};

void hang::nhap(){
    cout<<"Nhap ten hang: ";
    fflush(stdin);
    gets(tenHang);
    cout<<"Nhap don gia: ";
    cin>>donGia;
    cout<<"Nhap so luong: ";
    cin>>soLuong;
    cout<<endl;
}

void hang::xuat(){
    cout<<setw(10)<<tenHang;
    cout<<setw(10)<<donGia;
    cout<<setw(10)<<soLuong;
    cout<<setw(10)<<thanhTien()<<endl;
}
float hang::thanhTien(){
    return donGia*soLuong;
}
void NhaCc::nhap(){
    cout<<"Nhap ma NCC: ";  fflush(stdin);gets(maNCC);
    cout<<"Nhap ten NCC: "; fflush(stdin);gets(tenNCC);
    cout<<"Nhap dia chi: "; fflush(stdin);gets(DC);
}
void NhaCc::xuat(){
    cout<<setw(10)<<maNCC;
    cout<<setw(10)<<tenNCC;
    cout<<setw(10)<<DC;
}
void phieu::nhap(){
    cout<<"Nhap ma phieu: ";fflush(stdin);gets(maPhieu);
    cout<<"Nhap ngay lap: ";fflush(stdin);gets(ngayLap);
    nhaCc.nhap();
    cout<<"Nhap so hang hoa: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin hang hoa thu "<<i+1<<endl;
        a[i].nhap();
    }
}
float tong(hang a[],int n){
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i].thanhTien();
    }
    return sum;
}
void phieu::xuat(){
    cout<<setw(10)<<"maPhieu"<<setw(10)<<"maNCC"<<setw(10)<<"DC"<<setw(10)<<"ngayLap"<<setw(10)<<"tenNCC"<<endl;
    cout<<setw(10)<<maPhieu<<setw(10)<<nhaCc.maNCC<<setw(10)<<nhaCc.tenNCC<<setw(10)<<nhaCc.DC<<setw(10)<<ngayLap<<endl;
    cout<<"\n==========Thong tin cac mat hang==========\n";
    cout<<setw(10)<<"tenHang"<<setw(10)<<"donGia"<<setw(10)<<"SL"<<setw(10)<<"TTien"<<endl;
    for(int i=0;i<n;i++){
        a[i].xuat();
    }
    cout<<setw(30)<<"Cong thanh tien:"<<setw(10)<<tong(a,n);
}


int main()
{
    phieu x;
    cout<<"Nhap thong tin cua phieu: "<<endl;
    x.nhap();
    cout<<"==========THONG TIN VUA NHAP=========="<<endl;
    x.xuat();
    return 0;
}
