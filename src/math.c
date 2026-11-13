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

extern VEC3 vec3_addition(VEC3 Augend, VEC3 Addend) {

  Augend.components.x_cordinate += Addend.components.x_cordinate;
  Augend.components.y_cordinate += Addend.components.y_cordinate;
  Augend.components.z_cordinate += Addend.components.z_cordinate;

  return Augend;
}

extern VEC3 vec3_subtraction(VEC3 Minuend, VEC3 Subtrahend) {

  Minuend.components.x_cordinate -= Subtrahend.components.x_cordinate;
  Minuend.components.y_cordinate -= Subtrahend.components.y_cordinate;
  Minuend.components.z_cordinate -= Subtrahend.components.z_cordinate;
  return Minuend;
}
extern VEC2 vec2_addition(VEC2 Augend, VEC2 Addend) {

  Augend.components.x_cordinate += Addend.components.x_cordinate;
  Augend.components.y_cordinate += Addend.components.y_cordinate;
  return Augend;
}

extern VEC2 vec2_subtraction(VEC2 Minuend, VEC2 Subtrahend) {

  Minuend.components.x_cordinate -= Subtrahend.components.x_cordinate;
  Minuend.components.y_cordinate -= Subtrahend.components.y_cordinate;
  return Minuend;
}
