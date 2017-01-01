#ifndef TRON_MENUWINDOW_H
#define TRON_MENUWINDOW_H


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QtWidgets/QPushButton>
#include "GameWindow.h"

class MenuWindow : public QGraphicsView {
Q_OBJECT
public:
    MenuWindow(QWidget *parent = NULL);

private:

    const QSize SCREEN_SIZE{1000, 500};
    const QSize BUTTON_SIZE{300, 50};

    QPushButton *exitButton;
    QPushButton *startButton;

    QString QPushButtonStyle =
            "QPushButton"
                    "{"
                    "background-color: #C0EAFE;"
                    "color: #000;"
                    "border: 1px solid #293136;"
                    "border-radius: 4px;"
                    "padding: 7.5px 15px;"
                    "font-size: 22px;"
                    "font-family: sans-serif;"
                    "}"
                    "QPushButton:pressed"
                    "{"
                    "background-color: #7490CC;"
                    "}";

private slots:

    void exit();

    void startGame();

};


#endif
