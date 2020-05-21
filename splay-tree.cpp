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

struct SplayTree{
    struct SplayNode{
        SplayNode *right,*left,*parent;
        int size;
        int value;

        SplayNode(){
            left=nullptr;
            right=nullptr;
            parent=nullptr;
            size=1;
        }

        void rotate(){
            SplayNode *c,*p,*pp;
            p=this->parent;
            pp=p->parent;

            if(p->left==this){
                c=this->right;
                this->right=p;
                p->left=c; 
            }else{
                c=this->left;
                this->left=p;
                p->right=c; 
            }

            if(pp && pp->left==p)pp->left=this;
            if(pp && pp->right==p)pp->right=this;
            this->parent=pp;
            p->parent=this;
            if(c)c->parent=p;
            
            p->update();
            this->update();
        }

        int state(){
            if(!parent)return 0;
            if(parent->left==this)return 1;
            if(parent->right==this)return -1;
            return 0;
        }
        
        void splay(){
            while(parent){
                if(parent->state()==0){
                    this->rotate();
                }else if(this->state()==parent->state()){
                    this->parent->state();
                    this->state();
                }else{
                    this->state();
                    this->state();
                }
            }
        }

        void update(){
            size=1;
            if(this->left)this->size+=this->left->size;
            if(this->right)this->size+=this->right->size;
        }
    };


    SplayNode *get(int ind,SplayNode *root){
        SplayNode *now=root;
        while(1){
            int lsize=(now->left ? now->left->size : 0);
            if(ind < lsize){
                now=now->left;
            }else if(ind==lsize){
                now->splay();
                return now;
            }else if(ind > lsize){
                now=now->right;
                ind=ind-lsize-1;
            }
        }
    }
};

bool solve(){
    return false;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(30);
    solve();
}
