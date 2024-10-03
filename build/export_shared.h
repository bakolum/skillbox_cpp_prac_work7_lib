
#ifndef MATRIXLIB_EXPORT_H
#define MATRIXLIB_EXPORT_H

#ifdef MATRIXLIB_STATIC_DEFINE
#  define MATRIXLIB_EXPORT
#  define MATRIXLIB_NO_EXPORT
#else
#  ifndef MATRIXLIB_EXPORT
#    ifdef shared_matrixlib_EXPORTS
        /* We are building this library */
#      define MATRIXLIB_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define MATRIXLIB_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef MATRIXLIB_NO_EXPORT
#    define MATRIXLIB_NO_EXPORT 
#  endif
#endif

#ifndef MATRIXLIB_DEPRECATED
#  define MATRIXLIB_DEPRECATED __declspec(deprecated)
#endif

#ifndef MATRIXLIB_DEPRECATED_EXPORT
#  define MATRIXLIB_DEPRECATED_EXPORT MATRIXLIB_EXPORT MATRIXLIB_DEPRECATED
#endif

#ifndef MATRIXLIB_DEPRECATED_NO_EXPORT
#  define MATRIXLIB_DEPRECATED_NO_EXPORT MATRIXLIB_NO_EXPORT MATRIXLIB_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MATRIXLIB_NO_DEPRECATED
#    define MATRIXLIB_NO_DEPRECATED
#  endif
#endif

#endif /* MATRIXLIB_EXPORT_H */
