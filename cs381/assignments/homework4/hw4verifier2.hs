import Stacklang2
main = do
    stack1 :: Stack
    stack1 = [Right 1, Right 3, Right 5, Right 7, Right 9]
    stack2 :: Stack
    stack2= [Left True, Right 3]
    test1 = [LDI 3, DUP, ADD, DUP,MULT]
    test2 = [LDB True, DUP, IFELSE [LDI 1][LDI 0]]
    test3 = [LEQ]
    test4 = [ADD, ADD, MULT, DUP]
    test5 = [LEQ, IFELSE [] [], LDI 9]
    test6 = [LDI 5, LDI 2, LEQ, IFELSE [LDI 10, DUP] [], ADD]
    test7 = [LDI 5, LDI 2, LEQ, IFELSE [LDI 10, DUP] [LDI 20, DUP], ADD]
    test8 = [LDI 1, LDI 2, LDI 3, LDI 4, LDI 5, ADD, ADD, ADD, ADD]

    putStrLn " run test1 [] = Just [Right 36]?"
	putStr " run test1 [] = "
	print (run test1 [])
	putStrLn "******************"
    putStrLn " run test2 [] = Just [Right 1,Left True]?"
    putStr " run test2 [] = "
	print (run test2 [])
	putStrLn "******************"
    putStrLn " run test3 stack1 = Just [Left True,Right 5,Right 7,Right 9]?"
    putStr " run test3 stack1 = "
	print (run test3 stack1)
	putStrLn "******************"
    putStrLn " run test4 stack1 = Just [Right 63,Right 63,Right 9]?"
    putStr " run test4 stack1 = "
	print (run test4 stack1)
	putStrLn "******************"
    putStrLn " run test4 stack2 = Nothing?"
    putStr " run test4 stack2 = "
	print (run test4 stack1)
	putStrLn "******************"
    putStrLn " run test5 stack1 = Just [Right 9,Right 5,Right 7,Right 9]?"
    putStr " run test5 stack1 = "
	print (run test4 stack1)
	putStrLn "******************"
    putStrLn " run test6 [] = Just [Right 20]?"
    putStr " run test6 [] = "
	print (run test2 [])
	putStrLn "******************"
    putStrLn " run test7 [] = Just [Right 40]?"
    putStr " run test7 [] = "
	print (run test2 [])
	putStrLn "******************"
    putStrLn " run test8 [] = Just [Right 15]?"
    putStr " run test8 [] = "
	print (run test2 [])