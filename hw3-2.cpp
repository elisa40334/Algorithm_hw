#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int cal = 0,ans = 0;
    string a,b;
    vector<int> vec;
    cin >> a >> b;
    vec.resize(b.length(),0);
    for (int i = 0; i < a.length(); i++)
    {
        int check = 0;
        for (int j = cal; j < b.length(); j++)
        {
            if (vec[j-1] != 0 && a[i] == b[j]){
                vec[j] = vec[j-1] + 1;
                cal = j+1;
                ans++;
                break;
            }
            else if(vec[j-1] != 0 && a[i] != b[j]){
                vec[j] = vec[j-1];
            }
            else if(a[i] == b[j]){
                vec.clear();
                vec.resize(b.length(),0);
                vec[j] = 1;
                cal = j+1;
                ans++;
                break;
            }
            // if(vec[j] > ans) ans = vec[j];
            // cout << vec[j] << endl;
            // if (a[i] != b[j] && vec[j] == 0)
            // {
            //     check++;
            // }
            // else 
            // else if (a[i] == b[j] && check == j){
            //     vec.clear();
            //     vec.resize(b.length());
            //     vec[j] = 1;
            // }
            
        }
    }
    vec.clear();
    vec.resize(a.length(),0);
    for (int i = 0; i < b.length(); i++)
    {
        int check = 0;
        for (int j = cal; j < a.length(); j++)
        {
            if (vec[j-1] != 0 && b[i] == a[j]){
                vec[j] = vec[j-1] + 1;
                cal = j+1;
                ans++;
                break;
            }
            else if(vec[j-1] != 0 && b[i] != a[j]){
                vec[j] = vec[j-1];
            }
            else if(b[i] == a[j]){
                vec.clear();
                vec.resize(a.length(),0);
                vec[j] = 1;
                cal = j+1;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    // cout << a << ":" << b; 
}