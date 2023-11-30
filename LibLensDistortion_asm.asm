.code
extern mProcs:QWORD
calArgs_wrapper proc
  jmp mProcs[0 * 8]
calArgs_wrapper endp
distortPoint_wrapper proc
  jmp mProcs[1 * 8]
distortPoint_wrapper endp
distortUV_wrapper proc
  jmp mProcs[2 * 8]
distortUV_wrapper endp
genMesh_wrapper proc
  jmp mProcs[3 * 8]
genMesh_wrapper endp
getEnlargeRatio_wrapper proc
  jmp mProcs[4 * 8]
getEnlargeRatio_wrapper endp
getErrorMsg_wrapper proc
  jmp mProcs[5 * 8]
getErrorMsg_wrapper endp
getGrowForUndistort_wrapper proc
  jmp mProcs[6 * 8]
getGrowForUndistort_wrapper endp
getIntrinsic_wrapper proc
  jmp mProcs[7 * 8]
getIntrinsic_wrapper endp
getSmartMeshPoints_wrapper proc
  jmp mProcs[8 * 8]
getSmartMeshPoints_wrapper endp
getSmartMeshSize_wrapper proc
  jmp mProcs[9 * 8]
getSmartMeshSize_wrapper endp
init_wrapper proc
  jmp mProcs[10 * 8]
init_wrapper endp
loadJson_wrapper proc
  jmp mProcs[11 * 8]
loadJson_wrapper endp
loadJsonStr_wrapper proc
  jmp mProcs[12 * 8]
loadJsonStr_wrapper endp
setResolution_wrapper proc
  jmp mProcs[13 * 8]
setResolution_wrapper endp
end