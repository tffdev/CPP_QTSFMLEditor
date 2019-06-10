#ifndef QSFMLCANVAS_H
#define QSFMLCANVAS_H
#include <QWidget>
#include <QTimer>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Cursor.hpp>

#define FRAME_RATE 60
#define MS_PER_FRAME 1000/FRAME_RATE

class QSFMLCanvas : public QWidget, public sf::RenderWindow
{
public :
    QSFMLCanvas(QWidget* parent);
    virtual ~QSFMLCanvas();

protected:
    sf::RenderWindow window;

private:
    /* To be overridden by child classes */
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void OnResize(int w, int h) = 0;

    void resizeEvent(QResizeEvent* event);
    void paintEvent(QPaintEvent*);
    void showEvent(QShowEvent*);
    QPaintEngine* paintEngine() const;

    QTimer frameTimer;
};

#endif // QSFMLCANVAS_H
