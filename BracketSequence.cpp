#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    string s;
    cin >> s;
    stack<char> st;
    int flag = 0;
    for(int i = 0; i<s.size(); i++) {
        char ch = s[i];
        if(ch=='(' || ch=='{' || ch=='[') {
            st.push(ch);
        }
        else if(ch==')' || ch=='}' || ch==']') {
            if(st.size()==0){
                flag = 1;
                break;
            }
            else if((ch==')'&&st.top()=='(') ||(ch=='}'&&st.top()=='{') || (ch==']'&&st.top()=='[') ){
                st.pop();
            }
            else {
                flag = 1; 
                break;
            }
            
        }
    } 
    if(flag) {
        cout << "Opening bracket is missing!. So, the given arithmetic expression is Invalid!" << endl;
    }
    else if(st.size()>0) {
        cout << "Closing bracket is missing!. So, the given arithmetic expression is Invalid!" << endl;
    }
    else {
        cout << "The stack is also empty! So, the given arithmetic expression is Valid!" << endl;
    }
    return 0;
}

Input:
------
d+[(a-b)*{m/(n+p)}

Output:
-------
Closing bracket is missing!. So, the given arithmetic expression is Invalid!