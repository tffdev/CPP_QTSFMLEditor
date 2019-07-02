#include "tilepicker.h"
#include <QMouseEvent>
#include "mainroomeditor.h"

void TilePicker::Init() {
}

void TilePicker::Update() {
    /* Get mouse position */
    QPoint mouse = QWidget::mapFromGlobal(QCursor::pos());

    /* Highlight tile area */
    if(is_selecting_tile_area) {
        tile_selection_area.left    = reinterpret_cast<int>(tile_selection_position_buffer.x()/16)*16;
        tile_selection_area.top     = reinterpret_cast<int>(tile_selection_position_buffer.y()/16)*16;
        tile_selection_area.width   = reinterpret_cast<int>(mouse.x()/16)*16 - tile_selection_area.left + 16;
        tile_selection_area.height  = reinterpret_cast<int>(mouse.y()/16)*16 - tile_selection_area.top + 16;
    }

    *parent_rect_ref = tile_selection_area;

    /* Draw background */
    window.clear(sf::Color(0,0,0,255));

    /* Draw currently selected tileset */
    window.draw(loaded_tileset_sprite);

    /* Draw current hovered tile */
    sf::RectangleShape tile_rect;
    tile_rect.setOutlineColor(sf::Color(255,255,255));
    tile_rect.setFillColor(sf::Color(0,0,0,0));
    tile_rect.setOutlineThickness(1.0);
    if(is_selecting_tile_area) {
        tile_rect.setSize(sf::Vector2f(tile_selection_area.width, tile_selection_area.height));
        tile_rect.setPosition(tile_selection_area.left, tile_selection_area.top);
    } else {
        tile_rect.setSize(sf::Vector2f(16, 16));
        tile_rect.setPosition(reinterpret_cast<int>(mouse.x()/16)*16, reinterpret_cast<int>(mouse.y()/16)*16);
    }
    window.draw(tile_rect);

    /* Draw current chosen rectangle */
    sf::RectangleShape selection_rect;
    selection_rect.setSize(sf::Vector2f(tile_selection_area.width, tile_selection_area.height));
    selection_rect.setPosition(tile_selection_area.left, tile_selection_area.top);
    selection_rect.setFillColor(sf::Color(255, 255, 255, 100));
    window.draw(selection_rect);

    window.display();
}

void TilePicker::setLoadedTilesetSprite(sf::Sprite spr) {
    loaded_tileset_sprite = spr;
}

void TilePicker::setRectReference(sf::IntRect* rect_ref) {
    parent_rect_ref = rect_ref;
}

void TilePicker::mousePressEvent(QMouseEvent *event){
    /* On mouse down, start tile area selection, and vice versa */
    if(event->button() == Qt::LeftButton) {
        QPoint mouse = QWidget::mapFromGlobal(QCursor::pos());
        is_selecting_tile_area = true;
        tile_selection_position_buffer = {mouse.x(), mouse.y()};
    }
}

void TilePicker::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton) {
        is_selecting_tile_area = false;
    }
}

void TilePicker::OnResize(int, int) {}
