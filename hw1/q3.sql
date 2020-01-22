SELECT dname
FROM dept
WHERE did NOT IN
(SELECT did FROM works);