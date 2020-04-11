#include "TEST0116.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	srand(static_cast<unsigned int>(time(0)));
	QApplication a(argc, argv);
	TEST0116 w;
	w.show();
	return a.exec();
}
