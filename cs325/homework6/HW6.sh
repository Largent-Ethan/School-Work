#! /bin/bash

optarray=("14" "108159" "2579" "5333" "7411" "23001")
if [ -f tsp.cpp ];
then
    echo "C++ file"
	g++ ./tsp.cpp -std=c++11 -o tsp

	for number in {0..5}
	do
		echo "Example $number"
		echo
		mv tsp_example_"${number}".txt.tour tsp_example_"${number}".txt.tour.old
		timeout 30s ./tsp tsp_example_"${number}".txt
		
		if [ -f ./tsp_example_"${number}".txt.tour ];
		then
			python tsp-verifier.py tsp_example_"${number}".txt tsp_example_"${number}".txt.tour > result"${number}".txt 

			python tsp-verifier.py tsp_example_"${number}".txt tsp_example_"${number}".txt.tour
			dist=$(sed -n '3p' result"${number}".txt)
			div=`echo "scale=4; $dist/${optarray[number]}" | bc`
			echo "Rho Ratio $number: $div"
		else
			echo "Timed out"
		fi
		echo
	done
else
    echo "No C++ file"	
fi	
if [ -f tsp.c ];
then
    echo "C file"
	rm tsp

	gcc --std=c99 ./tsp.c -o tsp -lm
	for number in {0..5}
	do
		echo "Example $number"
		echo
		mv tsp_example_"${number}".txt.tour tsp_example_"${number}".txt.tour.old
		
		timeout 30s ./tsp tsp_example_"${number}".txt
		if [ -f ./tsp_example_"${number}".txt.tour ];
		then
			python tsp-verifier.py tsp_example_"${number}".txt tsp_example_"${number}".txt.tour > result"${number}".txt 

			python tsp-verifier.py tsp_example_"${number}".txt tsp_example_"${number}".txt.tour
			dist=$(sed -n '3p' result"${number}".txt)
			div=`echo "scale=4; $dist/${optarray[number]}" | bc`
			echo "Rho Ratio $number: $div"
		else
			echo "Timed out"
		fi
		echo
	done
else
    echo "No C file"	
fi
if [ -f tsp.py ];
then
    echo "Python file"

	for number in {0..5}
	do
		echo "Example $number"
		echo
		mv tsp_example_"${number}".txt.tour tsp_example_"${number}".txt.tour.old

		timeout 30s python3 ./tsp.py tsp_example_"${number}".txt
		
		if [ -f ./tsp_example_"${number}".txt.tour ];
		then
			python tsp-verifier.py tsp_example_"${number}".txt tsp_example_"${number}".txt.tour > result"${number}".txt 

			python tsp-verifier.py tsp_example_"${number}".txt tsp_example_"${number}".txt.tour
			dist=$(sed -n '3p' result"${number}".txt)
			div=`echo "scale=4; $dist/${optarray[number]}" | bc`
			echo "Rho Ratio $number: $div"
		else
			echo "Timed out"
		fi
		echo
	done
else
    echo "No Python file"	
fi	

rm tsp
rm result0.txt result1.txt result2.txt result3.txt result4.txt result5.txt
rm tsp_example_0.txt.tour.old tsp_example_1.txt.tour.old tsp_example_2.txt.tour.old tsp_example_3.txt.tour.old tsp_example_4.txt.tour.old tsp_example_5.txt.tour.old