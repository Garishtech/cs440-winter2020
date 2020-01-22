SELECT did, dname
FROM dept
WHERE did IN
(SELECT did FROM works WHERE pct_time = 50);