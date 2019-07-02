#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExpValidator>
#include <QRegExp>
#include <SFML/Graphics.hpp>

namespace Ui {
class MainWindow;
}

class MainRoomEditor : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainRoomEditor(QWidget *parent = nullptr);
    ~MainRoomEditor();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private slots:
    void on_checkBox_2_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    sf::Texture loaded_tileset_texture;
    sf::Sprite loaded_tileset_sprite;
    sf::IntRect tile_selection_area;
};

#endif // MAINWINDOW_H
