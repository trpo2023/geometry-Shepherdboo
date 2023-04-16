NAME_APP = app
LIB_NAME = libgeometry.a

CFLAGS = -Wall -Werror
DEPSFLAGS = -MMD

OBJ_DIR = obj
BIN_DIR = bin
APP_DIR = src/geometry
LIB_DIR = src/libgeometry

APP_PATH = $(BIN_DIR)/$(NAME_APP)
LIB_PATH = $(OBJ_DIR)/$(LIB_DIR)/$(LIB_NAME)

APP_SRC = $(wildcard $(APP_DIR)/*.c)
LIB_SRC = $(wildcard $(LIB_DIR)/*.c)
APP_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(APP_SRC))
LIB_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(LIB_SRC))
APP_DEPS = $(patsubst $(APP_OBJ), $(OBJ_DIR)/%.d, $(APP_OBJ))
LIB_DEPS = $(patsubst $(LIB_OBJ), $(OBJ_DIR)/%.d, $(LIB_OBJ))

all: $(APP_PATH)

$(APP_PATH): $(APP_OBJ) $(LIB_PATH)
	gcc -I $(LIB_DIR) $^ -o $@ -lm

$(LIB_PATH): $(LIB_OBJ)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	gcc $(CFLAGS) $(DEPSFLAGS) -I $(LIB_DIR) -c $< -o $@ -lm

clean:
	rm $(APP_PATH) $(OBJ_DIR)/$(APP_DIR)/*.* $(OBJ_DIR)/$(LIB_DIR)/*.*

-include $(LIB_DEPS) $(APP_DEPS)

.PHONY: all clean
