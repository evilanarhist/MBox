#include <QGraphicsScene>

class MvScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MvScene(QObject *parent = 0);
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void keyPressEvent(QKeyEvent * keyEvent);
private:
    QGraphicsPixmapItem * worker;
    void makeWalls();
    QGraphicsItem * itemCollidesWith(QGraphicsItem * item);
    void placeBox(float x, float y);
    void setBoxes();
};
