#ifndef TYPE_HEADER_H
#define TYPE_HEADER_H

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#define MATRIX_4X4_LINEAR 16U
#define FLOAT_EXP_MASK 0x7F800000U

#define TWO_OVER_PI 0x1.45f306p-1f
#define PI_OVER_TWO 0x1.921fb6p+0f

#define QUAD_FIRST 0x00U
#define QUAD_SECOND 0x01U
#define QUAD_THIRD (QUAD_SECOND << 1)
#define QUAD_FOURTH (QUAD_SECOND | QUAD_THIRD)

#ifdef __STDC_VERSION__

#if (__STDC_VERSION__ >= 201112L)

#define CHECK_TYPE(control_expression)                                         \
  _Generic((control_expression),                                               \
      int: "integer",                                                          \
      float: "float",                                                          \
      char: "character",                                                       \
      int *: "pointer to int",                                                 \
      char *: "pointer to char",                                               \
      float *: "pointer to float",                                             \
      default: "others")

#endif

#endif

#if FLT_RADIX == 2 && FLT_MANT_DIG == 24 && FLT_MAX_EXP == 128
#define FLOAT_IEEE754_BINARY32 1
#else
#define FLOAT_IEEE754_BINARY32 0
#endif

#define MATRIX_MXN_DECLARATION(ROWS, COLOUMNS, _NAME)                          \
  typedef union _NAME##ROWS##x##COLOUMNS {                                     \
    float matrix_linear[(ROWS) * (COLOUMNS)];                                  \
    struct {                                                                   \
      float matrix_2darr[(ROWS)][(COLOUMNS)];                                  \
    } mat;                                                                     \
  } _NAME##ROWS##x##COLOUMNS

#define VEC2_DECLARATION(_NAME)                                                \
  typedef union _NAME {                                                        \
    float coordinates[2];                                                      \
    struct vec2 {                                                              \
      float x_cordinate;                                                       \
      float y_cordinate;                                                       \
    } components;                                                              \
  } VEC2

#define VEC3_DECLARATION(_NAME)                                                \
  typedef union _NAME {                                                        \
    float coordinate[3];                                                       \
    struct vec3 {                                                              \
      float x_cordinate;                                                       \
      float y_cordinate;                                                       \
      float z_cordinate;                                                       \
    } components;                                                              \
  } VEC3

VEC2_DECLARATION(VEC2);
VEC3_DECLARATION(VEC3);

#if FLOAT_IEEE754_BINARY32

typedef union Flour_bits {
  float f;
  uint32_t u;
} fbit;

extern size_t scaler_multiply_v3_binary32(VEC3 *vec, const float scaler);
extern size_t scaler_multiply_v2_binary32(VEC2 *vec, const float scaler);
#endif

extern size_t scaler_multiply_v3(VEC3 *vec, const float scaler);
extern size_t scaler_multiply_v2(VEC2 *vec, const float scaler);

extern VEC3 vec3_addition(VEC3 Augend, VEC3 Addend);
extern VEC3 vec3_subtraction(VEC3 Minuend, VEC3 Subtraend);
extern VEC2 vec2_addition(VEC2 Augend, VEC2 Addend);
extern VEC2 vec2_subtraction(VEC2 Minuend, VEC2 Suntraned);
static int Round(const float value);
/*
 * Its a implementation of Taylor series
 * for calculating transcendental function
 * over small domain ,to achive polynomial
 * approximation the large domain follow
 * the reduction algorithm however its just
 * be floor and ceil value for some x the
 * rounding function doesnt gurantee about
 * overflow detection therefore use the
 * c standerd function for better portability
 * Dont use for large calulation
 */

extern float Sine(const float radians);
extern float Cos(const float radians);

#endif
