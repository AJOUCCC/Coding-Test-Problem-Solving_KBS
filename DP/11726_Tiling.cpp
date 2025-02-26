#include <iostream>
#include <iomanip>

using namespace std;

long long combination(int n, int k) {
	long long result = 1;
	for (int i = 0; i < k; i++) {
		result *= n - i;
		result /= i + 1;
	}
	cout << n << "C" << k << " = " << result << "\n";
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	long long result = 0;

	for (int i = 0; N - i*2 >= 0; i++) {
		result += combination((N - i * 2) + i, i);
	}

	cout << fixed << setprecision(0);
	cout << result%10007;
	return 0;
}