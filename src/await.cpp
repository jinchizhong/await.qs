#include "await.h"

namespace await
{
	void connect(QAbstractSocket * socket, const QString & hostName, quint16 port, 
				 QIODevice::OpenMode openMode, QAbstractSocket::NetworkLayerProtocol protocol)
	{
		socket->connectToHost(hostName, port, openMode, protocol);
		QFiber::wait(socket, SIGNAL(connected()));
	}


	QByteArray read(QIODevice * s)
	{
		if (!s->bytesAvailable())
		{
			QFiber::wait(s, SIGNAL(readyRead()));
		}
		return s->readAll();
	}
	void write(QIODevice * s, const QByteArray & a)
	{
		s->write(a);
	}
}
