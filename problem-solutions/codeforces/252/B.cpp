#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

int days[3001];

int main() {
    int n, v;
    scanf("%d%d", &n, &v);
    for (int i = 0; i < n; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
        days[a - 1] += b;
    }
    int ant = 0, ans = 0;
    for (int i = 0; i <= 3000; ++ i) {
        int antn = std :: min(ant, v);
        int sbr = std :: min(days[i], v - antn);
        ans += antn + sbr;
        ant = days[i] - sbr;
    }
    printf("%d\n", ans);
    return 0;
}
