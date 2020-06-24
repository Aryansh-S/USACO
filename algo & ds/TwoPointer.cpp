const int SZ = 1e5;

int n, a[SZ], S, L, R;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> S; F0R(i,n) cin >> a[i];
  sort(a,a+n);
  int l=0, r=n-1; //keep two pointers (simply indices)
  while(l<r){ //we require the left pointer l to be to the left of r
    if(a[l]+a[r]==S) {L=l,R=r; break;}
    if(a[l]+a[r]<S) l++; else r--;
  }
  cout << L << " " << R << "\n";
  return 0;
}
