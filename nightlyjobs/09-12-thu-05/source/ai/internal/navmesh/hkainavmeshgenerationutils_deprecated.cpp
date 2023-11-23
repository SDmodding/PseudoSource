// File Line: 84
// RVA: 0xBA63C0
void __fastcall hkaiNavMeshGenerationUtils::DeprecatedGenerationOutputs::DeprecatedGenerationOutputs(
        hkaiNavMeshGenerationUtils::DeprecatedGenerationOutputs *this)
{
  this->m_cuttingGeom = 0i64;
  this->m_walkableGeom = 0i64;
  this->m_extrudedCuttingGeom = 0i64;
  this->m_unsimplifiedNavMesh = 0i64;
  this->m_navMesh = 0i64;
}

// File Line: 90
// RVA: 0xBA63E0
hkaiNavMeshGenerationResult::GenerationResultEnum __fastcall hkaiNavMeshGenerationUtils::generateNavMeshDeprecated(
        hkaiNavMeshGenerationSettings *input,
        hkGeometry *triMeshIn,
        hkaiNavMesh *navMeshOut)
{
  hkaiNavMeshGenerationUtils::DeprecatedGenerationOutputs outputs; // [rsp+20h] [rbp-38h] BYREF

  hkaiNavMeshGenerationUtils::DeprecatedGenerationOutputs::DeprecatedGenerationOutputs(&outputs);
  outputs.m_navMesh = navMeshOut;
  return hkaiNavMeshGenerationUtils::_generateNavMeshDeprecated(input, triMeshIn, &outputs, 0i64);
}

// File Line: 101
// RVA: 0xBA6430
__int64 __fastcall hkaiNavMeshGenerationUtils::_generateNavMeshDeprecated(
        hkaiNavMeshGenerationSettings *input,
        hkGeometry *triMeshIn,
        hkaiNavMeshGenerationUtils::DeprecatedGenerationOutputs *outputs,
        hkaiEdgeGeometryRaycaster *edgeConnectionRayCaster)
{
  hkaiNavMeshGenerationUtils::DeprecatedGenerationOutputs *v5; // rsi
  _QWORD *Value; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r8
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkVector4f *m_navMesh; // rax
  unsigned int v13; // edi
  hkVector4f *v14; // rax
  hkaiEdgeGeometry *m_cuttingGeom; // r12
  hkaiEdgeGeometry *v16; // rdi
  hkaiEdgeGeometry *v17; // rcx
  hkaiEdgeGeometry *m_walkableGeom; // rax
  hkaiEdgeGeometry *m_extrudedCuttingGeom; // rax
  hkaiNavMesh *v20; // r13
  hkaiNavMesh *v21; // r15
  int m_edgeDataStriding; // eax
  __int64 m_size; // r12
  int SizeInBytesFor; // eax
  unsigned int v25; // r8d
  int v26; // ebx
  hkVector4f *v27; // rax
  __int64 i; // rbx
  int m_capacityAndFlags; // eax
  hkVector4f v30; // xmm1
  int v31; // ebx
  int v32; // r9d
  hkVector4f *v33; // rax
  int v34; // edx
  int v35; // ecx
  int v36; // eax
  int v37; // eax
  int v38; // r9d
  hkRefPtr<hkaiVolume const > *v39; // r12
  __int64 v40; // rbx
  hkReferencedObject *m_pntr; // rcx
  __int64 v42; // rcx
  hkRefPtr<hkaiVolume const > *m_data; // r12
  __int64 v44; // rbx
  hkRefPtr<hkaiVolume const > *v45; // rsi
  __int64 v46; // r13
  hkReferencedObject *v47; // rcx
  hkReferencedObject *v48; // rcx
  hkaiVolume *v49; // rax
  hkRefPtr<hkaiVolume const > *v50; // rbx
  hkRefPtr<hkaiVolume const > *v51; // rcx
  __int64 v52; // rdx
  __int64 v53; // rcx
  hkaiVolume **v54; // r12
  _QWORD **v55; // rax
  hkaiInvertedAabbVolume *v56; // rax
  hkaiVolume *v57; // rax
  hkaiVolume *v58; // r12
  int v59; // ecx
  hkRefPtr<hkaiVolume const > *v60; // rbx
  hkRefPtr<hkaiVolume const > *v61; // rdx
  __int64 v62; // rax
  hkReferencedObject *v63; // rcx
  __m128 v64; // xmm2
  __m128 v65; // xmm3
  hkArray<hkRefPtr<hkaiMaterialPainter const >,hkContainerHeapAllocator> *p_m_painters; // r12
  hkVector4f *v67; // rax
  hkVector4f *v68; // rax
  _QWORD *v69; // r8
  _QWORD *v70; // rcx
  unsigned __int64 v71; // rax
  _QWORD *v72; // rcx
  float m_quantizationGridSize; // xmm1_4
  int v74; // ebx
  int v75; // r12d
  int v76; // eax
  hkErrStream *v77; // rcx
  int v78; // eax
  int v79; // eax
  int v80; // r9d
  int v81; // ebx
  int v82; // r9d
  int v83; // r9d
  int v84; // r9d
  hkVector4f *v85; // rax
  hkErrStream *v86; // rcx
  hkVector4f *v87; // rax
  hkaiEdgeGeometry *v88; // rbx
  hkVector4f *v89; // rax
  hkErrStream *v90; // rcx
  unsigned int m_storage; // ebx
  unsigned int v92; // r8d
  hkaiEdgeGeometry *v93; // rbx
  hkVector4f *v94; // rax
  _QWORD *v95; // r8
  _QWORD *v96; // rcx
  unsigned __int64 v97; // rax
  _QWORD *v98; // rcx
  _QWORD *v99; // r8
  _QWORD *v100; // rcx
  unsigned __int64 v101; // rax
  _QWORD *v102; // rcx
  _QWORD *v103; // r8
  _QWORD *v104; // rcx
  unsigned __int64 v105; // rax
  _QWORD *v106; // rcx
  hkVector4f *v107; // rax
  _QWORD *v108; // r8
  _QWORD *v109; // rcx
  unsigned __int64 v110; // rax
  _QWORD *v111; // rcx
  _QWORD *v112; // r8
  _QWORD *v113; // rcx
  unsigned __int64 v114; // rax
  _QWORD *v115; // rcx
  hkErrStream *v116; // rcx
  hkVector4f *v117; // rax
  _QWORD *v118; // r9
  _QWORD *v119; // rcx
  unsigned __int64 v120; // rax
  _QWORD *v121; // rcx
  hkaiEdgeGeometry *v122; // r12
  hkVector4f *v123; // rax
  _QWORD *v124; // r8
  _QWORD *v125; // rcx
  unsigned __int64 v126; // rax
  _QWORD *v127; // rcx
  _QWORD *v128; // r8
  _QWORD *v129; // rcx
  unsigned __int64 v130; // rax
  _QWORD *v131; // rcx
  _QWORD *v132; // rax
  _QWORD *v133; // rcx
  _QWORD *v134; // r8
  unsigned __int64 v135; // rax
  _QWORD *v136; // rcx
  hkVector4f *v137; // rax
  _QWORD *v138; // r8
  _QWORD *v139; // rcx
  unsigned __int64 v140; // rax
  _QWORD *v141; // rcx
  _QWORD *v142; // r9
  _QWORD *v143; // rcx
  unsigned __int64 v144; // rax
  _QWORD *v145; // rcx
  _QWORD *v146; // r8
  _QWORD *v147; // rcx
  unsigned __int64 v148; // rax
  _QWORD *v149; // rcx
  hkErrStream *v150; // rcx
  hkVector4f *v151; // rax
  _QWORD *v152; // r8
  _QWORD *v153; // rcx
  unsigned __int64 v154; // rax
  _QWORD *v155; // rcx
  _QWORD *v156; // r8
  _QWORD *v157; // rcx
  unsigned __int64 v158; // rax
  _QWORD *v159; // rcx
  int v160; // eax
  int v161; // r9d
  hkVector4f *v162; // rcx
  hkErrStream *v163; // rcx
  __m128 *p_m_quad; // rdx
  __int64 v165; // r8
  hkVector4f v166; // xmm0
  int v167; // ebx
  _QWORD *v168; // r8
  _QWORD *v169; // rcx
  unsigned __int64 v170; // rax
  _QWORD *v171; // rcx
  hkaiNavMesh *v172; // r12
  hkErrStream *v173; // rcx
  hkVector4f *v174; // rax
  _QWORD *v175; // r8
  _QWORD *v176; // rcx
  unsigned __int64 v177; // rax
  _QWORD *v178; // rcx
  _QWORD *v179; // r8
  _QWORD *v180; // rcx
  unsigned __int64 v181; // rax
  _QWORD *v182; // rcx
  hkErrStream *v183; // rcx
  __m128 v184; // xmm2
  hkaiNavMesh *m_unsimplifiedNavMesh; // rcx
  _QWORD *v186; // r8
  _QWORD *v187; // rcx
  unsigned __int64 v188; // rax
  _QWORD *v189; // rcx
  int v190; // ebx
  int v191; // r8d
  int v192; // eax
  int v193; // r8d
  int v194; // r8d
  int v195; // r8d
  hkVector4f *v196; // rax
  _QWORD *v197; // r8
  _QWORD *v198; // rcx
  unsigned __int64 v199; // rax
  _QWORD *v200; // rcx
  _QWORD *v201; // r9
  _QWORD *v202; // rcx
  unsigned __int64 v203; // rax
  _QWORD *v204; // rcx
  hkVector4f *v205; // rax
  hkVector4f *v206; // rax
  _QWORD *v207; // r8
  _QWORD *v208; // rcx
  unsigned __int64 v209; // rax
  _QWORD *v210; // rcx
  int v211; // ebx
  hkRefPtr<hkaiVolume const > *v212; // rsi
  _QWORD *v213; // rax
  _QWORD *v214; // rcx
  _QWORD *v215; // r8
  unsigned __int64 v216; // rax
  _QWORD *v217; // rcx
  hkArrayBase<hkRefPtr<hkaiVolume const > > carvers; // [rsp+80h] [rbp-80h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> vertsIn; // [rsp+90h] [rbp-70h] BYREF
  hkArrayBase<hk1AxisSweep::AabbInt> sortedAabbs; // [rsp+A0h] [rbp-60h] BYREF
  hkArrayBase<hkRadixSort::SortData32> sortData; // [rsp+B0h] [rbp-50h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> uniqueVerts; // [rsp+C0h] [rbp-40h] BYREF
  hkArrayBase<hk1AxisSweep::AabbInt> sweepAabbs; // [rsp+D0h] [rbp-30h] BYREF
  int v225; // [rsp+E0h] [rbp-20h]
  hkArray<int,hkContainerHeapAllocator> triangleRemapOut; // [rsp+E8h] [rbp-18h] BYREF
  char v227; // [rsp+F8h] [rbp-8h]
  char v228; // [rsp+F9h] [rbp-7h]
  hkArray<int,hkContainerHeapAllocator> vertexRemapOut; // [rsp+100h] [rbp+0h] BYREF
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> newTriangles; // [rsp+110h] [rbp+10h] BYREF
  void *array; // [rsp+120h] [rbp+20h] BYREF
  int v232; // [rsp+128h] [rbp+28h]
  int v233; // [rsp+12Ch] [rbp+2Ch]
  hkArray<int,hkContainerHeapAllocator> trisPerFaceOut; // [rsp+130h] [rbp+30h] BYREF
  hkResult v235; // [rsp+140h] [rbp+40h] BYREF
  hkResult v236; // [rsp+144h] [rbp+44h] BYREF
  hkResult v237; // [rsp+148h] [rbp+48h] BYREF
  hkArray<int,hkContainerHeapAllocator> trisOut; // [rsp+150h] [rbp+50h] BYREF
  hkResult v239; // [rsp+160h] [rbp+60h] BYREF
  __int64 v240; // [rsp+168h] [rbp+68h]
  hkResult v241; // [rsp+170h] [rbp+70h] BYREF
  hkResult v242; // [rsp+174h] [rbp+74h] BYREF
  hkResult v243; // [rsp+178h] [rbp+78h] BYREF
  hkResult v244; // [rsp+17Ch] [rbp+7Ch] BYREF
  hkResult v245; // [rsp+180h] [rbp+80h] BYREF
  hkResult v246; // [rsp+184h] [rbp+84h] BYREF
  hkResult v247; // [rsp+188h] [rbp+88h] BYREF
  int v248; // [rsp+18Ch] [rbp+8Ch]
  hkResult v249; // [rsp+190h] [rbp+90h] BYREF
  hkaiNavMesh *v250; // [rsp+198h] [rbp+98h]
  hkArray<int,hkContainerHeapAllocator> materialsOut; // [rsp+1A0h] [rbp+A0h] BYREF
  int v252; // [rsp+1B0h] [rbp+B0h] BYREF
  hkArray<int,hkContainerHeapAllocator> triConnectivityOut; // [rsp+1B8h] [rbp+B8h] BYREF
  hkaiEdgeGeometry *geomInOut; // [rsp+1C8h] [rbp+C8h]
  hkaiEdgeGeometry *extrudeGeom; // [rsp+1D0h] [rbp+D0h]
  hkResult v256; // [rsp+1D8h] [rbp+D8h] BYREF
  hkResult v257; // [rsp+1DCh] [rbp+DCh] BYREF
  hkResult v258; // [rsp+1E0h] [rbp+E0h] BYREF
  int newStride; // [rsp+1E4h] [rbp+E4h]
  hkResult v260; // [rsp+1E8h] [rbp+E8h] BYREF
  hkResult v261; // [rsp+1ECh] [rbp+ECh] BYREF
  hkaiCarverTree v262; // [rsp+1F0h] [rbp+F0h] BYREF
  hkResult v263; // [rsp+220h] [rbp+120h] BYREF
  hkResult v264; // [rsp+224h] [rbp+124h] BYREF
  hkResult v265; // [rsp+228h] [rbp+128h] BYREF
  hkResult v266; // [rsp+22Ch] [rbp+12Ch] BYREF
  hkGeometry dstGeom; // [rsp+230h] [rbp+130h] BYREF
  hkaiEdgeGeometry *geomOut; // [rsp+260h] [rbp+160h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v269; // [rsp+268h] [rbp+168h] BYREF
  hkResult result; // [rsp+278h] [rbp+178h] BYREF
  hkResult v271; // [rsp+27Ch] [rbp+17Ch] BYREF
  hkResult v272; // [rsp+288h] [rbp+188h] BYREF
  hkResult v273; // [rsp+28Ch] [rbp+18Ch] BYREF
  hkResult v274; // [rsp+290h] [rbp+190h] BYREF
  hkResult v275; // [rsp+294h] [rbp+194h] BYREF
  hkAabb pruneAabb; // [rsp+2A0h] [rbp+1A0h] BYREF
  hkErrStream v277; // [rsp+2C0h] [rbp+1C0h] BYREF
  hkErrStream v278; // [rsp+2D8h] [rbp+1D8h] BYREF
  hkErrStream v279; // [rsp+2F0h] [rbp+1F0h] BYREF
  hkErrStream v280; // [rsp+308h] [rbp+208h] BYREF
  hkErrStream v281; // [rsp+320h] [rbp+220h] BYREF
  hkErrStream v282; // [rsp+338h] [rbp+238h] BYREF
  hkErrStream v283; // [rsp+350h] [rbp+250h] BYREF
  hkErrStream v284; // [rsp+368h] [rbp+268h] BYREF
  hkErrStream v285; // [rsp+380h] [rbp+280h] BYREF
  hkErrStream v286; // [rsp+398h] [rbp+298h] BYREF
  hkErrStream v287; // [rsp+3B0h] [rbp+2B0h] BYREF
  hkErrStream v288; // [rsp+3C8h] [rbp+2C8h] BYREF
  hkErrStream v289; // [rsp+3E0h] [rbp+2E0h] BYREF
  hkErrStream v290; // [rsp+3F8h] [rbp+2F8h] BYREF
  hkErrStream v291; // [rsp+410h] [rbp+310h] BYREF
  hkErrStream v292; // [rsp+428h] [rbp+328h] BYREF
  hkErrStream v293; // [rsp+440h] [rbp+340h] BYREF
  hkErrStream v294; // [rsp+458h] [rbp+358h] BYREF
  hkErrStream v295; // [rsp+470h] [rbp+370h] BYREF
  hkErrStream v296; // [rsp+488h] [rbp+388h] BYREF
  hkErrStream v297; // [rsp+4A0h] [rbp+3A0h] BYREF
  hkErrStream v298; // [rsp+4B8h] [rbp+3B8h] BYREF
  hkErrStream v299; // [rsp+4D0h] [rbp+3D0h] BYREF
  hkErrStream v300; // [rsp+4E8h] [rbp+3E8h] BYREF
  hkErrStream v301; // [rsp+500h] [rbp+400h] BYREF
  hkErrStream v302; // [rsp+518h] [rbp+418h] BYREF
  hkErrStream v303; // [rsp+530h] [rbp+430h] BYREF
  hkErrStream v304; // [rsp+548h] [rbp+448h] BYREF
  hkErrStream v305; // [rsp+560h] [rbp+460h] BYREF
  hkErrStream v306; // [rsp+578h] [rbp+478h] BYREF
  hkErrStream v307; // [rsp+590h] [rbp+490h] BYREF
  hkErrStream v308; // [rsp+5A8h] [rbp+4A8h] BYREF
  hkErrStream v309; // [rsp+5C0h] [rbp+4C0h] BYREF
  hkErrStream v310; // [rsp+5D8h] [rbp+4D8h] BYREF
  hkErrStream v311; // [rsp+5F0h] [rbp+4F0h] BYREF
  hkErrStream v312; // [rsp+608h] [rbp+508h] BYREF
  hkErrStream v313; // [rsp+620h] [rbp+520h] BYREF
  hkErrStream v314; // [rsp+638h] [rbp+538h] BYREF
  hkErrStream v315; // [rsp+650h] [rbp+550h] BYREF
  hkErrStream v316; // [rsp+668h] [rbp+568h] BYREF
  hkErrStream v317; // [rsp+680h] [rbp+580h] BYREF
  hkErrStream v318; // [rsp+698h] [rbp+598h] BYREF
  hkErrStream v319; // [rsp+6B0h] [rbp+5B0h] BYREF
  hkErrStream v320; // [rsp+6C8h] [rbp+5C8h] BYREF
  hkaiCarverTree carverTree; // [rsp+6E0h] [rbp+5E0h] BYREF
  hkaiEdgeGeometryRaycaster cuttingGeomRaycaster; // [rsp+710h] [rbp+610h] BYREF
  hkaiGeometryToEdgeGeometryConverter v323; // [rsp+780h] [rbp+680h] BYREF
  hkaiEdgeGeometry v324; // [rsp+7E0h] [rbp+6E0h] BYREF
  hkaiEdgeGeometry v325; // [rsp+830h] [rbp+730h] BYREF
  hkaiEdgeGeometry v326; // [rsp+880h] [rbp+780h] BYREF
  hkaiNavMesh v327; // [rsp+8D0h] [rbp+7D0h] BYREF
  hkaiNavMesh v328; // [rsp+980h] [rbp+880h] BYREF
  char v329[512]; // [rsp+A30h] [rbp+930h] BYREF
  char v330[512]; // [rsp+C30h] [rbp+B30h] BYREF
  char description[512]; // [rsp+E30h] [rbp+D30h] BYREF
  char v332[512]; // [rsp+1030h] [rbp+F30h] BYREF
  char v333[512]; // [rsp+1230h] [rbp+1130h] BYREF
  char v334[512]; // [rsp+1430h] [rbp+1330h] BYREF
  char v335[512]; // [rsp+1630h] [rbp+1530h] BYREF
  char v336[512]; // [rsp+1830h] [rbp+1730h] BYREF
  char v337[512]; // [rsp+1A30h] [rbp+1930h] BYREF
  char v338[512]; // [rsp+1C30h] [rbp+1B30h] BYREF
  char v339[512]; // [rsp+1E30h] [rbp+1D30h] BYREF
  char v340[512]; // [rsp+2030h] [rbp+1F30h] BYREF
  char v341[512]; // [rsp+2230h] [rbp+2130h] BYREF
  char v342[512]; // [rsp+2430h] [rbp+2330h] BYREF
  char v343[512]; // [rsp+2630h] [rbp+2530h] BYREF
  char v344[512]; // [rsp+2830h] [rbp+2730h] BYREF
  char v345[512]; // [rsp+2A30h] [rbp+2930h] BYREF
  char v346[512]; // [rsp+2C30h] [rbp+2B30h] BYREF
  char v347[512]; // [rsp+2E30h] [rbp+2D30h] BYREF
  char v348[512]; // [rsp+3030h] [rbp+2F30h] BYREF
  char buf[512]; // [rsp+3230h] [rbp+3130h] BYREF
  char v350[512]; // [rsp+3430h] [rbp+3330h] BYREF
  char v351[512]; // [rsp+3630h] [rbp+3530h] BYREF
  char v352[512]; // [rsp+3830h] [rbp+3730h] BYREF
  char v353[512]; // [rsp+3A30h] [rbp+3930h] BYREF
  char v354[512]; // [rsp+3C30h] [rbp+3B30h] BYREF
  char v355[512]; // [rsp+3E30h] [rbp+3D30h] BYREF
  char v356[512]; // [rsp+4030h] [rbp+3F30h] BYREF
  char v357[512]; // [rsp+4230h] [rbp+4130h] BYREF
  char v358[512]; // [rsp+4430h] [rbp+4330h] BYREF
  char v359[512]; // [rsp+4630h] [rbp+4530h] BYREF
  char v360[512]; // [rsp+4830h] [rbp+4730h] BYREF
  char v361[512]; // [rsp+4A30h] [rbp+4930h] BYREF
  char v362[512]; // [rsp+4C30h] [rbp+4B30h] BYREF
  char v363[512]; // [rsp+4E30h] [rbp+4D30h] BYREF
  char v364[512]; // [rsp+5030h] [rbp+4F30h] BYREF
  char v365[512]; // [rsp+5230h] [rbp+5130h] BYREF
  char v366[512]; // [rsp+5430h] [rbp+5330h] BYREF
  char v367[512]; // [rsp+5630h] [rbp+5530h] BYREF
  char v368[512]; // [rsp+5830h] [rbp+5730h] BYREF
  char v369[512]; // [rsp+5A30h] [rbp+5930h] BYREF
  char v370[512]; // [rsp+5C30h] [rbp+5B30h] BYREF
  char v371[512]; // [rsp+5E30h] [rbp+5D30h] BYREF
  char v372[512]; // [rsp+6030h] [rbp+5F30h] BYREF
  hkGeometry *srcGeom; // [rsp+6278h] [rbp+6178h] BYREF
  hkaiNavMeshGenerationUtils::DeprecatedGenerationOutputs *v374; // [rsp+6280h] [rbp+6180h]
  hkaiEdgeGeometryRaycaster *raycaster; // [rsp+6288h] [rbp+6188h]

  raycaster = edgeConnectionRayCaster;
  v374 = outputs;
  srcGeom = triMeshIn;
  v5 = outputs;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)Value[1];
  v9 = Value;
  if ( (unsigned __int64)v8 < Value[3] )
  {
    *v8 = "TthkaiNavMeshGenerationUtils::generateNavMesh";
    v10 = __rdtsc();
    v11 = v8 + 2;
    *((_DWORD *)v11 - 2) = v10;
    v9[1] = v11;
  }
  if ( !triMeshIn->m_triangles.m_size )
  {
    hkErrStream::hkErrStream(&v306, buf, 512);
    hkOstream::operator<<(&v306, "Passed in empty triMesh to generateNavMesh()");
    hkError::messageWarning(1060047688, buf, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 108);
    hkOstream::~hkOstream(&v306);
    m_navMesh = (hkVector4f *)v5->m_navMesh;
    if ( m_navMesh )
    {
      m_navMesh[8] = (hkVector4f)aabbOut.m_quad;
      m_navMesh[9] = (hkVector4f)aabbOut.m_quad;
    }
    v13 = 1;
    goto LABEL_354;
  }
  if ( !HK_flyingcolors_ai_1.m_bool )
  {
    hkaiCheckKeycode();
    hkaiProcessFlyingColors(&HK_flyingcolors_ai_1);
    if ( !HK_flyingcolors_ai_1.m_bool )
    {
      hkErrStream::hkErrStream(&v317, description, 512);
      hkOstream::operator<<(&v317, "Invalid keycode. Exiting nav mesh generation.");
      hkError::messageWarning(691989308, description, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 120);
      hkOstream::~hkOstream(&v317);
      v14 = (hkVector4f *)v5->m_navMesh;
      if ( v14 )
      {
        v14[8] = (hkVector4f)aabbOut.m_quad;
        v14[9] = (hkVector4f)aabbOut.m_quad;
      }
      v13 = 3;
      goto LABEL_354;
    }
  }
  hkaiEdgeGeometry::hkaiEdgeGeometry(&v325);
  hkaiEdgeGeometry::hkaiEdgeGeometry(&v324);
  hkaiEdgeGeometry::hkaiEdgeGeometry(&v326);
  m_cuttingGeom = &v325;
  v16 = &v324;
  v17 = &v326;
  if ( v5->m_cuttingGeom )
    m_cuttingGeom = v5->m_cuttingGeom;
  m_walkableGeom = v5->m_walkableGeom;
  geomOut = m_cuttingGeom;
  if ( m_walkableGeom )
    v16 = m_walkableGeom;
  m_extrudedCuttingGeom = v5->m_extrudedCuttingGeom;
  geomInOut = v16;
  if ( m_extrudedCuttingGeom )
    v17 = m_extrudedCuttingGeom;
  extrudeGeom = v17;
  hkaiNavMesh::hkaiNavMesh(&v328);
  hkaiNavMesh::hkaiNavMesh(&v327);
  v20 = &v327;
  v21 = &v328;
  if ( v5->m_navMesh )
    v20 = v5->m_navMesh;
  m_edgeDataStriding = v20->m_edgeDataStriding;
  if ( !input->m_enableSimplification.m_bool )
    v21 = v20;
  v250 = v20;
  newStride = m_edgeDataStriding;
  hkaiNavMesh::setEdgeDataStriding(v20, &result, 0, 0);
  hkaiNavMesh::setEdgeDataStriding(v21, &v272, 0, 0);
  hkaiEdgeGeometry::clear(m_cuttingGeom);
  hkaiEdgeGeometry::clear(v16);
  hkaiEdgeGeometry::clear(extrudeGeom);
  if ( input->m_saveInputSnapshot.m_bool )
    hkaiNavMeshGenerationUtils::_saveSnapshot(input, triMeshIn);
  m_size = input->m_materialMap.m_size;
  v233 = 0x80000000;
  array = 0i64;
  v232 = 0;
  SizeInBytesFor = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(m_size);
  v25 = 0x80000000;
  v13 = 1;
  v26 = SizeInBytesFor;
  if ( SizeInBytesFor <= 0 )
  {
    v246.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v246, &hkContainerHeapAllocator::s_alloc, &array, SizeInBytesFor, 1);
    if ( v246.m_enum )
    {
      hkErrStream::hkErrStream(&v319, v367, 512);
      hkOstream::operator<<(
        &v319,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v367, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 193);
      hkOstream::~hkOstream(&v319);
      v27 = (hkVector4f *)v5->m_navMesh;
      if ( v27 )
      {
        v27[8] = (hkVector4f)aabbOut.m_quad;
        v27[9] = (hkVector4f)aabbOut.m_quad;
      }
      v13 = 2;
      goto LABEL_351;
    }
    v25 = v233;
  }
  v232 = v26;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
    &v269,
    array,
    v25 & 0x3FFFFFFF);
  for ( i = 0i64; i < m_size; ++i )
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &v269,
      &hkContainerHeapAllocator::s_alloc,
      (unsigned int)input->m_materialMap.m_data[i].m_materialIndex,
      input->m_materialMap.m_data[i].m_flags.m_storage);
  m_capacityAndFlags = 0x80000000;
  pruneAabb.m_min = input->m_boundsAabb.m_min;
  v30.m_quad = (__m128)input->m_boundsAabb.m_max;
  v31 = 0;
  carvers.m_data = 0i64;
  carvers.m_size = 0;
  carvers.m_capacityAndFlags = 0x80000000;
  pruneAabb.m_max = (hkVector4f)v30.m_quad;
  v32 = input->m_carvers.m_size + 1;
  if ( v32 <= 0 )
  {
    v242.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v242, &hkContainerTempAllocator::s_alloc, &carvers, v32, 8);
    if ( v242.m_enum )
    {
      hkErrStream::hkErrStream(&v280, v333, 512);
      hkOstream::operator<<(
        &v280,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v333, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 211);
      hkOstream::~hkOstream(&v280);
      v33 = (hkVector4f *)v5->m_navMesh;
      if ( v33 )
      {
        v33[8] = (hkVector4f)aabbOut.m_quad;
        v33[9] = (hkVector4f)aabbOut.m_quad;
      }
      v13 = 2;
      goto LABEL_345;
    }
    m_capacityAndFlags = carvers.m_capacityAndFlags;
    v31 = carvers.m_size;
  }
  v35 = input->m_carvers.m_size;
  v225 = v35;
  v34 = v35;
  if ( v35 > v31 )
    v35 = v31;
  v36 = m_capacityAndFlags & 0x3FFFFFFF;
  v248 = v35;
  if ( v36 >= v225 )
  {
    HIDWORD(v262.vfptr) = 0;
  }
  else
  {
    v37 = 2 * v36;
    v38 = v225;
    if ( v225 < v37 )
      v38 = v37;
    hkArrayUtil::_reserve((hkResult *)&v262.vfptr + 1, &hkContainerTempAllocator::s_alloc, &carvers, v38, 8);
    v34 = v225;
  }
  v39 = &carvers.m_data[v34];
  v40 = v31 - v34 - 1;
  if ( (int)v40 >= 0 )
  {
    do
    {
      m_pntr = v39[v40].m_pntr;
      if ( m_pntr )
        hkReferencedObject::removeReference(m_pntr);
      v39[v40--].m_pntr = 0i64;
    }
    while ( v40 >= 0 );
  }
  v42 = v248;
  m_data = input->m_carvers.m_data;
  v44 = 0i64;
  v240 = v248;
  if ( v248 > 0 )
  {
    v45 = carvers.m_data;
    v46 = v248;
    do
    {
      v47 = m_data[v44].m_pntr;
      if ( v47 )
        hkReferencedObject::addReference(v47);
      v48 = v45[v44].m_pntr;
      if ( v48 )
        hkReferencedObject::removeReference(v48);
      v49 = m_data[v44++].m_pntr;
      v45[v44 - 1].m_pntr = v49;
    }
    while ( v44 < v46 );
    v5 = v374;
    v20 = v250;
    v42 = v240;
  }
  v50 = &input->m_carvers.m_data[v42];
  v51 = &carvers.m_data[v42];
  v52 = v225 - v248;
  v240 = v52;
  if ( v225 - v248 > 0 )
  {
    v53 = (char *)v51 - (char *)v50;
    v250 = (hkaiNavMesh *)v53;
    do
    {
      v54 = (hkaiVolume **)((char *)&v50->m_pntr + v53);
      if ( (hkRefPtr<hkaiVolume const > *)((char *)v50 + v53) )
      {
        if ( v50->m_pntr )
        {
          hkReferencedObject::addReference(v50->m_pntr);
          v52 = v240;
        }
        v53 = (__int64)v250;
        *v54 = v50->m_pntr;
      }
      ++v50;
      v240 = --v52;
    }
    while ( v52 );
  }
  carvers.m_size = v225;
  if ( (_mm_movemask_ps(_mm_cmple_ps(input->m_boundsAabb.m_max.m_quad, input->m_boundsAabb.m_min.m_quad)) & 7) == 0 )
  {
    v55 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v56 = (hkaiInvertedAabbVolume *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v55[11] + 8i64))(v55[11], 96i64);
    if ( v56 )
    {
      hkaiInvertedAabbVolume::hkaiInvertedAabbVolume(v56, &input->m_boundsAabb);
      v58 = v57;
    }
    else
    {
      v58 = 0i64;
    }
    v59 = carvers.m_size;
    if ( carvers.m_size == (carvers.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &carvers, 8);
      v59 = carvers.m_size;
    }
    v60 = carvers.m_data;
    v61 = &carvers.m_data[v59];
    if ( v61 )
    {
      v61->m_pntr = 0i64;
      v59 = carvers.m_size;
      v60 = carvers.m_data;
    }
    v62 = v59;
    carvers.m_size = v59 + 1;
    v63 = v60[v59].m_pntr;
    v250 = (hkaiNavMesh *)v62;
    if ( v63 && v63 != v58 )
    {
      hkReferencedObject::removeReference(v63);
      v62 = (__int64)v250;
    }
    v60[v62].m_pntr = v58;
    v64 = _mm_mul_ps(
            _mm_shuffle_ps((__m128)LODWORD(input->m_characterHeight), (__m128)LODWORD(input->m_characterHeight), 0),
            input->m_up.m_quad);
    v65 = _mm_add_ps(v64, input->m_boundsAabb.m_min.m_quad);
    pruneAabb.m_max.m_quad = _mm_max_ps(
                               input->m_boundsAabb.m_max.m_quad,
                               _mm_add_ps(v64, input->m_boundsAabb.m_max.m_quad));
    pruneAabb.m_min.m_quad = _mm_min_ps(input->m_boundsAabb.m_min.m_quad, v65);
  }
  hkaiCarverTree::hkaiCarverTree(&carverTree);
  p_m_painters = &input->m_painters;
  hkaiCarverTree::init(&carverTree, &v275, &carvers, &input->m_painters);
  *(_DWORD *)&dstGeom.m_memSizeAndFlags = 0x1FFFF;
  dstGeom.m_vertices.m_data = 0i64;
  dstGeom.m_vertices.m_size = 0;
  dstGeom.m_vertices.m_capacityAndFlags = 0x80000000;
  dstGeom.m_triangles.m_data = 0i64;
  dstGeom.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  dstGeom.m_triangles.m_size = 0;
  dstGeom.m_triangles.m_capacityAndFlags = 0x80000000;
  hkaiNavMeshGenerationUtils::safeCopyAndPruneByAabb(
    (hkResult *)&v262.m_painters + 1,
    &dstGeom,
    srcGeom,
    &pruneAabb,
    (hkaiNavMeshGenerationSettings::TriangleWinding)(unsigned __int8)input->m_triangleWinding.m_storage);
  if ( HIDWORD(v262.m_painters) )
  {
    hkErrStream::hkErrStream(&v279, v353, 512);
    hkOstream::operator<<(
      &v279,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, v353, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 238);
    hkOstream::~hkOstream(&v279);
    v67 = (hkVector4f *)v5->m_navMesh;
    if ( v67 )
    {
      v67[8] = (hkVector4f)aabbOut.m_quad;
      v67[9] = (hkVector4f)aabbOut.m_quad;
    }
    v13 = 2;
    hkGeometry::~hkGeometry(&dstGeom);
    goto LABEL_344;
  }
  if ( dstGeom.m_triangles.m_size )
  {
    v69 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v70 = (_QWORD *)v69[1];
    if ( (unsigned __int64)v70 < v69[3] )
    {
      *v70 = "TtconvertAndMerge";
      v71 = __rdtsc();
      v72 = v70 + 2;
      *((_DWORD *)v72 - 2) = v71;
      v69[1] = v72;
    }
    m_quantizationGridSize = input->m_quantizationGridSize;
    if ( m_quantizationGridSize != 0.0 )
      hkaiNavMeshGenerationUtils::quantize(&dstGeom, m_quantizationGridSize);
    hkaiNavMeshGenerationUtils::setCarvedMaterialsDeprecated(
      &dstGeom,
      input->m_carvedCuttingMaterialDeprecated,
      input->m_carvedMaterialDeprecated,
      (hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v269,
      input->m_defaultConstructionProperties.m_storage,
      &carverTree);
    if ( input->m_weldInputVertices.m_bool )
    {
      v74 = dstGeom.m_vertices.m_size;
      v75 = dstGeom.m_triangles.m_size;
      v76 = 0x80000000;
      vertexRemapOut.m_data = 0i64;
      vertexRemapOut.m_size = 0;
      vertexRemapOut.m_capacityAndFlags = 0x80000000;
      triangleRemapOut.m_data = 0i64;
      triangleRemapOut.m_size = 0;
      triangleRemapOut.m_capacityAndFlags = 0x80000000;
      sweepAabbs.m_data = 0i64;
      sweepAabbs.m_size = 0;
      sweepAabbs.m_capacityAndFlags = 0x80000000;
      uniqueVerts.m_data = 0i64;
      uniqueVerts.m_size = 0;
      uniqueVerts.m_capacityAndFlags = 0x80000000;
      sortData.m_data = 0i64;
      sortData.m_size = 0;
      sortData.m_capacityAndFlags = 0x80000000;
      sortedAabbs.m_data = 0i64;
      sortedAabbs.m_size = 0;
      sortedAabbs.m_capacityAndFlags = 0x80000000;
      if ( dstGeom.m_vertices.m_size <= 0 )
      {
        v244.m_enum = HK_SUCCESS;
      }
      else
      {
        hkArrayUtil::_reserve(&v244, &hkContainerHeapAllocator::s_alloc, &vertexRemapOut, dstGeom.m_vertices.m_size, 4);
        if ( v244.m_enum )
        {
          hkErrStream::hkErrStream(&v282, v363, 512);
          hkOstream::operator<<(
            &v282,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v363, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 282);
          v77 = &v282;
LABEL_127:
          hkOstream::~hkOstream(v77);
          v85 = (hkVector4f *)v5->m_navMesh;
          if ( v85 )
          {
            v85[8] = (hkVector4f)aabbOut.m_quad;
            v85[9] = (hkVector4f)aabbOut.m_quad;
          }
          sortedAabbs.m_size = 0;
          if ( sortedAabbs.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              sortedAabbs.m_data,
              32 * sortedAabbs.m_capacityAndFlags);
          sortedAabbs.m_data = 0i64;
          sortedAabbs.m_capacityAndFlags = 0x80000000;
          sortData.m_size = 0;
          if ( sortData.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              sortData.m_data,
              8 * sortData.m_capacityAndFlags);
          sortData.m_data = 0i64;
          sortData.m_capacityAndFlags = 0x80000000;
          uniqueVerts.m_size = 0;
          if ( uniqueVerts.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              uniqueVerts.m_data,
              16 * uniqueVerts.m_capacityAndFlags);
          uniqueVerts.m_data = 0i64;
          uniqueVerts.m_capacityAndFlags = 0x80000000;
          sweepAabbs.m_size = 0;
          if ( sweepAabbs.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              sweepAabbs.m_data,
              32 * sweepAabbs.m_capacityAndFlags);
          sweepAabbs.m_data = 0i64;
          sweepAabbs.m_capacityAndFlags = 0x80000000;
          triangleRemapOut.m_size = 0;
          if ( triangleRemapOut.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              triangleRemapOut.m_data,
              4 * triangleRemapOut.m_capacityAndFlags);
          triangleRemapOut.m_data = 0i64;
          triangleRemapOut.m_capacityAndFlags = 0x80000000;
          vertexRemapOut.m_size = 0;
          if ( vertexRemapOut.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              vertexRemapOut.m_data,
              4 * vertexRemapOut.m_capacityAndFlags);
          vertexRemapOut.m_data = 0i64;
          vertexRemapOut.m_capacityAndFlags = 0x80000000;
LABEL_179:
          v13 = 2;
          v95 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v96 = (_QWORD *)v95[1];
          if ( (unsigned __int64)v96 < v95[3] )
          {
            *v96 = "Et";
            v97 = __rdtsc();
            v98 = v96 + 2;
            *((_DWORD *)v98 - 2) = v97;
            v95[1] = v98;
          }
          goto LABEL_181;
        }
        v76 = triangleRemapOut.m_capacityAndFlags;
      }
      v78 = v76 & 0x3FFFFFFF;
      if ( v78 >= v75 )
      {
        v236.m_enum = HK_SUCCESS;
      }
      else
      {
        v79 = 2 * v78;
        if ( v75 < v79 )
          v75 = v79;
        hkArrayUtil::_reserve(&v236, &hkContainerHeapAllocator::s_alloc, &triangleRemapOut, v75, 4);
        if ( v236.m_enum )
        {
          hkErrStream::hkErrStream(&v302, v337, 512);
          hkOstream::operator<<(
            &v302,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v337, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 285);
          v77 = &v302;
          goto LABEL_127;
        }
      }
      if ( (uniqueVerts.m_capacityAndFlags & 0x3FFFFFFF) >= v74 )
      {
        v237.m_enum = HK_SUCCESS;
      }
      else
      {
        v80 = v74;
        if ( v74 < 2 * (uniqueVerts.m_capacityAndFlags & 0x3FFFFFFF) )
          v80 = 2 * (uniqueVerts.m_capacityAndFlags & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&v237, &hkContainerHeapAllocator::s_alloc, &uniqueVerts, v80, 16);
        if ( v237.m_enum )
        {
          hkErrStream::hkErrStream(&v284, v355, 512);
          hkOstream::operator<<(
            &v284,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v355, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 288);
          v77 = &v284;
          goto LABEL_127;
        }
      }
      v81 = v74 + 4;
      if ( (sweepAabbs.m_capacityAndFlags & 0x3FFFFFFF) >= v81 )
      {
        v239.m_enum = HK_SUCCESS;
      }
      else
      {
        v82 = v81;
        if ( v81 < 2 * (sweepAabbs.m_capacityAndFlags & 0x3FFFFFFF) )
          v82 = 2 * (sweepAabbs.m_capacityAndFlags & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&v239, &hkContainerHeapAllocator::s_alloc, &sweepAabbs, v82, 32);
        if ( v239.m_enum )
        {
          hkErrStream::hkErrStream(&v312, v339, 512);
          hkOstream::operator<<(
            &v312,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v339, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 291);
          v77 = &v312;
          goto LABEL_127;
        }
      }
      if ( (sortData.m_capacityAndFlags & 0x3FFFFFFF) >= v81 )
      {
        v241.m_enum = HK_SUCCESS;
      }
      else
      {
        v83 = v81;
        if ( v81 < 2 * (sortData.m_capacityAndFlags & 0x3FFFFFFF) )
          v83 = 2 * (sortData.m_capacityAndFlags & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&v241, &hkContainerHeapAllocator::s_alloc, &sortData, v83, 8);
        if ( v241.m_enum )
        {
          hkErrStream::hkErrStream(&v286, v371, 512);
          hkOstream::operator<<(
            &v286,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v371, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 294);
          v77 = &v286;
          goto LABEL_127;
        }
      }
      sortData.m_size = v81;
      if ( (sortedAabbs.m_capacityAndFlags & 0x3FFFFFFF) >= v81 )
      {
        v243.m_enum = HK_SUCCESS;
      }
      else
      {
        v84 = v81;
        if ( v81 < 2 * (sortedAabbs.m_capacityAndFlags & 0x3FFFFFFF) )
          v84 = 2 * (sortedAabbs.m_capacityAndFlags & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&v243, &hkContainerHeapAllocator::s_alloc, &sortedAabbs, v84, 32);
        if ( v243.m_enum )
        {
          hkErrStream::hkErrStream(&v304, v341, 512);
          hkOstream::operator<<(
            &v304,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v341, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 297);
          v77 = &v304;
          goto LABEL_127;
        }
      }
      sortedAabbs.m_size = v81;
      v228 = 0;
      hkGeometryUtils::_weldVertices(
        &dstGeom,
        input->m_weldThreshold,
        0,
        &vertexRemapOut,
        &triangleRemapOut,
        &uniqueVerts,
        &sweepAabbs,
        &sortData,
        &sortedAabbs);
      sortedAabbs.m_size = 0;
      if ( sortedAabbs.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          sortedAabbs.m_data,
          32 * sortedAabbs.m_capacityAndFlags);
      sortedAabbs.m_data = 0i64;
      sortedAabbs.m_capacityAndFlags = 0x80000000;
      sortData.m_size = 0;
      if ( sortData.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          sortData.m_data,
          8 * sortData.m_capacityAndFlags);
      sortData.m_data = 0i64;
      sortData.m_capacityAndFlags = 0x80000000;
      uniqueVerts.m_size = 0;
      if ( uniqueVerts.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          uniqueVerts.m_data,
          16 * uniqueVerts.m_capacityAndFlags);
      uniqueVerts.m_data = 0i64;
      uniqueVerts.m_capacityAndFlags = 0x80000000;
      sweepAabbs.m_size = 0;
      if ( sweepAabbs.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          sweepAabbs.m_data,
          32 * sweepAabbs.m_capacityAndFlags);
      sweepAabbs.m_data = 0i64;
      sweepAabbs.m_capacityAndFlags = 0x80000000;
      triangleRemapOut.m_size = 0;
      if ( triangleRemapOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          triangleRemapOut.m_data,
          4 * triangleRemapOut.m_capacityAndFlags);
      triangleRemapOut.m_data = 0i64;
      triangleRemapOut.m_capacityAndFlags = 0x80000000;
      vertexRemapOut.m_size = 0;
      if ( vertexRemapOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          vertexRemapOut.m_data,
          4 * vertexRemapOut.m_capacityAndFlags);
      vertexRemapOut.m_data = 0i64;
      vertexRemapOut.m_capacityAndFlags = 0x80000000;
      p_m_painters = &input->m_painters;
    }
    newTriangles.m_data = 0i64;
    newTriangles.m_size = 0;
    newTriangles.m_capacityAndFlags = 0x80000000;
    if ( dstGeom.m_triangles.m_size <= 0 )
    {
      v245.m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&v245, &hkContainerHeapAllocator::s_alloc, &newTriangles, dstGeom.m_triangles.m_size, 16);
      if ( v245.m_enum )
      {
        hkErrStream::hkErrStream(&v288, v357, 512);
        hkOstream::operator<<(
          &v288,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, v357, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 306);
        v86 = &v288;
LABEL_162:
        hkOstream::~hkOstream(v86);
        v87 = (hkVector4f *)v5->m_navMesh;
        if ( v87 )
        {
          v87[8] = (hkVector4f)aabbOut.m_quad;
          v87[9] = (hkVector4f)aabbOut.m_quad;
        }
        newTriangles.m_size = 0;
        if ( newTriangles.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            newTriangles.m_data,
            16 * newTriangles.m_capacityAndFlags);
        newTriangles.m_data = 0i64;
        newTriangles.m_capacityAndFlags = 0x80000000;
        goto LABEL_179;
      }
    }
    hkGeometryUtils::removeDuplicateTrianglesFast((hkResult *)(&v262.m_referenceCount + 1), &dstGeom, &newTriangles);
    if ( *(_DWORD *)(&v262.m_referenceCount + 1) )
    {
      hkErrStream::hkErrStream(&v320, v343, 512);
      hkOstream::operator<<(
        &v320,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v343, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 309);
      v86 = &v320;
      goto LABEL_162;
    }
    newTriangles.m_size = 0;
    if ( newTriangles.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        newTriangles.m_data,
        16 * newTriangles.m_capacityAndFlags);
    newTriangles.m_data = 0i64;
    newTriangles.m_capacityAndFlags = 0x80000000;
    hkaiGeometryToEdgeGeometryConverter::hkaiGeometryToEdgeGeometryConverter(&v323);
    v88 = geomOut;
    v227 = 1;
    hkaiGeometryToEdgeGeometryConverter::convertGeometryToEdgeGeometry(
      &v323,
      (hkResult *)&v262.m_carverTree.m_pntr + 1,
      &dstGeom,
      (hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char>)1,
      geomOut);
    if ( HIDWORD(v262.m_carverTree.m_pntr) )
    {
      hkErrStream::hkErrStream(&v290, v365, 512);
      hkOstream::operator<<(
        &v290,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v365, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 315);
      hkOstream::~hkOstream(&v290);
      v89 = (hkVector4f *)v5->m_navMesh;
      if ( v89 )
      {
        v89[8] = (hkVector4f)aabbOut.m_quad;
        v89[9] = (hkVector4f)aabbOut.m_quad;
      }
      hkaiGeometryToEdgeGeometryConverter::~hkaiGeometryToEdgeGeometryConverter(&v323);
      goto LABEL_179;
    }
    hkaiGeometryToEdgeGeometryConverter::~hkaiGeometryToEdgeGeometryConverter(&v323);
    hkaiEdgeGeometry::set(geomInOut, &v257, v88);
    if ( v257.m_enum )
    {
      hkErrStream::hkErrStream(&v277, v345, 512);
      hkOstream::operator<<(
        &v277,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v345, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 331);
      v90 = &v277;
      goto LABEL_177;
    }
    m_storage = input->m_defaultConstructionProperties.m_storage;
    hkaiNavMeshGenerationUtils::pruneEdgeGeometryByMaterialDeprecated(
      geomInOut,
      (hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v269,
      m_storage,
      1u);
    v92 = m_storage;
    v93 = geomOut;
    hkaiNavMeshGenerationUtils::pruneEdgeGeometryByMaterialDeprecated(
      geomOut,
      (hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v269,
      v92,
      2u);
    hkaiEdgeGeometryUtil::removeUnwalkableFaces(&v258, geomInOut, input);
    if ( v258.m_enum )
    {
      hkErrStream::hkErrStream(&v292, v359, 512);
      hkOstream::operator<<(
        &v292,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v359, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 341);
      v90 = &v292;
LABEL_177:
      hkOstream::~hkOstream(v90);
      v94 = (hkVector4f *)v5->m_navMesh;
      if ( v94 )
      {
        v94[8] = (hkVector4f)aabbOut.m_quad;
        v94[9] = (hkVector4f)aabbOut.m_quad;
      }
      goto LABEL_179;
    }
    v99 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v100 = (_QWORD *)v99[1];
    if ( (unsigned __int64)v100 < v99[3] )
    {
      *v100 = "Et";
      v101 = __rdtsc();
      v102 = v100 + 2;
      *((_DWORD *)v102 - 2) = v101;
      v99[1] = v102;
    }
    hkGeometry::~hkGeometry(&dstGeom);
    v103 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v104 = (_QWORD *)v103[1];
    if ( (unsigned __int64)v104 < v103[3] )
    {
      *v104 = "Ttextrude";
      v105 = __rdtsc();
      v106 = v104 + 2;
      *((_DWORD *)v106 - 2) = v105;
      v103[1] = v106;
    }
    hkaiNavMeshGenerationUtils::_extrudeDeprecated(&v260, input, v93, extrudeGeom);
    if ( v260.m_enum )
    {
      hkErrStream::hkErrStream(&v314, v347, 512);
      hkOstream::operator<<(
        &v314,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v347, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 353);
      hkOstream::~hkOstream(&v314);
      v107 = (hkVector4f *)v5->m_navMesh;
      if ( v107 )
      {
        v107[8] = (hkVector4f)aabbOut.m_quad;
        v107[9] = (hkVector4f)aabbOut.m_quad;
      }
      v108 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v109 = (_QWORD *)v108[1];
      if ( (unsigned __int64)v109 < v108[3] )
      {
        *v109 = "Et";
        v110 = __rdtsc();
        v111 = v109 + 2;
        v13 = 2;
        *((_DWORD *)v111 - 2) = v110;
        v108[1] = v111;
        goto LABEL_344;
      }
LABEL_199:
      v13 = 2;
      goto LABEL_344;
    }
    v112 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v113 = (_QWORD *)v112[1];
    if ( (unsigned __int64)v113 < v112[3] )
    {
      *v113 = "Et";
      v114 = __rdtsc();
      v115 = v113 + 2;
      *((_DWORD *)v115 - 2) = v114;
      v112[1] = v115;
    }
    hkaiGeometryCarverExtractor::addCarvers(&v247, extrudeGeom, &carvers, p_m_painters);
    if ( v247.m_enum )
    {
      hkErrStream::hkErrStream(&v294, v369, 512);
      hkOstream::operator<<(
        &v294,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v369, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 368);
      v116 = &v294;
      goto LABEL_197;
    }
    v247.m_enum = hkaiGeometryCarverExtractor::addCarvers(&v273, v93, &carvers, p_m_painters)->m_enum;
    if ( v247.m_enum )
    {
      hkErrStream::hkErrStream(&v308, v329, 512);
      hkOstream::operator<<(
        &v308,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v329, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 371);
      v116 = &v308;
LABEL_197:
      hkOstream::~hkOstream(v116);
      v117 = (hkVector4f *)v5->m_navMesh;
      if ( v117 )
      {
        v117[8] = (hkVector4f)aabbOut.m_quad;
        v117[9] = (hkVector4f)aabbOut.m_quad;
      }
      goto LABEL_199;
    }
    v118 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v119 = (_QWORD *)v118[1];
    if ( (unsigned __int64)v119 < v118[3] )
    {
      *v119 = "Ttsubtract";
      v120 = __rdtsc();
      v121 = v119 + 2;
      *((_DWORD *)v121 - 2) = v120;
      v118[1] = v121;
    }
    v122 = geomInOut;
    hkaiNavMeshGenerationUtils::_subtractDeprecated((hkResult *)&srcGeom, input, extrudeGeom, geomInOut, 0i64);
    if ( (_DWORD)srcGeom )
    {
      hkErrStream::hkErrStream(&v296, v361, 512);
      hkOstream::operator<<(
        &v296,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v361, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 387);
      hkOstream::~hkOstream(&v296);
      v123 = (hkVector4f *)v5->m_navMesh;
      if ( v123 )
      {
        v123[8] = (hkVector4f)aabbOut.m_quad;
        v123[9] = (hkVector4f)aabbOut.m_quad;
      }
      v124 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v125 = (_QWORD *)v124[1];
      if ( (unsigned __int64)v125 < v124[3] )
      {
        *v125 = "Et";
        v126 = __rdtsc();
        v127 = v125 + 2;
        *((_DWORD *)v127 - 2) = v126;
        v124[1] = v127;
      }
      v13 = 2;
      goto LABEL_344;
    }
    v128 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v129 = (_QWORD *)v128[1];
    if ( (unsigned __int64)v129 < v128[3] )
    {
      *v129 = "Et";
      v130 = __rdtsc();
      v131 = v129 + 2;
      *((_DWORD *)v131 - 2) = v130;
      v128[1] = v131;
    }
    trisOut.m_capacityAndFlags = 0x80000000;
    trisOut.m_data = 0i64;
    trisOut.m_size = 0;
    trisPerFaceOut.m_data = 0i64;
    trisPerFaceOut.m_size = 0;
    trisPerFaceOut.m_capacityAndFlags = 0x80000000;
    triConnectivityOut.m_data = 0i64;
    triConnectivityOut.m_size = 0;
    triConnectivityOut.m_capacityAndFlags = 0x80000000;
    materialsOut.m_data = 0i64;
    materialsOut.m_size = 0;
    materialsOut.m_capacityAndFlags = 0x80000000;
    v132 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v133 = (_QWORD *)v132[1];
    v134 = v132;
    if ( (unsigned __int64)v133 < v132[3] )
    {
      *v133 = "Tttriangulate";
      v135 = __rdtsc();
      v136 = v133 + 2;
      *((_DWORD *)v136 - 2) = v135;
      v134[1] = v136;
    }
    hkaiNavMeshGenerationUtils::_triangulate(
      &v264,
      input,
      v122,
      &trisOut,
      &trisPerFaceOut,
      &triConnectivityOut,
      &materialsOut,
      0);
    if ( v264.m_enum )
    {
      hkErrStream::hkErrStream(&v318, v351, 512);
      hkOstream::operator<<(
        &v318,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v351, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 410);
      hkOstream::~hkOstream(&v318);
      v137 = (hkVector4f *)v5->m_navMesh;
      if ( v137 )
      {
        v137[8] = (hkVector4f)aabbOut.m_quad;
        v137[9] = (hkVector4f)aabbOut.m_quad;
      }
      v138 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v139 = (_QWORD *)v138[1];
      if ( (unsigned __int64)v139 < v138[3] )
      {
        *v139 = "Et";
        v140 = __rdtsc();
        v141 = v139 + 2;
        *((_DWORD *)v141 - 2) = v140;
        v138[1] = v141;
      }
      v13 = 2;
      goto LABEL_335;
    }
    v142 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v143 = (_QWORD *)v142[1];
    if ( (unsigned __int64)v143 < v142[3] )
    {
      *v143 = "Et";
      v144 = __rdtsc();
      v145 = v143 + 2;
      *((_DWORD *)v145 - 2) = v144;
      v142[1] = v145;
    }
    hkaiEdgeGeometryRaycaster::hkaiEdgeGeometryRaycaster(&cuttingGeomRaycaster);
    if ( !raycaster )
    {
      hkaiEdgeGeometryRaycaster::init(&cuttingGeomRaycaster, &v271, v93);
      raycaster = &cuttingGeomRaycaster;
    }
    v146 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v147 = (_QWORD *)v146[1];
    if ( (unsigned __int64)v147 < v146[3] )
    {
      *v147 = "TtRemoveUnreachable";
      v148 = __rdtsc();
      v149 = v147 + 2;
      *((_DWORD *)v149 - 2) = v148;
      v146[1] = v149;
    }
    hkaiNavMeshGenerationUtils::_removeDegenerateTriangles(
      &v261,
      &v122->m_vertices,
      &trisOut,
      &trisPerFaceOut,
      &triConnectivityOut,
      &materialsOut,
      (__m128 *)input);
    if ( v261.m_enum )
    {
      hkErrStream::hkErrStream(&v298, v330, 512);
      hkOstream::operator<<(
        &v298,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v330, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 429);
      v150 = &v298;
      goto LABEL_228;
    }
    hkaiNavMeshGenerationUtils::_removeUnreachableTriangles(
      &v262,
      (hkArrayBase<int> *)input,
      &cuttingGeomRaycaster,
      (hkArray<int,hkContainerHeapAllocator> *)v122,
      (hkArray<int,hkContainerHeapAllocator> *)&carverTree,
      &trisPerFaceOut,
      &trisOut,
      &triConnectivityOut,
      &trisPerFaceOut,
      &materialsOut,
      0i64,
      0i64,
      0i64,
      0i64,
      0i64);
    if ( LODWORD(v262.vfptr) )
    {
      hkErrStream::hkErrStream(&v310, v332, 512);
      hkOstream::operator<<(
        &v310,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v332, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 434);
      v150 = &v310;
LABEL_228:
      hkOstream::~hkOstream(v150);
      v151 = (hkVector4f *)v5->m_navMesh;
      if ( v151 )
      {
        v151[8] = (hkVector4f)aabbOut.m_quad;
        v151[9] = (hkVector4f)aabbOut.m_quad;
      }
LABEL_331:
      v207 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v208 = (_QWORD *)v207[1];
      if ( (unsigned __int64)v208 < v207[3] )
      {
        *v208 = "Et";
        v209 = __rdtsc();
        v210 = v208 + 2;
        *((_DWORD *)v210 - 2) = v209;
        v207[1] = v210;
      }
LABEL_333:
      v13 = 2;
      goto LABEL_334;
    }
    raycaster->m_faceFlagMask.m_storage = 15;
    v152 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v153 = (_QWORD *)v152[1];
    if ( (unsigned __int64)v153 < v152[3] )
    {
      *v153 = "Et";
      v154 = __rdtsc();
      v155 = v153 + 2;
      *((_DWORD *)v155 - 2) = v154;
      v152[1] = v155;
    }
    v156 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v157 = (_QWORD *)v156[1];
    if ( (unsigned __int64)v157 < v156[3] )
    {
      *v157 = "TtcreateNavMesh";
      v158 = __rdtsc();
      v159 = v157 + 2;
      *((_DWORD *)v159 - 2) = v158;
      v156[1] = v159;
    }
    v160 = 0x80000000;
    vertsIn.m_data = 0i64;
    vertsIn.m_size = 0;
    vertsIn.m_capacityAndFlags = 0x80000000;
    v161 = v122->m_vertices.m_size;
    v162 = 0i64;
    if ( v161 <= 0 )
    {
      v249.m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&v249, &hkContainerHeapAllocator::s_alloc, &vertsIn, v161, 16);
      if ( v249.m_enum )
      {
        hkErrStream::hkErrStream(&v300, v334, 512);
        hkOstream::operator<<(
          &v300,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, v334, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 445);
        v163 = &v300;
LABEL_326:
        hkOstream::~hkOstream(v163);
        v206 = (hkVector4f *)v5->m_navMesh;
        if ( v206 )
        {
          v206[8] = (hkVector4f)aabbOut.m_quad;
          v206[9] = (hkVector4f)aabbOut.m_quad;
        }
        vertsIn.m_size = 0;
        if ( vertsIn.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            vertsIn.m_data,
            16 * vertsIn.m_capacityAndFlags);
        vertsIn.m_data = 0i64;
        vertsIn.m_capacityAndFlags = 0x80000000;
        goto LABEL_331;
      }
      v160 = vertsIn.m_capacityAndFlags;
      v162 = vertsIn.m_data;
    }
    if ( (v160 & 0x3FFFFFFF) < v122->m_vertices.m_size )
    {
      if ( v160 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v162, 16 * v160);
      v252 = 16 * v122->m_vertices.m_size;
      v162 = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v252);
      vertsIn.m_data = v162;
      vertsIn.m_capacityAndFlags = v252 / 16;
    }
    vertsIn.m_size = v122->m_vertices.m_size;
    p_m_quad = &v122->m_vertices.m_data->m_quad;
    v165 = vertsIn.m_size;
    if ( vertsIn.m_size > 0 )
    {
      do
      {
        v166.m_quad = *p_m_quad;
        ++v162;
        ++p_m_quad;
        v162[-1] = (hkVector4f)v166.m_quad;
        --v165;
      }
      while ( v165 );
    }
    hkaiNavMeshGenerationUtils::_createNavMesh(
      (hkResult *)&v262.m_memSizeAndFlags,
      &vertsIn,
      &trisOut,
      &trisPerFaceOut,
      &triConnectivityOut,
      &materialsOut,
      &carverTree,
      input,
      v21);
    if ( *(_DWORD *)&v262.m_memSizeAndFlags )
    {
      hkErrStream::hkErrStream(&v278, v336, 512);
      hkOstream::operator<<(
        &v278,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v336, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 449);
      v163 = &v278;
      goto LABEL_326;
    }
    if ( v21->m_edges.m_size >= 0x400000 || v21->m_faces.m_size >= 0x400000 )
    {
      hkErrStream::hkErrStream(&v315, v372, 512);
      hkOstream::operator<<(
        &v315,
        "Nav mesh generation created a mesh with too many edges or faces. Please try hkaiSplitGenerationUtils to process "
        "the mesh in pieces instead.");
      hkError::messageWarning(1349609975, v372, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 450);
      v163 = &v315;
      goto LABEL_326;
    }
    v167 = 0;
    vertsIn.m_size = 0;
    if ( vertsIn.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        vertsIn.m_data,
        16 * vertsIn.m_capacityAndFlags);
    vertsIn.m_data = 0i64;
    vertsIn.m_capacityAndFlags = 0x80000000;
    v168 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v169 = (_QWORD *)v168[1];
    if ( (unsigned __int64)v169 < v168[3] )
    {
      *v169 = "Et";
      v170 = __rdtsc();
      v171 = v169 + 2;
      *((_DWORD *)v171 - 2) = v170;
      v168[1] = v171;
    }
    if ( !v21->m_faces.m_size || !v21->m_edges.m_size )
    {
      hkErrStream::hkErrStream(&v313, v370, 512);
      hkOstream::operator<<(
        &v313,
        "Empty nav mesh created. This could happen if all input was unwalkable, or if all walkable geometry was contained in carvers.");
      hkError::messageWarning(1541620706, v370, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 455);
      v183 = &v313;
LABEL_323:
      hkOstream::~hkOstream(v183);
      v205 = (hkVector4f *)v5->m_navMesh;
      if ( v205 )
      {
        v205[8] = (hkVector4f)aabbOut.m_quad;
        v205[9] = (hkVector4f)aabbOut.m_quad;
      }
      goto LABEL_334;
    }
    v172 = (hkaiNavMesh *)raycaster;
    hkaiEdgeGeometryRaycaster::setupForEdgeConnections(raycaster);
    hkaiNavMeshGenerationUtils::_connectEdges((hkResult *)&v262.m_carverTree, input, v21, v172, 0, 0i64, 0i64);
    if ( LODWORD(v262.m_carverTree.m_pntr) )
    {
      hkErrStream::hkErrStream(&v281, v338, 512);
      hkOstream::operator<<(
        &v281,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v338, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 479);
      v173 = &v281;
      goto LABEL_257;
    }
    if ( v21->m_edges.m_size >= 0x400000 || v21->m_faces.m_size >= 0x400000 )
    {
      hkErrStream::hkErrStream(&v311, v368, 512);
      hkOstream::operator<<(
        &v311,
        "Nav mesh generation created a mesh with too many edges or faces. Please try hkaiSplitGenerationUtils to process "
        "the mesh in pieces instead.");
      hkError::messageWarning(1349609975, v368, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 480);
      v173 = &v311;
LABEL_257:
      hkOstream::~hkOstream(v173);
      v174 = (hkVector4f *)v5->m_navMesh;
      if ( v174 )
      {
        v174[8] = (hkVector4f)aabbOut.m_quad;
        v174[9] = (hkVector4f)aabbOut.m_quad;
      }
      goto LABEL_333;
    }
    if ( input->m_edgeConnectionIterations > 0 )
    {
      while ( 1 )
      {
        v175 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v176 = (_QWORD *)v175[1];
        if ( (unsigned __int64)v176 < v175[3] )
        {
          *v176 = "TtconnectEdges";
          v177 = __rdtsc();
          v178 = v176 + 2;
          *((_DWORD *)v178 - 2) = v177;
          v175[1] = v178;
        }
        hkaiNavMeshGenerationUtils::_connectEdges((hkResult *)&v262.m_painterTree, input, v21, v172, ++v167, 0i64, 0i64);
        if ( LODWORD(v262.m_painterTree.m_pntr) )
          break;
        if ( v21->m_edges.m_size >= 0x400000 || v21->m_faces.m_size >= 0x400000 )
        {
          hkErrStream::hkErrStream(&v283, v340, 512);
          hkOstream::operator<<(
            &v283,
            "Nav mesh generation created a mesh with too many edges or faces. Please try hkaiSplitGenerationUtils to proc"
            "ess the mesh in pieces instead.");
          hkError::messageWarning(1349609975, v340, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 503);
          v150 = &v283;
          goto LABEL_228;
        }
        v179 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v180 = (_QWORD *)v179[1];
        if ( (unsigned __int64)v180 < v179[3] )
        {
          *v180 = "Et";
          v181 = __rdtsc();
          v182 = v180 + 2;
          *((_DWORD *)v182 - 2) = v181;
          v179[1] = v182;
        }
        if ( v167 >= input->m_edgeConnectionIterations )
          goto LABEL_270;
      }
      hkErrStream::hkErrStream(&v285, v342, 512);
      hkOstream::operator<<(
        &v285,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v342, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 502);
      v150 = &v285;
      goto LABEL_228;
    }
LABEL_270:
    hkaiNavMeshUtils::validate(v21, 0);
    hkaiNavMeshUtils::compactVertices((hkResult *)&v262.m_carvers, v21, 0, 0);
    if ( LODWORD(v262.m_carvers) )
    {
      hkErrStream::hkErrStream(&v287, v344, 512);
      hkOstream::operator<<(
        &v287,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v344, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 524);
      v173 = &v287;
      goto LABEL_257;
    }
    hkaiNavMeshGenerationUtils::_mergeVertices((hkResult *)&v262.m_painters, v21, 0.00039999999);
    if ( LODWORD(v262.m_painters) )
    {
      hkErrStream::hkErrStream(&v289, v346, 512);
      hkOstream::operator<<(
        &v289,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v346, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 539);
      v173 = &v289;
      goto LABEL_257;
    }
    hkaiNavMeshGenerationUtils::_removeDegenerateFaces(&v265, (hkSimdFloat32 *)v21);
    if ( v265.m_enum )
    {
      hkErrStream::hkErrStream(&v291, v348, 512);
      hkOstream::operator<<(
        &v291,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v348, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 551);
      v173 = &v291;
      goto LABEL_257;
    }
    hkaiNavMeshUtils::validate(v21, 0);
    hkaiNavMeshGenerationUtils::_applyMinCharacterRadius(&v256, v21, input, &cuttingGeomRaycaster, 0i64);
    if ( v256.m_enum )
    {
      hkErrStream::hkErrStream(&v293, v350, 512);
      hkOstream::operator<<(
        &v293,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v350, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 571);
      v173 = &v293;
      goto LABEL_257;
    }
    if ( !v21->m_faces.m_size )
    {
      hkErrStream::hkErrStream(&v295, v352, 512);
      hkOstream::operator<<(&v295, "Erosion removed all faces from the nav mesh.");
      hkError::messageWarning(1209185063, v352, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 574);
      v183 = &v295;
      goto LABEL_323;
    }
    hkaiNavMeshGenerationUtils::_pruneRegions(&v266, v21, &input->m_up, &input->m_regionPruningSettings);
    if ( v266.m_enum )
    {
      hkErrStream::hkErrStream(&v297, v354, 512);
      hkOstream::operator<<(
        &v297,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v354, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 591);
      v173 = &v297;
      goto LABEL_257;
    }
    hkaiNavMeshUtils::compactVertices((hkResult *)&v262.m_carvers + 1, v21, 0, 0);
    if ( HIDWORD(v262.m_carvers) )
    {
      hkErrStream::hkErrStream(&v299, v356, 512);
      hkOstream::operator<<(
        &v299,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, v356, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 605);
      v173 = &v299;
      goto LABEL_257;
    }
    hkAabbUtil::calcAabb(v21->m_vertices.m_data, v21->m_vertices.m_size, &v21->m_aabb);
    v184 = _mm_shuffle_ps((__m128)LODWORD(input->m_characterHeight), (__m128)LODWORD(input->m_characterHeight), 0);
    v21->m_aabb.m_max.m_quad = _mm_add_ps(v21->m_aabb.m_max.m_quad, v184);
    v21->m_aabb.m_min.m_quad = _mm_sub_ps(v21->m_aabb.m_min.m_quad, v184);
    if ( input->m_enableSimplification.m_bool )
    {
      hkaiNavMesh::setEdgeDataStriding(v21, &v235, 1, 0);
      if ( v235.m_enum )
      {
        hkErrStream::hkErrStream(&v301, v358, 512);
        hkOstream::operator<<(
          &v301,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, v358, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 631);
        v173 = &v301;
        goto LABEL_257;
      }
      v235.m_enum = hkaiNavMesh::setEdgeDataStriding(v20, &v274, 1, 0)->m_enum;
      if ( v235.m_enum )
      {
        hkErrStream::hkErrStream(&v303, v360, 512);
        hkOstream::operator<<(
          &v303,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, v360, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 633);
        v173 = &v303;
        goto LABEL_257;
      }
      hkaiNavMeshUtils::validate(v21, 0);
      m_unsimplifiedNavMesh = v5->m_unsimplifiedNavMesh;
      if ( m_unsimplifiedNavMesh )
      {
        hkaiNavMesh::copy(m_unsimplifiedNavMesh, &v263, v21);
        if ( v263.m_enum )
        {
          hkErrStream::hkErrStream(&v305, v362, 512);
          hkOstream::operator<<(
            &v305,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, v362, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 643);
          v173 = &v305;
          goto LABEL_257;
        }
      }
      v186 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v187 = (_QWORD *)v186[1];
      if ( (unsigned __int64)v187 < v186[3] )
      {
        *v187 = "Ttsimplify";
        v188 = __rdtsc();
        v189 = v187 + 2;
        *((_DWORD *)v189 - 2) = v188;
        v186[1] = v189;
      }
      v190 = hkaiNavMeshSimplificationUtils::_simplifyNavMesh(input, v21, v20, &cuttingGeomRaycaster, 0i64);
      if ( v190 != 2 )
      {
        v20->m_faces.m_size = 0;
        v191 = v20->m_faces.m_capacityAndFlags;
        if ( v191 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v20->m_faces.m_data,
            16 * v191);
        v20->m_faces.m_data = 0i64;
        v20->m_faces.m_capacityAndFlags = 0x80000000;
        v20->m_edges.m_size = 0;
        v192 = v20->m_edges.m_capacityAndFlags;
        if ( v192 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v20->m_edges.m_data,
            20 * (v192 & 0x3FFFFFFF));
        v20->m_edges.m_data = 0i64;
        v20->m_edges.m_capacityAndFlags = 0x80000000;
        v20->m_vertices.m_size = 0;
        v193 = v20->m_vertices.m_capacityAndFlags;
        if ( v193 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v20->m_vertices.m_data,
            16 * v193);
        v20->m_vertices.m_data = 0i64;
        v20->m_vertices.m_capacityAndFlags = 0x80000000;
        v20->m_faceData.m_size = 0;
        v194 = v20->m_faceData.m_capacityAndFlags;
        if ( v194 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v20->m_faceData.m_data,
            4 * v194);
        v20->m_faceData.m_data = 0i64;
        v20->m_faceData.m_capacityAndFlags = 0x80000000;
        v20->m_edgeData.m_size = 0;
        v195 = v20->m_edgeData.m_capacityAndFlags;
        if ( v195 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v20->m_edgeData.m_data,
            4 * v195);
        v20->m_edgeData.m_data = 0i64;
        v20->m_edgeData.m_capacityAndFlags = 0x80000000;
      }
      if ( v190 == 1 )
      {
        hkErrStream::hkErrStream(&v307, v364, 512);
        hkOstream::operator<<(
          &v307,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, v364, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 662);
        hkOstream::~hkOstream(&v307);
        v196 = (hkVector4f *)v5->m_navMesh;
        if ( v196 )
        {
          v196[8] = (hkVector4f)aabbOut.m_quad;
          v196[9] = (hkVector4f)aabbOut.m_quad;
        }
        v13 = 2;
        goto LABEL_314;
      }
      if ( !v190 )
      {
        v13 = 0;
LABEL_314:
        v197 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v198 = (_QWORD *)v197[1];
        if ( (unsigned __int64)v198 < v197[3] )
        {
          *v198 = "Et";
          v199 = __rdtsc();
          v200 = v198 + 2;
          *((_DWORD *)v200 - 2) = v199;
          v197[1] = v200;
        }
        goto LABEL_334;
      }
      v201 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v202 = (_QWORD *)v201[1];
      if ( (unsigned __int64)v202 < v201[3] )
      {
        *v202 = "Et";
        v203 = __rdtsc();
        v204 = v202 + 2;
        *((_DWORD *)v204 - 2) = v203;
        v201[1] = v204;
      }
    }
    hkaiNavMesh::setEdgeDataStriding(v20, (hkResult *)&v262.m_painterTree.m_pntr + 1, newStride, 0);
    if ( !HIDWORD(v262.m_painterTree.m_pntr) )
    {
      hkaiNavMeshUtils::validate(v20, 1);
      v13 = 5;
LABEL_334:
      hkaiEdgeGeometryRaycaster::~hkaiEdgeGeometryRaycaster(&cuttingGeomRaycaster);
LABEL_335:
      materialsOut.m_size = 0;
      if ( materialsOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          materialsOut.m_data,
          4 * materialsOut.m_capacityAndFlags);
      materialsOut.m_data = 0i64;
      materialsOut.m_capacityAndFlags = 0x80000000;
      triConnectivityOut.m_size = 0;
      if ( triConnectivityOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          triConnectivityOut.m_data,
          4 * triConnectivityOut.m_capacityAndFlags);
      triConnectivityOut.m_data = 0i64;
      triConnectivityOut.m_capacityAndFlags = 0x80000000;
      trisPerFaceOut.m_size = 0;
      if ( trisPerFaceOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          trisPerFaceOut.m_data,
          4 * trisPerFaceOut.m_capacityAndFlags);
      trisPerFaceOut.m_data = 0i64;
      trisPerFaceOut.m_capacityAndFlags = 0x80000000;
      trisOut.m_size = 0;
      if ( trisOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          trisOut.m_data,
          4 * trisOut.m_capacityAndFlags);
      trisOut.m_data = 0i64;
      trisOut.m_capacityAndFlags = 0x80000000;
      goto LABEL_344;
    }
    hkErrStream::hkErrStream(&v309, v366, 512);
    hkOstream::operator<<(
      &v309,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, v366, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 676);
    v173 = &v309;
    goto LABEL_257;
  }
  hkErrStream::hkErrStream(&v316, v335, 512);
  hkOstream::operator<<(&v316, "No triangles were contained in the input AABB.");
  hkError::messageWarning(1541620707, v335, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 242);
  hkOstream::~hkOstream(&v316);
  v68 = (hkVector4f *)v5->m_navMesh;
  if ( !v68 )
  {
LABEL_181:
    hkGeometry::~hkGeometry(&dstGeom);
    goto LABEL_344;
  }
  v68[8] = (hkVector4f)aabbOut.m_quad;
  v68[9] = (hkVector4f)aabbOut.m_quad;
  hkGeometry::~hkGeometry(&dstGeom);
LABEL_344:
  hkaiCarverTree::~hkaiCarverTree(&carverTree);
LABEL_345:
  v211 = carvers.m_size - 1;
  if ( carvers.m_size - 1 >= 0 )
  {
    v212 = &carvers.m_data[v211];
    do
    {
      hkRefPtr<hkaiVolume const>::`scalar deleting destructor(v212--);
      --v211;
    }
    while ( v211 >= 0 );
  }
  carvers.m_size = 0;
  if ( carvers.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      carvers.m_data,
      8 * carvers.m_capacityAndFlags);
  carvers.m_data = 0i64;
  carvers.m_capacityAndFlags = 0x80000000;
  hkMap<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMap<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>,hkContainerHeapAllocator>((hkMap<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>,hkContainerHeapAllocator> *)&v269);
LABEL_351:
  v232 = 0;
  if ( v233 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, v233 & 0x3FFFFFFF);
  array = 0i64;
  v233 = 0x80000000;
  hkaiNavMesh::~hkaiNavMesh(&v327);
  hkaiNavMesh::~hkaiNavMesh(&v328);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&v326);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&v324);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&v325);
LABEL_354:
  v213 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v214 = (_QWORD *)v213[1];
  v215 = v213;
  if ( (unsigned __int64)v214 < v213[3] )
  {
    *v214 = "Et";
    v216 = __rdtsc();
    v217 = v214 + 2;
    *((_DWORD *)v217 - 2) = v216;
    v215[1] = v217;
  }
  return v13;
}

// File Line: 691
// RVA: 0xBA9430
void __fastcall hkaiNavMeshGenerationUtils::setCarvedMaterialsDeprecated(
        hkGeometry *mesh,
        unsigned int carvedCuttingMaterial,
        unsigned int carvedMaterial,
        hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *materialMap,
        unsigned int defaultConstructionFlags,
        hkaiCarverTree *tree)
{
  __int64 m_size; // rsi
  unsigned __int64 v8; // rbp
  unsigned __int64 v9; // r14
  __int64 v11; // rdi
  hkGeometry::Triangle *v12; // rbx
  int v13; // eax

  m_size = mesh->m_triangles.m_size;
  v8 = carvedMaterial;
  v9 = carvedCuttingMaterial;
  if ( m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = &mesh->m_triangles.m_data[v11];
      if ( (unsigned int)hkaiCarverTree::carversContainTriangle(
                           tree,
                           &mesh->m_vertices.m_data[v12->m_a],
                           &mesh->m_vertices.m_data[v12->m_b],
                           &mesh->m_vertices.m_data[v12->m_c]) )
      {
        v13 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                &materialMap->m_map,
                (unsigned int)v12->m_material,
                defaultConstructionFlags)
            - 1;
        if ( v13 )
        {
          if ( v13 == 2 )
            v12->m_material = v9;
        }
        else
        {
          v12->m_material = v8;
        }
      }
      ++v11;
      --m_size;
    }
    while ( m_size );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &materialMap->m_map,
    &hkContainerHeapAllocator::s_alloc,
    v9,
    2ui64);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &materialMap->m_map,
    &hkContainerHeapAllocator::s_alloc,
    v8,
    0i64);
}

// File Line: 737
// RVA: 0xBA9310
void __fastcall hkaiNavMeshGenerationUtils::pruneEdgeGeometryByMaterialDeprecated(
        hkaiEdgeGeometry *geomInOut,
        hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *materialMap,
        unsigned int defaultConstructionFlags,
        unsigned int material)
{
  const unsigned int *v5; // r8
  int v6; // ebx
  __int64 v10; // rdi
  unsigned __int64 v11; // rbp
  int v12; // ecx
  unsigned int *array; // [rsp+20h] [rbp-28h] BYREF
  int numRemoveFaces; // [rsp+28h] [rbp-20h]
  int v15; // [rsp+2Ch] [rbp-1Ch]
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  v5 = 0i64;
  v6 = 1;
  array = 0i64;
  numRemoveFaces = 0;
  v15 = 0x80000000;
  if ( geomInOut->m_faces.m_size > 1 )
  {
    v10 = 1i64;
    v11 = defaultConstructionFlags;
    do
    {
      if ( ((unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                            &materialMap->m_map,
                            geomInOut->m_faces.m_data[v10].m_data,
                            v11) & material) == 0 )
      {
        v12 = numRemoveFaces;
        if ( numRemoveFaces == (v15 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 4);
          v12 = numRemoveFaces;
        }
        array[v12] = v6;
        ++numRemoveFaces;
      }
      ++v6;
      ++v10;
    }
    while ( v6 < geomInOut->m_faces.m_size );
    v5 = array;
  }
  hkaiEdgeGeometry::removeFaces(geomInOut, &result, v5, numRemoveFaces);
  numRemoveFaces = 0;
  if ( v15 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v15);
}

// File Line: 759
// RVA: 0xBA9520
hkResult *__fastcall hkaiNavMeshGenerationUtils::_extrudeDeprecated(
        hkResult *result,
        hkaiNavMeshGenerationSettings *input,
        hkaiEdgeGeometry *geomIn,
        hkaiEdgeGeometry *geomOut)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx
  hkVector4f extrudeDirection; // [rsp+20h] [rbp-18h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "Tt_extrude";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  extrudeDirection.m_quad = _mm_mul_ps(
                              _mm_sub_ps(
                                (__m128)0i64,
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(input->m_characterHeight),
                                  (__m128)LODWORD(input->m_characterHeight),
                                  0)),
                              input->m_up.m_quad);
  hkaiGeometryExtrudeUtil::silhouetteExtrudeDeprecated(result, geomIn, &extrudeDirection, geomOut);
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)v13[1];
  if ( (unsigned __int64)v14 < v13[3] )
  {
    *v14 = "Et";
    v15 = __rdtsc();
    v16 = v14 + 2;
    *((_DWORD *)v16 - 2) = v15;
    v13[1] = v16;
  }
  return result;
}

// File Line: 775
// RVA: 0xBA9600
hkResult *__fastcall hkaiNavMeshGenerationUtils::_subtractDeprecated(
        hkResult *result,
        hkaiNavMeshGenerationSettings *input,
        hkaiEdgeGeometry *cuttingGeom,
        hkaiEdgeGeometry *walkableGeomInOut,
        hkaiBooleanFaceFaceIntersects *intersects)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  _QWORD *v13; // r9
  unsigned __int64 v14; // r8
  unsigned __int64 v15; // rax
  hkResult v17; // [rsp+40h] [rbp-C0h] BYREF
  hkResult v18; // [rsp+44h] [rbp-BCh] BYREF
  hkResult resulta; // [rsp+48h] [rbp-B8h] BYREF
  hkaiEdgeGeometry geomA; // [rsp+50h] [rbp-B0h] BYREF
  hkaiSelfIntersectBooleanFilter2 filter; // [rsp+A0h] [rbp-60h] BYREF
  hkaiBooleanOperation v22; // [rsp+100h] [rbp+0h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "Tt_subtract";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  hkaiEdgeGeometry::hkaiEdgeGeometry(&geomA);
  hkaiEdgeGeometry::set(&geomA, &resulta, walkableGeomInOut);
  if ( resulta.m_enum )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    hkaiBooleanOperation::hkaiBooleanOperation(&v22);
    hkaiSelfIntersectBooleanFilter2::hkaiSelfIntersectBooleanFilter2(&filter);
    hkaiSelfIntersectBooleanFilter2::setEdgeGeoms(&filter, &v18, &geomA, cuttingGeom);
    if ( v18.m_enum )
    {
      result->m_enum = HK_FAILURE;
    }
    else
    {
      hkaiBooleanOperation::subtract(&v22, &v17, &geomA, cuttingGeom, walkableGeomInOut, intersects, &filter);
      if ( v17.m_enum )
        result->m_enum = HK_FAILURE;
      else
        result->m_enum = HK_SUCCESS;
    }
    hkaiSelfIntersectBooleanFilter2::~hkaiSelfIntersectBooleanFilter2(&filter);
    hkaiBooleanOperation::~hkaiBooleanOperation(&v22);
  }
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&geomA);
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = v13[1];
  if ( v14 < v13[3] )
  {
    v15 = __rdtsc();
    *(_DWORD *)(v14 + 8) = v15;
    *(_QWORD *)v14 = "Et";
    v13[1] = v14 + 16;
  }
  return result;
}

