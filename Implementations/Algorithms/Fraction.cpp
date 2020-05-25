struct frac{
  int num = 0, den = 1; 
  frac(int n = 0, int d = 1){num = n, den = d;}
  void simp(){
    int gcd = __gcd(num,den); num/=gcd, den/=gcd;
  }
  bool operator==(frac f){return num * f.den == den * f.num;}
  frac operator+(frac f){
    frac ret = {num * f.den + den * f.num, den * f.den}; ret.simp(); return ret;
  }
  frac operator-(frac f){
    frac ret = {num * f.den - den * f.num, den * f.den}; ret.simp(); return ret; 
  }
  frac operator*(frac f){
    frac ret = {num * f.num, den * f.den}; ret.simp(); return ret; 
  }
  frac operator/(frac f){
    frac ret = {num * f.den, den * f.num}; ret.simp(); return ret;
  }
  long double val(){return (long double)num / (long double)den;}
};
