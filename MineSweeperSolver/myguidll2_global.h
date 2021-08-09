#ifndef MYGUIDLL2_GLOBAL_H
#define MYGUIDLL2_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MYGUIDLL2_LIBRARY)
#  define MYGUIDLL2_EXPORT Q_DECL_EXPORT
#else
#  define MYGUIDLL2_EXPORT Q_DECL_IMPORT
#endif

#endif // MYGUIDLL2_GLOBAL_H
