#include "BBWidget.h"
#include "BBController.h"
#include <QApplication>

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    BBController controller(480, 640);
    BBWidget window(controller);
    
    window.setAttribute(Qt::WA_QuitOnClose);
    window.show();
    controller.startThreads();
    
    app.exec();
    
    return 0;
}
