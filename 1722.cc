#include <bits/stdc++.h>
using namespace std;

const int dim = 2;
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
	base.m[0][0] = base.m[0][1] = base.m[1][0] = 1;
	long long n;
	cin >> n;

	if (n <= 1) {
		cout << n << "\n";
		return 0;
	}

	matrix ans = _power(base, n - 1);
	cout << ans.m[0][0] << "\n";
	return 0;
}