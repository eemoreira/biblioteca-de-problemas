const int maxn = 3e5 + 5;
int p2[maxn];
const int lg = __lg(maxn) + 2;
const node neutral = node();

template<typename T>
struct sparseTable {
  vector<T> sparse[lg];
  int n;
  T query(int l, int r){
    int i = p2[r - l + 1];
    return comp(sparse[i][l], sparse[i][r - (1 << i) + 1]);
  }
  sparseTable(vector<T>& a) {
    n = a.size();
    if (p2[2] == 0) {
      for (int i = 2; i < maxn; i++) {
        p2[i] = p2[i >> 1] + 1;
      }
    }
    for(int i = 0; i < lg; i++){
      sparse[i] = vector<T>(n);
    }
    for(int i = 0; i < n; i++){
      sparse[0][i] = a[i];
    }
    for(int i = 1; i < lg; i++){
      for(int j = 0; j + (1 << i) <= n;  j++){
        sparse[i][j] = comp(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
};
