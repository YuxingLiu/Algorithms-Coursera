#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;


class Median{
public:
    int Median_heap(vector<int> X){
        priority_queue<int, vector<int>, greater<int> > pq_min;     // min heap (larger half)
        priority_queue<int> pq_max;                                 // max heap (smaller half)
        int n = X.size();
        vector<int> M(n);       // medians
        int sum = 0;

        for(int i=0; i<n; ++i)
        {
            if(pq_max.empty() || X[i] <= pq_max.top())
            {
                pq_max.push(X[i]);                  // push xi to smaller half heap
                if(pq_max.size() > pq_min.size() + 1){
                    pq_min.push(pq_max.top());      // adjust two heap size if smaller > larger + 1
                    pq_max.pop();
                }
            }
            else
            {
                pq_min.push(X[i]);                  // push xi to larger half heap
                if(pq_min.size() > pq_max.size()){   
                    pq_max.push(pq_min.top());      // adjust two heaps size if larger > smaller
                    pq_min.pop();
                }
            }
            M[i] = pq_max.top();                    // median is the top of smaller half heap
            sum += M[i];
        }

        return sum % 10000;
    }
};


int main()
{

    ifstream myfile("Median.txt");
    vector<int> X;
    int x;

    while(myfile >> x){
        X.push_back(x);
    }

    Median med;
    int s = med.Median_heap(X);

    cout << s << endl;

    return 0;
}
