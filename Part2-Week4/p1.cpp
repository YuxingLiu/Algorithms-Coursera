#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <algorithm>        // for sort()

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

    int twosumBS(vector<long long> X, vector<int> T){
        if(X.empty() || T.empty())
            return 0;

        sort(X.begin(), X.end());   // sorted array with duplicates

        int i=0;
        int j=X.size()-1;
        unordered_set<int> Sum;

        while(i < j)                // iterate until i pass j
        {
            if(X[i] + X[j] < -10000)
                i++;
            else if(X[i] + X[j] > 10000)
                j--;
            else if(X[i] == X[j])
                break;
            else
            {
                int k=j;
                long long sum = X[i] + X[k];
                while(sum >= -10000 && sum <= 10000)
                {
                    Sum.insert(sum);
                    k--;
                    if(X[i] == X[k])
                        break;
                    sum = X[i] + X[k];
                }
                i++;
            }
        }

        return Sum.size();
    }
};

int main(){

    ifstream myfile("prob-2sum.txt");
    vector<long long> X;
    long long x;

    while(myfile >> x){
        X.push_back(x);
    }

    vector<int> T;
    for(int i=-10000; i<=10000; ++i)
        T.push_back(i);

    TwoSum ts;
    //int c = ts.twosumHash(X, T);  // very slow
    int c = ts.twosumBS(X, T);

    cout << c << endl;

    return 0;
}
