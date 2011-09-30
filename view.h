
#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
class View : public QGraphicsView
{
public:
    View(QGraphicsScene *scene) : QGraphicsView(scene) { }
    View(QWidget *scene) : QGraphicsView(scene) { }

protected:
    void resizeEvent(QResizeEvent *event)
    {
        QGraphicsView::resizeEvent(event);
        fitInView(sceneRect(), Qt::KeepAspectRatio);
        const double factor = 0.88;
        scale(factor, factor);
    }
};

#endif // VIEW_H
