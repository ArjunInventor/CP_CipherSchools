// ever meet or not. 
#include <bits/stdc++.h> 
using namespace std; 
  
bool MeetEachOther(int x1, int x2, int v1, int v2) 
{ 
    if (x1 < x2 && v1 <= v2) return false; 
    if (x1 > x2 && v1 >= v2) return false;   
    return (abs(x1 - x2) % abs(v1 - v2) == 0);  
} 
  
int main() 
{ 
    if (MeetEachOther(3, 6, 6, 3)) cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl; 

    if (MeetEachOther(3, 7, 11, 3)) cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl; 
    return 0; 
} 