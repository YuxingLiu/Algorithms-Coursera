#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <list>
#include <ctime>            // for time()
#include <cstdlib>          // for srand()
#include <cmath>            // for log()
#include <bits/stdc++.h>    // for INT_MAX

using namespace std;

class MinCut{
public:
    int karger(map<int, list<int> > G)
    {
        int n = G.size();
        // if there are 2 vertices or less, return the num of edges
        if(n <= 2)
            return G.begin()->second.size();

        // run algorithm many times, and return the smallest cut
        int min = INT_MAX;
        int curr;
        //int N = n*n*ceil(log(n));
        int N = 1000;

        for(int i=0; i<N; ++i)
        {
            curr = contraction(G);
            if(min > curr)
                min = curr;
            if(i%100 == 0)
                cout << "iter = " << i << ", min = " << min << endl;
        }

        return min;
    }

    int contraction(map<int, list<int> > G)
    {
        int n = G.size();
        // if there are 2 vertices or less, return the num of edges
        if(n <= 2)
            return G.begin()->second.size();

        // pick a remaining edge (u,v) uniformly at random
        int m = 0;
        for(map<int, list<int> >::iterator it=G.begin(); it!=G.end(); ++it)
            m += it->second.size(); // count the num of edges

        if(m==0)
            cout << "m = 0, n = " << n << endl;
        srand(time(0));             // initialize random number generator
        int e = rand() % m + 1;     // random number e in the range 1 to m

        int e1 = 1;
        int u, v;
        for(map<int, list<int> >::iterator it=G.begin(); it!=G.end(); ++it)
        {
            for(list<int>::iterator j=it->second.begin(); j!=it->second.end(); ++j)
            {
                if(e1 == e)
                {
                    u = it->first;
                    v = *j;
                }
                e1++;
            }
        }

        // merge u and v into single vertice
        G[u].remove(v);             // delete (u,v) edge
        G[v].remove(u);

        for(list<int>::iterator j=G[v].begin(); j!=G[v].end(); ++j)
        {
            G[u].push_front(*j);    // add v's list to u's list
            for(list<int>::iterator k=G[*j].begin(); k!=G[*j].end(); ++k)
            {
                if(*k == v)
                    *k = u;         // rename edges with node v by u;
            }
        }

        G.erase(v);                 // delete node v

        return contraction(G);
    }
};

int main()
{
    ifstream myfile("kargerMinCut.txt");
    if(!myfile.is_open()){
        cout << "File failed to open" << endl;
        return 0;
    }

    map<int, list<int> > G;
    string line;
    int u, v;

    while(getline(myfile, line))
    {
        stringstream ss(line);
        ss >> u;
        while(ss >> v)
            G[u].push_back(v);
    }

    //cout << G.size() << "\t" << G[1].size() << "\t" << G[1].front() << endl;

    MinCut mc;
    int c = mc.karger(G);

    cout << c << endl;

    return 0;
}
