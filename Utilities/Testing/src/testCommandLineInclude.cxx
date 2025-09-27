#include "testCommandLineInclude.h"
#include "qbuCmdLine/QCmdParseError.h"
#include "qbuCmdLine/QCmdLine.h"
#include <QFile>
#include <iostream>

/////////////////////////////////////////////////////////////////////////////////////////

QCmdTestCmdLineFileInclude::QCmdTestCmdLineFileInclude( QString strName, QString strDescription ) : 
	QCmd(strName,strDescription)
{
	int nTest =0;
	AddOpt("test","Test Number","The test to run",nTest);
}

/////////////////////////////////////////////////////////////////////////////////////////

int QCmdTestCmdLineFileInclude::Execute()
{
	int nTest;
	int retVal = GetOpt("test",nTest);
	if (QCmdParseError::Succeeded(retVal)) {
		retVal = runTest(nTest);
	}
	return retVal;
}

/////////////////////////////////////////////////////////////////////////////////////////

int QCmdTestCmdLineFileInclude::runTest( int nTest )
{
	int retVal = QCmdParseError::STATUS_OK;
	switch(nTest) {
	case ALL_TESTS:
		for(int i=1;i < NUM_TESTS;++i) {
			retVal = runTest(i);
			if (!QCmdParseError::Succeeded(retVal)) {
				break;
			}
		}
		break;
	case DOUBLE_QUOTES_1:
		retVal = runTest_DoubleQuotes_1();
		break;
	default:
		retVal = QCmdParseError::NOT_IMPLEMENTED;
		break;
	}

	if (!QCmdParseError::Succeeded(retVal)) {
		if (nTest > ALL_TESTS) {
			std::cerr << "ERROR: QCmdTestCmdLineFileInclude test #" << nTest << " failed." << std::endl;
		}
		
	}
	return retVal;
}

/////////////////////////////////////////////////////////////////////////////////////////

int QCmdTestCmdLineFileInclude::runTest_DoubleQuotes_1()
{
	int retVal = writeTestFile("DoubleQuotes1.txt","+CMD1 --var1=\"John Drescher\" --var2=\"Kathy Drescher\"");
	if (QCmdParseError::Succeeded(retVal)) {

	}
	//QCmdLine		myCmdLine("dbdev0",lst);

	return retVal;
}

/////////////////////////////////////////////////////////////////////////////////////////

bool QCmdTestCmdLineFileInclude::writeTestFile( QString strFileName, QString strMsg )
{
	QFile file(strFileName);
	bool retVal = file.open(QFile::WriteOnly|QFile::Text|QFile::Truncate);
	if (retVal) {
		QTextStream stream(&file);
		stream << strMsg;
	}

	return retVal;
}

/////////////////////////////////////////////////////////////////////////////////////////
