#include "Rectangle.h"

void Rectangle::paintNested(QPainter* painter)
{
	painter->drawRect(rect());
}