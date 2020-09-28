-- 코드를 입력하세요
SELECT name, count(*) as count from animal_ins
WHERE NAME IS NOT NULL
group by name
having count > 1
order by name asc