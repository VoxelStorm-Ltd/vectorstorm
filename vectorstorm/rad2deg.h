#ifndef VECTORSTORM_RAD2DEG_H_INCLUDED
#define VECTORSTORM_RAD2DEG_H_INCLUDED

#include "pi.h"

#define RAD2DEG rad2deg

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

template<typename T>
inline static T constexpr const rad2deg(T const angle_rad) noexcept __attribute__((__always_inline__));
template<typename T>
inline static T constexpr const rad2deg(T const angle_rad) noexcept {
  #ifndef VMATH_NO_BOOST
    return angle_rad * boost::math::constants::radian<T>();
  #else  // VMATH_NO_BOOST
    return (angle_rad * 180.0) / M_PI;
  #endif // VMATH_NO_BOOST
}

#ifdef VMATH_NAMESPACE
}
#endif

#endif // VECTORSTORM_RAD2DEG_H_INCLUDED
