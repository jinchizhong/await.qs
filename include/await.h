#ifndef QS_REDIS_REDIS_H
#define QS_REDIS_REDIS_H

#include <QtServer>

namespace await 
{
	// QAbstractSocket
	void connect(QAbstractSocket * socket, const QString & hostName, quint16 port, 
				 QIODevice::OpenMode openMode = QIODevice::ReadWrite, 
				 QAbstractSocket::NetworkLayerProtocol protocol = QAbstractSocket::AnyIPProtocol);

	// QIODevice
	QByteArray read(QIODevice * s);
	void write(QIODevice * s, const QByteArray & a);
}

#endif
