#include <bits/stdc++.h>
using namespace std;

int main() {

    string bwt = "annb$aa", bwt2, ans = "$";
    int n = bwt.size();
    vector<pair<pair<char,int>,pair<char,int>>> b(n);
    map<char,int> mp, mp2;
    vector<pair<char,char>> bwtarry(n);
    bwt2 = bwt;
    sort(bwt2.begin(),bwt2.end()); 
    for(int i = 0; i<n; i++) {
        bwtarry[i] = {bwt2[i],bwt[i]};
    } 
    for(int i = 0; i<n; i++) {
        char ch = bwt2[i], ch2 = bwt[i]; 
        mp[ch]++;
        mp2[ch2]++;
        b[i] = {{ch,mp[ch]},{ch2, mp2[ch2]}};
    }
    char maping = b[0].second.first;
    int pos = b[0].second.second;
    for(auto i: b){
        cout << i.first.first << " " << i.first.second << " " << i.second.first << " " << i.second.second << endl;
    }
    cout << endl;
    for(int i = 0; i<n; i++) {
        if(maping=='$') break; 
        ans = maping + ans;
        for(int j = 0; j<n; j++){
            if(maping==b[j].first.first && pos==b[j].first.second) {
                maping = b[j].second.first;
                pos = b[j].second.second;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0; 
}