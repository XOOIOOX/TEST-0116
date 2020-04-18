#pragma once
#include "Actor.h"
class Ellipse : public Actor
{
public:
	Ellipse(QGraphicsScene* scene) : Actor(scene) {}
	Ellipse(const Ellipse& ellipse) : Ellipse(ellipse.scene) {}
	~Ellipse() {}

protected:
	void paintNested(QPainter* painter);
};
