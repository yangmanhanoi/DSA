#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define test() int t; cin >> t; while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
struct Node
{
    int val;
    Node* next;
    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};
typedef Node* node;
void addFirst(node &a, int val)
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
        node min = i;
        for(node j = i->next; j != nullptr; j = j->next)
        {
            if(j->val <= min->val) min = j;
        }
        swap(i->val, min->val);
    }
}
void print(node a)
{
    while(a != nullptr)
    {
        cout << a->val << ' ';
        a = a->next;
    }
}
int main()
{
    faster()
    int n; cin >> n;
    int x;
    node a = nullptr;
    while(n--)
    {
        cin >> x;
        addFirst(a, x);
    }
    sortList(a);
    print(a);
    return 0;
}