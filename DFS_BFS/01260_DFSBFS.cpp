#include <iostream>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

unordered_map<int, vector<int>> graph;
unordered_map<int, bool> visited;

void DFS(int V) {
	stack<int> stack;
	stack.push(V);
	

	while (!stack.empty()) {
		int now = stack.top();
		stack.pop();

		if (visited[now])
			continue;
		visited[now] = true;
		cout << now << " ";

		// 인접 노드를 스택에 추가 (작은 번호 먼저 탐색하기 위해 역순으로 추가)
		for (auto it = graph[now].rbegin(); it != graph[now].rend(); ++it) {	
			if (!visited[*it]) {
				stack.push(*it);
			}
		}
	}
}

void BFS(int V) {
	queue<int> queue;
	queue.push(V);
	visited[V] = true;

	while (!queue.empty()) {
		int now = queue.front();
		cout << now << " ";
		queue.pop();

		for (int neighbor : graph[now]) {
			if (!visited[neighbor]) {
				queue.push(neighbor);
				visited[neighbor] = true;
			}
		}
	}
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 정점 번호가 작은 것부터 방문하도록 정렬
	for (auto& [key, neighbors] : graph) {
		sort(neighbors.begin(), neighbors.end());
	}

	/*
	*	[입력 예시]			[저장된 그래프 값]	
			1 2			graph = {
			1 3				{1, {2, 3, 4}},
			1 4				{2, {1, 4}},
			2 4				{3, {1, 4}},
			3 4				{4, {1, 2, 3}}
						};
	*/
	DFS(V);
	cout << endl;

	// visited 초기화 해주어야 한다
	visited.clear(); 
	BFS(V);
	return 0;
}