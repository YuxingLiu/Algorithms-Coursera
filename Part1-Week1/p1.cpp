#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>    // for reverse()

using namespace std;

class IntMult{
public:
    string RecIntMult(string x, string y){
        int n = x.length();
        if(n==1)
        {
            int xy = stoi(x) * stoi(y);
            return to_string(xy);
        }

        string a = x.substr(0, n/2);
        string b = x.substr(n/2, n/2);
        string c = y.substr(0, n/2);
        string d = y.substr(n/2, n/2);

        string ac = RecIntMult(a, c);
        string bd = RecIntMult(b, d);
        string ad = RecIntMult(a, d);
        string bc = RecIntMult(b, c);

        string adbc = intSum(ad, bc);

        // 10^n * ac
        for(int i=0; i<n; i++)
            ac.push_back('0');

        // 10^n/2 * (ad+bc)
        for(int i=0; i<n/2; i++)
            adbc.push_back('0');

        // 10^n * ac + 10^n/2 (ad+bc) + bd
        string theSum = intSum(ac, adbc);
        theSum = intSum(theSum, bd);

        return theSum;
    }

    string intSum(string str1, string str2){
        // make sure length of str2 is larger
        if(str1.length() > str2.length())
            swap(str1, str2);

        int n1 = str1.length();
        int n2 = str2.length();

        // reverse string
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());

        // initize empty string to store the sum
        string theSum = "";

        int carry = 0;
        for(int i=0; i<n1; ++i){
            // compute sum of current digits and carry
            int sum = (str1[i]-'0') + (str2[i]-'0') + carry;
            theSum.push_back(sum%10 + '0');

            // compute carry for next step
            carry = sum/10;
        }

        // add remaining digits of larger number
        for(int i=n1; i<n2; ++i){
            // compute sum of current digits and carry
            int sum = (str2[i]-'0') + carry;
            theSum.push_back(sum%10 + '0');

            // compute carry for next step
            carry = sum/10;
        }

        // add remaining carry
        if(carry)
            theSum.push_back(carry + '0');

        reverse(theSum.begin(), theSum.end());
        return theSum;
    }
};

int main()
{
    ifstream myfile("int_multiply.txt");
    if(!myfile.is_open())
    {
        cout << "File failed to open" << endl;
        return 0;
    }

    string x,y;
    myfile >> x >> y;
    cout << "x \t= " << x << endl << "y \t= " << y << endl;

    IntMult im;
    cout << "x*y \t= " << im.RecIntMult(x, y) << endl;

    return 0;
}
