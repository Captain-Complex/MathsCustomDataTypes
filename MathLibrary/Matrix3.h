#pragma once
#include "Vector3.h"

namespace MathLibrary
{
    struct Matrix3
    {
        //Column-Major
        //|m1|m4|m7
        //|m2|m5|m8
        //|m3|m6|m9


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
        Matrix3(const Matrix3& other)
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
        Matrix3 operator = (const Matrix3& other) 
        {
            Matrix3 temp;
            temp.m1 = m1 = other.m1;
            temp.m2 = m2 = other.m2;
            temp.m3 = m3 = other.m3;

            temp.m4 = m4 = other.m4;
            temp.m5 = m5 = other.m5;
            temp.m6 = m6 = other.m6;

            temp.m7 = m7 = other.m7;
            temp.m8 = m8 = other.m8;
            temp.m9 = m9 = other.m9;

            return temp;
        }

        friend Vector3 operator * (Matrix3 a,Vector3 b)
        {
            return {
                a.m1*b.x + a.m4*b.y + a.m7*b.z,
                a.m2*b.x + a.m5*b.y + a.m8*b.z,
                a.m3*b.x + a.m6*b.y + a.m9*b.z
            };
        }
       friend Matrix3 operator * (Matrix3 a, Matrix3 b)
        {
            return a *= b;  
        }
        friend Matrix3& operator *= (Matrix3& lhs, Matrix3 rhs)
        {
            Vector3 row1{ lhs.m1,lhs.m4,lhs.m7 };
            Vector3 row2{ lhs.m2,lhs.m5,lhs.m8 };
            Vector3 row3{ lhs.m3,lhs.m6,lhs.m9 };
            Vector3 column1{rhs.m1,rhs.m2,rhs.m3};
            Vector3 column2{rhs.m4,rhs.m5,rhs.m6};
            Vector3 column3{rhs.m7,rhs.m8,rhs.m9};

            lhs.m1 = row1.Dot(column1);
            lhs.m2 = row2.Dot(column1);
            lhs.m3 = row3.Dot(column1);

            lhs.m4 = row1.Dot(column2);
            lhs.m5 = row2.Dot(column2);
            lhs.m6 = row3.Dot(column2);
            
            lhs.m7 = row1.Dot(column3);
            lhs.m8 = row2.Dot(column3);
            lhs.m9 = row3.Dot(column3);

            return lhs;
        }

        friend bool operator == (Matrix3 lhs, Matrix3 equal)
        {
            return lhs.m1 == equal.m1 && lhs.m2 == equal.m2 && lhs.m3 == equal.m3 &&
                lhs.m4 == equal.m4 && lhs.m5 == equal.m5 && lhs.m6 == equal.m6 &&
                lhs.m7 == equal.m7 && lhs.m8 == equal.m8 && lhs.m9 == equal.m9;
        }
        friend bool operator!=(Matrix3 lhs,Matrix3 rhs)
        {
            return lhs.m1 != rhs.m1 && lhs.m2 != rhs.m2 && lhs.m3 != rhs.m3 &&
                lhs.m4 != rhs.m4 && lhs.m5 != rhs.m5 && lhs.m6 != rhs.m6 &&
                lhs.m7 != rhs.m7 && lhs.m8 != rhs.m8 && lhs.m9 != rhs.m9;;
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
        static Matrix3 MakeRotate(float rad)
        {
            Matrix3 result = {
            1.f, 0.f, 0.f,
            0.f, 1.f, 0.f,
            0.f, 0.f, 1.f,};

            float cosResult = cosf(rad);
            float sinResult = sinf(rad);

            result.m1 = cosResult;
            result.m2 = sinResult;
            result.m4 = -sinResult;
            result.m5 = cosResult;

            return result;
        }
        static Matrix3 MakeScale(float x, float y)
        {
            Matrix3 result = {
            1.f, 0.f, 0.f,
            0.f, 1.f, 0.f,
            0.f, 0.f, 1.f, };
            
            result.m1 *= x;
            result.m5 *= y;

            return result;
        }
        static Matrix3 MakeTranslation(float x, float y)
        {
            Matrix3 result = {
                1.f, 0.f, 0.f,
                0.f, 1.f, 0.f,
                x, y, 1.f
            };
            return result;
        }

        bool IsApproximatelyEqual(Matrix3 rhs, float epsilon = 1e-4f)const
        {
            float deltas[] = {
                std::abs(m1 - rhs.m1),
                std::abs(m2 - rhs.m2),
                std::abs(m3 - rhs.m3),
                std::abs(m4 - rhs.m4),
                std::abs(m5 - rhs.m5),
                std::abs(m6 - rhs.m6),
                std::abs(m7 - rhs.m7),
                std::abs(m8 - rhs.m8),
                std::abs(m9 - rhs.m9)
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

        Vector3 GetRight()
        {
            Vector3 right = {m4, m5, m6};
            return right;
        }
        Vector3 GetForward()
        {
            Vector3 forward = {m1, m2, m3};
            return forward;
        }
        Vector3 GetTranslate()
        {
            //not tested so added translation
            Matrix3::MakeTranslation(2.0f, 3.0f);
            Vector3 translate = { m3, m6, m9 };
            return translate;
        }

    };
}