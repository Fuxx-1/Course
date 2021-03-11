::[Bat To Exe Converter]
::
::YAwzoRdxOk+EWAnk
::fBw5plQjdG8=
::YAwzuBVtJxjWCl3EqQJgSA==
::ZR4luwNxJguZRRnk
::Yhs/ulQjdF+5
::cxAkpRVqdFKZSDk=
::cBs/ulQjdF+5
::ZR41oxFsdFKZSDk=
::eBoioBt6dFKZSDk=
::cRo6pxp7LAbNWATEpCI=
::egkzugNsPRvcWATEpCI=
::dAsiuh18IRvcCxnZtBJQ
::cRYluBh/LU+EWAnk
::YxY4rhs+aU+JeA==
::cxY6rQJ7JhzQF1fEqQJQ
::ZQ05rAF9IBncCkqN+0xwdVs0
::ZQ05rAF9IAHYFVzEqQJQ
::eg0/rx1wNQPfEVWB+kM9LVsJDGQ=
::fBEirQZwNQPfEVWB+kM9LVsJDGQ=
::cRolqwZ3JBvQF1fEqQJQ
::dhA7uBVwLU+EWDk=
::YQ03rBFzNR3SWATElA==
::dhAmsQZ3MwfNWATElA==
::ZQ0/vhVqMQ3MEVWAtB9wSA==
::Zg8zqx1/OA3MEVWAtB9wSA==
::dhA7pRFwIByZRRnk
::Zh4grVQjdCmDJHSd0ks8LQhobwuXLni/OjLoF24TH218bMjAoWXiiQYaD/qLOOVz
::YB416Ek+ZG8=
::
::
::978f952a14a936cc963da21a135fa983
@echo off
chcp 65001
cls
echo Designed For Fuxx-1【@GitHub�?
echo '软件版本：v1.0.0'
echo 作者：Fuxx-1【@GitHub】，博客链接：fuxx-1.github.io
echo 声明：本软件仅供学习参考，不做任何商业用途！
echo *****按任意键生成网页*****

pause > nul

del %~dp0index.html

echo ^<^!DOCTYPE html^> > %~dp0temp.txt
echo     ^<html lang="en"^> >> %~dp0temp.txt
echo     ^<head^> >> %~dp0temp.txt
echo         ^<style^> >> %~dp0temp.txt
echo             .main { >> %~dp0temp.txt
echo                 width: 65^vw; >> %~dp0temp.txt
echo                 height: 100^vh; >> %~dp0temp.txt
echo                 margin: auto; >> %~dp0temp.txt
echo                 background-color: rgba(255, 255, 255, 0.7); >> %~dp0temp.txt
echo                 backdrop-filter: blur(7.5px); >> %~dp0temp.txt
echo                 border-radius: 10px 10px 10px 10px; >> %~dp0temp.txt
echo             } >> %~dp0temp.txt
echo             .link { >> %~dp0temp.txt
echo                 width: 50^vw; >> %~dp0temp.txt
echo                 margin: auto; >> %~dp0temp.txt
echo                 background-color: rgba(255, 255, 255, 0); >> %~dp0temp.txt
echo             } >> %~dp0temp.txt
echo             body { >> %~dp0temp.txt
echo                 background-image: url(https://fuxx-1.gitee.io/images/background.png); >> %~dp0temp.txt
echo                 background-size: 100^vw 100^vh; >> %~dp0temp.txt
echo                 background-attachment: fixed; >> %~dp0temp.txt
echo             } >> %~dp0temp.txt
echo         ^</style^> >> %~dp0temp.txt
echo         ^<meta charset="UTF-8"^> >> %~dp0temp.txt
echo         ^<meta http-equiv="X-UA-Compatible" content="IE=edge"^> >> %~dp0temp.txt
echo         ^<meta name="viewport" content="width=device-width, initial-scale=1.0"^> >> %~dp0temp.txt
echo         ^<title^>我的网页^</title^> >> %~dp0temp.txt
echo     ^</head^> >> %~dp0temp.txt
echo     ^<body^> >> %~dp0temp.txt
echo         ^<div class="main"^> >> %~dp0temp.txt
echo             ^<div class="link"^> >> %~dp0temp.txt
echo                 ^<br^> >> %~dp0temp.txt
echo                 ^<h1^ align="center"^>我的网页^</h1^> >> %~dp0temp.txt
echo                 ^<br^> >> %~dp0temp.txt

for /r . %%g in (*.html) do (echo ^<a href="%%g" target="_blank"^>%%~nxg^</a^>^<br^>^<br^> >> %~dp0temp.txt)

echo             ^</div^> >> %~dp0temp.txt
echo         ^</div^> >> %~dp0temp.txt
echo     ^</body^> >> %~dp0temp.txt
echo     ^</html^> >> %~dp0temp.txt


SetLocal EnableDelayedExpansion
Set File=%~dp0temp.txt
Set Str=%~dp0
Set Replace=http://fuxx-1.github.io/Course/
Set File=%File:"=%
For /F "Usebackq Delims=" %%i In ("%File%") Do (
    Set "Line=%%i"
    Echo !Line:%Str%=%Replace%! >> index.html
)
del %~dp0temp.txt
echo 完成
pause > nul