#include <QGraphicsScene>

class MvScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MvScene(QObject *parent = 0);
private:
    QGraphicsPixmapItem *worker;
    QGraphicsPixmapItem *ball;
    QGraphicsItem * itemCollidesWith(QGraphicsItem * item);

};
