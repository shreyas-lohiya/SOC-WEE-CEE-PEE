#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
using pii = pair<int,int>;
using vpi = vector<pii>;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define sortv(x) sort(all(x))
#define sortr(x) sort(rall(x))
template<class T1, class T2>
istream& operator>>(istream& in, pair<T1,T2>& p){
    in >> p.first >> p.second;
    return in;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1,T2>& p){
    return out << "\n" << p.first << " " << p.second;
}
template<class T>
istream& operator>>(istream& in, vector<T>& v){
    for(auto &x:v) in>>x;
    return in;
}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& v){
    for(auto &x:v) out<<x<<" ";
    return out;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1; cin>>t;
    while(t--){
        int n; cin>>n; vi a(n),b(n); cin>>a>>b;
        int dminus=0,dplus=0,scorea=0,scoreb=0;
        for(int i=0; i<n; i++){
                 if(a[i]==-1 && b[i]==-1) dminus++;
            else if(a[i]==-1 && b[i]==0) continue;
            else if(a[i]==-1 && b[i]==1) scoreb++;
            else if(a[i]==0 && b[i]==-1) continue;
            else if(a[i]==0 && b[i]==0) continue;
            else if(a[i]==0 && b[i]==1) scoreb++;
            else if(a[i]==1 && b[i]==-1) scorea++;
            else if(a[i]==1 && b[i]==0) scorea++;
            else if(a[i]==1 && b[i]==1) dplus++;
        }
        int big=max(scorea,scoreb);
        int small=min(scorea,scoreb);
        if(dplus<=big-small){
            small+=dplus;
            if(dminus<=big-small){
                big-=dminus;
                cout<<small;
            }
            else{
                dminus-=big-small;
                big=small;
                cout<<small-((dminus+1)/2);
            }
        }
        else{
            dplus-=big-small;
            small=big;
            if(dplus>=dminus){
                dplus-=dminus;
                cout<<small+(dplus/2);
            }
            else{
                dminus-=dplus;
                cout<<small-((dminus+1)/2);
            }
        }

        cout<<"\n";
    }
}
