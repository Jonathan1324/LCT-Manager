TARGET = $(LIB_DIR)/lib$(LIB).a
R_TARGET = $(BUILD_DIR)/$(RUST_TARGET)/release/liblct_download.a
RUST_SRCS = $(shell find $(SRC_DIR) -name '*.rs' | sed "s|$(SRC_DIR)/||")

.PHONY: all clean

all: $(TARGET) record

$(TARGET): $(RUST_SRCS)
	@echo "Compiling Rust source " $@
	@mkdir -p $(BUILD_DIR)
	@RUSTFLAGS="$(RUSTFLAGS)" \
	  CARGO_TARGET_DIR="$(BUILD_DIR)" \
	  cargo build --release --target=$(RUST_TARGET) --manifest-path=$(SRC_DIR)/Cargo.toml
	@mkdir -p $(LIB_DIR)
	@cp "$(R_TARGET)" "$(TARGET)"
#	@rustc $(RUSTFLAGS) --target=$(RUST_TARGET) $(SRC_DIR)/main.rs $(RUSTLDFLAGS) -o $@
#	Rust just uses one file and modules inside of it

record:
	@mkdir -p $(BUILD_DIR)
	@cargo license --do-not-bundle \
		| grep -v "linked-assembly-buildtool" \
		> $(BUILD_DIR)/LICENSES.txt
	@echo $(BUILD_DIR)/LICENSES.txt >> $(BIN_DIR)/licenses.txt

clean:
	@rm -rf $(BUILD_DIR)
