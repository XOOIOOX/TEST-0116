#pragma once
#include "Defs.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include "QTimer"

class Actor : public QObject, public QGraphicsRectItem
{
	Q_OBJECT

public:
	Actor(QGraphicsScene* scene);
	Actor(const Actor& actor) : Actor(actor.scene) {}
	virtual ~Actor();

	virtual void advance(int phase);
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr);

protected:
	QGraphicsScene* scene;
	virtual void paintNested(QPainter* painter) = 0;

private:
	QPointF delta{ DeltaPosMax, DeltaPosMax };
	QPointF direction{ randomSign(), randomSign() };
	double rotationDelta{ RotationStep * randomSign() };
	QPainter painter;
	QBrush brush;
	QPen pen;
	double opacity{ 1.0 };
	double opacityDirection{ OpacityStep };

	QTimer* beepTimer;

	double randomSign();
	double speedRandomizer();
	double random();

public slots:
	void timerSlot();

signals:
	void beepSignal();
};
