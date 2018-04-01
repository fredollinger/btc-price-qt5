// Copyright (c) 2011-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <QApplication>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

#include "exchangerate.h"

int main( int argc, char **argv )
{
    QApplication a( argc, argv );
    ExchangeRate er(nullptr);
    er.uiReady();

    return a.exec();
}
