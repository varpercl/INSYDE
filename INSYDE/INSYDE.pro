
TEMPLATE = subdirs

#Esta configurado por defecto
CONFIG += ordered

QMAKE_LINK += /MACHINE:X64

SUBDIRS = \
core \
ann_base \
ec_base \
#ga_base \
ann_gui \
#ga_gui \
ec_gui \
#erp \
gui \