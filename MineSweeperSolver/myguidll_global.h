#ifndef MYGUIDLL_GLOBAL_H
#define MYGUIDLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MYGUIDLL_LIBRARY)
#  define MYGUIDLL_EXPORT Q_DECL_EXPORT
#else
#  define MYGUIDLL_EXPORT Q_DECL_IMPORT
#endif

#endif // MYGUIDLL_GLOBAL_H
