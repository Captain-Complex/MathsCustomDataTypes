#pragma once

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
        Vector4 operator + (Vector4& v4Add)const
        {
            Vector4 TempAdd;
            TempAdd.x = x + v4Add.x;
            TempAdd.y = y + v4Add.y;
            TempAdd.z = z + v4Add.z;
            TempAdd.w = w + v4Add.w;
            return TempAdd;
        }
        Vector4 operator - (Vector4& v4Subtract)const
        {
            Vector4 TempSubtract;
            TempSubtract.x = x - v4Subtract.x;
            TempSubtract.y = y - v4Subtract.y;
            TempSubtract.z = z - v4Subtract.z;
            TempSubtract.w = w - v4Subtract.w;
            return TempSubtract;
        }
        Vector4 operator * (Vector4& v4Multiply)const
        {
            Vector4 TempMultiply;
            TempMultiply.x = x * v4Multiply.x;
            TempMultiply.y = y * v4Multiply.y;
            TempMultiply.z = z * v4Multiply.z;
            TempMultiply.w = w * v4Multiply.w;
            return TempMultiply;
        }
        Vector4 operator *  ( float v4ScalarMultiplyAssign) const
        {
            return { x * v4ScalarMultiplyAssign, y * v4ScalarMultiplyAssign,
                z * v4ScalarMultiplyAssign, w * v4ScalarMultiplyAssign };
        }
        Vector4 operator / (float v4ScalarDivide) const
        {
            return { x / v4ScalarDivide, y / v4ScalarDivide,
            z / v4ScalarDivide, w / v4ScalarDivide };
        }
        
        Vector4 operator = (Vector4& v4Assignment)
        {
            Vector4 TempAssignment;
            TempAssignment.x = x = v4Assignment.x;
            TempAssignment.y = y = v4Assignment.y;
            TempAssignment.z = z = v4Assignment.z;
            TempAssignment.w = w = v4Assignment.w;
            return TempAssignment;
        }
        Vector4 operator += (Vector4 v4AddAssign)
        {
            Vector4 TempAddAssign;
            TempAddAssign.x = x += v4AddAssign.x;
            TempAddAssign.y = y += v4AddAssign.y;
            TempAddAssign.z = z += v4AddAssign.z;
            TempAddAssign.w = w += v4AddAssign.w;
            return TempAddAssign;
        }
        Vector4 operator -= (Vector4 v4SubtractAssign)
        {
            Vector4 tempSubtractAssign;
            tempSubtractAssign.x = x -= v4SubtractAssign.x;
            tempSubtractAssign.y = y -= v4SubtractAssign.y;
            tempSubtractAssign.z = z -= v4SubtractAssign.z;
            tempSubtractAssign.w = w -= v4SubtractAssign.w;
            return tempSubtractAssign;
        }
        Vector4 operator *= (Vector4 v4MulitplyAssign)
        {
            Vector4 tempMultiplyAssign;
            tempMultiplyAssign.x = x *= v4MulitplyAssign.x;
            tempMultiplyAssign.y = y *= v4MulitplyAssign.y;
            tempMultiplyAssign.z = z *= v4MulitplyAssign.z;
            tempMultiplyAssign.w = w *= v4MulitplyAssign.w;
            return tempMultiplyAssign;
        }
        Vector4 operator *=  (const float v4ScalarMultiplyAssign) 
        {
            return Vector4(x *= v4ScalarMultiplyAssign, y *= v4ScalarMultiplyAssign,
                z *= v4ScalarMultiplyAssign, w *= v4ScalarMultiplyAssign);
        }
        Vector4 operator /= (const float v4ScalarDivideAssign)
        {
            return { x /= v4ScalarDivideAssign, y /= v4ScalarDivideAssign,
            z /= v4ScalarDivideAssign, w /= v4ScalarDivideAssign };
        }
        
        Vector4 operator -()
        {
            return {};
        }
        friend bool operator == (Vector4 lhs,Vector4 v4Equality)
        {
            return lhs.x == v4Equality.x && lhs.y == v4Equality.y 
                && lhs.z == v4Equality.z && lhs.w == v4Equality.w;
        }
        bool operator != (Vector4& v4Inequality)
        {
            return x != v4Inequality.x && y != v4Inequality.y 
                && z != v4Inequality.z && w != v4Inequality.w;
        }
        bool operator < (Vector4& v4LessThan)
        {
            return x < v4LessThan.x && y < v4LessThan.y 
                && z < v4LessThan.z && w < v4LessThan.w;
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
        bool IsApproximatelyEqual(Vector4, float = 1e-4) const
        {
            return {};
        }

        float Dot(Vector4) const
        {
            return {};
        }
        Vector4 Cross(Vector4) const
        {
            return {};
        }

        float Magnitude() const
        {
            return{};
        }
        void Normalise()
        {

        }
        Vector4 Normalised() const
        {
            return {};
        }
        
        float AngleBetween(Vector4) const
        {
            return {};
        }
        float Distance(Vector4) const
        {
            return {};
        }
    };
}