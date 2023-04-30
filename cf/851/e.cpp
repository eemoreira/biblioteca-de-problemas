#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int neutral = -1e9; //comp(x, neutral) = x
#define comp(a, b) max(a,b)

class SegmentTree {
private:
	vector<int> st, lazy;
	int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
	void build(int p, int l, int r, int* A) {
		if (l == r) { st[p] = A[l]; return; }
		int m = (l + r) / 2;
		build(left(p), l, m, A);
		build(right(p), m+1, r, A);
		st[p] = comp(st[left(p)], st[right(p)]);
	}
	void push(int p, int l, int r) {
		st[p] += lazy[p];
		if (l != r) {
			lazy[right(p)] += lazy[p];
			lazy[left(p)] += lazy[p];
		}
		lazy[p] = 0;
	}
	void update(int p, int l, int r, int a, int b, int k) {
		push(p, l, r);
		if (a > r || b < l) return;
		else if (l >= a && r <= b) {
			lazy[p] = k; push(p, l, r); return;
		}
		int m = (l + r) / 2;
		update(left(p), l, m, a, b, k);
		update(right(p), m+1, r, a, b, k);
		st[p] = comp(st[left(p)], st[right(p)]);
	}
	void pointupdate(int p, int l, int r, int a, int b, int k) {
		push(p, l, r);
		if (a > r || b < l) return;
		else if (l == r) {
			st[p] = k;
			return;
		}
		int m = (l + r) / 2;
		pointupdate(left(p), l, m, a, b, k);
		pointupdate(right(p), m+1, r, a, b, k);
		st[p] = comp(st[left(p)], st[right(p)]);
	}
	int query(int p, int l, int r, int a, int b) {
		push(p, l, r);
		if (a > r || b < l) return neutral;
		if (l >= a && r <= b) return st[p];
		int m = (l + r) / 2;
		int p1 = query(left(p), l, m, a, b);
		int p2 = query(right(p), m+1, r, a, b);
		return comp(p1, p2);
	}
public:
	SegmentTree(int* bg, int* en) {
		size = (int)(en - bg);
		st.assign(4 * size, neutral);
		lazy.assign(4 * size, 0);
		build(1, 0, size - 1, bg);
	}
	int query(int a, int b) { return query(1, 0, size - 1, a, b); }
	void update(int a, int b, int k) { update(1, 0, size - 1, a, b, k); }
	void pointupdate(int a, int b, int k) { pointupdate(1, 0, size - 1, a ,b ,k); }
};
const int N = 2e5 + 10;
long long p[N];
int b[N];

void solve() {
  int n;
  cin >> n;
	map<long long, int> cp;
	cp[0];
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		p[i] += p[i-1];
		cp[p[i]];
	}
	int k = 0;
	for (auto &u : cp) {
		u.second = k++;
	}
	int t[N];
	for (int i = 0; i <= k; i++) {
		t[i] = neutral;
	}
	dbg(cp);
	SegmentTree seg(t, t+k+1);
	vector<int> dp(n+1);
	for (int i = 0; i <= n; i++) {
		dbg(seg.query(0,cp[p[i]]));
		if (i > 0) {
			dp[i] = dp[i-1];
		}
		dbg(cp[p[i]]);
		dp[i] = max(dp[i], seg.query(0,cp[p[i]]));
		seg.pointupdate(cp[p[i]],cp[p[i]],dp[i]);
		seg.update(0,k+1,1);
		dbg(i, dp[i]);
	}
	cout << dp[n] << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}





