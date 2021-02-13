#include<bits/stdc++.h>
using namespace std;

int getCandidate(vector<int> & vec)
{
    int candidateIndex = 0, count = 1;
    for(int i=0; i<vec.size(); i++)
    {
        if(vec[i] == vec[candidateIndex]) 
        {
            count++;
        } else {
            count--;
        }

        if(count == 0) {
            candidateIndex = i;
        }
    }
    return vec[candidateIndex];
}


int main() {
    vector<int> a = {4, 4, 3, 4, 4, 4, 4, 5, 2};
    cout<< getCandidate(a);
    return 0;
}