#Environment test CMakeLists
cmake_minimum_required(VERSION 3.2)

set(TOOLCHAIN_ID_STRING)
string(CONCAT TOOLCHAIN_ID_STRING "Platform ID: "
								  ${CMAKE_CXX_COMPILER_ID}
								  ${CMAKE_CXX_COMPILER_VERSION})

#AttemptCompile
#arg1: Project Name
#arg2: Source Directory Name
#arg3: Binary Directory Name
#arg4: Error message on failure
function(AttemptCompile arg1 arg2 arg3 arg4)
	string(APPEND BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR} /${arg1})
	string(APPEND SRC_DIR ${BASE_DIR} /${arg2})
	string(APPEND BIN_DIR ${BASE_DIR} /${arg3})
	try_compile(COMPILE_SUCCESS_RESULT ${BIN_DIR} ${SRC_DIR}
				${arg1} OUTPUT_VARIABLE COMPILE_OUTPUT)
	if(ENVIRONMENT_FEATURE_SUPPORT EQUAL FALSE)
		string(CONCAT ERROR_MESSAGE ${arg4}
			   " "
			   ${TOOLCHAIN_ID_STRING}
			   " Error: " 
			   ${COMPILE_OUTPUT})
		message(FATAL_ERROR ${ERROR_MESSAGE})
	endif()
	message(STATUS ${arg1} " compiled successfully.")
endfunction(AttemptCompile)

#Feature tests
AttemptCompile(RangeForTest src bin "Your platform does not support Range-For.")
AttemptCompile(AutoTest src bin "Your platform does not support the auto keyword.")
AttemptCompile(UniformInitTest src bin "Your platform does not support uniform initialization.")
AttemptCompile(LambdaTest src bin "Your platform does not support lambdas.")
AttemptCompile(UsingAliasTest src bin "Your platform does not support using aliases.")
