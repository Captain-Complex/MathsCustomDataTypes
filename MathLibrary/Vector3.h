#pragma once

namespace MathLibrary
{
    struct Vector3
    {
        //vector3's public field
    public:
        float x, y, z = 0.f;

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
        Vector3 operator + (Vector3& v3Add)const
        {
            Vector3 tempAdd;
            tempAdd.x = x + v3Add.x;
            tempAdd.y = y + v3Add.y;
            tempAdd.z = z + v3Add.z;
            return tempAdd;
        }
        Vector3 operator - (Vector3& v3Subtract)const
        {
            Vector3 tempSubtract;
            tempSubtract.x = x - v3Subtract.x;
            tempSubtract.y = y - v3Subtract.y;
            tempSubtract.z = z - v3Subtract.z;
            return tempSubtract;
        }
        Vector3 operator * (Vector3& v3Multiply)const
        {
            Vector3 tempMultiply;
            tempMultiply.x = x * v3Multiply.x;
            tempMultiply.y = y * v3Multiply.y;
            tempMultiply.z = z * v3Multiply.z;
            return tempMultiply;
        }
        Vector3 operator * (float v3ScalarMult) const
        {
            return Vector3(x * v3ScalarMult, y * v3ScalarMult, z * v3ScalarMult);
        }
        Vector3 operator / (float v3ScalarDivide) const
        {
            return Vector3(x / v3ScalarDivide, y / v3ScalarDivide, z / v3ScalarDivide);
        }
        
        Vector3 operator = (Vector3& v3Assignment)
        {
            Vector3 tempAssignment;
            tempAssignment.x = x = v3Assignment.x;
            tempAssignment.y = y = v3Assignment.y;
            tempAssignment.z = z = v3Assignment.z;
            return tempAssignment;
        }
        Vector3 operator += (Vector3& v3AddAssign)
        {
            Vector3 tempAddAssign;
            tempAddAssign.x = x += v3AddAssign.x;
            tempAddAssign.y = y += v3AddAssign.y;
            tempAddAssign.z = z += v3AddAssign.z;
            return tempAddAssign;
        }
        Vector3 operator -= (Vector3& v3SubtractAssign)
        {
            Vector3 tempSubtractAssign;
            tempSubtractAssign.x = x -= v3SubtractAssign.x;
            tempSubtractAssign.y = y -= v3SubtractAssign.y;
            tempSubtractAssign.z = z -= v3SubtractAssign.z;
            return tempSubtractAssign;
        }
        Vector3 operator *= (Vector3& v3MulitplyAssign)
        {
            Vector3 tempMultiplyAssign;
            tempMultiplyAssign.x = x *= v3MulitplyAssign.x;
            tempMultiplyAssign.y = y *= v3MulitplyAssign.y;
            tempMultiplyAssign.z = z *= v3MulitplyAssign.z;
            return tempMultiplyAssign;
        }
        Vector3 operator *= (const float v3ScalarMultAssign)
        {
            return Vector3(x *= v3ScalarMultAssign, y *= v3ScalarMultAssign, z *= v3ScalarMultAssign);
        }
        Vector3 operator /= (const float v3ScalarDivideAssign) 
        {
            return Vector3(x /= v3ScalarDivideAssign, y /= v3ScalarDivideAssign, z /= v3ScalarDivideAssign);
        }

        Vector3 operator -() const
        {
            return { -x, -y, -z };
        }
        bool operator == (Vector3& v3Equality)const
        {
            return x == v3Equality.x && y == v3Equality.y && z == v3Equality.z;
        }
        bool operator != (Vector3& v3Inequality)const
        {
            return x != v3Inequality.x && y != v3Inequality.y && z != v3Inequality.z;
        }
        bool operator < (Vector3& v3LessThan)const
        {
            return x < v3LessThan.x && y < v3LessThan.y && z < v3LessThan.z;
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
                std::abs(z - rhs.z),

            };
            const int arraySize = sizeof(deltas) / sizeof(deltas[0]);
            for (int i = 0; i < arraySize; ++i)
            {
                if (deltas[i] > epsilon)
                {
                    return false;
                }
            }
            return true;
        }

        float Dot(Vector3) const
        {
            return{};
        }
        Vector3 Cross(Vector3) const
        {
            return{};
        }

        float Magnitude() const
        {
            return {};
        }
        void Normalise()
        {

        }
        Vector3 Normalised() const
        {
            return {};
        }

        float AngleBetween(Vector3) const
        {
            return {};
        }
        float Distance(Vector3) const
        {
            return {};
        }
        float Angle2D() const
        {
            return {};
        }
    };
}
