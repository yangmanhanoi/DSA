#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t;cin.ignore(); while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
struct Data{
    int heso, mu;
};
struct Node
{
    Data val;
    Node* next;
    Node(Data val)
    {
        this->val.heso = val.heso;
        this->val.mu = val.mu;
        this->next = nullptr;
    }
};
typedef Node* node;
void addFront(node &a, Data val)
{
    if(a)
    {
        node tmp = new Node(val);
        tmp->next = a;
        a = tmp;
    }
    else a = new Node(val);
}
void sortList(node &a)
{
    for(node i = a; i->next != nullptr; i = i->next)
    {
        node max = i;
        for(node j = i->next; j != nullptr; j = j->next)
        {
            if(j->val.mu >= max->val.mu) max = j;
        }
        swap(max->val, i->val);
    }
}
void add_or_plus(node &a, Data val)
{
    if(a)
    {
        node tmp = a;
        node i;
        for(i = a->next; i != nullptr; i = i->next)
        {
            if(i->val.mu == val.mu) break;
        }
        if(i) i->val.heso += val.heso;
        else addFront(a, val);
    }
    else a = new Node(val);
}
string s1 = "", s2 = "";
void find(string s)
{
    int i = 0;
    while(s[i] == ' ') ++i;
    while(isdigit(s[i]))
    {
    	s1 += s[i];
    	i++;
    }
    i = s.size() - 1;
    while(s[i] == ' ') --i;
    while(isdigit(s[i]))
    {
    	s2 += s[i];
    	--i;
    }
    reverse(s2.begin(), s2.end());
}
void print(node a)
{
    while(a->next != nullptr)
    {
        cout << a->val.heso << "*x^" << a->val.mu << " + ";
        a = a->next;
    }
    cout << a->val.heso << "*x^" << a->val.mu << endl;
}
int main()
{
    faster()
    test()
    {
        string fx, gx;
        getline(cin, fx);
        getline(cin, gx);
        stringstream ss(fx);
        node a = nullptr;
        while(getline(ss, fx, '+'))
        {
        	s1 = ""; s2 = "";
            find(fx);
            int heso = stoi(s1), mu = stoi(s2);
            Data val;
            val.heso = heso;
            val.mu = mu;
         //   cout << val.heso << ' ' << val.mu << endl;
            add_or_plus(a, val);
          //  cout << fx << endl;
        }
      //  cout << endl;
        stringstream ss1(gx);
        while (getline(ss1, gx, '+'))
        {
        	s1 = ""; s2 = "";
            find(gx);
            int heso = stoi(s1), mu = stoi(s2);
            Data val;
            val.heso = heso;
            val.mu = mu;
          //  cout << val.heso << ' ' << val.mu << endl;
            add_or_plus(a, val);
           // cout << gx << endl;
        }
         sortList(a);
         print(a);
    }
    return 0;
}