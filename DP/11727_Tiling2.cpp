#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10007;

long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    // dp[i][k] = iĭ�� ä��� ��, 2ĭ ������ k�� ����� ����� ��
    static long long dp[1001][501];
    // �޸�: �뷫 1001*501 = 501501 ���� => 2MB ����, ����� ����

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= i / 2; k++) {
            // 1ĭ ����(O)�� i�� ������� -> (i-1)ĭ + 2ĭ ���� k��
            if (i - 1 >= 0) {
                dp[i][k] = (dp[i][k] + dp[i - 1][k]) % MOD;
            }
            // 2ĭ ����(X)�� i�� ������� -> (i-2)ĭ + 2ĭ ���� (k-1)��
            if (i - 2 >= 0 && k - 1 >= 0) {
                dp[i][k] = (dp[i][k] + dp[i - 2][k - 1]) % MOD;
            }
        }
    }

    // ���� ���: sum_{k} [ dp[n][k] * 2^k ] % MOD
    long long answer = 0;
    for (int k = 0; k <= n / 2; k++) {
        long long ways = dp[n][k];          // ����� ��
        long long mul = power_mod(2, k, MOD); // 2^k
        answer = (answer + (ways * mul) % MOD) % MOD;
    }

    cout << answer << endl;
    return 0;
}