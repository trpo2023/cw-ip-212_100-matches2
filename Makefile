APP_NAME = matches
LIB_NAME = libmatches
APP_TEST_NAME = matchestest
 
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I thirdparty -I src -MP -MMD
GDB = -g -O0
 
BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test
 
APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_DIR)/$(APP_TEST_NAME)
 
SRC_EXT = c
 
APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)
APP_TEST_SOURCES = $(shell find $(TEST_DIR) -name '*.$(SRC_EXT)')
APP_TEST_OBJECTS = $(APP_TEST_SOURCES:$(TEST_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(TEST_DIR)/%.o)
 
LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)
 
DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)
 
.PHONY: all clean test
 
all: $(APP_PATH)
 
-include $(DEPS)
 
$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
 	gcc $(CFLAGS) $(GDB) $(CPPFLAGS) $^ -o $@ -lm
 
$(LIB_PATH): $(LIB_OBJECTS)
 ar rcs $@ $^
 
$(OBJ_DIR)/%.o: %.c
 	gcc -c $(CFLAGS) $(GDB) $(CPPFLAGS) $< -o $@
 
test: $(TEST_PATH)
 
$(OBJ_DIR)/$(TEST_DIR)/%.o: %.c
	gcc -c $(CFLAGS) $(CPPFLAGS) $< -o $@
 
$(TEST_PATH): $(APP_TEST_OBJECTS) $(LIB_PATH)
 	gcc $(CFLAGS) $(CPPFLAGS) $^ -o $@ -lm
 
 
clean:
 $(RM) $(APP_PATH) $(LIB_PATH) $(TEST_PATH)
 find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
 find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;