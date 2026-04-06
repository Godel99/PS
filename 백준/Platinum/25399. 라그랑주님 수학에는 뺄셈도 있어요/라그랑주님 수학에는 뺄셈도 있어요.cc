#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    ll n; cin >> n;
    const char *op[] = {"-", "+"};
    bool rv = 0 < n;
    n = abs(n);
    if(n == 0) return !(cout << "3\n+ 5\n- 4\n- 3\n");
    if(n == 2) return !(cout << "3\n" << op[rv] << " 6\n" << op[!rv] << " 5\n" << op[!rv] << " 3");
    if(n == (ll)sqrt(n)*(ll)sqrt(n)) return !(cout << "1\n" << op[rv] << " " << (ll)sqrt(n));
    if(n&1) return !(cout << "2\n" << op[rv] << " " << n/2+1 << '\n' << op[!rv] << " " << n/2);
    if((n&3) == 0) return !(cout << "2\n" << op[rv] << " " << n/4+1 << "\n" << op[!rv] << " " << n/4-1);
    for(ll p = 1; p <= (ll)sqrt(n/2); p++){
        ll t = n-p*p;
        ll re = (ll)sqrt(t);
        if(re*re == t) return !(cout << "2\n" << op[rv] << " " << re << "\n" << op[rv] << " " << p);
    }
    cout << "3\n" << op[!rv] << " 1\n" << op[rv] << " " << n/2+1 << "\n" << op[!rv] << " " << n/2;
    return 0;
}