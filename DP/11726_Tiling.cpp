/*
	"1) 조합을 이용한 피보나치 수열의 해석 (Binomial Fibonacci Identity)"
	-> 특정 유형의 조합은 피보나치 수열을 생성한다!!

	F(n) = sigma[ n-k C k ] (k는 0 ~ (n-1)/2 까지) >>> F(n) = F(n-1) + F(n-2)
		* n - 1 - k는 1칸을 차지하는 타일의 개수
		* k는 2칸을 차지하는 타일의 개수
	
	[일반화로 확장 가능 -> a칸 점프와 b칸 점프로 n만큼 이동하기]
		* 결국 axk + bxm = n의 식으로 생각 가능하고, 이는 k+m C k 의 조합 형태로 생각 가능
        * F(n) = F(n-a) + F(n-b)
	
    "2) 모듈러 연산의 특징"
    (a×b) mod m=[(a mod m)×(b mod m)] mod m

*/
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10007;
const int MAX_N = 1000; // 최대 n 값

vector<long long> fact(MAX_N + 1), ifact(MAX_N + 1);

// 빠른 거듭제곱 (페르마의 소정리 이용)
long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// 전처리: 팩토리얼과 역팩토리얼 미리 계산
void precompute_factorials(int n, int mod) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    ifact[n] = power_mod(fact[n], mod - 2, mod); // (n!)^(p-2) % p (페르마의 소정리)

    for (int i = n - 1; i >= 0; i--) {
        ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
    }
}

// 조합 nCk % p 계산
long long Combination(int n, int k, int mod) {
    if (k > n || k < 0) return 0;
    return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

// a칸, b칸 점프 문제 해결
long long generalized_jump(int n, int a, int b, int mod) {
    long long totalWays = 0;

    for (int k = 0; k * a <= n; k++) { // k번 a칸 점프하는 경우
        int remaining = n - k * a;
        if (remaining % b == 0) {  // b칸 점프 가능해야 함
            int m = remaining / b;
            totalWays = (totalWays + Combination(k + m, k, mod)) % mod;
        }
    }

    return totalWays;
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    precompute_factorials(N, MOD); // 사전 계산

    cout << generalized_jump(N, 1, 2, MOD) << endl;

    return 0;
}