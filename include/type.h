#ifndef TYPE_HEADER_H
#define TYPE_HEADER_H

#include <stdint.h>

#define MATRIX_4X4_LINEAR 16U
#define FLOAT_EXP_MASK 0x7F800000U
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
_Static_assert(sizeof(float) == 4, "Failed required 32-bit float width size");
_Static_assert(sizeof(uint32_t) == 4, "Failed required  32-bit uint32_t");

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

/* Assuming IEEE 754 FPU */

typedef union Flour_bits {
  float f;
  uint32_t u;
} fbit;

extern int32_t scaler_multiply_v3(VEC3 *vec, const float scaler);
extern int32_t scaler_multiply_v2(VEC2 *vec, const float scaler);

#endif
