#include <QtWidgets>
#include "MenuWindow.h"

int main(int argv, char **args) {
    QApplication app(argv, args);

    MenuWindow menuWindow(0);
    menuWindow.show();

    return app.exec();
}