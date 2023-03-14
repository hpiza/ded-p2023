#include "Vec3.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct strVec3 {
  float x, y, z;
};

Vec3 vec3_create(float x, float y, float z) {
  Vec3 v = (Vec3)malloc(sizeof(struct strVec3));
  v->x = x;
  v->y = y;
  v->z = z;
  return v;
}

void vec3_destroy(Vec3 v) { free(v); }

// Setters
void vec3_setX(Vec3 v, float x) { v->x = x; }

void vec3_setY(Vec3 v, float y) { v->y = y; }

void vec3_setZ(Vec3 v, float z) { v->z = z; }

// Getters
float vec3_getX(Vec3 v) { return v->x; }

float vec3_getY(Vec3 v) { return v->y; }

float vec3_getZ(Vec3 v) { return v->z; }

float vec3_magnitude(Vec3 v) {
  float mag = sqrt(((v->x) * (v->x)) + ((v->y) * (v->z)) + ((v->z) * (v->z)));
  return mag;
}

Vec3 vec3_normalize(Vec3 v) {
  float m = vec3_magnitude(v);
  return vec3_create(v->x / m, v->y / m, v->z / m);
}

// producto punto de dos vectores
float vec3_dot(Vec3 u, Vec3 v) {
  return (u->x * v->x) + (u->y * v->y) + (u->z * v->z);
}

void vec3_print(Vec3 v) { printf(" <%.1f, %.1f, %.1f>\n", v->x, v->y, v->z); }

void vec3_println(Vec3 v) {
  vec3_print(v);
  printf("\n");
}


Bool vec3_equals(Vec3 u, Vec3 v) {
	return u->x == v->x && u->y == v->y && u->z == v->z;
}

Vec3 vec3_clone(Vec3 v) {
	return vec3_create(v->x, v->y, v->z);
}