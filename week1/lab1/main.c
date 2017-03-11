#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	printf("%lu, %lu, %lu\n", sizeof(a), sizeof(b), sizeof(c));
	printf("%d, %f, %f\n", a,b ,c);
	return 0;
}
