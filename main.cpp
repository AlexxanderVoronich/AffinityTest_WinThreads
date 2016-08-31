#include <qapplication.h>
#include "affinity.h"
//#include "iostream.h"

int main( int argc, char** argv )
{
	QApplication app( argc, argv );

	AffinityTest *pMainDialog = new AffinityTest;
	pMainDialog->show();
	app.exec();

	delete pMainDialog;
	return 0;
}
