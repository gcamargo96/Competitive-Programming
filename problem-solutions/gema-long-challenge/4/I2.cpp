#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"

using namespace std;

const double PI=acos(-1);

struct Base{
	double real, imag;
	Base(){
		real = 0;
		imag = 0;
	}
	Base(double r, double i){
		real = r;
		imag = i;
	}
 	Base operator + (const Base& a) const { return Base(real+a.real, imag+a.imag); }
 	Base operator - (const Base& a) const { return Base(real-a.real, imag-a.imag); }
  	Base operator * (const Base& a) const { return Base(real*a.real - imag*a.imag, real*a.imag+imag*a.real); }
	Base operator / (const double& a) const { return Base(real/a,imag/a); }
};

const int M = 400005;
// string s, t, ss;
char s[M], t[M], ss[M];
int p[5];
size_t n;
int len;

int rev[M], a[M], b[M], ans[M], res[M];
Base fa[M], fb[M];
Base wlen_pw[M];

int dp[5][5][M];
 
void fft (Base a[], int n, bool invert) {
	for (int i=0; i<n; ++i)
		if (i < rev[i])
			swap (a[i], a[rev[i]]);
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert?-1:+1);
		int len2 = len>>1;
 
		Base wlen (cos(ang), sin(ang));
		wlen_pw[0] = Base (1, 0);
		for (int i=1; i<len2; ++i)
			wlen_pw[i] = wlen_pw[i-1] * wlen;
 
		for (int i=0; i<n; i+=len) {
			Base t,
				*pu = a+i,
				*pv = a+i+len2, 
				*pu_end = a+i+len2,
				*pw = wlen_pw;
			for (; pu!=pu_end; ++pu, ++pv, ++pw) {
				t = *pv * *pw;
				*pv = *pu - t;
				*pu = *pu + t;
			}
		}
	}
 
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] = a[i]/n;
}
 
void calc_rev (int n, int log_n) {
	for (int i=0; i<n; ++i) {
		rev[i] = 0;
		for (int j=0; j<log_n; ++j)
			if (i & (1<<j))
				rev[i] |= 1<<(log_n-1-j);
	}
}

// a, b => coefs to multiply,  res => resulting coefs
// a[0], b[0], res[0] = coef x^0
// Doesnt work with negative coefs
void multiply (int na, int nb, int c1, int c2) {
	// vector<Base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	n=1;
	while (n<max(na,nb)) n<<=1;
	n<<=1;

	for(int i = 0; i < n; i++){
		fa[i] = Base(a[i], 0);
	}
	for(int i = 0; i < n; i++){
		fb[i] = Base(b[i], 0);
	}

	calc_rev(n, log2(n));

	fft (fa,n,false);  fft(fb,n,false);

	for (size_t i=0; i<n; ++i)
		fa[i] = fa[i]*fb[i];
	fft (fa,n,true);
	// res.resize (n);
	// avoid precision errors, mess up with negative values of coefs
	for(size_t i=0; i<n; ++i){
		dp[c1][c2][i] = int(fa[i].real + 0.5);
		// printf("%d ", dp[c1][c2][i]);
	}
	// printf("\n");
		// res[i]=int(fa[i].real + 0.5);

	// for(int i = 0; i < n; i++){
	// 	printf("%d ", res[i]);
	// }
	// printf("\n");
}

void prepare(char x, char y){
	for(int i = 0; i < 2*len; i++){
		a[i] = s[i] == x ? 1 : 0;
	}

	for(int i = 0; i < len; i++){
		b[i] = t[i] == y ? 1 : 0;
	}
}

void update(int x){
	for(int i = 0; i < n; i++){
		ans[i] += dp[p[x]][x][i];
		// printf("%d ", ans[i]);
	}
	// printf("\n");
}

int main(void){
	// ios_Base::sync_with_stdio(false);
	// cin >> s >> t;
	// s += s;
	// t += t;

	scanf("%s", s);
	scanf("%s", t);

	len = strlen(s);

	for(int i = 0; i < len; i++){
		s[len+i] = s[i];
	}

	// reverse(t.begin(), t.end());
	for(int i = 0; i < len/2; i++){
		swap(t[i], t[len-1-i]);
	}

	for(int i = 0; i < 2*len; i++){
		s[i] = s[i] - 'A' + 'a';
	}

	for(int i = 0; i < 5; i++){
		p[i] = i;
	}

	// calcula a dp para todos os matchings
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			prepare('a'+i, 'a'+j);
			multiply(2*len, len, i, j);
		}
	}


	int MX = -1;

	do{
		// vector<int> a(s.size()), b(t.size()), aux, ans;
		memset(ans, 0, sizeof ans);

		for(int i = 0; i < 5; i++){
			update(i);
		}

		// reverse(ans.begin(), ans.end());

		int mx = -1;
		for(int i = 0; i < n; i++){
			mx = max(mx, ans[i]);
		}

		MX = max(MX, mx);
	} while(next_permutation(p, p+5));

	// cout << t.size() - MX << endl;
	printf("%d\n", len-MX);

	return 0;
}