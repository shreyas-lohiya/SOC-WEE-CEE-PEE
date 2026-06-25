#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t; 
    for(int i=1; i<=t; i++){
        int n; cin>>n; vector<int> v(n); for(int i=0; i<n; i++) cin>>v[i];
        int bought=0; int earned=0; int coin=0; 
        for(int i=0; i<n; i++){
            
            if(v[i]==0) continue;
            else if (v[i]<0) { v[i]*=-1;
                if (earned>=v[i]) earned-=v[i];
                else { bought+=v[i]-earned; coin+=v[i]-earned; earned=0;}
            }
            else{
                earned+=v[i];
            }

        }
        cout<<coin<<endl;
    }
}
