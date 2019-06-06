#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    long long key;
    node *left;
    node *right;
    node(long long x) : key(x), left(NULL), right(NULL) {}
};

class compareNodes{
public:
    bool operator()(node* a, node* b)
    {
        // return "true" if "b" is ordered at top
        return (a->key > b->key);
    }
};

class Huffman{
public:
    int coding(int n, vector<int> W){
        if(n == 0)
            return 0;
        else if(n <= 2)
            return 1;

        // use a min-priority queue
        priority_queue<node*, vector<node*>, compareNodes> mHeap;
        for(int i=0; i<n; ++i){
            mHeap.push(new node(W[i]));
        }

        // create Huffman tree
        for(int i=0; i<n-1; ++i){
            // remove 1
            node* x = mHeap.top();
            mHeap.pop();

            // remove 2
            node* y = mHeap.top();
            mHeap.pop();

            // merge and re-insert
            node* z = new node(x->key + y->key);
            z->left = x;
            z->right = y;
            mHeap.push(z);
        }
        
        return minDepth(mHeap.top())-1;
    }

        // compute the min depth of a tree
    int minDepth(node* x){
        if(!x)
            return 0;
        else
            return min(minDepth(x->left)+1, minDepth(x->right)+1);
    }
};

int main()
{
    ifstream myfile;
    myfile.open("huffman.txt");

    int n;              // number of symbols
    myfile >> n;

    vector<int> W(n);

    for(int i=0; i<n; ++i)
        myfile >> W[i];

    Huffman huff;
    int min_length = huff.coding(n, W);

    cout << min_length << endl;
    return 0;
}
