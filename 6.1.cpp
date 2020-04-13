#include <iostream>
using namespace std;
class VECTO
{
private:
    float x,y;
public:
    void nhap();
    void xuat();
     VECTO operator +(VECTO A, VECTO B);
     VECTO operator -(VECTO A, VECTO B);
};
void VECTO::nhap()
{
    cout<<"\n Nhap toa do x: ";
    cin>>x;
    cout<<"\n Nhap toa do y: ";
    cin>>y;
}
void VECTO::xuat()
{
    cout<<"("<<x<<";"<<y<<")"<<endl;
}
VECTO operator+(VECTO A, VECTO B)
{
    VECTO a;
    a.x = A.x + B.x;
    a.y = A.y + B.y;
    return a;
}
VECTO operator-(VECTO A, VECTO B)
{
    VECTO a;
    a.x = A.x - B.x;
    a.y = A.y - B.y;
    return a;
}
int main()
{
    VECTO A,B;
    cout<<"\nnhap toa do vecto A"<<endl;
    A.nhap();
    cout<<"\nnhap toa do vecto B"<<endl;
    B.nhap();
    VECTO tong = A+B;
    cout<<"\n tong 2 vecto: A + B = ";
    tong.xuat();
    VECTO hieu = A-B;
    cout<<"\n hieu 2 vecto: A - B = ";
    hieu.xuat();
    return 0;
}

