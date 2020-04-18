#include "TEST0116.h"
#include "Ellipse.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Image.h"

TEST0116::TEST0116(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	view = ui.graphicsView;
	installEventFilter(this);

	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

	scene = new QGraphicsScene(0, 0, 600, 600, this);
	view->setScene(scene);

	for (size_t i = 0; i < MaxItems; ++i)
	{
		switch ((Shapes::Shape)(rand() % 4))
		{
			case Shapes::Rectangle:
			{
				actorsVector.push_back(std::make_shared<Rectangle>(scene));
				break;
			}
			case Shapes::Ellipse:
			{
				actorsVector.push_back(std::make_shared<Ellipse>(scene));
				break;
			}
			case Shapes::Triangle:
			{
				actorsVector.push_back(std::make_shared<Triangle>(scene));
				break;
			}
			case Shapes::Image:
			{
				actorsVector.push_back(std::make_shared<Image>(scene));
				break;
			}
			default:
			{
				break;
			}
		}
	}

	animationTimer = new QTimer(this);
	connect(animationTimer, SIGNAL(timeout()), scene, SLOT(advance()));
	animationTimer->start(1000 / AinmationFps);
}