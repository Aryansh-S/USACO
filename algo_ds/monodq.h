//Monotonic Deque Trick (default: strictly increasing monotonic queue, small...large)
//O(1) amortized insertion and deletion 

template<class T> struct mdq {
	deque<T> dq; 
	void push(T x) {
		while(sz(dq) && dq.bk() >= x) dq.ppb(); //= sign disallows rep 
		dq.pb(x); 
	} 
};
