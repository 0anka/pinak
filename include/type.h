#ifndef __TYPE_HEADER__H
#define __TYPE_HEADER__H

#define MATRIX_4X4_LINEAR 16U

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

#endif
