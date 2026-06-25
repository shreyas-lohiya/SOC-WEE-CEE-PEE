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
        int n,m; cin>>n>>m; vector<string> s; string temp;
        while(n--) {
            cin>>temp; bool p=1;
            for(auto &e:s){
                if(temp==e) p=0;
            }
            if(p) s.push_back(temp);
        }
        if(s.size()==1) cout<<temp<<"\n";
        else if(m==1) cout<<"a"<<"\n";
        else{
            string ans=""; int count=0;
            for(int i=0; i<m; i++) {
                if(s[0][i]==s[1][i]) ans=ans+s[0][i];
                else ans=ans+"A",count++;
            }
            if(count>2) cout<<-1<<"\n";
            else if(count==2){
                string ans1="",ans2=""; bool p=1;
                for(int i=0; i<m; i++) {
                    if(s[0][i]==s[1][i]) ans1=ans1+s[0][i],ans2=ans2+s[0][i];
                    else if(p) ans1=ans1+s[0][i],ans2=ans2+s[1][i],p=0;
                    else ans1=ans1+s[1][i],ans2=ans2+s[0][i];
                }
                bool correct=1;
                for(auto &e:s){
                    int count=0;
                    for(int i=0; i<m; i++){
                        if(e[i]!=ans1[i]) count++;
                    }
                    if(count>1) {correct=0; break;}
                }
                if(correct) cout<<ans1<<"\n";
                else{
                    bool correct=1;
                    for(auto &e:s){
                        int count=0;
                        for(int i=0; i<m; i++){
                            if(e[i]!=ans2[i]) count++;
                        }
                        if(count>1) {correct=0; break;}
                    }
                    if(correct) cout<<ans2<<"\n";
                    else cout<<-1<<"\n";
                }
            }
            else if(count==1){
                int star;
                for(int i=0; i<m; i++) if(ans[i]=='A') star=i;
                bool set=0,correct=1;
                for(auto &e:s){
                    int count=0;
                    for(int i=0; i<m; i++){
                        if(e[i]!=ans[i]) count++;
                    }
                    if(set && count>1) {correct=0; break;}
                    else if(!set && count>2) {correct=0; break;}
                    else if(!set && count==2) {ans[star]=e[star]; set=1;}
                }
                if(!set) ans[star]='a';
                if(correct) cout<<ans<<"\n";
                else cout<<-1<<"\n";
            }
        }
    }
}
