#pragma once

#include "vec2.h"
#include "../types.h"

typedef union IVec2 {
	struct {
		i32 x;
		i32 y;
	};

	i32 c[2];
} IVec2;

IVec2 ivec2(i32, i32);
IVec2 ivec2_from_vec2(Vec2);
IVec2 ivec2_add(IVec2, IVec2);
IVec2 ivec2_sub(IVec2, IVec2);
IVec2 ivec2_scale(IVec2, i32);
bool ivec2_eq(IVec2, IVec2);