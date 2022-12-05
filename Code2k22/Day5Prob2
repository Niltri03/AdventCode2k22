#include <vector>
#include <iostream>

using namespace std;

string test1 = "ZN";
string test2 = "MCD"; 
string test3 = "P";

string s1 = "GFVHSP";
string s2 = "GJFBVDZM";
string s3 = "GMLJN";
string s4 = "NGZVDWP";
string s5 = "VRCB";
string s6 = "VRSMPWLZ";
string s7 = "THP";
string s8 = "QRSNCHZV";
string s9 = "FLGPVQJ";

int main()
{
    string mt;
    mt = "";
    vector<string> staks{mt, s1, s2, s3, s4, s5, s6, s7, s8, s9};
    //vector<string> staks{mt, test1, test2, test3};
    string trash;
    int q, from, to; 
    while(cin >> trash >> q >> trash >> from >> trash >> to){
        int q2 = staks[from].size()  - q; 
        for(int i = 0; i < q; ++i){
            
            staks[to].push_back(staks[from][q2]);
            staks[from].erase(staks[from].begin()+q2);
            
        }
    }
    cout << "------" << endl; 
    for(int i = 1; i <= staks.size()-1; ++i)cout << staks[i][staks[i].size()-1];
    cout << endl; 
}

    
