SELECT distinct l1.Num AS ConsecutiveNums
FROM Logs l1
JOIN Logs l2 ON l2.Id = l1.Id + 1
JOIN Logs l3 ON l3.Id = l1.Id + 2
WHERE l1.Num = l2.Num AND l2.Num = l3.Num;