#ifndef __CMDTESTFLOATOPTS_H__
#define __CMDTESTFLOATOPTS_H__

#include "qbuCmdLine/QCmd.h"

/////////////////////////////////////////////////////////////////////////////////////////

class QCmdTestFloatOpts : public QCmd
{
public:
	QCmdTestFloatOpts(QString strName, QString strDescription);
	virtual int Execute();
public:
	enum Test {
		AllTests=0,
		TempExample=1,
		NUM_TESTS
	};
protected:
	int	runTest(int nTest);
};

/////////////////////////////////////////////////////////////////////////////////////////

#endif // __CMDTESTFLOATOPTS_H__

