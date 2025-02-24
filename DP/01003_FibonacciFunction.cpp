#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    // DP �迭: dp[n][0]�� fibonacci(n) ȣ�� �� 0�� ��µǴ� Ƚ��, dp[n][1]�� 1�� ��µǴ� Ƚ��
    // 41���� �����ؾ� 40���� ��� ������ (0���� 40���� �� 41���̱� ������)
    static int dp[41][2];

    // �ʱⰪ ����
    dp[0][0] = 1; dp[0][1] = 0; // fibonacci(0)
    dp[1][0] = 0; dp[1][1] = 1; // fibonacci(1)

    // �ݺ����� ���� DP ��� (�޸������̼�)
    for (int i = 2; i <= 40; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }

    while (T--) {
        int N;
        cin >> N;
        cout << dp[N][0] << " " << dp[N][1] << "\n";
    }
    return 0;
}
