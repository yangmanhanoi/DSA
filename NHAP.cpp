#include <bits/stdc++.h>
#define test int t; cin >> t; while (t--)
#define endl '\n'
#define ll long long
using namespace std;
int maCTV = 0;
int maCV = 0;
class Hunam
{
    private:
        string ten, diaChi, soDT;
    public:
        friend istream& operator >>(istream& in,const Hunam &a)
        {
            in >> a.ten >> a.diaChi >> a.soDT;
        }
    
};
class CTV: public Hunam{
    private:
        string maCTV;
        string trinhDo;
    public:
        friend istream& operator >>(istream& in,const CTV &a)
        {
            in >> a.maCTV >> a.trinhDo
        }
};
class CV()
{
    private:
        string maCV, tenCV, kieuCV;
        int kinhPhi;

};
int main()
{
    
    return 0;
}