#!/bin/bash
#cleans all bin folders that contain DoNotDelete.txt

func () {
	local pathonly=""
	find ./ -wholename '*/bin/DoNotDelete.txt' | while read path; do
		pathonly=$(dirname "$path")
		find $pathonly -maxdepth 1 -mindepth 1 -type d | while read folder; do
			echo $folder
			rm -rf $folder
		done
		find $pathonly -maxdepth 1 -mindepth 1 -type f | while read file; do
			if [ "$(basename $file)" != "DoNotDelete.txt" ]; then
				echo $file
				rm $file
			fi
		done
	done
}

func
