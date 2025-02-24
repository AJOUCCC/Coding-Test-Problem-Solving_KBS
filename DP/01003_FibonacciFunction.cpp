#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    // DP 배열: dp[n][0]은 fibonacci(n) 호출 시 0이 출력되는 횟수, dp[n][1]은 1이 출력되는 횟수
    // 41까지 선언해야 40까지 계산 가능함 (0부터 40까지 총 41개이기 때문에)
    static int dp[41][2];

    // 초기값 설정
    dp[0][0] = 1; dp[0][1] = 0; // fibonacci(0)
    dp[1][0] = 0; dp[1][1] = 1; // fibonacci(1)

    // 반복문을 통한 DP 계산 (메모이제이션)
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
