#include "mainroomeditor.h"
#include "ui_mainwindow.h"
#include "keyboardinput.h"

MainRoomEditor::MainRoomEditor(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    /* Only allow room name to be alphanumeric inc. underscore, starting with letter */
    ui->settingsRoomName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z][A-Za-z0-9_]+")));

    // Load tileset, for now we'll hardcode the values until we get it all working
    printf("Setting texture and sprite\n");
    loaded_tileset_texture.loadFromFile("./resources/Tileset.png");
    loaded_tileset_sprite.setTexture(loaded_tileset_texture);

    // Pass tileset to children
    ui->roomEditorCanvas->setLoadedTilesetTexture(loaded_tileset_texture);
    ui->roomEditorCanvas->setRectReference(&tile_selection_area);
    ui->tabTilesPickerCanvas->setLoadedTilesetSprite(loaded_tileset_sprite);
    ui->tabTilesPickerCanvas->setRectReference(&tile_selection_area);
}

MainRoomEditor::~MainRoomEditor() {
    delete ui;
}

void MainRoomEditor::on_checkBox_2_stateChanged(int state)
{
    printf("state: %i\n", state);
    ui->roomEditorCanvas->setGridShown((state==2) ? true : false);
}

void MainRoomEditor::keyPressEvent(QKeyEvent *event) {
    int keycode = event->key();
    KeyboardInput::setKey(keycode, true);
}

void MainRoomEditor::keyReleaseEvent(QKeyEvent *event){
    int keycode = event->key();
     KeyboardInput::setKey(keycode, false);
}
