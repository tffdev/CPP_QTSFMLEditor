#include "tileplacementeditor.h"
#include <QMouseEvent>
#include "keyboardinput.h"
#define SCROLL_THRESHOLD 40

void TilePlacementEditor::Init() {
    if(!texture_background.loadFromFile("./resources/bg.png"))
        printf("cant load ./resources/bg.png\n");
    texture_background.setRepeated(true);
    sprite_background.setTexture(texture_background);
    sprite_background.setTextureRect(sf::IntRect(0,0,QWidget::width(), QWidget::height()));

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
    window.draw(sprite_background);

    /* Draw room boundaries */
    sf::RectangleShape roomRect;
    roomRect.setSize(sf::Vector2f(room_size.x*camera_scale, room_size.y*camera_scale));
    roomRect.setFillColor(sf::Color(0, 0, 0)); // TODO: replace this with user-defined window color
    roomRect.setPosition(camera_position.x, camera_position.y);
    window.draw(roomRect);


    /* Draw all tiles */


    /* Draw tile grid */
    if(grid_shown) {
        for (int i = 0; i < room_size.y; i += 16) {
            sf::RectangleShape line(sf::Vector2f(room_size.x*camera_scale, 1));
            line.setFillColor(sf::Color(145,145,145));
            line.setPosition(camera_position.x, camera_position.y + i*camera_scale);
            window.draw(line);
        }
        for (int i = 0; i < room_size.x; i += 16) {
            sf::RectangleShape line(sf::Vector2f(1, room_size.y*camera_scale));
            line.setFillColor(sf::Color(145,145,145));
            line.setPosition(camera_position.x + i*camera_scale, camera_position.y);
            window.draw(line);
        }
    }

    /* Present room to user */
    window.display();
}

void TilePlacementEditor::OnResize(int, int) {
    sprite_background.setTextureRect(sf::IntRect(0,0,QWidget::width(), QWidget::height()));
}

void TilePlacementEditor::setGridShown(bool state) {
    grid_shown = state;
}

void TilePlacementEditor::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton && KeyboardInput::keyIsPressed(Qt::Key_Space)) {
        dragging_room = true;
        QPoint mouse = QWidget::mapFromGlobal(QCursor::pos());
        drag_mouse_position_buffer.x = mouse.x();
        drag_mouse_position_buffer.y = mouse.y();
    }
}

void TilePlacementEditor::mouseReleaseEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        dragging_room = false;
    }
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
