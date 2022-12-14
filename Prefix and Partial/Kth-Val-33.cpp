#include<bits/stdc++.h>
using namespace std;

#define ll long long int

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t;
    while(_t--) {
        int n, m, q;
        cin >> n >> m >> q;
        pair<int,int> A[n];
        for(int i = 0; i < n; i++) {
            cin >> A[i].first;
            A[i].second = 0;
        }
        for(int i = 0; i < m; i++) {
            int l, r; cin >> l >> r;
            l--; r--;
            A[l].second++;
            if(r + 1 < n) A[r + 1].second--;
        }
        for(int i = 1; i < n; i++)
            A[i].second += A[i - 1].second;

        sort(A, A + n);

        int ans[q];
        pair<ll,int> Q[q];
        for(int i = 0; i < q; i++) {
            cin >> Q[i].first;
            Q[i].second = i;
        }

        sort(Q, Q + q);

        int ptr = 0;
        ll sum = 0;

        for(int i = 0; i < q; i++) {
            ll x = Q[i].first;
            while(ptr < n && sum + A[ptr].second < x) {
                sum += A[ptr].second;
                ptr++;
            }
            if(ptr < n) ans[Q[i].second] = A[ptr].first;
            else ans[Q[i].second] = -1;
        }

        for(int i = 0; i < q; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}