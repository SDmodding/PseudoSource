// File Line: 84
// RVA: 0xBA63C0
void __fastcall hkaiNavMeshGenerationUtils::DeprecatedGenerationOutputs::DeprecatedGenerationOutputs(hkaiNavMeshGenerationUtils::DeprecatedGenerationOutputs *this)
{
  this->m_cuttingGeom = 0i64;
  this->m_walkableGeom = 0i64;
  this->m_extrudedCuttingGeom = 0i64;
  this->m_unsimplifiedNavMesh = 0i64;
  this->m_navMesh = 0i64;
}

// File Line: 90
// RVA: 0xBA63E0
hkaiNavMeshGenerationResult::GenerationResultEnum __fastcall hkaiNavMeshGenerationUtils::generateNavMeshDeprecated(hkaiNavMeshGenerationSettings *input, hkGeometry *triMeshIn, hkaiNavMesh *navMeshOut)
{
  hkaiNavMeshGenerationSettings *v3; // rsi
  hkaiNavMesh *v4; // rbx
  hkGeometry *v5; // rdi
  hkaiNavMeshGenerationUtils::DeprecatedGenerationOutputs outputs; // [rsp+20h] [rbp-38h]

  v3 = input;
  v4 = navMeshOut;
  v5 = triMeshIn;
  hkaiNavMeshGenerationUtils::DeprecatedGenerationOutputs::DeprecatedGenerationOutputs(&outputs);
  outputs.m_navMesh = v4;
  return hkaiNavMeshGenerationUtils::_generateNavMeshDeprecated(v3, v5, &outputs, 0i64);
}

// File Line: 101
// RVA: 0xBA6430
__int64 __fastcall hkaiNavMeshGenerationUtils::_generateNavMeshDeprecated(hkaiNavMeshGenerationSettings *input, hkGeometry *triMeshIn, hkaiNavMeshGenerationUtils::DeprecatedGenerationOutputs *outputs, hkaiEdgeGeometryRaycaster *edgeConnectionRayCaster)
{
  hkaiNavMeshGenerationSettings *v4; // r14
  hkaiNavMeshGenerationUtils::DeprecatedGenerationOutputs *v5; // rsi
  hkGeometry *v6; // rbx
  _QWORD *v7; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r8
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  hkVector4f *v12; // rax
  unsigned int v13; // edi
  hkVector4f *v14; // rax
  hkaiEdgeGeometry *v15; // r12
  hkaiEdgeGeometry *v16; // rdi
  hkaiEdgeGeometry *v17; // rcx
  hkaiEdgeGeometry *v18; // rax
  hkaiEdgeGeometry *v19; // rax
  hkaiNavMesh *v20; // r13
  hkaiNavMesh *v21; // r15
  int v22; // eax
  __int64 v23; // r12
  int v24; // eax
  int v25; // er8
  int v26; // ebx
  int v27; // er9
  hkVector4f *v28; // rax
  __int64 i; // rbx
  int v30; // eax
  hkVector4f v31; // xmm1
  int v32; // ebx
  int v33; // er9
  hkVector4f *v34; // rax
  int v35; // edx
  int v36; // ecx
  int v37; // eax
  int v38; // eax
  int v39; // er9
  hkRefPtr<hkaiVolume const > *v40; // r12
  __int64 v41; // rbx
  hkReferencedObject *v42; // rcx
  __int64 v43; // rcx
  hkRefPtr<hkaiVolume const > *v44; // r12
  __int64 v45; // rbx
  hkRefPtr<hkaiVolume const > *v46; // rsi
  __int64 v47; // r13
  hkReferencedObject *v48; // rcx
  hkReferencedObject *v49; // rcx
  hkaiVolume *v50; // rax
  hkReferencedObject **v51; // rbx
  hkRefPtr<hkaiVolume const > *v52; // rcx
  __int64 v53; // rdx
  __int64 v54; // rcx
  hkReferencedObject **v55; // r12
  _QWORD **v56; // rax
  hkaiInvertedAabbVolume *v57; // rax
  hkaiVolume *v58; // rax
  hkaiVolume *v59; // r12
  int v60; // ecx
  hkRefPtr<hkaiVolume const > *v61; // rbx
  hkRefPtr<hkaiVolume const > *v62; // rdx
  __int64 v63; // rax
  hkReferencedObject *v64; // rcx
  __m128 v65; // xmm2
  __m128 v66; // xmm3
  hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *v67; // r12
  hkVector4f *v68; // rax
  hkVector4f *v69; // rax
  _QWORD *v70; // r8
  _QWORD *v71; // rcx
  unsigned __int64 v72; // rax
  signed __int64 v73; // rcx
  float v74; // xmm1_4
  int v75; // ebx
  int v76; // er12
  int v77; // eax
  int v78; // er9
  hkErrStream *v79; // rcx
  int v80; // eax
  int v81; // eax
  int v82; // er9
  int v83; // ebx
  int v84; // er9
  int v85; // er9
  int v86; // er9
  hkVector4f *v87; // rax
  int v88; // er9
  hkErrStream *v89; // rcx
  hkVector4f *v90; // rax
  hkaiEdgeGeometry *v91; // rbx
  hkVector4f *v92; // rax
  hkErrStream *v93; // rcx
  unsigned int v94; // ebx
  unsigned int v95; // er8
  hkaiEdgeGeometry *v96; // rbx
  hkVector4f *v97; // rax
  _QWORD *v98; // r8
  _QWORD *v99; // rcx
  unsigned __int64 v100; // rax
  signed __int64 v101; // rcx
  _QWORD *v102; // r8
  _QWORD *v103; // rcx
  unsigned __int64 v104; // rax
  signed __int64 v105; // rcx
  _QWORD *v106; // r8
  _QWORD *v107; // rcx
  unsigned __int64 v108; // rax
  signed __int64 v109; // rcx
  hkVector4f *v110; // rax
  _QWORD *v111; // r8
  _QWORD *v112; // rcx
  unsigned __int64 v113; // rax
  signed __int64 v114; // rcx
  _QWORD *v115; // r8
  _QWORD *v116; // rcx
  unsigned __int64 v117; // rax
  signed __int64 v118; // rcx
  hkErrStream *v119; // rcx
  hkVector4f *v120; // rax
  _QWORD *v121; // r9
  _QWORD *v122; // rcx
  unsigned __int64 v123; // rax
  signed __int64 v124; // rcx
  hkaiEdgeGeometry *v125; // r12
  hkVector4f *v126; // rax
  _QWORD *v127; // r8
  _QWORD *v128; // rcx
  unsigned __int64 v129; // rax
  signed __int64 v130; // rcx
  _QWORD *v131; // r8
  _QWORD *v132; // rcx
  unsigned __int64 v133; // rax
  signed __int64 v134; // rcx
  _QWORD *v135; // rax
  _QWORD *v136; // rcx
  _QWORD *v137; // r8
  unsigned __int64 v138; // rax
  signed __int64 v139; // rcx
  hkVector4f *v140; // rax
  _QWORD *v141; // r8
  _QWORD *v142; // rcx
  unsigned __int64 v143; // rax
  signed __int64 v144; // rcx
  _QWORD *v145; // r9
  _QWORD *v146; // rcx
  unsigned __int64 v147; // rax
  signed __int64 v148; // rcx
  _QWORD *v149; // r8
  _QWORD *v150; // rcx
  unsigned __int64 v151; // rax
  signed __int64 v152; // rcx
  hkErrStream *v153; // rcx
  hkVector4f *v154; // rax
  _QWORD *v155; // r8
  _QWORD *v156; // rcx
  unsigned __int64 v157; // rax
  signed __int64 v158; // rcx
  _QWORD *v159; // r8
  _QWORD *v160; // rcx
  unsigned __int64 v161; // rax
  signed __int64 v162; // rcx
  int v163; // eax
  int v164; // er9
  hkVector4f *v165; // rcx
  hkErrStream *v166; // rcx
  __m128 *v167; // rdx
  __int64 v168; // r8
  hkVector4f v169; // xmm0
  int v170; // ebx
  _QWORD *v171; // r8
  _QWORD *v172; // rcx
  unsigned __int64 v173; // rax
  signed __int64 v174; // rcx
  hkaiEdgeGeometryRaycaster *v175; // r12
  hkErrStream *v176; // rcx
  hkVector4f *v177; // rax
  _QWORD *v178; // r8
  _QWORD *v179; // rcx
  unsigned __int64 v180; // rax
  signed __int64 v181; // rcx
  _QWORD *v182; // r8
  _QWORD *v183; // rcx
  unsigned __int64 v184; // rax
  signed __int64 v185; // rcx
  hkErrStream *v186; // rcx
  __m128 v187; // xmm2
  hkaiNavMesh *v188; // rcx
  _QWORD *v189; // r8
  _QWORD *v190; // rcx
  unsigned __int64 v191; // rax
  signed __int64 v192; // rcx
  int v193; // ebx
  int v194; // er8
  int v195; // eax
  int v196; // er8
  int v197; // er8
  int v198; // er8
  hkVector4f *v199; // rax
  _QWORD *v200; // r8
  _QWORD *v201; // rcx
  unsigned __int64 v202; // rax
  signed __int64 v203; // rcx
  _QWORD *v204; // r9
  _QWORD *v205; // rcx
  unsigned __int64 v206; // rax
  signed __int64 v207; // rcx
  hkVector4f *v208; // rax
  hkVector4f *v209; // rax
  _QWORD *v210; // r8
  _QWORD *v211; // rcx
  unsigned __int64 v212; // rax
  signed __int64 v213; // rcx
  int v214; // ebx
  hkRefPtr<hkaiVolume const > *v215; // rsi
  _QWORD *v216; // rax
  _QWORD *v217; // rcx
  _QWORD *v218; // r8
  unsigned __int64 v219; // rax
  signed __int64 v220; // rcx
  hkArrayBase<hkRefPtr<hkaiVolume const > > carvers; // [rsp+80h] [rbp-80h]
  hkArray<hkVector4f,hkContainerHeapAllocator> vertsIn; // [rsp+90h] [rbp-70h]
  hkArrayBase<hk1AxisSweep::AabbInt> sortedAabbs; // [rsp+A0h] [rbp-60h]
  hkArrayBase<hkRadixSort::SortData32> sortData; // [rsp+B0h] [rbp-50h]
  hkArray<hkVector4f,hkContainerHeapAllocator> uniqueVerts; // [rsp+C0h] [rbp-40h]
  hkArrayBase<hk1AxisSweep::AabbInt> sweepAabbs; // [rsp+D0h] [rbp-30h]
  int v228; // [rsp+E0h] [rbp-20h]
  hkArray<int,hkContainerHeapAllocator> triangleRemapOut; // [rsp+E8h] [rbp-18h]
  char v230; // [rsp+F8h] [rbp-8h]
  char v231; // [rsp+F9h] [rbp-7h]
  hkArray<int,hkContainerHeapAllocator> vertexRemapOut; // [rsp+100h] [rbp+0h]
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> newTriangles; // [rsp+110h] [rbp+10h]
  void *array; // [rsp+120h] [rbp+20h]
  int v235; // [rsp+128h] [rbp+28h]
  int v236; // [rsp+12Ch] [rbp+2Ch]
  hkArray<int,hkContainerHeapAllocator> trisPerFaceOut; // [rsp+130h] [rbp+30h]
  hkResult v238; // [rsp+140h] [rbp+40h]
  hkResult v239; // [rsp+144h] [rbp+44h]
  hkResult v240; // [rsp+148h] [rbp+48h]
  hkArray<int,hkContainerHeapAllocator> trisOut; // [rsp+150h] [rbp+50h]
  hkResult v242; // [rsp+160h] [rbp+60h]
  __int64 v243; // [rsp+168h] [rbp+68h]
  hkResult v244; // [rsp+170h] [rbp+70h]
  hkResult v245; // [rsp+174h] [rbp+74h]
  hkResult v246; // [rsp+178h] [rbp+78h]
  hkResult v247; // [rsp+17Ch] [rbp+7Ch]
  hkResult v248; // [rsp+180h] [rbp+80h]
  hkResult v249; // [rsp+184h] [rbp+84h]
  hkResult v250; // [rsp+188h] [rbp+88h]
  int v251; // [rsp+18Ch] [rbp+8Ch]
  hkResult v252; // [rsp+190h] [rbp+90h]
  hkaiNavMesh *v253; // [rsp+198h] [rbp+98h]
  hkArray<int,hkContainerHeapAllocator> materialsOut; // [rsp+1A0h] [rbp+A0h]
  int v255; // [rsp+1B0h] [rbp+B0h]
  hkArray<int,hkContainerHeapAllocator> triConnectivityOut; // [rsp+1B8h] [rbp+B8h]
  hkaiEdgeGeometry *geomInOut; // [rsp+1C8h] [rbp+C8h]
  hkaiEdgeGeometry *extrudeGeom; // [rsp+1D0h] [rbp+D0h]
  hkResult v259; // [rsp+1D8h] [rbp+D8h]
  hkResult v260; // [rsp+1DCh] [rbp+DCh]
  hkResult v261; // [rsp+1E0h] [rbp+E0h]
  int newStride; // [rsp+1E4h] [rbp+E4h]
  hkResult v263; // [rsp+1E8h] [rbp+E8h]
  hkResult v264; // [rsp+1ECh] [rbp+ECh]
  hkResult v265; // [rsp+1F0h] [rbp+F0h]
  hkResult v266; // [rsp+1F4h] [rbp+F4h]
  hkResult v267; // [rsp+1F8h] [rbp+F8h]
  hkResult v268; // [rsp+1FCh] [rbp+FCh]
  hkResult v269; // [rsp+200h] [rbp+100h]
  hkResult v270; // [rsp+204h] [rbp+104h]
  hkResult v271; // [rsp+208h] [rbp+108h]
  hkResult v272; // [rsp+20Ch] [rbp+10Ch]
  hkResult v273; // [rsp+210h] [rbp+110h]
  hkResult v274; // [rsp+214h] [rbp+114h]
  hkResult v275; // [rsp+218h] [rbp+118h]
  hkResult v276; // [rsp+21Ch] [rbp+11Ch]
  hkResult v277; // [rsp+220h] [rbp+120h]
  hkResult v278; // [rsp+224h] [rbp+124h]
  hkResult v279; // [rsp+228h] [rbp+128h]
  hkResult v280; // [rsp+22Ch] [rbp+12Ch]
  hkGeometry dstGeom; // [rsp+230h] [rbp+130h]
  hkaiEdgeGeometry *geomOut; // [rsp+260h] [rbp+160h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v283; // [rsp+268h] [rbp+168h]
  hkResult result; // [rsp+278h] [rbp+178h]
  hkResult v285; // [rsp+27Ch] [rbp+17Ch]
  hkResult v286; // [rsp+288h] [rbp+188h]
  hkResult v287; // [rsp+28Ch] [rbp+18Ch]
  hkResult v288; // [rsp+290h] [rbp+190h]
  hkResult v289; // [rsp+294h] [rbp+194h]
  hkAabb pruneAabb; // [rsp+2A0h] [rbp+1A0h]
  hkErrStream v291; // [rsp+2C0h] [rbp+1C0h]
  hkErrStream v292; // [rsp+2D8h] [rbp+1D8h]
  hkErrStream v293; // [rsp+2F0h] [rbp+1F0h]
  hkErrStream v294; // [rsp+308h] [rbp+208h]
  hkErrStream v295; // [rsp+320h] [rbp+220h]
  hkErrStream v296; // [rsp+338h] [rbp+238h]
  hkErrStream v297; // [rsp+350h] [rbp+250h]
  hkErrStream v298; // [rsp+368h] [rbp+268h]
  hkErrStream v299; // [rsp+380h] [rbp+280h]
  hkErrStream v300; // [rsp+398h] [rbp+298h]
  hkErrStream v301; // [rsp+3B0h] [rbp+2B0h]
  hkErrStream v302; // [rsp+3C8h] [rbp+2C8h]
  hkErrStream v303; // [rsp+3E0h] [rbp+2E0h]
  hkErrStream v304; // [rsp+3F8h] [rbp+2F8h]
  hkErrStream v305; // [rsp+410h] [rbp+310h]
  hkErrStream v306; // [rsp+428h] [rbp+328h]
  hkErrStream v307; // [rsp+440h] [rbp+340h]
  hkErrStream v308; // [rsp+458h] [rbp+358h]
  hkErrStream v309; // [rsp+470h] [rbp+370h]
  hkErrStream v310; // [rsp+488h] [rbp+388h]
  hkErrStream v311; // [rsp+4A0h] [rbp+3A0h]
  hkErrStream v312; // [rsp+4B8h] [rbp+3B8h]
  hkErrStream v313; // [rsp+4D0h] [rbp+3D0h]
  hkErrStream v314; // [rsp+4E8h] [rbp+3E8h]
  hkErrStream v315; // [rsp+500h] [rbp+400h]
  hkErrStream v316; // [rsp+518h] [rbp+418h]
  hkErrStream v317; // [rsp+530h] [rbp+430h]
  hkErrStream v318; // [rsp+548h] [rbp+448h]
  hkErrStream v319; // [rsp+560h] [rbp+460h]
  hkErrStream v320; // [rsp+578h] [rbp+478h]
  hkErrStream v321; // [rsp+590h] [rbp+490h]
  hkErrStream v322; // [rsp+5A8h] [rbp+4A8h]
  hkErrStream v323; // [rsp+5C0h] [rbp+4C0h]
  hkErrStream v324; // [rsp+5D8h] [rbp+4D8h]
  hkErrStream v325; // [rsp+5F0h] [rbp+4F0h]
  hkErrStream v326; // [rsp+608h] [rbp+508h]
  hkErrStream v327; // [rsp+620h] [rbp+520h]
  hkErrStream v328; // [rsp+638h] [rbp+538h]
  hkErrStream v329; // [rsp+650h] [rbp+550h]
  hkErrStream v330; // [rsp+668h] [rbp+568h]
  hkErrStream v331; // [rsp+680h] [rbp+580h]
  hkErrStream v332; // [rsp+698h] [rbp+598h]
  hkErrStream v333; // [rsp+6B0h] [rbp+5B0h]
  hkErrStream v334; // [rsp+6C8h] [rbp+5C8h]
  hkaiCarverTree carverTree; // [rsp+6E0h] [rbp+5E0h]
  hkaiEdgeGeometryRaycaster cuttingGeomRaycaster; // [rsp+710h] [rbp+610h]
  hkaiGeometryToEdgeGeometryConverter v337; // [rsp+780h] [rbp+680h]
  hkaiEdgeGeometry v338; // [rsp+7E0h] [rbp+6E0h]
  hkaiEdgeGeometry v339; // [rsp+830h] [rbp+730h]
  hkaiEdgeGeometry v340; // [rsp+880h] [rbp+780h]
  hkaiNavMesh v341; // [rsp+8D0h] [rbp+7D0h]
  hkaiNavMesh v342; // [rsp+980h] [rbp+880h]
  char v343; // [rsp+A30h] [rbp+930h]
  char v344; // [rsp+C30h] [rbp+B30h]
  char description; // [rsp+E30h] [rbp+D30h]
  char v346; // [rsp+1030h] [rbp+F30h]
  char v347; // [rsp+1230h] [rbp+1130h]
  char v348; // [rsp+1430h] [rbp+1330h]
  char v349; // [rsp+1630h] [rbp+1530h]
  char v350; // [rsp+1830h] [rbp+1730h]
  char v351; // [rsp+1A30h] [rbp+1930h]
  char v352; // [rsp+1C30h] [rbp+1B30h]
  char v353; // [rsp+1E30h] [rbp+1D30h]
  char v354; // [rsp+2030h] [rbp+1F30h]
  char v355; // [rsp+2230h] [rbp+2130h]
  char v356; // [rsp+2430h] [rbp+2330h]
  char v357; // [rsp+2630h] [rbp+2530h]
  char v358; // [rsp+2830h] [rbp+2730h]
  char v359; // [rsp+2A30h] [rbp+2930h]
  char v360; // [rsp+2C30h] [rbp+2B30h]
  char v361; // [rsp+2E30h] [rbp+2D30h]
  char v362; // [rsp+3030h] [rbp+2F30h]
  char buf; // [rsp+3230h] [rbp+3130h]
  char v364; // [rsp+3430h] [rbp+3330h]
  char v365; // [rsp+3630h] [rbp+3530h]
  char v366; // [rsp+3830h] [rbp+3730h]
  char v367; // [rsp+3A30h] [rbp+3930h]
  char v368; // [rsp+3C30h] [rbp+3B30h]
  char v369; // [rsp+3E30h] [rbp+3D30h]
  char v370; // [rsp+4030h] [rbp+3F30h]
  char v371; // [rsp+4230h] [rbp+4130h]
  char v372; // [rsp+4430h] [rbp+4330h]
  char v373; // [rsp+4630h] [rbp+4530h]
  char v374; // [rsp+4830h] [rbp+4730h]
  char v375; // [rsp+4A30h] [rbp+4930h]
  char v376; // [rsp+4C30h] [rbp+4B30h]
  char v377; // [rsp+4E30h] [rbp+4D30h]
  char v378; // [rsp+5030h] [rbp+4F30h]
  char v379; // [rsp+5230h] [rbp+5130h]
  char v380; // [rsp+5430h] [rbp+5330h]
  char v381; // [rsp+5630h] [rbp+5530h]
  char v382; // [rsp+5830h] [rbp+5730h]
  char v383; // [rsp+5A30h] [rbp+5930h]
  char v384; // [rsp+5C30h] [rbp+5B30h]
  char v385; // [rsp+5E30h] [rbp+5D30h]
  char v386; // [rsp+6030h] [rbp+5F30h]
  hkGeometry *srcGeom; // [rsp+6278h] [rbp+6178h]
  hkaiNavMeshGenerationUtils::DeprecatedGenerationOutputs *v388; // [rsp+6280h] [rbp+6180h]
  hkaiEdgeGeometryRaycaster *raycaster; // [rsp+6288h] [rbp+6188h]

  raycaster = edgeConnectionRayCaster;
  v388 = outputs;
  srcGeom = triMeshIn;
  v4 = input;
  v5 = outputs;
  v6 = triMeshIn;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)v7[1];
  v9 = v7;
  if ( (unsigned __int64)v8 < v7[3] )
  {
    *v8 = "TthkaiNavMeshGenerationUtils::generateNavMesh";
    v10 = __rdtsc();
    v11 = (signed __int64)(v8 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v9[1] = v11;
  }
  if ( !v6->m_triangles.m_size )
  {
    hkErrStream::hkErrStream(&v320, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v320.vfptr, "Passed in empty triMesh to generateNavMesh()");
    hkError::messageWarning(1060047688, &buf, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 108);
    hkOstream::~hkOstream((hkOstream *)&v320.vfptr);
    v12 = (hkVector4f *)v5->m_navMesh;
    if ( v12 )
    {
      v12[8] = (hkVector4f)aabbOut.m_quad;
      v12[9] = (hkVector4f)aabbOut.m_quad;
    }
    v13 = 1;
    goto LABEL_362;
  }
  if ( !HK_flyingcolors_ai_1.m_bool )
  {
    hkaiCheckKeycode();
    hkaiProcessFlyingColors(&HK_flyingcolors_ai_1);
    if ( !HK_flyingcolors_ai_1.m_bool )
    {
      hkErrStream::hkErrStream(&v331, &description, 512);
      hkOstream::operator<<((hkOstream *)&v331.vfptr, "Invalid keycode. Exiting nav mesh generation.");
      hkError::messageWarning(691989308, &description, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 120);
      hkOstream::~hkOstream((hkOstream *)&v331.vfptr);
      v14 = (hkVector4f *)v5->m_navMesh;
      if ( v14 )
      {
        v14[8] = (hkVector4f)aabbOut.m_quad;
        v14[9] = (hkVector4f)aabbOut.m_quad;
      }
      v13 = 3;
      goto LABEL_362;
    }
  }
  hkaiEdgeGeometry::hkaiEdgeGeometry(&v339);
  hkaiEdgeGeometry::hkaiEdgeGeometry(&v338);
  hkaiEdgeGeometry::hkaiEdgeGeometry(&v340);
  v15 = &v339;
  v16 = &v338;
  v17 = &v340;
  if ( v5->m_cuttingGeom )
    v15 = v5->m_cuttingGeom;
  v18 = v5->m_walkableGeom;
  geomOut = v15;
  if ( v18 )
    v16 = v18;
  v19 = v5->m_extrudedCuttingGeom;
  geomInOut = v16;
  if ( v19 )
    v17 = v19;
  extrudeGeom = v17;
  hkaiNavMesh::hkaiNavMesh(&v342);
  hkaiNavMesh::hkaiNavMesh(&v341);
  v20 = &v341;
  v21 = &v342;
  if ( v5->m_navMesh )
    v20 = v5->m_navMesh;
  v22 = v20->m_edgeDataStriding;
  if ( !v4->m_enableSimplification.m_bool )
    v21 = v20;
  v253 = v20;
  newStride = v22;
  hkaiNavMesh::setEdgeDataStriding(v20, &result, 0, 0);
  hkaiNavMesh::setEdgeDataStriding(v21, &v286, 0, 0);
  hkaiEdgeGeometry::clear(v15);
  hkaiEdgeGeometry::clear(v16);
  hkaiEdgeGeometry::clear(extrudeGeom);
  if ( v4->m_saveInputSnapshot.m_bool )
    hkaiNavMeshGenerationUtils::_saveSnapshot(v4, v6);
  v23 = v4->m_materialMap.m_size;
  v236 = 2147483648;
  array = 0i64;
  v235 = 0;
  v24 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(v23);
  v25 = v236;
  v13 = 1;
  v26 = v24;
  if ( (v236 & 0x3FFFFFFF) >= v24 )
  {
    v249.m_enum = 0;
  }
  else
  {
    v27 = v24;
    if ( v24 < 2 * (v236 & 0x3FFFFFFF) )
      v27 = 2 * (v236 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v249, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v27, 1);
    if ( v249.m_enum )
    {
      hkErrStream::hkErrStream(&v333, &v381, 512);
      hkOstream::operator<<(
        (hkOstream *)&v333.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v381, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 193);
      hkOstream::~hkOstream((hkOstream *)&v333.vfptr);
      v28 = (hkVector4f *)v5->m_navMesh;
      if ( v28 )
      {
        v28[8] = (hkVector4f)aabbOut.m_quad;
        v28[9] = (hkVector4f)aabbOut.m_quad;
      }
      v13 = 2;
      goto LABEL_359;
    }
    v25 = v236;
  }
  v235 = v26;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
    &v283,
    array,
    v25 & 0x3FFFFFFF);
  for ( i = 0i64; i < v23; ++i )
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &v283,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (unsigned int)v4->m_materialMap.m_data[i].m_materialIndex,
      v4->m_materialMap.m_data[i].m_flags.m_storage);
  v30 = 2147483648;
  pruneAabb.m_min = v4->m_boundsAabb.m_min;
  v31.m_quad = (__m128)v4->m_boundsAabb.m_max;
  v32 = 0;
  carvers.m_data = 0i64;
  carvers.m_size = 0;
  carvers.m_capacityAndFlags = 2147483648;
  pruneAabb.m_max = (hkVector4f)v31.m_quad;
  v33 = v4->m_carvers.m_size + 1;
  if ( v33 <= 0 )
  {
    v245.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(&v245, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &carvers, v33, 8);
    if ( v245.m_enum )
    {
      hkErrStream::hkErrStream(&v294, &v347, 512);
      hkOstream::operator<<(
        (hkOstream *)&v294.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v347, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 211);
      hkOstream::~hkOstream((hkOstream *)&v294.vfptr);
      v34 = (hkVector4f *)v5->m_navMesh;
      if ( v34 )
      {
        v34[8] = (hkVector4f)aabbOut.m_quad;
        v34[9] = (hkVector4f)aabbOut.m_quad;
      }
      v13 = 2;
      goto LABEL_353;
    }
    v30 = carvers.m_capacityAndFlags;
    v32 = carvers.m_size;
  }
  v36 = v4->m_carvers.m_size;
  v228 = v4->m_carvers.m_size;
  v35 = v228;
  if ( v228 > v32 )
    v36 = v32;
  v37 = v30 & 0x3FFFFFFF;
  v251 = v36;
  if ( v37 >= v228 )
  {
    v266.m_enum = 0;
  }
  else
  {
    v38 = 2 * v37;
    v39 = v228;
    if ( v228 < v38 )
      v39 = v38;
    hkArrayUtil::_reserve(&v266, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &carvers, v39, 8);
    v35 = v228;
  }
  v40 = &carvers.m_data[v35];
  v41 = v32 - v35 - 1;
  if ( (signed int)v41 >= 0 )
  {
    do
    {
      v42 = (hkReferencedObject *)&v40[v41].m_pntr->vfptr;
      if ( v42 )
        hkReferencedObject::removeReference(v42);
      v40[v41--].m_pntr = 0i64;
    }
    while ( v41 >= 0 );
  }
  v43 = v251;
  v44 = v4->m_carvers.m_data;
  v45 = 0i64;
  v243 = v251;
  if ( v251 > 0i64 )
  {
    v46 = carvers.m_data;
    v47 = v251;
    do
    {
      v48 = (hkReferencedObject *)&v44[v45].m_pntr->vfptr;
      if ( v48 )
        hkReferencedObject::addReference(v48);
      v49 = (hkReferencedObject *)&v46[v45].m_pntr->vfptr;
      if ( v49 )
        hkReferencedObject::removeReference(v49);
      v50 = v44[v45++].m_pntr;
      v46[v45 - 1].m_pntr = v50;
    }
    while ( v45 < v47 );
    v5 = v388;
    v20 = v253;
    v43 = v243;
  }
  v51 = (hkReferencedObject **)&v4->m_carvers.m_data[v43];
  v52 = &carvers.m_data[v43];
  v53 = v228 - v251;
  v243 = v228 - v251;
  if ( v228 - v251 > 0 )
  {
    v54 = (char *)v52 - (char *)v51;
    v253 = (hkaiNavMesh *)v54;
    do
    {
      v55 = (hkReferencedObject **)((char *)v51 + v54);
      if ( (hkReferencedObject **)((char *)v51 + v54) )
      {
        if ( *v51 )
        {
          hkReferencedObject::addReference(*v51);
          v53 = v243;
        }
        v54 = (__int64)v253;
        *v55 = *v51;
      }
      ++v51;
      v243 = --v53;
    }
    while ( v53 );
  }
  carvers.m_size = v228;
  if ( !(_mm_movemask_ps(_mm_cmpleps(v4->m_boundsAabb.m_max.m_quad, v4->m_boundsAabb.m_min.m_quad)) & 7) )
  {
    v56 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v57 = (hkaiInvertedAabbVolume *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v56[11] + 8i64))(
                                      v56[11],
                                      96i64);
    if ( v57 )
    {
      hkaiInvertedAabbVolume::hkaiInvertedAabbVolume(v57, &v4->m_boundsAabb);
      v59 = v58;
    }
    else
    {
      v59 = 0i64;
    }
    v60 = carvers.m_size;
    if ( carvers.m_size == (carvers.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &carvers, 8);
      v60 = carvers.m_size;
    }
    v61 = carvers.m_data;
    v62 = &carvers.m_data[v60];
    if ( v62 )
    {
      v62->m_pntr = 0i64;
      v60 = carvers.m_size;
      v61 = carvers.m_data;
    }
    v63 = v60;
    carvers.m_size = v60 + 1;
    v64 = (hkReferencedObject *)&v61[v60].m_pntr->vfptr;
    v253 = (hkaiNavMesh *)v63;
    if ( v64 && v64 != (hkReferencedObject *)v59 )
    {
      hkReferencedObject::removeReference(v64);
      v63 = (__int64)v253;
    }
    v61[v63].m_pntr = v59;
    v65 = (__m128)LODWORD(v4->m_characterHeight);
    v66 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v65, v65, 0), v4->m_up.m_quad), v4->m_boundsAabb.m_min.m_quad);
    pruneAabb.m_max.m_quad = _mm_max_ps(
                               v4->m_boundsAabb.m_max.m_quad,
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps(v65, v65, 0), v4->m_up.m_quad),
                                 v4->m_boundsAabb.m_max.m_quad));
    pruneAabb.m_min.m_quad = _mm_min_ps(v4->m_boundsAabb.m_min.m_quad, v66);
  }
  hkaiCarverTree::hkaiCarverTree(&carverTree);
  v67 = (hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *)&v4->m_painters.m_data;
  hkaiCarverTree::init(
    &carverTree,
    &v289,
    &carvers,
    (hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *)&v4->m_painters.m_data);
  *(_DWORD *)&dstGeom.m_memSizeAndFlags = 0x1FFFF;
  dstGeom.m_vertices.m_data = 0i64;
  dstGeom.m_vertices.m_size = 0;
  dstGeom.m_vertices.m_capacityAndFlags = 2147483648;
  dstGeom.m_triangles.m_data = 0i64;
  dstGeom.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable';
  dstGeom.m_triangles.m_size = 0;
  dstGeom.m_triangles.m_capacityAndFlags = 2147483648;
  hkaiNavMeshGenerationUtils::safeCopyAndPruneByAabb(
    &v276,
    &dstGeom,
    srcGeom,
    &pruneAabb,
    (hkaiNavMeshGenerationSettings::TriangleWinding)(unsigned __int8)v4->m_triangleWinding.m_storage);
  if ( v276.m_enum )
  {
    hkErrStream::hkErrStream(&v293, &v367, 512);
    hkOstream::operator<<(
      (hkOstream *)&v293.vfptr,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, &v367, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 238);
    hkOstream::~hkOstream((hkOstream *)&v293.vfptr);
    v68 = (hkVector4f *)v5->m_navMesh;
    if ( v68 )
    {
      v68[8] = (hkVector4f)aabbOut.m_quad;
      v68[9] = (hkVector4f)aabbOut.m_quad;
    }
    v13 = 2;
    hkGeometry::~hkGeometry(&dstGeom);
    goto LABEL_352;
  }
  if ( dstGeom.m_triangles.m_size )
  {
    v70 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v71 = (_QWORD *)v70[1];
    if ( (unsigned __int64)v71 < v70[3] )
    {
      *v71 = "TtconvertAndMerge";
      v72 = __rdtsc();
      v73 = (signed __int64)(v71 + 2);
      *(_DWORD *)(v73 - 8) = v72;
      v70[1] = v73;
    }
    v74 = v4->m_quantizationGridSize;
    if ( v74 != 0.0 )
      hkaiNavMeshGenerationUtils::quantize(&dstGeom, v74);
    hkaiNavMeshGenerationUtils::setCarvedMaterialsDeprecated(
      &dstGeom,
      v4->m_carvedCuttingMaterialDeprecated,
      v4->m_carvedMaterialDeprecated,
      (hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v283,
      v4->m_defaultConstructionProperties.m_storage,
      &carverTree);
    if ( v4->m_weldInputVertices.m_bool )
    {
      v75 = dstGeom.m_vertices.m_size;
      v76 = dstGeom.m_triangles.m_size;
      v77 = 2147483648;
      vertexRemapOut.m_data = 0i64;
      vertexRemapOut.m_size = 0;
      vertexRemapOut.m_capacityAndFlags = 2147483648;
      triangleRemapOut.m_data = 0i64;
      triangleRemapOut.m_size = 0;
      triangleRemapOut.m_capacityAndFlags = 2147483648;
      sweepAabbs.m_data = 0i64;
      sweepAabbs.m_size = 0;
      sweepAabbs.m_capacityAndFlags = 2147483648;
      uniqueVerts.m_data = 0i64;
      uniqueVerts.m_size = 0;
      uniqueVerts.m_capacityAndFlags = 2147483648;
      sortData.m_data = 0i64;
      sortData.m_size = 0;
      sortData.m_capacityAndFlags = 2147483648;
      sortedAabbs.m_data = 0i64;
      sortedAabbs.m_size = 0;
      sortedAabbs.m_capacityAndFlags = 2147483648;
      if ( dstGeom.m_vertices.m_size <= 0 )
      {
        v247.m_enum = 0;
      }
      else
      {
        v78 = dstGeom.m_vertices.m_size;
        if ( dstGeom.m_vertices.m_size < 0 )
          v78 = 0;
        hkArrayUtil::_reserve(
          &v247,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &vertexRemapOut,
          v78,
          4);
        if ( v247.m_enum )
        {
          hkErrStream::hkErrStream(&v296, &v377, 512);
          hkOstream::operator<<(
            (hkOstream *)&v296.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v377, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 282);
          v79 = &v296;
LABEL_131:
          hkOstream::~hkOstream((hkOstream *)&v79->vfptr);
          v87 = (hkVector4f *)v5->m_navMesh;
          if ( v87 )
          {
            v87[8] = (hkVector4f)aabbOut.m_quad;
            v87[9] = (hkVector4f)aabbOut.m_quad;
          }
          sortedAabbs.m_size = 0;
          if ( sortedAabbs.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              sortedAabbs.m_data,
              32 * sortedAabbs.m_capacityAndFlags);
          sortedAabbs.m_data = 0i64;
          sortedAabbs.m_capacityAndFlags = 2147483648;
          sortData.m_size = 0;
          if ( sortData.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              sortData.m_data,
              8 * sortData.m_capacityAndFlags);
          sortData.m_data = 0i64;
          sortData.m_capacityAndFlags = 2147483648;
          uniqueVerts.m_size = 0;
          if ( uniqueVerts.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              uniqueVerts.m_data,
              16 * uniqueVerts.m_capacityAndFlags);
          uniqueVerts.m_data = 0i64;
          uniqueVerts.m_capacityAndFlags = 2147483648;
          sweepAabbs.m_size = 0;
          if ( sweepAabbs.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              sweepAabbs.m_data,
              32 * sweepAabbs.m_capacityAndFlags);
          sweepAabbs.m_data = 0i64;
          sweepAabbs.m_capacityAndFlags = 2147483648;
          triangleRemapOut.m_size = 0;
          if ( triangleRemapOut.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              triangleRemapOut.m_data,
              4 * triangleRemapOut.m_capacityAndFlags);
          triangleRemapOut.m_data = 0i64;
          triangleRemapOut.m_capacityAndFlags = 2147483648;
          vertexRemapOut.m_size = 0;
          if ( vertexRemapOut.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              vertexRemapOut.m_data,
              4 * vertexRemapOut.m_capacityAndFlags);
          vertexRemapOut.m_data = 0i64;
          vertexRemapOut.m_capacityAndFlags = 2147483648;
LABEL_185:
          v13 = 2;
          v98 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v99 = (_QWORD *)v98[1];
          if ( (unsigned __int64)v99 < v98[3] )
          {
            *v99 = "Et";
            v100 = __rdtsc();
            v101 = (signed __int64)(v99 + 2);
            *(_DWORD *)(v101 - 8) = v100;
            v98[1] = v101;
          }
          goto LABEL_187;
        }
        v77 = triangleRemapOut.m_capacityAndFlags;
      }
      v80 = v77 & 0x3FFFFFFF;
      if ( v80 >= v76 )
      {
        v239.m_enum = 0;
      }
      else
      {
        v81 = 2 * v80;
        if ( v76 < v81 )
          v76 = v81;
        hkArrayUtil::_reserve(
          &v239,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &triangleRemapOut,
          v76,
          4);
        if ( v239.m_enum )
        {
          hkErrStream::hkErrStream(&v316, &v351, 512);
          hkOstream::operator<<(
            (hkOstream *)&v316.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v351, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 285);
          v79 = &v316;
          goto LABEL_131;
        }
      }
      if ( (uniqueVerts.m_capacityAndFlags & 0x3FFFFFFF) >= v75 )
      {
        v240.m_enum = 0;
      }
      else
      {
        v82 = v75;
        if ( v75 < 2 * (uniqueVerts.m_capacityAndFlags & 0x3FFFFFFF) )
          v82 = 2 * (uniqueVerts.m_capacityAndFlags & 0x3FFFFFFF);
        hkArrayUtil::_reserve(
          &v240,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &uniqueVerts,
          v82,
          16);
        if ( v240.m_enum )
        {
          hkErrStream::hkErrStream(&v298, &v369, 512);
          hkOstream::operator<<(
            (hkOstream *)&v298.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v369, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 288);
          v79 = &v298;
          goto LABEL_131;
        }
      }
      v83 = v75 + 4;
      if ( (sweepAabbs.m_capacityAndFlags & 0x3FFFFFFF) >= v83 )
      {
        v242.m_enum = 0;
      }
      else
      {
        v84 = v83;
        if ( v83 < 2 * (sweepAabbs.m_capacityAndFlags & 0x3FFFFFFF) )
          v84 = 2 * (sweepAabbs.m_capacityAndFlags & 0x3FFFFFFF);
        hkArrayUtil::_reserve(
          &v242,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &sweepAabbs,
          v84,
          32);
        if ( v242.m_enum )
        {
          hkErrStream::hkErrStream(&v326, &v353, 512);
          hkOstream::operator<<(
            (hkOstream *)&v326.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v353, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 291);
          v79 = &v326;
          goto LABEL_131;
        }
      }
      if ( (sortData.m_capacityAndFlags & 0x3FFFFFFF) >= v83 )
      {
        v244.m_enum = 0;
      }
      else
      {
        v85 = v83;
        if ( v83 < 2 * (sortData.m_capacityAndFlags & 0x3FFFFFFF) )
          v85 = 2 * (sortData.m_capacityAndFlags & 0x3FFFFFFF);
        hkArrayUtil::_reserve(&v244, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &sortData, v85, 8);
        if ( v244.m_enum )
        {
          hkErrStream::hkErrStream(&v300, &v385, 512);
          hkOstream::operator<<(
            (hkOstream *)&v300.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v385, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 294);
          v79 = &v300;
          goto LABEL_131;
        }
      }
      sortData.m_size = v83;
      if ( (sortedAabbs.m_capacityAndFlags & 0x3FFFFFFF) >= v83 )
      {
        v246.m_enum = 0;
      }
      else
      {
        v86 = v83;
        if ( v83 < 2 * (sortedAabbs.m_capacityAndFlags & 0x3FFFFFFF) )
          v86 = 2 * (sortedAabbs.m_capacityAndFlags & 0x3FFFFFFF);
        hkArrayUtil::_reserve(
          &v246,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &sortedAabbs,
          v86,
          32);
        if ( v246.m_enum )
        {
          hkErrStream::hkErrStream(&v318, &v355, 512);
          hkOstream::operator<<(
            (hkOstream *)&v318.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v355, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 297);
          v79 = &v318;
          goto LABEL_131;
        }
      }
      sortedAabbs.m_size = v83;
      v231 = 0;
      hkGeometryUtils::_weldVertices(
        &dstGeom,
        v4->m_weldThreshold,
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
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          sortedAabbs.m_data,
          32 * sortedAabbs.m_capacityAndFlags);
      sortedAabbs.m_data = 0i64;
      sortedAabbs.m_capacityAndFlags = 2147483648;
      sortData.m_size = 0;
      if ( sortData.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          sortData.m_data,
          8 * sortData.m_capacityAndFlags);
      sortData.m_data = 0i64;
      sortData.m_capacityAndFlags = 2147483648;
      uniqueVerts.m_size = 0;
      if ( uniqueVerts.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          uniqueVerts.m_data,
          16 * uniqueVerts.m_capacityAndFlags);
      uniqueVerts.m_data = 0i64;
      uniqueVerts.m_capacityAndFlags = 2147483648;
      sweepAabbs.m_size = 0;
      if ( sweepAabbs.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          sweepAabbs.m_data,
          32 * sweepAabbs.m_capacityAndFlags);
      sweepAabbs.m_data = 0i64;
      sweepAabbs.m_capacityAndFlags = 2147483648;
      triangleRemapOut.m_size = 0;
      if ( triangleRemapOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          triangleRemapOut.m_data,
          4 * triangleRemapOut.m_capacityAndFlags);
      triangleRemapOut.m_data = 0i64;
      triangleRemapOut.m_capacityAndFlags = 2147483648;
      vertexRemapOut.m_size = 0;
      if ( vertexRemapOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          vertexRemapOut.m_data,
          4 * vertexRemapOut.m_capacityAndFlags);
      vertexRemapOut.m_data = 0i64;
      vertexRemapOut.m_capacityAndFlags = 2147483648;
      v67 = (hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *)&v4->m_painters.m_data;
    }
    v88 = dstGeom.m_triangles.m_size;
    newTriangles.m_data = 0i64;
    newTriangles.m_size = 0;
    newTriangles.m_capacityAndFlags = 2147483648;
    if ( dstGeom.m_triangles.m_size <= 0 )
    {
      v248.m_enum = 0;
    }
    else
    {
      if ( dstGeom.m_triangles.m_size < 0 )
        v88 = 0;
      hkArrayUtil::_reserve(
        &v248,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &newTriangles,
        v88,
        16);
      if ( v248.m_enum )
      {
        hkErrStream::hkErrStream(&v302, &v371, 512);
        hkOstream::operator<<(
          (hkOstream *)&v302.vfptr,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, &v371, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 306);
        v89 = &v302;
LABEL_168:
        hkOstream::~hkOstream((hkOstream *)&v89->vfptr);
        v90 = (hkVector4f *)v5->m_navMesh;
        if ( v90 )
        {
          v90[8] = (hkVector4f)aabbOut.m_quad;
          v90[9] = (hkVector4f)aabbOut.m_quad;
        }
        newTriangles.m_size = 0;
        if ( newTriangles.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            newTriangles.m_data,
            16 * newTriangles.m_capacityAndFlags);
        newTriangles.m_data = 0i64;
        newTriangles.m_capacityAndFlags = 2147483648;
        goto LABEL_185;
      }
    }
    hkGeometryUtils::removeDuplicateTrianglesFast(&v268, &dstGeom, &newTriangles);
    if ( v268.m_enum )
    {
      hkErrStream::hkErrStream(&v334, &v357, 512);
      hkOstream::operator<<(
        (hkOstream *)&v334.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v357, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 309);
      v89 = &v334;
      goto LABEL_168;
    }
    newTriangles.m_size = 0;
    if ( newTriangles.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        newTriangles.m_data,
        16 * newTriangles.m_capacityAndFlags);
    newTriangles.m_data = 0i64;
    newTriangles.m_capacityAndFlags = 2147483648;
    hkaiGeometryToEdgeGeometryConverter::hkaiGeometryToEdgeGeometryConverter(&v337);
    v91 = geomOut;
    v230 = 1;
    hkaiGeometryToEdgeGeometryConverter::convertGeometryToEdgeGeometry(
      &v337,
      &v270,
      &dstGeom,
      (hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char>)1,
      geomOut);
    if ( v270.m_enum )
    {
      hkErrStream::hkErrStream(&v304, &v379, 512);
      hkOstream::operator<<(
        (hkOstream *)&v304.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v379, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 315);
      hkOstream::~hkOstream((hkOstream *)&v304.vfptr);
      v92 = (hkVector4f *)v5->m_navMesh;
      if ( v92 )
      {
        v92[8] = (hkVector4f)aabbOut.m_quad;
        v92[9] = (hkVector4f)aabbOut.m_quad;
      }
      hkaiGeometryToEdgeGeometryConverter::~hkaiGeometryToEdgeGeometryConverter(&v337);
      goto LABEL_185;
    }
    hkaiGeometryToEdgeGeometryConverter::~hkaiGeometryToEdgeGeometryConverter(&v337);
    hkaiEdgeGeometry::set(geomInOut, &v260, v91);
    if ( v260.m_enum )
    {
      hkErrStream::hkErrStream(&v291, &v359, 512);
      hkOstream::operator<<(
        (hkOstream *)&v291.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v359, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 331);
      v93 = &v291;
      goto LABEL_183;
    }
    v94 = v4->m_defaultConstructionProperties.m_storage;
    hkaiNavMeshGenerationUtils::pruneEdgeGeometryByMaterialDeprecated(
      geomInOut,
      (hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v283,
      v4->m_defaultConstructionProperties.m_storage,
      1u);
    v95 = v94;
    v96 = geomOut;
    hkaiNavMeshGenerationUtils::pruneEdgeGeometryByMaterialDeprecated(
      geomOut,
      (hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v283,
      v95,
      2u);
    hkaiEdgeGeometryUtil::removeUnwalkableFaces(&v261, geomInOut, v4);
    if ( v261.m_enum )
    {
      hkErrStream::hkErrStream(&v306, &v373, 512);
      hkOstream::operator<<(
        (hkOstream *)&v306.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v373, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 341);
      v93 = &v306;
LABEL_183:
      hkOstream::~hkOstream((hkOstream *)&v93->vfptr);
      v97 = (hkVector4f *)v5->m_navMesh;
      if ( v97 )
      {
        v97[8] = (hkVector4f)aabbOut.m_quad;
        v97[9] = (hkVector4f)aabbOut.m_quad;
      }
      goto LABEL_185;
    }
    v102 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v103 = (_QWORD *)v102[1];
    if ( (unsigned __int64)v103 < v102[3] )
    {
      *v103 = "Et";
      v104 = __rdtsc();
      v105 = (signed __int64)(v103 + 2);
      *(_DWORD *)(v105 - 8) = v104;
      v102[1] = v105;
    }
    hkGeometry::~hkGeometry(&dstGeom);
    v106 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v107 = (_QWORD *)v106[1];
    if ( (unsigned __int64)v107 < v106[3] )
    {
      *v107 = "Ttextrude";
      v108 = __rdtsc();
      v109 = (signed __int64)(v107 + 2);
      *(_DWORD *)(v109 - 8) = v108;
      v106[1] = v109;
    }
    hkaiNavMeshGenerationUtils::_extrudeDeprecated(&v263, v4, v96, extrudeGeom);
    if ( v263.m_enum )
    {
      hkErrStream::hkErrStream(&v328, &v361, 512);
      hkOstream::operator<<(
        (hkOstream *)&v328.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v361, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 353);
      hkOstream::~hkOstream((hkOstream *)&v328.vfptr);
      v110 = (hkVector4f *)v5->m_navMesh;
      if ( v110 )
      {
        v110[8] = (hkVector4f)aabbOut.m_quad;
        v110[9] = (hkVector4f)aabbOut.m_quad;
      }
      v111 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v112 = (_QWORD *)v111[1];
      if ( (unsigned __int64)v112 < v111[3] )
      {
        *v112 = "Et";
        v113 = __rdtsc();
        v114 = (signed __int64)(v112 + 2);
        v13 = 2;
        *(_DWORD *)(v114 - 8) = v113;
        v111[1] = v114;
        goto LABEL_352;
      }
LABEL_205:
      v13 = 2;
      goto LABEL_352;
    }
    v115 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v116 = (_QWORD *)v115[1];
    if ( (unsigned __int64)v116 < v115[3] )
    {
      *v116 = "Et";
      v117 = __rdtsc();
      v118 = (signed __int64)(v116 + 2);
      *(_DWORD *)(v118 - 8) = v117;
      v115[1] = v118;
    }
    hkaiGeometryCarverExtractor::addCarvers(&v250, extrudeGeom, &carvers, v67);
    if ( v250.m_enum )
    {
      hkErrStream::hkErrStream(&v308, &v383, 512);
      hkOstream::operator<<(
        (hkOstream *)&v308.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v383, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 368);
      v119 = &v308;
      goto LABEL_203;
    }
    v250.m_enum = hkaiGeometryCarverExtractor::addCarvers(&v287, v96, &carvers, v67)->m_enum;
    if ( v250.m_enum )
    {
      hkErrStream::hkErrStream(&v322, &v343, 512);
      hkOstream::operator<<(
        (hkOstream *)&v322.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v343, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 371);
      v119 = &v322;
LABEL_203:
      hkOstream::~hkOstream((hkOstream *)&v119->vfptr);
      v120 = (hkVector4f *)v5->m_navMesh;
      if ( v120 )
      {
        v120[8] = (hkVector4f)aabbOut.m_quad;
        v120[9] = (hkVector4f)aabbOut.m_quad;
      }
      goto LABEL_205;
    }
    v121 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v122 = (_QWORD *)v121[1];
    if ( (unsigned __int64)v122 < v121[3] )
    {
      *v122 = "Ttsubtract";
      v123 = __rdtsc();
      v124 = (signed __int64)(v122 + 2);
      *(_DWORD *)(v124 - 8) = v123;
      v121[1] = v124;
    }
    v125 = geomInOut;
    hkaiNavMeshGenerationUtils::_subtractDeprecated((hkResult *)&srcGeom, v4, extrudeGeom, geomInOut, 0i64);
    if ( (_DWORD)srcGeom )
    {
      hkErrStream::hkErrStream(&v310, &v375, 512);
      hkOstream::operator<<(
        (hkOstream *)&v310.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v375, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 387);
      hkOstream::~hkOstream((hkOstream *)&v310.vfptr);
      v126 = (hkVector4f *)v5->m_navMesh;
      if ( v126 )
      {
        v126[8] = (hkVector4f)aabbOut.m_quad;
        v126[9] = (hkVector4f)aabbOut.m_quad;
      }
      v127 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v128 = (_QWORD *)v127[1];
      if ( (unsigned __int64)v128 < v127[3] )
      {
        *v128 = "Et";
        v129 = __rdtsc();
        v130 = (signed __int64)(v128 + 2);
        *(_DWORD *)(v130 - 8) = v129;
        v127[1] = v130;
      }
      v13 = 2;
      goto LABEL_352;
    }
    v131 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v132 = (_QWORD *)v131[1];
    if ( (unsigned __int64)v132 < v131[3] )
    {
      *v132 = "Et";
      v133 = __rdtsc();
      v134 = (signed __int64)(v132 + 2);
      *(_DWORD *)(v134 - 8) = v133;
      v131[1] = v134;
    }
    trisOut.m_capacityAndFlags = 2147483648;
    trisOut.m_data = 0i64;
    trisOut.m_size = 0;
    trisPerFaceOut.m_data = 0i64;
    trisPerFaceOut.m_size = 0;
    trisPerFaceOut.m_capacityAndFlags = 2147483648;
    triConnectivityOut.m_data = 0i64;
    triConnectivityOut.m_size = 0;
    triConnectivityOut.m_capacityAndFlags = 2147483648;
    materialsOut.m_data = 0i64;
    materialsOut.m_size = 0;
    materialsOut.m_capacityAndFlags = 2147483648;
    v135 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v136 = (_QWORD *)v135[1];
    v137 = v135;
    if ( (unsigned __int64)v136 < v135[3] )
    {
      *v136 = "Tttriangulate";
      v138 = __rdtsc();
      v139 = (signed __int64)(v136 + 2);
      *(_DWORD *)(v139 - 8) = v138;
      v137[1] = v139;
    }
    hkaiNavMeshGenerationUtils::_triangulate(
      &v278,
      v4,
      v125,
      &trisOut,
      &trisPerFaceOut,
      &triConnectivityOut,
      &materialsOut,
      0);
    if ( v278.m_enum )
    {
      hkErrStream::hkErrStream(&v332, &v365, 512);
      hkOstream::operator<<(
        (hkOstream *)&v332.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v365, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 410);
      hkOstream::~hkOstream((hkOstream *)&v332.vfptr);
      v140 = (hkVector4f *)v5->m_navMesh;
      if ( v140 )
      {
        v140[8] = (hkVector4f)aabbOut.m_quad;
        v140[9] = (hkVector4f)aabbOut.m_quad;
      }
      v141 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v142 = (_QWORD *)v141[1];
      if ( (unsigned __int64)v142 < v141[3] )
      {
        *v142 = "Et";
        v143 = __rdtsc();
        v144 = (signed __int64)(v142 + 2);
        *(_DWORD *)(v144 - 8) = v143;
        v141[1] = v144;
      }
      v13 = 2;
      goto LABEL_343;
    }
    v145 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v146 = (_QWORD *)v145[1];
    if ( (unsigned __int64)v146 < v145[3] )
    {
      *v146 = "Et";
      v147 = __rdtsc();
      v148 = (signed __int64)(v146 + 2);
      *(_DWORD *)(v148 - 8) = v147;
      v145[1] = v148;
    }
    hkaiEdgeGeometryRaycaster::hkaiEdgeGeometryRaycaster(&cuttingGeomRaycaster);
    if ( !raycaster )
    {
      hkaiEdgeGeometryRaycaster::init(&cuttingGeomRaycaster, &v285, v96);
      raycaster = &cuttingGeomRaycaster;
    }
    v149 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v150 = (_QWORD *)v149[1];
    if ( (unsigned __int64)v150 < v149[3] )
    {
      *v150 = "TtRemoveUnreachable";
      v151 = __rdtsc();
      v152 = (signed __int64)(v150 + 2);
      *(_DWORD *)(v152 - 8) = v151;
      v149[1] = v152;
    }
    hkaiNavMeshGenerationUtils::_removeDegenerateTriangles(
      &v264,
      &v125->m_vertices,
      &trisOut,
      &trisPerFaceOut,
      &triConnectivityOut,
      (hkArrayBase<int> *)&materialsOut.m_data,
      v4);
    if ( v264.m_enum )
    {
      hkErrStream::hkErrStream(&v312, &v344, 512);
      hkOstream::operator<<(
        (hkOstream *)&v312.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v344, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 429);
      v153 = &v312;
      goto LABEL_234;
    }
    hkaiNavMeshGenerationUtils::_removeUnreachableTriangles(
      &v265,
      v4,
      &cuttingGeomRaycaster,
      v125,
      (hkArrayBase<int> *)v96,
      &carverTree,
      &trisPerFaceOut,
      &trisOut,
      &triConnectivityOut,
      &trisPerFaceOut,
      (hkArrayBase<int> *)&materialsOut.m_data,
      0i64,
      0i64,
      0i64,
      0i64,
      0i64);
    if ( v265.m_enum )
    {
      hkErrStream::hkErrStream(&v324, &v346, 512);
      hkOstream::operator<<(
        (hkOstream *)&v324.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v346, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 434);
      v153 = &v324;
LABEL_234:
      hkOstream::~hkOstream((hkOstream *)&v153->vfptr);
      v154 = (hkVector4f *)v5->m_navMesh;
      if ( v154 )
      {
        v154[8] = (hkVector4f)aabbOut.m_quad;
        v154[9] = (hkVector4f)aabbOut.m_quad;
      }
LABEL_339:
      v210 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v211 = (_QWORD *)v210[1];
      if ( (unsigned __int64)v211 < v210[3] )
      {
        *v211 = "Et";
        v212 = __rdtsc();
        v213 = (signed __int64)(v211 + 2);
        *(_DWORD *)(v213 - 8) = v212;
        v210[1] = v213;
      }
LABEL_341:
      v13 = 2;
      goto LABEL_342;
    }
    raycaster->m_faceFlagMask.m_storage = 15;
    v155 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v156 = (_QWORD *)v155[1];
    if ( (unsigned __int64)v156 < v155[3] )
    {
      *v156 = "Et";
      v157 = __rdtsc();
      v158 = (signed __int64)(v156 + 2);
      *(_DWORD *)(v158 - 8) = v157;
      v155[1] = v158;
    }
    v159 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v160 = (_QWORD *)v159[1];
    if ( (unsigned __int64)v160 < v159[3] )
    {
      *v160 = "TtcreateNavMesh";
      v161 = __rdtsc();
      v162 = (signed __int64)(v160 + 2);
      *(_DWORD *)(v162 - 8) = v161;
      v159[1] = v162;
    }
    v163 = 2147483648;
    vertsIn.m_data = 0i64;
    vertsIn.m_size = 0;
    vertsIn.m_capacityAndFlags = 2147483648;
    v164 = v125->m_vertices.m_size;
    v165 = 0i64;
    if ( v164 <= 0 )
    {
      v252.m_enum = 0;
    }
    else
    {
      if ( v164 < 0 )
        v164 = 0;
      hkArrayUtil::_reserve(&v252, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &vertsIn, v164, 16);
      if ( v252.m_enum )
      {
        hkErrStream::hkErrStream(&v314, &v348, 512);
        hkOstream::operator<<(
          (hkOstream *)&v314.vfptr,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, &v348, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 445);
        v166 = &v314;
LABEL_334:
        hkOstream::~hkOstream((hkOstream *)&v166->vfptr);
        v209 = (hkVector4f *)v5->m_navMesh;
        if ( v209 )
        {
          v209[8] = (hkVector4f)aabbOut.m_quad;
          v209[9] = (hkVector4f)aabbOut.m_quad;
        }
        vertsIn.m_size = 0;
        if ( vertsIn.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            vertsIn.m_data,
            16 * vertsIn.m_capacityAndFlags);
        vertsIn.m_data = 0i64;
        vertsIn.m_capacityAndFlags = 2147483648;
        goto LABEL_339;
      }
      v163 = vertsIn.m_capacityAndFlags;
      v165 = vertsIn.m_data;
    }
    if ( (v163 & 0x3FFFFFFF) < v125->m_vertices.m_size )
    {
      if ( v163 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v165,
          16 * v163);
      v255 = 16 * v125->m_vertices.m_size;
      v165 = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                             (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                             &v255);
      vertsIn.m_data = v165;
      vertsIn.m_capacityAndFlags = v255 / 16;
    }
    vertsIn.m_size = v125->m_vertices.m_size;
    v167 = &v125->m_vertices.m_data->m_quad;
    v168 = vertsIn.m_size;
    if ( vertsIn.m_size > 0 )
    {
      do
      {
        v169.m_quad = *v167;
        ++v165;
        ++v167;
        v165[-1] = (hkVector4f)v169.m_quad;
        --v168;
      }
      while ( v168 );
    }
    hkaiNavMeshGenerationUtils::_createNavMesh(
      &v267,
      &vertsIn,
      &trisOut,
      &trisPerFaceOut,
      &triConnectivityOut,
      &materialsOut,
      &carverTree,
      v4,
      v21);
    if ( v267.m_enum )
    {
      hkErrStream::hkErrStream(&v292, &v350, 512);
      hkOstream::operator<<(
        (hkOstream *)&v292.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v350, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 449);
      v166 = &v292;
      goto LABEL_334;
    }
    if ( v21->m_edges.m_size >= 0x400000 || v21->m_faces.m_size >= 0x400000 )
    {
      hkErrStream::hkErrStream(&v329, &v386, 512);
      hkOstream::operator<<(
        (hkOstream *)&v329.vfptr,
        "Nav mesh generation created a mesh with too many edges or faces. Please try hkaiSplitGenerationUtils to process "
        "the mesh in pieces instead.");
      hkError::messageWarning(1349609975, &v386, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 450);
      v166 = &v329;
      goto LABEL_334;
    }
    v170 = 0;
    vertsIn.m_size = 0;
    if ( vertsIn.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        vertsIn.m_data,
        16 * vertsIn.m_capacityAndFlags);
    vertsIn.m_data = 0i64;
    vertsIn.m_capacityAndFlags = 2147483648;
    v171 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v172 = (_QWORD *)v171[1];
    if ( (unsigned __int64)v172 < v171[3] )
    {
      *v172 = "Et";
      v173 = __rdtsc();
      v174 = (signed __int64)(v172 + 2);
      *(_DWORD *)(v174 - 8) = v173;
      v171[1] = v174;
    }
    if ( !v21->m_faces.m_size || !v21->m_edges.m_size )
    {
      hkErrStream::hkErrStream(&v327, &v384, 512);
      hkOstream::operator<<(
        (hkOstream *)&v327.vfptr,
        "Empty nav mesh created. This could happen if all input was unwalkable, or if all walkable geometry was contained in carvers.");
      hkError::messageWarning(1541620706, &v384, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 455);
      v186 = &v327;
LABEL_331:
      hkOstream::~hkOstream((hkOstream *)&v186->vfptr);
      v208 = (hkVector4f *)v5->m_navMesh;
      if ( v208 )
      {
        v208[8] = (hkVector4f)aabbOut.m_quad;
        v208[9] = (hkVector4f)aabbOut.m_quad;
      }
      goto LABEL_342;
    }
    v175 = raycaster;
    hkaiEdgeGeometryRaycaster::setupForEdgeConnections(raycaster);
    hkaiNavMeshGenerationUtils::_connectEdges(&v269, v4, v21, v175, 0, 0i64, 0i64);
    if ( v269.m_enum )
    {
      hkErrStream::hkErrStream(&v295, &v352, 512);
      hkOstream::operator<<(
        (hkOstream *)&v295.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v352, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 479);
      v176 = &v295;
      goto LABEL_265;
    }
    if ( v21->m_edges.m_size >= 0x400000 || v21->m_faces.m_size >= 0x400000 )
    {
      hkErrStream::hkErrStream(&v325, &v382, 512);
      hkOstream::operator<<(
        (hkOstream *)&v325.vfptr,
        "Nav mesh generation created a mesh with too many edges or faces. Please try hkaiSplitGenerationUtils to process "
        "the mesh in pieces instead.");
      hkError::messageWarning(1349609975, &v382, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 480);
      v176 = &v325;
LABEL_265:
      hkOstream::~hkOstream((hkOstream *)&v176->vfptr);
      v177 = (hkVector4f *)v5->m_navMesh;
      if ( v177 )
      {
        v177[8] = (hkVector4f)aabbOut.m_quad;
        v177[9] = (hkVector4f)aabbOut.m_quad;
      }
      goto LABEL_341;
    }
    if ( v4->m_edgeConnectionIterations > 0 )
    {
      while ( 1 )
      {
        v178 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v179 = (_QWORD *)v178[1];
        if ( (unsigned __int64)v179 < v178[3] )
        {
          *v179 = "TtconnectEdges";
          v180 = __rdtsc();
          v181 = (signed __int64)(v179 + 2);
          *(_DWORD *)(v181 - 8) = v180;
          v178[1] = v181;
        }
        hkaiNavMeshGenerationUtils::_connectEdges(&v271, v4, v21, v175, ++v170, 0i64, 0i64);
        if ( v271.m_enum )
          break;
        if ( v21->m_edges.m_size >= 0x400000 || v21->m_faces.m_size >= 0x400000 )
        {
          hkErrStream::hkErrStream(&v297, &v354, 512);
          hkOstream::operator<<(
            (hkOstream *)&v297.vfptr,
            "Nav mesh generation created a mesh with too many edges or faces. Please try hkaiSplitGenerationUtils to proc"
            "ess the mesh in pieces instead.");
          hkError::messageWarning(1349609975, &v354, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 503);
          v153 = &v297;
          goto LABEL_234;
        }
        v182 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v183 = (_QWORD *)v182[1];
        if ( (unsigned __int64)v183 < v182[3] )
        {
          *v183 = "Et";
          v184 = __rdtsc();
          v185 = (signed __int64)(v183 + 2);
          *(_DWORD *)(v185 - 8) = v184;
          v182[1] = v185;
        }
        if ( v170 >= v4->m_edgeConnectionIterations )
          goto LABEL_278;
      }
      hkErrStream::hkErrStream(&v299, &v356, 512);
      hkOstream::operator<<(
        (hkOstream *)&v299.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v356, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 502);
      v153 = &v299;
      goto LABEL_234;
    }
LABEL_278:
    hkaiNavMeshUtils::validate(v21, 0);
    hkaiNavMeshUtils::compactVertices(&v273, v21, 0, 0);
    if ( v273.m_enum )
    {
      hkErrStream::hkErrStream(&v301, &v358, 512);
      hkOstream::operator<<(
        (hkOstream *)&v301.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v358, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 524);
      v176 = &v301;
      goto LABEL_265;
    }
    hkaiNavMeshGenerationUtils::_mergeVertices(&v275, v21, 0.00039999999);
    if ( v275.m_enum )
    {
      hkErrStream::hkErrStream(&v303, &v360, 512);
      hkOstream::operator<<(
        (hkOstream *)&v303.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v360, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 539);
      v176 = &v303;
      goto LABEL_265;
    }
    hkaiNavMeshGenerationUtils::_removeDegenerateFaces(&v279, v21);
    if ( v279.m_enum )
    {
      hkErrStream::hkErrStream(&v305, &v362, 512);
      hkOstream::operator<<(
        (hkOstream *)&v305.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v362, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 551);
      v176 = &v305;
      goto LABEL_265;
    }
    hkaiNavMeshUtils::validate(v21, 0);
    hkaiNavMeshGenerationUtils::_applyMinCharacterRadius(&v259, v21, v4, &cuttingGeomRaycaster, 0i64);
    if ( v259.m_enum )
    {
      hkErrStream::hkErrStream(&v307, &v364, 512);
      hkOstream::operator<<(
        (hkOstream *)&v307.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v364, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 571);
      v176 = &v307;
      goto LABEL_265;
    }
    if ( !v21->m_faces.m_size )
    {
      hkErrStream::hkErrStream(&v309, &v366, 512);
      hkOstream::operator<<((hkOstream *)&v309.vfptr, "Erosion removed all faces from the nav mesh.");
      hkError::messageWarning(1209185063, &v366, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 574);
      v186 = &v309;
      goto LABEL_331;
    }
    hkaiNavMeshGenerationUtils::_pruneRegions(&v280, v21, &v4->m_up, &v4->m_regionPruningSettings);
    if ( v280.m_enum )
    {
      hkErrStream::hkErrStream(&v311, &v368, 512);
      hkOstream::operator<<(
        (hkOstream *)&v311.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v368, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 591);
      v176 = &v311;
      goto LABEL_265;
    }
    hkaiNavMeshUtils::compactVertices(&v274, v21, 0, 0);
    if ( v274.m_enum )
    {
      hkErrStream::hkErrStream(&v313, &v370, 512);
      hkOstream::operator<<(
        (hkOstream *)&v313.vfptr,
        "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter"
        " in the User Guide.");
      hkError::messageWarning(1549811857, &v370, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 605);
      v176 = &v313;
      goto LABEL_265;
    }
    hkAabbUtil::calcAabb(v21->m_vertices.m_data, v21->m_vertices.m_size, &v21->m_aabb);
    v187 = _mm_shuffle_ps((__m128)LODWORD(v4->m_characterHeight), (__m128)LODWORD(v4->m_characterHeight), 0);
    v21->m_aabb.m_max.m_quad = _mm_add_ps(v21->m_aabb.m_max.m_quad, v187);
    v21->m_aabb.m_min.m_quad = _mm_sub_ps(v21->m_aabb.m_min.m_quad, v187);
    if ( v4->m_enableSimplification.m_bool )
    {
      hkaiNavMesh::setEdgeDataStriding(v21, &v238, 1, 0);
      if ( v238.m_enum )
      {
        hkErrStream::hkErrStream(&v315, &v372, 512);
        hkOstream::operator<<(
          (hkOstream *)&v315.vfptr,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, &v372, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 631);
        v176 = &v315;
        goto LABEL_265;
      }
      v238.m_enum = hkaiNavMesh::setEdgeDataStriding(v20, &v288, 1, 0)->m_enum;
      if ( v238.m_enum )
      {
        hkErrStream::hkErrStream(&v317, &v374, 512);
        hkOstream::operator<<(
          (hkOstream *)&v317.vfptr,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, &v374, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 633);
        v176 = &v317;
        goto LABEL_265;
      }
      hkaiNavMeshUtils::validate(v21, 0);
      v188 = v5->m_unsimplifiedNavMesh;
      if ( v188 )
      {
        hkaiNavMesh::copy(v188, &v277, v21);
        if ( v277.m_enum )
        {
          hkErrStream::hkErrStream(&v319, &v376, 512);
          hkOstream::operator<<(
            (hkOstream *)&v319.vfptr,
            "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation cha"
            "pter in the User Guide.");
          hkError::messageWarning(1549811857, &v376, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 643);
          v176 = &v319;
          goto LABEL_265;
        }
      }
      v189 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v190 = (_QWORD *)v189[1];
      if ( (unsigned __int64)v190 < v189[3] )
      {
        *v190 = "Ttsimplify";
        v191 = __rdtsc();
        v192 = (signed __int64)(v190 + 2);
        *(_DWORD *)(v192 - 8) = v191;
        v189[1] = v192;
      }
      v193 = hkaiNavMeshSimplificationUtils::_simplifyNavMesh(v4, v21, v20, &cuttingGeomRaycaster, 0i64);
      if ( v193 != 2 )
      {
        v20->m_faces.m_size = 0;
        v194 = v20->m_faces.m_capacityAndFlags;
        if ( v194 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v20->m_faces.m_data,
            16 * v194);
        v20->m_faces.m_data = 0i64;
        v20->m_faces.m_capacityAndFlags = 2147483648;
        v20->m_edges.m_size = 0;
        v195 = v20->m_edges.m_capacityAndFlags;
        if ( v195 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v20->m_edges.m_data,
            20 * (v195 & 0x3FFFFFFF));
        v20->m_edges.m_data = 0i64;
        v20->m_edges.m_capacityAndFlags = 2147483648;
        v20->m_vertices.m_size = 0;
        v196 = v20->m_vertices.m_capacityAndFlags;
        if ( v196 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v20->m_vertices.m_data,
            16 * v196);
        v20->m_vertices.m_data = 0i64;
        v20->m_vertices.m_capacityAndFlags = 2147483648;
        v20->m_faceData.m_size = 0;
        v197 = v20->m_faceData.m_capacityAndFlags;
        if ( v197 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v20->m_faceData.m_data,
            4 * v197);
        v20->m_faceData.m_data = 0i64;
        v20->m_faceData.m_capacityAndFlags = 2147483648;
        v20->m_edgeData.m_size = 0;
        v198 = v20->m_edgeData.m_capacityAndFlags;
        if ( v198 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v20->m_edgeData.m_data,
            4 * v198);
        v20->m_edgeData.m_data = 0i64;
        v20->m_edgeData.m_capacityAndFlags = 2147483648;
      }
      if ( v193 == 1 )
      {
        hkErrStream::hkErrStream(&v321, &v378, 512);
        hkOstream::operator<<(
          (hkOstream *)&v321.vfptr,
          "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapt"
          "er in the User Guide.");
        hkError::messageWarning(1549811857, &v378, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 662);
        hkOstream::~hkOstream((hkOstream *)&v321.vfptr);
        v199 = (hkVector4f *)v5->m_navMesh;
        if ( v199 )
        {
          v199[8] = (hkVector4f)aabbOut.m_quad;
          v199[9] = (hkVector4f)aabbOut.m_quad;
        }
        v13 = 2;
        goto LABEL_322;
      }
      if ( !v193 )
      {
        v13 = 0;
LABEL_322:
        v200 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v201 = (_QWORD *)v200[1];
        if ( (unsigned __int64)v201 < v200[3] )
        {
          *v201 = "Et";
          v202 = __rdtsc();
          v203 = (signed __int64)(v201 + 2);
          *(_DWORD *)(v203 - 8) = v202;
          v200[1] = v203;
        }
        goto LABEL_342;
      }
      v204 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v205 = (_QWORD *)v204[1];
      if ( (unsigned __int64)v205 < v204[3] )
      {
        *v205 = "Et";
        v206 = __rdtsc();
        v207 = (signed __int64)(v205 + 2);
        *(_DWORD *)(v207 - 8) = v206;
        v204[1] = v207;
      }
    }
    hkaiNavMesh::setEdgeDataStriding(v20, &v272, newStride, 0);
    if ( v272.m_enum == HK_SUCCESS )
    {
      hkaiNavMeshUtils::validate(v20, 1);
      v13 = 5;
LABEL_342:
      hkaiEdgeGeometryRaycaster::~hkaiEdgeGeometryRaycaster(&cuttingGeomRaycaster);
LABEL_343:
      materialsOut.m_size = 0;
      if ( materialsOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          materialsOut.m_data,
          4 * materialsOut.m_capacityAndFlags);
      materialsOut.m_data = 0i64;
      materialsOut.m_capacityAndFlags = 2147483648;
      triConnectivityOut.m_size = 0;
      if ( triConnectivityOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          triConnectivityOut.m_data,
          4 * triConnectivityOut.m_capacityAndFlags);
      triConnectivityOut.m_data = 0i64;
      triConnectivityOut.m_capacityAndFlags = 2147483648;
      trisPerFaceOut.m_size = 0;
      if ( trisPerFaceOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          trisPerFaceOut.m_data,
          4 * trisPerFaceOut.m_capacityAndFlags);
      trisPerFaceOut.m_data = 0i64;
      trisPerFaceOut.m_capacityAndFlags = 2147483648;
      trisOut.m_size = 0;
      if ( trisOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          trisOut.m_data,
          4 * trisOut.m_capacityAndFlags);
      trisOut.m_data = 0i64;
      trisOut.m_capacityAndFlags = 2147483648;
      goto LABEL_352;
    }
    hkErrStream::hkErrStream(&v323, &v380, 512);
    hkOstream::operator<<(
      (hkOstream *)&v323.vfptr,
      "Nav mesh generation ran out of memory. Please see the Troubleshooting section of the Nav Mesh Generation chapter i"
      "n the User Guide.");
    hkError::messageWarning(1549811857, &v380, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 676);
    v176 = &v323;
    goto LABEL_265;
  }
  hkErrStream::hkErrStream(&v330, &v349, 512);
  hkOstream::operator<<((hkOstream *)&v330.vfptr, "No triangles were contained in the input AABB.");
  hkError::messageWarning(1541620707, &v349, "NavMesh\\hkaiNavMeshGenerationUtils_deprecated.cpp", 242);
  hkOstream::~hkOstream((hkOstream *)&v330.vfptr);
  v69 = (hkVector4f *)v5->m_navMesh;
  if ( !v69 )
  {
LABEL_187:
    hkGeometry::~hkGeometry(&dstGeom);
    goto LABEL_352;
  }
  v69[8] = (hkVector4f)aabbOut.m_quad;
  v69[9] = (hkVector4f)aabbOut.m_quad;
  hkGeometry::~hkGeometry(&dstGeom);
LABEL_352:
  hkaiCarverTree::~hkaiCarverTree(&carverTree);
LABEL_353:
  v214 = carvers.m_size - 1;
  if ( carvers.m_size - 1 >= 0 )
  {
    v215 = &carvers.m_data[v214];
    do
    {
      hkRefPtr<hkaiVolume const>::`scalar deleting destructor'(v215);
      --v215;
      --v214;
    }
    while ( v214 >= 0 );
  }
  carvers.m_size = 0;
  if ( carvers.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      carvers.m_data,
      8 * carvers.m_capacityAndFlags);
  carvers.m_data = 0i64;
  carvers.m_capacityAndFlags = 2147483648;
  hkMap<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMap<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>,hkContainerHeapAllocator>((hkMap<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>,hkContainerHeapAllocator> *)&v283);
LABEL_359:
  v235 = 0;
  if ( v236 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      v236 & 0x3FFFFFFF);
  array = 0i64;
  v236 = 2147483648;
  hkaiNavMesh::~hkaiNavMesh(&v341);
  hkaiNavMesh::~hkaiNavMesh(&v342);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&v340);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&v338);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&v339);
LABEL_362:
  v216 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v217 = (_QWORD *)v216[1];
  v218 = v216;
  if ( (unsigned __int64)v217 < v216[3] )
  {
    *v217 = "Et";
    v219 = __rdtsc();
    v220 = (signed __int64)(v217 + 2);
    *(_DWORD *)(v220 - 8) = v219;
    v218[1] = v220;
  }
  return v13;
}kaiNavMeshGenerationUtils_deprecated.cpp", 242);
  hkOstream::~hkOstream((hkOstream *)&v330.vfptr);
  v69 = (hkVector4f *)v5->m_navMesh;
  if ( !v69 )
  {
LABEL_187:
    hkGeometry::~hkGeometry(&dstGeom);
    goto LABEL_352;
  }
  v69[8] = (hkVector4f)aabbOut.m_quad;
  v69[9] = (hkVector4f)aabbOut.m_quad;
  hkGeometry::~hkGeometry(&dstGeom);
LABEL_352:
  hkaiCarverTree::~hkaiCarverTree(&carverTree);
LABEL_353:
  v214 = carvers.m_size - 1;
  if ( carvers.m_size - 1 >= 0 )
  {
    v215 = &carvers.m_data[v214];
    do
    {
      hkRefPtr<hkaiVolume const>::`scalar deleting destructor'(v215);
      --v215;
      --v214;
    }
    while ( v214 >= 0 );
  }
  carvers.m_size = 0;
  if ( carvers.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      carvers.m_data,
      8 * carvers.m_capacityAndFlags);
  carvers.m_data = 0i64;
  carvers.m_capacityAndFlags = 2147483648;
  hkMap<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMap<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>,hkContainerHeapAllocator>((hkMap<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>,hkContainerHeapAllocator> *)&v283);
LABEL_359:
  v235 = 0;
  if ( v236 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      v236 & 0x3FFFFFFF);
  array = 0i64;
  v236 = 2147483648;
  hkaiNavMesh::~hkaiNavMesh(&v341);
  hkaiNavMesh::~hkaiNavMesh(&v342);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&v340);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&v338);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&v339);
LABEL_362:
  v216 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v217 = (_QWORD *)v216[1];
  v218 = v216;
  if ( 

// File Line: 691
// RVA: 0xBA9430
void __fastcall hkaiNavMeshGenerationUtils::setCarvedMaterialsDeprecated(hkGeometry *mesh, int carvedCuttingMaterial, int carvedMaterial, hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *materialMap, unsigned int defaultConstructionFlags, hkaiCarverTree *tree)
{
  __int64 v6; // rsi
  hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *v7; // r15
  unsigned __int64 v8; // rbp
  unsigned __int64 v9; // r14
  hkGeometry *v10; // r13
  __int64 v11; // rdi
  hkGeometry::Triangle *v12; // rbx
  int v13; // eax

  v6 = mesh->m_triangles.m_size;
  v7 = materialMap;
  v8 = (unsigned int)carvedMaterial;
  v9 = (unsigned int)carvedCuttingMaterial;
  v10 = mesh;
  if ( v6 > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = &v10->m_triangles.m_data[v11];
      if ( (unsigned int)hkaiCarverTree::carversContainTriangle(
                           tree,
                           &v10->m_vertices.m_data[v12->m_a],
                           &v10->m_vertices.m_data[v12->m_b],
                           &v10->m_vertices.m_data[v12->m_c]) )
      {
        v13 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v7->m_map.m_elem,
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
      --v6;
    }
    while ( v6 );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v7->m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v9,
    2ui64);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v7->m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v8,
    0i64);
}

// File Line: 737
// RVA: 0xBA9310
void __fastcall hkaiNavMeshGenerationUtils::pruneEdgeGeometryByMaterialDeprecated(hkaiEdgeGeometry *geomInOut, hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *materialMap, unsigned int defaultConstructionFlags, unsigned int material)
{
  unsigned int v4; // eax
  const unsigned int *v5; // r8
  signed int v6; // ebx
  unsigned int v7; // er14
  hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *v8; // r15
  hkaiEdgeGeometry *v9; // rsi
  signed __int64 v10; // rdi
  unsigned __int64 v11; // rbp
  int v12; // ecx
  unsigned int *array; // [rsp+20h] [rbp-28h]
  int numRemoveFaces; // [rsp+28h] [rbp-20h]
  int v15; // [rsp+2Ch] [rbp-1Ch]
  hkResult result; // [rsp+50h] [rbp+8h]

  v4 = defaultConstructionFlags;
  v5 = 0i64;
  v6 = 1;
  array = 0i64;
  numRemoveFaces = 0;
  v15 = 2147483648;
  v7 = material;
  v8 = materialMap;
  v9 = geomInOut;
  if ( geomInOut->m_faces.m_size > 1 )
  {
    v10 = 1i64;
    v11 = v4;
    do
    {
      if ( !((unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v8->m_map.m_elem,
                             v9->m_faces.m_data[v10].m_data,
                             v11) & v7) )
      {
        v12 = numRemoveFaces;
        if ( numRemoveFaces == (v15 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 4);
          v12 = numRemoveFaces;
        }
        array[v12] = v6;
        ++numRemoveFaces;
      }
      ++v6;
      ++v10;
    }
    while ( v6 < v9->m_faces.m_size );
    v5 = array;
  }
  hkaiEdgeGeometry::removeFaces(v9, &result, v5, numRemoveFaces);
  numRemoveFaces = 0;
  if ( v15 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v15);
}

// File Line: 759
// RVA: 0xBA9520
hkResult *__fastcall hkaiNavMeshGenerationUtils::_extrudeDeprecated(hkResult *result, hkaiNavMeshGenerationSettings *input, hkaiEdgeGeometry *geomIn, hkaiEdgeGeometry *geomOut)
{
  hkResult *v4; // rbx
  hkaiEdgeGeometry *v5; // rsi
  hkaiEdgeGeometry *v6; // rbp
  hkaiNavMeshGenerationSettings *v7; // rdi
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  signed __int64 v16; // rcx
  hkVector4f extrudeDirection; // [rsp+20h] [rbp-18h]

  v4 = result;
  v5 = geomOut;
  v6 = geomIn;
  v7 = input;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "Tt_extrude";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  extrudeDirection.m_quad = _mm_mul_ps(
                              _mm_sub_ps(
                                (__m128)0i64,
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(v7->m_characterHeight),
                                  (__m128)LODWORD(v7->m_characterHeight),
                                  0)),
                              v7->m_up.m_quad);
  hkaiGeometryExtrudeUtil::silhouetteExtrudeDeprecated(v4, v6, &extrudeDirection, v5);
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)v13[1];
  if ( (unsigned __int64)v14 < v13[3] )
  {
    *v14 = "Et";
    v15 = __rdtsc();
    v16 = (signed __int64)(v14 + 2);
    *(_DWORD *)(v16 - 8) = v15;
    v13[1] = v16;
  }
  return v4;
}

// File Line: 775
// RVA: 0xBA9600
hkResult *__fastcall hkaiNavMeshGenerationUtils::_subtractDeprecated(hkResult *result, hkaiNavMeshGenerationSettings *input, hkaiEdgeGeometry *cuttingGeom, hkaiEdgeGeometry *walkableGeomInOut, hkaiBooleanFaceFaceIntersects *intersects)
{
  hkResult *v5; // rbx
  hkaiEdgeGeometry *geomOut; // rdi
  hkaiEdgeGeometry *v7; // rsi
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  _QWORD *v13; // r9
  unsigned __int64 v14; // r8
  unsigned __int64 v15; // rax
  hkResult v17; // [rsp+40h] [rbp-C0h]
  hkResult v18; // [rsp+44h] [rbp-BCh]
  hkResult resulta; // [rsp+48h] [rbp-B8h]
  hkaiEdgeGeometry geomA; // [rsp+50h] [rbp-B0h]
  hkaiSelfIntersectBooleanFilter2 filter; // [rsp+A0h] [rbp-60h]
  hkaiBooleanOperation v22; // [rsp+100h] [rbp+0h]

  v5 = result;
  geomOut = walkableGeomInOut;
  v7 = cuttingGeom;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "Tt_subtract";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  hkaiEdgeGeometry::hkaiEdgeGeometry(&geomA);
  hkaiEdgeGeometry::set(&geomA, &resulta, geomOut);
  if ( resulta.m_enum )
  {
    v5->m_enum = 1;
  }
  else
  {
    hkaiBooleanOperation::hkaiBooleanOperation(&v22);
    hkaiSelfIntersectBooleanFilter2::hkaiSelfIntersectBooleanFilter2(&filter);
    hkaiSelfIntersectBooleanFilter2::setEdgeGeoms(&filter, &v18, &geomA, v7);
    if ( v18.m_enum )
    {
      v5->m_enum = 1;
    }
    else
    {
      hkaiBooleanOperation::subtract(&v22, &v17, &geomA, v7, geomOut, intersects, (hkaiBooleanFilter *)&filter.vfptr);
      if ( v17.m_enum )
        v5->m_enum = 1;
      else
        v5->m_enum = 0;
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
  return v5;
}

