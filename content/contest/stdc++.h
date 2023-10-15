#include <bits/stdc++.h>
using namespace std;

template <typename T> constexpr
void __print (const T &x);

template<typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << "{"; __print(x.first);
  cerr << ", "; __print(x.second); cerr << "}";
}
template <typename T> constexpr
void __print (const T &x) {
  if constexpr (is_arithmetic_v<T> ||
    is_same_v<T,const char*> || is_same_v<T,bool>
    || is_same_v<T, string>) cerr << x;
  else {
    int f = 0; cerr << '{';
    for (auto &i: x)
      cerr << (f++ ? ", " : ""), __print(i);
    cerr << "}";
  }
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}

#ifdef DeBuG
#define dbg(x...) cerr << "\t\e[93m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[0m";
#endif