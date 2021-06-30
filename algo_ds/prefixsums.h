//2D prefix sums (less intuitive than the 1D case)
//0-indexed

template<class T> struct PSUM {
	vector<vector<T>> sum; //can access directly with .sum
	void init(const vector<vector<T>>& v) {
		int R = sz(v), C = sz(v[0]);
		sum.assign(R + 1, vector<T>(C + 1));
		F0R(i,R) F0R(j,C) sum[i + 1][j + 1] = v[i][j] + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
	}
	T get(int X1, int X2, int Y1, int Y2) { ++X2, ++Y2; return sum[X2][Y2] - sum[X1][Y2] - sum[X2][Y1] + sum[X1][Y1]; }
};
