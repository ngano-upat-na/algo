/* 
author: ngano_upat_na
Notes to self (IN EXACT ORDER):
    - is this brute force?
    - is this binary search?
    - is this (insert some algorithm or just dp)
*/

#pragma GCC optimize("O1,O2,O3,Ofast,unroll-loops")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define pb push_back
#define vi vector<int> 
#define vp vector<pair<int,int>>

//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;

bool f(vp &v, vi &va, vector<bool> &vis, int h) {
    bool ok = true;
    for (int i=0; i<n; i++) {
        int idx = v[i].second;
        if (vis[idx]==false) {
            if (va[idx]<=h) {
                vis[idx] = true;
            }
            for (int j=idx+1; j<n; j++) {
                if (abs(va[j]-va[j-1])<=h && vis[j]==false) {
                    vis[j]=true;
                }
                else {
                    break;
                }
            }
            for (int j=idx-1; j>=0; j--) {
                if (abs(va[j]-va[j+1])<=h && vis[j]==false) {
                    vis[j]=true;
                }
                else {
                    break;
                }
            }
        }
    }
    int ct = 0;
    for (int i=0; i<n; i++) {
        if (vis[i]==true) {
            ct++;
            vis[i] = false;
        }
    }
    return (ct == n);
}

void sol(int Case) {
    //int n;
    cin >> n;
    vp v;
    vi va;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        v.pb({a,i});
        va.pb(a);
    }
    sort(v.begin(),v.end());
    vector<bool> vis(n,false);

    int l = 1, r = 2e9, ans = 2e9;
    while (l <= r) {
        int m = (l + r) / 2;
        if (f(v,va,vis,m)) {
            ans = min(ans,m);
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    cout << "Case #" << Case << ": " << ans << '\n'; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("snake_scales_chapter_2_validation_input.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);

    int t = 1;
    cin >> t;
    for (int i=1; i<=t; i++) sol(i);
}
