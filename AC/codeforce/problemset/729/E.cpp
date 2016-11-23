#include <cstdio>

const int NMAX = 200000;
int count[NMAX];

int main(void) {
	int n, m;
	int v;
	int ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i < m; ++i) {
		scanf("%d", &v);
		++count[v];
	}
	scanf("%d", &v);
	if (0 != v)
		++ans;
	for (int i = m; i < n; ++i) {
		scanf("%d", &v);
		++count[v];
	}
	int fre = count[0];
	ans += fre;
	int p = n - 1;
	count[0] = 1;
	while (!count[p])
		--p;
	for (int i = 1; i < p; ++i) {
		if (!count[i]) {
			count[i] = 1;
			if (fre)
				--fre;
			else {
				++ans;
				--count[p];
				if (!count[p]) {
					while ((i < p) && !count[p])
						--p;
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
	
