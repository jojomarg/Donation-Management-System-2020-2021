#pragma once
#include<string>
#include<vector>
using namespace std;

void tokenize(string const str, const char delim, vector<string> &out)
{
    size_t start;
    size_t end = 0;
 
    int count= 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        // cout << count++ << endl;
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
        // cout << out[out.size() - 1] << endl;
    }
    

}
