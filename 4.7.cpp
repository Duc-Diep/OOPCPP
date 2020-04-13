#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;
class DoanhNghiep;
class Date{
private:
    int day,month,year;
public:
    void nhap();
    void xuat();
    friend class DoanhNghiep;
    friend void sumByYear(DoanhNghiep a[], int n);
    friend void modifyInfo(DoanhNghiep a[], int n);
};
class DiaChi{
private:
    char dienThoai[12];
    char phuong[30];
    char quan[30];
    char thanhPho[30];
public:
    friend class DoanhNghiep;
    friend void DisplayByCity(DoanhNghiep a[],int n);
};
class DoanhNghiep{
private:
    int maDn;
    char tenDn[60];
    Date ngayTl;
    DiaChi diaChi;
    char giamDoc[30];
    long doanhThu;
public:
    void nhap();
    void xuat();
    friend void DisplayByCity(DoanhNghiep a[],int n);
    friend void sumByYear(DoanhNghiep a[], int n);
    friend void modifyInfo(DoanhNghiep a[], int n);
};
//date
void Date::nhap(){
    cout << "Nhap ngay: ";  cin >> day;
    cout << "Nhap thang: "; cin >> month;
    cout << "Nhap nam: ";   cin >> year;
}
void Date::xuat(){
    cout << setw(5) << day << "/" << month << "/" << year;
}
//Doanhnghiep
void DoanhNghiep::nhap(){
cout << "Nhap ma doanh nghiep: ";   cin >> maDn;
    cout << "Nhap ten doan nghiep: ";   fflush(stdin);  gets(tenDn);
    cout << "===NHAP THONG TIN NGAY THANH LAP===" << endl;
    ngayTl.nhap();
    cout << "===NHAP THONG TIN DIA CHI===" << endl;
    cout << "Nhap so dien thoai: "; fflush(stdin); gets(diaChi.dienThoai);
    cout << "Nhap ten phuong: ";    fflush(stdin);  gets(diaChi.phuong);
    cout << "Nhap ten quan: ";      fflush(stdin);  gets(diaChi.quan);
    cout << "Nhap ten thanh pho: "; fflush(stdin);  gets(diaChi.thanhPho);
    cout << "Nhap ten giam doc: ";  fflush(stdin);  gets(giamDoc);
    cout << "Nhap doanh thu: ";     cin >> doanhThu;
}
void DoanhNghiep::xuat(){
    cout << setw(5) << maDn << setw(10) << tenDn;
    ngayTl.xuat();
    cout << setw(10) << diaChi.dienThoai << setw(10) << diaChi.phuong << setw(10) << diaChi.quan << setw(10) << diaChi.thanhPho;
    cout << setw(10) << giamDoc << setw(10) << doanhThu <<endl;
}
void DisplayByCity(DoanhNghiep a[], int n) {
    int dem = 0;
    for(int i = 0; i < n; i++) {
        if(strcmp(a[i].diaChi.thanhPho,"Ha Noi") == 0) {
            dem++;
        }
    }
    if(dem == 0)
        cout << endl << "Khong co doanh nghiep nao o Ha Noi !!!" << endl;
    else {
        cout << endl << "====THONG TIN DOANH NGHIEP O HA NOI====" << endl;
        cout << setw(5) << "maDN" << setw(10) << "tenDN" << setw(10) << "ngayTL" << setw(15) << "dienThoai" << setw(10) << "phuong" << setw(10) << "quan" << setw(10) << "thanhPho";
        cout << setw(10) << "giamDoc" << setw(10) << "doanhThu" <<endl;
        for(int i = 0; i < n; i++) {
            if(strcmp(a[i].diaChi.thanhPho,"Ha Noi") == 0) {
                a[i].xuat();
            }
        }
    }
}
void sumByYear(DoanhNghiep a[],int n){
long sum=0;
for(int i=0;i<n;i++){
    if(a[i].ngayTl.year==2015){
        sum+=a[i].doanhThu;
    }
}
cout<<"Tong doanh thu cua cac doanh nghiep thanh lap nam 2015 la: "<<sum;
}
void modifyInfo(DoanhNghiep a[],int n){
int ma, dem = 0;
    cout << endl << "Nhap ma doanh nghiep can sua: ";   cin >> ma;
    for(int i = 0; i < n; i++){
        if(a[i].maDn == ma){
            cout << "===BAN DANG SUA THONG TIN DOANH NGHIEP===" << endl;
            cout << setw(5) << "ma DN" << setw(10) << "ten DN" << setw(10) << "ngay TL" << setw(15) << "Dien Thoai" << setw(10) << "phuong" << setw(10) << "quan" << setw(10) << "thanhPho";
            cout << setw(10) << "Giam Doc" << setw(10) << "Doanh Thu" <<endl;
            a[i].xuat();
            cout << endl << "===NHAP THONG TIN MOI===" << endl;
            a[i].nhap();
            cout << "====THONG TIN CAC DOANH NGHIEP SAU KHI SUA====" << endl;
            cout << setw(5) << "maDN" << setw(10) << "tenDN" << setw(10) << "ngayTL" << setw(15) << "dienThoai" << setw(10) << "phuong" << setw(10) << "quan" << setw(10) << "thanhPho";
            cout << setw(10) << "giamDoc" << setw(10) << "doanhThu" <<endl;
            for(int j = 0; j < n; j++){
                a[j].xuat();
            }
            dem++;
            break;
        }
    }
    if(dem == 0){
        cout << endl << "KHONG TON TAI DOANH NGHIEP CO MA VUA NHAP !!!" << endl;
    }
}
int main()
{
    DoanhNghiep a[100];
    int n;
    cout<<"Nhap so doanh nghiep: ";cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Nhanp thong tin doanh nghiep thu "<<i+1<<": \n";
        a[i].nhap();
    }
    cout<<"Thong tin cac doanh nghiep vua nhap: \n";
    cout << setw(5) << "ma DN" << setw(10) << "ten DN" << setw(10) << "ngay TL" << setw(15) << "Dien Thoai" << setw(10) << "phuong" << setw(10) << "quan" << setw(10) << "thanhPho";
            cout << setw(10) << "Giam Doc" << setw(10) << "Doanh Thu" <<endl;
    for(int i=0;i<n;i++){
        a[i].xuat();
    }
    DisplayByCity(a,n);
    sumByYear(a,n);
    modifyInfo(a,n);
    return 0;
}
