#include <QApplication>
#include <QMainWindow>

int main(int argc, char **argv){

    QApplication app(argc, argv);

    QMainWindow mainWindow;

    mainWindow.setFixedSize(1600, 900);
    mainWindow.show();

    return QApplication::exec();
}
