#ifndef GRAPHICS_CONTEXT_H
#define GRAPHICS_CONTEXT_H

#include "PlsIncludes.h"

namespace PlsEngine {
        class GraphicsContext {
        public:
                virtual void Init() = 0;
                virtual void SwapBuffers() = 0;
        };
}

#endif
