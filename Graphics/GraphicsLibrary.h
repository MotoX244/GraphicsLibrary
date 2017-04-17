#pragma once

#ifdef _WIN32
#  ifdef GRAPHICS_EXPORTS
#    define GRAPHICS_LIBRARY __declspec(dllexport)
#  else
#    define GRAPHICS_LIBRARY __declspec(dllimport)
#  endif
#else
#  define GRAPHICS_LIBRARY
#endif
