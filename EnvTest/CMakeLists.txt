#Environment test CMakeLists
cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0056 NEW)

set(TOOLCHAIN_ID_STRING "Platform ID: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

#AttemptCompileRun
#arg1: Project Name
#arg2: Source Directory Name
#arg3: Binary Directory Name
#arg4: Error message on failure
function(AttemptCompileRun arg1 arg2 arg3 arg4)
	set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${arg1})
  set(SRC_DIR ${BASE_DIR}/${arg2})
  set(BIN_DIR ${BASE_DIR}/${arg3})
	file(SHA1 ${SRC_DIR}/main.cpp SRC_HASH)
	
	if(DEFINED ${arg1}_SUCCESS)
	string(COMPARE EQUAL "${${arg1}_SUCCESS}" "${SRC_HASH}" HASHES_EQUAL)
		if(${HASHES_EQUAL} AND NOT ${RERUN_ALL_TESTS})
			return()
		endif()
	endif()
	
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
	set(${arg1}_SUCCESS ${SRC_HASH} CACHE INTERNAL "" FORCE)
endfunction(AttemptCompileRun)

option(SHOW_TEST_OUTPUT "Enable to view the stdout of each test after it is ran successfully." OFF)
option(RERUN_ALL_TESTS "Enable to have all tests rerun, regardless of whether they previously succeeded." OFF)

#Feature tests
AttemptCompileRun(RangeForTest src bin "Your platform does not support Range-For.")
AttemptCompileRun(AutoTest src bin "Your platform does not support the auto keyword.")
AttemptCompileRun(RValueRefTest src bin "Your platform does not support r-value references.")
AttemptCompileRun(StrongEnumTest src bin "Your platform does not support strongly-typed enums.")
AttemptCompileRun(NullptrTest src bin "Your platform does not support nullptr.")
AttemptCompileRun(UniformInitTest src bin "Your platform does not support uniform initialization.")
AttemptCompileRun(DecltypeTest src bin "Your platform does not support decltype.")
AttemptCompileRun(TrailingReturnTest src bin "Your platform does not support trailing return types.")
AttemptCompileRun(LambdaTest src bin "Your platform does not support lambdas.")
AttemptCompileRun(UsingAliasTest src bin "Your platform does not support using aliases.")
AttemptCompileRun(ConstexprTest src bin "Your platform does not support constexpr.")
AttemptCompileRun(DefaultDeleteTest src bin "Your platform does not support defaulted and deleted functions.")
AttemptCompileRun(DelegatingConstructorTest src bin "Your platform does not support delegating constructors.")
AttemptCompileRun(InheritingConstructorTest src bin "Your platform does not support inheriting constructors.")
AttemptCompileRun(ExplicitConversionTest src bin "Your platform does not support explicit conversion operators.")
AttemptCompileRun(OverrideFinalTest src bin "Your platform does not support override and final keywords.")
AttemptCompileRun(VariadicTemplateTest src bin "Your platform does not support variadic templates.")

AttemptCompileRun(ChronoTest src bin "Your platform does not support std::chrono.")
AttemptCompileRun(ThreadingTest src bin "Your platform does not support C++11 threading.")
