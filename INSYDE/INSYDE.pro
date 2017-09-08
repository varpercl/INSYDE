
TEMPLATE = subdirs

#Esta configurado por defecto
CONFIG += ordered

ann_base.depends = core
ec_base.depeds = core
ann_gui.depends = ann_base
ec_gui.depends = ec_base
gui.depends = ann_gui ec_gui

#QMAKE_LINK += /MACHINE:X64

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
tstool \
anntool

