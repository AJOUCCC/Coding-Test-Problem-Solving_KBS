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

    // dp[i][k] = i칸을 채우는 데, 2칸 점프를 k번 사용한 경우의 수
    static long long dp[1001][501];
    // 메모리: 대략 1001*501 = 501501 정수 => 2MB 정도, 충분히 가능

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= i / 2; k++) {
            // 1칸 점프(O)로 i를 만들려면 -> (i-1)칸 + 2칸 점프 k번
            if (i - 1 >= 0) {
                dp[i][k] = (dp[i][k] + dp[i - 1][k]) % MOD;
            }
            // 2칸 점프(X)로 i를 만들려면 -> (i-2)칸 + 2칸 점프 (k-1)번
            if (i - 2 >= 0 && k - 1 >= 0) {
                dp[i][k] = (dp[i][k] + dp[i - 2][k - 1]) % MOD;
            }
        }
    }

    // 최종 결과: sum_{k} [ dp[n][k] * 2^k ] % MOD
    long long answer = 0;
    for (int k = 0; k <= n / 2; k++) {
        long long ways = dp[n][k];          // 경우의 수
        long long mul = power_mod(2, k, MOD); // 2^k
        answer = (answer + (ways * mul) % MOD) % MOD;
    }

    cout << answer << endl;
    return 0;
}