#pragma once
#include "Vector4.h"
namespace MathLibrary
{
    struct Matrix4
    {
        //Column-Major
        //|m1|m5|m9 |m13
        //|m2|m6|m10|m14
        //|m3|m7|m11|m15
        //|m4|m8|m12|m16


        //matrix4's public flields
    public:
        float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16;

        //matrix4's constructors
        Matrix4()
        {
            m1 = 1;
            m2 = 0;
            m3 = 0;
            m4 = 0;
            m5 = 0;
            m6 = 1;
            m7 = 0;
            m8 = 0;
            m9 = 0;
            m10 = 0;
            m11 = 1;
            m12 = 0;
            m13 = 0;
            m14 = 0;
            m15 = 0;
            m16 = 1;
        }
        Matrix4(const Matrix4& other)
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
            m10 = other.m10;
            m11 = other.m11;
            m12 = other.m12;
            m13 = other.m13;
            m14 = other.m14;
            m15 = other.m15;
            m16 = other.m16;
        }
        Matrix4(
            float mat4m1, float mat4m2, float mat4m3, float mat4m4,
            float mat4m5, float mat4m6, float mat4m7, float mat4m8,
            float mat4m9, float mat4m10, float mat4m11, float mat4m12,
            float mat4m13, float mat4m14, float mat4m15, float mat4m16)
        {
            m1 = mat4m1;
            m2 = mat4m2;
            m3 = mat4m3;
            m4 = mat4m4;
            m5 = mat4m5;
            m6 = mat4m6;
            m7 = mat4m7;
            m8 = mat4m8;
            m9 = mat4m9;
            m10 = mat4m10;
            m11 = mat4m11;
            m12 = mat4m12;
            m13 = mat4m13;
            m14 = mat4m14;
            m15 = mat4m15;
            m16 = mat4m16;
        }
        //matrix4's operators
        Matrix4 operator = (const Matrix4& other)
        {
            Matrix4 temp;
            temp.m1 = m1 = other.m1;
            temp.m2 = m2 = other.m2;
            temp.m3 = m3 = other.m3;
            temp.m4 = m4 = other.m4;

            temp.m5 = m5 = other.m5;
            temp.m6 = m6 = other.m6;
            temp.m7 = m7 = other.m7;
            temp.m8 = m8 = other.m8;

            temp.m9 = m9 = other.m9;
            temp.m10 = m10 = other.m10;
            temp.m11 = m11 = other.m11;
            temp.m12 = m12 = other.m12;
            
            temp.m13 = m13 = other.m13;
            temp.m14 = m14 = other.m14;
            temp.m15 = m15 = other.m15;
            temp.m16 = m16 = other.m16;

            return temp;
        }

        friend Vector4 operator*(Matrix4 a, Vector4 b)
        {
            return {
                a.m1 * b.x + a.m5 * b.y + a.m9 * b.z + a.m13 *b.w,
                a.m2 * b.x + a.m6 * b.y + a.m10 * b.z + a.m14 *b.w,
                a.m3 * b.x + a.m7 * b.y + a.m11 * b.z + a.m15 * b.w,
                a.m4 * b.x + a.m8 * b.y + a.m12 * b.z + a.m16 * b.w,
            };
        }
        friend Matrix4 operator*(Matrix4 a, Matrix4 b)
        {
            return a *= b;
        }
        friend Matrix4& operator*=(Matrix4& lhs, Matrix4 rhs)
        {
            Vector4 row1{lhs.m1,lhs.m5,lhs.m9,lhs.m13};
            Vector4 row2{lhs.m2,lhs.m6,lhs.m10,lhs.m14};
            Vector4 row3{lhs.m3,lhs.m7,lhs.m11,lhs.m15};
            Vector4 row4{lhs.m4,lhs.m8,lhs.m12,lhs.m16};
            Vector4 column1{rhs.m1,rhs.m2,rhs.m3,rhs.m4};
            Vector4 column2{rhs.m5,rhs.m6,rhs.m7,rhs.m8};
            Vector4 column3{rhs.m9,rhs.m10,rhs.m11,rhs.m12};
            Vector4 column4{rhs.m13,rhs.m14,rhs.m15,rhs.m16};
            
            lhs.m1 = row1.Dot(column1) + row1.w * column1.w;
            lhs.m2 = row2.Dot(column1) + row2.w * column1.w;
            lhs.m3 = row3.Dot(column1) + row3.w * column1.w;
            lhs.m4 = row4.Dot(column1) + row4.w * column1.w;

            lhs.m5 = row1.Dot(column2) + row1.w * column2.w;
            lhs.m6 = row2.Dot(column2) + row2.w * column2.w;
            lhs.m7 = row3.Dot(column2) + row3.w * column2.w;
            lhs.m8 = row4.Dot(column2) + row4.w * column2.w;

            lhs.m9 = row1.Dot(column3) + row1.w * column3.w;
            lhs.m10 = row2.Dot(column3) + row2.w * column3.w;
            lhs.m11 = row3.Dot(column3) + row3.w * column3.w;
            lhs.m12 = row4.Dot(column3) + row4.w * column3.w;

            lhs.m13 = row1.Dot(column4) + row1.w * column4.w;
            lhs.m14 = row2.Dot(column4) + row2.w * column4.w;
            lhs.m15 = row3.Dot(column4) + row3.w * column4.w;
            lhs.m16 = row4.Dot(column4) + row4.w * column4.w;

            return lhs;
        }
        friend bool operator==(Matrix4 lhs, Matrix4 equal)
        {
            return  lhs.m1 == equal.m1 && lhs.m2 == equal.m2 && lhs.m3 == equal.m3 && lhs.m4 == equal.m4 &&
                lhs.m5 == equal.m5 && lhs.m6 == equal.m6 && lhs.m7 == equal.m7 && lhs.m8 == equal.m8 &&
                lhs.m9 == equal.m9 && lhs.m10 == equal.m10 && lhs.m11 == equal.m11 && lhs.m12 == equal.m12 &&
                lhs.m13 == equal.m13 && lhs.m14 == equal.m14 && lhs.m15 == equal.m15 && lhs.m16 == equal.m16;
        }
        friend bool operator!=(Matrix4 lhs, Matrix4 rhs)
        {
            return lhs.m1 != rhs.m1 && lhs.m2 != rhs.m2 && lhs.m3 != rhs.m3 && lhs.m4 != rhs.m4 &&
                lhs.m5 != rhs.m5 && lhs.m6 != rhs.m6 && lhs.m7 != rhs.m7 && lhs.m8 != rhs.m8 &&
                lhs.m9 != rhs.m9 && lhs.m10 != rhs.m10 && lhs.m11 != rhs.m11 && lhs.m12 != rhs.m12 &&
                lhs.m13 != rhs.m13 && lhs.m14 != rhs.m14 && lhs.m15 != rhs.m15 && lhs.m16 != rhs.m16;
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
            case 9:
                return m10;
            case 10:
                return m11;
            case 11:
                return m12;
            case 12:
                return m13;
            case 13:
                return m14;
            case 14:
                return m15;
            case 15:
                return m16;
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
            case 9:
                return m10;
            case 10:
                return m11;
            case 11:
                return m12;
            case 12:
                return m13;
            case 13:
                return m14;
            case 14:
                return m15;
            case 15:
                return m16;
            }

            throw;
        }
      
        //matrix4's member functions
        static Matrix4 MakeRotateX(float)
        {
            return {};
        }
        static Matrix4 MakeRotateY(float)
        {
            return {};
        }
        static Matrix4 MakeRotateZ(float)
        {
            return {};
        }

        static Matrix4 MakeScale(float, float, float)
        {
            return {};
        }
        static Matrix4 MakeTranslation(float, float, float)
        {
            return {};
        }

        bool IsApproximatelyEqual(Matrix4 rhs, float epsilon = 1e-4f)const 
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
                std::abs(m9 - rhs.m9),
                std::abs(m10 - rhs.m10),
                std::abs(m11 - rhs.m11),
                std::abs(m12 - rhs.m12),
                std::abs(m13 - rhs.m13),
                std::abs(m14 - rhs.m14),
                std::abs(m15 - rhs.m15),
                std::abs(m16 - rhs.m16)
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

        Vector4 GetRight()
        {
            return {};
        }
        Vector4 GetUp()
        {
            return {};
            
        }
        Vector4 GetForward()
        {
            return {};
        }
        Vector4 GetPosition()
        {
            return {};
        }


    };
}