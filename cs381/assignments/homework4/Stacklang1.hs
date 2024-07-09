----------------
-- Homework 4 P1
-- Ethan Largent
-- largenet@oregonstate.edu
----------------
module Stacklang1 where

type Prog = [Cmd]

data Cmd
    = LD Int                        -- loads integer onto the stack
    | ADD                           -- removes the top two integers and loads their sum onto the stack
    | MULT                          -- removes the top two integers and loads their product onto the stack
    | DUP                           -- removes the top integer and loads it onto the stack twice
    deriving Show

type Stack = [Int]

run :: Prog -> Stack -> Maybe Stack
run [] s = Just s                   -- if the program is empty return the stack
run (c:p) s = case semCmd c s of
    Nothing -> Nothing              -- if an error has occurred return an error
    Just s' -> run p (s')           -- if we have a stack run the top command on the stack and run again with the used command removed

semCmd :: Cmd -> Stack -> Maybe Stack
semCmd (LD n) s = Just(n:s)         -- load integer onto the stack
semCmd ADD [] = Nothing             -- if the stack is empty return an error
semCmd ADD (x:[]) = Nothing         -- if the stack contains one element return an error
semCmd ADD (x:(y:s)) = Just((x+y):s)-- if the stack contains at least two elements, remove the top two and load their sum onto the stack
semCmd MULT [] = Nothing            -- if the stack is empty return an error
semCmd MULT (x:[]) = Nothing        -- if the stack contains one element return an error
semCmd MULT (x:(y:s)) = Just((x*y):s)--if the stack contains at least two elements, remove the top two and load their product onto the stack
semCmd DUP [] = Nothing             -- if the stack is empty return an error
semCmd DUP (x:s) = Just(x:(x:s))    -- if the stack contains at least one element, remove the top one and load it onto the stack twice