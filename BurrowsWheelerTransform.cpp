#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "banana$";
    int n = s.size();
    std::vector<string> a(n);
    for(int i = 0; i<n; i++){
        string x = s.substr(i,n) + s.substr(0,i);
        a[i] = x; 
    }
    sort(a.begin(),a.end());
    string bwt = "";
    for(int i = 0; i<n; i++) bwt += a[i][n-1];
    cout << bwt << endl;
    return 0; 
}
