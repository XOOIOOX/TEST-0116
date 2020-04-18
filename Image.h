#pragma once
#include "Actor.h"

class Image : public Actor
{
public:
	Image(QGraphicsScene* scene);
	Image(const Image& image) : Image(image.scene) {}
	~Image() {};

protected:
	void paintNested(QPainter* painter);

private:
	QPixmap pixmap;
};
