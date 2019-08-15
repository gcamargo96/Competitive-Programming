#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define endl "\n"
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int MAXS = 315; //Sum of the lenght of all keywords
const int MAXC = 2; //Max chars in alphabet

int out[MAXS]; 

int f[MAXS];
int g[MAXS][MAXC];

int buildMatchingMachine(const vector<string> &words,
                         char lowestChar = '0',
                         char highestChar = '1') {
    memset(out, 0, sizeof out);
    memset(f, -1, sizeof f);
    memset(g, -1, sizeof g);
    
    int states = 1;
        
    for (int i = 0; i < words.size(); ++i) {
        const string &keyword = words[i];
        int currentState = 0;
        for (int j = 0; j < keyword.size(); ++j) {
            int c = keyword[j] - lowestChar;
            if (g[currentState][c] == -1) {
                g[currentState][c] = states++;
            }
            currentState = g[currentState][c];
        }
        out[currentState] |= (1 << i);
    }
    
    for (int c = 0; c < MAXC; ++c) {
        if (g[0][c] == -1) {
            g[0][c] = 0;
        }
    }

    queue<int> q;
    for (int c = 0; c <= highestChar - lowestChar; ++c) {
        if (g[0][c] != -1 and g[0][c] != 0) {
            f[g[0][c]] = 0;
            q.push(g[0][c]);
        }
    }
    while (q.size()) {
        int state = q.front();
        q.pop();
        for (int c = 0; c <= highestChar - lowestChar; ++c) {
            if (g[state][c] != -1) {
                int failure = f[state];
                while (g[failure][c] == -1) {
                    failure = f[failure];
                }
                failure = g[failure][c];
                f[g[state][c]] = failure;

                out[g[state][c]] |= out[failure]; 
                q.push(g[state][c]);
            }
        }
    }

    return states;
}

int findNextState(int currentState, char nextInput,
                                    char lowestChar = '0') {
    int answer = currentState;
    int c = nextInput - lowestChar;
    while (g[answer][c] == -1) answer = f[answer];
    return g[answer][c];
}

int w, b;
vector<string> seq;

double gauss (vector < vector<double> > mat) {
    int n = mat.size();
    int i, j, k, l;
    double t;
    for (j = 0; j < n; j++) {
        l = j;
        for (i = j+1; i < n; i++)
            if (fabs(mat[i][j]) > fabs(mat[l][j]))
                l = i;
        swap (mat[j], mat[l]);
        for (i = j+1; i < n; i++)
            for (k = n; k >=j; k--)
                mat[i][k] = mat[i][k] - (mat[j][k] * mat[i][j] / mat[j][j]);
    }
    vector <double> ans;
    ans.resize(n, 0.0);
    for (j = n-1; j >= 0; j--) {
        double at = 0.0;
        for (k = j+1; k < n; k++) at = at + mat[j][k] * ans[k];
        ans[j] = (mat[j][n] - at) / mat[j][j];
    }
    return ans[0];
}

int main() {
	cin >> w >> b;

    string s;
    for(int i = 0; i < w; i++){
        cin >> s;

        for(int j = 0; j < s.size(); j++){
            if(s[j] == 'H') s[j] = '0';
            else s[j] = '1';
        }

        seq.pb(s);
    }

    int states = buildMatchingMachine(seq, '0', '1');
    vector < vector < double> > mat;
    int n = states;
    mat.resize(n, vector<double> (n+1, 0));


    for (int i = 0; i < n; i++) {
  		mat[i][i] = 1;
  		
  		if(out[i]){
  			mat[i][n] = 0;
  		}
  		else{
  			mat[i][findNextState(i, '0')] -= 0.5;
  			mat[i][findNextState(i, '1')] -= 0.5;
  			mat[i][n] = 1;
  		}
    }

    printf("%.9lf\n", gauss(mat));
	
    return 0;
}