SELECT ename
FROM emp
WHERE salary <= ALL
(SELECT salary FROM emp);