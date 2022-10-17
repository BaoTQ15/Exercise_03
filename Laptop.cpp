#include<iostream>
#include<string.h>
using namespace std;

class MatHang
{
protected:
    string ma_hang;
    string ten_hang;
    string hang_san_xuat;
    long int don_gia;
public:
    MatHang();
    ~MatHang();
    void Nhap();
    void Xuat();
    string get_ten_hang();
};
MatHang::MatHang()
{
    ma_hang="abc123";
    ten_hang="Sirius";
    hang_san_xuat="Yamaha";
    don_gia=21000000;
}
MatHang::~MatHang(){};
void MatHang::Nhap()
{
    cout<<"\tMa hang: ";
    fflush(stdin);
    getline(cin,ma_hang);
    cout<<"\tTen hang: ";
    fflush(stdin);
    getline(cin,ten_hang);
    cout<<"\tHang san xuat: ";
    fflush(stdin);
    getline(cin,hang_san_xuat);
    cout<<"\tDon gia(VND): ";
    cin>>don_gia;
}
void MatHang::Xuat()
{
    cout<<"\tMa hang: "<<ma_hang<<endl;
    cout<<"\tTen hang: "<<ten_hang<<endl;
    cout<<"\tHang san xuat: "<<hang_san_xuat<<endl;
    cout<<"\tDon gia: "<<don_gia<<" VND"<<endl;
}
string MatHang::get_ten_hang()
{
    return ten_hang;
}

class Laptop:public MatHang
{
private:
    string cpu;
    int ram;
    string he_dieu_hanh;
    float trong_luong;
public:
    void Nhap();
    void Xuat();
    string get_hang_san_xuat();
    long int get_gia();
};
void Laptop::Nhap()
{
    MatHang::Nhap();
    cout<<"\tCPU: ";
    fflush(stdin);
    getline(cin,cpu);
    cout<<"\tRam(gb): ";
    cin>>ram;
    cout<<"\tHe dieu hanh: ";
    fflush(stdin);
    getline(cin,he_dieu_hanh);
    cout<<"\tTrong luong(kg): ";
    cin>>trong_luong;
}
void Laptop::Xuat()
{
    MatHang::Xuat();
    cout<<"\tCPU: "<<cpu<<endl;
    cout<<"\tRam(gb): "<<ram<<endl;
    cout<<"\tTrong luong(kg): "<<trong_luong<<endl;
}
string Laptop::get_hang_san_xuat()
{
    return hang_san_xuat;
}
long int Laptop::get_gia()
{
    return don_gia;
}
int main()
{
    int n;
    Laptop *a;
    string hang_lap_top;
    cout<<"Nhap so luong Laptop: ";
    cin>>n;
    a=new Laptop[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Nhap Laptop("<<i<<"): "<<endl;
        (a+i)->Nhap();
    }
    cout<<"Nhap hang Laptop can tim: ";
    fflush(stdin);
    getline(cin,hang_lap_top);
    int tim=0;
    for(int i=0;i<n;i++)
    {
        if((a+i)->get_hang_san_xuat()==hang_lap_top)
        {
            (a+i)->Xuat();
            tim=1;
        }
    }
    if(tim==0)
        cout<<"Khong co hang Laptop ma ban tim."<<endl;
    long int min_gia=a->get_gia();
    for(int i=1;i<n;i++)
    {
        if((a+i)->get_gia()<min_gia)
            min_gia=(a+i)->get_gia();
    }
    cout<<"Laptop co gia tri thap nhat: "<<endl;
    for(int i=0;i<n;i++)
    {
        if((a+i)->get_gia()==min_gia)
            cout<<"\t"<<(a+i)->get_ten_hang()<<endl;
    }
    return 0;
}
