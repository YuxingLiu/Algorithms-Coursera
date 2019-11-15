#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<double, double> pi;

class TSP{
public:
    int MinCostHeu(int n, vector<pi> G)
    {
        vector<bool> S(n, 0);   // indicator of visited vertices
        vector<int> path;       // sequence of visited vertices

        // start tour at the first vertex
        S[0] = 1;
        path.push_back(0);
        double cost_min = 0;

        // repeatly visit the cloest vertex that hasn't been visited
        while(path.size() < n)
        {
            double d2_min = 10000000000.0;
            double dx, dy, d2;
            int i_min;
            int j = path.back();
            for(int i=1; i<n; ++i)
            {
                if(!S[i])   // vertex i hasn't been visited
                {
                    dx = G[i].first - G[j].first;
                    dy = G[i].second - G[j].second;
                    d2 = dx*dx + dy*dy;
                    if(d2_min > d2)
                    {
                        d2_min = d2;
                        i_min = i;
                    }
                }
            }

            S[i_min] = 1;
            path.push_back(i_min);
            cost_min += sqrt(d2_min);
        }

        // once every vertex has been visited exactly once, return to the first vertex
        double dx = G[0].first - G[path.back()].first;
        double dy = G[0].second - G[path.back()].second;
        cost_min += sqrt(dx*dx + dy*dy);

        return floor(cost_min);
    }
};

int main()
{
    ifstream myfile("nn.txt");
    if(!myfile.is_open())
    {
        cout << "File failed to open." << endl;
        return 0;
    }

    int n;              // number of vertices
    myfile >> n;
    vector<pi> G(n);    // coordinate of vertices

    int i;
    while(myfile >> i)
    {
        myfile >> G[i-1].first;
        myfile >> G[i-1].second;
    }
    myfile.close();

    TSP tsp;
    int cost = tsp.MinCostHeu(n, G);
    cout << "Cost of TSP heuristic = " << cost << endl;

    return 0;
}
