# コンパイラ設定
CC = gcc
CFLAGS = -Wall -I./src -I/usr/include/SDL2

# 全ての.cファイルを再帰的に検索
SRCS = $(shell find . -name "*.c")
# オブジェクトファイルのリスト作成
OBJS = $(SRCS:.c=.o)
# 実行ファイル名
TARGET = game

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lSDL2 -lSDL2_mixer -lSDL2_ttf -lSDL2_image -fPIC

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
