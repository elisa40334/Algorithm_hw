#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
struct edge{
    int n1,n2,weig;
};
int cmpe(const void *a,const void *b){
    edge aa = *(edge*)a;
    edge bb = *(edge*)b;
    if(aa.weig == bb.weig) {
        if(aa.n1 == bb.n1) {
            if(aa.n2 == bb.n2) return 0;
            return (aa.n2 > bb.n2) ? 1 : -1;
        }
        return (aa.n1 > bb.n1) ? 1 : -1;
    }
    return (aa.weig > bb.weig) ? 1 : -1;
}

int main(){
    int cal = 0,max = 0;
    edge line[40001];
    vector<int> check[40001],adj[40001],tree;

    while (cin >> line[cal].n1 >> line[cal].n2 >> line[cal].weig) {
        if(line[cal].n1 > max) max = line[cal].n1;
        else if(line[cal].n2 > max) max = line[cal].n2;
        adj[line[cal].n1].push_back(line[cal].n2);
        adj[line[cal].n2].push_back(line[cal].n1);
        cal++;
    }
    qsort(line, cal, sizeof(edge), cmpe);
    
    for (int i = 0; i < cal; i++)
    {
        int exist = 0;
        for (int j = 0; j < check[line[i].n1].size(); j++)
        {
            if(check[line[i].n1][j] == line[i].n2){
                exist = 1;
                break;
            }
        }
        if(exist == 0){
            vector<int> vec;
            tree.push_back(i);
            check[line[i].n1].push_back(line[i].n2);
            check[line[i].n2].push_back(line[i].n1);

            vec.insert(vec.end(),check[line[i].n1].begin(),check[line[i].n1].end());
            vec.insert(vec.end(),check[line[i].n2].begin(),check[line[i].n2].end());
            sort(vec.begin(), vec.end());
            vector<int>::iterator ite = unique(vec.begin(), vec.end());
            vec.erase(ite, vec.end());
            for (int j = 0; j < vec.size(); j++) {
                check[vec[j]].clear();
                check[vec[j]].assign(vec.begin(), vec.end());
            }
            vec.clear();
        }
    }
    
    cout << "Adjacency list:\n";
    for (int i = 0; i <= max; i++)
    {
        cout << i << ": ";
        sort(adj[i].begin(), adj[i].end());
        for (int j = 0; j < adj[i].size(); j++) cout << adj[i][j] << " -> ";
        cout << "end" << endl;
    }
    cout << "\nminimum spanning tree:\n";
    int cost = 0;
    for (int i = 0; i < tree.size(); i++) {
        cout << i+1 << ": <" << line[tree[i]].n1 << "," << line[tree[i]].n2 << ">\n";
        cost += line[tree[i]].weig;
    }
    cout << "\nThe cost of minimum spanning tree: " << cost << "\n";
}