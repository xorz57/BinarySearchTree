<h1 align="center">BinarySearchTree</h1>

<div align="center">
    <a href="https://sonarcloud.io/summary/new_code?id=xorz57_BinarySearchTree">
        <img src="https://sonarcloud.io/api/project_badges/measure?project=xorz57_BinarySearchTree&metric=alert_status" alt="Quality Gate Status">
    </a>
    <a href="https://sonarcloud.io/summary/new_code?id=xorz57_BinarySearchTree">
        <img src="https://sonarcloud.io/api/project_badges/measure?project=xorz57_BinarySearchTree&metric=bugs" alt="Bugs">
    </a>
    <a href="https://sonarcloud.io/summary/new_code?id=xorz57_BinarySearchTree">
        <img src="https://sonarcloud.io/api/project_badges/measure?project=xorz57_BinarySearchTree&metric=vulnerabilities" alt="Vulnerabilities">
    </a>
    <a href="https://sonarcloud.io/summary/new_code?id=xorz57_BinarySearchTree">
        <img src="https://sonarcloud.io/api/project_badges/measure?project=xorz57_BinarySearchTree&metric=code_smells" alt="Code Smells">
    </a>
    <a href="https://sonarcloud.io/summary/new_code?id=xorz57_BinarySearchTree">
        <img src="https://sonarcloud.io/api/project_badges/measure?project=xorz57_BinarySearchTree&metric=coverage" alt="Coverage">
    </a>
    <a href="https://sonarcloud.io/summary/new_code?id=xorz57_BinarySearchTree">
        <img src="https://sonarcloud.io/api/project_badges/measure?project=xorz57_BinarySearchTree&metric=duplicated_lines_density" alt="Duplicated Lines (%)">
    </a>
</div>

## How to Build

#### Linux & macOS

```bash
git clone https://github.com/microsoft/vcpkg.git ~/vcpkg
~/vcpkg/bootstrap-vcpkg.sh

git clone https://github.com/xorz57/BinarySearchTree.git
cd BinarySearchTree
cmake -B build -DCMAKE_BUILD_TYPE=Release -S . -DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
ctest --build-config Release
```

#### Windows

```powershell
git clone https://github.com/microsoft/vcpkg.git C:/vcpkg
C:/vcpkg/bootstrap-vcpkg.bat
C:/vcpkg/vcpkg.exe integrate install

git clone https://github.com/xorz57/BinarySearchTree.git
cd BinarySearchTree
cmake -B build -DCMAKE_BUILD_TYPE=Release -S . -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
ctest --build-config Release
```
