template<class T, int SZ> struct Krus{ //also get DSU
    DSU d; T weight; Krus(){d.init(SZ);}
    vector<pair<T,pii> > edge,MST;
    void add(int a, int b, T w){
        edge.pb(mp(w,mp(a,b)));
        edge.pb(mp(w,mp(b,a)));
    }
    void add_(int a, int b, T w){
        edge.pb(mp(w,mp(a,b)));
    }
    void upd(){
        sort(begin(edge),end(edge));
        F0R(i,edge.size()){
            int urep=d.get(edge[i].s.f),
            vrep=d.get(edge[i].s.s);
            if(urep!=vrep){
                MST.pb(edge[i]); d.unite(edge[i].s.f,edge[i].s.s); weight+=edge[i].f;
            }
        }
    }
    T sum(){return weight;}
    vector<pair<T,pii> > getMST(){return MST;}
};

Krus<int,100> k;

int main(){
    k.add(1,2,1);
    k.add(2,3,2);
    k.add(3,4,5);
    k.add(1,3,4);
    k.upd();
    cout << k.sum() << "\n";
    return 0;
}
