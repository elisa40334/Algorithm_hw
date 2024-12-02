#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,a;
    cin >> m;
    for (int j = 0; j < m; j++)
    {
        int h,n,des = 1;
        cin >> h >> n;
        for (int i = 0; i < h-1; i++)
        {
            if(n % 2 == 0) des = des*2+1;
            else des *= 2;
            if (n > 1)
            {
                if(n % 2 == 0) n /= 2;
                else n = n/2+1;
            }
        }
        cout << des << "\n";
    }
    cin >> a;
}