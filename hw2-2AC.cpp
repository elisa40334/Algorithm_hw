#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;
struct item
{
    double price,weig;
};
int cmp(const void * a, const void * b){
    item aa = *(item *)a;
    item bb = *(item *)b;
    if (aa.price/aa.weig == bb.price/bb.weig) return 0;
    return (aa.price/aa.weig < bb.price/bb.weig) ? 1 : -1;
}

int main(){
    item items[100000];
    double n,p,w,ans;
    int cal = 0,j =0;
    cin >> n;
    while (cin >> items[cal].price >> items[cal].weig){
        cal++; 
    }

    qsort(items, cal, sizeof(item), cmp);

    // for (int i = 0; i < cal; i++)
    // {
    //     cout << items[i].price << ":" << items[i].weig << "\n";
    // }
    while (n != 0)
    {
        if(items[j].weig < n) {
            n -= items[j].weig;
            ans += items[j].price;
        }
        else if(items[j].weig == n){
            ans += items[j].price;
            break;
        }
        else
        {
            ans += (items[j].price/items[j].weig)*n;
            break;
        }
        j++;
    }
    printf("%lf\n",ans);
}