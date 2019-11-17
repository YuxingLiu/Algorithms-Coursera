#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>    // for time()
#include <cstdlib>  // for srand()
#include <random>
#include <functional>   // for bind()
#include <algorithm>    // for generate()

using namespace std;

class TwoSAT{
public:
    bool Papadim(int n, vector< vector<int>> C)
    {
        int N = 7;          // number of independent tests
        int M = n*100;      // number of steps per test
        int b1, b2;

        // repeat N times
        for(int i=0; i<N; ++i)
        {
            cout << "i = " << i << endl;
            // choose random initial assignment
            vector<bool> X = XGen(n);

            // repeat M times
            for(int j=0; j<M; ++j)
            {
                // check whether current assignment satisfies all clauses
                bool flag = true;
                for(int k=0; k<n; ++k)
                {
                    if(C[k][0] > 0)
                        b1 = X[C[k][0] - 1];
                    else
                        b1 = !X[-C[k][0] - 1];

                    if(C[k][1] > 0)
                        b2 = X[C[k][1] - 1];
                    else
                        b2 = !X[-C[k][1] - 1];

                    if(!b1 && !b2)
                    {
                        flag = false;
                        if(intGen() == 0)
                        {
                            if(C[k][0] > 0)
                                X[C[k][0] - 1] = true;
                            else
                                X[-C[k][0] - 1] = false;
                        }
                        else
                        {
                            if(C[k][1] > 0)
                                X[C[k][1] - 1] = true;
                            else
                                X[-C[k][1] - 1] = false;
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

    vector<bool> XGen(int n)
    {
        random_device rd;       // to obtain a seed for the random number engine
        mt19937 gen(rd());      // standard mersenne_twister_engine seeded with rd()
        auto generator = bind(uniform_int_distribution<>(0,1), gen);
        vector<bool> X(n);
        generate(X.begin(), X.end(), generator);

//        int nT = 0;
//        int nF = 0;
//        for(int i=0; i<n; ++i)
//        {
//            if (X[i])  ++nT;
//            else    ++nF;
//        }
//        cout << "# of True = " << nT << ", # of False = " << nF << endl;

        return X;
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
    //ifstream myfile("input_beaunus_39_100000.txt");
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
    bool b = ts.Papadim(n, C);
    cout << "b = " << b << endl;

    return 0;
}
