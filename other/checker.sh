#!/bin/bash

 echo "############## Check problem 1 ##############"
 FILE1="Papyrus.java"
 FILE2="papyrus.cpp"
 if test -f $FILE1; then
     javac Papyrus.java

     aux_result=$?

     if [ $aux_result -eq 0 ]
     then
         score=0
         for i in {1..10}
         do
             test_name="papyrus"$i".in"
             ref_name="papyrus"$i".out"
             cp tests/$test_name papyrus.in
             timeout 0.8 java Papyrus 2> /dev/null
             aux_res=$?
             #echo $aux_res
             if [ $aux_res -eq 124 ]
             then
                 echo "Test "$i" ......................... TLE"
                 continue
             elif [ $aux_res != 0 ]
             then
                 echo "Test "$i" ......................... Run Time Error"
                 continue
             fi
             diff -w papyrus.out refs/$ref_name
             result=$?
             if [ $result -eq 0 ]
             then
                 score=$((score+10))
                 echo "Test "$i" ......................... passed"
             else
                 echo "Test "$i" ......................... failed"
             fi
         done
         echo "Total score: "$score
         rm Papyrus.class
         rm -f papyrus.in
         rm -f papyrus.out
     else
         echo "Source not compiling. Abort testing!"
     fi
 elif test -f $FILE2; then
     g++ papyrus.cpp -std=c++14 -o exe

     aux_result=$?

     if [ $aux_result -eq 0 ]
     then
         score=0
         for i in {1..10}
         do
             test_name="papyrus"$i".in"
             ref_name="papyrus"$i".out"
             cp tests/$test_name papyrus.in
             timeout 0.4 ./exe
             aux_res=$?
             #echo $aux_res
             if [ $aux_res != 0 ]
             then
                 echo "Test "$i" ......................... TLE"
                 continue
             fi
             diff -w papyrus.out refs/$ref_name
             result=$?
             if [ $result -eq 0 ]
             then
                 score=$((score+10))
                 echo "Test "$i" ......................... passed"
             else
                 echo "Test "$i" ......................... failed"
             fi
         done
         echo "Total score: "$score
         rm exe
         rm -f papyrus.in
         rm -f papyrus.out
     else
         echo "Source not compiling. Abort testing!"
     fi
 fi

echo "############## Check problem 2 ##############"
FILE1="Interview.java"
FILE2="interview.cpp"
if test -f $FILE1; then
    javac Interview.java

    aux_result=$?

    if [ $aux_result -eq 0 ]
    then
        score=0
        for i in {1..10}
        do
            test_name="interview"$i".in"
            ref_name="interview"$i".out"
            cp tests/$test_name interview.in
            timeout 0.5 java Interview 2> /dev/null
            aux_res=$?
            #echo $aux_res
            if [ $aux_res -eq 124 ]
            then
                echo "Test "$i" ......................... TLE"
                continue
            elif [ $aux_res != 0 ]
            then
                echo "Test "$i" ......................... Run Time Error"
                continue
            fi
            diff -w interview.out refs/$ref_name
            result=$?
            if [ $result -eq 0 ]
            then
                score=$((score+10))
                echo "Test "$i" ......................... passed"
            else
                echo "Test "$i" ......................... failed"
            fi
        done
        echo "Total score: "$score
        rm Interview.class
        rm -f interview.in
        rm -f interview.out
    else
        echo "Source not compiling. Abort testing!"
    fi
elif test -f $FILE2; then
    g++ interview.cpp -std=c++14 -o exe

    aux_result=$?

    if [ $aux_result -eq 0 ]
    then
        score=0
        for i in {1..10}
        do
            test_name="interview"$i".in"
            ref_name="interview"$i".out"
            cp tests/$test_name interview.in
            timeout 0.2 ./exe
            aux_res=$?
            #echo $aux_res
            if [ $aux_res != 0 ]
            then
                echo "Test "$i" ......................... TLE"
                continue
            fi
            diff -w interview.out refs/$ref_name
            result=$?
            if [ $result -eq 0 ]
            then
                score=$((score+10))
                echo "Test "$i" ......................... passed"
            else
                echo "Test "$i" ......................... failed"
            fi
        done
        echo "Total score: "$score
        rm exe
        rm -f interview.in
        rm -f interview.out
    else
        echo "Source not compiling. Abort testing!"
    fi
fi

