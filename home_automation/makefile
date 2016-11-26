# ==========================================
#   Unity Project - A Test Framework for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================

#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OSTYPE),cygwin)
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
elseifeq ($(OSTYPE),msys)
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.exe
elseifeq ($(OS),Windows_NT)
	CLEANUP = del /F /Q
	MKDIR = mkdir
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

UNITY_ROOT=../../tools/Unity
BOOK_ROOT=../../book/code
C_COMPILER=gcc
#export GCOV_PREFIX=./obj

CFLAGS = -std=c99
#CFLAGS += -Wall
#CFLAGS += -Wextra
#CFLAGS += -Werror 
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
CFLAGS += -Wmissing-prototypes
CFLAGS += -Wmissing-declarations
CFLAGS += -DUNITY_FIXTURES
CFLAGS += -g
CFLAGS += -fprofile-arcs
CFLAGS += -ftest-coverage
CFLAGS += -fprofile-dir=./obj

TARGET_BASE1=all_tests
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
SRC_FILES1=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  $(BOOK_ROOT)/mocks/RuntimeErrorStub.c \
  src/LightScheduler.c \
  mocks/LightControllerSpy.c \
  mocks/FakeTimeService.c \
  test/LightSchedulerTest.c \
  test/test_runners/LightSchedulerTest_Runner.c \
  test/test_runners/all_tests.c
INC_DIRS=-Isrc -Imocks -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src \
	 -I$(BOOK_ROOT)/mocks -I$(BOOK_ROOT)/include/util
SYMBOLS=

all: clean default

default:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o ./obj/$(TARGET1)
	valgrind --tool=memcheck --leak-check=full --xml=yes --xml-file=./obj/valgrind_report.xml ./obj/$(TARGET1) -v
	mkdir ./obj/cov
	mv *.gcno ./obj
	lcov -t 'Coverage_Report' -o ./obj/cov/coverage_result.info -c -d ./obj
	genhtml -o ./obj/cov/coverage_report ./obj/cov/coverage_result.info -f -s -legend --function-coverage --branch-coverage
	valgrind --tool=callgrind ./obj/all_tests.out
	#kcachegrind ./obj &


clean:
	$(CLEANUP) $(TARGET1)
	rm -rf ./obj/*

