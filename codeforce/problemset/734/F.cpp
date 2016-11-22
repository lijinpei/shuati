#include <cstdio>

#define ERROR printf("-1\n");return 0;
const int NMAX = 200000;
int B[NMAX], C[NMAX], D[NMAX];
int A[NMAX];

bool bits[NMAX][31];
int tot_bits[31];

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", B + i);
	for (int i = 0; i < n; ++i)
		scanf("%d", C + i);
	for (int i = 0; i < n; ++i)
		D[i] = B[i] + C[i];
	long long s = 0;
	for (int i = 0; i < n; ++i)
		s += D[i];
	if (0 != s % (n + n)) {
		ERROR
	}
	s = s / (n + n);

	for (int i = 0; i < n; ++i) {
		if (0 != (D[i] - s) % n) {
			ERROR
		}
		A[i] = (D[i] - s) / n;
	}
	for (int i = 0; i < n; ++i) {
		if (A[i] < 0) {
			ERROR
		}
		for (int j = 0; j < 31; ++j) {
			bits[i][j] = A[i] & (1 << j);
		}
	}
	for (int i = 0; i < 31; ++i) {
		for (int j = 0; j < n; ++j)
			tot_bits[i] += (bits[j][i] ? 1 : 0);
	}
	for (int i = 0; i < n; ++i) {
		int b = 0, c = 0;
		for (int j = 0; j < 31; ++j) {
			int tmp_b = bits[i][j] ? tot_bits[j] : 0;
			int tmp_c = bits[i][j] ? n : tot_bits[j];
			b += tmp_b * (1 << j);
			c += tmp_c * (1 << j);
		}
		if ((B[i] != b) || (C[i] != c)) {
			ERROR
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", A[i]);
}
