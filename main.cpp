#include "main.h"
QVector<QString> v;
int l;

void ReadFile(QVector<QString>& v) {
	QFile file("SNL.txt");
	if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QTextStream t(&file);
		while (!t.atEnd())
		{
			v << t.readLine();
		}
	}
	else {
		QMessageBox::critical(NULL, "Critical", "The file is occupied");
	}
}

void SimpleRandomRollCall::ChangeText() {
	ui.Name->setText(v[QRandomGenerator::global()->bounded(l - 1)]);
}


void SimpleRandomRollCall::RamdomAName() {
	ui.Random->setDisabled(true);
	ui.Random->setText("Again");


	for (int i = 1; i <= 9; i++) {
		QTimer::singleShot(100 * i, Qt::PreciseTimer, this, SLOT(ChangeText()));
	}

	QTimer::singleShot(1000, Qt::PreciseTimer, this, SLOT(Stop()));
}










int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	SimpleRandomRollCall w;
	w.show();
	if (!QFile::exists("SNL.txt"))
	{
		QMessageBox::critical(NULL, "Critical", "You need to create a file named SNL.txt in the current directory and write the student names, separated by new lines.");
		a.exit();
	}

	ReadFile(v);
	//qDebug() << v;
	l = v.count();






	return a.exec();
}
