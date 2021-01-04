-- 1. How many dogs and cats are there
SELECT ANIMAL_TYPE, COUNT(ANIMAL_TYPE) FROM ANIMAL_INS WHERE ANIMAL_TYPE = 'Cat'
UNION
SELECT ANIMAL_TYPE, COUNT(ANIMAL_TYPE) FROM ANIMAL_INS WHERE ANIMAL_TYPE = 'Dog'

-- 2. How many animals have same name
SELECT DISTINCT NAME, COUNT(NAME) AS COUNT FROM ANIMAL_INS  GROUP BY NAME HAVING COUNT(NAME) >= 2 ORDER BY NAME

-- 3. Calculate income date (1) : calculate without count 0
SELECT DISTINCT HOUR(DATETIME) AS HOUR, COUNT(HOUR(DATETIME)) FROM ANIMAL_OUTS GROUP BY HOUR HAVING HOUR >= 9 AND HOUR <= 19 ORDER BY HOUR

-- 4. Calculate income date (2) : calculate include count 0
SET @HOUR = -1;

SELECT (@HOUR := @HOUR + 1) AS HOUR, (SELECT COUNT(*) FROM ANIMAL_OUTS WHERE HOUR(DATETIME) = @HOUR) AS COUNT
FROM ANIMAL_OUTS
WHERE @HOUR < 23;