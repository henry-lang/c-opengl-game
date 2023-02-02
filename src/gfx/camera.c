#include "camera.h"

Camera camera_init(Vec2 min, Vec2 max, f32 depth) {
	return (Camera) {
		.min = min,
		.max = max,
		.depth = depth
	};
}

Mat4 camera_proj(Camera *self) {
	return mat4_ortho(self->min.x, self->max.x, self->min.y, self->max.y, 0, self->depth);
}