#############################################################################
# Makefile for building: BouncingBalls
# Generated by qmake (2.01a) (Qt 4.8.6) on: lun jul 7 10:55:21 2014
# Project:  BouncingBalls.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -o Makefile BouncingBalls.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fstack-protector --param=ssp-buffer-size=4 -grecord-gcc-switches -m64 -mtune=generic -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fstack-protector --param=ssp-buffer-size=4 -grecord-gcc-switches -m64 -mtune=generic -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/lib64/qt4/mkspecs/linux-g++ -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-z,relro
LIBS          = $(SUBLIBS)  -L/usr/lib64 -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = 
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = Ball.cpp \
		Bar.cpp \
		BBController.cpp \
		BBGame.cpp \
		BBGraphicsView.cpp \
		BBWidget.cpp \
		BBWorker.cpp \
		Brick.cpp \
		BrickArea.cpp \
		GameObject.cpp \
		main.cpp \
		ThreadController.cpp \
		ThreadWorker.cpp moc_BBController.cpp \
		moc_BBGraphicsView.cpp \
		moc_BBWidget.cpp \
		moc_BBWorker.cpp \
		moc_ThreadController.cpp \
		moc_ThreadWorker.cpp
OBJECTS       = Ball.o \
		Bar.o \
		BBController.o \
		BBGame.o \
		BBGraphicsView.o \
		BBWidget.o \
		BBWorker.o \
		Brick.o \
		BrickArea.o \
		GameObject.o \
		main.o \
		ThreadController.o \
		ThreadWorker.o \
		moc_BBController.o \
		moc_BBGraphicsView.o \
		moc_BBWidget.o \
		moc_BBWorker.o \
		moc_ThreadController.o \
		moc_ThreadWorker.o
DIST          = /usr/lib64/qt4/mkspecs/common/unix.conf \
		/usr/lib64/qt4/mkspecs/common/linux.conf \
		/usr/lib64/qt4/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt4/mkspecs/common/g++-base.conf \
		/usr/lib64/qt4/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt4/mkspecs/qconfig.pri \
		/usr/lib64/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt4/mkspecs/features/qt_config.prf \
		/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt4/mkspecs/features/default_pre.prf \
		/usr/lib64/qt4/mkspecs/features/release.prf \
		/usr/lib64/qt4/mkspecs/features/default_post.prf \
		/usr/lib64/qt4/mkspecs/features/shared.prf \
		/usr/lib64/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/lib64/qt4/mkspecs/features/warn_on.prf \
		/usr/lib64/qt4/mkspecs/features/qt.prf \
		/usr/lib64/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt4/mkspecs/features/moc.prf \
		/usr/lib64/qt4/mkspecs/features/resources.prf \
		/usr/lib64/qt4/mkspecs/features/uic.prf \
		/usr/lib64/qt4/mkspecs/features/yacc.prf \
		/usr/lib64/qt4/mkspecs/features/lex.prf \
		/usr/lib64/qt4/mkspecs/features/include_source_dir.prf \
		BouncingBalls.pro
QMAKE_TARGET  = BouncingBalls
DESTDIR       = 
TARGET        = BouncingBalls

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: BouncingBalls.pro  /usr/lib64/qt4/mkspecs/linux-g++/qmake.conf /usr/lib64/qt4/mkspecs/common/unix.conf \
		/usr/lib64/qt4/mkspecs/common/linux.conf \
		/usr/lib64/qt4/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt4/mkspecs/common/g++-base.conf \
		/usr/lib64/qt4/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt4/mkspecs/qconfig.pri \
		/usr/lib64/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt4/mkspecs/features/qt_config.prf \
		/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt4/mkspecs/features/default_pre.prf \
		/usr/lib64/qt4/mkspecs/features/release.prf \
		/usr/lib64/qt4/mkspecs/features/default_post.prf \
		/usr/lib64/qt4/mkspecs/features/shared.prf \
		/usr/lib64/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/lib64/qt4/mkspecs/features/warn_on.prf \
		/usr/lib64/qt4/mkspecs/features/qt.prf \
		/usr/lib64/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt4/mkspecs/features/moc.prf \
		/usr/lib64/qt4/mkspecs/features/resources.prf \
		/usr/lib64/qt4/mkspecs/features/uic.prf \
		/usr/lib64/qt4/mkspecs/features/yacc.prf \
		/usr/lib64/qt4/mkspecs/features/lex.prf \
		/usr/lib64/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib64/libQtGui.prl \
		/usr/lib64/libQtCore.prl
	$(QMAKE) -o Makefile BouncingBalls.pro
/usr/lib64/qt4/mkspecs/common/unix.conf:
/usr/lib64/qt4/mkspecs/common/linux.conf:
/usr/lib64/qt4/mkspecs/common/gcc-base.conf:
/usr/lib64/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/lib64/qt4/mkspecs/common/g++-base.conf:
/usr/lib64/qt4/mkspecs/common/g++-unix.conf:
/usr/lib64/qt4/mkspecs/qconfig.pri:
/usr/lib64/qt4/mkspecs/features/qt_functions.prf:
/usr/lib64/qt4/mkspecs/features/qt_config.prf:
/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf:
/usr/lib64/qt4/mkspecs/features/default_pre.prf:
/usr/lib64/qt4/mkspecs/features/release.prf:
/usr/lib64/qt4/mkspecs/features/default_post.prf:
/usr/lib64/qt4/mkspecs/features/shared.prf:
/usr/lib64/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/lib64/qt4/mkspecs/features/warn_on.prf:
/usr/lib64/qt4/mkspecs/features/qt.prf:
/usr/lib64/qt4/mkspecs/features/unix/thread.prf:
/usr/lib64/qt4/mkspecs/features/moc.prf:
/usr/lib64/qt4/mkspecs/features/resources.prf:
/usr/lib64/qt4/mkspecs/features/uic.prf:
/usr/lib64/qt4/mkspecs/features/yacc.prf:
/usr/lib64/qt4/mkspecs/features/lex.prf:
/usr/lib64/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib64/libQtGui.prl:
/usr/lib64/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile BouncingBalls.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/BouncingBalls1.0.0 || $(MKDIR) .tmp/BouncingBalls1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/BouncingBalls1.0.0/ && $(COPY_FILE) --parents Ball.h Bar.h BBController.h BBGame.h BBGraphicsView.h BBWidget.h BBWorker.h Brick.h BrickArea.h GameObject.h ThreadController.h ThreadWorker.h .tmp/BouncingBalls1.0.0/ && $(COPY_FILE) --parents Ball.cpp Bar.cpp BBController.cpp BBGame.cpp BBGraphicsView.cpp BBWidget.cpp BBWorker.cpp Brick.cpp BrickArea.cpp GameObject.cpp main.cpp ThreadController.cpp ThreadWorker.cpp .tmp/BouncingBalls1.0.0/ && (cd `dirname .tmp/BouncingBalls1.0.0` && $(TAR) BouncingBalls1.0.0.tar BouncingBalls1.0.0 && $(COMPRESS) BouncingBalls1.0.0.tar) && $(MOVE) `dirname .tmp/BouncingBalls1.0.0`/BouncingBalls1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/BouncingBalls1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_BBController.cpp moc_BBGraphicsView.cpp moc_BBWidget.cpp moc_BBWorker.cpp moc_ThreadController.cpp moc_ThreadWorker.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_BBController.cpp moc_BBGraphicsView.cpp moc_BBWidget.cpp moc_BBWorker.cpp moc_ThreadController.cpp moc_ThreadWorker.cpp
moc_BBController.cpp: ThreadController.h \
		BBController.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) BBController.h -o moc_BBController.cpp

moc_BBGraphicsView.cpp: BBGraphicsView.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) BBGraphicsView.h -o moc_BBGraphicsView.cpp

moc_BBWidget.cpp: BBWidget.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) BBWidget.h -o moc_BBWidget.cpp

moc_BBWorker.cpp: ThreadWorker.h \
		BBWorker.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) BBWorker.h -o moc_BBWorker.cpp

moc_ThreadController.cpp: ThreadController.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ThreadController.h -o moc_ThreadController.cpp

moc_ThreadWorker.cpp: ThreadWorker.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) ThreadWorker.h -o moc_ThreadWorker.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

Ball.o: Ball.cpp Ball.h \
		GameObject.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Ball.o Ball.cpp

Bar.o: Bar.cpp Bar.h \
		GameObject.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Bar.o Bar.cpp

BBController.o: BBController.cpp BBController.h \
		ThreadController.h \
		Ball.h \
		GameObject.h \
		Bar.h \
		BBGame.h \
		BBWorker.h \
		ThreadWorker.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BBController.o BBController.cpp

BBGame.o: BBGame.cpp BBGame.h \
		BrickArea.h \
		Ball.h \
		GameObject.h \
		Bar.h \
		Brick.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BBGame.o BBGame.cpp

BBGraphicsView.o: BBGraphicsView.cpp BBGraphicsView.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BBGraphicsView.o BBGraphicsView.cpp

BBWidget.o: BBWidget.cpp BBWidget.h \
		BBController.h \
		ThreadController.h \
		ThreadWorker.h \
		GameObject.h \
		BBGraphicsView.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BBWidget.o BBWidget.cpp

BBWorker.o: BBWorker.cpp BBWorker.h \
		ThreadWorker.h \
		GameObject.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BBWorker.o BBWorker.cpp

Brick.o: Brick.cpp Brick.h \
		BrickArea.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Brick.o Brick.cpp

BrickArea.o: BrickArea.cpp BrickArea.h \
		Brick.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BrickArea.o BrickArea.cpp

GameObject.o: GameObject.cpp GameObject.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GameObject.o GameObject.cpp

main.o: main.cpp BBWidget.h \
		BBController.h \
		ThreadController.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

ThreadController.o: ThreadController.cpp ThreadController.h \
		ThreadWorker.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ThreadController.o ThreadController.cpp

ThreadWorker.o: ThreadWorker.cpp ThreadWorker.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ThreadWorker.o ThreadWorker.cpp

moc_BBController.o: moc_BBController.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_BBController.o moc_BBController.cpp

moc_BBGraphicsView.o: moc_BBGraphicsView.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_BBGraphicsView.o moc_BBGraphicsView.cpp

moc_BBWidget.o: moc_BBWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_BBWidget.o moc_BBWidget.cpp

moc_BBWorker.o: moc_BBWorker.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_BBWorker.o moc_BBWorker.cpp

moc_ThreadController.o: moc_ThreadController.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ThreadController.o moc_ThreadController.cpp

moc_ThreadWorker.o: moc_ThreadWorker.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ThreadWorker.o moc_ThreadWorker.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

