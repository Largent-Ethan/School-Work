----------------
-- Homework 2
-- Ethan Largent
-- largenet@oregonstate.edu
----------------
module HW2sol where
import HW2types
sname = "Ethan Largent"
----------------
-- Exercise 1
----------------
-- ins -- insert an item into a bag
ins :: Eq a => a -> (Bag a) -> (Bag a)
ins a [] = [(a, 1)]
ins a ((x, y) : xs)
    | a == x = ((x, y + 1) : xs)
    | otherwise = (x, y) : (ins a xs)

-- del -- delete and item from a bag
del :: Eq a => a -> Bag a -> Bag a
del a [] = []
del a ((x, y) : xs)
    | a == x && y == 1 = xs
    | a == x = ((x, y - 1) : xs)
    | otherwise = ((x, y) : del a xs)

-- bag -- Convert a standard list into a bag
bag :: Eq a => [a] -> Bag a
bag [] = []
bag (x : xs) = ins x (bag xs)

-- subbag -- Check if all items in 1 bag are present in another bag
subbag :: Eq a => Bag a -> Bag a -> Bool
subbag xs [] = False
subbag [] ys = True
subbag (x : xs) ys = check x ys && subbag xs ys

check x []     = False
check x (y : ys)
    | fst x == fst y && snd x <= snd y = True
    | otherwise = check x ys

-- isSet -- Check if a bag contains 1 of each item
isSet :: Eq a => Bag a -> Bool
isSet [] = True
isSet ((x, y) : xs)
    | y == 1 = isSet(xs)
    | otherwise = False

-- size
size :: Bag a -> Int
size [] = 0
size ((x, y) : xs) = y + size(xs)


----------------
-- Exercise 2
----------------
-- nodes -- Find all nodes in a graph
nodes :: Graph -> [Node]
nodes [] = []
nodes ((x, y) : xs) = norm ([x, y] ++ nodes xs)

-- suc -- Find all nodes a nodes edges point towards
suc :: Node -> Graph -> [Node]
suc z [] = []
suc z ((x, y) : xs)
    | z == x = [y] ++ suc z xs
    | otherwise = suc z xs

-- detach -- Deletes all edges in a graph that contain a specified node
detach :: Node -> Graph -> Graph
detach z [] = []
detach z ((x, y) : xs)
    | z == x = detach z xs
    | z == y = detach z xs
    | otherwise = (x, y) : detach z xs

-- cyc -- Create a graph that cycles through each point in order
cyc :: Int -> Graph
cyc x = cyc2 x ++ [(x, 1)]

cyc2 :: Int -> Graph
cyc2 1 = []
cyc2 x = (cyc2 (x - 1) ++ [(x - 1, x)])

----------------
-- Exercise 3
----------------
-- width -- Find the width of a shape
width :: Shape -> Length
width (Pt p) = 0
width (Circle p l) = l * 2
width (Rect p l1 l2) = l1

-- bbox -- Find bottom left and top right coordinates of a box that encloses the shape
bbox :: Shape -> BBox
bbox (Pt p) = (p, p)
bbox (Circle (x, y) l) = ((x - l, y - l), (x + l, y + l))
bbox (Rect (x, y) l1 l2) = ((x, y), (x + l1, y + l2))

-- minX -- Find leftmost position of shape
minX :: Shape -> Number
minX (Pt p) = fst p
minX (Circle (x, y) l) = x - l
minX (Rect p l1 l2) = fst p

-- move -- Add point to shapes point
move :: Shape -> Point -> Shape
move (Pt (x1, y1)) (x2, y2) = (Pt (x1 + x2, y1 + y2))
move (Circle (x1, y1) l) (x2, y2) = (Circle (x1 + x2, y1 + y2) l)
move (Rect (x1, y1) l1 l2) (x2, y2) = (Rect (x1 + x2, y1 + y2) l1 l2)