#include <math.h>

#include "../types.h"
#include "vec2.h"

Vec2 vec2(f32 x, f32 y) {
	return (Vec2) {{x, y}};
}

Vec2 vec2_add(Vec2 a, Vec2 b) {
	return vec2(a.x + b.x, a.y + b.y);
}

Vec2 vec2_sub(Vec2 a, Vec2 b) {
	return vec2(a.x - b.x, a.y - b.y);
}

Vec2 vec2_scale(Vec2 v, f32 scale) {
	return vec2(v.x * scale, v.y * scale);
}

Vec2 vec2_inverse(Vec2 v) {
	return vec2(-v.x, -v.y);
}

Vec2 vec2_normalize(Vec2 v) {
	f32 mag = vec2_mag(v);

	return vec2(v.x / mag, v.y / mag);
}

f32 vec2_dot(Vec2 a, Vec2 b) {
	return a.x * b.x + a.y * b.y;
}

f32 vec2_mag(Vec2 v) {
	return sqrtf(v.x * v.x + v.y * v.y);
}

f32 vec2_dist(Vec2 a, Vec2 b) {
	f32 dist_x = a.x - b.x;
	f32 dist_y = a.y - b.y;

	return sqrtf(dist_x * dist_x - dist_y * dist_y);
}

bool vec2_eq(Vec2 a, Vec2 b) {
	return a.x == b.x && a.y == b.y;
}