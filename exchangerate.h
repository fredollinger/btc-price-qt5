// Copyright (c) 2011-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_EXCHANGERATE_H
#define BITCOIN_QT_EXCHANGERATE_H

#include <QObject>
#include <QList>
#include <QString>

QT_BEGIN_NAMESPACE
class QNetworkAccessManager;
class QNetworkReply;
class QSslError;
QT_END_NAMESPACE

class ExchangeRate : public QObject
{

Q_OBJECT

public:
    ExchangeRate(QObject*);
    virtual ~ExchangeRate(void);
    // Create a request for a certain price.
    // When the price is returned, we will
    // send the signal currentPrice().
    void requestPrice(QString units);

public Q_SLOTS:
    // Signal this when the main window's UI is ready
    // to display payment requests to the user
    void uiReady();

Q_SIGNALS:
    // Emit currentPrice() once we have it.
    // The units are the ones selected by
    // requestPrice().
    void currentPrice(float price);

private slots:
    void netRequestFinished(QNetworkReply*);
    void reportSslErrors(QNetworkReply* reply, const QList<QSslError> &errs);

private:
    QNetworkAccessManager *netManager;
    QString unitOfRequest;

    void fetchRequest(const QUrl& url);
    void initNetManager(void);
};

#endif // BITCOIN_QT_EXCHANGERATE_H
