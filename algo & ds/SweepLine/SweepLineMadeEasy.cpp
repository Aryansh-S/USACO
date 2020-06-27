vector<pii> pts; 

inline void io() { cin.tie(0)->sync_with_stdio(0); cout.precision(2); cout.setf(ios::fixed,ios::floatfield); }

inline void ans(int a) { cout << sqrt((double)a) << "\n"; }

inline void getpts(int n) { while(n--) { int x,y; cin >> x >> y; pts.pb(mp(x, y)); } }
    //input pts

struct cmps { bool operator()(pii a, pii b) { return a.s == b.s ? a.f < b.f : a.s < b.s; } };
    //sort by secondary coord

int n, d = INF; 
    //d must be "infinity" to begin with

set<pii, cmps> act;
    //active set sorted by secondary coord comparator 

int main(){
    io();
    cin >> n; getpts(n); 
    
    sort(begin(pts), end(pts));
        //sort pts by first coord

    int l = 0; //left ptr
    
    for(int i = 0; i < n; ++i) {
        pii curr = pts[i]; //get current pt
        
        int x = curr.f, y = curr.s; //set up coords
        
        while(x - pts[l].f >= d) act.ers(pts[l]), l++;
            //horizontal narrow threshold: the distance d can be used to delete things not within horizontal vicinity d
            //forward the pointer l accordingly 
        
        auto L = act.lb(mp(x, y - ceil(sqrt(d)))), R=act.ub(mp(x, y + ceil(sqrt(d)))); 
            //vertical narrow threshold: binary search for the lowest and highest points within d of curr (others are meaninglesss to consider)  
        
        it = L;
            //start at the leftmost point to consider
        
        while(it != R) ckmin(d, dist(*it, curr)), ++it;
            //range through to the right
        
        act.ins(curr);
            //current point now in active set
    }

    ans(d);
}
