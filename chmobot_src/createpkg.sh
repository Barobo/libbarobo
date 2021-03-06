#!/bin/sh
PACKAGE=chbarobo
VERSION=0.1
PKGDIR=$PACKAGE-$VERSION/$PACKAGE

echo Building $PACKAGE-$VERSION.zip ...
rm -rf $PACKAGE-$VERSION
rm -rf $PACKAGE-$VERSION.zip
mkdir -p $PKGDIR
mkdir $PKGDIR/lib
mkdir $PKGDIR/demos
mkdir $PKGDIR/dl
mkdir $PKGDIR/include
mkdir $PKGDIR/docs
cp chmobot.chf $PKGDIR/lib
cp chlinkboti.chf $PKGDIR/lib
cp chlinkbotl.chf $PKGDIR/lib
cp shiftTime.chf $PKGDIR/lib
#cp systemTime.chf $PKGDIR/lib
cp delay.chf $PKGDIR/lib
cp libmobot.dl $PKGDIR/dl/libmobot.dl
cp ../include/mobot.h $PKGDIR/include
cp ../include/linkbot.h $PKGDIR/include
cp ../docs/mobot.pdf $PKGDIR/docs
cp -R ../demos/chdemos/* $PKGDIR/demos
cp Makefile_pkg $PACKAGE-$VERSION/Makefile
cp Readme.txt $PACKAGE-$VERSION
zip -rq $PACKAGE-$VERSION.zip $PACKAGE-$VERSION
