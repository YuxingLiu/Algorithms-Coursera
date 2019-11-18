#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <functional>   // for bind()
#include <algorithm>    // for generate(), sort(), set_symmetric_difference()
#include <set>
#include <map>

using namespace std;

class TwoSAT{
public:
    bool Papadim(vector< vector<int>> C)
    {
        while(reduction(C)){;}

        int nC = C.size();
        set<int> Xset;
        for(int i=0; i<nC; ++i)
        {
            Xset.insert(abs(C[i][0]));
            Xset.insert(abs(C[i][1]));
        }

        int nX = Xset.size();
        map<int, int> Xmap;
        int iX = 0;
        for(set<int>::iterator it = Xset.begin(); it != Xset.end(); ++it)
            Xmap.insert(pair<int,int>(*it, iX++));
        cout << endl << "nX = " << nX << "\n\n";

        int N = 10;         // number of independent tests
        int M = 2*nX*nX;    // number of steps per test
        int b1, b2;

        // repeat N times
        for(int i=0; i<N; ++i)
        {
            cout << "independent test = " << i << endl;
            // choose random initial assignment
            vector<bool> X = XGen(nX);

            // repeat M times
            for(int j=0; j<M; ++j)
            {
                // check whether current assignment satisfies all clauses
                bool flag = true;
                for(int k=0; k<nC; ++k)
                {
                    if(C[k][0] > 0)
                        b1 = X[Xmap[C[k][0]]];
                    else
                        b1 = !X[Xmap[-C[k][0]]];

                    if(C[k][1] > 0)
                        b2 = X[Xmap[C[k][1]]];
                    else
                        b2 = !X[Xmap[-C[k][1]]];

                    if(!b1 && !b2)
                    {
                        flag = false;
                        if(intGen() == 0)
                        {
                            if(C[k][0] > 0)
                                X[Xmap[C[k][0]]] = true;
                            else
                                X[Xmap[-C[k][0]]] = false;
                        }
                        else
                        {
                            if(C[k][1] > 0)
                                X[Xmap[C[k][1]]] = true;
                            else
                                X[Xmap[-C[k][1]]] = false;
                        }
                        break;
                    }
                }

                if(flag)
                    return 1;
            }
        }

        return 0;
    }

    int reduction(vector< vector<int>>& C)
    {
        int nC = C.size();

        // store positive x_i and negative x_i in two sets
        set<int> X1;
        set<int> X0;
        for(int i=0; i<nC; ++i)
        {
            if(C[i][0] > 0)
                X1.insert(C[i][0]);
            else
                X0.insert(-C[i][0]);

            if(C[i][1] > 0)
                X1.insert(C[i][1]);
            else
                X0.insert(-C[i][1]);
        }

        // find and remove variables appeared in only one vector by taking symmetric difference
        vector<int> V(2*nC);
        vector<int>::iterator it = set_symmetric_difference(X0.begin(), X0.end(), X1.begin(), X1.end(), V.begin());
        V.resize(it-V.begin());

        cout << "remove " << V.size() << " variables" << endl;

        // remove elements in X and C with value v
        vector< vector<int>> C1;
        for(int i=0; i<nC; ++i)
        {
            vector<int> c = C[i];
            bool flag = true;
            for(auto v:V)
            {
                if(abs(c[0]) == v || abs(c[1]) == v)
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
                C1.push_back(c);
        }

        C.resize(C1.size());
        for(int i=0; i<C1.size(); ++i)
        {
            C[i] = C1[i];
        }
        cout << "nC = " << C.size() << endl;

        return V.size();
    }

    vector<bool> XGen(int n)
    {
        random_device rd;       // to obtain a seed for the random number engine
        mt19937 gen(rd());      // standard mersenne_twister_engine seeded with rd()
        auto generator = bind(uniform_int_distribution<>(0,1), gen);
        vector<bool> B(n);
        generate(B.begin(), B.end(), generator);

        return B;
    }

    int intGen()
    {
        random_device rd;       // to obtain a seed for the random number engine
        mt19937 gen(rd());      // standard mersenne_twister_engine seeded with rd()
        auto generator = bind(uniform_int_distribution<>(0,1), gen);

        return generator();
    }
};

int main()
{
    ifstream myfile("2sat6.txt");
    if(!myfile.is_open())
    {
        cout << "File failed to open." << endl;
        return 0;
    }

    int n;
    myfile >> n;
    vector< vector<int>> C(n, vector<int>(2, 0));

    for(int i=0; i<n; ++i)
    {
        myfile >> C[i][0];
        myfile >> C[i][1];
    }
    myfile.close();

    TwoSAT ts;
    bool b = ts.Papadim(C);
    cout << "feasible solution = " << b << endl;

    return 0;
}
