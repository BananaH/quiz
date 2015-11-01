CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

run_iter:iterative
	@./iterative

run_rec:recursive
	@./recursive

run:$(EXEC)
	echo "echo 1 > /proc/sys/vm/drop_caches" |sudo sh
	perf stat -r 10 -e cache-misses,cache-references,L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses make run_iter
	echo "echo 1 > /proc/sys/vm/drop_caches" |sudo sh
	perf stat -r 10 -e cache-misses,cache-references,L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses make run_rec


clean:
	$(RM) $(EXEC) *.o perf.*
