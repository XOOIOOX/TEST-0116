#include "TEST0116.h"
#include "Ellipse.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Image.h"
#include <iostream>

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

	animationTimer = new QTimer(this);
	connect(animationTimer, SIGNAL(timeout()), scene, SLOT(advance()));
	animationTimer->start(1000 / AinmationFps);

	modificationTimer = new QTimer(this);
	connect(modificationTimer, SIGNAL(timeout()), this, SLOT(modificationObjectSlot()));
	modificationTimer->start(DeleteAfterMs);
}

void TEST0116::itemsGenerator()
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

	connect(actorsVector.back().get(), SIGNAL(beepSignal()), this, SLOT(beepSlot()));
}

void TEST0116::modificationObjectSlot()
{
	if (!modifiacationDirection)
	{
		if (!actorsVector.empty()) { actorsVector.erase(actorsVector.end() - 1); }
		else { modifiacationDirection = true; }
	}
	else
	{
		if (actorsVector.size() < MaxItems) { itemsGenerator(); }
		else { modifiacationDirection = false; }
	}
}

void TEST0116::beepSlot()
{
	std::cout << "Beep\nBeeep\nBeeeep" << std::endl;
}