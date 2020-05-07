#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TEST0116.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <vector>
#include "Actor.h"


class TEST0116 : public QMainWindow
{
	Q_OBJECT

public:
	TEST0116(QWidget* parent = Q_NULLPTR);

private:
	Ui::TEST0116Class ui;
	QGraphicsView* view;
	QGraphicsScene* scene;
	QTimer* animationTimer;
	QTimer* modificationTimer;
	bool modifiacationDirection{ false };

	void itemsGenerator();
	std::vector<std::shared_ptr<Actor>> actorsVector;

public slots:
	void modificationObjectSlot();
};
