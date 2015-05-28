#ifdef _WIN32
  #include <windows.h>
#endif

#include <GL/gl.h>

#include "util.h"

static void convert3to4(const Matrix3f& M, GLfloat *dest)
{
    const float *e = M.getElements();
    dest[ 0] = e[0];    dest[ 1] = e[1];    dest[ 2] = e[2];    dest[ 3] = 0;
    dest[ 4] = e[3];    dest[ 5] = e[4];    dest[ 6] = e[5];    dest[ 7] = 0;
    dest[ 8] = e[6];    dest[ 9] = e[7];    dest[10] = e[8];    dest[11] = 0;
    dest[12] =    0;    dest[13] =    0;    dest[14] =    0;    dest[15] = 1;
}

namespace vm
{
    void loadMatrix(const Matrix3f& M3)
    {
        GLfloat M4[16];
        convert3to4(M3, M4);
        glLoadMatrixf(M4);
    }

    void loadMatrix(const Matrix4f& M)
    {
        glLoadMatrixf(M.getElements());
    }

    void multMatrix(const Matrix3f& M3)
    {
        GLfloat M4[16];
        convert3to4(M3, M4);
        glMultMatrixf(M4);
    }

    void multMatrix(const Matrix4f& M)
    {
        glMultMatrixf(M.getElements());
    }

    
    void pushMatrix(const Matrix3f& M3)
    {
        GLfloat M4[16];
        convert3to4(M3, M4);
        glPushMatrix();
        glMultMatrixf(M4);
    }

    void pushMatrix(const Matrix4f& M)
    {
        glPushMatrix();
        glMultMatrixf(M.getElements());
    }

    void normal(const Vector3f& v)
    {
        glNormal3fv(v.getElements());
    }

    void normal(const Vector4f& v)
    {
        glNormal3fv(v.getElements());
    }

    void vertex(const Vector2f& v)
    {
        glVertex2fv(v.getElements());
    }

    void vertex(const Vector3f& v)
    {
        glVertex3fv(v.getElements());
    }

    void vertex(const Vector4f& v)
    {
        glVertex4fv(v.getElements());
    }

    void vertex3(const Vector4f& v)
    {
        glVertex3fv(v.getElements());
    }
}