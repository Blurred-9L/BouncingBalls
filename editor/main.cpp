#include <QApplication>
#include "BBEditorWindow.h"
#include "BBEditorWidget.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    BBEditorWindow window;
    
    window.setAttribute(Qt::WA_QuitOnClose);
    window.show();
    
    app.exec();
    
    return 0;
}
