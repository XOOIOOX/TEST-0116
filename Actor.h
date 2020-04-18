#pragma once
#include "Defs.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>

class Actor : public QGraphicsRectItem, QObject
{
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

	double randomSign();
	double speedRandomizer();
	double random();
};
