-- 1. ID who has no name
SELECT ANIMAL_ID FROM ANIMAL_INS WHERE ISNULL(NAME)

-- 2. ID who has name
SELECT ANIMAL_ID FROM ANIMAL_INS WHERE !ISNULL(NAME) ORDER BY ANIMAL_ID

-- 3. process Null value
SELECT ANIMAL_TYPE, IFNULL(NAME, 'No name'), SEX_UPON_INTAKE FROM ANIMAL_INS ORDER BY ANIMAL_ID