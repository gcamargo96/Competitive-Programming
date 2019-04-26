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

// Ax = B
// columns 0 to n-1 are from A
// column n is B

// matrix declaration:
// vector < vector < double> > mat;
// int n = states+1;
// mat.resize(n, vector<double> (n+1, 0));