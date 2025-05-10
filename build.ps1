$msbuildPath = "C:\Program Files\Microsoft Visual Studio\2022\Preview\MSBuild\Current\Bin\MSBuild.exe"

# Run MSBuild directly
& $msbuildPath /property:GenerateFullPaths=true /t:build /consoleloggerparameters:NoSummary cvutil.sln

Write-Host "Press any key to continue..."
$null = $Host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown") 