#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 500005;
vector<int> s[N];
int at = 0;

struct No {
    int L, R, p, suff, id;
    map <int, int> f;
    No() {}
    No(int l, int r, int P, int ID) : L(l), R(r), p(P), id(ID) {}
    inline int len () {
        return R-L+1;
    }
    inline int operator[] (int i) {
        return s[id][L + i];
    }
} t[2*N];

int novo (int L, int R, int p, int id) {
    t[at] = No (L, R, p, id);
    at++;
    return at-1;
}

//Caso 1: S[i..j] já existe
//Caso 2: vertice nao folha e estou de fato no nó
//Caso 3: vertice nao folha e estou no meio da aresta
//Caso 4: vertice folha
void build_suffix_tree (vector<int>& s, int id) {    
    // s += "$";
    int i = 0, cn = 0, cd = 0, ns = 0;
    int n = s.size();
    for (int j = 0; j < s.size(); j++) {
        for (; i <= j; i++) {
            if (t[cn].len() == cd ? t[cn].f.count(s[j]) : t[cn][cd] == s[j]) {//CASO 1
                if (t[cn].len() == cd) {
                    cd = 0;
                    cn = t[cn].f[s[j]];
                }
                cd++;
                break;
            } else if (t[cn].len() == cd) {//CASO 2
                t[cn].f[s[j]] = novo(j, n-1, cn, id);
                if (cn) {
                    cn = t[cn].suff;
                    cd = t[cn].len();
                }
            } else {//CASO 3 (precisa criar o suffix link)
                //quebrar a aresta
                int mid = novo (t[cn].L, t[cn].L + cd - 1, t[cn].p, t[cn].id);
                t[t[mid].p].f[t[mid][0]] = mid;
                t[mid].f[s[j]] = novo (j, n-1, mid, id);
                t[mid].f[t[cn][cd]] = cn;
                t[cn].p = mid;
                t[cn].L += cd;
                if (ns) t[ns].suff = mid;
                //achar o suffix link de mid
                cn = t[mid].p;
                int g;
                if (cn) {
                    cn = t[cn].suff;
                    g = j - cd;
                } else g = i+1;
                while (g < j && g + t[t[cn].f[s[g]]].len() <= j) {
                    cn = t[cn].f[s[g]];
                    g += t[cn].len();
                }
                if (g == j) {
                    t[mid].suff = cn;
                    cd = t[cn].len();
                    ns = 0;
                } else { // g < j
                    ns = mid;
                    cn = t[cn].f[s[g]];
                    cd = j - g;
                }
            }
        }
    }
}

int k;
string ans;
int n;
ll L, R, a, b, x, y;
ll acc[N];
vector<ll> seg[4*N];

void build_seg(int p, int l, int r) {
    if(l == r) {
        seg[p].pb(acc[l]);
    } else {
        int mid = (l + r)/2;
        build_seg(2 * p, l, mid);
        build_seg(2 * p + 1, mid+1, r);
 
        seg[p].resize(r - l + 1);
        merge(seg[2 * p].begin(), seg[2 * p].end(), seg[2 * p + 1].begin(), seg[2 * p + 1].end(), seg[p].begin());
    }
 
}
 
int query(int p, int l, int r) {
    if(l > b or r < a) return 0;
    if(l >= a and r <= b) {
        int i = upper_bound(seg[p].begin(), seg[p].end(), y) - seg[p].begin();
        int j = lower_bound(seg[p].begin(), seg[p].end(), x) - seg[p].begin();
        return max(0, i - j);
    }

    int mid = (l + r)/2;
    return query(2 * p, l, mid) + query(2 * p + 1, mid+1, r);
}

ll dfs(int cn, ll sum){
    ll ret = 0;

    if(t[cn].R >= t[cn].L){
        ll pre = t[cn].L > 0 ? acc[t[cn].L-1] : 0;
        a = t[cn].L, b = t[cn].R;
        x = L+pre-sum, y = R+pre-sum;
        
        ret += query(1, 0, n-1);
    }

    // cout << "L = " << t[cn].L << ", R = " << t[cn].R << ", x = " << x << ", y = " << y << ", ret = " << ret << endl;

    sum += acc[t[cn].R] - (t[cn].L > 0 ? acc[t[cn].L-1] : 0);

    for(auto it : t[cn].f){
        ret += dfs(it.se, sum);
    }

    return ret;
}

int main(void){
    fastcin;

    novo (0, -1, -1, 0); //criando raiz

    cin >> n >> L >> R;

    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        s[0].pb(x);
        acc[i] = i > 0 ? acc[i-1] + x : x;
    }

    build_seg(1, 0, n-1);
    build_suffix_tree(s[0], 0);

    ll ans = dfs(0, 0);

    cout << ans << endl;

    return 0;
}