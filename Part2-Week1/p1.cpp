#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class SCC {
public:
    vector<long long> TopoSort(long long n, vector<long long> E[]){
        vector<long long> V(n+1);   // mark all vertices as unexplored
        vector<long long> f(n+1);   // initialize f-value to 0
        vector<long long> g(n);     // vertices in increasing order of the f-value
        long long label = n;        // keep track of ordering

        for(long long i=1; i<=n; ++i)
        {
            if(V[i] == 0)   // if i is unexplored in a prior DFS
                DFS_Topo(n, E, i, V, g, f, label);
        }

        return g;   // export the vertices in order of their positions
    }

    void DFS_Topo(long long n, vector<long long> E[], long long s, vector<long long>& V, vector<long long>& g, vector<long long>& f, long long& label){
        V[s] = 1;       // mark s as explored

        for(auto i : E[s])
        {
            if(V[i] == 0)
                DFS_Topo(n, E, i, V, g, f, label);
        }

        f[s] = label--;
        g[label] = s;
    }

    vector<long long> Kosaraju(long long n, vector<long long> E_out[], vector<long long> E_in[]){
        vector<long long> g(n);     // reversed topological order
        g = TopoSort(n, E_in);      // first pass of DFS

        vector<long long> V(n+1);   // mark all vertices as unexplored
        long long numSCC = 0;       // number of SCC
        long long sizeSCC;          // size of one SCC
        vector<long long> scc_size; // size of all SCCs

        // second pass of DFS
        for(auto i : g)
        {
            if(V[i] == 0)
            {
                numSCC++;
                sizeSCC = 0;
                DFS_SCC(n, E_out, i, V, numSCC, sizeSCC);
                scc_size.push_back(sizeSCC);
            }
        }

        cout << "number of SCC is " << numSCC << endl;

        sort(scc_size.begin(), scc_size.end(), greater<long long>());

        if(scc_size.size() > 5)
        {
            vector<long long> scc_5(scc_size.begin(), scc_size.begin()+5);
            return scc_5;
        }
        else
            return scc_size;        
    }

    void DFS_SCC(long long n, vector<long long> E[], long long s, vector<long long>& V, long long numSCC, long long& sizeSCC){
        V[s] = numSCC;   // mark s as explored
        sizeSCC++;

        for(auto i : E[s])
        {
            if(V[i] == 0)
                DFS_SCC(n, E, i, V, numSCC, sizeSCC);
        }
    }
};

int main()
{
    ifstream myfile;
    myfile.open("SCC.txt");
    long long n = 875714;	// number of vertices

    vector<long long> E_out[n+1];	// outgoing edges (for which i is the tail)
    vector<long long> E_in[n+1];	// incoming edges (for which i is the head)

    long long vi, vo;

    while(myfile >> vi)
    {
        myfile >> vo;
	if(vi != vo)
	{
	    E_out[vi].push_back(vo);
	    E_in[vo].push_back(vi);
	}
    }

    SCC scc;
    vector<long long> scc_size;
    scc_size = scc.Kosaraju(n, E_out, E_in);

    for(auto i : scc_size)
        cout << i << ' ';
    cout << endl;

    return 0;
}
