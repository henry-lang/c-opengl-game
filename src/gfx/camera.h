#pragma once

#include "../math/mat4.h"
#include "../math/vec2.h"

typedef struct Camera {
	Vec2 min;
	Vec2 max;
	f32 depth;
} Camera;

Camera camera_init(Vec2, Vec2, f32);
Mat4 camera_proj(Camera *);
