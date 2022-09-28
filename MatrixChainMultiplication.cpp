#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixChain(vector<int> &p, int n){
    vector<vector<int>> m(n, vector<int>(n)), s(n,vector<int>(n));
    for(int l = 1; l<n; l++){
        for(int i = 1; i<=n-l; i++){
            int j = i + l - 1;
            if (i==j) {
                m[i][j] = 0;
            }
            else {
                m[i][j] = INT_MAX;
                for(int k = i; k<j; k++){
                    int mn = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
                    if (mn < m[i][j]) {
                        m[i][j] = mn;
                        s[i][j] = k; 
                    }
                }
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return m;
}

int main(){
    std::vector<int> p =  {4, 10, 3, 12, 20, 7};
    int n = p.size();
    auto m = matrixChain(p, n);
    cout << "M table: " << endl;
    for(int i = 1; i<m.size(); i++){
        for(int j = 1; j<m[i].size(); j++){
            if( i>j) cout << "\t";
            else cout << m[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Minimum number of scalar operations needed is " << m[1][n-1] << endl;
    return 0;
}
