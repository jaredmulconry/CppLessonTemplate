@echo off
setlocal EnableExtensions EnableDelayedExpansion

echo. 
for /R %cd% %%A in (DoNotDelete.t?t) do (
	set DIR_SEARCH_RES=%%~dpA
	cd !DIR_SEARCH_RES!
	echo !cd!
	echo Folders: 
	for /f %%C in ('dir /a:d-s /b !cd!') do (
		echo %%C
		rd /s /q %%C
	)
	
	echo. & echo Files:
	for %%B in (*) do (
		set SUB_FILE_NAME=%%~nxB
		if "!SUB_FILE_NAME!" NEQ "DoNotDelete.txt" (
			echo !SUB_FILE_NAME!
			del /Q %%B
		)
	)
	echo. 
)

endlocal