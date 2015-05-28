#ifndef __VECMATH_UTIL_H__
#define __VECMATH_UTIL_H__

#include "Matrix3f.h"
#include "Matrix4f.h"
#include "Vector2f.h"
#include "Vector3f.h"
#include "Vector4f.h"

namespace vm
{
    void loadMatrix(const Matrix3f& M);
    void loadMatrix(const Matrix4f& M);
    void multMatrix(const Matrix3f& M);
    void multMatrix(const Matrix4f& M);
    void pushMatrix(const Matrix3f& M);
    void pushMatrix(const Matrix4f& M);
    void normal(const Vector3f& v);
    void normal(const Vector4f& v);
    void vertex(const Vector2f& v);
    void vertex(const Vector3f& v);
    void vertex(const Vector4f& v);
    void vertex3(const Vector4f& v);
}

#endif /* __VECMATH_UTIL_H__ */