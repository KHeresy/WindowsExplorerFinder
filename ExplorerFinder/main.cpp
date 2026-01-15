#include "QExplorerFinder.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QExplorerFinder window;
    
    QStringList args = QCoreApplication::arguments();
    if (args.count() > 1) {
        window.setTargetPath(args[1]);
        window.setWindowTitle("Finding in: " + args[1]);
    }

    window.show();
    return app.exec();
}
