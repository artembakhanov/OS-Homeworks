#include <limits.h>
#include <float.h>
#include <stdio.h>

int main() {
	int i = INT_MAX; // from limits.h 
	float f = FLT_MAX; // from float.h
	double d = DBL_MAX; // from float.h

	printf("int i: size=%d, value=%d\n", sizeof(i), i);
	printf("float f: size=%d, value=%f\n", sizeof(f), f);
	printf("double d: size=%d, value=%lf\n", sizeof(d), d);	

	return 0;
}