@if not defined _echo echo off

rem Builds YRpp-Spawner DevBuild-HardEnd.

rem Ensure we're in correct directory.
cd /D "%~dp0"

call run_msbuild /maxCpuCount /consoleloggerparameters:NoSummary /property:Configuration=DevBuild-HardEnd
