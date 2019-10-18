#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

class TwoSum{
public:
    int twosumHash(vector<long long> X, vector<int> T){
        unordered_set<long long> A;

        //creat hash table with de-duplication
        for(auto x : X)
        {
            if(A.find(x) == A.end())
                A.insert(x);
        }

        int count=0;
        // 2-sum via hash table
        for(auto t : T)
        {
            for(unordered_set<long long> :: iterator itr = A.begin(); itr != A.end(); itr++)
            {
                if(*itr != t-*itr && A.find(t-*itr) != A.end())
                {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};

int main(){

    //ifstream myfile("prob-2sum.txt");
    ifstream myfile("input_random_68_640000.txt");
    vector<long long> X;
    long long x;

    while(myfile >> x){
        X.push_back(x);
    }

    vector<int> T;
    for(int i=-10000; i<=10000; ++i)
        T.push_back(i);

    TwoSum ts;
    int c = ts.twosumHash(X, T);

    cout << c << endl;

    return 0;
}
