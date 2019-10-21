#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Sort{
public:
    long long QuickSort(vector<int>& X, int l, int r, int flag=1)
    {
        if(l >= r)                              // 0- or 1-element subarray
            return 0;


        int p;
        if(flag==1)
            p = l;                              // choose 1st element as pivot point
        else if(flag==2)
            p = r;                              // choose last element as pivot point
        else if(flag==3)
        {
            p = Median(X, l, r);                // choose the median among 1st, n/2, last as pivot point
        }
        swap(X[l], X[p]);                       // make pivot first

        int j = Partition(X, l, r);
        long long c1 = r-l;                             // number of comparision on a subarray with length r-l+1
        long long c2 = QuickSort(X, l, j-1, flag);      // recurse on first part
        long long c3 = QuickSort(X, j+1, r, flag);      // recurse on second part

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

    int Median(vector<int> X, int l, int r)
    {
        int m = l + (r-l)/2;
        bool b1 = X[r] > X[m];
        bool b2 = X[m] > X[l];
        bool b3 = X[l] > X[r];

        if(b1 && b2 || !b1 && !b2)
            return m;
        else if(b1 && b3 || !b1 && !b3)
            return r;
        else if(b2 && b3 || !b2 && !b3)
            return l;
    }
};

int main(){

    ifstream myfile("QuickSort.txt");
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
    vector<int> X1(X.begin(), X.end());
    vector<int> X2(X.begin(), X.end());
    long long c1 = qs.QuickSort(X1, 0, X.size()-1, 1);
    long long c2 = qs.QuickSort(X2, 0, X.size()-1, 2);
    long long c3 = qs.QuickSort(X, 0, X.size()-1, 3);
    cout << c1 << endl << c2 << endl << c3 << endl;

    return 0;
}
