#include <bits/stdc++.h>
using namespace std;

int CoinChange(vector<int> a, int n, int unit) {
    vector<vector<int>> dp(n+1, vector<int>(unit+1));
    for(int i = 1; i<=n; i++) {
        for(int j = 0; j<=unit; j++) {
            if( i==0 ) {
                dp[0][j] = 0;
            }
            else if( j==0 ) {
                dp[i][0] = 1;
            }
            else if ( j<a[i-1] ) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j] + dp[i][ j - a[i-1]];
            }
        }
    }
    return dp[n][unit];
}
int main(){
    freopen("in.txt", "r", stdin);
    vector<int> ara = {1, 2, 3, 5};
    int unit;
    cout << "Enter Units: ";
    cin >> unit;
    cout << endl;
    int n = ara.size();
    int way = CoinChange (ara, n, unit);
    cout << "Total " << way << " ways we can make " << unit << " Units using [ ";
    for(int i: ara) cout << i << " ";
    cout << "] Coin" << endl;
    return 0;
}