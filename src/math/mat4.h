#pragma once

#include "../types.h"

typedef union Mat4 {
	f32 c[16];
} Mat4;

Mat4 mat4_ortho(f32, f32, f32, f32, f32, f32);