#include <stdio.h>

int main2() {
	char c = 'A', d = 'B';
	int edad = 23;
	long long millis = 15314738293;
	printf("%p\n", &c);
	printf("%p\n", &d);
	printf("%p\n", &edad);
	printf("%p\n", &millis);

	int *ptrEdad = &edad;
	printf("%p\n", ptrEdad);
	char *ptrD = &d;
	printf("%p\n", ptrD);

	printf("%p\n", &ptrEdad);
	printf("%p\n", &ptrD);
	ptrD = &c;
	printf("%p\n", ptrD);

	long long *ptrL1 = NULL, *ptrL2 = NULL;
	printf("%p, %p\n", ptrL1, ptrL2);

	// edad ++;
	*ptrEdad = 18;
	printf("%d\n", edad);

	*ptrD = 'Z';
	printf("%c\n", c);

	printf("%d, %lu, %lu, %lu, %lu\n", (int) sizeof(int), sizeof(char), sizeof(double), sizeof(long double), sizeof(float));
	printf("%lu, %lu, %lu, %lu, %lu\n", sizeof edad, sizeof millis, sizeof ptrEdad, sizeof ptrD, sizeof(char*));


	ptrD = &c;	// ...B72
	printf("%p, %c\n", ptrD, *ptrD);
	ptrD ++;	// ...B73
	printf("%p, %c\n", ptrD, *ptrD);
	ptrD ++;	// ...B74
	printf("%p, %c\n", ptrD, *ptrD);

	printf("%p, %d\n", ptrEdad, *ptrEdad);
	ptrEdad ++;
	printf("%p, %d\n", ptrEdad, *ptrEdad);

	return 0;

	// 5FF7DF - millis (64b)
	// 5FF7DE -
	// 5FF7DD
	// 5FF7DC
	// 5FF7DB
	// 5FF7DA
	// 5FF7D9 - millis (64b)
	// 5FF7D8 - millis (64b)
	// 5FF7D7 - edad (32b)
	// 5FF7D6 - edad (32b)
	// 5FF7D5 - edad (32b)
	// 5FF7D4 - edad (32b)
	// 5FF7D3 - d (8b)
	// 5FF7D2 - c (8b)

}