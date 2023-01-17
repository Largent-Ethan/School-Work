-- mySum
mySum [a] = a
mySum (x:xs) = x + mySum xs

-- myLength
myLength :: [a] -> Int
myLength [] = 0
myLength (x:xs) = 1 + myLength xs