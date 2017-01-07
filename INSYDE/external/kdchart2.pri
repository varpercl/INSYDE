win32:{

	CONFIG(release, debug|release):{#RELEASE

		contains(QMAKE_TARGET.arch, x86): {

			LIBS += -L$$PWD/../external/kdchart-2.5.1-source-win/lib/x86/ -lkdchart2 \
		}

		contains(QMAKE_TARGET.arch, x86_64): {
#			QMAKE_LFLAGS += /MACHINE:X64
			LIBS += -L$$PWD/../external/kdchart-2.5.1-source-win/lib/x64/ -lkdchart2 \
		}

	}else:{ #DEBUG

		contains(QMAKE_TARGET.arch, x86): {
			LIBS += -L$$PWD/../external/kdchart-2.5.1-source-win/lib/x86/ -lkdchartd2 \
		}
		contains(QMAKE_TARGET.arch, x86_64): {
#			QMAKE_LFLAGS += /MACHINE:X64
			LIBS += -L$$PWD/../external/kdchart-2.5.1-source-win/lib/x64/ -lkdchartd2 \
		}
	}

	INCLUDEPATH += $$PWD/../external/kdchart-2.5.1-source-win/include
	DEPENDPATH += $$PWD/../external/kdchart-2.5.1-source-win/include

}
