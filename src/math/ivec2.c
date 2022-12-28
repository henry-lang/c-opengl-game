#include "../types.h"

#include "vec2.h"
#include "ivec2.h"

IVec2 ivec2(i32 x, i32 y) {
	return (IVec2) {{x, y}};
}

IVec2 ivec2_from_vec2(Vec2 v) {
	return ivec2((i32) v.x, (i32) v.y);
}

IVec2 ivec2_add(IVec2 a, IVec2 b) {
	return ivec2(a.x + b.x, a.y + b.y);
}

IVec2 ivec2_sub(IVec2 a, IVec2 b) {
	return ivec2(a.x - b.x, a.y - b.y);
}

IVec2 ivec2_scale(IVec2 v, i32 scale) {
	return ivec2(v.x * scale, v.y * scale);
}

bool ivec2_eq(IVec2 a, IVec2 b) {
	return a.x == b.x && b.x == b.y;
}