#Environment test CMakeLists
cmake_minimum_required(VERSION 2.8)

set(TOOLCHAIN_ID_STRING "Platform ID: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
#string(CONCAT TOOLCHAIN_ID_STRING "Platform ID: "
#								  ${CMAKE_CXX_COMPILER_ID}
#								  ${CMAKE_CXX_COMPILER_VERSION})

#AttemptCompile
#arg1: Project Name
#arg2: Source Directory Name
#arg3: Binary Directory Name
#arg4: Error message on failure
function(AttemptCompile arg1 arg2 arg3 arg4)
  if(DEFINED ${arg1}_SUCCESS AND NOT ${SHOW_TEST_OUTPUT})
		return()
	endif()
	set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${arg1})
  set(SRC_DIR ${BASE_DIR}/${arg2})
  set(BIN_DIR ${BASE_DIR}/${arg3})
	try_run(COMPILE_RESULT RUN_RESULT ${BIN_DIR} ${SRC_DIR}/main.cpp 
					COMPILE_OUTPUT_VARIABLE COMPILE_OUTPUT RUN_OUTPUT_VARIABLE RUN_OUTPUT)
	if(NOT COMPILE_RESULT EQUAL 0 OR NOT RUN_RESULT)
		set(ERROR_MESSAGE "${arg4}\n${TOOLCHAIN_ID_STRING}\nCompile Error:\n${COMPILE_OUTPUT}\nRun Error: ${RUN_OUTPUT}")
		message(FATAL_ERROR ${ERROR_MESSAGE})
	endif()
	message(STATUS ${arg1} " compiled and ran successfully.")
	if(${SHOW_TEST_OUTPUT})
		message(STATUS "Test output:\n" ${RUN_OUTPUT})
	endif()
	set(${arg1}_SUCCESS CACHE INTERNAL "" FORCE)
endfunction(AttemptCompile)

option(SHOW_TEST_OUTPUT "Enable to view the stdout of each test after it is ran successfully." OFF)

#Feature tests
AttemptCompile(RangeForTest src bin "Your platform does not support Range-For.")
AttemptCompile(AutoTest src bin "Your platform does not support the auto keyword.")
AttemptCompile(RValueRefTest src bin "Your platform does not support r-value references.")
AttemptCompile(StrongEnumTest src bin "Your platform does not support strongly-typed enums.")
AttemptCompile(NullptrTest src bin "Your platform does not support nullptr.")
AttemptCompile(UniformInitTest src bin "Your platform does not support uniform initialization.")
AttemptCompile(DecltypeTest src bin "Your platform does not support decltype.")
AttemptCompile(TrailingReturnTest src bin "Your platform does not support trailing return types.")
AttemptCompile(LambdaTest src bin "Your platform does not support lambdas.")
AttemptCompile(UsingAliasTest src bin "Your platform does not support using aliases.")
AttemptCompile(ConstexprTest src bin "Your platform does not support constexpr.")
AttemptCompile(DefaultDeleteTest src bin "Your platform does not support defaulted and deleted functions.")
AttemptCompile(DelegatingConstructorTest src bin "Your platform does not support delegating constructors.")
AttemptCompile(InheritingConstructorTest src bin "Your platform does not support inheriting constructors.")
AttemptCompile(ExplicitConversionTest src bin "Your platform does not support explicit conversion operators.")
AttemptCompile(OverrideFinalTest src bin "Your platform does not support override and final keywords.")
AttemptCompile(VariadicTemplateTest src bin "Your platform does not support variadic templates.")
