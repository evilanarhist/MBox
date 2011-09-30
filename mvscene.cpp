#include "mvscene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QtCore>

MvScene::MvScene(QObject *parent) : QGraphicsScene(parent)
{
        ball = addPixmap(QPixmap("ball.png"));
	worker = addPixmap(QPixmap("Worker.gif"));
        //worker->translate(0, 0);
        ball->translate(-50,-50);
	worker->setData(0, "Worker");
        //ball->setData(0, "ball");
        QColor color;
        double f =4;
        color.setRgbF(0.88, 0.88, 0.88, 1.0);
            setBackgroundBrush(QBrush(color));
}

QGraphicsItem * MvScene::itemCollidesWith(QGraphicsItem * item)
{
	QList<QGraphicsItem *> collisions = collidingItems(item);
	foreach (QGraphicsItem * it, collisions) {
        	if (it == item)
        	     continue;
		return it;
 	}
	return NULL;
}

