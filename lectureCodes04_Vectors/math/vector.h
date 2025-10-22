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

        /**
         * 取得向量某个元素
         * int a=v[1].
         */
        T operator[](int i) const
        {
            assert(i >= 0 && i < 2);
            if (i == 0)return x;
            return y;
        }

        /**
         * 给向量某个元素赋值
         * v[1]=6.
         */
        T& operator[](int i)
        {
            assert(i >= 0 && i < 2);
            if (i == 0)return x;
            return y;
        }

        //等号运算符重载
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

        //加法
        Vector2<T> operator+(const Vector2<T>& v) const
        {
            return Vector2<T>(x + v.x, y + v.y);
        }

        //加法并赋值
        Vector2<T>& operator+=(const Vector2<T>& v)
        {
            x += v.x;
            y += v.y;
            return *this;
        }

        //减法
        Vector2<T> operator-(const Vector2<T>& v) const
        {
            return Vector2<T>(x - v.x, y - v.y);
        }

        //减法并赋值
        Vector2<T>& operator-=(const Vector2<T>& v)
        {
            x -= v.x;
            y -= v.y;
            return *this;
        }

        //与标量的乘法
        Vector2<T> operator*(T s) const
        {
            return Vector2<T>(x * s, y * s);
        }

        //与标量的乘法并赋值
        Vector2<T>& operator*=(T s)
        {
            x *= s;
            y *= s;
            return *this;
        }

        //与标量的除法
        Vector2<T> operator/(T f) const
        {
            assert(f != 0);
            float inv = static_cast<T>(1) / f;
            return Vector2<T>(x * inv, y * inv);
        }

        //与标量的除法并赋值
        Vector2<T>& operator/=(T f)
        {
            assert(f != 0);
            float inv = static_cast<T>(1) / f;
            x *= inv;
            y *= inv;
            return *this;
        }

        //负号
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

        /**
         * 取得向量某个元素
         * int a=v[1].
         */
        T operator[](int i) const
        {
            assert(i >= 0 && i < 3);
            if (i == 0)return x;
            if (i == 1)return y;
            return z;
        }

        /**
         * 给向量某个元素赋值
         * v[1]=6.
         */
        T& operator[](int i)
        {
            assert(i >= 0 && i < 3);
            if (i == 0)return x;
            if (i == 1)return y;
            return z;
        }

        //等号运算符重载
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

        //加法
        Vector3<T> operator+(const Vector3<T>& v) const
        {
            return Vector3<T>(x + v.x, y + v.y, z + v.z);
        }

        //加法并赋值
        Vector3<T>& operator+=(const Vector3<T>& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        //减法
        Vector3<T> operator-(const Vector3<T>& v) const
        {
            return Vector3<T>(x - v.x, y - v.y, z - v.z);
        }

        //减法并赋值
        Vector3<T>& operator-=(const Vector3<T>& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }

        //与标量的乘法
        Vector3<T> operator*(T s) const
        {
            return Vector3<T>(x * s, y * s, z * s);
        }

        //与标量的乘法并赋值
        Vector3<T>& operator*=(T s)
        {
            x *= s;
            y *= s;
            z *= s;
            return *this;
        }

        //与标量的除法
        Vector3<T> operator/(T f) const
        {
            assert(f != 0);
            float inv = static_cast<T>(1) / f;
            return Vector3<T>(x * inv, y * inv, z * inv);
        }

        //与标量的除法并赋值
        Vector3<T>& operator/=(T f)
        {
            assert(f != 0);
            float inv = static_cast<T>(1) / f;
            x *= inv;
            y *= inv;
            z *= inv;
            return *this;
        }

        //负号
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

        /**
         * 取得向量某个元素
         * int a=v[1].
         */
        T operator[](int i) const
        {
            assert(i >= 0 && i < 4);
            if (i == 0)return x;
            if (i == 1)return y;
            if (i == 2)return z;
            return w;
        }

        /**
         * 给向量某个元素赋值
         * v[1]=6.
         */
        T& operator[](int i)
        {
            assert(i >= 0 && i < 4);
            if (i == 0)return x;
            if (i == 1)return y;
            if (i == 2)return z;
            return w;
        }

        //等号运算符重载
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

        //加法
        Vector4<T> operator+(const Vector4<T>& v) const
        {
            return Vector4<T>(x + v.x, y + v.y, z + v.z, w + v.w);
        }

        //加法并赋值
        Vector4<T>& operator+=(const Vector4<T>& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            w += v.w;
            return *this;
        }

        //减法
        Vector4<T> operator-(const Vector4<T>& v) const
        {
            return Vector4<T>(x - v.x, y - v.y, z - v.z, w - v.w);
        }

        //减法并赋值
        Vector4<T>& operator-=(const Vector4<T>& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            w -= v.w;
            return *this;
        }

        //与标量的乘法
        Vector4<T> operator*(T s) const
        {
            return Vector4<T>(x * s, y * s, z * s, w * s);
        }

        //与标量的乘法并赋值
        Vector4<T>& operator*=(T s)
        {
            x *= s;
            y *= s;
            z *= s;
            w *= s;
            return *this;
        }

        //四维向量与三维向量每个点的坐标相乘
        Vector4<T> operator*(const Vector3<T>& v) const
        {
            x=x*v.x;
            y=y*v.y;
            z=z*v.z;
            return *this;
        }

        //与标量的除法
        Vector4<T> operator/(T f) const
        {
            assert(f != 0);
            float inv = static_cast<T>(1) / f;
            return Vector4<T>(x * inv, y * inv, z * inv, w * inv);
        }

        //与标量的除法并赋值
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

        //负号
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
