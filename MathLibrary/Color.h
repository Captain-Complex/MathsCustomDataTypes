#pragma once

namespace MathLibrary
{
    struct Color
    {
        //color's public field
    public:
        unsigned int rgba;
        
        //color's constructors
        Color() 
        {
            rgba = 255;
        }
        Color::Color()
        {

        }
        Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
        {
            rgba = 0;
            rgba = rgba | (static_cast<unsigned int>(r) << 24);
            rgba = rgba | (static_cast<unsigned int>(g) << 16);
            rgba = rgba | (static_cast<unsigned int>(b) << 8);
            rgba = rgba | (static_cast<unsigned int>(a) << 0);
        }
        //color's operators
        bool operator == (Color& C)
        {
            return rgba == C.rgba;
        }
        //color's functions/methods
        unsigned char GetRed()
        {
            unsigned char gotRed = static_cast<unsigned char>(rgba >> 24);
            return gotRed;
        }
        void SetRed(unsigned char redValue)
        {
            rgba = rgba & ~(0x000000FF << 24);
            rgba = rgba | (static_cast<unsigned int>(redValue) << 24);
        }
        unsigned char GetGreen()
        {
            unsigned char gotGreen = static_cast<unsigned char>(rgba >> 16);
            return gotGreen;
        }
        void SetGreen(unsigned char greenValue)
        {
            rgba = rgba & ~(0x000000FF << 16);
            rgba = rgba | (static_cast<unsigned int>(greenValue) << 16);
        }
        unsigned char GetBlue()
        {
            unsigned char gotBlue = static_cast<unsigned char>(rgba >> 8);
            return gotBlue;
        }
        void SetBlue(unsigned char blueValue)
        {
            rgba = rgba & ~(0x000000FF << 8);
            rgba = rgba | (static_cast<unsigned int>(blueValue) << 8);
        }
        unsigned char GetAlpha()
        {
            unsigned char gotAlpha = static_cast<unsigned char>(rgba >> 0);
            return gotAlpha;
        }
        void SetAlpha(unsigned char alphaValue)
        {
            rgba = rgba & ~(0x000000FF << 0);
            rgba = rgba | (static_cast<unsigned int>(alphaValue) << 0);
        }
    };
}