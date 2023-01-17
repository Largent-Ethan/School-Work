-- Title: Program 1
-- Name: Ethan Largent
-- Date: 7 November 2022

-- Company Database from the textbook

create table DEPARTMENT (
  Dname varchar(20) not null,
  Dnumber int(2) not null check (Dnumber > 0 and Dnumber < 41),  
  Mgr_ssn char(9) not null,   
  Mgr_start_date date not null, 
  primary key (Dnumber), 
  unique (Dname)
)ENGINE = INNODB;

create table EMPLOYEE (
  Fname varchar(15) not null,
  Lname varchar(15) not null,
  Ssn char(9) not null,  
  Bdate date not null,
  Address varchar(30) not null,
  Sex char(1) not null,
  Salary decimal(10,2) not null,
  Super_ssn char(9),
  Dno int(2) not null,
  constraint Fullname UNIQUE(Fname, Lname),  
  primary key (Ssn), 
  foreign key (Dno) references DEPARTMENT(Dnumber)
)ENGINE = INNODB;

create table PROJECT (
  Pname varchar(20) not null,
  Pnumber int(4) not null,  
  Plocation varchar(20) not null,
  Dnum int(2) not null, 
  primary key (Pnumber), 
  unique (Pname), 
  foreign key (Dnum) references DEPARTMENT(Dnumber)
)ENGINE = INNODB; 

create table WORKS_ON (
  Essn char(9) not null,  
  Pno int(2) not null, 
  Hours decimal(3,1),  
  primary key (Essn, Pno), 
  foreign key (Essn) references EMPLOYEE(Ssn),
  foreign key (Pno) references PROJECT(Pnumber)
)ENGINE = INNODB; 

create table DEPENDENT (
  Essn char(9) not null,  
  Dependent_name varchar(15) not null,
  Sex char(1) not null,
  Bdate date not null,
  Relationship varchar(8) not null,
  primary key (Essn, Dependent_name),
  foreign key (Essn) references EMPLOYEE(Ssn)
)ENGINE = INNODB; 

create table DEPT_LOCATIONS (
  Dnumber int(2) not null,
  Dlocation varchar(15) not null,
  primary key (Dnumber, Dlocation), 
  foreign key (Dnumber) references DEPARTMENT(Dnumber)
)ENGINE = INNODB;

insert into DEPARTMENT values 
 ('Research',5,333445555,'1988-05-22'),
 ('Administration',4,987654321,'1995-01-01'),
 ('Headquarters',1,888665555,'1981-06-19');

insert into EMPLOYEE values 
 ('John','Smith',123456789,'1965-01-09','731 Fondren, Houston TX','M',30000,333445555,5),
 ('Franklin','Wong',333445555,'1965-12-08','638 Voss, Houston TX','M',40000,888665555,5),
 ('Alicia','Zelaya',999887777,'1968-01-19','3321 Castle, Spring TX','F',25000,987654321,4),
 ('Jennifer','Wallace',987654321,'1941-06-20','291 Berry, Bellaire TX','F',43000,888665555,4),
 ('Ramesh','Narayan',666884444,'1962-09-15','975 Fire Oak, Humble TX','M',38000,333445555,5),
 ('Joyce','English',453453453,'1972-07-31','5631 Rice, Houston TX','F',25000,333445555,5),
 ('Ahmad','Jabbar',987987987,'1969-03-29','980 Dallas, Houston TX','M',25000,987654321,4),
 ('James','Borg',888665555,'1937-11-10','450 Stone, Houston TX','M',55000,null,1);

insert into PROJECT values 
 ('ProductX',1,'Bellaire',5),
 ('ProductY',2,'Sugarland',5),
 ('ProductZ',3,'Houston',5),
 ('Computerization',10,'Stafford',4),
 ('Reorganization',20,'Houston',1),
 ('Newbenefits',30,'Stafford',4);

insert into WORKS_ON values 
 (123456789,1,32.5),
 (123456789,2,7.5),
 (666884444,3,40.0),
 (453453453,1,20.0),
 (453453453,2,20.0),
 (333445555,2,10.0),
 (333445555,3,10.0),
 (333445555,10,10.0),
 (333445555,20,10.0),
 (999887777,30,30.0),
 (999887777,10,10.0),
 (987987987,10,35.0),
 (987987987,30,5.0),
 (987654321,30,20.0),
 (987654321,20,15.0),
 (888665555,20,null);

insert into DEPENDENT values 
 (333445555,'Alice','F','1986-04-04','Daughter'),
 (333445555,'Theodore','M','1983-10-25','Son'),
 (333445555,'Joy','F','1958-05-03','Spouse'),
 (987654321,'Abner','M','1942-02-28','Spouse'),
 (123456789,'Michael','M','1988-01-04','Son'),
 (123456789,'Alice','F','1988-12-30','Daughter'),
 (123456789,'Elizabeth','F','1967-05-05','Spouse');

insert into DEPT_LOCATIONS values
 (1,'Houston'),
 (4,'Stafford'),
 (5,'Bellaire'),
 (5,'Sugarland'),
 (5,'Houston');

alter table DEPARTMENT 
 add constraint depemp foreign key (Mgr_ssn) references EMPLOYEE(Ssn);

alter table EMPLOYEE   
 add constraint empemp foreign key (Super_ssn) references EMPLOYEE(Ssn);


-- --------------------------
-- Question 1 Create Table
-- --------------------------

CREATE TABLE DEPT_STATS (
    Dnumber int(2) not null,
    Emp_count int(11) not null,
    Avg_salary decimal(10,2) not null
)ENGINE = INNODB;

-- --------------------------
-- Question 2 Initialize Table
-- --------------------------

DELIMITER $$
CREATE PROCEDURE InitDeptStats()
BEGIN
    -- data variables
    DECLARE iDnumber int(2);
    DECLARE iEmp_count int(11);
    DECLARE iAvg_salary decimal(10,2);
    DECLARE salary_sum decimal(16,2);
    DECLARE emp_salary decimal(10,2);
    DECLARE emp_dnum int(2);
    -- outer loop variables
    DECLARE no_more_dept_data BOOLEAN DEFAULT false;
    DECLARE dept_cursor CURSOR for SELECT Dnumber FROM DEPARTMENT;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET no_more_dept_data = true;
    -- clear table
    DELETE FROM DEPT_STATS;
    -- loop through all departments
    OPEN dept_cursor;
myOutLoop: WHILE(no_more_dept_data = false)DO
    -- reset operating variables to 0
		SET iEmp_count = 0;
        SET iAvg_salary = 0;
        SET salary_sum = 0;
        FETCH dept_cursor INTO iDnumber;
        IF(no_more_dept_data)THEN
            CLOSE dept_cursor;
            leave myoutloop;
        END IF;
        BEGIN
    -- inner loop variables
        DECLARE no_more_emp_data BOOLEAN DEFAULT false;
        DECLARE emp_cursor CURSOR for SELECT Salary, Dno FROM EMPLOYEE;
        DECLARE CONTINUE HANDLER FOR NOT FOUND SET no_more_emp_data = true;
    -- loop through all employees
        OPEN emp_cursor;
myInLoop: WHILE(no_more_emp_data = false)DO
            FETCH emp_cursor INTO emp_salary, emp_dnum;
            IF(no_more_emp_data)THEN    
                CLOSE emp_cursor;
                leave myinloop;
            END IF;
    -- find employees that work in the department
            IF(emp_dnum = iDnumber)THEN
                SET salary_sum = salary_sum + emp_salary;
                SET iEmp_count = iEmp_count + 1;
            END IF;
        END WHILE;
        END;
    -- insert values into DEPT_STATS
        SET iAvg_salary = salary_sum / iEmp_count;
        insert into DEPT_STATS values (iDnumber, iEmp_count, iAvg_salary);
    END WHILE;
END $$

-- --------------------------
-- Question 3 DEPT_STATS Triggers
-- --------------------------

CREATE TRIGGER DELETEDeptStats AFTER DELETE ON EMPLOYEE FOR EACH ROW
BEGIN
    call InitDeptStats();
END $$

CREATE TRIGGER INSERTDeptStats AFTER INSERT ON EMPLOYEE FOR EACH ROW
BEGIN
    call InitDeptStats();
END $$

CREATE TRIGGER UPDATEDeptStats AFTER UPDATE ON EMPLOYEE FOR EACH ROW
BEGIN
    call InitDeptStats();
END $$

-- --------------------------
-- Question 4 WORKS_ON Trigger
-- --------------------------

CREATE TRIGGER INSERTWorksOn BEFORE INSERT ON WORKS_ON FOR EACH ROW
BEGIN
    DECLARE total_hours int(3);
    DECLARE error_msg varchar(100);
    SELECT SUM(Hours) INTO total_hours FROM WORKS_ON AS WO WHERE WO.Essn = New.Essn;
    IF(total_hours + New.Hours > 40)THEN
        SET error_msg = concat('You entered ', New.Hours, '. You currently work ', total_hours, '. You are over 40 hours.');
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = error_msg;
    END IF;
END $$

-- --------------------------
-- Question 5 PayLevel Function
-- --------------------------

CREATE FUNCTION PayLevel(empSsn char(9))
RETURNS varchar(20)
BEGIN
    DECLARE dept_avg_sal decimal (10,2);
    DECLARE emp_sal decimal (10,2);
    DECLARE emp_dnum int(2);

	SELECT Dno INTO emp_dnum FROM EMPLOYEE AS E WHERE E.Ssn = empSsn;
    SELECT Avg_salary INTO dept_avg_sal FROM DEPT_STATS AS D WHERE D.Dnumber = emp_dnum;
    SELECT Salary INTO emp_sal FROM EMPLOYEE AS E WHERE E.Ssn = empSsn;

    IF(dept_avg_sal < emp_sal)THEN
        RETURN 'Above Average';
    END IF;
    IF(dept_avg_sal > emp_sal)THEN
        RETURN 'Below Average';
    END IF;
    RETURN 'Average';
END $$
