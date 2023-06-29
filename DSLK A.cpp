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
        this->next = NULL;
    }
};
typedef struct Node* node;
void addBack(node& list, int val)
{
    if(list)
    {
        node tmp = list;
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new Node(val);
    }
    else list = new Node(val);
}
void addFront(node &a, int val)
{
    if(a)
    {
        node tmp = new Node(val);
        tmp->next = a;
        a = tmp;
    }
    else a = new Node(val);
}
void print(node a)
{
    while(a != NULL)
    {
        cout << a->val << ' ';
        a = a->next;
    }
}
int main()
{
    faster()
    node a = NULL;
    test()
    {
        int k, x; cin >> k;
        if(k == 1)
        {
            cin >> x;
            addBack(a, x);
        }
        else if( k == 2)
        {
            cin >> x;
            addFront(a, x);
        }
        else
        {
            if(a == NULL) continue;
            print(a);
            cout << endl;
        }
    }
    return 0;
}
