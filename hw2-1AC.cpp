#include<iostream>
#include<vector>
using namespace std;
vector<int> start,endd,ans;

int main(){
    int num,starttime,endtime,cal = 0;

    while (cin >> num >> starttime >> endtime)
    {
        start.push_back(starttime);
        endd.push_back(endtime);
    }
    ans.push_back(1);
    for (int i = 1; i < num; i++)
    {
        if (endd[cal] <= start[i])
        {
            ans.push_back(i+1);
            cal = i;
        }
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
}