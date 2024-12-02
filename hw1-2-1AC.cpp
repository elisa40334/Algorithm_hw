#include<bits/stdc++.h>
using namespace std;
int vec[50001];
struct posi
{
    int high;
    int low;
    int sum;
};

posi FMCS(int low,int mid,int high){
    int lsum = INT_MIN,sum = 0,maxl,rsum = INT_MIN,maxr;
    posi po;
    for (int i = mid; i >= low; i--)
    {
        sum += vec[i];
        if(sum > lsum){
            // cout << i << "LL::" << vec[i] << "??" << sum << endl;
            lsum = sum;
            po.low = i;
        }
    }
    sum = 0;
    for (int i = mid+1; i <= high; i++)
    {
        sum += vec[i];
        if(sum > rsum){
            // cout << i << "RR::" << vec[i] << "??" << sum << endl;
            rsum = sum;
            po.high = i;
        }
    }
    po.sum = lsum + rsum;
    // cout << po.sum << "popo\n" ;
    return po;
}

posi FMS(int low,int high){
    posi po,lpo,rpo,crpo;
    po.high = high,po.low = low;
    if(high == low) {
        po.sum = vec[low];
        // cout << po.sum << "popo\n";
        return po;
    }
    int mid = (high + low)/2;
    lpo = FMS(low,mid);
    rpo = FMS(mid+1,high);
    crpo = FMCS(low,mid,high);
    if (lpo.sum >= rpo.sum && lpo.sum >= crpo.sum) return lpo;
    else if(rpo.sum >= lpo.sum && rpo.sum >= crpo.sum) return rpo;
    return crpo;
}

int main(){
    int a,cal = 0;
    posi po;
    while (cin >> a)
    {
        vec[cal++] = a;
    }
    po = FMS(0,cal-1);
    // cout << cal-1;
    cout << po.sum << "\n";
}