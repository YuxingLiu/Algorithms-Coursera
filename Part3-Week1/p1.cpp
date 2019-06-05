#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Job {
public:
    int w;
    int l;
    int diff;
    double ratio;
};

bool compareTwoJobs(Job a, Job b){
    // if diffs are not equal, return true for higher diff
    if(a.diff != b.diff)
        return a.diff > b.diff;

    // if diffs are equal, return ture for higher weight
    return a.w > b.w;
}

class Scheduling {
public:
    long long weightedCompleteTime(vector<Job> jobs){
        int n =  jobs.size();

        // calculate difference = weight - length
        for(int i=0; i<n; ++i)
            jobs[i].diff = jobs[i].w - jobs[i].l;

        // sort jobs using user defined function
        sort(jobs.begin(), jobs.end(), compareTwoJobs);

        // calculate weighted sum of completion times
        long long cTime = 0;
        long long sum = 0;
        for(int i=0; i<n; ++i){
            cTime += jobs[i].l;
            sum += cTime * jobs[i].w;
        }

        return sum;
    }
};

int main()
{
    ifstream myfile;
    myfile.open("jobs.txt");

    int n;
    myfile >> n;

    vector<Job> jobs(n);

    for(int i=0; i<n; ++i)
    {
        myfile >> jobs[i].w;
        myfile >> jobs[i].l;
    }

    Scheduling sche;
    long long sum = sche.weightedCompleteTime(jobs);

    cout << sum << endl;
    return 0;
}
