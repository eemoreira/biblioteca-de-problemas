template<typename T>
struct Seg {
    vector<T> t;
    int n;
    void update(int i, T v) {
        for (t[i += n] = v; i >>= 1;) {
            t[i] = merge(t[i << 1], t[i << 1 | 1]);
        }
    }
    T query(int l, int r) {
        T ansl = neutral;
        T ansr = neutral;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ansl = merge(ansl, t[l++]);
            if (r & 1) ansr = merge(t[--r], ansr);
        }
        return merge(ansl, ansr);
    }
    Seg(vector<T> &a) {
        n = a.size();
        t.assign(n << 1, neutral);
        for (int i = 0; i < n; i++) {
            t[i + n] = a[i];
        }
        for (int i = n-1; i > 0; i--) {
            t[i] = merge(t[i << 1], t[i << 1 | 1]);
        }
    }
};
