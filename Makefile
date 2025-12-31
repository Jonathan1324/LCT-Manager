ifndef OS_NAME
$(error OS_NAME is not set. Must be one of: windows, macos, linux)
endif

ifndef ARCH
$(error ARCH is not set. Must be one of: x86_64, arm64)
endif

include scripts/config.mk
include scripts/os.mk

SRC_DIR = src
DIST_DIR = dist

ifeq ($(DEBUG),1)
	BUILD_DIR = build/debug
else
	BUILD_DIR = build/release
endif

SRC_DIR := $(shell pwd)/$(SRC_DIR)
BUILD_DIR := $(shell pwd)/$(BUILD_DIR)
BIN_DIR = $(BUILD_DIR)
LIB_DIR = $(BUILD_DIR)/lib

LDFLAGSSRC = -L$(LIB_DIR) -lrust

.PHONE: all clean

all: lct librust

lct: librust
	@$(MAKE) -C $(SRC_DIR)/lct 				\
		DEBUG=$(DEBUG)						\
											\
		CC=$(CC) CFLAGS="$(CFLAGS)" 		\
		CXX=$(CXX) CXXFLAGS="$(CXXFLAGS)"	\
		AR=$(AR) ARFLAGS=$(ARFLAGS)			\
		LDFLAGS="$(LDFLAGSSRC) $(LDFLAGS)"	\
		STRIPFLAGS="$(STRIPFLAGS)"			\
		RANLIB=$(RANLIB)					\
		SRC_DIR=$(SRC_DIR)/lct 				\
		LIB_DIR=$(LIB_DIR)					\
		LIB=core							\
		BUILD_DIR=$(BUILD_DIR)/lct			\
		BIN_DIR=$(BIN_DIR)

librust:
	@$(MAKE) -C $(SRC_DIR)/rust				\
		DEBUG=$(DEBUG)						\
											\
		RUSTFLAGS="$(RUSTFLAGS)"			\
		RUSTLIBFLAGS="$(RUSTLIBFLAGS)"		\
		RUST_TARGET="$(RUST_TARGET)"		\
		SRC_DIR=$(SRC_DIR)/rust 			\
		LIB_DIR=$(LIB_DIR)					\
		STRIPFLAGS="$(STRIPFLAGS)"			\
		LIB=rust							\
		BUILD_DIR=$(BUILD_DIR)/rust			\
		BIN_DIR=$(BIN_DIR)

clean:
	@rm -rf $(BUILD_DIR)
