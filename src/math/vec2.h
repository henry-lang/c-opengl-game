#pragma once

#include "../types.h"

typedef union Vec2 {
	struct {
		f32 x;
		f32 y;
	};

	f32 c[2];
} Vec2;

Vec2 vec2(f32, f32);
Vec2 vec2_add(Vec2, Vec2);
Vec2 vec2_sub(Vec2, Vec2);
Vec2 vec2_scale(Vec2, f32);
Vec2 vec2_inverse(Vec2);
Vec2 vec2_normalize(Vec2);
f32 vec2_dot(Vec2, Vec2);
f32 vec2_mag(Vec2);
f32 vec2_dist(Vec2, Vec2);
bool vec2_eq(Vec2, Vec2);