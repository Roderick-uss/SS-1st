ded_flags = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef \
-Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

.phony: all clean intall uninstall test_run main_run

B_PREFIX = bin/
O_PREFIX = objects/
S_PREFIX = sources/
SOURCES = in_out square
M_OBJECTS := $(patsubst %,$(O_PREFIX)%.o,$(SOURCES) main)
T_OBJECTS := $(patsubst %,$(O_PREFIX)%.o,$(SOURCES) test)
HEADER_LIST =$(S_PREFIX)*.h
all: main test

main_run: main
	./$(B_PREFIX)main

test_run: test
	./$(B_PREFIX)test

test: $(T_OBJECTS)
	@mkdir -p $(B_PREFIX)
	@gcc $(ded_flags) $^ -o $(B_PREFIX)$@

main: $(M_OBJECTS)
	@mkdir -p $(B_PREFIX)
	@gcc $(ded_flags) $^ -o $(B_PREFIX)$@

$(O_PREFIX)%.o : $(S_PREFIX)%.cpp $(HEADER_LIST)
	@mkdir -p $(O_PREFIX)
	@gcc $(ded_flags) $< -c -o $@

clean:
	rm -rf $(O_PREFIX)*.o $(B_PREFIX)*.exe
