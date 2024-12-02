#include<iostream>
using namespace std;
struct num
{
    float x,y;
};

int main(){
    num a;
    float m,n;

    while (cin >> m >> n)
    {
        if (m == 1 && n == 1) break;
        num ll,mm,rr;
        a.x = 0,a.y = 1;
        ll = a;
        a.x = 1;
        mm = a;
        a.y = 0;
        rr = a;
        while (1)
        {
            long double t1 = (long double)m/n, t2 = (long double)mm.x/mm.y;
            if(t1<t2){
                // cout << "L:" << mm.x << "/" << mm.y << "::LL--::" << fabs((m/n)-((vec[1-1].x+mm.x)/(vec[1-1].y+mm.y)))<< "::RR--::" << fabs((m/n)-((vec[1+1].x+mm.x)/(vec[1+1].y+mm.y)));
                cout << "L";
                rr = mm;
                a.x = ll.x+mm.x,a.y = ll.y+mm.y;
                mm = a;
            }
            else if(t1>t2)
            {
                // cout << "R:" << mm.x << "/" << mm.y << "::LL--::" << fabs((m/n)-((vec[1-1].x+mm.x)/(vec[1-1].y+mm.y)))<< "::RR--::" << fabs((m/n)-((vec[1+1].x+mm.x)/(vec[1+1].y+mm.y)));
                cout << "R";
                ll = mm;
                a.x = rr.x+mm.x,a.y = rr.y+mm.y;
                mm = a;
            }
            else break;
        // cout << "\n" << mm.x << "/" << mm.y << "::LL--::" << fabs((m/n)-((vec[1-1].x+mm.x)/(vec[1-1].y+mm.y)))<< "::RR--::" << fabs((m/n)-((vec[1+1].x+mm.x)/(vec[1+1].y+mm.y)));;; 
        }
        cout << "\n";
    }
}