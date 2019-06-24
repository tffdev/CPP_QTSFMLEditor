#include "qsfmlcanvas.h"

/*
 * Initialisation
 * ~> Allow screen to be painted on
 * ~> Set size and position
 * ~> Set timer interval
 * NoSystemBackground attr is set so there's no conflict
 * in rendering, causing flickering.
 */
QSFMLCanvas::QSFMLCanvas(QWidget* parent) : QWidget(parent) {
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);
    setFocusPolicy(Qt::StrongFocus);
    /* frameTimer will send signal timeout() every 60th of a second, connect to "repaint" */
    frameTimer.setInterval(MS_PER_FRAME);
    window.setActive(false);
}

void QSFMLCanvas::resizeEvent(QResizeEvent*) {
    createWindow();
    OnResize(reinterpret_cast<int>(QWidget::width()), reinterpret_cast<int>(QWidget::height()));
}

void QSFMLCanvas::createWindow() {
    window.setActive(false);
    printf("Creating SFML window with ID %i\n", winId());
    window.create(reinterpret_cast<sf::WindowHandle>(winId()));
}

void QSFMLCanvas::showEvent(QShowEvent*) {
    Init();
    connect(&frameTimer, SIGNAL(timeout()), this, SLOT(repaint()));
    frameTimer.start();
}

QSFMLCanvas::~QSFMLCanvas() {}

/* Override default system paint engine to remove flickering */
QPaintEngine* QSFMLCanvas::paintEngine() const {
    return reinterpret_cast<QPaintEngine*>(0);
}

void QSFMLCanvas::paintEvent(QPaintEvent*) {
    Update();
    display();
}
