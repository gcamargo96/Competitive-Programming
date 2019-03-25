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

const int N = 200005;
char s[12][N];
int at = 0;

struct No {
    int L, R, p, suff, id;
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
void build_suffix_tree (char* s, int id) {    
    // s += "$";
    int i = 0, cn = 0, cd = 0, ns = 0;
    int n = strlen(s);
    for (int j = 0; j < n; j++) {
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

int tests, cnt;
bitset<10> simbols[2*N];

void set_simbols(int cn){
    char c = t[cn][t[cn].len()-1];
    if(c >= '0' and c <= '9'){
        simbols[cn].set(c-'0');
    }
}

void merge_child(int cn, int ch){
    simbols[cn] |= simbols[ch];
}

void precalc(int cn){
    set_simbols(cn);    

    for(auto it : t[cn].f){
        precalc(it.se);
        merge_child(cn, it.se);
    }
}

int max_path(int cn){
    if(simbols[cn].count() < cnt){
        return 0;
    }

    int ret = t[cn].len();
    for(auto it : t[cn].f){
        ret = max(ret, t[cn].len() + max_path(it.se));
    }

    return ret;
}

void dfs(int cn){
    for(int i = 0; i < t[cn].len(); i++){
        cout << t[cn][i];
    }
    cout << endl;

    for(int i = 0; i < 10; i++){
        cout << simbols[cn][i];
    }
    cout << endl;

    for(auto it : t[cn].f){
        dfs(it.se);
    }
}

int main(void){
    novo (0, -1, -1, 0); //criando raiz

    for(int i = 0; scanf("%s", s[i]) != EOF; i++){
        char c[2];
        c[0] = cnt+'0';
        c[1] = '\0';
        strcat(s[i], c);
        cnt++;
        build_suffix_tree(s[i], i);
    }

    precalc(0);
    int ans = max_path(0);
    // dfs(0);

    // cout << ans << endl;
    printf("%d\n", ans);

    return 0;
}