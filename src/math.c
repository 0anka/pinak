#include "../include/type.h"

extern int32_t scaler_multiply_v3(VEC3 *vec, const float scaler) {

  fbit conversion = {.f = scaler};

  if (!vec) {
    return -1;
  }
  if ((conversion.u & FLOAT_EXP_MASK) == FLOAT_EXP_MASK) {
    return -1;
  }
  vec->components.x_cordinate *= scaler;
  vec->components.y_cordinate *= scaler;
  vec->components.z_cordinate *= scaler;
  return 0;
}

extern int32_t scaler_multiply_v2(VEC2 *vec, const float scaler) {

  fbit conversion = {.f = scaler};

  if (!vec) {
    return -1;
  }
  if ((conversion.u & FLOAT_EXP_MASK) == FLOAT_EXP_MASK) {
    return -1;
  }
  vec->components.x_cordinate *= scaler;
  vec->components.y_cordinate *= scaler;
  return 0;
}
