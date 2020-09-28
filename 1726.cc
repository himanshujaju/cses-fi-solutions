#include <bits/stdc++.h>
using namespace std;

constexpr int N = 64;

struct matrix {
	matrix() {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				mat[i][j] = 0.0;
	}

	matrix operator*(const matrix& a) {
		matrix ret;

		// Cache unoptimised version.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					ret.mat[i][j] += mat[i][k] * a.mat[k][j];
				}
			}
		}
		return ret;
	}

	double mat[N][N];
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int encode(int x, int y) {
	assert(x >= 0 && x < 8 && y >= 0 && y < 8);
	return x * 8 + y;
}

int main() {
	matrix base;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			int possible_moves = 0;

			for (int d = 0; d < 4; d++) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (min(nx, ny) >= 0 && max(nx, ny) < 8) {
					possible_moves += 1;
					base.mat[encode(i, j)][encode(nx, ny)] = 1.0;
				}
			}

			for (int x = 0; x < N; x++) {
				base.mat[encode(i, j)][x] /= possible_moves;
			}
		}
	}

	matrix ans = base;
	int K;
	cin >> K;
	for (int i = 2; i <= K; i++) {
		ans = ans * base;
	}

	double exp = 0;
	for (int i = 0; i < N; i++) {
		double val = 1.0;
		for (int j = 0; j < N; j++) {
			val = val * (1.0 - ans.mat[j][i]);
		}
		exp += val;
	}
	cout << fixed << setprecision(6) << exp << "\n";
	return 0;
}
