#include <bits/stdc++.h>
using namespace std;

constexpr long long inf = (1LL << 61);

const int dim = 101;
 
struct matrix{
	long long m[dim][dim];
	matrix(){
		for(int i = 0; i < dim; i++)
			for(int j = 0; j < dim; j++)
				m[i][j] = inf;
	}
 
	matrix operator * (matrix &a){
		matrix ret;
		for(int i = 0; i < dim; i++){
			for(int j = 0; j < dim; j++){
				for(int k = 0; k < dim; k++)
					ret.m[i][j] = min(ret.m[i][j], m[i][k] + a.m[k][j]);
			}
		}
		return ret;
	}
};
 
matrix _power(matrix base, long long b){
	matrix out = base;
	b--;
	while(b){
		if(b&1) out = out * base;
		base = base * base;
		b >>= 1;
	}
	return out;
}
 
int main() {
	matrix base;
	int n, m, k;
	cin >> n >> m >> k;
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		base.m[u][v] = min(base.m[u][v], 1LL * c);
	}
	matrix ans = _power(base, k);
	if (ans.m[1][n] >= inf)
		ans.m[1][n] = -1;
	cout << ans.m[1][n] << "\n";
	return 0;
}