#include <bits/stdc++.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}