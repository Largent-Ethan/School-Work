/* course(course_number, course_name, credits) */
course(cs101,python, 2).
course(mth210, calculusI, 5).
course(cs120, web_design, 3).
course(cs200, data_structures, 4).
course(cs210, algorithms, 4).
course(wrt101, basic_writing, 3).

/* section(CRN, course_number) */
section(1522,cs101).
section(1122,cs101).
section(2322,mth210).
section(2421,cs120).
section(8522,mth210).
section(1621,cs200).
section(7822,mth210).
section(2822,cs210).
section(3522,wrt101).

/* place( CRN, building, time) */
place(1522,owen102,10).
place(1122,dear118,11).
place(2322,with210,11).
place(2421,cov216,15).
place(8522,kec1001,13).
place(1621,cov216,14).
place(7822,kec1001,14).
place(2822,owen102,13).
place(3522,with210,15).

/* enroll(sid, CRN) */
enroll(122,1522).
enroll(122,8522).
enroll(150,1522).
enroll(150,2421).
enroll(212,7822).
enroll(300,2822).
enroll(300,8522).
enroll(310,3522).
enroll(310,8522).
enroll(310,1621).
enroll(175,2822).
enroll(175,7822).
enroll(175,3522).
enroll(410,1621).
enroll(410,7822).
enroll(113,3522).

/* student(sid, student_name, major) */
student(122, mary, cs).
student(150, john, math).
student(212, jim, ece).
student(300, lee, cs).
student(310, pat, cs).
student(175, amy, math).
student(410, john, cs).
student(113, zoe, ece).

/************
  Problem 1
************/
/* A */
schedule(SID, C, B, T) :- 
    student(SID, _, _),
    enroll(SID, CRN),
    section(CRN, Cnum),
    course(Cnum, C, _),  
    place(CRN, B, T).
/* B */
schedule(SID, N, C):-
    student(SID, N, _),
    enroll(SID, CRN),
    section(CRN, Cnum),
    course(Cnum, C, _).
/* C */
offer(Cnum, N, C, T):-
    course(Cnum, N, _),
    section(C, Cnum),
    place(C, _, T).
/* D */
conflict(SID, X, Y):-
    enroll(SID, X),
    enroll(SID, Y),
    X \= Y,
    place(X, _, Xtime),
    place(Y, _, Ytime),
    Xtime = Ytime.
/* E */
meet(SID1, SID2):-
    student(SID1, _, _),
    student(SID2, _, _),
    SID1 \= SID2,
    enroll(SID1, X),
    enroll(SID2, Y),
    (   X = Y
    ;   place(X, B, Xtime),
        place(Y, B, Ytime),
        Ytime =:= Xtime + 1
    ;   place(X, B, Xtime),
        place(Y, B, Ytime),
        Xtime =:= Ytime + 1
    ).
/* F */
roster(CRN, Sname):-
    section(CRN, _),
    enroll(SID, CRN),
    student(SID, Sname, _).
/* G */
highCredits(Cname):-
    course(_, Cname, Credits),
    Credits >= 4.

/************
  Problem 2
************/
/* A */
rdup([], []).
rdup([X], [X]).
rdup([X,X|L], M):-
    rdup([X|L], M).
rdup([X,Y|L], [X|M]):-
    X \= Y,
    rdup([Y|L], M).
/* B */
flat([], []).
flat([X|L], F):-
    flat(X, FX),
    flat(L, FL),
    append(FX, FL, F).
flat(L, [L]):-
    \+ is_list(L).
/* C */
project([], _, []).
project([I|IL], EL, [X|L]) :-
    element_at(I, EL, X),
    project(IL, EL, L).

element_at(1, [X|_], X) :- !.
element_at(I, [_|EL], X) :-
    I > 1,
    I1 is I - 1,
    element_at(I1, EL, X).