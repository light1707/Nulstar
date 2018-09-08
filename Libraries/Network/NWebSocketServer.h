#ifndef NWEBSOCKETSERVER_H
#define NWEBSOCKETSERVER_H

#include <QHostAddress>
#include <QObject>
#include <QWebSocketServer>
#include "Network.h"

QT_FORWARD_DECLARE_CLASS(QWebSocket)

namespace NulstarNS {
  class NETWORKSHARED_EXPORT NWebSocketServer : public QWebSocketServer {
    Q_OBJECT

    public:
      explicit NWebSocketServer(const QString& lName, const QString& lLabel, SslMode lSslMode, QObject* rParent = nullptr);
      virtual ~NWebSocketServer();

      bool fListen(const QHostAddress& lAddress = QHostAddress::Null, quint16 lPort = 0);
      QString fName() { return mName; }
      void fSetName(const QString& lName);
      void fSetPort(quint16 lPort);
      void fSetBindAddress(const QHostAddress& lBindAddress);

    private:
      quint16 mPort;
      QString mName;
      QHostAddress mBindAddress;
      QList<QWebSocket* > mConnections;
      bool listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 0) { return QWebSocketServer::listen(address, port); }
      void setServerName(const QString& serverName) { QWebSocketServer::setServerName(serverName); }

    private Q_SLOTS:
      void fOnNewConnection();
      void fProcessTextMessage(QString lMessage);
      void fProcessBinaryMessage(QByteArray lMessage);
      void fSocketDisconnected();
  };
}

#endif // NNULSTARWEBSOCKETSERVER_H
