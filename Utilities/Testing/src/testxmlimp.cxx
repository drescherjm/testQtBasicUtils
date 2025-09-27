#include "qbuBase/qbuProperty.h"
#include "qbuCmdLine/QCmdParseError.h"
#include "qbuCmdLine/QCmdParseException.h"
#include "qbuCmdLine/QCmdHelpException.h"
#include "qbuBase/qbuPropertyMap.h"
#include <iostream>
#include <QDate>
#include "testxmlimp.h"



/////////////////////////////////////////////////////////////////////////////////////////

QCmdTestXMLImport::QCmdTestXMLImport(QString strName, QString strDescription) :
	QCmd(strName,strDescription)
{
	int nTest = 0;
	AddArg("Test","Run test #","",nTest);
}

/////////////////////////////////////////////////////////////////////////////////////////

static bool test0()
{
	QString testXML("<xml ty=\"127\"><RMTPatientID>HB016603</RMTPatientID></xml>");
	qbuPropertyMap map;
	bool retVal = map.fromXML(testXML);
	if (retVal) {
		retVal = (map.size() == 1);
	}
	return retVal;
}

/////////////////////////////////////////////////////////////////////////////////////////

int  QCmdTestXMLImport::Execute()
{
	int nTest;

	GetArg("Test",nTest);

	bool bVal;
	switch(nTest) {
	case 0:
		bVal = test0();
		break;
	default:
		bVal = false;
	}

	return bVal ? QCmdParseError::STATUS_OK : QCmdParseError::USER_EXECUTION_ERROR;
}

/////////////////////////////////////////////////////////////////////////////////////////


