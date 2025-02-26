#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

unordered_map<int, vector<int>> graph;
unordered_map<int, bool> visited;

void BFS(int V) {
	queue<int> queue;
	queue.push(V);
	visited[V] = true;
	while (!queue.empty()) {
		auto now = queue.front();
		queue.pop();

		for (auto neighbor : graph[now]) {
			if (!visited[neighbor]) {
				queue.push(neighbor);
				visited[neighbor] = true;
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	int u, v;
	while (M--) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N + 1; i++) {
		visited[i] = false;
	}

	int count = 0;
	int idx = 0;
	int size = N;
	for (int i = 1; i <= size; i++) {
		if (!visited[i]) {
			BFS(i);	// 노드 i부터 BFS를 거치며 지나간 노드들을 visited = true로 바꾸기
			count++;
		}
	}
	cout << count;
	return 0;
}