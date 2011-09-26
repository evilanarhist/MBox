#include "mvscene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QtCore>

MvScene::MvScene(QObject *parent) : QGraphicsScene(parent)
{
	makeWalls();
	setBoxes();
	worker = addPixmap(QPixmap("Worker.gif"));
	worker->translate(25.5, 25.5);
	worker->setData(0, "Worker");
	setBackgroundBrush(QBrush(QColor(255,255,255), QPixmap("bg.jpg")));
}

void MvScene::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
	if (mouseEvent->button() == Qt::LeftButton) 
		placeBox(mouseEvent->scenePos().x(), mouseEvent->scenePos().y());
	if (mouseEvent->button() == Qt::RightButton) {
		QGraphicsItem * item = itemAt(mouseEvent->scenePos());
		if (item)
			if (item->data(0) == "Box")
				removeItem(item);
	}
			
}

void MvScene::keyPressEvent(QKeyEvent * keyEvent)
{
	QPointF np;
	np.setX(0);
	np.setY(0);
	switch (keyEvent->key()) {
		case Qt::Key_Left:
			np.setX(-10);
			break;
		case Qt::Key_Right:
			np.setX(10);
			break;
		case Qt::Key_Up:
			np.setY(-10);
			break;
		case Qt::Key_Down:
			np.setY(10);
			break;
	}
	worker->translate(np.x(), np.y());
	QGraphicsItem * obstacle = itemCollidesWith(worker);
	if (obstacle) {
		if (obstacle->data(0) == "Wall") {	
			worker->translate(-np.x(), -np.y());
			printf("Hello wall!\n");
		}
		else
		if (obstacle->data(0) == "Box") {
			obstacle->translate(np.x(), np.y());
			if (itemCollidesWith(obstacle) || itemCollidesWith(worker)) {
				obstacle->translate(-np.x(), -np.y());
				worker->translate(-np.x(), -np.y());
				printf("Cannot move!\n");
			}
		}

	}
	
}

void MvScene::makeWalls()
{
	float walls[11][4] = {{0, 0, 25, 245}, {25, 0, 425, 25}, {425, 0, 25, 245}, {25, 220, 400, 25}, {25, 60, 75, 25}, {100, 60, 25, 95}, {50, 120, 25, 25}, {175, 60, 25, 100}, {225, 90, 125, 25}, {275, 190, 25, 30}, {325, 115, 25, 30}};
	QBrush brush(QColor(255, 255, 255), QPixmap("wall.jpg"));
	QPen pen(Qt::NoPen);
	for (int i = 0; i < 11; i++) {
		QGraphicsItem * item =
		addRect(QRectF(walls[i][0], walls[i][1], walls[i][2], walls[i][3]), pen, brush);
		item->setData(0, "Wall");
	}
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

void MvScene::placeBox(float x, float y) 
{
	QGraphicsItem *	box = addPixmap(QPixmap("box.gif"));
	box->translate(x, y);
	if (itemCollidesWith(box))
		removeItem(box);
	else
		box->setData(0, "Box");
}

void MvScene::setBoxes()
{
	float boxes[6][2] = {{78, 120}, {180, 165}, {205, 60}, {285, 170}, {130, 100}, {330, 65}};
	for (int i = 0; i < 6; i++)
		placeBox(boxes[i][0], boxes[i][1]);
}
