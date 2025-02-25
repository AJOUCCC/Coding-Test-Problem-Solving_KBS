#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	std::cin >> T;
	int pentagon[5] = { 1,1,1,2,2 };

	int N;
	int* maxPtr;
	int maxIndex;

	int result[101];
	result[0] = 1;
	result[1] = 1;
	result[2] = 1;
	result[3] = 2;


	int idx = 4;
	for (int i = 0; i < 96; i++) {
		maxPtr = max_element(pentagon, pentagon + 5);
		maxIndex = maxPtr - pentagon;
		result[idx++] = *maxPtr;
		if (pentagon[(maxIndex + 1) % 5] > pentagon[(maxIndex + 4) % 5]) {
			pentagon[(maxIndex + 4) % 5] += *maxPtr;
		} else {
			pentagon[(maxIndex + 1) % 5] += *maxPtr;
		}
	}

	//for (int i = 0; i < 100; i++) {
	//	cout << result[i] << " : " << i << "\n";
	//}

	while (T--) {
		std::cin >> N;
		cout << result[N - 1] << "\n";
	}
	return 0;
}