#include "mvscene.h"
#include "mvform.h"


MvForm::MvForm(QWidget *parent):QMainWindow(parent)
{
	setupUi(this);
        setWindowTitle(trUtf8("Yellow"));
	scene = new MvScene;
        graphicsView->setScene(scene);
        //double factor = 0.3;
        //graphicsView->scale(factor, factor);
}
