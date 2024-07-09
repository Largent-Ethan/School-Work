import HW5sol
import HW5types
-- rankAll   ( if failure test each using rankP pi 0 )
-- runAllTests  ( if failure test each using run pi si )
-- runAllEmpty  ( if failure test each using run pi [] )
    {-runAllTests
    Test 1 ==> A [I 6,I 5,B True]
    Test 2 ==> A [I 4,I 2]
    Test 3 ==> A [I 23,I 1,I 3]
    Test 4 ==> A [B False,B False,I 4,I 7]
    Test 5 ==> RankError
    Test 6 ==> RankError
    Test 7 ==> TypeError
    Test 8 ==> A [I 21,I 21,I 10,I 20,I 1]
    Test 9 ==> TypeError
    Test 10 ==> A [I 9,I 9,I 1,I 4,I 6]
    Test 11 ==> TypeError
    Test 12 ==> A [I 15,I 15,I 100,I 6]
    Test 13 ==> A [I 50,I 10,I 20,I 1]
    Test 14 ==> A [I 7,I 5,I 10,I 3,I 8]
    Test 15 ==> A [I 7,I 5,I 10,I 3,I 8]
    -}
    {-rankAll
    Test 1 ==> Just 2
    Test 2 ==> Just 1
    Test 3 ==> Just 1
    Test 4 ==> Nothing
    Test 5 ==> Nothing
    Test 6 ==> Nothing
    Test 7 ==> Just 1
    Test 8 ==> Just 2
    Test 9 ==> Just 1
    Test 10 ==> Just 2
    Test 11 ==> Just 1
    Test 12 ==> Just 1
    Test 13 ==> Just 1
    Test 14 ==> Just 1
    Test 15 ==> Nothing
    -}
--test progs
p1 = [LDI 3, DUP, ADD, LDI 5, SWAP] 
p2 = [LDI 8, POP 1, LDI 3, DUP, POP 2, LDI 4] 
p3 = [LDI 3, LDI 4, LDI 5, MULT, ADD] 
p4 = [DUP] 
p5 = [POP 4] 
p6 = [LDB True, IFELSE [ADD] [LDI 7], ADD ]
p7 = [LDB True, LDI 1, LDI 10, LDI 5, IFELSE [ADD] [LDI 7], ADD ]
p8 = [LDI 20, LDI 1, LDI 10, LDI 5, LEQ, IFELSE [ADD] [LDI 7], DUP ]
p9 = [LDB True, LDB False, MULT]
p10 = [LDI 10, DEC, DUP, DUP, DUP, POP 2]
p11 = [LDI 10, LDI 20, LEQ, DEC]
p12 = [LDI 10, LDI 5, LDB True, IFELSE [LDB True, IFELSE [ADD, DUP] [MULT]] [LDI 7]]
p13 = [LDI 10, LDI 5, LDB True, IFELSE [LDB False, IFELSE [ADD, DUP] [MULT]] [LDI 7] ]
p14 = [LDI 10, LDI 5, LDB False, IFELSE [LDB True, IFELSE [ADD, DUP] [MULT]] [LDI 7] ]
p15 = [LDI 10, LDI 5, LDB False, IFELSE [LDB True, IFELSE [ADD, ADD] [MULT]] [LDI 7] ]

tList  = [p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15]
-- sList ::[[Int]]
sList =[s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15 ]
eList = [ [], [],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[]]
s1 = [B True]
s2 = [I 2]
s3 = [I 1, I 3]
s4 = [B False, I 4, I 7]
s5 = [I 1, I 4, I 6]
s6 = [I 10]
s7 = [I 100, I 6]
s8 = [I 10, I 20, I 1]
s9 = [I 3, I 8]
s10 = [I 1, I 4, I 6]
s11 = [I 10]
s12 = [I 100, I 6]
s13 = [I 10, I 20, I 1]
s14 = [I 3, I 8]
s15 = [I 3, I 8]

runAll :: [Stack] -> [Prog]-> Int -> String
runAll [] _ _= " "
runAll _ [] _ = " "
runAll (s:ss) (p:ps) n = "Test "++show(n)++" ==> "++show(run p s) ++ "\n" ++ (runAll ss ps (n+1))

runAllTests :: IO ()
runAllTests = putStrLn ("\nStack Tests\n"++ (runAll sList tList 1))

runAllEmpty :: IO()
runAllEmpty = putStrLn("\nEmpty Stack Tests\n"++(runAll eList tList 1))

prettyERank :: [Prog] -> Int -> String
prettyERank [] _ = " "
prettyERank (p:pp) n = "Test "++show(n)++" ==> "++show (rankP p 0)++"\n"++ (prettyERank pp (n+1))

rankAll :: IO ()
rankAll = putStrLn ("\nRank Tests with empty stack \n"++(prettyERank tList 1))
