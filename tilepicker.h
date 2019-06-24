#ifndef TILEPICKER_H
#define TILEPICKER_H

#include "qsfmlcanvas.h"

class TilePicker : public QSFMLCanvas
{
public:
    TilePicker(QWidget* parent) : QSFMLCanvas(parent) {}
private:
    void Init();
    void Update();
    void OnResize(int w, int h);

    sf::Texture loaded_tileset;
    sf::Sprite loaded_tileset_sprite;
    sf::Vector2i tile_size = {16, 16};

    // tile area selection
    sf::Rect<int> tile_selection_area = {0, 0, 0, 0};
    bool is_selecting_tile_area = false;
    QPoint tile_selection_position_buffer = {0, 0};
};

#endif // TILEPICKER_H
