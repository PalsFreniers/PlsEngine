//
// Created by tidian on 18/09/22.
//

#ifndef PLSENGINE_CORE_H
#define PLSENGINE_CORE_H

#ifdef PLSENGINE_WINDOW_BUILD_SHARED
#   define PLSEXPORT dllExport;
#else
#   ifdef PLSENGINE_WINODW_BUILD_SANDBOX
#       define PLSEXPORT dllImport
#   else
#       define PLSEXPORT 
#   endif
#endif

#define BIT(x) (1 << x)

#endif //PLSENGINE_CORE_H
