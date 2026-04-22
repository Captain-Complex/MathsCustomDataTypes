#pragma once
#include <cmath>
namespace MathLibrary
{
    struct Vector4
    {
        //vector4's public fields
    public:
        float x, y, z, w;
        
        //vector4's constructors
        Vector4() 
        {
            x = 0;
            y = 0;
            z = 0;
            w = 0;
        }
        Vector4(const Vector4& copy)
        {
            x = copy.x;
            y = copy.y;
            z = copy.z;
            w = copy.w;
        }
        Vector4(float vec4x, float vec4y, float vec4z, float vec4w)
        {
            x = vec4x;
            y = vec4y;
            z = vec4z;
            w = vec4w;
        }
        //vector4's operators
        Vector4 operator + (const Vector4& v4Add) const
        {
            return {
            x + v4Add.x,
            y + v4Add.y,
            z + v4Add.z,
            w
            };
        }
        Vector4 operator - (const Vector4& v4Subtract) const
        {
            return {
            x - v4Subtract.x,
            y - v4Subtract.y,
            z - v4Subtract.z,
            w
            };
        }
        Vector4 operator * (const Vector4& v4Multiply)const 
        {
            return {
            x * v4Multiply.x,
            y * v4Multiply.y,
            z * v4Multiply.z,
            w
            };
        }
        Vector4 operator *  ( float v4ScalarMultiplyAssign) const
        {
            return { x * v4ScalarMultiplyAssign, y * v4ScalarMultiplyAssign,
                z * v4ScalarMultiplyAssign, w};
        }
        Vector4 operator / (float v4ScalarDivide) const
        {
            return { x / v4ScalarDivide, y / v4ScalarDivide,
            z / v4ScalarDivide, w};
        }
        
        Vector4& operator = (const Vector4& v4Assignment)
        {
            x = v4Assignment.x;
            y = v4Assignment.y;
            z = v4Assignment.z;
            w = v4Assignment.w;
            return *this;
        }
        Vector4& operator += (const Vector4 v4AddAssign)
        {
            x += v4AddAssign.x;
            y += v4AddAssign.y;
            z += v4AddAssign.z;
            w;
            return *this;
        }
        Vector4& operator -= (const Vector4 v4SubtractAssign)
        {
            x -= v4SubtractAssign.x;
            y -= v4SubtractAssign.y;
            z -= v4SubtractAssign.z;
            w;
            return *this;
        }
        Vector4& operator *= (const Vector4 v4MulitplyAssign)
        {
            x *= v4MulitplyAssign.x;
            y *= v4MulitplyAssign.y;
            z *= v4MulitplyAssign.z;
            w ;
            return *this;
        }
        Vector4& operator *=  (const float v4ScalarMultiplyAssign) 
        {
            x *= v4ScalarMultiplyAssign;
            y *= v4ScalarMultiplyAssign;
            z *= v4ScalarMultiplyAssign;
            w;
            return *this;
        }
        Vector4& operator /= (const float v4ScalarDivideAssign)
        {
            x /= v4ScalarDivideAssign;
            y /= v4ScalarDivideAssign;
            z /= v4ScalarDivideAssign;
            w;
            return *this;
        }
        
        Vector4 operator -() const
        {
            return {-x, -y, -z, w};
        }

        friend bool operator == (const Vector4 lhs,const Vector4 v4Equality)
        {
            return lhs.x == v4Equality.x && lhs.y == v4Equality.y 
                && lhs.z == v4Equality.z && lhs.w == v4Equality.w;
        }
        bool operator != (Vector4& v4Inequality) const
        {
            return x != v4Inequality.x || y != v4Inequality.y 
                || z != v4Inequality.z || w != v4Inequality.w;
        }
        friend bool operator < (const Vector4& lhs, const Vector4 v4LessThan)
        {
            float v3a = v4LessThan.Magnitude();
            float v3b = lhs.Magnitude();
            if ((v3b < v3a) == true)
            {
                return true;
            }
            return false;
        }
        
        float& operator[] (int i)
        {
            switch (i)
            {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
            case 3:
                return w;
            }

            throw;
        }
        const float& operator[] (int i) const
        {
            switch (i)
            {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
            case 3:
                return w;
            }

            throw;
        }

        //vector4's member functions
        bool IsApproximatelyEqual(Vector4 rhs, float epsilon = 1e-4) const
        {
            float deltas[] = {
                std::abs(x - rhs.x),
                std::abs(y - rhs.y),
                std::abs(z - rhs.z),
                std::abs(w - rhs.w)
            };
            const int arraySize = sizeof(deltas) / sizeof(deltas[0]);
            for (int i = 0; i < arraySize; ++i)
            {
                if (!(deltas[i] <= epsilon))
                {
                    return false;
                }
            }
            return true;
        }

        float Dot(Vector4 rhs) const
        {
            return x * rhs.x + y * rhs.y + z * rhs.z;

        }
        Vector4 Cross(Vector4 rhs) const
        {
            return {
           y * rhs.z - z * rhs.y,
           z * rhs.x - x * rhs.z,
           x * rhs.y - y * rhs.x,
            w};
        }

        float Magnitude() const
        {
            return std::hypot(x, y, z);
        }
        void Normalise()
        {
            float mag = std::hypot(x, y, z);
            if (mag == 0.f)
            {
                return;
            }
            x /= mag;
            y /= mag;
            z /= mag;
            w = w;
        }
        Vector4 Normalised() const
        {
            Vector4 result{ *this };
            result.Normalise();
            return result;
        }
        
        float AngleBetween(Vector4 other) const
        {
            float dot = x * other.x + y * other.y + z * other.z;
            float magLeft = std::sqrt(x*x + y*y +z*z);
            float magRight = std::sqrt(other.x*other.x + other.y*other.y + other.z*other.z);
            float acosResult = std::acos(dot / (magLeft * magRight));
            return acosResult;
        }
        float Distance(Vector4 rhs) const
        {
            Vector4 diff = Vector4{ rhs.x - x, rhs.y - y, rhs.z - z, w };
            return diff.Magnitude();
        }
    };
}