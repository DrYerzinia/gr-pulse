INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_PULSE pulse)

FIND_PATH(
    PULSE_INCLUDE_DIRS
    NAMES pulse/api.h
    HINTS $ENV{PULSE_DIR}/include
        ${PC_PULSE_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    PULSE_LIBRARIES
    NAMES gnuradio-pulse
    HINTS $ENV{PULSE_DIR}/lib
        ${PC_PULSE_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PULSE DEFAULT_MSG PULSE_LIBRARIES PULSE_INCLUDE_DIRS)
MARK_AS_ADVANCED(PULSE_LIBRARIES PULSE_INCLUDE_DIRS)

