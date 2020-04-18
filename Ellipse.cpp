#include "Ellipse.h"

void Ellipse::paintNested(QPainter* painter)
{
	painter->drawEllipse(rect());
}