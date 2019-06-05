#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class MinSpanTree {
public:
    long long prim(int n, int m, vector<vector<int> > E){
        vector<int> X;
        vector<vector<int> > T;

        // initialize X with first node
        X.push_back(1);

        // Prim's MST (simpler version)
        vector<int> e(3);
        int v;
        int minCost;
        bool flag0, flag1;
        vector<bool> iX (n, 0);
        iX[0] = 1;

        for(int j=1; j<n; ++j)
        {
            minCost = INT_MAX;
            for(int i=0; i<m; ++i)
            {
                flag0 = iX[E[i][0]-1];
                flag1 = iX[E[i][1]-1];

                if((flag0 ^ flag1) && (E[i][2] < minCost)){
                    minCost = E[i][2];
                    e[0] = E[i][0];
                    e[1] = E[i][1];
                    e[2] = E[i][2];
                    if(flag1 == 0)
                        v = e[1];
                    else
                        v = e[0];
                }
            }
            T.push_back(e);
            X.push_back(v);
            iX[v-1] = 1;
        }

        // calculate sum of edge costs
        long long sum = 0;
        for(int j=0; j<T.size(); ++j)
            sum += T[j][2];

        return sum;
    }
};

int main()
{
    ifstream myfile;
    myfile.open("edges.txt");

    int m, n;
    myfile >> n;  // number of nodes
    myfile >> m;  // number of edges

    vector<vector<int> > E(m, vector<int>(3));

    for(int i=0; i<m; ++i)
    {
        myfile >> E[i][0];
        myfile >> E[i][1];
        myfile >> E[i][2];
    }

    MinSpanTree mst;
    long long sum = mst.prim(n, m, E);

    cout << sum << endl;
    return 0;
}
