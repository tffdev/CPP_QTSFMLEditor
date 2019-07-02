#include "tileplacementeditor.h"
#include <QMouseEvent>
#include "keyboardinput.h"
#define SCROLL_THRESHOLD 40

void TilePlacementEditor::Init() {
    if(!tex_checkered_background.loadFromFile("./resources/bg.png"))
        printf("cant load ./resources/bg.png\n");
    tex_checkered_background.setRepeated(true);
    spr_checkered_background.setTexture(tex_checkered_background);
    spr_checkered_background.setTextureRect(sf::IntRect(0,0,QWidget::width(), QWidget::height()));

    /* in future, will be set to preferred defaults */
    room_size.x = 320;
    room_size.y = 240;
    camera_position.x = 0;
    camera_position.y = 0;
}

void TilePlacementEditor::Update() {
    /* Get mouse position */
    QPoint mouse = QWidget::mapFromGlobal(QCursor::pos());

    /* Move room around */
    if(dragging_room) {
        camera_position.x += mouse.x() - drag_mouse_position_buffer.x;
        camera_position.y += mouse.y() - drag_mouse_position_buffer.y;
        drag_mouse_position_buffer.x = mouse.x();
        drag_mouse_position_buffer.y = mouse.y();
    }

    /* Clear + Draw checkered background */
    window.clear(sf::Color(0,0,0,255));
    window.draw(spr_checkered_background);

    /* Draw room boundaries */
    sf::RectangleShape roomRect;
    roomRect.setSize(sf::Vector2f(room_size.x*camera_scale, room_size.y*camera_scale));
    roomRect.setFillColor(sf::Color(0, 0, 0)); // TODO: replace this with user-defined window color
    roomRect.setPosition(camera_position.x, camera_position.y);
    window.draw(roomRect);


    /* Draw current tile selection */
    sf::Sprite spr;
    spr.setPosition(static_cast<int>((mouse.x()-camera_position.x) / (16*camera_scale))*(16*camera_scale) + camera_position.x,
                    static_cast<int>((mouse.y()-camera_position.y) / (16*camera_scale))*(16*camera_scale) + camera_position.y);
    spr.setTexture(loaded_tileset_texture);
    spr.setScale(camera_scale, camera_scale);
    spr.setTextureRect(*parent_rect_ref);
    spr.setColor(sf::Color(255,255,255,200));
    window.draw(spr);

    /* Draw all tiles */
    for(sf::Sprite tile : tiles) {
        sf::Sprite spr(tile);
        spr.setScale(camera_scale, camera_scale);
        spr.setPosition(camera_position.x + tile.getPosition().x*camera_scale,
                        camera_position.y + tile.getPosition().y*camera_scale);
        window.draw(spr);
    }

    /* Draw tile grid */
    if(grid_shown) {
        for (int i = 0; i < room_size.y; i += 16) {
            sf::RectangleShape line(sf::Vector2f(room_size.x*camera_scale, 1));
            line.setFillColor(sf::Color(255,255,255,100));
            line.setPosition(camera_position.x, camera_position.y + i*camera_scale);
            window.draw(line);
        }
        for (int i = 0; i < room_size.x; i += 16) {
            sf::RectangleShape line(sf::Vector2f(1, room_size.y*camera_scale));
            line.setFillColor(sf::Color(255,255,255,100));
            line.setPosition(camera_position.x + i*camera_scale, camera_position.y);
            window.draw(line);
        }
    }

    /* Present room to user */
    window.display();
}

void TilePlacementEditor::setLoadedTilesetTexture(sf::Texture tex) {
    loaded_tileset_texture = tex;
}

void TilePlacementEditor::OnResize(int, int) {
    spr_checkered_background.setTextureRect(sf::IntRect(0,0,QWidget::width(), QWidget::height()));
}

void TilePlacementEditor::setGridShown(bool state) {
    grid_shown = state;
}

void TilePlacementEditor::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton && KeyboardInput::keyIsPressed(Qt::Key_Space)) {
        QPoint mouse = QWidget::mapFromGlobal(QCursor::pos());
        dragging_room = true;
        drag_mouse_position_buffer.x = mouse.x();
        drag_mouse_position_buffer.y = mouse.y();
        return;
    }
    if(event->button() == Qt::LeftButton) {
        // place tile!
        QPoint mouse = QWidget::mapFromGlobal(QCursor::pos());

        sf::Sprite new_tile;
        new_tile.setTexture(loaded_tileset_texture);
        new_tile.setPosition(static_cast<int>((mouse.x()-camera_position.x) / (16*camera_scale))*(16),
                             static_cast<int>((mouse.y()-camera_position.y) / (16*camera_scale))*(16));
        new_tile.setTextureRect(*parent_rect_ref);
        tiles.emplace_back(new_tile);
    }
}

void TilePlacementEditor::mouseReleaseEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        dragging_room = false;
    }
}

void TilePlacementEditor::setRectReference(sf::IntRect* rect_ref) {
    parent_rect_ref = rect_ref;
}

/*
 * Scales the room size up or down depending on mouse scroll input.
 * TODO: Let scroll zooming origin be mouse position, not top left of room boundaries.
 */
void TilePlacementEditor::wheelEvent(QWheelEvent *event) {
    QPoint angle = event->angleDelta();
    if(angle.y() > SCROLL_THRESHOLD) camera_scale = camera_scale * 0.9f - 0.01f;
    if(angle.y() < -SCROLL_THRESHOLD) camera_scale = camera_scale * 1.1f + 0.01f;
    if(camera_scale < 0.01f) camera_scale = 0.01f;
}
