#include "SimpleRandomRollCall.h"

SimpleRandomRollCall::SimpleRandomRollCall(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.Random, SIGNAL(clicked()), this, SLOT(RamdomAName()));
}
