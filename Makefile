CFLAGS := -std=c++11

TARGETS := cpp rust cpp-lib

.PHONY: all
all: $(TARGETS)

cpp: main.o second.o
	$(CXX) $(CFLAGS) $^ -o $@

cpp-lib: main.o libsecond.a
	$(CXX) $(CFLAGS) $< -o $@ -L. -lsecond

main.o: main.cpp first.h
	$(CXX) $(CFLAGS) $< -c -o $@

second.o: second.cpp second.h
	$(CXX) $(CFLAGS) $< -c -o $@

rust: main.o rustlib/target/debug/librustlib.a
	$(CXX) $< -o $@ -Lrustlib/target/debug -lrustlib -ldl -lpthread -lgcc_s -lc -lm -lrt -lutil

libsecond.a: second.o
	$(AR) cr $@ $<

.PHONY: rustlib/target/debug/librustlib.a
rustlib/target/debug/librustlib.a:
	cd rustlib && cargo build

.PHONY: clean
clean:
	$(RM) *.o *.a $(TARGETS)
	cd rustlib && cargo clean
