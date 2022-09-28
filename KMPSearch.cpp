#include <bits/stdc++.h>
using namespace std;

void lpsTable(vector<int> &lps, string pat, int m){
    for(int i = 1, j = 0; i<m; i++){
        if( pat[i]==pat[j]) {
            lps[i] = ++j;
        }
        else {
            if(j!=0) {
                j = lps[j-1];
                i--;
            }
            else lps[i] = 0;
        }
    }
}

void KMPSearch(string text, string pat, int n, int m) {
    std::vector<int> lps(m);
    lpsTable(lps, pat, m);
    cout << "LPS Table of " << pat << " is: ";
    for(int i: lps) cout << i << " ";
    cout << endl;
    int i = 0, j = 0;
    while(i<n){
        if(text[i]==pat[j]) {
            i++, j++;
            if(j==m) {
                cout << "Found pattern at index " << i - j << endl;
                j = lps[j-1];
            }
        }
        else {
            if( j!=0 ) {
                j = lps[j-1];
            }
            else i++;
        }
    }
}

int main() {
    string text, pat;
    cout << "Enter the text: ";
    getline(cin,text);
    cout << "Enter the pattern: ";
    getline(cin,pat);
    int n = text.size();
    int m = pat.size();
    cout << "Length of the Text: " << text.size() << endl;
    cout << "Length of the Pattern: " << pat.size() << "\n\n";
    KMPSearch(text, pat, n, m);
    return 0;
}

