//Merge Sort Tree, Insertion & Deletion

template<class T, int SZ> struct MBIT { //merge sort bit, 1...SZ-1
	OST<pair<T, int>> val[SZ]; 
	void upd(int x, T y, int t = 1) { //0 del, 1 ins
		for (int X = x; X < SZ; X += X&-X) {
			if (t == 1) val[X].ins({y,x});
			else val[X].ers({y,x});
		}
	}
	int qry(int i, T a) { //up to i, is there a?
		int res = 0; 
	for (; i; i -= i&-i) res += val[i].ook({a,MOD});
		return res;
	}
	int qry(int i, int j, T a, T b) { //in [i,j], how many are in range [a,b]
		return qry(j,b)-qry(j,a-1)-qry(i-1,b)+qry(i-1,a-1); 
	}
};
