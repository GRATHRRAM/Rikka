#pragma once
#include <cstdint>
#include <algorithm>

class Color {
public:
    uint8_t r, g, b, a;

    Color() : r(0), g(0), b(0), a(255) {}
    Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
        : r(red), g(green), b(blue), a(alpha) {}

    static Color FromNormalized(float red, float green, float blue, float alpha = 1.0f) {
        return Color(
            static_cast<uint8_t>(Clamp01(red) * 255.0f),
            static_cast<uint8_t>(Clamp01(green) * 255.0f),
            static_cast<uint8_t>(Clamp01(blue) * 255.0f),
            static_cast<uint8_t>(Clamp01(alpha) * 255.0f)
        );
    }

    float fr() const { return r / 255.0f; }
    float fg() const { return g / 255.0f; }
    float fb() const { return b / 255.0f; }
    float fa() const { return a / 255.0f; }

    void SetNormalized(float red, float green, float blue, float alpha = 1.0f) {
        r = static_cast<uint8_t>(Clamp01(red) * 255.0f);
        g = static_cast<uint8_t>(Clamp01(green) * 255.0f);
        b = static_cast<uint8_t>(Clamp01(blue) * 255.0f);
        a = static_cast<uint8_t>(Clamp01(alpha) * 255.0f);
    }

private:
    static float Clamp01(float value) {
        return std::max(0.0f, std::min(1.0f, value));
    }
};

