#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class DP{
public:
    string mwis(vector<int> W){
        int n = W.size();
        vector<long long> V(n); // value function
        vector<bool> S(n);      // max weight independent set

        V[0] = W[0];
        V[1] = max(W[0], W[1]);
        for(int i=2; i<n; ++i){
            V[i] = max(V[i-1], V[i-2] + W[i]);
        }

        // reconstruction
        int i = n-1;
        while(i>=2){
            if( V[i-1] >= V[i-2] + W[i])
                i--;
            else{
                S[i] = true;
                i -= 2;
            }
        }
        if(S[2] == true)
            S[0] = true;
        else{
            if(W[0] >= W[1])
                S[0] = true;
            else
                S[1] = true;
        }

        int vertices[8] = {1,2,3,4,17,117,517,997};
        string str;
        for(int i=0; i<8; ++i){
            if(S[vertices[i]-1])
                str += "1";
            else
                str += "0";
        }
        return str;
    }
};

int main()
{
    ifstream myfile;
    myfile.open("mwis.txt");

    int n;              // number of vertices
    myfile >> n;

    vector<int> W(n);

    for(int i=0; i<n; ++i)
        myfile >> W[i];

    DP dp;
    string str = dp.mwis(W);

    cout << str << endl;
    return 0;
}
