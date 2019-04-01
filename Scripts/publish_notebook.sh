#!/bin/bash

outputfile=$(echo $1 | cut -d . -f 1).html


#working on the Programs repository
path2=/home/diksha/Programs/ML_Using_Python
cp $1 $path2
jupyter nbconvert $1 --output=$path2/$outputfile
cd $path2
git add .
git commit -m "Commited from script"
git push origin master

#working on the portfolio repository
path1=/home/diksha/Diksha65.github.io
jupyter nbconvert $1 --output=$path1/$outputfile
cd $path1
git add .
git commit -m "Commited from script"
git push origin master
