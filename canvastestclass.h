#ifndef QSFMLCANVASTEST_H
#define QSFMLCANVASTEST_H

#include "qsfmlcanvas.h"
#include <vector>

typedef struct {
    int x, y;
    int texture_x, texture_y, texture_w, texture_h;
    sf::Sprite sprite;
} Tile;

class CanvasTestClass : public QSFMLCanvas
{
public:
    CanvasTestClass(QWidget* parent) : QSFMLCanvas(parent) {}

private:
    void Init();
    void Update();
    void OnResize(int w, int h);

    sf::Texture tex;
    sf::Texture texture_background;
    sf::Sprite sprite_background;
    sf::Sprite spr;

    sf::Vector2i room_size;
    sf::Vector2f camera_position;
    float camera_scale = 1.0f;
    bool dragging_room = false;
    sf::Vector2i drag_mouse_position_buffer;
    std::vector<Tile> tiles;
};

#endif // QSFMLCANVASTEST_H
