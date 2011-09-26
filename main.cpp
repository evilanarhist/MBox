#include <QApplication>
#include "mvform.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MvForm * window = new MvForm;
        window->showMaximized();
	return app.exec();
}
