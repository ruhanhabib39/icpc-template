/**
 * Author: Arman Ferdous
 * Date:
 * License: 
 * Source: Internet
 * Description: Call \texttt{build()} first, then query (uper-left, lower-right).
 * Time: build() in $\mathcal{O}(nm\lg(n)\lg(m))$ query $\mathcal{O}(1)$
 * Status: Tested
 */

struct SparseTable2D{
	int n, m, t[10][500][10][500];

	int lg(int x) { return 31 - __builtin_clz(x); }
	
	void build(int _n, int _m, int a[][500]) {
		n = _n, m = _m;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++)
				t[0][i][0][j] = a[i][j];

			for(int jj = 1; jj < 10; jj++)
				for(int j = 0; j + (1 << (jj - 1)) < m; j++) 
					t[0][i][jj][j] = min(t[0][i][jj - 1][j], t[0][i][jj - 1][j + (1 << (jj - 1))]);
		}

		for(int ii = 1; ii < 10; ii++) 
			for(int i = 0; i + (1 << (ii - 1)) < n; i++)
				for(int jj = 0; jj < 10; jj++)
					for(int j = 0; j < m; j++)
						t[ii][i][jj][j] = min(t[ii - 1][i][jj][j], t[ii - 1][i + (1 << (ii - 1))][jj][j]);
	}

	int query(int x1, int y1, int x2, int y2) {
		int kx = lg(x2 - x1 + 1), ky = lg(y2 - y1 + 1);
		int r1 = min(t[kx][x1][ky][y1], t[kx][x1][ky][y2 - (1 << ky) + 1]);
		int r2 = min(t[kx][x2 - (1 << kx) + 1][ky][y1], t[kx][x2 - (1 << kx) + 1][ky][y2 - (1 << ky) + 1]);
		return min(r1, r2);
	}
};

