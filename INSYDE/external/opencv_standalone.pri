win32:{

#	CONFIG(release, debug|release):{ #RELEASE

#       if x86
		contains(QMAKE_TARGET.arch, x86): {

			LIBS += -L$$PWD/../external/opencv/build/x64/vc14/bin/ -lopencv_world320 \
					-L$$PWD/../external/opencv/build/x64/vc14/bin/ -lopencv_ffmpeg320_64 \
					-L$$PWD/../external/opencv/build/x64/vc14/bin/ -lopencv_face320
		}
#       if x64
		contains(QMAKE_TARGET.arch, x86_64): {

			QMAKE_LFLAGS += /MACHINE:X64
			LIBS += -L$$PWD/../external/opencv/build/x64/vc14/bin/ -lopencv_world320 \
					-L$$PWD/../external/opencv/build/x64/vc14/bin/ -lopencv_ffmpeg320_64 \
					-L$$PWD/../external/opencv/build/x64/vc14/bin/ -lopencv_face320


		}
#	}else:{ #DEBUG

##       if x86
#		contains(QMAKE_TARGET.arch, x86):{
#			LIBS += -L$$PWD/../external/opencv/build/x64/vc14/bin/ -ltbb_debug \
#		}
##       if x64
#		contains(QMAKE_TARGET.arch, x86_64):{
#			QMAKE_LFLAGS += /MACHINE:X64
#			LIBS += -L$$PWD/../external/opencv/build/x64/vc14/bin/ -ltbb_debug \
#		}

#	}
	INCLUDEPATH += $$PWD/../external/opencv/build/include
	DEPENDPATH += $$PWD/../external/opencv/build/include

#message($$INCLUDEPATH);
}
