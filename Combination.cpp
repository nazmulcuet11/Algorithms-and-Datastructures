/**
    @author : nazmul_islam
*/
#include <bits/stdc++.h>

using namespace std;

#define SIZE 10000

vector<char> v;

void printCombination()
{
    for(int j=0; j<v.size(); j++)
        cout<<v[j];
    cout<<endl;
}

void combination(char *a, int r,int start)
{
    if(v.size()==r)
    {
        printCombination();
        return;
    }

    for(int i = start; i<strlen(a); i++)
    {
        v.push_back(a[i]);
        combination(a, r, i+1);
        v.pop_back();
    }
}

int main()
{
    char* str = "abcde";
    combination(str, 3, 0);
    return 0;
}
