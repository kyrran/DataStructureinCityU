#include <iostream>
#include <vector>
using namespace std;

typedef long long int64;

const int Max_N = 100005;

struct vector_t {
	int64 x, y;
	vector_t(int64 _x = 0LL, int64 _y = 0LL) : x(_x), y(_y) {}
	vector_t operator -(const vector_t &rhs) const {
		return vector_t(x - rhs.x, y - rhs.y);
	}
	bool operator <(const vector_t &rhs) const {
		return (x != rhs.x) ? (x < rhs.x) : (y < rhs.y);
	}
};

typedef vector_t point_t;

inline int64 cross(const vector_t &i, const vector_t &j) {
	return i.x * j.y - j.x * i.y;
}

int n, Cases, ans;
point_t P[Max_N];

int main() {
	scanf("%d", &Cases);

	while (Cases--) {
		static int stk[Max_N], stk1[Max_N], stk2[Max_N], top, top1, top2;
		#define CUR stk[top]
		#define PRE stk[top - 1]

		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld%lld", &P[i].x, &P[i].y);
		sort(P + 1, P + 1 + n);

		stk[top = 1] = 1;
		for (int i = 2; i <= n; i++) {
			while (top > 1 && (P[CUR].y - P[PRE].y) * (P[i].x - P[PRE].x) > (P[i].y - P[PRE].y) * (P[CUR].x - P[PRE].x))
				--top;
			stk[++top] = i;
		}
		for (int i = 1; i <= top; i++)
			stk1[i] = stk[i];
		top1 = top;
		stk[top = 1] = 1;
		for (int i = 2; i <= n; i++){
			while (top > 1 && (P[CUR].y - P[PRE].y) * (P[i].x - P[PRE].x) < (P[i].y - P[PRE].y) * (P[CUR].x - P[PRE].x))
				--top;
			stk[++top] = i;
        }
		top2 = top;
		for (int i = 1; i <= top; i++)
			stk2[i] = stk[i];

        printf("%d\n", top1 + top2 - 2);
		for (int i = 1; i <= top1 - 1; i++)
			printf("%lld %lld\n", P[ stk1[i] ].x, P[ stk1[i] ].y);
		for (int i = top2; i > 1; i--)
			printf("%lld %lld\n", P[ stk2[i] ].x, P[ stk2[i] ].y);
    }
	
	return 0;
}