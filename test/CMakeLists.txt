enable_testing()
include(CTest)

add_executable(LexerTest lexerTest.cpp)
target_link_libraries(LexerTest FlyPlumLexer)
add_test(NAME LexerTest COMMAND LexerTest)