#include "mat4.h"
#include "../types.h"

Mat4 mat4_ortho(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far) {
	f32 a = 2.0 / (right - left);
    f32 b = 2.0 / (top - bottom);
    f32 c = -2.0 / (far - near);
    f32 tx = -(right + left) / (right - left);
    f32 ty = -(top + bottom) / (top - bottom);
    f32 tz = -(far + near) / (far - near);

	return (Mat4) {
		.c = {
			a, 0.0f, 0.0f, 0.0f,
			0.0f, b, 0.0f, 0.0f,
			0.0f, 0.0f, c, 0.0f,
			tx, ty, tz, 0.0f
		}
	};
}