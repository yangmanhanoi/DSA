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
    Node* pre;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->pre = NULL;
    }
};
typedef Node* node;
void addBack(node &a, int val)
{
    if(a)
    {
        node tmp = a;
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        node newNode = new Node(val);
        tmp->next = newNode;
        newNode->pre = tmp;
    }
    else a = new Node(val);
}
void addFront(node &a, int val)
{
    if(a)
    {
        node tmp = new Node(val);
        tmp->next = a;
        a->pre = tmp;
        a = tmp;
    }
    else a = new Node(val);
}
void deleteX(node &a, int val)
{
    if(a)
    {
        // TH node đầu tiên có giá trị = val
        if(a->val == val)
        {
            // nếu có từ 2 node trở lên trong dslk
            if(a->next != nullptr)
            {
                a = a->next;
                a->pre = nullptr;
             //   a = a->next;
                return;
            }
            // nếu chỉ có 1 node trong dslk
            else
            {
                a = nullptr;
                return;
            }
        }
        // TH có 1 node trong dslk nhưng k có giá trị bằng val
        else if(a->val != val and a->next == nullptr) return;
        else
        {
            node sau = a;
            node truoc = nullptr;
            while(sau->next != nullptr and sau->val != val)
            {
                truoc = sau;
                sau = sau->next;
            }
            // Tìm thấy node có giá trị là val trong dslk
            if(sau->val == val)
            {
                // node có giá trị bằng val ở cuối dslk
                if(sau->next == nullptr) truoc->next = nullptr;
                else
                {
                    sau = sau->next;
                    sau->pre = truoc;
                    truoc->next = sau;
                }
            }
            // Không tìm thấy val
            else return;
        }
    }
    else return;
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
        else if(k == 2)
        {
            cin >> x;
            addFront(a, x);
        }
        else if(k == 3)
        {
            cin >> x;
            deleteX(a, x);
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
// void delete(node &a, int val)
// {

// }