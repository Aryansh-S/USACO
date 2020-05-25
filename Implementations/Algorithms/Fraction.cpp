struct frac{
  int num = 0, den = 1; 
  void simp(){
    int gcd = __gcd(num,den); num/=gcd, den/=gcd;
  }
  void rec(){ swap(num,den); }
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
