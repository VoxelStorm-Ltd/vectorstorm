#ifndef VECTORSTORM_VECTOR2_TYPES_H_INCLUDED
#define VECTORSTORM_VECTOR2_TYPES_H_INCLUDED

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

//-------------------------------------
// Typedef shortcuts for 2D vector
//-------------------------------------
/// Two dimensional vector of floats
using vector2f  = vector2<float>;
/// Two dimensional vector of doubles
using vector2d  = vector2<double>;
/// Two dimensional vector of long doubles
using vector2ld = vector2<long double>;
/// Two dimensional vector of ints
using vector2i  = vector2<int>;

// abbreviated aliases
template<typename T>
using vec2   = vector2<T>;
using vec2f  = vector2f;
using vec2d  = vector2d;
using vec2ld = vector2ld;
using vec2i  = vector2i;

// deprecated transitional declarations
template<typename T>
using Vector2   __attribute__((deprecated("Use vector2 or vec2 instead."))) = vector2<T>;
using Vector2f  __attribute__((deprecated("Use vector2 or vec2 instead."))) = vector2f;
using Vector2d  __attribute__((deprecated("Use vector2 or vec2 instead."))) = vector2d;
using Vector2ld __attribute__((deprecated("Use vector2 or vec2 instead."))) = vector2ld;
using Vector2i  __attribute__((deprecated("Use vector2 or vec2 instead."))) = vector2i;

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#endif // VECTORSTORM_VECTOR2_TYPES_H_INCLUDED
