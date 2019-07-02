#ifndef TILEPICKER_H
#define TILEPICKER_H

#include "qsfmlcanvas.h"

class TilePicker : public QSFMLCanvas
{
public:
    TilePicker(QWidget* parent) : QSFMLCanvas(parent) {}
    void setLoadedTilesetSprite(sf::Sprite spr);
    void setRectReference(sf::IntRect* rect_ref);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    void Init();
    void Update();
    void OnResize(int w, int h);

    sf::Sprite loaded_tileset_sprite;
    sf::Vector2i tile_size = {16, 16};
    sf::IntRect* parent_rect_ref;

    // tile area selection
    sf::Rect<int> tile_selection_area = {0, 0, 0, 0};
    bool is_selecting_tile_area = false;
    QPoint tile_selection_position_buffer = {0, 0};
};

#endif // TILEPICKER_H
