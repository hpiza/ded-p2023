#include "Vec3.h"
#include <stdio.h>

int main15() {
	Vec3 v1 = vec3_create(5, 1, 2);
	printf("v1 = <%.1f, %.1f, %.1f>\n", vec3_getX(v1), vec3_getY(v1), vec3_getZ(v1));
	vec3_setX(v1, 4);
	vec3_println(v1);
	printf("Magnitud = %.1f\n", vec3_magnitude(v1));

	Vec3 v2 = vec3_create(6, -2, -1);
	vec3_println(v2);
	printf("dot(v1, v2) = %.1f\n", vec3_dot(v1, v2));

	Vec3 v3 = vec3_normalize(v1);
	vec3_println(v3);

	Vec3 v4 = vec3_clone(v3);
	vec3_println(v4);

	if(vec3_equals(v1, v3)) printf("v1 y v3 son iguales\n"); else printf("v1 y v3 son diferentes\n");
	if(vec3_equals(v3, v4)) printf("v3 y v4 son iguales\n"); else printf("v3 y v4 son diferentes\n");

	printf("%p, %p, %p, %p\n", v1, v2, v3, v4);

	vec3_destroy(v1);
	vec3_destroy(v2);
	vec3_destroy(v3);
  vec3_destroy(v4);
	return 0;
}

