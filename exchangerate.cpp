// Copyright (c) 2011-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

#include "exchangerate.h"

ExchangeRate::ExchangeRate(QObject* parent) :
QObject(parent),
netManager(0)
{
    // netManager is used to fetch paymentrequests given in bitcoin: URIs
    // netManager = new QNetworkAccessManager(this);
}

ExchangeRate::~ExchangeRate()
{
    if (netManager)
    {
        delete netManager;
    }
}

void ExchangeRate::initNetManager()
{
    // netManager is used to fetch bitcoin conversion information: URIs
    netManager = new QNetworkAccessManager(this);

    connect(netManager, SIGNAL(finished(QNetworkReply*)),
        this, SLOT(netRequestFinished(QNetworkReply*)));
    connect(netManager, SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError> &)),
        this, SLOT(reportSslErrors(QNetworkReply*, const QList<QSslError> &)));
}

void ExchangeRate::netRequestFinished(QNetworkReply* reply)
{
    reply->deleteLater();
}

void ExchangeRate::reportSslErrors(QNetworkReply* reply, const QList<QSslError> &errs)
{
    Q_UNUSED(reply);
}

void ExchangeRate::fetchRequest(const QUrl& url)
{
    netManager->get(QNetworkRequest(QUrl(url)));
}
