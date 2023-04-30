const int LOG = 11;
const int N = 1010;
int p2[N];
vector<vector<int>> sparse[LOG];
vector<vi> a;
int n,m;

namespace sparse2d{
  void build(){ // dont forget to compute p2 and change min/max
    for(int k = 0; k < LOG ; k++){
      sparse[k] = vector<vi> (n, vi(m, inf));
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        sparse[0][i][j] = a[i][j];
      }
    }
    for(int k = 0; k < LOG - 1; k++){
      for(int i = 0; i + (1 << (k + 1)) <= n; i++){
        for(int j = 0; j + (1 << (k + 1)) <= m; j++){
          sparse[k + 1][i][j] = 
            min({sparse[k][i][j], sparse[k][i + (1 << k)][j], 
              sparse[k][i][j + (1 << k)], sparse[k][i + (1 << k)][j + (1 << k)]});
        }
      }
    }
  }
  int getvalue(int x, int y, int d) {
    int k = p2[d];
    int s = d - (1 << k);
    return min({sparse[k][x][y], sparse[k][x + s][y], sparse[k][x][y + s], sparse[k][x + s][y + s]});
  }
}
