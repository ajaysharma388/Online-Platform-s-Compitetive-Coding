/*==========================
Author : Ajay Sharma
date : 01.06.2020
============================*/
#include <bits/stdc++.h>
using namespace std;

// Some useful macros that are helpful to reduce code size.
#define vi vector<int>
#define int long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ld long double
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
    return;
}

int activityNotifications(vi expenditure, int days) {
    int actNotCount = 0;
    deque<int> win(expenditure.begin(),expenditure.begin()+days);
    sort(win.begin(),win.end());
    for(int i = days; i < expenditure.size(); ++i) {
        double m;
        if(days & 1) m = (double) win[days/2];
        else m = (double) (win[days/2-1] + win[days/2])/2.0;
        if(2*m <= expenditure[i]) actNotCount += 1;
        auto old = lower_bound (win.begin(), win.end(), expenditure[i-days]);
        win.erase(old);
        auto cur = upper_bound (win.begin(), win.end(), expenditure[i]);
        win.insert (cur, expenditure[i]);
    }
    return actNotCount;
}

int32_t main() {
    fastio(true);
    int t; cin >> t;
    while(t--) {
        int n,days;
        cin >> n >> days;
        vi expenditure(n);
        for(int i = 0; i < n; i++) cin >> expenditure[i];
        cout << activityNotifications(expenditure,days) << endl;
    }
    return 0;
}

// Sample Input :

// 2
// 9 5
// 2 3 4 2 3 6 8 4 5
// 5 4
// 1 2 3 4 4

// Sample Output :

// 2
// 0