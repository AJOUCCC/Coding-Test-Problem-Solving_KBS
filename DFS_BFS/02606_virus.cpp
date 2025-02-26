#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

unordered_map <int, vector<int>> graph;
unordered_map <int, bool> visited;

int BFS(int v) {
	int count = 0;
	queue<int> queue;
	queue.push(v);
	visited[v] = true;

	while (!queue.empty()) {
		int now = queue.front();
		queue.pop();
		cout << now << " ";

		for (int neighbor : graph[now]) {
			if (!visited[neighbor]) {
				queue.push(neighbor);
				visited[neighbor] = true;
				count++;
			}
		}
	}
	return count;
}

int main() {
	int N, t;
	cin >> N;
	cin >> t;
	while (t--) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 0; i <= 100; i++) {
		visited[i] = false;
	}

	int count = BFS(1);

	cout << count;

	return 0;
}