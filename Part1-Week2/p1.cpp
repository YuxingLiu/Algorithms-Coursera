#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class DAC{
public:
    long long SortCountInv(vector<int>& A, int l, int r)
    {
        if(l > r)
        {
            cout << "Error! l is greater than r." << endl;
            return 0;
        }

        if(r==l)      // base case, n=1
            return 0;

        int m = l + (r-l)/2;    // same as (l+r)/2, but avoid overflow for large l and r
        long long leftInv = SortCountInv(A, l, m);
        long long rightInv = SortCountInv(A, m+1, r);
        long long splitInv = MergeCountSplitInv(A, l, m, r);

        return leftInv + rightInv + splitInv;
    }

    long long MergeCountSplitInv(vector<int>& A, int l, int m, int r)
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<int> L(n1), R(n2);
        // copy data to temp arrays L and R
        for(i=0; i<n1; ++i)
            L[i] = A[l+i];
        for(j=0; j<n2; ++j)
            R[j] = A[m+1+j];

        i=0;
        j=0;
        k=l;
        long long splitInv = 0;
        // merge temp arrays back into A[l,..r]
        while(i != n1 && j != n2)
        {
            if(L[i] < R[j])
            {
                A[k] = L[i];
                i++;
            }
            else
            {
                A[k] = R[j];
                j++;
                splitInv += n1 - i;
            }
            k++;
        }

        // copy the remaining elements of L, if any
        while(i != n1)
        {
            A[k] = L[i];
            i++;
            k++;
        }

        // copy the remaining elements of R, if any
        while(j != n2)
        {
            A[k] = R[j];
            j++;
            k++;
        }

        return splitInv;
    }
};

int main(){

    ifstream myfile("IntegerArray.txt");
    if(!myfile.is_open())
    {
        cout << "File failed to open" << endl;
        return 0;
    }

    vector<int> X;
    int x;

    while(myfile >> x)
        X.push_back(x);

    DAC dac;
    long long count = dac.SortCountInv(X, 0, X.size()-1);
    cout << count << endl;

    return 0;
}
