#include <bits/stdc++.h>
using namespace std;

long long int pathCount(int row, int col) {
    std::vector<std::vector<int>> dp(row+1, std::vector<int>(col+1));
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            if( i==0 || j==0 ) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            cout << dp[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
    return dp[row-1][col-1];
}

int main() {
    int row, col;
    cout << "Enter no of rows: " << endl;
    cin >> row;
    cout << "Enter no of columns: " << endl;
    cin >> col;
    long long int path = pathCount(row, col);
    cout << "There are " << path << " ways we can go from top-left cell to right-down cell" << endl;
    return 0;
}
