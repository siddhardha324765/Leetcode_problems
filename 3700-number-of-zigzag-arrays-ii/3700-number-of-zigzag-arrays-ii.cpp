class Solution {
public:
    const long long MOD = 1000000007LL;

    // Matrix × Matrix
    vector<vector<long long>> multiplyMatrix( vector<vector<long long>>& A,vector<vector<long long>>& B){
        int sz = A.size();
        vector<vector<long long>> C(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++){
            for (int k = 0; k < sz; k++){
                if (A[i][k] == 0) continue;
                long long cur = A[i][k];
                for (int j = 0; j < sz; j++){
                    if (B[k][j] == 0) continue;
                    C[i][j] = (C[i][j] + cur * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    // Vector × Matrix
    vector<long long> multiplyVector(vector<long long>& V,vector<vector<long long>>& A){
        int sz = V.size();
        vector<long long> C(sz, 0);
        for (int i = 0; i < sz; i++) {
            if (V[i] == 0) continue;
            long long cur = V[i];
            for (int j = 0; j < sz; j++) {
                if (A[i][j] == 0) continue;
                C[j] = (C[j] + cur * A[i][j]) % MOD;
            }
        }
        return C;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;
        vector<vector<long long>> T(sz, vector<long long>(sz, 0));
        for (int x = 0; x < m; x++) {
            for (int y = x + 1; y < m; y++)
                T[x][m + y] = 1;

            for (int y = 0; y < x; y++)
                T[m + x][y] = 1;
        }
        vector<long long> result(sz, 1);
        long long power = n - 1;
        while (power > 0) {
            if (power & 1)
                result = multiplyVector(result, T);

            T = multiplyMatrix(T, T);
            power/=2;
        }
        long long answer = 0;
        for (long long x : result)
            answer = (answer + x) % MOD;

        return answer;
    }
};