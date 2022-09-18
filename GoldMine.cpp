#include <bits/stdc++.h>
using namespace std;

pair<int,pair<int,int>> getMaxGold(vector<vector<int>> a, int row, int col) {
    vector<vector<int>> dp(row,vector<int>(col));
    for(int i = 0; i<row; i++) dp[i][0] = a[i][0];
    int rightUp, right, rightDown;
    for(int i = 1; i<col; i++) {
        for(int j = 0; j<row; j++) {
            rightUp = (j==0 ? 0: dp[j-1][i-1]);
            rightDown = (j==row-1 ? 0: dp[j+1][i-1]);
            right =  dp[j][i-1];
            dp[j][i] = a[j][i] + max(rightUp, max(right, rightDown));
        }
    }
    int mxGold = dp[0][col-1];
    pair<int,int> mxPosition = {1, col};
    for(int i  = 0; i<row; i++) {
        if( mxGold < dp[i][col-1]) {
            mxGold = dp[i][col-1];
            mxPosition = {i+1, col};
        }
    }
    return {mxGold, mxPosition};
}

int main(){
    int row, col;
    cout << "Enter the number of row: " << endl;
    cin >> row;
    cout << "Enter the number of column: " << endl;
    cin >> col;
    cout << endl;
    std::vector<vector<int>> gold(row,vector<int>(col));
    cout << "Enter the gold value: " << endl; 
    for(auto& i: gold) {
        for(int& j: i ) {
            cin >> j;
        }
    }
    auto ans = getMaxGold(gold, row, col);
    int mxGold = ans.first;
    pair<int,int> mxGoldPos = ans.second;
    cout << "Maximum amount of gold can be collect from GoldMine table is: " <<  mxGold << " Units" << endl;
    cout <<"Maximum amount of Gold position is : [" << mxGoldPos.first << " " << mxGoldPos.second << "]" << endl;
    return 0;
}

/*4 4
1 3 1 5 
2 2 4 1 
5 0 2 3 
0 6 1 2*/ 