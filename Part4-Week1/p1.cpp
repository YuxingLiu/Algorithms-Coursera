#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class APSP{
public:
    int FloydWarshall(int n, vector<int> E[], vector<int> F[]){
        // initialization
        vector<vector<vector <int>>> A(n+1, vector<vector <int>>(n+1, vector<int>(n+1, 1000000)));
        for(int i=1; i<=n; ++i)
        {
            A[i][i][0] = 0;
            for(int it=0; it<E[i].size(); ++it)
            {
                int j = E[i][it];
                A[i][j][0] = F[i][it];
            }
        }

        // DP recurrence
        for(int k=1; k<=n; ++k)
        {
            for(int i=1; i<=n; ++i)
            {
                for(int j=1; j<=n; ++j)
                {
                    A[i][j][k] = min(A[i][j][k-1], A[i][k][k-1] + A[k][j][k-1]);
                }
            }
        }

        // check negative cycle
        for(int i=1; i<=n; ++i)
        {
            if(A[i][i][n] < 0)
            {
                cout << "Negative cycle found." << endl;
                throw "NULL";
            }
        }

        // find the shortest u-v path from all edges
        int sp = 0;
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                if(sp > A[i][j][n])
                    sp = A[i][j][n];
            }
        }

        return sp;
    }

    int min(int x, int y)
    {
        if(x < y)
            return x;
        else
            return y;
    }
};

int main()
{
    ifstream myfile("g1.txt");
    if(!myfile.is_open())
    {
        cout << "File failed to open." << endl;
        return 0;
    }

    int n,m;
    myfile >> n;    // number of vertices
    myfile >> m;    // number of edges

    vector<int> E[n+1];     // outgoing edges (for which i is the tail)
    vector<int> F[n+1];     // length of edges

    int i,j,l;
    while(myfile >> i)
    {
        myfile >> j;
        myfile >> l;
        E[i].push_back(j);
        F[i].push_back(l);
    }
    myfile.close();

    APSP apsp;

    try{
        int sp = apsp.FloydWarshall(n, E, F);
        cout << "Shortest path = " << sp << endl;
    } catch (const char* msg) {
        cerr << msg << endl;
    }


    return 0;
}
