#include<bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long int ll;
typedef long double ld;
const ll INF=(1LL<<62);
const ld pi=acosl((ld)-1);
const ll mod = 1000000007;
// const ll mod = 1234567;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int ddx[8]={1,0,-1,-1,-1,0,1,1};
const int ddy[8]={1,1,1,0,-1,-1,-1,0};
#define endn "\n"
#define TO_STRING(VariableName) # VariableName

template <typename T>ostream &operator<<(ostream &out,const vector<T> &v) {rep(i,(int)v.size()-1)cout<<v[i]<<" ";cout<<v[(int)v.size()-1];return out;}
template <typename T1, typename T2>ostream &operator<<(ostream &out, const map<T1, T2> &p) {out << "(" << p.first << ", " << p.second << ")";return out;}
template <typename T1, typename T2>ostream &operator<<(ostream &out, const pair<T1, T2> &p){out << "(" << p.first << ", " << p.second << ")";return out;}
template<class T>void debag(const T &obj){cout<<obj<<endl;}

template<class T>
struct PersistentArray{
    int cnt=0;
    int n;
    vector<T>update_data;//保存用
    vector<vector<int>>search_data;//検索用

    PersistentArray(int sz) : search_data(sz){n=sz;}

    int update(int ind,T key){
        search_data[ind].push_back(cnt);
        update_data.push_back(key);
        return cnt++;
    }
    T get(int k,int ind){return update_data[*(--upper_bound(all(search_data[ind]),k))];}

    // void show(int k=-1){rep(i,n)cout<<get((k==-1 ? cnt : k),i)<<" ";cout<<endl;}
};

bool solve(){
    PersistentArray<int>array(3);
    array.update(0,1);
    array.update(1,2);
    int x=array.update(2,3);
    // array.show();//[1,2,3]

    array.update(0,5);
    // array.show();//[5,2,3]

    // array.show(x);//[1,2,3]
    rep(i,3)cout<<array.get(x,i)<<" ";
    cout<<endl;
    return false;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(30);
    solve();
}
