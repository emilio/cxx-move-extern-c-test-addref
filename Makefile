CFLAGS := -std=c++11

final: main.o second.o
	$(CXX) $(CFLAGS) $^ -o $@

main.o: main.cpp first.h
	$(CXX) $(CFLAGS) $< -c -o $@

second.o: second.cpp second.h
	$(CXX) $(CFLAGS) $< -c -o $@

.PHONY: clean
clean:
	$(RM) *.o final
