int nxtpw2(int v){
	if((bool)v & !(v & (v - 1))) return v; 
	int x = 1; while(x < v) x<<=1; return x; 
}
