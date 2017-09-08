win32:{

	CONFIG(release, debug|release):{ #RELEASE

#       if x86
		contains(QMAKE_TARGET.arch, x86): {

			LIBS += -L$$PWD/../external/tbb44_20160128oss_win_0/lib/ia32/vc14/ -ltbb \
		}
#       if x64
		contains(QMAKE_TARGET.arch, x86_64): {

			QMAKE_LFLAGS += /MACHINE:X64
			LIBS += -L$$PWD/../external/tbb44_20160128oss_win_0/lib/intel64/vc14/ -ltbb \
		}
	}else:{ #DEBUG

#       if x86
		contains(QMAKE_TARGET.arch, x86):{
			LIBS += -L$$PWD/../external/tbb44_20160128oss_win_0/lib/ia32/vc14/ -ltbb_debug \
		}
#       if x64
		contains(QMAKE_TARGET.arch, x86_64):{
			QMAKE_LFLAGS += /MACHINE:X64
			LIBS += -L$$PWD/../external/tbb44_20160128oss_win_0/lib/intel64/vc14/ -ltbb_debug \
		}

	}
	INCLUDEPATH += $$PWD/../external/tbb44_20160128oss_win_0/include
	DEPENDPATH += $$PWD/../external/tbb44_20160128oss_win_0/include

}

unix{
    LIBS += -L$$PWD/../external/tbb42_20140416oss_lin/bin/intel64/gcc4.4/ -ltbb \
            -L$$PWD/../external/tbb42_20140416oss_lin/lib/intel64/gcc4.4/ -ltbb

    INCLUDEPATH += $$PWD/../external/tbb42_20140416oss_lin/include
    DEPENDPATH += $$PWD/../external/tbb42_20140416oss_lin/include
}
