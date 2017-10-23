win32:{

    contains(QMAKE_TARGET.arch, x86): {

            LIBS += -L$$PWD/../external/kdchart-2.5.1-source-win/lib/x86/vc14/ -lkdchart2
    }

    contains(QMAKE_TARGET.arch, x86_64):{
            QMAKE_LFLAGS += /MACHINE:X64
            LIBS += -L$$PWD/../external/kdchart-2.5.1-source-win/lib/x64/vc14/ -lkdchart2
    }

    INCLUDEPATH += $$PWD/../external/kdchart-2.5.1-source-win/include
    DEPENDPATH += $$PWD/../external/kdchart-2.5.1-source-win/include

}
unix:{

    LIBS += -L$$PWD/../external/kdchart-2.5.1-source-linux/lib/release/ -lkdchart

    INCLUDEPATH += $$PWD/../external/kdchart-2.5.1-source-linux/include
    DEPENDPATH += $$PWD/../external/kdchart-2.5.1-source-linux/include
}
