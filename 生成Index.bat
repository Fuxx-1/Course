@echo off
chcp 65001
cls

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
echo                 background-color: rgba(255, 255, 255, 0);
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
pause