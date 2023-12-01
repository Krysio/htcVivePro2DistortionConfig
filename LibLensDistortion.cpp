#include <windows.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <streambuf>
#include "hook_macro.h"

HINSTANCE mHinst = 0, mHinstDLL = 0;

extern "C" UINT_PTR mProcs[14] = {0};

LPCSTR mImportNames[] = {
  "calArgs",
  "distortPoint",
  "distortUV",
  "genMesh",
  "getEnlargeRatio",
  "getErrorMsg",
  "getGrowForUndistort",
  "getIntrinsic",
  "getSmartMeshPoints",
  "getSmartMeshSize",
  "init",
  "loadJson",
  "loadJsonStr",
  "setResolution",
};

#ifndef _DEBUG
inline void log_info(const char* info) {
}
#else
FILE* debug;
inline void log_info(const char* info) {
  fprintf(debug, "%s\n", info);
  fflush(debug);
}
#endif

/************************************/

std::ifstream configFile("C:\\Program Files (x86)\\VIVE\\Updater\\App\\ViveVRRuntime\\ViveVR\\ViveVRServer\\drivers\\vive_lh\\bin\\win64\\distortion.config.json");
std::string customConfig((std::istreambuf_iterator<char>(configFile)), std::istreambuf_iterator<char>());

#define LOADJSONSTR
FAKE(void, __cdecl, loadJsonStr, const char* originalJsonConfig) {
	loadJsonStr_real(customConfig.c_str());
}

/************************************/

inline void _hook_setup() {
#ifdef CALARGS
  calArgs_real = (calArgs_ptr)mProcs[0];
  mProcs[0] = (UINT_PTR)&calArgs_fake;
#endif
#ifdef DISTORTPOINT
  distortPoint_real = (distortPoint_ptr)mProcs[1];
  mProcs[1] = (UINT_PTR)&distortPoint_fake;
#endif
#ifdef DISTORTUV
  distortUV_real = (distortUV_ptr)mProcs[2];
  mProcs[2] = (UINT_PTR)&distortUV_fake;
#endif
#ifdef GENMESH
  genMesh_real = (genMesh_ptr)mProcs[3];
  mProcs[3] = (UINT_PTR)&genMesh_fake;
#endif
#ifdef GETENLARGERATIO
  getEnlargeRatio_real = (getEnlargeRatio_ptr)mProcs[4];
  mProcs[4] = (UINT_PTR)&getEnlargeRatio_fake;
#endif
#ifdef GETERRORMSG
  getErrorMsg_real = (getErrorMsg_ptr)mProcs[5];
  mProcs[5] = (UINT_PTR)&getErrorMsg_fake;
#endif
#ifdef GETGROWFORUNDISTORT
  getGrowForUndistort_real = (getGrowForUndistort_ptr)mProcs[6];
  mProcs[6] = (UINT_PTR)&getGrowForUndistort_fake;
#endif
#ifdef GETINTRINSIC
  getIntrinsic_real = (getIntrinsic_ptr)mProcs[7];
  mProcs[7] = (UINT_PTR)&getIntrinsic_fake;
#endif
#ifdef GETSMARTMESHPOINTS
  getSmartMeshPoints_real = (getSmartMeshPoints_ptr)mProcs[8];
  mProcs[8] = (UINT_PTR)&getSmartMeshPoints_fake;
#endif
#ifdef GETSMARTMESHSIZE
  getSmartMeshSize_real = (getSmartMeshSize_ptr)mProcs[9];
  mProcs[9] = (UINT_PTR)&getSmartMeshSize_fake;
#endif
#ifdef INIT
  init_real = (init_ptr)mProcs[10];
  mProcs[10] = (UINT_PTR)&init_fake;
#endif
#ifdef LOADJSON
  loadJson_real = (loadJson_ptr)mProcs[11];
  mProcs[11] = (UINT_PTR)&loadJson_fake;
#endif
#ifdef LOADJSONSTR
  loadJsonStr_real = (loadJsonStr_ptr)mProcs[12];
  mProcs[12] = (UINT_PTR)&loadJsonStr_fake;
#endif
#ifdef SETRESOLUTION
  setResolution_real = (setResolution_ptr)mProcs[13];
  mProcs[13] = (UINT_PTR)&setResolution_fake;
#endif
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
  mHinst = hinstDLL;
  if (fdwReason == DLL_PROCESS_ATTACH) {
    mHinstDLL = LoadLibrary("real_LibLensDistortion.dll");
    if (!mHinstDLL) {
      return FALSE;
    }
    for (int i = 0; i < 14; ++i) {
      mProcs[i] = (UINT_PTR)GetProcAddress(mHinstDLL, mImportNames[i]);
    }
    _hook_setup();
#ifdef _DEBUG
    debug = fopen("./debug.log", "a");
#endif
  } else if (fdwReason == DLL_PROCESS_DETACH) {
#ifdef _DEBUG
    fclose(debug);
#endif
    FreeLibrary(mHinstDLL);
  }
  return TRUE;
}

extern "C" void calArgs_wrapper();
extern "C" void distortPoint_wrapper();
extern "C" void distortUV_wrapper();
extern "C" void genMesh_wrapper();
extern "C" void getEnlargeRatio_wrapper();
extern "C" void getErrorMsg_wrapper();
extern "C" void getGrowForUndistort_wrapper();
extern "C" void getIntrinsic_wrapper();
extern "C" void getSmartMeshPoints_wrapper();
extern "C" void getSmartMeshSize_wrapper();
extern "C" void init_wrapper();
extern "C" void loadJson_wrapper();
extern "C" void loadJsonStr_wrapper();
extern "C" void setResolution_wrapper();
