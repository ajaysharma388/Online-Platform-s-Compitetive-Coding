#include <bits/stdc++.h>
using namespace std;

#define ll long long int
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
    cin.tie(NULL);
    cout.tie(NULL);
}


int lastStoneWeight(vector<int>& stones) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(stones.size() > 1) {
        int n = stones.size();
        sort(stones.begin(),stones.end());
        int wx = stones[n-1];
        int wy = stones[n-2];
        stones.pop_back();
        stones.pop_back();
        stones.push_back(abs(wx-wy));
    }
    return stones[0];
}

int main(){
    fastio(true);
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << lastStoneWeight(arr) << endl;
    return 0;
}