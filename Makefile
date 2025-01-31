# コンパイラとフラグの設定
CC = gcc
CFLAGS = -Wall -Werror -g

# ソースディレクトリとビルドディレクトリの設定
SRC_DIR = src
OBJ_DIR = obj
#BIN_DIR = bin

# ターゲットバイナリの設定
TARGET = game

LIBDIR  = -lSDL -L/usr/lib -lSDL_gfx  -lSDL_ttf -lSDL_mixer

# ソースファイルとオブジェクトファイルのリスト
SRCS = $(wildcard $(SRC_DIR)/*.c) test.c
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# デフォルトターゲット
all: $(TARGET)

# ターゲットバイナリのビルドルール
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBDIR)

# オブジェクトファイルのビルドルール
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# クリーンアップルール
clean:
	rm -rf $(OBJ_DIR)

# .PHONYターゲット
.PHONY: all clean
