#ifndef QSFMLCANVASTEST_H
#define QSFMLCANVASTEST_H

#include "qsfmlcanvas.h"
#include <vector>
#include <QWheelEvent>

class TilePlacementEditor : public QSFMLCanvas
{
public:
    TilePlacementEditor(QWidget* parent) : QSFMLCanvas(parent) {}
    void setGridShown(bool state);
    void setLoadedTilesetTexture(sf::Texture tex);
    void setRectReference(sf::IntRect* rect_ref);
protected:
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    void Init();
    void Update();
    void OnResize(int w, int h);


    // Canvas background
    sf::Texture tex_checkered_background;
    sf::Sprite spr_checkered_background;

    // Loaded tileset texture
    sf::Texture loaded_tileset_texture;
    sf::IntRect* parent_rect_ref;

    // Camera and meta
    sf::Vector2i room_size;
    sf::Vector2f camera_position;
    float camera_scale = 1.0f;
    bool dragging_room = false;
    sf::Vector2i drag_mouse_position_buffer;

    std::vector<sf::Sprite> tiles;
    bool grid_shown = true;
};

#endif // QSFMLCANVASTEST_H
