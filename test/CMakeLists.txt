enable_testing()
include(CTest)

add_executable(LexerTest lexerTest.cpp)
target_link_libraries(LexerTest FlyPlumLexer)
add_test(NAME LexerTest COMMAND LexerTest)

add_executable(EngineTest engineTest.cpp)
target_link_libraries(EngineTest FlyPlumEngine)
add_test(NAME EngineTest COMMAND EngineTest)