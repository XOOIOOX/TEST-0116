#include "Triangle.h"

Triangle::Triangle(QGraphicsScene* scene) : Actor(scene)
{
	polygon = QVector<QPointF>{ QPointF{ rect().width() / 2.0, 0.0 }, QPointF{ rect().width(), rect().height() }, QPointF{ 0.0, rect().height() } };
}

void Triangle::paintNested(QPainter* painter)
{
	painter->drawPolygon(polygon);
}