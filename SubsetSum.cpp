#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> a, int n, int sum) {
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
    for(int i = 1; i<=sum; i++) dp[0][i] = false;
    for(int i = 0; i<=n; i++) dp[i][0] = true;
    for(int i = 1; i<=n; i++) {
        for(int j = 0; j<=sum; j++) {
            if( j<a[i-1]) {
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = (dp[i-1][j] || dp[i-1][ j - a[i-1]]);
            }
        }
    }
    return dp[n][sum];
}

int main(){
    std::vector<int> a = {1, 2, 4, 5};
    int sum;
    cout << "Input Sum: ";
    cin >> sum;
    int n = a.size();
    int ans = subsetSum(a, n, sum );
    if(ans) {
        cout << "Found a Subset with given Sum" << endl;
    }
    else {
        cout << "Not found a Subset with given Sum" << endl;
    }
    return 0;
}
