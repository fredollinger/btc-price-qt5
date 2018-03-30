// Copyright (c) 2011-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_EXCHANGERATE_H
#define BITCOIN_QT_EXCHANGERATE_H

#include <QObject>

class QNetworkAccessManager;

class ExchangeRate : public QObject
{

Q_OBJECT

public:
    ExchangeRate(QObject*);
    virtual ~ExchangeRate(void);

private:
    QNetworkAccessManager *netManager;
    void initNetManager(void);
};

#endif // BITCOIN_QT_EXCHANGERATE_H
