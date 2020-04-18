#pragma once
#include "Actor.h"
class Triangle : public Actor
{
public:
	Triangle(QGraphicsScene* scene);
	Triangle(const Triangle& triangle) : Triangle(triangle.scene) {}
	~Triangle() {}
protected:
	void paintNested(QPainter* painter);
private:
	QPolygonF polygon;
};
