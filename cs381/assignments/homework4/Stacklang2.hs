----------------
-- Homework 4 P2
-- Ethan Largent
-- largenet@oregonstate.edu
----------------
module Stacklang2 where

type Prog = [Cmd]

data Cmd
    = LDI Int                       -- loads integer onto the stack
    | LDB Bool                      -- loads boolean onto the stack
    | ADD                           -- removes the top two integers and loads their sum onto the stack
    | MULT                          -- removes the top two integers and loads their product onto the stack
    | DUP                           -- removes the top integer and loads it onto the stack twice
    | LEQ                           -- removes the top two integers and loads true onto the stack if the first integer is less than or equal to the first second one and false otherwise
    | IFELSE Prog Prog              -- removes the top boolean and runs the first program on the stack if its true and the second program on the stack if it is false
    deriving Show

type Stack = [Either Bool Int]

run :: Prog -> Stack -> Maybe Stack
run [] s = Just s                   -- if the program is empty return the stack
run (c:p) s = case semCmd c s of
    Nothing -> Nothing              -- if an error has occurred return an error
    Just s' -> run p (s')           -- if we have a stack run the top command on the stack and run again with the used command removed

semCmd :: Cmd -> Stack -> Maybe Stack
semCmd (LDI n) s = Just(Right n:s)  -- loads integer onto the stack
semCmd (LDB n) s = Just(Left n:s)   -- loads boolean onto the stack
semCmd ADD [] = Nothing             -- if the stack is empty return an error
semCmd ADD (Right x:[]) = Nothing   -- if the stack contains one integer return an error
semCmd ADD (Right x:(Right y:s)) = Just(Right (x+y):s)--if the top two elements are integers, remove them and load their sum onto the stack
semCmd ADD _ = Nothing              -- otherwise return an error
semCmd MULT [] = Nothing            -- if the stack is empty return an error 
semCmd MULT (Right x:[]) = Nothing  -- if the stack contains one integer return an error
semCmd MULT (Right x:(Right y:s)) = Just(Right (x*y):s)--if the top two elements are integers, remove them and load their product onto the stack
semCmd MULT _ = Nothing             -- otherwise return an error
semCmd DUP [] = Nothing             -- if the stack is empty return an error
semCmd DUP (x:s) = Just(x:(x:s))    -- if the stack contains on element, remove it and load it to the stack twice
semCmd LEQ [] = Nothing             -- if the stack is empty return an error
semCmd LEQ (Right x:[]) = Nothing   -- if the stack contains one element return an error
semCmd LEQ (Right x:(Right y:s))    -- if the top two elements are integers, remove them and...
    | x <= y = Just(Left True:s)        -- if the first integer is less than or equal to the second load True onto the stack 
    | otherwise = Just(Left False:s)    -- otherwise load False onto the stack
semCmd LEQ _ = Nothing              -- otherwise return an error
semCmd (IFELSE p1 p2) (Left x:s)    -- if the top element on the stack is a boolean, remove it and...
    | x == True = (run p1 s)            --if the boolean is True run the first program on the stack
    | otherwise = (run p2 s)            -- otherwise run the second program on the stack
semCmd (IFELSE p1 p2) _ = Nothing   -- otherwise return an error