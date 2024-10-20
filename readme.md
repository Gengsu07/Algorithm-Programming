### Settings,

- https://youtu.be/oC69vlWofJQ
- https://code.visualstudio.com/docs/cpp/config-mingw#_prerequisites

### Flowchart docs using mermaid

- https://mermaid.js.org/syntax/flowchart.html
- https://docs.mermaidchart.com/mermaid/flowchart/syntax
- install mermaid cli buat convertt npm install -g @mermaid-js/mermaid-cli

### Emoji List

https://emojibase.dev/shortcodes/?

delete build files:

- mac

```bash
find . \( -type d \( -name "*.dSYM" -o -name "build" \) -exec rm -rf {} + \) -o \( -type f \( -name "*.o" -o -name "*.out" -o -name "*.exe" \) -delete \)
```

- linux

```bash
#!/bin/bash

# Find and remove directories named "*.dSYM" or "build"
find . \( -type d \( -name "*.dSYM" -o -name "build" \) -exec rm -rf {} + \)

# Find and delete files with extensions .o, .out, .exe
find . \( -type f \( -name "*.o" -o -name "*.out" -o -name "*.exe" \) -delete \)
```

- windows

```bash
@echo off

REM Remove directories named "*.dSYM" or "build"
for /d %%D in (*.dSYM build) do (
    if exist "%%D" rd /s /q "%%D"
)

REM Delete files with extensions .o, .out, .exe
for %%F in (*.o *.out *.exe) do (
    if exist "%%F" del /q "%%F"
)

REM Recursively handle subdirectories
for /r %%D in (.) do (
    pushd %%D
    for /d %%S in (*.dSYM build) do (
        if exist "%%S" rd /s /q "%%S"
    )
    for %%F in (*.o *.out *.exe) do (
        if exist "%%F" del /q "%%F"
    )
    popd
)

```
