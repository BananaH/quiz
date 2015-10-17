CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
DATA = "acdghkloqsuxz"
CHAR := a b c d e f g h i j k l m n o p q r s t u v w x y z
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

run_iter:iterative
	@$(foreach var,$(CHAR),./iterative $(DATA) $(var) ;)

run_rec:recursive
	@$(foreach var,$(CHAR),./recursive $(DATA) $(var) ;)

run:$(EXEC)
	echo "echo 1 > /proc/sys/vm/drop_caches" |sudo sh
	perf stat -r 10 -e cache-misses,cache-references,L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses make run_iter
	echo "echo 1 > /proc/sys/vm/drop_caches" |sudo sh
	perf stat -r 10 -e cache-misses,cache-references,L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses make run_rec

clean:
	$(RM) $(EXEC) *.o perf.*
