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
    cin.tie(0);
    cout.tie(0);
    return;
}

ll countTriplets(vector<ll> arr,ll r) {
    map<ll,ll> right;
    map<ll,ll> left;
    for(auto e : arr) {
        if(right.find(e) == right.end()) right[e] = 1;
        else right[e]++;
    }
    ll res = 0;
    for(auto a : arr) {
        right[a]--;
        long c1 = 0,c2 = 0;
        if(left.find(a/r) != left.end() and (a%r) == 0) c1 = left[a/r];
        if(right.find(a*r) != left.end()) c2 = right[a*r];
        res += (c1*c2);
        if(left.find(a) == left.end()) left[a] = 1;
        else left[a]++;
    }
    return res;
}

int main() {
	fastio(true);
	ll n,r;
	cin >> n >> r;
	vector<ll> arr(n,0);
	for(int i = 0; i < n; ++i) cin >> arr[i];
	cout << countTriplets(arr,r) << endl;
	return 0;
}

// Sample Input :

// 6 3
// 1 3 9 9 27 81
// 5 5
// 1 5 5 25 125
// 4 2
// 1 2 2 4

// Sample Output :

// 6
// 4
// 2