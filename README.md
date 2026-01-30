

### Running

> gcc  -Wall -Wextra -Werror .\src\*.c -o build/main; .\build\main.exe
> gcc (Get-ChildItem -Path .\src -Recurse -Filter *.c | ForEach-Object { $_.FullName }) -o build/main.exe ; .\build\main.exe
