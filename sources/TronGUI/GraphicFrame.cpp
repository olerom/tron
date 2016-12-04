#include "GraphicFrame.h"

GraphicFrame::GraphicFrame(QWidget *parent) {
    setFrameStyle(QFrame::Panel);
    setFocusPolicy(Qt::StrongFocus);

    QPixmap background(":/grid.jpg");
    QPalette qPalette;
    qPalette.setBrush(this->backgroundRole(), QBrush(background));
    this->setAutoFillBackground(true);
    this->setPalette(qPalette);

    game = new shogi::Shogi();
    game->load();
}
