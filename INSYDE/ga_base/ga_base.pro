
CONFIG += qt shared

CONFIG(release, debug|release):message("Staring RELEASE build for ga_base sources") #will print
CONFIG(debug, debug|release):message("Staring DEBUG build for ga_base sources") #no print

TARGET = ga_base

TEMPLATE = lib

MOC_DIR = moc
UI_DIR = ui
OBJECTS_DIR = obj
RCC_DIR = res
DESTDIR = ..
