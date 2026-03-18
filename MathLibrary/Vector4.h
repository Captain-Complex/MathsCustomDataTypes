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
            
        }
        Vector4::Vector4()
        {

        }
        Vector4(float x, float y, float z, float w)
        {

        }
        //vector4's operators
        Vector4 operator + (Vector4& v4Add)
        {
            Vector4 TempAdd;
            TempAdd.x = x + v4Add.x;
            TempAdd.y = y + v4Add.y;
            TempAdd.z = z + v4Add.z;
            TempAdd.w = w + v4Add.w;
            return TempAdd;
        }
        Vector4 operator - (Vector4& v4Subtract)
        {
            Vector4 TempSubtract;
            TempSubtract.x = x - v4Subtract.x;
            TempSubtract.y = y - v4Subtract.y;
            TempSubtract.z = z - v4Subtract.z;
            TempSubtract.w = w - v4Subtract.w;
            return TempSubtract;
        }
        Vector4 operator * (Vector4& v4Multiply)
        {
            Vector4 TempMultiply;
            TempMultiply.x = x * v4Multiply.x;
            TempMultiply.y = y * v4Multiply.y;
            TempMultiply.z = z * v4Multiply.z;
            TempMultiply.w = w * v4Multiply.w;
            return TempMultiply;
        }
        /*Vector4 operator *  (Vector4& v3ScalarMultiply)
        {

        }
        Vector4 operator / (Vector4& v3ScalarDivide)
        {

        }
        */
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
        /*Vector4 operator *  (Vector4& v4ScalarMultiplyAssign)
        {

        }
        Vector4 operator / (Vector4& v4ScalarDivideAssign)
        {

        }
        
        Vector4 operator -()
        {

        }*/
        bool operator == (Vector4& v4Equality)
        {
            return x == v4Equality.x && y == v4Equality.y 
                && z == v4Equality.z && w == v4Equality.w;
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
        //V4[n]
        //vector4's member functions
        float Dot(Vector4 v4D)
        {

        }
        Vector4 Cross(Vector4 v4C)
        {

        }
        float Magnitude()
        {

        }
        void Normalise()
        {

        }
        Vector4 Normalised()
        {

        }
        bool IsApproximatelyEqual(Vector4 v4E)
        {

        }
        float AngleBetween(Vector4 v4A)
        {

        }
        float Distance(Vector4 v4Dis)
        {

        }
    };
}