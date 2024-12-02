#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
vector<int> vec;
struct posi
{
    int left,right,sum;
};
posi find_max_crossing_subarray(int loww,int midd,int highh){
    posi po;
    int leftsum = INT_MIN,rightsum = INT_MIN;
    int sum = 0;
    for (int i = midd; i <= loww; i--)
    {
        sum += vec[i];
        if (sum > leftsum)
        {
            leftsum = sum;
            po.left = i;
        }
    }
    sum = 0;
    for (int i = midd+1; i <= highh; i++)
    {
        sum += vec[i];
        if (sum > rightsum)
        {
            rightsum = sum;
            po.right = i;
        }
    }
    po.sum = rightsum + leftsum;
    return po;
}

posi find_maximum_subarray(int loww,int highh){
    if (loww == highh)
    {
        posi po;
        po.left = loww;
        po.right = highh;
        po.sum = vec[loww];
        return po;
    }
    
    int midd = (loww+highh)/2;
    posi leftpo,rightpo,crosspo;
    leftpo = find_maximum_subarray(loww,midd);
    rightpo = find_maximum_subarray(midd+1,highh);
    // crosspo = find_max_crossing_subarray(loww,midd,highh);

    if (leftpo.sum >= rightpo.sum && leftpo.sum >= crosspo.sum)
    {
        return leftpo;
    }
    else if (leftpo.sum <= rightpo.sum && rightpo.sum >= crosspo.sum)
    {
        return rightpo;
    }
    return crosspo;
}

int main(){
    int a;
    posi po;
    while (cin >> a)
    {
        vec.push_back(a);
    }
    po = find_maximum_subarray(0,vec.size()-1);
    cout << po.sum << endl;
}