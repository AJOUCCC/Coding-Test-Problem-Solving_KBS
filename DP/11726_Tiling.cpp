/*
	"1) ������ �̿��� �Ǻ���ġ ������ �ؼ� (Binomial Fibonacci Identity)"
	-> Ư�� ������ ������ �Ǻ���ġ ������ �����Ѵ�!!

	F(n) = sigma[ n-k C k ] (k�� 0 ~ (n-1)/2 ����) >>> F(n) = F(n-1) + F(n-2)
		* n - 1 - k�� 1ĭ�� �����ϴ� Ÿ���� ����
		* k�� 2ĭ�� �����ϴ� Ÿ���� ����
	
	[�Ϲ�ȭ�� Ȯ�� ���� -> aĭ ������ bĭ ������ n��ŭ �̵��ϱ�]
		* �ᱹ axk + bxm = n�� ������ ���� �����ϰ�, �̴� k+m C k �� ���� ���·� ���� ����
        * F(n) = F(n-a) + F(n-b)
	
    "2) ��ⷯ ������ Ư¡"
    (a��b) mod m=[(a mod m)��(b mod m)] mod m

*/
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10007;
const int MAX_N = 1000; // �ִ� n ��

vector<long long> fact(MAX_N + 1), ifact(MAX_N + 1);

// ���� �ŵ����� (�丣���� ������ �̿�)
long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// ��ó��: ���丮��� �����丮�� �̸� ���
void precompute_factorials(int n, int mod) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    ifact[n] = power_mod(fact[n], mod - 2, mod); // (n!)^(p-2) % p (�丣���� ������)

    for (int i = n - 1; i >= 0; i--) {
        ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
    }
}

// ���� nCk % p ���
long long Combination(int n, int k, int mod) {
    if (k > n || k < 0) return 0;
    return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

// aĭ, bĭ ���� ���� �ذ�
long long generalized_jump(int n, int a, int b, int mod) {
    long long totalWays = 0;

    for (int k = 0; k * a <= n; k++) { // k�� aĭ �����ϴ� ���
        int remaining = n - k * a;
        if (remaining % b == 0) {  // bĭ ���� �����ؾ� ��
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

    precompute_factorials(N, MOD); // ���� ���

    cout << generalized_jump(N, 1, 2, MOD) << endl;

    return 0;
}