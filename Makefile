SRCDIR := src
OBJDIR := obj

SRC := main.cpp UI.cpp input.cpp calculations.cpp common.cpp 
SRC_TEST := tests.cpp calculations.cpp common.cpp
OBJ := $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))
OBJ_TEST := $(addprefix $(OBJDIR)/, $(SRC_TEST:.cpp=.o))

CXX := gcc
CXXFLAGS := -O3 -g -std=c++14 -fmax-errors=100 -Wall -Wextra                  \
	    -Weffc++ -Waggressive-loop-optimizations -Wc++0x-compat           \
	    -Wc++11-compat -Wc++14-compat -Wcast-align -Wcast-qual            \
	    -Wchar-subscripts -Wconditionally-supported -Wconversion          \
	    -Wctor-dtor-privacy -Wempty-body -Wfloat-equal                    \
	    -Wformat-nonliteral -Wformat-security -Wformat-signedness         \
	    -Wformat=2 -Winline -Wlarger-than=8192 -Wlogical-op               \
	    -Wmissing-declarations -Wnon-virtual-dtor -Wopenmp-simd           \
	    -Woverloaded-virtual -Wpacked -Wpointer-arith -Wredundant-decls   \
	    -Wshadow -Wsign-conversion -Wsign-promo -Wstack-usage=8192        \
	    -Wstrict-null-sentinel -Wstrict-overflow=2                        \
	    -Wsuggest-attribute=noreturn -Wsuggest-final-methods              \
	    -Wsuggest-final-types -Wsuggest-override -Wswitch-default         \
	    -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused     \
	    -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix              \
	    -Wno-missing-field-initializers -Wno-narrowing                    \
	    -Wno-old-style-cast -Wno-varargs -fcheck-new                      \
	    -fsized-deallocation -fstack-check -fstack-protector              \
	    -fstrict-overflow -flto-odr-type-merging                          \
	    -fno-omit-frame-pointer                                           \
	    -fsanitize=address                                                \
	    -fsanitize=alignment                                              \
	    -fsanitize=bool                                                   \
	    -fsanitize=bounds                                                 \
	    -fsanitize=enum                                                   \
	    -fsanitize=float-cast-overflow                                    \
	    -fsanitize=float-divide-by-zero                                   \
	    -fsanitize=integer-divide-by-zero                                 \
	    -fsanitize=leak                                                   \
	    -fsanitize=nonnull-attribute                                      \
	    -fsanitize=null                                                   \
	    -fsanitize=object-size                                            \
	    -fsanitize=return                                                 \
	    -fsanitize=returns-nonnull-attribute                              \
	    -fsanitize=shift                                                  \
	    -fsanitize=signed-integer-overflow                                \
	    -fsanitize=undefined                                              \
	    -fsanitize=unreachable                                            \
	    -fsanitize=vla-bound                                              \
	    -fsanitize=vptr                                                   \
	    -fPIE                                                             \
	    -lm -pie
TARGET := quadratic
TARGET_TEST := test

.SILENT:
all: out run

run:
	printf "%s\n" "Running tests..."
	./$(TARGET_TEST)
	printf "%s\n" "Finished."
	./$(TARGET)

out: $(OBJDIR) $(OBJ) $(OBJ_TEST)
	printf "%s\n" "Linking..."
	$(CXX) $(OBJ) -o $(TARGET) $(CXXFLAGS)
	$(CXX) $(OBJ_TEST) -o $(TARGET_TEST) $(CXXFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	printf "%s\n" "Compiling $^..."
	$(CXX) -c $^ -o  $@ $(CXXFLAGS)

$(OBJDIR):
	printf "%s\n" "Making obj/ directory..."
	mkdir $@

clean:
	printf "%s\n" "Removing obj/ directory..."
	rm -rf $(OBJDIR)
	printf "%s\n" "Done."

reinstall: 
	printf "%s\n" "Reinstalling..."
	rm -rf ../quadratic_calc
	printf "%s\n" "Program uninstalled successfully."

