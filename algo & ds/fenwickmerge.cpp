//Merge Sort Tree, Insertion & Deletion
//good for existence queries and bound queries on subarrays (log^2 n)

template<class T, int SZ> struct MBIT { //merge sort bit (zero indexed!)
	OST<pair<T, int>> val[SZ + 1]; 
	void upd(int x, T y, int t = 1) { //0 del, 1 ins -- put y at index x
    		++x;
		for(int X = x; X < SZ; X += X&-X) {
			if(t == 1) val[X].ins({y,x});
			else val[X].ers({y,x});
		}
	}
	int qryd(int i, T a) {
		int res = 0; 
		for(; i; i -= i&-i) res += val[i].ook({a,MOD});
		return res;
	}
	int qry(int i, int j, T a, T b) { //in subarray [i,j], how many are in range [a,b]
    		++i,++j;
		return qryd(j,b)-qryd(j,a-1)-qryd(i-1,b)+qryd(i-1,a-1); 
	}
};
