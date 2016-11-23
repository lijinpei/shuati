#include <cstdio>
#include <cstring>
#include <cstdlib>

const int NMAX = 200000;
int edge[NMAX][2]	;
int edge_count[NMAX + 2];
int edge_adjacent[NMAX + NMAX + 1];
int queue[NMAX + 1];
int flag[NMAX + 1];
int color[NMAX + 1];
int count[NMAX + 1];

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", color + i);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		edge[i][0] = u;
		edge[i][1] = v;
		edge_count[u] += 1;
		edge_count[v] += 1;
	}
	for (int i = 2; i <= n; ++i) {
		edge_count[i] += edge_count[i - 1];
	}
	edge_count[n + 1] = edge_count[n];
	for (int i = 0; i < n - 1; ++i) {
		edge_adjacent[--edge_count[edge[i][0]]] = edge[i][1];
		edge_adjacent[--edge_count[edge[i][1]]] = edge[i][0];
	}
	
	queue[0] = 1;
	flag[1] = 1;
	int j = 1;
	for (int i = 0;i < j; ++i) {
		int p = queue[i];
		for (int k = edge_count[p]; k < edge_count[p + 1]; ++k) {
			int q = edge_adjacent[k];
			if (0 == flag[q]) {
				flag[q] = 1;
				queue[j++] = q;
			}
		}
	}

	int ans = 0;
	memset(flag, 0, sizeof(flag));
	for (int i = n - 1; i >= 0; --i) {
		int p = queue[i];
		int c1 = 0;
		int c2 = 0;
		for (int k = edge_count[p]; k < edge_count[p + 1]; ++k) {
			int q = edge_adjacent[k];
			if (1 != flag[q])
				continue;
			int c;
			if (color[q] == color[p])
				c = count[q] - 1;
			else
				c = count[q];
			if (c > c1) {
				c2 = c1;
				c1 = c;
			} else if (c > c2)
				c2 = c;
		}
		flag[p] = 1;
		count[p] = c1 + 1;
		if (c1 + c2 + 1 > ans)
			ans = c1 + c2 + 1;
	}

	printf("%d\n", ans >> 1);
	
	return 0;
}