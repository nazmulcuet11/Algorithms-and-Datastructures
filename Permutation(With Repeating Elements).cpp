/**
    @author : nazmul_islam
*/
#include <bits/stdc++.h>

using namespace std;

#define SIZE 10000

vector<char> v;

void printPermutation()
{
    for(int j=0; j<v.size(); j++)
        cout<<v[j];
    cout<<endl;
}

void permutation(char *a, int r)
{
    if(v.size()==r)
    {
        printPermutation();
        return;
    }

    for(int i = 0; i<strlen(a); i++)
    {
        v.push_back(a[i]);
        permutation(a, r);
        v.pop_back();
    }
}

int main()
{
    char* str = "abcd";
    permutation(str, 3);
    return 0;
}
