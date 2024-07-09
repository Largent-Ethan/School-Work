----------------
-- Homework 5
-- Ethan Largent
-- largenet@oregonstate.edu
----------------
module HW5sol where
import HW5types
{--------------------------------------------
-- Name: rankP
-- Description: Gets the rank of a program
--------------------------------------------}
rankP :: Prog -> Rank -> Maybe Rank
rankP [] r = Just r                 -- if the program is empty, retunr the rank
rankP (c:cs) r = let (n, m) = rankC c in--if the program is not empty, find the rank of the first command
    if r < n || m < -1 then Nothing -- if the rank is less than whats required by the first command or the IFELSE went negative, return Nothing
    else rankP cs ((r - n) + m)     -- otherwise apply the first commands rank to the total rank and run rankIE on the rest of the program
{--------------------------------------------
-- Name: rankC
-- Description: Gets the number of elements
    required and produced by a command
--------------------------------------------}
rankC :: Cmd -> CmdRank
rankC (LDI n) = (0,1)               -- rank of LDI
rankC (ADD) = (2,1)                 -- rank of ADD
rankC (MULT) = (2,1)                -- rank of MULT
rankC (DUP) = (1,2)                 -- rank of DUP
rankC (DEC) = (1,1)                 -- rank of DEC
rankC (SWAP) = (2,2)                -- rank of SWAP
rankC (LDB n) = (0,1)               -- rank of LDB
rankC (LEQ) = (2,1)                 -- rank of LEQ
rankC (POP x) = (x,0)               -- rank of POP
rankC (IFELSE p1 p2) = let r = (min (rankIE p1 0) (rankIE p2 0)) in (1, r)--rank of IFELSE
{--------------------------------------------
-- Name: rankIE
-- Description: Gets the number of elements
    produced by a program in an IFELSE command
--------------------------------------------}
rankIE :: Prog -> Rank -> Rank
rankIE [] r = r                         -- if the program is empty, return the rank
rankIE (c:cs) r = let (n, m) = rankC c in--if the program is not empty, find the rank of the first command
    rankIE cs ((r - n) + m)             -- apply the first commands rank to the total rank and run rankIE on the rest of the program
{--------------------------------------------
-- Name: run
-- Description: Runs a program on a stack
--------------------------------------------}
run :: Prog -> Stack -> Result
run [] s = A s                          -- if the program is empty return the stack
run (c:p) s = case rankP (c:p) (length s) of
    Nothing -> RankError                -- if Nothing was returned from rankP, return a RankError
    Just r -> case semCmd c s of        -- if a rank was returned from rankP, run semCmd on the top command
        Nothing -> TypeError            -- if Nothing was returned from semCmd, return a TypeError
        Just s' -> run p (s')           -- if a stack was returned from semCmd, run again with the used command removed
{--------------------------------------------
-- Name: rts
-- Description: Converts results into stack if possible
--------------------------------------------}
rts :: Result -> Maybe Stack
rts (A r) = Just r                      -- if the result is a stack return the stack
rts _ = Nothing                         -- otherwise return nothing
{--------------------------------------------
-- Name: semCmd
-- Description: Runs a command in a stack program
        according to how it should function
--------------------------------------------}
semCmd :: Cmd -> Stack -> Maybe Stack
semCmd (LDI n) s = Just((I n):s)        -- loads integer onto the stack
semCmd (LDB n) s = Just((B n):s)        -- loads boolean onto the stack
semCmd ADD (I x:(I y:s)) = Just(I (x+y):s)--if the top two elements are integers, remove them and load their sum onto the stack
semCmd MULT (I x:(I y:s)) = Just(I (x*y):s)--if the top two elements are integers, remove them and load their product onto the stack
semCmd DUP (x:s) = Just(x:(x:s))        -- if the stack contains one element, remove it and load it to the stack twice
semCmd LEQ (I x:(I y:s))                -- if the top two elements are integers, remove them and...
    | x <= y = Just(B True:s)           -- if the first integer is less than or equal to the second load True onto the stack 
    | otherwise = Just(B False:s)       -- otherwise load False onto the stack
semCmd (IFELSE p1 p2) ((B x):s)         -- if the top element on the stack is a boolean, remove it and...
    | x == True = rts (run p1 (s))      -- if the boolean is True run the first program on the stack
    | otherwise = rts (run p2 (s))      -- otherwise run the second program on the stack
semCmd DEC ((I x):s) = Just(I (x-1):s)  --if the top element is an integer, remove it and load its value decremented by 1
semCmd SWAP (x:(y:s)) = Just(y:(x:s))   --if the stack contains at least two elements, remove the top two and load them back in the opposite order
semCmd (POP 0) s = Just(s)              -- if k is 0 return the stack
semCmd (POP k) (x:s) = (semCmd (POP (k - 1)) s)--if k is not 0 and the stack is not empty, run POP again where k is decremented by 1 and the top element of the stack has been removed
semCmd _ _ = Nothing                    -- otherwise return Nothing