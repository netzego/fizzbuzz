PROGNAME := fizzbuzz
BIN		 := bin
TARGET	 := $(BIN)/$(PROGNAME)
CHECK	 := $(BIN)/test_$(PROGNAME)
CFLAGS   := -Wall -Wextra -O2 -std=c99 -pedantic -g
LDFLAGS  := -lcheck
SRC_DIR	 := src
SRC		 := $(wildcard $(SRC_DIR)/*.c)
TEST	 := $(filter-out %/main.c, $(wildcard **/*.c))
HEADER   := $(wildcard $(SRC_DIR)/*.h)

$(BIN):
	@mkdir -p $(BIN)

$(TARGET): $(SRC) | $(BIN)
	$(CC) $(LDFLAGS) $^ -o $@

$(CHECK): $(TEST) | $(BIN)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	@$(RM) -r $(BIN)
	@fd -I -t x -x $(RM) {}	

run: $(TARGET)
	@./$^

watch_run: $(TARGET)
	@ls $(SRC) $(HEADER) | entr -c $(MAKE) --no-print-directory run

test: $(CHECK)
	@./$(CHECK)

watch_test: $(TARGET)
	@ls $(SRC) $(HEADER) $(TEST) | entr -c $(MAKE) --no-print-directory test

.PHONY : \
	clean \
	run \
	test \
	watch_run \
	watch_test

.DEFAULT_GOAL := run
