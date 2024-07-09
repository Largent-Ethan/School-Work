import Stacklang1

main:: IO ()
main =
    do
        stack1 :: Stack
        stack1 = [1, 2, 3, 4, 5]
        test1 = [LD 3, DUP, ADD, DUP, MULT] 
        test2 = [LD 3, ADD]
        test3 = []
        test4 = [ADD, ADD, ADD, ADD]


        putStrLn " run test1 [] = Just [36]?"
        putStr " run test1 [] = "
        print (run test1 [])
        putStrLn "******************"
        putStrLn " run test1 stack1 = Just [36,1,2,3,4,5]?"
        putStr " run test1 stack1 = "
        print (run test1 stack1)
        putStrLn "******************"
        putStrLn " run test2 [] = Nothing?"
        putStr " run test2 [] = "
        print (run test2 [])
        putStrLn "******************"
        putStrLn " run test2 stack1 = Just [4,2,3,4,5]?"
        putStr " run test2 stack1 = "
        print (run test2 stack1)
        putStrLn "******************"
        putStrLn " run test3 [] = Just []?"
        putStr " run test3 [] = "
        print (run test3 [])
        putStrLn "******************"
        putStrLn " run test3 stack1 = Just [1,2,3,4,5]?"
        putStr " run test3 stack1 = "
        print (run test3 stack1)
        putStrLn "******************"
        putStrLn " run test4 [] = Nothing?"
        putStr " run test4 [] = "
        print (run test4 [])
        putStrLn "******************"
        putStrLn " run test4 stack1 = Just [15]?"
        putStr " run test4 stack1 = "
        print (run test4 stack1)