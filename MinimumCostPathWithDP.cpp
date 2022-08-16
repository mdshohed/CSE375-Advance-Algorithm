#include <bits/stdc++.h>
using namespace std; 

int main() {
	std::vector<std::vector<int>> grid = {{3, 5, 7, 10},{6, 4, 3, 9},{6, 5, 4, 5}};
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> dp(n+1, vector<int>(m));
	vector<pair<int,int>> path; 
	dp[0][0] = grid[0][0];
	path.push_back({0,0}); 
	for(int i = 1; i<n; i++) dp[i][0] = dp[i-1][0] + grid[i][0]; 
	for(int i = 1; i<m; i++) dp[0][i] = dp[0][i-1] + grid[0][i]; 
	for(int i = 1; i<n; i++) {
		for(int j = 1; j<m; j++) {
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]; 
			if(dp[i-1][j]<=dp[i][j-1]) path.push_back({i-1,j});
			else path.push_back({i,j-1});
		} 
	}
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			cout << dp[i][j] << " "; 
		}
		cout << endl; 
	} 
	cout << dp[n-1][m-1] << endl;
	cout << "Path: "; 
	for(auto i = 0; i<path.size(); i++) {
		if(i+1==path.size()) cout << "(" << path[i].first << "," << path[i].second << ")" << endl; 
		else cout << "(" << path[i].first << "," << path[i].second << ")=> "; 
	}
	return 0;
}