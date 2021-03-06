// Copyright 2011 The Emscripten Authors.  All rights reserved.
// Emscripten is available under two separate licenses, the MIT license and the
// University of Illinois/NCSA Open Source License.  Both these licenses can be
// found in the LICENSE file.

#include <QtTest/QtTest>

#include <poppler-qt4.h>

class TestPageLayout: public QObject
{
    Q_OBJECT
private slots:
    void checkNone();
    void checkSingle();
    void checkFacing();
};

void TestPageLayout::checkNone()
{
    Poppler::Document *doc;
    doc = Poppler::Document::load("../../../test/unittestcases/UseNone.pdf");
    QVERIFY( doc );
  
    QCOMPARE( doc->pageLayout(), Poppler::Document::NoLayout );

    delete doc;
}

void TestPageLayout::checkSingle()
{
    Poppler::Document *doc;
    doc = Poppler::Document::load("../../../test/unittestcases/FullScreen.pdf");
    QVERIFY( doc );
  
    QCOMPARE( doc->pageLayout(), Poppler::Document::SinglePage );

    delete doc;
}

void TestPageLayout::checkFacing()
{
    Poppler::Document *doc;
    doc = Poppler::Document::load("../../../test/unittestcases/doublepage.pdf");
    QVERIFY( doc );

    QCOMPARE( doc->pageLayout(), Poppler::Document::TwoPageRight );

    delete doc;
}

QTEST_MAIN(TestPageLayout)
#include "check_pagelayout.moc"

