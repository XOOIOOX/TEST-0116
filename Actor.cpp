#include "Actor.h"

Actor::Actor(QGraphicsScene* scene) : QGraphicsRectItem(nullptr), scene(scene)
{
	setRect(QRectF{ 0.0, 0.0, random() * (MaxSize - MinSize) + MinSize, random() * (MaxSize - MinSize) + MinSize });
	setPos(QPointF{ random() * (scene->width() - this->rect().width()), random() * (scene->height() - this->rect().height()) });
	setTransformOriginPoint({ rect().size().width() / 2.0, rect().size().height() / 2.0 });

	delta = { speedRandomizer() * randomSign(), speedRandomizer() * randomSign() };
	brush = { QColor{ rand() % 255, rand() % 255, rand() % 255 }, Qt::SolidPattern };
	pen = { Qt::NoPen };
	opacity = random();

	beepTimer = new QTimer(this);
	beepTimer->start(1000);
	connect(beepTimer, SIGNAL(timeout()), this, SLOT(timerSlot()));

	this->scene->addItem(this);
}

Actor::~Actor()
{
	scene->removeItem(this);
}

void Actor::advance(int phase)
{
	if (phase)
	{
		auto position = pos();

		if (position.x() < scene->sceneRect().left() || position.x() > (scene->sceneRect().right() - rect().width()))
		{
			direction.rx() = -direction.x();
			delta.rx() *= direction.x();
			rotationDelta *= randomSign();
		}

		if (position.y() < scene->sceneRect().top() || position.y() > (scene->sceneRect().bottom() - rect().height()))
		{
			direction.ry() = -direction.y();
			delta.ry() *= direction.y();
			rotationDelta *= randomSign();
		}

		setRotation(rotation() + rotationDelta);
		position += delta;
		setPos(position);

		if (opacity + opacityDirection > 1.0 || opacity + opacityDirection < 0.0)
		{
			opacityDirection = -opacityDirection;
		}
		opacity += opacityDirection;
	}
}

void Actor::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget /*= nullptr*/)
{
	painter->setBrush(brush);
	painter->setPen(pen);
	painter->setOpacity(opacity);
	paintNested(painter);
}

double Actor::randomSign() { return rand() % 2 ? 1.0 : -1.0; }
double Actor::speedRandomizer() { return random() * (DeltaPosMax - DeltaPosMin) + DeltaPosMin; }
double Actor::random() { return (double)rand() / RAND_MAX; }

void Actor::timerSlot()
{
	emit beepSignal();
}