#include <iostream>

using namespace std;
class PhanSo
{
private:
    float tuso,mauso;
public:
    void nhap();
    void xuat();
    friend PhanSo operator+(PhanSo A, PhanSo B);
    friend PhanSo operator-(PhanSo A, PhanSo B);
    friend PhanSo operator*(PhanSo A, PhanSo B);
    friend PhanSo operator/(PhanSo A, PhanSo B);
    float giatri();
};
float PhanSo::giatri()
{
    return tuso/mauso;
}
void PhanSo::nhap()
{
    cout<<"Nhap tu so: ";
    cin>>tuso;
    cout<<"Nhap mau so: ";
    cin>>mauso;
}
void PhanSo::xuat()
{
    cout<<tuso<<"/"<<mauso;
}
PhanSo operator+(PhanSo A,PhanSo B)
{
    PhanSo C;
    C.tuso = A.tuso*B.mauso + A.mauso*B.tuso;
    C.mauso = A.mauso * B.mauso;
    return C;
}
PhanSo operator-(PhanSo A,PhanSo B)
{
    PhanSo C;
    C.tuso = A.tuso*B.mauso - A.mauso*B.tuso;
    C.mauso = A.mauso*B.mauso;
    return C;
}
PhanSo operator*(PhanSo A, PhanSo B)
{
    PhanSo C;
    C.tuso = A.tuso*B.tuso;
    C.mauso = A.mauso*B.mauso;
    return C;
}
PhanSo operator /(PhanSo A, PhanSo B)
{
    PhanSo C;
    C.tuso = A.tuso*B.mauso;
    C.mauso = A.mauso*B.tuso;
    return C;
}
int main()
{
    PhanSo A,B,C;
    cout<<"Nhap phan so A: \n";
    A.nhap();
    cout<<"Nhap phan so B: \n";
    B.nhap();
    C = A + B;
    cout<<"\nTong = "<<C.giatri();
    C = A - B;
    cout<<"\nHieu = "<<C.giatri();
    C = A * B;
    cout<<"\nTich = "<<C.giatri();
    C = A / B;
    cout<<"\nThuong = "<<C.giatri();
    return 0;
}
