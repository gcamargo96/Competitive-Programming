#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"

using namespace std;

const double PI=acos(-1);

typedef complex<double> base;

string s, t, ss;
vector<int> p;

void fft (vector<base> & a, bool invert) {
	int n=(int) a.size();
	for (int i=1, j=0; i<n; ++i) {
		int bit=n>>1;
		for (;j>=bit;bit>>=1)
			j-=bit;
		j+=bit;
		if(i<j)
			swap(a[i],a[j]);
	}
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w(1);
			for (int j=0; j<len/2; ++j) {
				base u=a[i+j], v=a[i+j+len/2]*w;
				a[i+j]=u+v;
				a[i+j+len/2]=u-v;
				w*=wlen;
			}
		}
	}
	if (invert)
		for(int i=0;i<n;++i)
			a[i]/=n;
}

// a, b => coefs to multiply,  res => resulting coefs
// a[0], b[0], res[0] = coef x^0
// Doesnt work with negative coefs
void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n=1;
	while (n<max(a.size(),b.size())) n<<=1;
	n<<=1;
	fa.resize(n),fb.resize(n);
	fft (fa,false);  fft(fb,false);

	

	for (size_t i=0; i<n; ++i)
		fa[i]*=fb[i];
	fft (fa, true);
	res.resize (n);
	// avoid precision errors, mess up with negative values of coefs
	for(size_t i=0; i<n; ++i)
		res[i]=int(fa[i].real() + 0.5);


	// for(int i = 0; i < n; i++){
	// 	printf("%d ", res[i]);
	// }
	// printf("\n");
}

void match(){
	ss.resize(s.size());

	for(int i = 0; i < s.size(); i++){
		ss[i] = p[s[i]-'a'];
	}
}

void prepare(vector<int> & a, vector<int> & b, char c){
	for(int i = 0; i < a.size(); i++){
		a[i] = ss[i] == c ? 1 : 0;
	}

	for(int i = 0; i < b.size(); i++){
		b[i] = t[i] == c ? 1 : 0;
	}
}

void add(vector<int> & a, vector<int> & b){
	a.resize(b.size());
	for(int i = 0; i < a.size(); i++){
		a[i] += b[i];
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s >> t;
	s += s;
	// t += t;
	
	reverse(t.begin(), t.end());

	for(int i = 0; i < s.size(); i++){
		s[i] = s[i] - 'A' + 'a';
	}

	for(char c = 'a'; c <= 'e'; c++){
		p.pb(c);
	}

	int MX = -1;

	do{
		vector<int> a(s.size()), b(t.size()), aux, ans;
		match();
		for(char c = 'a'; c <= 'e'; c++){
			prepare(a, b, c);
			multiply(a, b, aux);
			add(ans, aux);
		}

		reverse(ans.begin(), ans.end());

		int mx = -1;
		for(int i = 0; i < ans.size(); i++){
			mx = max(mx, ans[i]);
		}

		MX = max(MX, mx);
	} while(next_permutation(p.begin(), p.end()));

	// cout << t.size() - MX << endl;
	printf("%d\n", int(t.size())-MX);

	return 0;
}