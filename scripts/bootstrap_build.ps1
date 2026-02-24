param(
    [string]$VcpkgPath = "$PSScriptRoot\..\vcpkg",
    [string]$Triplet = "x64-windows"
)

Write-Host "Bootstrapping vcpkg (if needed) at $VcpkgPath"
if (-not (Test-Path $VcpkgPath)) {
    git clone https://github.com/microsoft/vcpkg.git $VcpkgPath
}

Push-Location $VcpkgPath
if (-not (Test-Path .\vcpkg.exe)) {
    .\bootstrap-vcpkg.bat
}
Write-Host "Installing packages: sdl2 glm glad"
.\vcpkg.exe install sdl2 glm glad:$Triplet

Pop-Location

$proj = Join-Path $PSScriptRoot ".."
$build = Join-Path $proj "build"
if (-not (Test-Path $build)) { New-Item -ItemType Directory -Path $build | Out-Null }

$toolchain = Join-Path $VcpkgPath "scripts\buildsystems\vcpkg.cmake"

Push-Location $build
cmake .. -A x64 -DCMAKE_TOOLCHAIN_FILE="$toolchain"
cmake --build . --config Release
Pop-Location

Write-Host "Build complete. Executable will be in build\Release\voxel_demo.exe"
