#include<stdio.h>
int tongNguoiTV = 0;
struct Phuong
{
    char tenPhuong[50];
    char ma[20];
    int caNhiem, caTV, caKB;
};
void nhap(struct Phuong *a)
{
    getchar();
    gets(a->tenPhuong);
    gets(a->ma);
    scanf("%d%d", &a->caNhiem, &a->caTV);
    a->caKB = a->caNhiem - a->caTV;
}
void in(struct Phuong a)
{
    printf("Ten phuong: %s\n", a.tenPhuong);
    printf("Ma: %s\n", a.ma);
    printf("So ca nhiem: %d ca\n", a.caNhiem);
    printf("So ca tu vong: %d ca\n", a.caTV);
}
void sapxep(struct Phuong a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i].caKB < a[j].caKB)
            {
                struct Phuong tmp;
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp; 
            }
        }
    }
}
void hienThi(struct Phuong a)
{
    printf("%-20s %-20d %-20d\n", a.tenPhuong, a.caNhiem, a.caKB);

}
int main()
{
    int n; scanf("%d", &n);
    struct Phuong a[n + 5];
    for(int i = 0; i < n; i++)
    {
        nhap(&a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        in(a[i]);
        tongNguoiTV += a[i].caTV;
    }
    printf("Tong so nguoi tu vong: %d\n", tongNguoiTV);
    sapxep(a, n);
    printf("%-20s %-20s %-20s\n", "Ten phuong", "So ca nhiem", "So ca khoi benh");
    for(int i = 0; i < n; i++) hienThi(a[i]);
    return 0;
}