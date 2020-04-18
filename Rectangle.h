#pragma once
#include "Actor.h"

class Rectangle : public Actor
{
public:
	Rectangle(QGraphicsScene* scene) : Actor(scene) {}
	Rectangle(const Rectangle& rectangle) : Rectangle(rectangle.scene) {}
	~Rectangle() {}

protected:
	void paintNested(QPainter* painter);
};
