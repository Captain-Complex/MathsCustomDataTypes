#pragma once
#include <cmath>
namespace MathLibrary
{
    struct Vector3
    {
        //vector3's public field
    public:
        float x, y, z;

        //vector3's constructors
        Vector3()
        {
            x = 0;
            y = 0;
            z = 0;
        }
        Vector3(const Vector3& other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        Vector3(float vec3x, float vec3y, float vec3z)
        {
            x = vec3x;
            y = vec3y;
            z = vec3z;
        }
        //vector3's operators
        Vector3 operator + (Vector3& v3Add) const
        {
            return {
             x + v3Add.x,
            y + v3Add.y,
            z + v3Add.z
            };
        }
        Vector3 operator - (const Vector3& v3Subtract) const
        {
            return {
            x - v3Subtract.x,
            y - v3Subtract.y,
            z - v3Subtract.z
            };
        }

        Vector3 operator * (Vector3& v3Multiply) const
        {
            return {
            x * v3Multiply.x,
            y * v3Multiply.y,
            z * v3Multiply.z
            };
        }
        Vector3 operator * (float v3ScalarMult) const
        {
            return Vector3(x * v3ScalarMult, y * v3ScalarMult, z * v3ScalarMult);
        }
        Vector3 operator / (float v3ScalarDivide) const
        {
            return Vector3(x / v3ScalarDivide, y / v3ScalarDivide, z / v3ScalarDivide);
        }
        
        const Vector3& operator = (const Vector3& v3Assignment)  
        {
            Vector3 tempAssignment;
            tempAssignment.x = x = v3Assignment.x;
            tempAssignment.y = y = v3Assignment.y;
            tempAssignment.z = z = v3Assignment.z;
            return tempAssignment;
        }
        const Vector3 operator += (const Vector3& v3AddAssign)  
        {
            Vector3 tempAddAssign;
            tempAddAssign.x = x += v3AddAssign.x;
            tempAddAssign.y = y += v3AddAssign.y;
            tempAddAssign.z = z += v3AddAssign.z;
            return tempAddAssign;
        }
         const Vector3 operator -=  (const Vector3& v3SubtractAssign) 
        {
            Vector3 tempSubtractAssign;
            tempSubtractAssign.x = x -= v3SubtractAssign.x;
            tempSubtractAssign.y = y -= v3SubtractAssign.y;
            tempSubtractAssign.z = z -= v3SubtractAssign.z;
            return tempSubtractAssign;
        }
        const Vector3 operator *= (const Vector3& v3MulitplyAssign) 
        {
            Vector3 tempMultiplyAssign;
            tempMultiplyAssign.x = x *= v3MulitplyAssign.x;
            tempMultiplyAssign.y = y *= v3MulitplyAssign.y;
            tempMultiplyAssign.z = z *= v3MulitplyAssign.z;
            return tempMultiplyAssign;
        }
      const Vector3 operator *= (const float v3ScalarMultAssign) 
        {
            return Vector3(x *= v3ScalarMultAssign, y *= v3ScalarMultAssign, z *= v3ScalarMultAssign);
        }
       const  Vector3 operator /= (const float v3ScalarDivideAssign) 
        {
            return Vector3(x /= v3ScalarDivideAssign, y /= v3ScalarDivideAssign, z /= v3ScalarDivideAssign);
        }

        Vector3 operator -() const
        {
            return { -x, -y, -z };
        }

        friend bool operator == (const Vector3& lhs,const Vector3& v3Equality)
        {
            return lhs.x == v3Equality.x && lhs.y == v3Equality.y && lhs.z == v3Equality.z;
        }
        friend bool operator != (const Vector3& lhs, const Vector3& v3Inequality)
        {
            return lhs.x != v3Inequality.x || lhs.y != v3Inequality.y || lhs.z != v3Inequality.z;
        }
        friend bool operator < (const Vector3& lhs, const Vector3& v3LessThan)
        {
            float v3a = v3LessThan.Magnitude();
            float v3b = lhs.Magnitude();
            if ((v3b < v3a) == true)
            {
                return true;
            }
            return false;
        }
        float& operator[] (int i)
        {
            switch(i)
            {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
            }

            throw;
        }
        const float& operator[] (int i)const
        {
            switch (i)
            {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
            }

            throw;

        }

        //vector3's member functions
        bool IsApproximatelyEqual(Vector3 rhs, float epsilon = 1e-4f) const
        {
            float deltas[] = {
                std::abs(x - rhs.x),
                std::abs(y - rhs.y),
                std::abs(z - rhs.z)
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

        float Dot(Vector3 rhs) const
        {
            return x * rhs.x + y * rhs.y + z * rhs.z;
        }
        Vector3 Cross(Vector3 rhs) const
        {
            return {
            y * rhs.z - z * rhs.y,
            z * rhs.x - x * rhs.z,
            x * rhs.y - y * rhs.x
            };
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
        }
        Vector3 Normalised() const
        {
            Vector3 result{ *this };
            result.Normalise();
            return result;
        }

        float AngleBetween(Vector3 other) const
        {
            float dot = x * other.x + y * other.y + z * other.z;
            float magLeft = std::hypot(x, y, z);
            float magRight = std::hypot(other.x, other.y, other.z);
            float acosResult = std::acos(dot / (magLeft * magRight));
            return acosResult;
        }
        float Distance(Vector3 rhs) const
        {
            Vector3 diff = Vector3{rhs.x - x, rhs.y - y, rhs.z - z};
            return diff.Magnitude();
        }
        float Angle2D() const
        {
            return std::atan2(y,x);
        }
        
    };
}
