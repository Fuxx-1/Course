cd  %~dp0
call git add --all
call git commit -m "%date:~0,4%-%date:~5,2%-%date:~8,2%"
call git push -u origin master