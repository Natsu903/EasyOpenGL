#pragma once
#include "../global/base.h"

namespace math
{
	template <typename T>
	class Vector3;

    template <typename T>
	class Vector4;

    template <typename T>
    class Vector2
    { 
    public:
        Vector2(){x=y=0;}
        Vector2(T x, T y):x(x),y(y){}
        Vector2(const Vector2<T>& v):x(v.x),y(v.y){}
        Vector2(const Vector3<T>& v):x(v.x),y(v.y){}
        Vector2(const Vector4<T>& v):x(v.x),y(v.y){}

        // Get element by index
        // int a=v[1]
        T operator[](int i) const
        {
            assert(i >= 0 && i < 2);
            if (i == 0)return x;
            return y;
        }

        // Assign element by index
        // v[1]=6
        T& operator[](int i)
        {
            assert(i >= 0 && i < 2);
            if (i == 0)return x;
            return y;
        }

        // Assignment operator overload
        Vector2<T>& operator=(const Vector2<T>& v)
        {
            x = v.x;
            y = v.y;
            return *this;
        }
        Vector2<T>& operator=(const Vector3<T>& v)
        {
            x = v.x;
            y = v.y;
            return *this;
        }
        Vector2<T>& operator=(const Vector4<T>& v)
        {
            x = v.x;
            y = v.y;
            return *this;
        }

        // Addition
        Vector2<T> operator+(const Vector2<T>& v) const
        {
            return Vector2<T>(x + v.x, y + v.y);
        }

        // Addition with assignment
        Vector2<T>& operator+=(const Vector2<T>& v)
        {
            x += v.x;
            y += v.y;
            return *this;
        }

        // Subtraction
        Vector2<T> operator-(const Vector2<T>& v) const
        {
            return Vector2<T>(x - v.x, y - v.y);
        }

        // Subtraction with assignment
        Vector2<T>& operator-=(const Vector2<T>& v)
        {
            x -= v.x;
            y -= v.y;
            return *this;
        }

        // Scalar multiplication
        Vector2<T> operator*(T s) const
        {
            return Vector2<T>(x * s, y * s);
        }

        // Scalar multiplication with assignment
        Vector2<T>& operator*=(T s)
        {
            x *= s;
            y *= s;
            return *this;
        }

        // Scalar division
        Vector2<T> operator/(T f) const
        {
            assert(f != 0);
            float inv = static_cast<T>(1) / f;
            return Vector2<T>(x * inv, y * inv);
        }

        // Scalar division with assignment
        Vector2<T>& operator/=(T f)
        {
            assert(f != 0);
            float inv = static_cast<T>(1) / f;
            x *= inv;
            y *= inv;
            return *this;
        }

        // Negation
        Vector2<T> operator-() const
        {
            return Vector2<T>(-x, -y);
        }

        void print()
        {
            std::cout << "Vector2:" << std::endl;
            std::cout << "x=" << x << ", y=" << y  << std::endl;
            std::cout << std::endl;
        }
        public:
            T x, y;
    };

	template <typename T>
    class Vector3
    {
    public:
        Vector3(){x=y=z=0;}
        Vector3(T x, T y, T z):x(x),y(y),z(z){}
        Vector3(const Vector2<T>& v):x(v.x),y(v.y),z(0){}
        Vector3(const Vector3<T>& v):x(v.x),y(v.y),z(v.z){}
        Vector3(const Vector4<T>& v):x(v.x),y(v.y),z(v.z){}

        // Get element by index
        // int a=v[1]
        T operator[](int i) const
        {
            assert(i >= 0 && i < 3);
            if (i == 0)return x;
            if (i == 1)return y;
            return z;
        }

        // Assign element by index
        // v[1]=6
        T& operator[](int i)
        {
            assert(i >= 0 && i < 3);
            if (i == 0)return x;
            if (i == 1)return y;
            return z;
        }

        // Assignment operator overload
        Vector3<T>& operator=(const Vector2<T>& v)
        {
            x = v.x;
            y = v.y;
            z = 0;
            return *this;
        }
        Vector3<T>& operator=(const Vector3<T>& v)
        {
            x = v.x;
            y = v.y;
            z = v.z;
            return *this;
        }
        Vector3<T>& operator=(const Vector4<T>& v)
        {
            x = v.x;
            y = v.y;
            z = v.z;
            return *this;
        }

        // Addition
        Vector3<T> operator+(const Vector3<T>& v) const
        {
            return Vector3<T>(x + v.x, y + v.y, z + v.z);
        }

        // Addition with assignment
        Vector3<T>& operator+=(const Vector3<T>& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        // Subtraction
        Vector3<T> operator-(const Vector3<T>& v) const
        {
            return Vector3<T>(x - v.x, y - v.y, z - v.z);
        }

        // Subtraction with assignment
        Vector3<T>& operator-=(const Vector3<T>& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }

        // Scalar multiplication
        Vector3<T> operator*(T s) const
        {
            return Vector3<T>(x * s, y * s, z * s);
        }

        // Scalar multiplication with assignment
        Vector3<T>& operator*=(T s)
        {
            x *= s;
            y *= s;
            z *= s;
            return *this;
        }

        // Scalar division
        Vector3<T> operator/(T f) const
        {
            assert(f != 0);
            float inv = static_cast<T>(1) / f;
            return Vector3<T>(x * inv, y * inv, z * inv);
        }

        // Scalar division with assignment
        Vector3<T>& operator/=(T f)
        {
            assert(f != 0);
            float inv = static_cast<T>(1) / f;
            x *= inv;
            y *= inv;
            z *= inv;
            return *this;
        }

        // Negation
        Vector3<T> operator-() const
        {
            return Vector3<T>(-x, -y, -z);
        }

        void print()
        {
            std::cout << "Vector3:" << std::endl;
            std::cout << "x=" << x << ", y=" << y << ", z=" << z << std::endl;
            std::cout << std::endl;
        }
    public:
        T x, y, z;
    };


	template <typename T>
    class Vector4
    {
    public:
        Vector4(){x=y=z=w=0;}
        Vector4(T x, T y, T z, T w):x(x),y(y),z(z),w(w){}
        Vector4(const Vector2<T>& v):x(v.x),y(v.y),z(0),w(0){}
        Vector4(const Vector3<T>& v):x(v.x),y(v.y),z(v.z),w(0){}
        Vector4(const Vector4<T>& v):x(v.x),y(v.y),z(v.z),w(v.w){}

        // Get element by index
        // int a=v[1]
        T operator[](int i) const
        {
            assert(i >= 0 && i < 4);
            if (i == 0)return x;
            if (i == 1)return y;
            if (i == 2)return z;
            return w;
        }

        // Assign element by index
        // v[1]=6
        T& operator[](int i)
        {
            assert(i >= 0 && i < 4);
            if (i == 0)return x;
            if (i == 1)return y;
            if (i == 2)return z;
            return w;
        }

        // Assignment operator overload
        Vector4<T>& operator=(const Vector2<T>& v)
        {
            x = v.x;
            y = v.y;
            z = 0;
            w = 0;
            return *this;
        }
        Vector4<T>& operator=(const Vector3<T>& v)
        {
            x = v.x;
            y = v.y;
            z = v.z;
            w = 0;
            return *this;
        }
        Vector4<T>& operator=(const Vector4<T>& v)
        {
            x = v.x;
            y = v.y;
            z = v.z;
            w = v.w;
            return *this;
        }

        // Addition
        Vector4<T> operator+(const Vector4<T>& v) const
        {
            return Vector4<T>(x + v.x, y + v.y, z + v.z, w + v.w);
        }

        // Addition with assignment
        Vector4<T>& operator+=(const Vector4<T>& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            w += v.w;
            return *this;
        }

        // Subtraction
        Vector4<T> operator-(const Vector4<T>& v) const
        {
            return Vector4<T>(x - v.x, y - v.y, z - v.z, w - v.w);
        }

        // Subtraction with assignment
        Vector4<T>& operator-=(const Vector4<T>& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            w -= v.w;
            return *this;
        }

        // Scalar multiplication
        Vector4<T> operator*(T s) const
        {
            return Vector4<T>(x * s, y * s, z * s, w * s);
        }

        // Scalar multiplication with assignment
        Vector4<T>& operator*=(T s)
        {
            x *= s;
            y *= s;
            z *= s;
            w *= s;
            return *this;
        }

        // Vector4 * Vector3 element-wise multiplication
        Vector4<T> operator*(const Vector3<T>& v) const
        {
            x=x*v.x;
            y=y*v.y;
            z=z*v.z;
            return *this;
        }

        // Scalar division
        Vector4<T> operator/(T f) const
        {
            assert(f != 0);
            float inv = static_cast<T>(1) / f;
            return Vector4<T>(x * inv, y * inv, z * inv, w * inv);
        }

        // Scalar division with assignment
        Vector4<T>& operator/=(T f)
        {
            assert(f != 0);
            float inv = static_cast<T>(1) / f;
            x *= inv;
            y *= inv;
            z *= inv;
            w *= inv;
            return *this;
        }

        // Negation
        Vector4<T> operator-() const
        {
            return Vector4<T>(-x, -y, -z, -w);
        }

        void print()
        {
            std::cout << "Vector4:" << std::endl;
            std::cout << "x=" << x << ", y=" << y << ", z=" << z << ", w=" << w << std::endl;
            std::cout << std::endl;
        }
    public:
        T x, y, z, w;
    };

	using vec2f = Vector2<float>;
	using vec2i = Vector2<int>;
	using vec3f = Vector3<float>;
	using vec3i = Vector3<int>;
	using vec4f = Vector4<float>;
	using vec4i = Vector4<int>;
}
