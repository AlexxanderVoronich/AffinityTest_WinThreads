#include <qapplication.h>
#include "affinity.h"

int main( int argc, char** argv )
{
	QApplication app( argc, argv );

	AffinityTest *pMainDialog = new AffinityTest;
	pMainDialog->show();
	app.exec();

    int temp = 888;

	delete pMainDialog;
	return 0;
}
