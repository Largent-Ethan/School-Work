-- Homework 3 template

module Sentence where

-- Grammar for the animal sentence language:
--
--   <sentence> ->  <noun> <verb> [<noun>]  
--               	|  <sentence> `and` <sentence>
--				 	
--   <noun> 	-> <adj> <noun> | <noun> `and` <noun>
--					| `cats` | `dogs` | `ducks` | `bunnies`

--   <verb>		->  `chase` | `cuddle` | `hug` | `scare`
--   <adj>		->	`silly` | `small` | `old` | `happy`

data Sentence
    = NVN Noun Verb Noun -- finished noun verb noun sentence
    | NV Noun Verb -- finished noun verb sentence
    | And Sentence Sentence -- finished sentence and sentence
    | End
  deriving (Eq,Show)

data Adj = Silly | Small | Old | Happy -- finished adjectives
  deriving (Eq,Show)

data Noun -- finished
    = NP Adj Noun  -- Noun phrase
    | NAnd Noun Noun  -- Finished noun and noun
	  | Cats | Dogs | Ducks | Bunnies		  -- list of nouns
  deriving (Eq,Show)

data Verb = Chase | Cuddle | Hug | Scare -- finished
  deriving (Eq,Show)


-- | The sentence: cats cuddle ducks and dogs cuddle ducks
ex1 :: Sentence
ex1 = NVN Cats Hug Dogs

ex2 :: Sentence
ex2 = NVN (NP Silly Cats) Hug Dogs

ex3 :: Sentence
ex3 = NVN (NAnd Dogs Cats) Chase Ducks

ex4 :: Sentence
ex4 = NVN (NAnd (NP Silly Dogs) Cats) Chase Ducks


-- | Build a sentence from a noun verb noun.
-- | buildS2 Cats Hug Cats
-- | NVN Cats Hug Cats

buildS2 :: Noun -> Verb ->Noun-> Sentence
buildS2 n1 v n2 = NVN n1 v n2
-- finished

-- | Build a sentence from a noun verb 
-- | buildS1 Cats Hug 
-- | NV Cats Hug 

buildS1 :: Noun -> Verb ->Sentence
buildS1 n v = NV n v
-- finished


-- | Build a noun phrase from an adjective and noun
-- | buildNP Silly Dogs
-- | NP Silly Dogs

buildNP :: Adj -> Noun -> Noun
buildNP a n = NP a n
-- finished

-- | Build a noun conjunction from two nouns
-- | buildNAnd Dogs Cats
-- | NAnd Dogs Cats

buildNAnd :: Noun -> Noun -> Noun
buildNAnd n1 n2 = NAnd n1 n2
-- finished

-- | Build a sentence that is a conjunction of a list of other sentences.
-- | conjunction [ex1, ex2]
-- | And (NVN Cats Hug Dogs) (NVN (NP Silly Cats) Hug Dogs)
--  
buildAnd :: Sentence -> Sentence -> Sentence
buildAnd s1 s2 = And s1 s2

conjunction :: [Sentence] -> Sentence
conjunction [] = End
conjunction (s:sl)
  | sl == [] = s
  | otherwise = buildAnd s (conjunction sl)
-- finished

-- | Pretty print a sentence.
pretty :: Sentence -> String
pretty (NVN s v o) = prettyNoun s ++ " " ++ prettyVerb v ++ " " ++ prettyNoun o
pretty (And l r)   = pretty l ++ " and " ++ pretty r
pretty (NV s v)     = prettyNoun s ++ " " ++ prettyVerb v
pretty (End) = "."

-- | Pretty print a noun.
prettyNoun :: Noun -> String
prettyNoun Cats = "cats"
prettyNoun Dogs = "dogs"
prettyNoun Ducks = "ducks"
prettyNoun Bunnies = "bunnies"
-- finished


prettyNoun (NP a n) = prettyAdj a ++ " " ++ prettyNoun n
prettyNoun (NAnd m n) = prettyNoun m ++ " and " ++prettyNoun n

-- | Pretty print a verb.
prettyVerb :: Verb -> String
prettyVerb Chase  = "chase"
prettyVerb Cuddle  = "cuddle"
prettyVerb Hug  = "hug"
prettyVerb Scare  = "scare"
-- finished

-- | Pretty print an adjective.
prettyAdj :: Adj -> String
prettyAdj Silly  = "silly"
prettyAdj Small  = "small"
prettyAdj Old  = "old"
prettyAdj Happy  = "happy"
-- finished


-- | Does the sentence contain only cuddling and hugs?
-- | isNice ex2
-- |   True
isNice :: Sentence -> Bool
isNice (And s1 s2) = isNice s1 && isNice s2
isNice (NVN _ Hug _) = True
isNice (NVN _ Cuddle _) = True
isNice (NV _ Hug) = True
isNice (NV _ Cuddle) = True
isNice _ = False
-- finished

-- |Count the number of words in a sentence
-- | wordCount ex4
--    6

wordCountN :: Noun -> Int
wordCountN (NP a n) = wordCountN n + 1
wordCountN (NAnd n1 n2) = wordCountN n1 + wordCountN n2 + 1
wordCountN _ = 1

wordCount :: Sentence -> Int
wordCount (And s1 s2) = wordCount s1 + wordCount s2 + 1
wordCount (NVN n1 v n2) = wordCountN n1 + wordCountN n2 + 1
wordCount (NV n v) = wordCountN n + 1
wordCount _ = 1
-- finished