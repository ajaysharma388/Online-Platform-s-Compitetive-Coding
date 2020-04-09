#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define pb(x) push_back(x)
#define ppb() pop_back()
#define endl "\n"


void fastio(bool read = false) {
    if(read) {
        #ifndef ONLINE_JUGDE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
        #endif
    }  
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return;
}

bool backspaceCompare(string S, string T) {
    int sptr = S.length()-1;
    int sSkips = 0;
    int tptr = T.length()-1;
    int tSkips = 0;
    while(sptr >= 0 or tptr >= 0) {
        while(sptr >= 0) {
            if(S[sptr] == '#'){
                sptr-=1;
                sSkips+=1;
            } else if(sSkips){
                sptr-=1;
                sSkips-=1;
            } else {
                break;
            }
        }
        while(tptr >= 0) {
            if(T[tptr] == '#'){
                tptr-=1;
                tSkips+=1;
            } else if(tSkips){
                tptr-=1;
                tSkips-=1;
            } else {
                break;
            }
        }
        if((tptr >= 0 and sptr >= 0) and (S[sptr] != T[tptr])) return false;
        if((sptr >= 0) != (tptr >= 0)) return false;
        sptr--;
        tptr--;
    }
    return true;
}

int main() {
    fastio(true);
    string s,t;
    int testCases;
    cin >> testCases;
    while(testCases--) {
        cin >> s >> t;
        if(backspaceCompare(s,t)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}

// Sample Input : 

// 5
// bbbextm bbb#extm
// bxj##tw bxj###tw
// ab#c ad#c
// ab## c#d#
// a##c #a#c
// a#c b

// Sample Output :

// false
// false
// true
// true
// true