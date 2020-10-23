set @a := -1;
select A.hour, IfNULL(B.count, 0)
from(select @a:=@a+1 as hour from animal_outs) A left join
(select count(*) as count, hour(datetime) as hour
 from animal_outs
 group by hour(datetime)
) B on A.hour = B.hour limit 24