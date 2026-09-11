MSYS2 initial configuration
```shell
pacman -S --needed mingw-w64-ucrt-x86_64-opencv
pacman -Q | grep opencv
pacman -S mingw-w64-ucrt-x86_64-qt6-base
```

Create the file c_cpp_properties.json under the .vscode directory and copy the following content. This sets the includePath to be "C:/msys64/ucrt64/include/opencv5" and thus the main.cpp include statements can start with opencv2, like #include <opencv2/opencv.hpp>

```json
{
    "configurations": [
        {
            "name": "MSYS2 UCRT64",
            "includePath": [
                "${workspaceFolder}/**",
                "C:/msys64/ucrt64/include/opencv5"
            ],
            "compilerPath": "C:/msys64/ucrt64/bin/g++.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "windows-gcc-x64"
        }
    ],
    "version": 4
}
```
Then create the file tasks.json and copy the following. This file specifies libraries and headers

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "cppbuild",
            "label": "Build OpenCV Selective Search",
            "command": "C:/msys64/ucrt64/bin/g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-I",
                "C:/msys64/ucrt64/include/opencv5",
                "-L",
                "C:/msys64/ucrt64/lib",
                "-lopencv_ximgproc",
                "-lopencv_highgui",
                "-lopencv_imgcodecs",
                "-lopencv_imgproc",
                "-lopencv_core",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

Then go to configure terminal settings and add
```json
{
    "terminal.integrated.profiles.windows": {
        "MSYS2 UCRT64": {
            "path": "C:\\msys64\\usr\\bin\\bash.exe",
            "args": ["--login", "-i"],
            "env": {
                "MSYSTEM": "UCRT64",
                "MSYS2_PATH_TYPE": "inherit"
            }
        }
    },
    "terminal.integrated.defaultProfile.windows": "MSYS2 UCRT64"
}
```


git remote set-url origin git@MC1:Mel-Capcha-C/Computer-Vision-Path-Learning.git
git remote -v
origin  git@MC1:Mel-Capcha-C/Computer-Vision-Path-Learning.git (fetch)
origin  git@MC1:Mel-Capcha-C/Computer-Vision-Path-Learning.git (push)