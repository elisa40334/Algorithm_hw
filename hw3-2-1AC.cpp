#include<iostream>
#include<string>
#include<vector>
using namespace std;
int c[20000][20000];
void LCSlength(string x,string y){
    for (int i = 1; i <= x.length(); i++) c[i][0] = 0;
    for (int i = 0; i <= y.length(); i++) c[0][i] = 0;
    for (int i = 1; i <= x.length(); i++)
    {
        for (int j = 1; j <= y.length(); j++)
        {
            if (x[i] == y[j]) c[i][j] = c[i-1][j-1]+1;
            else if (c[i-1][j] >= c[i][j-1]) c[i][j] = c[i-1][j];
            else c[i][j] = c[i][j-1];
        }
    }
    return;
}

int main(){
    string x,y;
    cin >> x >> y;
    LCSlength(x,y);
    cout << c[x.length()][y.length()] << endl;
}