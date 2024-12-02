#include<iostream>
using namespace std;

int main(){
    int n,p[50001],a[2],r[50001];
    cin >> n;
    cin >> a[0] >> a[1];
    while (a[0] != 0 && a[1] != 0)
    {
        if(a[0] <= n) p[a[0]] = a[1];
        cin >> a[0] >> a[1];
    }
    
    r[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        int q = -1e8;
        for (int i = 1; i <= j; i++)
        {
            if(p[i]+r[j-i] > q)q = p[i]+r[j-i];
        }
        r[j] = q;
    }
    
    cout << r[n] << endl;
}