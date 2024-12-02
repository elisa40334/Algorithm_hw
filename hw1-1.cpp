#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
vector<int> ans;
int check = 0;

void devide(vector<int> a){
    int mid = (a.size())/2-1;
    if(mid == -1) return;
    // cout << "\n" << mid << " ::";
    vector<int> ll;
    vector<int> rr;
    // cout << "\n";
    for (int i = 0; i <= mid; i++) {
        ll.push_back(a[i]);
        // cout << a[i] << " ";
    }
    // cout << "\n";
    for (int i = mid+1; i < a.size(); i++) {
        rr.push_back(a[i]);
        // cout << a[i] << " ";
    }
    if (ll.size() == 1)
    {
        check = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            if(ans[i] > ll[0]){
                ans.insert(ans.begin()+i,ll[0]);
                check = 1;
                // cout << "aa" << ll[0] << "aab\n"; 
                break;
            }
        }
        if(!check) ans.push_back(ll[0]);
    }
    if (rr.size() == 1)
    {
        check = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            if(ans[i] > rr[0]){
                ans.insert(ans.begin()+i,rr[0]);
                check = 1;
                break;
            }
        }
        if(!check) ans.push_back(rr[0]);
    }
    devide(ll);
    devide(rr);
}

int main(){
    int a;
    while (cin >> a)
    {
        vec.push_back(a);
    }
    devide(vec);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout <<"\n";
}