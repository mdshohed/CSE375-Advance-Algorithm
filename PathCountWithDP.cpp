#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 6, m = 7; 
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1)); 
    for(int i = 0; i<=n; i++) {
        for(int j = 0; j<=m; j++) {
            if(i==0 || j==0 ) dp[i][j] = 1; 
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    for(int i = 0; i<=n; i++) {
        for(int j = 0; j<=m; j++) {
            cout << dp[i][j] << " "; 
        }
        cout << endl; 
    }
    cout << endl; 
    cout << dp[n][m] << endl; 
    return 0;   
}