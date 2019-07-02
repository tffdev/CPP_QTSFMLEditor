/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "tilepicker.h"
#include "tileplacementeditor.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *headerMenu;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QCheckBox *checkBox_2;
    QHBoxLayout *editorMain;
    QWidget *inspectorContainer;
    QVBoxLayout *verticalLayout;
    QTabWidget *inspectorTabWidget;
    QWidget *tabObject;
    QWidget *tabTiles;
    QVBoxLayout *verticalLayout_3;
    QWidget *tabTilesOptions;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_5;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QLabel *label_5;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer;
    QComboBox *comboBox;
    QWidget *tabTilesPickerContainer;
    QGridLayout *gridLayout_3;
    QWidget *tabTilesPickerScrollStopper;
    TilePicker *tabTilesPickerCanvas;
    QScrollBar *tabTilesPickerScrollh;
    QScrollBar *tabTilesPickerScrollv;
    QWidget *tabBackgrounds;
    QWidget *tabSettings;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *settingsRoomName;
    QLabel *label_3;
    QPushButton *pushButton;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_4;
    QCheckBox *checkBox;
    QHBoxLayout *roomEditorContainer;
    TilePlacementEditor *roomEditorCanvas;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(946, 648);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        headerMenu = new QWidget(centralWidget);
        headerMenu->setObjectName(QStringLiteral("headerMenu"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(headerMenu->sizePolicy().hasHeightForWidth());
        headerMenu->setSizePolicy(sizePolicy);
        headerMenu->setMaximumSize(QSize(16777215, 43));
        horizontalLayout = new QHBoxLayout(headerMenu);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(headerMenu);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_3);

        checkBox_2 = new QCheckBox(headerMenu);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setChecked(true);

        horizontalLayout->addWidget(checkBox_2);


        verticalLayout_2->addWidget(headerMenu, 0, Qt::AlignLeft);

        editorMain = new QHBoxLayout();
        editorMain->setSpacing(6);
        editorMain->setObjectName(QStringLiteral("editorMain"));
        inspectorContainer = new QWidget(centralWidget);
        inspectorContainer->setObjectName(QStringLiteral("inspectorContainer"));
        inspectorContainer->setMaximumSize(QSize(270, 16777215));
        verticalLayout = new QVBoxLayout(inspectorContainer);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        inspectorTabWidget = new QTabWidget(inspectorContainer);
        inspectorTabWidget->setObjectName(QStringLiteral("inspectorTabWidget"));
        inspectorTabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabObject = new QWidget();
        tabObject->setObjectName(QStringLiteral("tabObject"));
        inspectorTabWidget->addTab(tabObject, QString());
        tabTiles = new QWidget();
        tabTiles->setObjectName(QStringLiteral("tabTiles"));
        verticalLayout_3 = new QVBoxLayout(tabTiles);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabTilesOptions = new QWidget(tabTiles);
        tabTilesOptions->setObjectName(QStringLiteral("tabTilesOptions"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabTilesOptions->sizePolicy().hasHeightForWidth());
        tabTilesOptions->setSizePolicy(sizePolicy2);
        tabTilesOptions->setMaximumSize(QSize(16777215, 100));
        layoutWidget = new QWidget(tabTilesOptions);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 241, 119));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_2->addWidget(pushButton_5, 3, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        comboBox_2 = new QComboBox(layoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout_2->addWidget(comboBox_2, 2, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_2->addWidget(pushButton_4, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_2->addWidget(comboBox, 0, 1, 1, 1);


        verticalLayout_3->addWidget(tabTilesOptions);

        tabTilesPickerContainer = new QWidget(tabTiles);
        tabTilesPickerContainer->setObjectName(QStringLiteral("tabTilesPickerContainer"));
        gridLayout_3 = new QGridLayout(tabTilesPickerContainer);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        tabTilesPickerScrollStopper = new QWidget(tabTilesPickerContainer);
        tabTilesPickerScrollStopper->setObjectName(QStringLiteral("tabTilesPickerScrollStopper"));
        tabTilesPickerScrollStopper->setStyleSheet(QStringLiteral("background-color: rgb(223, 223, 223)"));

        gridLayout_3->addWidget(tabTilesPickerScrollStopper, 1, 1, 1, 1);

        tabTilesPickerCanvas = new TilePicker(tabTilesPickerContainer);
        tabTilesPickerCanvas->setObjectName(QStringLiteral("tabTilesPickerCanvas"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabTilesPickerCanvas->sizePolicy().hasHeightForWidth());
        tabTilesPickerCanvas->setSizePolicy(sizePolicy3);
        tabTilesPickerCanvas->setMinimumSize(QSize(0, 0));
        tabTilesPickerCanvas->setStyleSheet(QStringLiteral("background-color: red;"));

        gridLayout_3->addWidget(tabTilesPickerCanvas, 0, 0, 1, 1);

        tabTilesPickerScrollh = new QScrollBar(tabTilesPickerContainer);
        tabTilesPickerScrollh->setObjectName(QStringLiteral("tabTilesPickerScrollh"));
        tabTilesPickerScrollh->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(tabTilesPickerScrollh, 1, 0, 1, 1);

        tabTilesPickerScrollv = new QScrollBar(tabTilesPickerContainer);
        tabTilesPickerScrollv->setObjectName(QStringLiteral("tabTilesPickerScrollv"));
        tabTilesPickerScrollv->setOrientation(Qt::Vertical);

        gridLayout_3->addWidget(tabTilesPickerScrollv, 0, 1, 1, 1);


        verticalLayout_3->addWidget(tabTilesPickerContainer);

        inspectorTabWidget->addTab(tabTiles, QString());
        tabBackgrounds = new QWidget();
        tabBackgrounds->setObjectName(QStringLiteral("tabBackgrounds"));
        inspectorTabWidget->addTab(tabBackgrounds, QString());
        tabSettings = new QWidget();
        tabSettings->setObjectName(QStringLiteral("tabSettings"));
        tabSettings->setTabletTracking(false);
        tabSettings->setAcceptDrops(false);
        widget = new QWidget(tabSettings);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 251, 171));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy4);
        widget->setMaximumSize(QSize(16777215, 500));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        settingsRoomName = new QLineEdit(widget);
        settingsRoomName->setObjectName(QStringLiteral("settingsRoomName"));
        settingsRoomName->setMaxLength(50);

        gridLayout->addWidget(settingsRoomName, 0, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 4, 1, 1, 1);

        spinBox_2 = new QSpinBox(widget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(999999999);
        spinBox_2->setValue(240);

        gridLayout->addWidget(spinBox_2, 3, 1, 1, 1);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(999999999);
        spinBox->setValue(320);

        gridLayout->addWidget(spinBox, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 5, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(tabSettings);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 210, 241, 121));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        checkBox = new QCheckBox(tabSettings);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 180, 221, 19));
        checkBox->setChecked(true);
        checkBox->setTristate(false);
        inspectorTabWidget->addTab(tabSettings, QString());

        verticalLayout->addWidget(inspectorTabWidget);


        editorMain->addWidget(inspectorContainer);

        roomEditorContainer = new QHBoxLayout();
        roomEditorContainer->setSpacing(6);
        roomEditorContainer->setObjectName(QStringLiteral("roomEditorContainer"));
        roomEditorContainer->setContentsMargins(-1, 0, -1, -1);
        roomEditorCanvas = new TilePlacementEditor(centralWidget);
        roomEditorCanvas->setObjectName(QStringLiteral("roomEditorCanvas"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(roomEditorCanvas->sizePolicy().hasHeightForWidth());
        roomEditorCanvas->setSizePolicy(sizePolicy5);
        roomEditorCanvas->setStyleSheet(QLatin1String("QWidget {\n"
"	background-color: rgb(143, 143, 143)\n"
"}"));

        roomEditorContainer->addWidget(roomEditorCanvas);


        editorMain->addLayout(roomEditorContainer);


        verticalLayout_2->addLayout(editorMain);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        inspectorTabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Room Editor", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Confirm", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "Show Grid", Q_NULLPTR));
        inspectorTabWidget->setTabText(inspectorTabWidget->indexOf(tabObject), QApplication::translate("MainWindow", "Objects", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "- Delete Layer", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Layer", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Default (0)", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("MainWindow", "Tileset", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "+ New Layer", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "tilesetForest", Q_NULLPTR)
        );
        inspectorTabWidget->setTabText(inspectorTabWidget->indexOf(tabTiles), QApplication::translate("MainWindow", "Tiles", Q_NULLPTR));
        inspectorTabWidget->setTabText(inspectorTabWidget->indexOf(tabBackgrounds), QApplication::translate("MainWindow", "Backgrounds", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", " Name:", Q_NULLPTR));
        settingsRoomName->setInputMask(QString());
        label_3->setText(QApplication::translate("MainWindow", "Height:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Creation Code", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Instance Order", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Width:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Here's some helper text", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Clear Display Buffer with Window Colour ", Q_NULLPTR));
        inspectorTabWidget->setTabText(inspectorTabWidget->indexOf(tabSettings), QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        roomEditorCanvas->setToolTip(QString());
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
