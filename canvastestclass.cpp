#include "canvastestclass.h"

void CanvasTestClass::Init() {
    tex.loadFromFile("resources/test.png");
    texture_background.loadFromFile("resources/bg.png");
    texture_background.setRepeated(true);
    sprite_background.setTexture(texture_background);
    sprite_background.setTextureRect(sf::IntRect(0,0,QWidget::width(), QWidget::height()));

    /* in future, will be set to preferred defaults */
    room_size.x = 320;
    room_size.y = 240;
    camera_position.x = 0;
    camera_position.y = 0;
}

void CanvasTestClass::Update() {
    /* Get mouse position */
    QPoint mouse = QWidget::mapFromGlobal(QCursor::pos());

    /*
     * Event loop that handles input when the mouse is over the SFML widget.
     * Scales the room size up or down depending on mouse scroll input.
     *
     * TODO: Let scroll zooming origin be mouse position, not top left of room boundaries.
     */
    sf::Event event;
    while(window.pollEvent(event)) {
        if(event.type == sf::Event::MouseWheelMoved) {
            if(event.mouseWheel.delta == -1) camera_scale = camera_scale*0.9f - 0.01f;
            if(event.mouseWheel.delta == 1)  camera_scale = camera_scale*1.1f + 0.01f;
            if(camera_scale < 0.01f) camera_scale = 0.01f;
        } else if(event.type == sf::Event::MouseButtonPressed) {
            if(event.mouseButton.button == sf::Mouse::Button::Left && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                dragging_room = true;

                sf::Cursor cursor;
                cursor.loadFromSystem(sf::Cursor::Hand);
                window.setMouseCursor(cursor);

                drag_mouse_position_buffer.x = mouse.x();
                drag_mouse_position_buffer.y = mouse.y();
            }
        } else if(event.type == sf::Event::MouseButtonReleased) {
            if(event.mouseButton.button == sf::Mouse::Button::Left) {
                dragging_room = false;
                sf::Cursor cursor;
                cursor.loadFromSystem(sf::Cursor::Arrow);
                window.setMouseCursor(cursor);
            }
        }
    }

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

    /* Present room to user */
    window.display();
}

void CanvasTestClass::OnResize(int, int) {
    sprite_background.setTextureRect(sf::IntRect(0,0,QWidget::width(), QWidget::height()));
}
