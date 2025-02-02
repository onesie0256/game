# コンパイラ設定
CC = gcc
CFLAGS = -Wall -I./src

# 全ての.cファイルを再帰的に検索
SRCS = $(shell find . -name "*.c")
# オブジェクトファイルのリスト作成
OBJS = $(SRCS:.c=.o)
# 実行ファイル名
TARGET = game

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lSDL -lSDL_mixer -lSDL_ttf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
