#include "../include/type.h"

#if FLOAT_IEEE754_BINARY32
extern size_t scaler_multiply_v3_binary32(VEC3 *vec, const float scaler) {

  fbit conversion = {.f = scaler};

  if (!vec) {
    return 1;
  }
  if ((conversion.u & FLOAT_EXP_MASK) == FLOAT_EXP_MASK) {
    return 1;
  }

  if ((((fbit){.f = vec->components.x_cordinate * scaler}).u &
       FLOAT_EXP_MASK) == FLOAT_EXP_MASK ||
      (((fbit){.f = vec->components.y_cordinate * scaler}).u &
       FLOAT_EXP_MASK) == FLOAT_EXP_MASK ||
      (((fbit){.f = vec->components.z_cordinate * scaler}).u &
       FLOAT_EXP_MASK) == FLOAT_EXP_MASK) {
    return 1;
  }

  vec->components.x_cordinate *= scaler;
  vec->components.y_cordinate *= scaler;
  vec->components.z_cordinate *= scaler;
  return 0;
}

extern size_t scaler_multiply_v2_binary32(VEC2 *vec, const float scaler) {

  fbit conversion = {.f = scaler};

  if (!vec) {
    return 1;
  }
  if ((conversion.u & FLOAT_EXP_MASK) == FLOAT_EXP_MASK) {
    return 1;
  }

  if ((((fbit){.f = vec->components.x_cordinate * scaler}).u &
       FLOAT_EXP_MASK) == FLOAT_EXP_MASK ||
      (((fbit){.f = vec->components.y_cordinate * scaler}).u &
       FLOAT_EXP_MASK) == FLOAT_EXP_MASK) {
    return 1;
  }

  vec->components.x_cordinate *= scaler;
  vec->components.y_cordinate *= scaler;
  return 0;
}
#endif

extern size_t scaler_multiply_v3(VEC3 *vec, const float scaler) {
  if (!vec || !isfinite(scaler)) {
    return 1;
  }
  if (!isfinite(vec->components.x_cordinate * scaler) ||
      !isfinite(vec->components.y_cordinate * scaler) ||
      !isfinite(vec->components.z_cordinate * scaler)) {
    return 1;
  }

  vec->components.x_cordinate *= scaler;
  vec->components.y_cordinate *= scaler;
  vec->components.z_cordinate *= scaler;

  return 0;
}

extern size_t scaler_multiply_v2(VEC2 *vec, const float scaler) {
  if (!vec || !isfinite(scaler)) {
    return 1;
  }
  if (!isfinite(vec->components.x_cordinate * scaler) ||
      !isfinite(vec->components.y_cordinate * scaler)) {
    return 1;
  }

  vec->components.x_cordinate *= scaler;
  vec->components.y_cordinate *= scaler;

  return 0;
}

extern VEC3 vec3_addition(VEC3 Augend, VEC3 Addend) {

  if (!isfinite(Augend.components.x_cordinate) ||
      !isfinite(Augend.components.y_cordinate) ||
      !isfinite(Augend.components.z_cordinate) ||
      !isfinite(Addend.components.x_cordinate) ||
      !isfinite(Addend.components.y_cordinate) ||
      !isfinite(Addend.components.z_cordinate)) {
    return (VEC3){0};
  }
  if (!isfinite(Augend.components.x_cordinate +
                Addend.components.x_cordinate) ||
      !isfinite(Augend.components.y_cordinate +
                Addend.components.y_cordinate) ||
      !isfinite(Augend.components.z_cordinate +
                Addend.components.z_cordinate)) {
    return (VEC3){0};
  }

  Augend.components.x_cordinate += Addend.components.x_cordinate;
  Augend.components.y_cordinate += Addend.components.y_cordinate;
  Augend.components.z_cordinate += Addend.components.z_cordinate;

  return Augend;
}

extern VEC3 vec3_subtraction(VEC3 Minuend, VEC3 Subtrahend) {
  if (!isfinite(Minuend.components.x_cordinate) ||
      !isfinite(Minuend.components.y_cordinate) ||
      !isfinite(Minuend.components.z_cordinate) ||
      !isfinite(Subtrahend.components.x_cordinate) ||
      !isfinite(Subtrahend.components.y_cordinate) ||
      !isfinite(Subtrahend.components.z_cordinate)) {
    return (VEC3){0};
  }

  if (!isfinite(Minuend.components.x_cordinate -
                Subtrahend.components.x_cordinate) ||
      !isfinite(Minuend.components.y_cordinate -
                Subtrahend.components.y_cordinate) ||
      !isfinite(Minuend.components.z_cordinate -
                Subtrahend.components.z_cordinate)) {
    return (VEC3){0};
  }

  Minuend.components.x_cordinate -= Subtrahend.components.x_cordinate;
  Minuend.components.y_cordinate -= Subtrahend.components.y_cordinate;
  Minuend.components.z_cordinate -= Subtrahend.components.z_cordinate;
  return Minuend;
}
extern VEC2 vec2_addition(VEC2 Augend, VEC2 Addend) {

  if (!isfinite(Augend.components.x_cordinate) ||
      !isfinite(Augend.components.y_cordinate) ||
      !isfinite(Addend.components.x_cordinate) ||
      !isfinite(Addend.components.y_cordinate)) {
    return (VEC2){0};
  }

  if (!isfinite(Augend.components.x_cordinate +
                Addend.components.x_cordinate) ||
      !isfinite(Augend.components.y_cordinate +
                Addend.components.y_cordinate)) {
    return (VEC2){0};
  }

  Augend.components.x_cordinate += Addend.components.x_cordinate;
  Augend.components.y_cordinate += Addend.components.y_cordinate;
  return Augend;
}

extern VEC2 vec2_subtraction(VEC2 Minuend, VEC2 Subtrahend) {

  if (!isfinite(Minuend.components.x_cordinate) ||
      !isfinite(Minuend.components.y_cordinate) ||
      !isfinite(Subtrahend.components.x_cordinate) ||
      !isfinite(Subtrahend.components.y_cordinate)) {
    return (VEC2){0};
  }

  if (!isfinite(Minuend.components.x_cordinate -
                Subtrahend.components.x_cordinate) ||
      !isfinite(Minuend.components.y_cordinate -
                Subtrahend.components.y_cordinate)) {
    return (VEC2){0};
  }

  Minuend.components.x_cordinate -= Subtrahend.components.x_cordinate;
  Minuend.components.y_cordinate -= Subtrahend.components.y_cordinate;
  return Minuend;
}
static int Round(const float value) {
  if (!isfinite(value) || value > (float)INT_MAX || value < (float)INT_MIN) {
    return 0;
  }
  float absolute = fabsf(value);
  int intpart = (int)absolute;
  if (absolute - (float)intpart >= 0.5f) {
    ++intpart;
  }
  return value < 0.f ? -intpart : intpart;
}

extern float Sine(const float radians) {
  int truncate = Round(radians * TWO_OVER_PI);
  float interval = radians - (float)truncate * PI_OVER_TWO;
  float sine_quadrent =
      interval *
      (1.0f + (interval * interval) *
                  ((-1.0f / 6.0f +
                    (interval * interval) *
                        ((1.0f / 120.0f +
                          (interval * interval) *
                              (-1.0f / 5040.0f +
                               (interval * interval) * (1.0f / 362880.0f)))))));
  float cosine_quadrent =
      1.0f +
      (interval * interval) *
          (-1.0f / 2.0f +
           (interval * interval) *
               (1.0f / 24.0f + (interval * interval) *
                                   (-1.0f / 720.0f + (interval * interval) *
                                                         (1.0f / 40320.0f))));

  switch (truncate % 4 < 0 ? truncate % 4 + 4 : truncate % 4) {
  case QUAD_FIRST:
    return sine_quadrent;
  case QUAD_SECOND:
    return cosine_quadrent;
  case QUAD_THIRD:
    return -sine_quadrent;
  case QUAD_FOURTH:
    return -cosine_quadrent;
  }
  return 0.0f;
}

extern float Cos(const float radians) {
  int truncate = Round(radians * TWO_OVER_PI);
  float interval = radians - (float)truncate * PI_OVER_TWO;
  float sine_quadrent =
      interval *
      (1.0f + (interval * interval) *
                  ((-1.0f / 6.0f +
                    (interval * interval) *
                        ((1.0f / 120.0f +
                          (interval * interval) *
                              (-1.0f / 5040.0f +
                               (interval * interval) * (1.0f / 362880.0f)))))));
  float cosine_quadrent =
      1.0f +
      (interval * interval) *
          (-1.0f / 2.0f +
           (interval * interval) *
               (1.0f / 24.0f + (interval * interval) *
                                   (-1.0f / 720.0f + (interval * interval) *
                                                         (1.0f / 40320.0f))));

  switch (truncate % 4 < 0 ? truncate % 4 + 4 : truncate % 4) {
  case QUAD_FIRST:
    return cosine_quadrent;
  case QUAD_SECOND:
    return -sine_quadrent;
  case QUAD_THIRD:
    return -cosine_quadrent;
  case QUAD_FOURTH:
    return sine_quadrent;
  }
  return 0.0f;
}

extern float vec3_magnitude(const VEC3 *vec3) {
  if (!vec3) {
    return NAN;
  }

  if (!isfinite(vec3->components.x_cordinate) ||
      !isfinite(vec3->components.y_cordinate) ||
      !isfinite(vec3->components.z_cordinate)) {
    return NAN;
  }

  return hypotf(
      hypotf(vec3->components.x_cordinate, vec3->components.y_cordinate),
      vec3->components.z_cordinate);
}

extern float vec2_magnitude(const VEC2 *vec2) {
  if (!vec2) {
    return NAN;
  }

  if (!isfinite(vec2->components.x_cordinate) ||
      !isfinite(vec2->components.y_cordinate)) {

    return NAN;
  }

  return hypotf(vec2->components.x_cordinate, vec2->components.y_cordinate);
}

extern float vec3_Dot_Product(VEC3 vec1, VEC3 vec2) {
  float add;
  vec1.components.x_cordinate *= vec2.components.x_cordinate;
  vec1.components.y_cordinate *= vec2.components.y_cordinate;
  vec1.components.z_cordinate *= vec2.components.z_cordinate;

  if (!isfinite(vec1.components.x_cordinate) ||
      !isfinite(vec1.components.y_cordinate) ||
      !isfinite(vec1.components.z_cordinate)) {
    return NAN;
  }
  add = vec1.components.x_cordinate + vec1.components.y_cordinate +
        vec1.components.z_cordinate;
  if (!isfinite(add)) {
    return NAN;
  }

  return add;
}
extern float vec2_Dot_Product(VEC2 vec1, VEC2 vec2) {
  float add;
  vec1.components.x_cordinate *= vec2.components.x_cordinate;
  vec1.components.y_cordinate *= vec2.components.y_cordinate;
  if (!isfinite(vec1.components.x_cordinate) ||
      !isfinite(vec1.components.y_cordinate)) {

    return NAN;
  }

  add = vec1.components.x_cordinate + vec1.components.y_cordinate;

  return add;
}

extern VEC3 vec3_cross_Product(VEC3 vec1, VEC3 vec2) {
  VEC3 product = {0};
  VEC3 sproduct = {0};

  product.components.x_cordinate =
      vec1.components.y_cordinate * vec2.components.z_cordinate;
  product.components.y_cordinate =
      vec1.components.z_cordinate * vec2.components.x_cordinate;
  product.components.z_cordinate =
      vec1.components.x_cordinate * vec2.components.y_cordinate;

  if (!isfinite(product.components.x_cordinate) ||
      !isfinite(product.components.y_cordinate) ||
      !isfinite(product.components.z_cordinate)) {
    return (VEC3){0};
  }

  sproduct.components.x_cordinate =
      vec1.components.z_cordinate * vec2.components.y_cordinate;
  sproduct.components.y_cordinate =
      vec1.components.x_cordinate * vec2.components.z_cordinate;
  sproduct.components.z_cordinate =
      vec1.components.y_cordinate * vec2.components.x_cordinate;

  if (!isfinite(sproduct.components.x_cordinate) ||
      !isfinite(sproduct.components.y_cordinate) ||
      !isfinite(sproduct.components.z_cordinate)) {
    return (VEC3){0};
  }

  product.components.x_cordinate -= sproduct.components.x_cordinate;
  product.components.y_cordinate -= sproduct.components.y_cordinate;
  product.components.z_cordinate -= sproduct.components.z_cordinate;

  if (!isfinite(product.components.x_cordinate) ||
      !isfinite(product.components.y_cordinate) ||
      !isfinite(product.components.z_cordinate)) {
    return (VEC3){0};
  }
  return product;
}

extern float vec2_cross_Product(VEC2 vec1, VEC2 vec2) {
  float operand1, operand2;
  operand1 = vec1.components.x_cordinate * vec2.components.y_cordinate;
  operand2 = vec1.components.y_cordinate * vec2.components.x_cordinate;
  if (!isfinite(operand1) || !isfinite(operand2)) {
    return NAN;
  }
  operand1 -= operand2;
  if (!isfinite(operand1)) {
    return NAN;
  }
  return operand1;
}
extern size_t matrice_create(MatriceProperty *create) {
  size_t check;
  if (!create || !create->row || !create->col || create->ops != CREATE) {
    return 1;
  }

  if (create->row > (SIZE_MAX / create->col)) {
    return 1;
  }
  check = create->row * create->col;

  if (check > (SIZE_MAX / sizeof(float))) {
    return 1;
  }

  create->matptr = (float *)malloc(check * sizeof(float));
  if (!create->matptr) {
    return 1;
  }
  return 0;
}

extern size_t Transpose_matrix(MatriceProperty *operation) {
  float *transpose = NULL;
  if (!operation || !operation->matptr || operation->ops != TRANSPOSE) {
    return 1;
  }
  transpose =
      (float *)malloc((operation->row * operation->col) * sizeof(float));
  if (!transpose) {
    return 1;
  }

  for (size_t i = 0; i < operation->row * operation->col; i++) {

    transpose[(i % operation->col) * (operation->row) + (i / operation->col)] =
        operation->matptr[(i / operation->col) * (operation->col) +
                          (i % operation->col)];
  }

  memcpy(operation->matptr, transpose,
         (operation->row * operation->col) * sizeof(float));
  free(transpose);
  return 0;
}
extern size_t scaler_multiplication_matrice(MatriceProperty *scaler,
                                            const float mul) {
  if (!scaler || !scaler->matptr || scaler->ops != SCALER_MULTIPLICATION) {
    return 1;
  }
  for (size_t i = 0; i < (scaler->row * scaler->col); i++) {
    scaler->matptr[i] *= mul;
  }
  return 0;
}
extern size_t Identity_matrix(MatriceProperty *identity) {
  if (!identity || !identity->matptr || identity->col != identity->row ||
      identity->ops != IDENTITY) {
    return 1;
  }
  memset(identity->matptr, 0, (identity->row * identity->col) * sizeof(float));
  for (size_t i = 0; i < (identity->row * identity->col); i++) {
    if ((i / identity->col) == (i % identity->col)) {
      identity->matptr[(i / identity->col) * (identity->col) +
                       (i % identity->col)] = 1;
    }
  }
  return 0;
}


