rem @echo off
set PROJECT_HOME=samples\AllNotations
start astah-com\astah-command.bat -f %PROJECT_HOME%\Design.asta -image -o %PROJECT_HOME%\Image -t png
start astah-com\astah-command.bat -f %PROJECT_HOME%\Design.asta -image -o %PROJECT_HOME%\TransImg -t png

