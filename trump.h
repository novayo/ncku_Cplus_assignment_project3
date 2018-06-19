#ifndef TRUMP_H
#define TRUMP_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Trump : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Trump();

private slots:
    void moveTrump();

private:
    QTimer* tmrMoveTrump;
    int moveSpeed;
    int rotateSpeed;
};

#endif // TRUMP_H
