#ifndef UTIL_RENDER_HPP
#define UTIL_RENDER_HPP

void drawTextCentered(const char *text, const struct Vector2 &position, float fontSize, const struct Color &color);

void drawTextureCentered(const struct Texture &texture, const struct Vector2 &position, const struct Vector2 &size, float rotation, const struct Color &color);
void drawRectCentered(const struct Vector2 &position, const struct Vector2 &size, const struct Color &color);
void drawTriangleCentered(const struct Vector2 &position, float size, const struct Color &color);

#endif
