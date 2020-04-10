#pragma once
#include "Defs.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>

class Actor : public QGraphicsRectItem, QObject
{
public:

	Actor(QGraphicsScene* scene);
	Actor(const Actor& actor);

	virtual void advance(int phase);
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr);

private:
	QGraphicsScene* scene;
	QPointF delta{ DeltaPosMax, DeltaPosMax };
	QPointF direction{ randomSign(), randomSign() };
	double rotationDelta{ RotationStep * randomSign() };

	QPainter painter;
	QBrush brush;
	QPen pen;
	Shape shape{ Rectangle };
	QPolygonF polygon;
	QPixmap pixmap;
	double opacity{ 1.0 };
	double opacityDirection{ OpacityStep };

	double randomSign();
	double speedRandomizer();
	double random();
};
