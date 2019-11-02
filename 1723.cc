#include <bits/stdc++.h>
using namespace std;

int _add(int a, int b, int mod){
	a += b;
	if(a >= mod) a -= mod;
	return a;
}

int _sub(int a, int b, int mod){
	a -= b;
	if(a < 0) a += mod;
	return a;
}

int _mult(int a, int b, int mod){
	return (1LL * a * b) % mod;
}

int _power(int a, int b, int mod){
	if(!b) return 1;
	int x = _power(a, b >> 1, mod);
	x = _mult(x, x, mod);
	if(b&1) x = _mult(x, a, mod);
	return x;
}

int _inverse(int x, int mod){
	return _power(x, mod - 2, mod);
}

int _div(int a, int b, int mod){
	return _mult(a, _inverse(b, mod), mod);
}

const int dim = 101;
const int modulo = 1000000007;
 
struct matrix{
	int m[dim][dim];
	matrix(){
		for(int i = 0; i < dim; i++)
			for(int j = 0; j < dim; j++)
				m[i][j] = 0;
	}
 
	void unit(){
		for(int i = 0; i < dim; i++)
			for(int j = 0; j < dim; j++)
				m[i][j] = (i == j)?1:0;
	}
 
	matrix operator + (matrix &a){
		matrix ret;
		for(int i = 0; i < dim; i++)
			for(int j = 0; j < dim; j++)
				ret.m[i][j] = (m[i][j] + a.m[i][j]) % modulo;
		return ret;
	}
 
	matrix operator * (matrix &a){
		matrix ret;
		for(int i = 0; i < dim; i++){
			for(int j = 0; j < dim; j++){
				for(int k = 0; k < dim; k++){
					ret.m[i][j] = (ret.m[i][j] + 1LL * m[i][k] * a.m[k][j]) % modulo;
				}
			}
		}
		return ret;
	}
};
 
matrix _power(matrix base, long long b){
	matrix out;
	out.unit();
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
		int u, v;
		cin >> u >> v;
		base.m[u][v] += 1;
	}
	matrix ans = _power(base, k);
	cout << ans.m[1][n] << "\n";
	return 0;
}