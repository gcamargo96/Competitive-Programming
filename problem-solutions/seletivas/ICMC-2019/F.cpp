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
string s[N];
int at = 0;

struct No {
    int L, R, p, suff, id;
    ll sub = 0;
    map <char, int> f;
    No() {}
    No(int l, int r, int P, int ID) : L(l), R(r), p(P), id(ID) {}
    inline int len () {
        return R-L+1;
    }
    inline char operator[] (int i) {
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
void build_suffix_tree (string& s, int id) {    
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

ll precalc(int cn){
    if(t[cn].f.size() == 0){
        return t[cn].sub = t[cn].len();
    }

    ll ret = t[cn].len();
    for(auto it : t[cn].f){
        ret += precalc(it.se);
    }

    return t[cn].sub = ret;
}

void add_prefix(int cn, int len){
    for(int i = 0; i < len; i++){
        ans += t[cn][i];
    }
}

void kth(int cn, ll cnt){
    if(cnt + t[cn].len() >= k){
        int falta = k-cnt;
        add_prefix(cn, falta);
        return;
    }
    else if(cnt + t[cn].len() < k){
        add_prefix(cn, t[cn].len());
        cnt += t[cn].len();
    }


    for(auto it : t[cn].f){
        if(cnt + t[it.se].sub >= k){
            kth(it.se, cnt);
            break;
        }
        else{
            cnt += t[it.se].sub;
        }
    }
}

void dfs(int cn){
    for(int i = 0; i < t[cn].len(); i++){
        cout << t[cn][i];
    }
    cout << endl;
    cout << t[cn].sub << endl;


    for(auto it : t[cn].f){
        dfs(it.se);
    }
}

int main(void){
    fastcin;

    novo (0, -1, -1, 0); //criando raiz

    cin >> s[0];
    build_suffix_tree(s[0], 0);
    precalc(0);

    // dfs(0);

    int q;
    cin >> q;

    while(q--){
        cin >> k;
        kth(0, 0);
        cout << ans << endl;
        ans.clear();
    }

    return 0;
}