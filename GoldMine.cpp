#include <bits/stdc++.h>
using namespace std;

int getMaxGold(vector<vector<int>> a, int n, int m) {
    vector<vector<int>> dp(n+1,vector<int>(m));
    for(int i = 0; i<m; i++) dp[i][0] = a[i][0]; 
    int rightUp, right, rightDown;
    for(int i = 1; i<m; i++) {
        for(int j = 0; j<n; j++) {
            rightUp = (j==0 ? 0: dp[j-1][i-1]); 
            rightDown = (j==n-1 ? 0: dp[j+1][i-1]);
            right =  dp[j][i-1]; 
            dp[j][i] = a[j][i] + max(rightUp, max(right, rightDown)); 
        }
    }
    int mx = dp[0][m-1];
    for(int i  = 0; i<n; i++) {
        mx = max( mx, dp[i][m-1]); 
    }
    return mx; 
}

int main(){
    std::vector<std::vector<int>> a = {{1, 3, 1, 5}, 
                                        {2, 2, 4, 1},
                                        {5, 0, 2, 3},
                                        {0, 6, 1, 2}};
    int n = a.size(), m = a[0].size(); 
    cout << getMaxGold(a, n, m) << endl; 
    return 0;  
}

printf("%f\n", );