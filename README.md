# VectorStorm

Vector mathematics for computer graphics - VoxelStorm version.

This library loosely follows the structure of the popular `vmath.h` library by Jan Bartipan for familiarity and ease of back-porting, but provides optimised algorithms, modern C++, extensive constexpr compatibility, explicit control over copy operations, SSE and platform-specific optimisations, and a GLSL-style altenative short syntax.

Designed for lean game applications, you only pay for what you use - there is no cruft or overhead, all types are templated and you may include only the headers you need.  Forward declaration headers are provided for all types.

The VectorStorm library is intended to easily interface with OpenGL and similar libraries, and its vector and matrix types can be passed to OpenGL functions directly - see below.  Conversion operators are also easily written for other common vector types in popular libraries - see below for example conversion operators to interoperate with ImGui::Vec2 types and other examples.

The VectorStorm library is used by most [VoxelStorm](https://github.com/VoxelStorm-Ltd) and [Armchair Software](https://github.com/Armchair-Software) libraries.

## Requirements

- Optional: Boost headers, for math constants and hash_combine.  This requirement can be overruled with the `VECTORSTORM_NO_BOOST` define, but will fall back to functionality that may introduce a performance penalty.  Alternatively, if you don't use the related functionality, Boost is not required.  For this reason, you may need to include the Boost headers yourself, only when instantiating the relevant templates.
  - boost/functional/hash.hpp
  - boost/math/constants/constants.hpp
  - boost/math/special_functions/erf.hpp

## Structure
### Top level includes
- [vectorstorm.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vectorstorm.h) - Include this to pull in all other headers.  For finer grained control, only include the required headers below.
- [vectorstorm_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vectorstorm_forward.h) - Forward declaration for all types.
- [vectorstorm.cpp](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vectorstorm.cpp) - Optionally build this in your project, with `VECTORSTORM_PREINSTANTIATE` enabled, if you wish to instantiate all templates with common numerical types.  Not normally required.
 
### Primary types
#### Vector
Two-dimensional vectors:
- [vector/vector2.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector2.h)
- [vector/vector2_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector2_forward.h) - forward declarations
- [vector/vector2_types.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector2_types.h) - shortcut type definitions
  - `using vec2   = vector2<T>;`
  - `using vec2f  = vector2f;`
  - `using vec2d  = vector2d;`
  - `using vec2ld = vector2ld;`
  - `using vec2i  = vector2i;`
  - `using vec2ui = vector2ui;`

Three-dimensional vectors:
- [vector/vector3.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector3.h)
- [vector/vector3_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector3_forward.h) - forward declarations
- [vector/vector3_types.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector3_types.h) - shortcut type definitions
  - `using vec3   = vector3<T>;`
  - `using vec3f  = vector3f;`
  - `using vec3d  = vector3d;`
  - `using vec3ld = vector3ld;`
  - `using vec3i  = vector3i;`
  - `using vec3ui = vector3ui;`
  
Four-dimensional vectors:
- [vector/vector4.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector4.h)
- [vector/vector4_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector4_forward.h) - forward declarations
- [vector/vector4_types.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/vector4_types.h) - shortcut type definitions
  - `using vec4   = vector4<T>;`
  - `using vec4f  = vector4f;`
  - `using vec4d  = vector4d;`
  - `using vec4ld = vector4ld;`
  - `using vec4i  = vector4i;`
  - `using vec4ui = vector4ui;`

Utility functionality for vectors:
- [vector/hash_combine.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/vector/hash_combine.h)

#### Quaternion
- [quat/quat.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/quat/quat.h)
- [quat/quat_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/quat/quat_forward.h) - forward declarations
- [quat/quat_types.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/quat/quat_types.h) - shortcut type definitions

#### Matrix
Three-dimensional matrix types (3x3 matrices)
- [matrix/matrix3.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/matrix/matrix3.h)
- [matrix/matrix3_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/matrix/matrix3_forward.h) - forward declarations
- [matrix/matrix3_types.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/matrix/matrix3_types.h) - shortcut type definitions

Four-dimensional matrix types (4x4 matrices)
- [matrix/matrix4.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/matrix/matrix4.h)
- [matrix/matrix4_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/matrix/matrix4_forward.h) - forward declarations
- [matrix/matrix4_types.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/matrix/matrix4_types.h) - shortcut type definitions

#### Axis-aligned Bounding Box (AABB)
Two-dimensional bounding box types
- [aabb/aabb2.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/aabb/aabb2.h)
- [aabb/aabb2_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/aabb/aabb2_forward.h) - forward declarations
- [aabb/aabb2_types.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/aabb/aabb2_types.h) - shortcut type definitions

Three-dimensional bounding box types
- [aabb/aabb3.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/aabb/aabb3.h)
- [aabb/aabb3_forward.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/aabb/aabb3_forward.h) - forward declarations
- [aabb/aabb3_types.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/aabb/aabb3_types.h) - shortcut type definitions

### Stand-alone functionality
- [deg2rad.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/deg2rad.h)
- [rad2deg.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/rad2deg.h)
- [epsilon.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/epsilon.h)
- [floor_fast.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/floor_fast.h)
- [lerp.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/lerp.h)
- [sigmoid.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/sigmoid.h)
- [sincos.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/sincos.h)
- [sqrt_fast.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/sqrt_fast.h)

### Miscellaneous
- [pi.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/pi.h)
- [deprecated_macros.h](https://github.com/VoxelStorm-Ltd/vectorstorm/blob/master/vectorstorm/deprecated_macros.h)

 
## Interoperability

### Use with OpenGL

### Use with GLFW

### Use with ImGUI

## Defines

- `VECTORSTORM_NAMESPACE` - What namespace to use, if any. Defaults to none. 
- `VECTORSTORM_NO_BOOST` - Avoid using boost headers - may have some performance penalty.
- `VECTORSTORM_SOFT_COMPARE` - Enable fuzzy matching for different types, with epsilon used to match within a range of rounding error.  This is needed for accurate comparisons between floating point types on most architectures, but as this is relatively expensive, it is not enabled by default.
- `VECTORSTORM_PREINSTANTIATE` - Instantiate all templates with common numerical types. 