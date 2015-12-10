#include <QtServer>
#include "await.h"

void myfiber(QVariant /*x*/)
{
	QTcpSocket s;
	await::connect(&s, "127.0.0.1", 6379);

	await::write(&s, "*1\r\n$4\r\ninfo\r\n");
	QByteArray x = await::read(&s);

	qDebug() << x;
}

int main(int argc, char * argv[])
{
	QCoreApplication app(argc, argv);

	QFiber * fib = new QFiber(myfiber);
	QObject::connect(fib, SIGNAL(done()), &app, SLOT(quit()), Qt::QueuedConnection);
	fib->run();

	return app.exec();
}
