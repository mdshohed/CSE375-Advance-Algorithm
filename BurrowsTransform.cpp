#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "banana"; 
    s += "$";
    int n = s.size();
    std::vector<string> a(n);
    vector<vector<char>> dp(n, vector<char>(n));
    // map<pair<char,int>> mp1; 
    for(int i = 0; i<n; i++) {
        string x = s.substr(i,n) + s.substr(0, i);
        a[i] = x; 
    }
    sort(a.begin(), a.end());
    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++) {
            dp[i][j] = a[i][j];
            char ch = a[i][j];
        } 
    } 
    for(auto i: a ){
        for(char j: i) cout << j;
        cout << endl;
    }
    cout << endl;
    return 0; 
}