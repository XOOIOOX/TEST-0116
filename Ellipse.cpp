#include "Ellipse.h"

Ellipse::Ellipse(QGraphicsScene* scene) : Actor(scene)
{}

Ellipse::Ellipse(const Ellipse& ellipse) : Ellipse(ellipse.scene)
{}

Ellipse::~Ellipse()
{}

void Ellipse::paintNested(QPainter* painter)
{
	painter->drawEllipse(rect());
}