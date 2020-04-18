#pragma once
#include "Actor.h"
class Ellipse : public Actor
{
public:
	Ellipse(QGraphicsScene* scene);
	Ellipse(const Ellipse& ellipse);
	~Ellipse();
protected:
	void paintNested(QPainter* painter);
};
