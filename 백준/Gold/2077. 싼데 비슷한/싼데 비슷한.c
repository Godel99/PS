#include <stdio.h>

typedef long long ll;

ll S[4];

ll min4(ll a, ll b, ll c, ll d) {
    ll m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    if (d < m) m = d;
    return m;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        printf("YES\n");
        
        int n;
        scanf("%d", &n);
        S[0] = S[1] = S[2] = S[3] = 0;
        
        for (int i = 1; i <= n; i++) {
            int t;
            scanf("%d", &t);
            S[i % 4] += t;
        }
        
        ll m = min4(S[0], S[1], S[2], S[3]);
        
        if (S[2] == m) {
            printf("0");
            n--;
        }
        else if (S[3] == m) {
            printf("01");
            n -= 2;
        }
        else if (S[0] == m) {
            printf("022");
            n -= 3;
        }
        
        while (n >= 4) {
            n -= 4;
            printf("0333");
        }
        
        if (n) printf("0");
        if (n == 2) printf("1");
        if (n == 3) printf("22");
        
        printf("\n");
    }
    
    return 0;
}