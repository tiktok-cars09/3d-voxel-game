# voxel_demo — minimal SDL2 + OpenGL cube

This project renders a slowly spinning cube (slightly tilted) using SDL2, GLAD and OpenGL 3.3 core.

Windows 11 build notes (recommended):

1. Install `vcpkg` and integrate with CMake (recommended):

```powershell
git clone https://github.com/microsoft/vcpkg.git
.\n+cd vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg integrate install
.
vcpkg install sdl2 glad glm
```

2. Configure and build with CMake from your workspace root:

```powershell
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake
cmake --build . --config Release
```
2. Install `vcpkg` and integrate with CMake (recommended).

Simplest option: run the provided bootstrap script which will clone/bootstrap vcpkg, install dependencies, configure and build the project:

```powershell
cd .\scripts
.\bootstrap_build.ps1 -VcpkgPath C:\path\to\vcpkg -Triplet x64-windows
```

Or manually:

```powershell
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg integrate install
.\vcpkg install sdl2 glm glad:x64-windows
```

Configure and build with CMake from your workspace root:

```powershell
mkdir build
cd build
cmake .. -A x64 -DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake
cmake --build . --config Release
```

3. Run `voxel_demo` executable produced in the build folder.


Required dependencies (installed by the script or via vcpkg):
- `sdl2`
- `glad`
- `glm`

Optional later:
- `stb_image` (textures)
- `imgui` (debug UI)

Important: I removed temporary local stub headers used earlier for editor checks; the project now expects real system/vcpkg-provided headers. Use the bootstrap script or install the packages via vcpkg before building.
