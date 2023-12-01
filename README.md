# HTC Vive Pro 2 custom barrel distortion configuration

Project generator: `https://github.com/mavenlin/wrap_dll`

### Build

- `mkdir build`
- `cd build`
- `cmake ..`
- `cmake -build . --config Release`

### Instalation

In the directory `C:\Program Files (x86)\VIVE\Updater\App\ViveVRRuntime\ViveVR\ViveVRServer\drivers\vive_lh\bin\win64`
 - rename `LibLensDistortion.dll` to `real_LibLensDistortion.dll`
 - paste release `LibLensDistortion.dll`
 - paste config as `distortion.config.json`