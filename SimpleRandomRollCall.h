#pragma once

#include <QWidget>
#include "ui_SimpleRandomRollCall.h"

class SimpleRandomRollCall : public QWidget
{
	Q_OBJECT

public:
	SimpleRandomRollCall(QWidget* parent = Q_NULLPTR);

private:
	Ui::SimpleRandomRollCallClass ui;
private slots:
	void RamdomAName();
	void ChangeText();
	void Stop() { ui.Random->setEnabled(true); };

};
