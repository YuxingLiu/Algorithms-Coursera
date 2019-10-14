#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>    // for find(), min()

using namespace std;

typedef pair<int, int> pi;

struct greater1{
    bool operator()(const pi& a, const pi& b) const{
        return a.second > b.second;
    }
};

class ShortestPath{
public:
    vector<int> Dijkstra(int n, vector<int> E[], vector<int> F[], int s){
        vector<int> X;                  // initialize X as empty set
        vector<int> key(n+1, 1000000);  // initialize distance as 1000000 except 0 at sourse
        key[s] = 0;

        //priority_queue <pi, vector<pi>, greater<pi> > H;    // create a min heap ordered by first element of pair
        //for(int i=1; i<=n; ++i)
        //    H.push(make_pair(key[i], i));

        vector<pi> H(n);
        for(int i=1; i<=n; ++i)
        {
            H[i-1].first = i;
            H[i-1].second = key[i];
        }
        // create a min heap ordered by second element of pair
        make_heap(H.begin(), H.end(), greater1());

        pi  W;
        int w;
        while(!H.empty())
        {
            // extract min from H
            pop_heap(H.begin(), H.end(), greater1());
            W = H.back();
            H.pop_back();
            w = W.first;
            key[w] = W.second;
            X.push_back(w);

            //cout << "debug, w = " << w << ", len(w) = " << key[w] << endl;

            // update heap to maintain invariant
            for(int i=0; i<E[w].size(); ++i)
            {
                int y = E[w][i];
                if( find(X.begin(), X.end(), y) == X.end() )    // y is not-yet-processed
                {   
                    int j=0;
                    for(; j<H.size(); ++j)
                    {
                        if(y == H[j].first)                     // find y in H
                            break;
                    }

                    key[y] = min(H[j].second, key[w] + F[w][i]);// update key of y

                    H.erase(H.begin() + j);                     // remove y from H
                    make_heap(H.begin(), H.end(), greater1());  // heapify after deletion (can be improved)

                    H.push_back(make_pair(y, key[y]));          // insert y into H
                    push_heap(H.begin(), H.end(), greater1());  // reorder elements after insertion

                    //cout << "debug, y = " << y << ", key(y) = " << key[y] << endl;
                }
            }
        }

        return key;
    }
};

int main()
{
    ifstream myfile("dijkstraData.txt");
    if(!myfile.is_open())
    {
        cout << "File failed to open" << endl;
        return 0;
    }

    int n = 200;            // number of vertices
    vector<int> E[n+1];     // edges
    vector<int> F[n+1];     // length of edges
    string line;
    char comma;
    int i, v, w;


    while(getline(myfile, line))
    {
        stringstream ss(line);
        ss >> i;
        while( ss >> v >> comma >> w )
        {
            E[i].push_back(v);
            F[i].push_back(w);
        }
        //cout << i << ',' << E[i].back() << ',' << F[i].back() << '\n';
    }
    myfile.close();

    ShortestPath sp;
    vector<int> len;
    len = sp.Dijkstra(n, E, F, 1);

    int v_out[] = {7, 37, 59, 82, 99, 115, 133, 165, 188, 197};

    for(auto i : v_out)
        cout << len[i] << ',';
    cout << endl;

    return 0;
}
