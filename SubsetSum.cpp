#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pii pair<ll,ll> 

bool subsetSum(vector<int> a, int n, int sum) {
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
    for(int i = 0; i<=n; i++) dp[i][0] = true;
    for(int i = 1; i<=sum; i++) dp[0][i] = false;
    for(int i = 1; i<=n; i++) {
        for(int j = 0; j<=sum; j++) {
            if( j<a[i-1]) {
                dp[i][j] = dp[i-1][j]; 
            }
            if ( j>=a[i-1]){
                dp[i][j] = dp[i-1][j] || dp[i-1][ j - a[i-1]]; 
            }
        }
    }
    for(int i = 0; i<=n; i++) {
        for(int j = 0; j<=sum; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return dp[n][sum]; 
}

int main(){
#ifndef LOCAL
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
#else
    freopen( "in.txt", "r", stdin);
    //freopen( "out.txt","w", stdout);
#endif
    std::vector<int> a = {1, 3, 4, 7, 10};
    int sum = 9;
    int n = a.size();
    int ans = subsetSum(a, n, sum ); 
    if(ans) {
        cout << "Found ia subset with given sum" << endl;
    }
    else {
        cout << "Not subset with given sum" << endl;
    }
    return 0;  
}