#pragma once
#include "Vector3.h"
namespace MathLibrary
{
    struct Matrix3
    {
        //matrix3's public fields
    public:
        float m1, m2, m3, m4, m5, m6, m7, m8, m9;

        //matrix3's constructors
        Matrix3()
        {
            m1 = 1;
            m2 = 0;
            m3 = 0;
            m4 = 0;
            m5 = 1;
            m6 = 0;
            m7 = 0;
            m8 = 0;
            m9 = 1;
        }
        Matrix3(Matrix3& other)
        {
            m1 = other.m1;
            m2 = other.m2;
            m3 = other.m3;
            m4 = other.m4;
            m5 = other.m5;
            m6 = other.m6;
            m7 = other.m7;
            m8 = other.m8;
            m9 = other.m9;
        }
        Matrix3(float mat3m1, float mat3m2, float mat3m3,
                float mat3m4, float mat3m5, float mat3m6,
                float mat3m7, float mat3m8, float mat3m9)
        {
            m1 = mat3m1;
            m2 = mat3m2;
            m3 = mat3m3;
            m4 = mat3m4;
            m5 = mat3m5;
            m6 = mat3m6;
            m7 = mat3m7;
            m8 = mat3m8;
            m9 = mat3m9;
        }
        //matrix3's operators
        Matrix3& operator = (const Matrix3&)
        {
            return *this;
        }

        Vector3 operator*(Vector3)const
        {
            return {};
        }
        Matrix3 operator*(Matrix3)const
        {
            return {};
        }
        Matrix3& operator*=(Matrix3)
        {
            return *this;
        }

        bool operator==(Matrix3 equal) const
        {
            return {m1 == equal.m1 && m2 == equal.m2 && m3 == equal.m3 &&
                m4 == equal.m4 && m5 == equal.m5 && m6 == equal.m6 &&
                m7 == equal.m7 && m8 == equal.m8 && m9 == equal.m9};
        }
        bool operator!=(Matrix3 notEqual)
        {
            return {};
        }

        float& operator[](int i)
        {
            switch (i)
            {
            case 0:
                return m1;
            case 1:
                return m2;
            case 2:
                return m3;
            case 3:
                return m4;
            case 4:
                return m5;
            case 5:
                return m6;
            case 6:
                return m7;
            case 7:
                return m8;
            case 8:
                return m9;
            }

            throw;
        }
        const float& operator[](int i)const
        {
            switch (i)
            {
            case 0:
                return m1;
            case 1:
                return m2;
            case 2:
                return m3;
            case 3:
                return m4;
            case 4:
                return m5;
            case 5:
                return m6;
            case 6:
                return m7;
            case 7:
                return m8;
            case 8:
                return m9;
            }

            throw;
        }
        //matrix3's member function
        static Matrix3 MakeRotate(float)
        {
            return {};
        }
        static Matrix3 MakeScale(float, float, float)
        {
            return {};
        }
        static Matrix3 MakeTranslation(float, float)
        {
            return {};
        }

        bool IsApproximatelyEqual(Matrix3, float = 1e-4f)
        {
            return {};
        }

        Vector3 GetRight()
        {
            return {};
        }
        Vector3 GetForward()
        {
            return {};
        }
        Vector3 GetTranslate()
        {
            return {};
        }

    };
}