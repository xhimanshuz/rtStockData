QT += core widgets network

HEADERS += \
    rtstockmainwindow.h \
    rtStockBackend/rtstockbackend.h \
    rtStockBlock/rtstockblock.h \
    rtStockSearch/rtstocksearch.h

SOURCES += \
    main.cpp \
    rtstockmainwindow.cpp \
    rtStockBackend/rtstockbackend.cpp \
    rtStockBlock/rtstockblock.cpp \
    rtStockSearch/rtstocksearch.cpp

DESTDIR = $$PWD/../../rtStockViewer
