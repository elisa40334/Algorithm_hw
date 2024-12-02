#include<bits/stdc++.h>
using namespace std;
vector<int> ans;

vector<int> mergee(vector<int> a,vector<int> b){
    int cal = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (b[cal] < a[i])
        {
            a.insert(a.begin()+i,b[cal++]);
            if(cal >= b.size()) break;
        }
    }
    for (int i = cal; i < b.size(); i++) a.push_back(b[i]);
    return a;
}

vector<int> sortt(vector<int> v){
    int mid = (v.size())/2-1;
    vector<int> ll;
    vector<int> rr;
    for (int i = 0; i <= mid; i++) ll.push_back(v[i]); //切割出左邊的陣列
    for (int i = mid+1; i < v.size(); i++) rr.push_back(v[i]); //切割出右邊的陣列
    if(ll.size() != 1) ll = sortt(ll); //若左邊陣列長度不為一則繼續切割
    if(rr.size() != 1) rr = sortt(rr); //同上
    return mergee(ll,rr); //切割完成後，往上合併排序，return
}

int main(){
    int a;
    vector<int> vec;
    while (cin >> a) vec.push_back(a);
    ans = sortt(vec);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";
}