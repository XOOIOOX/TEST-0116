#include "Image.h"

Image::Image(QGraphicsScene* scene) : Actor(scene)
{
	pixmap = QPixmap(":/Resources/covid19.png");
}

void Image::paintNested(QPainter* painter)
{
	painter->drawPixmap(rect().toRect(), pixmap);
}