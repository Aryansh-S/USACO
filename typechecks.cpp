//SFINAE type checks -- C++11 concept checking & std::enable_if

#include <bits/stdc++.h>
using namespace std;

// -- USED IN TEMPLATE -- //

#include <cxxabi.h> //typenames
template<class T> inline string type_name() { 
	typedef typename remove_reference<T>::type TR;
	unique_ptr<char, void(*)(void*)> own
	(abi::__cxa_demangle(typeid(TR).name(), nullptr,nullptr,nullptr),free); 
	string r = own != nullptr ? own.get() : typeid(TR).name();
	if (is_const<TR>::value) 
		r += " const";
	if (is_volatile<TR>::value) 
		r += " volatile";
	if (is_lvalue_reference<T>::value) 
		r += "&";
	else if (is_rvalue_reference<T>::value) 
		r += "&&";
	return r;
}
#define type(x) type_name<decltype(x)>()

template<class T> class is_iterator { //check if iterator or pointer   
	static T makeT();
	typedef void * twoptrs[2];  
	static twoptrs & test(...); 
	template<class R> static typename R::iterator_category * test(R); // Iterator
	template<class R> static void * test(R *); // Pointer
	public: static const bool value = sizeof(test(makeT())) == sizeof(void *); 
};
template<class T> class is_streamable { //check if can be used with cin >>, cout << 
	template<typename SS, typename TT> static auto test(int)->
	decltype(declval<SS&>() << declval<TT>(),true_type());
	template<typename, typename> static auto test(...)->false_type;
	public: static const bool value = decltype(test<ostream, const T&>(0))::value;
};

// -- OTHER (POSSIBLY USEFUL) -- //

template<typename T> auto is_iterable_impl(int)->decltype (begin(declval<T&>()) != end(declval<T&>()), 
void(), ++declval<decltype(begin(declval<T&>()))&>(), void(*begin(declval<T&>())), true_type{});
template<typename T> false_type is_iterable_impl(...);
template <typename T> using is_iterable = decltype(is_iterable_impl<T>(0));

// -- EXAMPLES -- //

template<typename T, typename = typename enable_if<is_streamable<T>::value>::type> inline void out(T var) {
	cout << var << "\n";
}

namespace extend_std { 
	//define begin() and end() for non-iterable types; enable_if and SFINAE destroy ambiguity 
	template<typename T, typename = typename enable_if<!is_iterable<T>::value>::type> inline T* begin(T& var){
		return &var; 
	}
	template<typename T, typename = typename enable_if<!is_iterable<T>::value>::type> inline T* end(T& var){
		return begin(var)+1;
	}
}
using namespace extend_std; 

int a = 0x3f, b[]={1,2,3}; vector<int> c = {1,2,3};

int main() {
	assert(*begin(a)==a);
	assert(*(end(a)-1)==a);
	assert(*begin(b)==b[0]);
	assert(*(end(c)-1)==c[c.size()-1]);
}
