#ifndef VECTORSTORM_VECTOR3_TYPES_H_INCLUDED
#define VECTORSTORM_VECTOR3_TYPES_H_INCLUDED

#ifdef VMATH_NAMESPACE
namespace VMATH_NAMESPACE {
#endif

//-------------------------------------
// Typedef shortcuts for 3D vector
//-------------------------------------
/// Three dimensional vector of floats
using vector3f  = vector3<float>;
/// Three dimensional vector of doubles
using vector3d  = vector3<double>;
/// Three dimensional vector of long doubles
using vector3ld = vector3<long double>;
/// Three dimensional vector of ints
using vector3i  = vector3<int>;

// abbreviated aliases
template<typename T>
using vec3   = vector3<T>;
using vec3f  = vector3f;
using vec3d  = vector3d;
using vec3ld = vector3ld;
using vec3i  = vector3i;

// deprecated transitional declarations
template<typename T>
using Vector3   __attribute__((deprecated("Use vector3 or vec3 instead."))) = vector3<T>;
using Vector3f  __attribute__((deprecated("Use vector3 or vec3 instead."))) = vector3f;
using Vector3d  __attribute__((deprecated("Use vector3 or vec3 instead."))) = vector3d;
using Vector3ld __attribute__((deprecated("Use vector3 or vec3 instead."))) = vector3ld;
using Vector3i  __attribute__((deprecated("Use vector3 or vec3 instead."))) = vector3i;

#ifdef VMATH_NAMESPACE
}
#endif //VMATH_NAMESPACE

#endif // VECTORSTORM_VECTOR3_TYPES_H_INCLUDED
