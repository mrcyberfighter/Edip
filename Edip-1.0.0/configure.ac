#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([Edip], [1.0.0], [mrcyberfighter@gmail.com], [Edip-1.0.0], [http://www.open-source-projects.net/Edip/Edip_presentation.html] )

: ${CXXFLAGS=""}

AC_CONFIG_SRCDIR([./Edip/Edip_functions.cpp])
AC_CONFIG_HEADERS([config.h])



# Checks for programs.
AC_PROG_CXX
AC_PROG_RANLIB
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_MKDIR_P
AC_PROG_LN_S

AC_PATH_PROG([CHMOD], [chmod])
AC_PATH_PROG([CP], [cp])
AC_PATH_PROG([RM], [rm])
AC_PATH_PROG([DESKTOP_FILE_INSTALL], [desktop-file-install])
AC_PATH_PROG([LDCONFIG], [ldconfig])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T


# Checks for libraries.
PKG_CHECK_MODULES([GTKMM], [gtkmm-3.0])

# Checks for library functions.
AC_CHECK_FUNCS([pow realpath sqrt])

AC_CONFIG_FILES([Makefile
                 Edip/Makefile
                 Edip/libedip/Makefile
                 testcv/Makefile
                 opencv3/Makefile])
AC_OUTPUT

echo \
"********************************************************************************

${PACKAGE_NAME} Version ${PACKAGE_VERSION}
Prefix: ${prefix}
Compiler: ${CXX} ${CXXFLAGS} ${CPPFLAGS}
Depends: gtkmm3 opencv-3.0.0

You can launch the program with the commandline:
$ Edip
or
$ edip # if your system support symbolic links.

or with the icon from your desktop menu.

************************** opencv-3.0.0 required !!! ***************************

Now install opencv-3.0.0 if you don't already get it installed.

Because Edip required this library in this version.
OpenCV coming from your packages manager is often precompiled with
GTK2 support and not GTK3 support, so uncompatible with Edip.

If you get opencv-3.0.0 installed and you are not sure,
try to launch the test program by typing:

  $ make test

If this fail you can install the opencv-3.0.0 version shipped with
Edip by typing:

  $ make opencv3 # An internet connection is required.

  $ sudo make install-opencv3 # Install opencv-3.0.0

What will add a library to your system and the only case it can disturb you is
if you want to write an application using GTK2 and opencv.

********************************************************************************

If everything OKAY you can type:

  $ make              # Build all binaries

  $ sudo make install # Install Micro Music Player.

********************************************************************************

Available targets:

$ make                    # Build all binaries.

$ make install            # Install the program.

$ make install-strip      # Install the program stripped.

$ make uninstall          # Uninstall the program.

$ make clean              # Clean generated files.

$ make test               # Perform a test to sea if opencv can work with GTK3.

$ make opencv3            # cmake opencv-3.0.0

$ make install-opencv3    # Install opencv-3.0.0

$ make uninstall-opencv3  # Uninstall opencv-3.0.0

**************************** Enjoy to use Edip !!! *****************************"