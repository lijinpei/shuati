#include <cstdio>

const int NMAX = 1000000;
long int ans[NMAX + 1];
char stair[NMAX + 2];

int main(void) {
	int n;
	scanf("%d\n", &n);
	scanf("%s", stair + 1);

	long int lc = 0, rc = 0;
	int p = 0;
	for (int i = 1; i <= n; ++i) {
		if (('U' == stair[i]) || (p >= i)) {
			while (1) {
				++p;
				if ((p > n) ||  ('D' == stair[p]))
					break;
			}
			if (p > n)
				break;
			if ('U' == stair[i]) {
				lc += i;
				rc += p;
			} else {
				rc += p - i;
			}
		} else
			p = i;
		ans[i] = i + 2 * (rc - lc);
	}

	lc = 0;
	rc = 0;
	p = n + 1;
	for (int i = n; i; --i) {
		if (('D' == stair[i]) || (p <= i)) {
			while (1) {
				--p;
				if ((p < 1) || ('U' == stair[p]))
					break;
			}
			if (p < 1)
				break;
			if ('D' == stair[i]) {
				rc += i;
				lc += p;
			} else {
				lc += p - i;
			}
		} else
			p = i;
		ans[i] = (n  + 1 - i) + 2 * (rc - lc);
	}

	for (int i = 1; i <= n; ++i)
		printf("%ld ", ans[i]);

	return 0;
}

