#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Sort{
public:
    long long QuickSort(vector<int>& X, int l, int r)
    {
        if(l >= r)                              // 0- or 1-element subarray
            return 0;

        int p = l;                              // choose 1st element as pivot point
        swap(X[l], X[p]);                       // make pivot first

        int j = Partition(X, l, r);
        long long c1 = r-l;                     // number of comparision on a subarray with length r-l+1
        long long c2 = QuickSort(X, l, j-1);    // recurse on first part
        long long c3 = QuickSort(X, j+1, r);    // recurse on second part

        return c1+c2+c3;
    }

    int Partition(vector<int>& X, int l, int r)
    {
        int p = X[l];   // pivot point
        int i = l+1;    // elements between p and i are less than pivot
        int j = l+1;    // elements between i and j are greater than pivot

        for(; j<=r; j++)
        {
            if(X[j] < p)            // if A[j] > p, do nothing
            {
                swap(X[j], X[i]);
                i++;                // restore invariant
            }
        }

        swap(X[l], X[i-1]);         // place pivot correctly
        return i-1;
    }
};

int main(){

    //ifstream myfile("QuickSort.txt");
    //ifstream myfile("input_dgrcode_01_5.txt");
    //ifstream myfile("input_dgrcode_10_10.txt");
    ifstream myfile("input_dgrcode_20_1000000.txt");
    if(!myfile.is_open())
    {
        cout << "File failed to open" << endl;
        return 0;
    }

    vector<int> X;
    int x;

    while(myfile >> x)
        X.push_back(x);

    Sort qs;
    long long c = qs.QuickSort(X, 0, X.size()-1);
    cout << c << endl;

    return 0;
}
