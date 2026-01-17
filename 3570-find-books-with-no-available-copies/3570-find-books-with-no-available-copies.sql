# Write your MySQL query statement below
select lb.book_id, lb.title, lb.author, lb.genre, lb.publication_year, total_copies as current_borrowers 
from library_books lb left join borrowing_records br on lb.book_id = br.book_id and return_date is null
group by lb.book_id having count(br.record_id) = total_copies
order by current_borrowers desc, lb.title asc;