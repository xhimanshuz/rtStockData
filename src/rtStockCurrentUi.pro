QT += core widgets network

HEADERS += \
    rtstockmainwindow.h \
    rtStockBackend/rtstockbackend.h \
    rtStockBlock/rtstockblock.h

SOURCES += \
    main.cpp \
    rtstockmainwindow.cpp \
    rtStockBackend/rtstockbackend.cpp \
    rtStockBlock/rtstockblock.cpp

DESTDIR = $$PWD/../../build
