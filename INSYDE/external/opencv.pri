win32:{

OPENCV_STANDALONE = YES

OPENCV_PATH = "C:/OpenCV/3.2.0"

#	CONFIG(release, debug|release):{ #RELEASE

#       if x86
#		contains(QMAKE_TARGET.arch, x86): {

#			LIBS += -L$$PWD/../external/opencv/build/x64/vc14/bin/ -lopencv_world320 \
#					-L$$PWD/../external/opencv/build/x64/vc14/bin/ -lopencv_ffmpeg320_64 \
#					-L$$PWD/../external/opencv/build/x64/vc14/bin/ -lopencv_face320
#		}
#       if x64
#		contains(QMAKE_TARGET.arch, x86_64): {


#                        QMAKE_LFLAGS += /MACHINE:X64
    equals(OPENCV_STANDALONE, "YES") :{

        LIBS += -L$${OPENCV_PATH}/x64/vc14/bin/ -lopencv_core320 \
#            -L$${OPENCV_PATH}/x64/vc14/bin/ -lopencv_ffmpeg320 \
            -L$${OPENCV_PATH}/x64/vc14/bin/ -lopencv_imgproc320 \
            -L$${OPENCV_PATH}/x64/vc14/bin/ -lopencv_video320 \
            -L$${OPENCV_PATH}/x64/vc14/bin/ -lopencv_face320 \

        INCLUDEPATH += $${OPENCV_PATH}/include
        DEPENDPATH += $${OPENCV_PATH}/include
#        message($$INCLUDEPATH)
    }
    else:{
#        message("NOT_STANDALONE")
        LIBS += -L$$PWD/../external/opencv/build/x64/vc14/bin/ -lopencv_core320 \
            -L$$PWD/../external/opencv/build/x64/vc14/bin/ -lopencv_ffmpeg320_64 \
            -L$$PWD/../external/opencv/build/x64/vc14/bin/ -lopencv_face320 \

        INCLUDEPATH += $$PWD/../external/opencv/build/include
        DEPENDPATH += $$PWD/../external/opencv/build/include
    }


#		}
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

#message($$INCLUDEPATH);
}
