#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,d,r;
    cin >> n >> d >> r;
    while(n != 0 && d != 0 && r != 0){
        vector<int> mor_rou,eve_rou;
        int a,paid = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            mor_rou.push_back(a);
        }
        sort(mor_rou.begin(),mor_rou.end());
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            eve_rou.push_back(a);
        }
        sort(eve_rou.begin(),eve_rou.end());
        for (int i = 0; i < n; i++)
        {
            int paid_rou = (mor_rou[i]+eve_rou[n-i-1])-d;
            if(paid_rou > 0) paid += (paid_rou*r);
        }
        cout << paid << endl;
        mor_rou.clear();
        eve_rou.clear();
        cin >> n >> d >> r;
    }
}