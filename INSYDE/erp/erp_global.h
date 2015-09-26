#ifndef ERP_GLOBAL_H
#define ERP_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ERP_LIBRARY)
#  define ERPSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ERPSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ERP_GLOBAL_H
