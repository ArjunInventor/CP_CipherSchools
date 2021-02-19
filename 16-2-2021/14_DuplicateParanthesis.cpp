#include<bits/stdc++.h>
using namespace std;

bool DuplicateParanthesis(string expr) 
{ 
    stack<char> s; 
    for (char c : expr) { 
        if (c == ')') { 
            char top = s.top(); 
            s.pop(); 
            int i = 0; 
            while (top != '(') { 
                i++; 
                top = s.top(); s.pop(); 
            } 
            if(i < 1) { 
                return 1; 
            }
            continue; 
        } 
        s.push(c); 
    } 
  
    return false; 
} 

int main() {
    cout<<(DuplicateParanthesis("(2+1)")?"TRUE":"FALSE")<<endl;
    cout<<(DuplicateParanthesis("((2+1))")?"TRUE":"FALSE")<<endl;
}
