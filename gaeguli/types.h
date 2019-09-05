/**
 *  Copyright 2019 SK Telecom, Co., Ltd.
 *    Author: Jeongseok Kim <jeongseok.kim@sk.com>
 *
 */

#ifndef __GAEGULI_TYPES_H__
#define __GAEGULI_TYPES_H__

#if !defined(__GAEGULI_INSIDE__) && !defined(GAEGULI_COMPILATION)
#error "Only <gaeguli/gaeguli.h> can be included directly."
#endif

#include <gmodule.h>

#ifndef _GAEGULI_EXTERN
#define _GAEGULI_EXTERN         extern
#endif

#define GAEGULI_API_EXPORT     _GAEGULI_EXTERN

typedef enum {
  GAEGULI_RETURN_FAIL = -1,
  GAEGULI_RETURN_OK,
} GaeguliReturn;

typedef enum {
  GAEGULI_SRT_MODE_UNKNOWN = 0,
  GAEGULI_SRT_MODE_CALLER,
  GAEGULI_SRT_MODE_LISTENER,
  GAEGULI_SRT_MODE_RENDEZVOUS,
} GaeguliSRTMode;

#define GAEGULI_RESOURCE_ERROR          (gaeguli_resource_error_quark ())
GQuark gaeguli_resource_error_quark     (void);

typedef enum {
  GAEGULI_RESOURCE_ERROR_UNSUPPORTED,
  GAEGULI_RESOURCE_ERROR_READ,
  GAEGULI_RESOURCE_ERROR_WRITE,
  GAEGULI_RESOURCE_ERROR_RW,
} GaeguliResourceError;

#endif // __GAEGULI_TYPES_H__
