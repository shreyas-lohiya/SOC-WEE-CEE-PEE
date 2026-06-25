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
        int n,temp,sum=0; cin>>n; multiset<int> s; for(int i=0; i<n; i++) cin>>temp,s.insert(temp),sum+=temp;
        multiset<int> s2; s2.insert(sum);
        //for (const auto& element : s) cout << element << " "; cout<<endl;
        //for (const auto& element : s2) cout << element << " "; cout<<endl; cout<<endl;
        while(s.size()>=s2.size() && s2.size()>0){
            auto it=s.end(); it--;
            auto it2=s2.end(); it2--;
            if(*it==*it2){
                s.erase(it); s2.erase(it2);
            }
            else{
                s2.insert(*it2/2);
                s2.insert((*it2+1)/2);
                s2.erase(it2);
            }
            //for (const auto& element : s) cout << element << " "; cout<<endl;
            //for (const auto& element : s2) cout << element << " "; cout<<endl; cout<<endl;
        }
        cout<<(s2.size()==0 && s.size()==0?"YES":"NO")<<"\n";
    }
}
