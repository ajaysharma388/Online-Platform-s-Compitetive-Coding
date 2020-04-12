#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    unordered_map<long,long> freq;
    unordered_map<long,long> count;
    int cur = 0;
    while(t--) {
        int q,d;
        cin >> q >> d;
        switch (q) {
        case 1:
            freq[count[d]]--;
            count[d]++;
            freq[count[d]]++;
            break;
        case 2:
            cur = count[d];
            if(cur > 0){
                freq[cur]--;
                count[d]--;
                freq[count[d]]++;
            }
            break;
        case 3:
            (freq[d] > 0) ? cout << 1 << endl: cout << 0 << endl; 
            break;
        default: break;
        }
    } 
    return 0;
}