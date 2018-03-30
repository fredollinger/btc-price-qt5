// Copyright (c) 2011-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

#include "exchangerate.h"

ExchangeRate::ExchangeRate(QObject* parent) : QObject(parent)
{
    // netManager is used to fetch paymentrequests given in bitcoin: URIs
    // netManager = new QNetworkAccessManager(this);
}

ExchangeRate::~ExchangeRate()
{
}

void ExchangeRate::initNetManager()
{
}
