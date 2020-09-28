select hour(datetime) as hour, count(*)
from animal_outs
group by hour(datetime)
having hour >= 9 && hour <= 19
order by hour asc