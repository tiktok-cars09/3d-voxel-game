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

**Linux (Ubuntu / Debian / Fedora / Arch)**

You can either use your distro packages for SDL2/GLM and a system GL loader, or use `vcpkg` (same as Windows). Below are step-by-step tutorials for each distro.

Ubuntu / Debian (detailed)

1) Install toolchain, CMake and dev packages:

```bash
sudo apt update
sudo apt install build-essential cmake git pkg-config libsdl2-dev libglm-dev libgl1-mesa-dev
```

2) Clone, configure and build the project:

```bash
git clone https://github.com/YOUR_USER/YOUR_REPO.git
cd YOUR_REPO
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

3) Run the binary:

```bash
./voxel_demo
```

Notes for Debian/Ubuntu:
- If `cmake` is old in your distro, install a newer CMake from Kitware or use `vcpkg` toolchain.
- If `glad` isn't packaged, use the `vcpkg` flow below or add a generated glad.c to the project.

Fedora (detailed)

1) Install development tools and libs:

```bash
sudo dnf groupinstall "Development Tools"
sudo dnf install cmake git SDL2-devel glm-devel mesa-libGL-devel pkgconfig
```

2) Clone and build:

```bash
git clone https://github.com/YOUR_USER/YOUR_REPO.git
cd YOUR_REPO
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

3) Run:

```bash
./voxel_demo
```

Arch Linux / Manjaro (detailed)

1) Install packages via pacman:

```bash
sudo pacman -Syu base-devel cmake git sdl2 glm mesa
```

2) Clone and build:

```bash
git clone https://github.com/YOUR_USER/YOUR_REPO.git
cd YOUR_REPO
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

3) Run:

```bash
./voxel_demo
```

Using vcpkg on Linux (optional, cross-distro)

If you want consistent, repeatable dependencies across distros, use `vcpkg` to install `sdl2`, `glm` and `glad` and configure CMake with the vcpkg toolchain.

```bash
git clone https://github.com/microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh
./vcpkg/vcpkg install sdl2 glm glad
cmake .. -DCMAKE_TOOLCHAIN_FILE=/full/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build .
```

Troubleshooting & tips
- If `cmake` cannot find SDL2/GLM, verify the dev packages are installed or use the `vcpkg` toolchain.
- If OpenGL context creation fails, update Mesa or vendor drivers and check hybrid GPU configuration (PRIME) on laptops.
- If you need a GL loader (glad) and your distro doesn't provide one, vendor a generated `glad.c` or use `vcpkg` to supply it.

GPU / drivers: ensure your system has working OpenGL drivers (Mesa or vendor drivers) that support OpenGL 3.3 core.
