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
    // return ture for higher ratio
    return a.ratio > b.ratio;
}

class Scheduling {
public:
    long long weightedCompleteTime(vector<Job> jobs){
        int n =  jobs.size();

        // calculate ratio = weight / length
        for(int i=0; i<n; ++i)
            jobs[i].ratio = jobs[i].w * 1.0 / jobs[i].l;

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
