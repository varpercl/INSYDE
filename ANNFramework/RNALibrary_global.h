#ifndef RNALIBRARY_GLOBAL_H
#define RNALIBRARY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RNALIBRARY_LIBRARY)
#  define RNALIBRARY_EXPORT Q_DECL_EXPORT
#else
#  define RNALIBRARY_EXPORT Q_DECL_IMPORT
#endif


#endif // RNALIBRARY_GLOBAL_H