// File Line: 41
// RVA: 0xE3CB0
void __fastcall UFG::HavokNavDaemon::HavokNavDaemon(UFG::HavokNavDaemon *this)
{
  UFG::HavokNavDaemon *v1; // rdi
  signed __int64 v2; // r13
  signed int *v3; // r15
  hkArray<hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator>,hkContainerHeapAllocator> *v4; // r12
  signed __int64 v5; // rbx
  char v6; // dl
  __int64 v7; // rax
  char v8; // cl
  int v9; // eax
  signed __int64 v10; // rsi
  int v11; // eax
  int v12; // er9
  int v13; // eax
  __int64 v14; // r14
  _DWORD *v15; // rdi
  int v16; // ecx
  signed __int64 v17; // rdx
  int v18; // eax
  __int64 v19; // r8
  char v20; // al
  char v21; // dl
  __int64 v22; // rax
  char v23; // cl
  int v24; // eax
  int v25; // eax
  int v26; // er9
  __int64 v27; // rax
  int v28; // ecx
  signed __int64 v29; // rax
  int v30; // edx
  __int64 v31; // r8
  signed __int64 v32; // rax
  char v33; // al
  char v34; // dl
  __int64 v35; // rax
  char v36; // cl
  int v37; // eax
  int v38; // eax
  int v39; // er9
  int v40; // eax
  __int64 v41; // r14
  int *v42; // rdi
  int v43; // ecx
  signed __int64 v44; // rdx
  int v45; // eax
  __int64 v46; // r8
  char v47; // al
  char v48; // dl
  __int64 v49; // rax
  char v50; // cl
  int v51; // eax
  int v52; // eax
  int v53; // er9
  int v54; // ecx
  signed __int64 v55; // rdx
  int v56; // eax
  __int64 v57; // r8
  char v58; // al
  char v59; // dl
  __int64 v60; // rax
  char v61; // cl
  int v62; // eax
  int v63; // eax
  int v64; // er9
  char v65; // al
  char v66; // dl
  __int64 v67; // rax
  char v68; // cl
  int v69; // eax
  int v70; // eax
  int v71; // er9
  char v72; // al
  char v73; // dl
  __int64 v74; // rax
  char v75; // cl
  int v76; // eax
  int v77; // eax
  int v78; // er9
  char v79; // al
  char v80; // dl
  __int64 v81; // rax
  char v82; // cl
  __int64 v83; // r14
  signed int *v84; // rdi
  int v85; // eax
  int v86; // eax
  int v87; // er9
  __int64 v88; // rcx
  signed __int64 v89; // r8
  int v90; // edx
  _DWORD *v91; // rdi
  int v92; // eax
  int v93; // eax
  int v94; // er9
  char v95; // al
  UFG::HavokNavDaemon *v96; // [rsp+A0h] [rbp+48h]
  hkResult result; // [rsp+A8h] [rbp+50h]
  hkaiNavMeshAStarCommand *v98; // [rsp+B0h] [rbp+58h]
  __int64 v99; // [rsp+B8h] [rbp+60h]

  v96 = this;
  v1 = this;
  UFG::Daemon::Daemon((UFG::Daemon *)&this->vfptr, 0, 0, 5u);
  v1->vfptr = (UFG::DaemonVtbl *)&UFG::HavokNavDaemon::`vftable';
  v1->m_PathRequests.p = 0i64;
  *(_QWORD *)&v1->m_PathRequests.size = 0i64;
  v2 = (signed __int64)&v1->m_outputs;
  *(_QWORD *)v2 = 0i64;
  *(_DWORD *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 12) = 2147483648;
  v3 = (signed int *)&v1->m_aStarOutputs;
  *(_QWORD *)v3 = 0i64;
  v3[2] = 0;
  v3[3] = 2147483648;
  v4 = &v1->m_smoothedPaths;
  v4->m_data = 0i64;
  v4->m_size = 0;
  v4->m_capacityAndFlags = 2147483648;
  v1->m_commands.m_data = 0i64;
  v1->m_commands.m_size = 0;
  v1->m_commands.m_capacityAndFlags = 2147483648;
  v1->m_goals.m_data = 0i64;
  v1->m_goals.m_size = 0;
  v1->m_goals.m_capacityAndFlags = 2147483648;
  v1->m_goalFaces.m_data = 0i64;
  v1->m_goalFaces.m_size = 0;
  v1->m_goalFaces.m_capacityAndFlags = 2147483648;
  v1->m_havokResults.m_data = 0i64;
  v1->m_havokResults.m_size = 0;
  v1->m_havokResults.m_capacityAndFlags = 2147483648;
  v1->m_maxIterationsStat = 0;
  UFG::Daemon::RegisterQueueableQueryType((UFG::Daemon *)&v1->vfptr, 0, &v1->m_PathRequests);
  UFG::Daemon::RegisterQueueableQueryType((UFG::Daemon *)&v1->vfptr, 1u, &v1->m_PathRequests);
  UFG::Daemon::RegisterQueueableQueryType((UFG::Daemon *)&v1->vfptr, 2u, &v1->m_PathRequests);
  UFG::Daemon::RegisterQueueableQueryType((UFG::Daemon *)&v1->vfptr, 3u, &v1->m_PathRequests);
  UFG::Daemon::RegisterQueueableQueryType((UFG::Daemon *)&v1->vfptr, 4u, &v1->m_PathRequests);
  v5 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v6 = ++*(_BYTE *)(v5 + 80);
  v7 = v6;
  *(_DWORD *)(v5 + 4 * v7) = 1;
  *(_QWORD *)(v5 + 8 * v7 + 16) = "AI::HavokNavDaemon::m_outputs";
  *(_QWORD *)(v5 + 8 * v7 + 48) = 0i64;
  v8 = *(_BYTE *)(v5 + 81);
  if ( v6 > v8 )
    v8 = v6;
  *(_BYTE *)(v5 + 81) = v8;
  v9 = v1->m_outputs.m_capacityAndFlags & 0x3FFFFFFF;
  v10 = 16i64;
  if ( v9 < 16 )
  {
    v11 = 2 * v9;
    v12 = 16;
    if ( v11 > 16 )
      v12 = v11;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_outputs,
      v12,
      16);
  }
  v13 = v1->m_outputs.m_size - 17;
  v14 = v13;
  if ( v13 >= 0 )
  {
    v15 = (_DWORD *)(16i64 * v13 + *(_QWORD *)v2 + 268i64);
    do
    {
      *(v15 - 1) = 0;
      if ( *v15 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v15 - 3),
          4 * *v15);
      *(_QWORD *)(v15 - 3) = 0i64;
      *v15 = 2147483648;
      v15 -= 4;
      --v14;
    }
    while ( v14 >= 0 );
  }
  v16 = 16 - *(_DWORD *)(v2 + 8);
  v17 = *(_QWORD *)v2 + 16i64 * *(signed int *)(v2 + 8);
  v98 = (hkaiNavMeshAStarCommand *)(*(_QWORD *)v2 + 16i64 * *(signed int *)(v2 + 8));
  v18 = 0;
  result.m_enum = 0;
  v19 = v16;
  if ( v16 > 0 )
  {
    do
    {
      v99 = v17;
      if ( v17 )
      {
        *(_QWORD *)v17 = 0i64;
        *(_DWORD *)(v17 + 8) = 0;
        *(_DWORD *)(v17 + 12) = 2147483648;
      }
      result.m_enum = ++v18;
      v17 += 16i64;
      --v19;
    }
    while ( v19 );
  }
  *(_DWORD *)(v2 + 8) = 16;
  v20 = *(_BYTE *)(v5 + 80);
  if ( v20 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v20 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  v21 = ++*(_BYTE *)(v5 + 80);
  v22 = v21;
  *(_DWORD *)(v5 + 4 * v22) = 1;
  *(_QWORD *)(v5 + 8 * v22 + 16) = "AI::HavokNavDaemon::m_aStarOutputs";
  *(_QWORD *)(v5 + 8 * v22 + 48) = 0i64;
  v23 = *(_BYTE *)(v5 + 81);
  if ( v21 > v23 )
    v23 = v21;
  *(_BYTE *)(v5 + 81) = v23;
  v24 = v3[3] & 0x3FFFFFFF;
  if ( v24 < 16 )
  {
    v25 = 2 * v24;
    v26 = 16;
    if ( v25 > 16 )
      v26 = v25;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v26, 16);
  }
  v27 = v3[2];
  v28 = 16 - v27;
  v29 = *(_QWORD *)v3 + 16 * v27;
  v98 = (hkaiNavMeshAStarCommand *)v29;
  v30 = 0;
  result.m_enum = 0;
  v31 = v28;
  if ( v28 > 0 )
  {
    v32 = v29 + 8;
    do
    {
      v99 = v32 - 8;
      if ( v32 != 8 )
      {
        *(_DWORD *)(v32 - 8) = 0;
        *(_DWORD *)(v32 - 4) = -1;
        *(_DWORD *)v32 = 2139095022;
        *(_WORD *)(v32 + 4) = 0;
      }
      result.m_enum = ++v30;
      v32 += 16i64;
      --v31;
    }
    while ( v31 );
  }
  v3[2] = 16;
  v33 = *(_BYTE *)(v5 + 80);
  if ( v33 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v33 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  v34 = ++*(_BYTE *)(v5 + 80);
  v35 = v34;
  *(_DWORD *)(v5 + 4 * v35) = 1;
  *(_QWORD *)(v5 + 8 * v35 + 16) = "AI::HavokNavDaemon::m_smoothedPaths";
  *(_QWORD *)(v5 + 8 * v35 + 48) = 0i64;
  v36 = *(_BYTE *)(v5 + 81);
  if ( v34 > v36 )
    v36 = v34;
  *(_BYTE *)(v5 + 81) = v36;
  v37 = v4->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v37 < 16 )
  {
    v38 = 2 * v37;
    v39 = 16;
    if ( v38 > 16 )
      v39 = v38;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v39, 16);
  }
  v40 = v4->m_size - 17;
  v41 = v40;
  if ( v40 >= 0 )
  {
    v42 = &v4->m_data[16].m_capacityAndFlags + 4 * v40;
    do
    {
      *(v42 - 1) = 0;
      if ( *v42 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v42 - 3),
          48 * (*v42 & 0x3FFFFFFF));
      *(_QWORD *)(v42 - 3) = 0i64;
      *v42 = 2147483648;
      v42 -= 4;
      --v41;
    }
    while ( v41 >= 0 );
  }
  v43 = 16 - v4->m_size;
  v44 = (signed __int64)&v4->m_data[v4->m_size];
  v98 = (hkaiNavMeshAStarCommand *)&v4->m_data[v4->m_size];
  v45 = 0;
  result.m_enum = 0;
  v46 = v43;
  if ( v43 > 0 )
  {
    do
    {
      v99 = v44;
      if ( v44 )
      {
        *(_QWORD *)v44 = 0i64;
        *(_DWORD *)(v44 + 8) = 0;
        *(_DWORD *)(v44 + 12) = 2147483648;
      }
      result.m_enum = ++v45;
      v44 += 16i64;
      --v46;
    }
    while ( v46 );
  }
  v4->m_size = 16;
  v47 = *(_BYTE *)(v5 + 80);
  if ( v47 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v47 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  v48 = ++*(_BYTE *)(v5 + 80);
  v49 = v48;
  *(_DWORD *)(v5 + 4 * v49) = 1;
  *(_QWORD *)(v5 + 8 * v49 + 16) = "AI::HavokNavDaemon::m_commands";
  *(_QWORD *)(v5 + 8 * v49 + 48) = 0i64;
  v50 = *(_BYTE *)(v5 + 81);
  if ( v48 > v50 )
    v50 = v48;
  *(_BYTE *)(v5 + 81) = v50;
  v51 = v96->m_commands.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v51 < 16 )
  {
    v52 = 2 * v51;
    v53 = 16;
    if ( v52 > 16 )
      v53 = v52;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v96->m_commands,
      v53,
      112);
  }
  v54 = 16 - v96->m_commands.m_size;
  v55 = (signed __int64)&v96->m_commands.m_data[v96->m_commands.m_size];
  v98 = &v96->m_commands.m_data[v96->m_commands.m_size];
  v56 = 0;
  result.m_enum = 0;
  v57 = v54;
  if ( v54 > 0 )
  {
    do
    {
      v99 = v55;
      if ( v55 )
        *(_QWORD *)(v55 + 64) = 0i64;
      result.m_enum = ++v56;
      v55 += 112i64;
      --v57;
    }
    while ( v57 );
  }
  v96->m_commands.m_size = 16;
  v58 = *(_BYTE *)(v5 + 80);
  if ( v58 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v58 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  v59 = ++*(_BYTE *)(v5 + 80);
  v60 = v59;
  *(_DWORD *)(v5 + 4 * v60) = 1;
  *(_QWORD *)(v5 + 8 * v60 + 16) = "AI::HavokNavDaemon::m_goals";
  *(_QWORD *)(v5 + 8 * v60 + 48) = 0i64;
  v61 = *(_BYTE *)(v5 + 81);
  if ( v59 > v61 )
    v61 = v59;
  *(_BYTE *)(v5 + 81) = v61;
  v62 = v96->m_goals.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v62 < 16 )
  {
    v63 = 2 * v62;
    v64 = 16;
    if ( v63 > 16 )
      v64 = v63;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v96->m_goals,
      v64,
      16);
  }
  v96->m_goals.m_size = 16;
  v65 = *(_BYTE *)(v5 + 80);
  if ( v65 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v65 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  v66 = ++*(_BYTE *)(v5 + 80);
  v67 = v66;
  *(_DWORD *)(v5 + 4 * v67) = 1;
  *(_QWORD *)(v5 + 8 * v67 + 16) = "AI::HavokNavDaemon::m_goalFaces";
  *(_QWORD *)(v5 + 8 * v67 + 48) = 0i64;
  v68 = *(_BYTE *)(v5 + 81);
  if ( v66 > v68 )
    v68 = v66;
  *(_BYTE *)(v5 + 81) = v68;
  v69 = v96->m_goalFaces.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v69 < 64 )
  {
    v70 = 2 * v69;
    v71 = 64;
    if ( v70 > 64 )
      v71 = v70;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v96->m_goalFaces,
      v71,
      4);
  }
  v96->m_goalFaces.m_size = 64;
  v72 = *(_BYTE *)(v5 + 80);
  if ( v72 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v72 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  v73 = ++*(_BYTE *)(v5 + 80);
  v74 = v73;
  *(_DWORD *)(v5 + 4 * v74) = 1;
  *(_QWORD *)(v5 + 8 * v74 + 16) = "AI::HavokNavDaemon::m_havokResults";
  *(_QWORD *)(v5 + 8 * v74 + 48) = 0i64;
  v75 = *(_BYTE *)(v5 + 81);
  if ( v73 > v75 )
    v75 = v73;
  *(_BYTE *)(v5 + 81) = v75;
  v76 = v96->m_havokResults.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v76 < 16 )
  {
    v77 = 2 * v76;
    v78 = 16;
    if ( v77 > 16 )
      v78 = v77;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v96->m_havokResults,
      v78,
      16);
  }
  v79 = *(_BYTE *)(v5 + 80);
  if ( v79 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v79 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  v80 = ++*(_BYTE *)(v5 + 80);
  v81 = v80;
  *(_DWORD *)(v5 + 4 * v81) = 1;
  *(_QWORD *)(v5 + 8 * v81 + 16) = "AI::HavokNavDaemon::smoothedPath";
  *(_QWORD *)(v5 + 8 * v81 + 48) = 0i64;
  v82 = *(_BYTE *)(v5 + 81);
  if ( v80 > v82 )
    v82 = v80;
  *(_BYTE *)(v5 + 81) = v82;
  v83 = 0i64;
  do
  {
    v84 = (signed int *)&v4->m_data[v83];
    v85 = v84[3] & 0x3FFFFFFF;
    if ( v85 >= 256 )
    {
      result.m_enum = 0;
    }
    else
    {
      v86 = 2 * v85;
      v87 = 256;
      if ( v86 > 256 )
        v87 = v86;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v84, v87, 48);
    }
    v88 = v84[2];
    v89 = *(_QWORD *)v84 + 48 * v88;
    v90 = 0;
    LODWORD(v98) = 0;
    if ( 256 - (signed int)v88 > 0 )
    {
      do
        LODWORD(v98) = ++v90;
      while ( v90 < 256 - v84[2] );
    }
    v84[2] = 256;
    v91 = (_DWORD *)(v83 * 16 + *(_QWORD *)v2);
    v92 = v91[3] & 0x3FFFFFFF;
    if ( v92 >= 256 )
    {
      LODWORD(v99) = 0;
    }
    else
    {
      v93 = 2 * v92;
      v94 = 256;
      if ( v93 > 256 )
        v94 = v93;
      hkArrayUtil::_reserve(
        (hkResult *)&v99,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v91,
        v94,
        4);
    }
    v91[2] = 256;
    ++v83;
    --v10;
  }
  while ( v10 );
  v95 = *(_BYTE *)(v5 + 80);
  if ( v95 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v95 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
}

// File Line: 103
// RVA: 0xE5A90
void __fastcall UFG::HavokNavDaemon::~HavokNavDaemon(UFG::HavokNavDaemon *this)
{
  UFG::HavokNavDaemon *v1; // rbx
  int v2; // er8
  int v3; // er8
  int v4; // er8
  int v5; // er8
  int v6; // eax
  __int64 v7; // rsi
  int *v8; // rdi
  int v9; // er8
  int v10; // er8
  int v11; // eax
  __int64 v12; // rsi
  int *v13; // rdi
  int v14; // er8
  UFG::DaemonQueryInput **v15; // rcx

  v1 = this;
  this->vfptr = (UFG::DaemonVtbl *)&UFG::HavokNavDaemon::`vftable';
  this->m_havokResults.m_size = 0;
  v2 = this->m_havokResults.m_capacityAndFlags;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_havokResults.m_data,
      16 * v2);
  v1->m_havokResults.m_data = 0i64;
  v1->m_havokResults.m_capacityAndFlags = 2147483648;
  v1->m_goalFaces.m_size = 0;
  v3 = v1->m_goalFaces.m_capacityAndFlags;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_goalFaces.m_data,
      4 * v3);
  v1->m_goalFaces.m_data = 0i64;
  v1->m_goalFaces.m_capacityAndFlags = 2147483648;
  v1->m_goals.m_size = 0;
  v4 = v1->m_goals.m_capacityAndFlags;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_goals.m_data,
      16 * v4);
  v1->m_goals.m_data = 0i64;
  v1->m_goals.m_capacityAndFlags = 2147483648;
  v1->m_commands.m_size = 0;
  v5 = v1->m_commands.m_capacityAndFlags;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_commands.m_data,
      112 * (v5 & 0x3FFFFFFF));
  v1->m_commands.m_data = 0i64;
  v1->m_commands.m_capacityAndFlags = 2147483648;
  v6 = v1->m_smoothedPaths.m_size - 1;
  v7 = v6;
  if ( v6 >= 0 )
  {
    v8 = &v1->m_smoothedPaths.m_data->m_capacityAndFlags + 4 * v6;
    do
    {
      *(v8 - 1) = 0;
      if ( *v8 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v8 - 3),
          48 * (*v8 & 0x3FFFFFFF));
      *(_QWORD *)(v8 - 3) = 0i64;
      *v8 = 2147483648;
      v8 -= 4;
      --v7;
    }
    while ( v7 >= 0 );
  }
  v1->m_smoothedPaths.m_size = 0;
  v9 = v1->m_smoothedPaths.m_capacityAndFlags;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_smoothedPaths.m_data,
      16 * v9);
  v1->m_smoothedPaths.m_data = 0i64;
  v1->m_smoothedPaths.m_capacityAndFlags = 2147483648;
  v1->m_aStarOutputs.m_size = 0;
  v10 = v1->m_aStarOutputs.m_capacityAndFlags;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_aStarOutputs.m_data,
      16 * v10);
  v1->m_aStarOutputs.m_data = 0i64;
  v1->m_aStarOutputs.m_capacityAndFlags = 2147483648;
  v11 = v1->m_outputs.m_size - 1;
  v12 = v11;
  if ( v11 >= 0 )
  {
    v13 = &v1->m_outputs.m_data->m_capacityAndFlags + 4 * v11;
    do
    {
      *(v13 - 1) = 0;
      if ( *v13 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v13 - 3),
          4 * *v13);
      *(_QWORD *)(v13 - 3) = 0i64;
      *v13 = 2147483648;
      v13 -= 4;
      --v12;
    }
    while ( v12 >= 0 );
  }
  v1->m_outputs.m_size = 0;
  v14 = v1->m_outputs.m_capacityAndFlags;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_outputs.m_data,
      16 * v14);
  v1->m_outputs.m_data = 0i64;
  v1->m_outputs.m_capacityAndFlags = 2147483648;
  v15 = v1->m_PathRequests.p;
  if ( v15 )
    operator delete[](v15);
  v1->m_PathRequests.p = 0i64;
  *(_QWORD *)&v1->m_PathRequests.size = 0i64;
  UFG::Daemon::~Daemon((UFG::Daemon *)&v1->vfptr);
}1->m_PathRequests.p = 0i64;
 

// File Line: 108
// RVA: 0xF1A60
void __fastcall UFG::HavokNavDaemon::SubmitImmediateQuery(UFG::HavokNavDaemon *this, UFG::DaemonQueryInput *input)
{
  unsigned int v2; // er8
  int v3; // er8
  int v4; // er8
  int v5; // er8

  v2 = input->m_internalType;
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v3 )
    {
      v4 = v3 - 1;
      if ( v4 )
      {
        v5 = v4 - 1;
        if ( v5 )
        {
          if ( v5 == 1 )
            ((void (*)(void))this->vfptr[2].__vecDelDtor)();
        }
        else
        {
          ((void (*)(void))this->vfptr[1].CompleteUpdate)();
        }
      }
      else
      {
        ((void (*)(void))this->vfptr[1].StartUpdate)();
      }
    }
    else
    {
      ((void (*)(void))this->vfptr[1].SubmitImmediateQuery)();
    }
  }
  else
  {
    ((void (*)(void))this->vfptr[1].__vecDelDtor)();
  }
}

// File Line: 144
// RVA: 0xF1A40
void __fastcall UFG::HavokNavDaemon::StartUpdate(UFG::HavokNavDaemon *this, float dt)
{
  UFG::HavokNavDaemon *v2; // rbx

  v2 = this;
  ((void (*)(void))this->vfptr[2].StartUpdate)();
  ((void (__fastcall *)(UFG::HavokNavDaemon *))v2->vfptr[2].CompleteUpdate)(v2);
}

// File Line: 161
// RVA: 0xE9590
void __fastcall UFG::HavokNavDaemon::CompleteUpdate(UFG::HavokNavDaemon *this, float dt)
{
  UFG::HavokNavDaemon *v2; // rbx

  v2 = this;
  ((void (*)(void))this->vfptr[3].__vecDelDtor)();
  ((void (__fastcall *)(UFG::HavokNavDaemon *))v2->vfptr[3].CancelQueueableQuery)(v2);
}

// File Line: 179
// RVA: 0xE94D0
void __fastcall UFG::HavokNavDaemon::CancelQueueableQuery(UFG::HavokNavDaemon *this, UFG::DaemonQueryInput *query)
{
  unsigned int v2; // er10
  unsigned int v3; // er8
  UFG::HavokNavDaemon *v4; // r9
  unsigned int v5; // ecx
  UFG::DaemonQueryInput **v6; // rax
  unsigned int v7; // ecx
  UFG::DaemonQueryOutput *v8; // rdx
  UFG::HavokNavDaemon::PathOutputEntry *v9; // rax
  int v10; // edx
  signed __int64 v11; // r10
  unsigned int v12; // eax

  v2 = this->m_PathRequests.size;
  v3 = 0;
  v4 = this;
  v5 = 0;
  if ( v2 )
  {
    v6 = v4->m_PathRequests.p;
    while ( *v6 != query )
    {
      ++v5;
      ++v6;
      if ( v5 >= v2 )
        goto LABEL_5;
    }
    v10 = (unsigned __int64)(8i64 * v5 >> 3) + 1;
    if ( v10 != v2 )
    {
      v11 = v10;
      do
      {
        ++v10;
        ++v11;
        v4->m_PathRequests.p[v11 - 2] = v4->m_PathRequests.p[v11 - 1];
      }
      while ( v10 != v4->m_PathRequests.size );
    }
    v12 = v4->m_PathRequests.size;
    if ( v12 > 1 )
      v4->m_PathRequests.size = v12 - 1;
    else
      v4->m_PathRequests.size = 0;
  }
  else
  {
LABEL_5:
    v7 = v4->m_havokResults.m_size;
    v8 = query->m_pOutput;
    if ( v7 )
    {
      v9 = v4->m_havokResults.m_data;
      while ( (UFG::DaemonQueryOutput *)v9->m_pUserOutput != v8 )
      {
        ++v3;
        ++v9;
        if ( v3 >= v7 )
          return;
      }
      v9->m_bValid = 0;
    }
  }
}

// File Line: 214
// RVA: 0xED680
char __fastcall UFG::HavokNavDaemon::GetUserEdgeOutlineForWaypoint(UFG::HavokNavDaemon *this, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *navPath, unsigned int currWpIndex, UFG::qVector3 *a)
{
  UFG::qVector3 *v4; // r13
  __int64 v5; // rbx
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *v6; // rsi
  UFG::NavManager *v7; // rdi
  hkaiNavMeshQueryMediator *v8; // r9
  signed __int64 v10; // r14
  char v11; // dl
  __int64 v12; // rax
  char v13; // cl
  hkVector4f *v14; // r10
  __int64 v15; // r8
  __m128 *v16; // rbx
  char v17; // al
  float v18; // xmm11_4
  unsigned int v19; // eax
  signed int v20; // eax
  signed __int64 v21; // rsi
  int v22; // edx
  float v23; // xmm9_4
  char v24; // r12
  __int64 v25; // rdi
  char v26; // dl
  __int64 v27; // rax
  char v28; // cl
  signed __int64 v29; // r14
  int v30; // er15
  signed int v31; // ecx
  signed __int64 v32; // rcx
  unsigned __int64 v33; // rax
  int v34; // ecx
  signed int *v35; // rdx
  __int64 v36; // rax
  signed int v37; // ecx
  __m128 *v38; // rax
  __m128 v39; // xmm5
  __m128 v40; // xmm6
  __m128 v41; // xmm7
  __m128 v42; // xmm4
  __m128 v43; // xmm3
  __int64 v44; // rax
  __m128 *v45; // rax
  __m128 v46; // xmm3
  __m128 v47; // xmm3
  float v48; // xmm3_4
  __m128 v49; // xmm2
  __m128 v50; // xmm2
  float v51; // xmm2_4
  __int64 v52; // rax
  unsigned __int64 v53; // rdi
  char v54; // al
  unsigned __int64 v55; // rax
  void *v56; // r13
  float *v57; // r14
  float *v58; // r15
  float v59; // xmm2_4
  float v60; // xmm4_4
  __m128 v61; // xmm3
  __m128 v62; // xmm1
  __m128 v63; // xmm13
  float v64; // xmm15_4
  float v65; // xmm10_4
  float v66; // xmm15_4
  int v67; // xmm14_4
  char *v68; // rbx
  unsigned int v69; // esi
  __m128 v70; // xmm6
  float v71; // xmm0_4
  __m128 v72; // xmm8
  __m128 v73; // xmm5
  float v74; // xmm1_4
  __m128 v75; // xmm7
  __m128 v76; // xmm3
  __m128 v77; // xmm4
  int v78; // er10
  unsigned int v79; // er12
  __int64 v80; // rcx
  unsigned int v81; // er9
  unsigned int v82; // er15
  unsigned int v83; // ecx
  __int64 v84; // r13
  unsigned int v85; // er14
  unsigned int v86; // edi
  unsigned __int64 v87; // rax
  char *v88; // r12
  void *v89; // rcx
  _DWORD *v90; // rdx
  char *v91; // r9
  __int64 v92; // r8
  _DWORD *v93; // rcx
  int v94; // er8
  __m128 *v95; // r15
  float v96; // eax
  signed __int64 v97; // rcx
  int v98; // edx
  __int64 v99; // r13
  __int64 v100; // r8
  __int64 v101; // rax
  signed __int64 v102; // r9
  int v103; // er10
  char v104; // dl
  __int64 v105; // rax
  char v106; // cl
  signed int v107; // ecx
  signed __int64 v108; // rcx
  unsigned __int64 v109; // rax
  int v110; // ecx
  signed int *v111; // rdx
  __int64 v112; // rax
  signed int v113; // ecx
  __m128 *v114; // rax
  __m128 v115; // xmm4
  __m128 v116; // xmm5
  __m128 v117; // xmm6
  __m128 v118; // xmm3
  __int64 v119; // rax
  __m128 *v120; // rax
  char v121; // al
  float v122; // xmm7_4
  float v123; // xmm8_4
  int v124; // xmm9_4
  float v125; // xmm10_4
  float v126; // xmm11_4
  int v127; // xmm12_4
  float v128; // xmm4_4
  __m128 v129; // xmm3
  __m128 v130; // xmm1
  float v131; // xmm1_4
  float v132; // xmm6_4
  unsigned int v133; // ecx
  unsigned int v134; // er14
  unsigned int v135; // edi
  unsigned __int64 v136; // rax
  char *v137; // rax
  unsigned __int64 v138; // r12
  int *v139; // rcx
  signed __int64 v140; // rdx
  __int64 v141; // rax
  int v142; // xmm1_4
  int v143; // xmm2_4
  int v144; // xmm1_4
  int v145; // xmm2_4
  signed __int64 v146; // rcx
  int v147; // eax
  bool v148; // sf
  unsigned __int8 v149; // of
  float v150; // xmm15_4
  char v151; // r12
  char v152; // r10
  __int64 v153; // r9
  float v154; // xmm1_4
  float v155; // xmm4_4
  float v156; // xmm11_4
  float v157; // xmm12_4
  float v158; // xmm7_4
  float v159; // xmm6_4
  float v160; // xmm10_4
  unsigned int v161; // xmm14_4
  float v162; // xmm8_4
  int v163; // xmm13_4
  float v164; // xmm5_4
  float v165; // xmm9_4
  float v166; // xmm2_4
  unsigned int v167; // xmm0_4
  int v168; // xmm0_4
  unsigned int v169; // xmm0_4
  __int64 v170; // rdx
  int v171; // xmm1_4
  int v172; // xmm2_4
  int v173; // xmm0_4
  int v174; // xmm1_4
  int v175; // xmm2_4
  float v176; // xmm2_4
  float v177; // xmm0_4
  float v178; // xmm1_4
  float *v179; // rax
  float v180; // xmm7_4
  float *v181; // rax
  unsigned int v182; // xmm4_4
  float v183; // xmm6_4
  float v184; // xmm3_4
  unsigned int v185; // xmm1_4
  unsigned int v186; // xmm0_4
  char v187; // [rsp+20h] [rbp-A8h]
  int v188; // [rsp+28h] [rbp-A0h]
  float v189; // [rsp+28h] [rbp-A0h]
  int v190; // [rsp+30h] [rbp-98h]
  float v191; // [rsp+30h] [rbp-98h]
  hkVector4f B2; // [rsp+40h] [rbp-88h]
  float v193; // [rsp+50h] [rbp-78h]
  __m128 *v194; // [rsp+58h] [rbp-70h]
  void *mem; // [rsp+60h] [rbp-68h]
  __int64 v196; // [rsp+68h] [rbp-60h]
  hkVector4f B; // [rsp+70h] [rbp-58h]
  __int64 v198; // [rsp+80h] [rbp-48h]
  __int64 v199; // [rsp+88h] [rbp-40h]
  __int64 v200; // [rsp+90h] [rbp-38h]
  hkLineSegmentUtil::ClosestPointLineSegResult result; // [rsp+98h] [rbp-30h]
  __m128 v202; // [rsp+A8h] [rbp-20h]
  hkaiNavMeshQueryMediator *v203; // [rsp+B8h] [rbp-10h]
  UFG::NavManager *v204; // [rsp+C0h] [rbp-8h]
  __int64 v205; // [rsp+C8h] [rbp+0h]
  int v206; // [rsp+D8h] [rbp+10h]
  __int64 v207; // [rsp+E0h] [rbp+18h]
  __int128 v208; // [rsp+E8h] [rbp+20h]
  __int64 v209; // [rsp+F8h] [rbp+30h]
  __m128 v210; // [rsp+108h] [rbp+40h]
  __m128 v211; // [rsp+118h] [rbp+50h]
  __int64 v212; // [rsp+128h] [rbp+60h]
  char *v213; // [rsp+138h] [rbp+70h]
  __int64 v214; // [rsp+140h] [rbp+78h]
  __int64 v215; // [rsp+230h] [rbp+168h]
  void *ptr; // [rsp+238h] [rbp+170h]
  float *v217; // [rsp+240h] [rbp+178h]
  float *v218; // [rsp+248h] [rbp+180h]

  v214 = -2i64;
  v4 = a;
  v5 = (signed int)currWpIndex;
  v6 = navPath;
  v7 = UFG::NavManager::ms_pInstance;
  v204 = UFG::NavManager::ms_pInstance;
  v8 = hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
  v203 = v8;
  if ( !v8 )
    return 0;
  v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  B2.m_quad.m128_u64[1] = v10;
  v11 = ++*(_BYTE *)(v10 + 80);
  v12 = v11;
  *(_DWORD *)(v10 + 4 * v12) = 1;
  *(_QWORD *)(v10 + 8 * v12 + 16) = "AI::HavokNavDaemon::GetUserEdgeOutlineForWaypoint";
  *(_QWORD *)(v10 + 8 * v12 + 48) = 0i64;
  v13 = *(_BYTE *)(v10 + 81);
  if ( v11 > v13 )
    v13 = v11;
  *(_BYTE *)(v10 + 81) = v13;
  v14 = &v6->m_data[v5].m_position;
  v194 = &v14->m_quad;
  v15 = v14[2].m_quad.m128_u16[1];
  v16 = *(__m128 **)(*((_QWORD *)v7[3].vfptr->LowHealthDefrag + 4) + 48i64 * v14[2].m_quad.m128_i32[1]);
  if ( v16[20].m128_i32[2] )
    v187 = *(_BYTE *)(v15 + v16[20].m128_u64[0]);
  else
    v187 = 0;
  v17 = *(_BYTE *)(v10 + 80);
  if ( v17 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v17 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  v18 = FLOAT_0_5;
  if ( v187 & 1 )
  {
    v206 = 0;
    v207 = 0i64;
    _mm_store_si128((__m128i *)&v208, (__m128i)0i64);
    v209 = 0i64;
    v210 = v14->m_quad;
    _mm_store_si128((__m128i *)&v211, (__m128i)_mm_shuffle_ps((__m128)0x3F000000u, (__m128)0x3F000000u, 0));
    v212 = 0i64;
    v19 = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, int *, __m128 *))v8->vfptr[1].__first_virtual_table_function__)(
            v8,
            &v206,
            &v202);
    LODWORD(v15) = v19 & 0x3FFFFF;
    v16 = *(__m128 **)(*((_QWORD *)v7[3].vfptr->LowHealthDefrag + 4) + 48i64 * (v19 >> 22));
    if ( !v16 )
      return 0;
    v14 = (hkVector4f *)v194;
  }
  v20 = v16[1].m128_i32[2];
  if ( (signed int)v15 < v20 )
  {
    if ( v16[14].m128_i32[2] )
      v22 = *(_DWORD *)(v16[14].m128_u64[0] + 4i64 * (signed int)v15);
    else
      v22 = v15;
    if ( v22 == -1 )
      v21 = v16[1].m128_u64[0] + 16i64 * (signed int)v15;
    else
      v21 = v16[15].m128_u64[0] + 16i64 * v22;
  }
  else
  {
    v21 = v16[17].m128_u64[0] + 16i64 * ((signed int)v15 - v20);
  }
  v23 = FLOAT_3_4028235e38;
  v24 = 0;
  v25 = *(signed int *)(v21 + 4);
  v193 = -6.8056469e38/*NaN*/;
  v26 = ++*(_BYTE *)(v10 + 80);
  v27 = v26;
  *(_DWORD *)(v10 + 4 * v27) = 1;
  *(_QWORD *)(v10 + 8 * v27 + 16) = "AI::HavokNavDaemon::GetUserEdgeOutlineForWaypoint_for";
  *(_QWORD *)(v10 + 8 * v27 + 48) = 0i64;
  v28 = *(_BYTE *)(v10 + 81);
  if ( v26 > v28 )
    v28 = v26;
  *(_BYTE *)(v10 + 81) = v28;
  if ( *(_WORD *)(v21 + 10) > 0 )
  {
    v29 = 4 * v25;
    v30 = -(signed int)v25;
    do
    {
      v31 = v16[2].m128_i32[2];
      if ( (signed int)v25 < v31 )
      {
        if ( v16[13].m128_i32[2] )
          v34 = *(_DWORD *)(v29 + v16[13].m128_u64[0]);
        else
          v34 = v25;
        if ( v34 == -1 )
        {
          v32 = 5i64 * (signed int)v25;
          v33 = v16[2].m128_u64[0];
        }
        else
        {
          v32 = 5i64 * v34;
          v33 = v16[16].m128_u64[0];
        }
      }
      else
      {
        v32 = 5i64 * ((signed int)v25 - v31);
        v33 = v16[18].m128_u64[0];
      }
      v35 = (signed int *)(v33 + 4 * v32);
      B.m_quad = 0i64;
      B2.m_quad = 0i64;
      v36 = *v35;
      v37 = v16[3].m128_i32[2];
      if ( (signed int)v36 >= v37 )
        v38 = (__m128 *)(v16[19].m128_u64[0] + 16i64 * ((signed int)v36 - v37));
      else
        v38 = (__m128 *)(v16[3].m128_u64[0] + 16 * v36);
      v39 = v16[7];
      v40 = v16[8];
      v41 = v16[9];
      v42 = v16[10];
      v43 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v38, *v38, 170), v41),
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v38, *v38, 85), v40),
                  _mm_mul_ps(_mm_shuffle_ps(*v38, *v38, 0), v39))),
              v42);
      B.m_quad = v43;
      v44 = v35[1];
      if ( (signed int)v44 >= v37 )
        v45 = (__m128 *)(v16[19].m128_u64[0] + 16i64 * ((signed int)v44 - v37));
      else
        v45 = (__m128 *)(v16[3].m128_u64[0] + 16 * v44);
      B2.m_quad = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(*v45, *v45, 170), v41),
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(*v45, *v45, 85), v40),
                        _mm_mul_ps(_mm_shuffle_ps(*v45, *v45, 0), v39))),
                    v42);
      v46 = _mm_sub_ps(v43, B2.m_quad);
      v47 = _mm_mul_ps(v46, v46);
      v48 = COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 170))
          + (float)(COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 0)));
      if ( v48 < 0.0 )
        LODWORD(v48) ^= _xmm[0];
      if ( v48 >= 0.001 )
      {
        hkLineSegmentUtil::closestPointLineSeg(v14, &B, &B2, &result);
        v14 = (hkVector4f *)v194;
        v49 = _mm_sub_ps(result.m_pointOnEdge.m_quad, *v194);
        v50 = _mm_mul_ps(v49, v49);
        v51 = COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 170))
            + (float)(COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 0)));
        if ( v51 < 0.010000001 && v51 < v23 )
        {
          *(hkVector4f *)&v4->x = (hkVector4f)B.m_quad;
          v52 = (__int64)v218;
          *v218 = B2.m_quad.m128_f32[0];
          *(_QWORD *)(v52 + 4) = *(unsigned __int64 *)((char *)B2.m_quad.m128_u64 + 4);
          v193 = *(float *)&v25;
          v23 = v51;
          v24 = 1;
        }
      }
      LODWORD(v25) = v25 + 1;
      v29 += 4i64;
    }
    while ( v30 + (signed int)v25 < *(signed __int16 *)(v21 + 10) );
    v18 = FLOAT_0_5;
  }
  v53 = B2.m_quad.m128_u64[1];
  v54 = *(_BYTE *)(B2.m_quad.m128_u64[1] + 80);
  if ( v54 > 0 )
  {
    *(_BYTE *)(B2.m_quad.m128_u64[1] + 80) = v54 - 1;
  }
  else
  {
    *(_BYTE *)(B2.m_quad.m128_u64[1] + 80) = 0;
    *(_DWORD *)v53 = 3;
    *(_QWORD *)(v53 + 16) = 0i64;
    *(_QWORD *)(v53 + 48) = 0i64;
  }
  if ( !v24 )
    return 0;
  B2.m_quad = (__m128)0i64;
  v199 = 16i64;
  UFG::qArray<UFG::HavokNavDaemon::MatchedEdgeCandidate,0>::Reallocate(
    (UFG::qArray<UFG::HavokNavDaemon::MatchedEdgeCandidate,0> *)&B2,
    0x10u,
    "qArray.Reallocate(Constructor)");
  mem = 0i64;
  v194 = 0i64;
  v55 = 64i64;
  if ( !is_mul_ok(0x10ui64, 4ui64) )
    v55 = -1i64;
  v56 = UFG::qMalloc(v55, "qArray.Reallocate(Constructor)", 0i64);
  mem = v56;
  HIDWORD(v194) = 16;
  v57 = v217;
  v58 = v218;
  v59 = v217[2] - v218[2];
  v61 = (__m128)*((unsigned int *)v217 + 1);
  v60 = (float)(v59 * UFG::qVector3::msDirUp.x) - (float)((float)(*v217 - *v218) * UFG::qVector3::msDirUp.z);
  v61.m128_f32[0] = (float)((float)(v61.m128_f32[0] - v218[1]) * UFG::qVector3::msDirUp.z)
                  - (float)(v59 * UFG::qVector3::msDirUp.y);
  v62 = v61;
  v62.m128_f32[0] = (float)(v61.m128_f32[0] * v61.m128_f32[0]) + (float)(v60 * v60);
  v63 = (__m128)(unsigned int)FLOAT_1_0;
  if ( v62.m128_f32[0] == 0.0 )
    v64 = 0.0;
  else
    v64 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v62));
  v65 = v64 * v60;
  v193 = v64 * v60;
  v66 = v64 * v61.m128_f32[0];
  B.m_quad.m128_f32[0] = v66;
  v67 = _xmm;
  v68 = (char *)B2.m_quad.m128_u64[1];
  v69 = B2.m_quad.m128_i32[0];
  do
  {
    v70 = (__m128)*((unsigned int *)v57 + 2);
    v71 = v58[2];
    if ( v70.m128_f32[0] >= v71 )
      v72 = (__m128)*((unsigned int *)v58 + 2);
    else
      v72 = (__m128)*((unsigned int *)v57 + 2);
    v73 = (__m128)*((unsigned int *)v57 + 1);
    v74 = v58[1];
    if ( v73.m128_f32[0] >= v74 )
      v75 = (__m128)*((unsigned int *)v58 + 1);
    else
      v75 = (__m128)*((unsigned int *)v57 + 1);
    v76 = (__m128)*(unsigned int *)v57;
    if ( v76.m128_f32[0] >= *v58 )
      v77 = (__m128)*(unsigned int *)v58;
    else
      v77 = (__m128)*(unsigned int *)v57;
    v72.m128_f32[0] = v72.m128_f32[0] - v18;
    v75.m128_f32[0] = v75.m128_f32[0] - v18;
    v77.m128_f32[0] = v77.m128_f32[0] - v18;
    if ( v70.m128_f32[0] <= v71 )
      v70 = (__m128)*((unsigned int *)v58 + 2);
    if ( v73.m128_f32[0] <= v74 )
      v73 = (__m128)*((unsigned int *)v58 + 1);
    if ( v76.m128_f32[0] <= *v58 )
      v76 = (__m128)*(unsigned int *)v58;
    v70.m128_f32[0] = v70.m128_f32[0] + v18;
    v73.m128_f32[0] = v73.m128_f32[0] + v18;
    v76.m128_f32[0] = v76.m128_f32[0] + v18;
    B.m_quad.m128_u64[0] = 0i64;
    B.m_quad.m128_u64[1] = 0x8000000000000000i64;
    v206 = 0;
    v207 = 0i64;
    _mm_store_si128((__m128i *)&v208, (__m128i)0i64);
    v209 = 0i64;
    v210 = _mm_unpacklo_ps(_mm_unpacklo_ps(v77, v72), _mm_unpacklo_ps(v75, v63));
    v211 = _mm_unpacklo_ps(_mm_unpacklo_ps(v76, v70), _mm_unpacklo_ps(v73, v63));
    ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, hkVector4f *))v203->vfptr[3].__first_virtual_table_function__)(
      v203,
      &v206,
      &B);
    v78 = 0;
    v190 = 0;
    v79 = _S8_2;
    if ( B.m_quad.m128_i32[2] <= 0 )
      goto LABEL_164;
    v80 = 0i64;
    v200 = 0i64;
    v81 = (unsigned int)v194;
    do
    {
      v82 = *(_DWORD *)(v80 + B.m_quad.m128_u64[0]);
      v83 = 0;
      if ( v81 )
      {
        while ( v82 != *((_DWORD *)v56 + v83) )
        {
          if ( ++v83 >= v81 )
            goto LABEL_80;
        }
        if ( v83 != -1 )
          goto LABEL_162;
      }
LABEL_80:
      v84 = v81;
      v85 = v81 + 1;
      if ( v81 + 1 > (unsigned int)v199 )
      {
        v86 = 1;
        if ( (_DWORD)v199 )
          v86 = 2 * v199;
        for ( ; v86 < v85; v86 *= 2 )
          ;
        if ( v86 <= 4 )
          v86 = 4;
        if ( v86 - v85 > 0x10000 )
          v86 = v81 + 65537;
        if ( v86 != v81 )
        {
          v87 = 4i64 * v86;
          if ( !is_mul_ok(v86, 4ui64) )
            v87 = -1i64;
          v88 = UFG::qMalloc(v87, "qArray.Add", 0i64);
          v89 = mem;
          if ( mem )
          {
            if ( (_DWORD)v194 )
            {
              v90 = v88;
              v91 = (char *)((_BYTE *)mem - v88);
              v92 = (unsigned int)v194;
              do
              {
                *v90 = *(_DWORD *)((char *)v90 + (_QWORD)v91);
                ++v90;
                --v92;
              }
              while ( v92 );
            }
            operator delete[](v89);
          }
          v93 = v88;
          mem = v88;
          v199 = v86;
          HIDWORD(v194) = v86;
          v79 = _S8_2;
          v53 = B2.m_quad.m128_u64[1];
          v78 = v190;
          goto LABEL_100;
        }
        v53 = B2.m_quad.m128_u64[1];
      }
      v93 = mem;
LABEL_100:
      v81 = v85;
      LODWORD(v194) = v85;
      v93[v84] = v82;
      v94 = v82 & 0x3FFFFF;
      v95 = *(__m128 **)(*((_QWORD *)v204[3].vfptr->LowHealthDefrag + 4) + 48i64 * (v82 >> 22));
      v96 = v95[1].m128_f32[2];
      if ( v94 < SLODWORD(v96) )
      {
        if ( v95[14].m128_i32[2] )
          v98 = *(_DWORD *)(v95[14].m128_u64[0] + 4i64 * v94);
        else
          v98 = v94;
        if ( v98 == -1 )
          v97 = v95[1].m128_u64[0] + 16i64 * v94;
        else
          v97 = v95[15].m128_u64[0] + 16i64 * v98;
      }
      else
      {
        v97 = v95[17].m128_u64[0] + 16i64 * (v94 - LODWORD(v96));
      }
      v196 = v97;
      v99 = *(signed int *)(v97 + 4);
      v100 = *(signed int *)(v97 + 4);
      v198 = *(signed int *)(v97 + 4);
      v101 = SLODWORD(v193);
      v205 = SLODWORD(v193);
      if ( *(_WORD *)(v97 + 10) > 0 )
      {
        v102 = 4 * v99;
        B.m_quad.m128_u64[1] = 4 * v99;
        v103 = -(signed int)v99;
        v188 = -(signed int)v99;
        while ( 1 )
        {
          if ( v101 == v100 )
            goto LABEL_157;
          v104 = ++*(_BYTE *)(v53 + 80);
          v105 = v104;
          *(_DWORD *)(v53 + 4 * v105) = 1;
          *(_QWORD *)(v53 + 8 * v105 + 16) = "AI::HavokNavDaemon::GetUserEdgeOutlineForWaypoint_for";
          *(_QWORD *)(v53 + 8 * v105 + 48) = 0i64;
          v106 = *(_BYTE *)(v53 + 81);
          if ( v104 > v106 )
            v106 = v104;
          *(_BYTE *)(v53 + 81) = v106;
          v107 = v95[2].m128_i32[2];
          if ( (signed int)v99 < v107 )
          {
            if ( v95[13].m128_i32[2] )
              v110 = *(_DWORD *)(v102 + v95[13].m128_u64[0]);
            else
              v110 = v99;
            if ( v110 == -1 )
            {
              v108 = 5i64 * (signed int)v99;
              v109 = v95[2].m128_u64[0];
            }
            else
            {
              v108 = 5i64 * v110;
              v109 = v95[16].m128_u64[0];
            }
          }
          else
          {
            v108 = 5i64 * ((signed int)v99 - v107);
            v109 = v95[18].m128_u64[0];
          }
          v111 = (signed int *)(v109 + 4 * v108);
          v112 = *v111;
          v113 = v95[3].m128_i32[2];
          if ( (signed int)v112 >= v113 )
            v114 = (__m128 *)(v95[19].m128_u64[0] + 16i64 * ((signed int)v112 - v113));
          else
            v114 = (__m128 *)(v95[3].m128_u64[0] + 16 * v112);
          v115 = v95[7];
          v116 = v95[8];
          v117 = v95[9];
          v118 = v95[10];
          v202 = _mm_add_ps(
                   v95[10],
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(*v114, *v114, 170), v117),
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(*v114, *v114, 85), v116),
                       _mm_mul_ps(_mm_shuffle_ps(*v114, *v114, 0), v115))));
          v119 = v111[1];
          if ( (signed int)v119 >= v113 )
            v120 = (__m128 *)(v95[19].m128_u64[0] + 16i64 * ((signed int)v119 - v113));
          else
            v120 = (__m128 *)(v95[3].m128_u64[0] + 16 * v119);
          result.m_pointOnEdge.m_quad = _mm_add_ps(
                                          v118,
                                          _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps(*v120, *v120, 170), v117),
                                            _mm_add_ps(
                                              _mm_mul_ps(_mm_shuffle_ps(*v120, *v120, 85), v116),
                                              _mm_mul_ps(_mm_shuffle_ps(*v120, *v120, 0), v115))));
          v121 = *(_BYTE *)(v53 + 80);
          if ( v121 > 0 )
          {
            *(_BYTE *)(v53 + 80) = v121 - 1;
          }
          else
          {
            *(_BYTE *)(v53 + 80) = 0;
            *(_DWORD *)v53 = 3;
            *(_QWORD *)(v53 + 16) = 0i64;
            *(_QWORD *)(v53 + 48) = 0i64;
          }
          v122 = v202.m128_f32[2];
          v57 = v217;
          v123 = v202.m128_f32[1];
          v124 = v202.m128_i32[0];
          if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v202.m128_f32[2] - v217[2]) & v67) >= 0.30000001
            || COERCE_FLOAT(COERCE_UNSIGNED_INT(
                              (float)(v65 * (float)(v202.m128_f32[1] - v217[1]))
                            + (float)((float)(v202.m128_f32[0] - *v217) * v66)) & v67) >= 0.02 )
          {
            goto LABEL_158;
          }
          v125 = result.m_pointOnEdge.m_quad.m128_f32[2];
          v129 = (__m128)v202.m128_u32[1];
          v126 = result.m_pointOnEdge.m_quad.m128_f32[1];
          v127 = result.m_pointOnEdge.m_quad.m128_i32[0];
          v128 = (float)((float)(v202.m128_f32[2] - result.m_pointOnEdge.m_quad.m128_f32[2]) * UFG::qVector3::msDirUp.x)
               - (float)((float)(v202.m128_f32[0] - result.m_pointOnEdge.m_quad.m128_f32[0]) * UFG::qVector3::msDirUp.z);
          v129.m128_f32[0] = (float)((float)(v202.m128_f32[1] - result.m_pointOnEdge.m_quad.m128_f32[1])
                                   * UFG::qVector3::msDirUp.z)
                           - (float)((float)(v202.m128_f32[2] - result.m_pointOnEdge.m_quad.m128_f32[2])
                                   * UFG::qVector3::msDirUp.y);
          v130 = v129;
          v130.m128_f32[0] = (float)(v129.m128_f32[0] * v129.m128_f32[0]) + (float)(v128 * v128);
          if ( v130.m128_f32[0] == 0.0 )
            v131 = 0.0;
          else
            v131 = v63.m128_f32[0] / COERCE_FLOAT(_mm_sqrt_ps(v130));
          v132 = (float)((float)(v131 * v128) * v193) + (float)((float)(v129.m128_f32[0] * v131) * v66);
          if ( !(v79 & 1) )
          {
            v79 |= 1u;
            _S8_2 = v79;
            kfMaxDotDiff = v63.m128_f32[0] - cosf(0.034906585);
            v100 = v198;
            v102 = B.m_quad.m128_i64[1];
            v103 = v188;
          }
          if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v63.m128_f32[0] - v132) & v67) < kfMaxDotDiff )
            break;
          v65 = v193;
LABEL_158:
          LODWORD(v99) = v99 + 1;
          v102 += 4i64;
          B.m_quad.m128_u64[1] = v102;
          v198 = ++v100;
          v147 = *(signed __int16 *)(v196 + 10);
          v149 = __OFSUB__(v103 + v99, v147);
          v148 = v103 + (signed int)v99 - v147 < 0;
          v101 = v205;
          if ( !(v148 ^ v149) )
          {
            v81 = (unsigned int)v194;
            v78 = v190;
            goto LABEL_161;
          }
        }
        v133 = v69;
        LODWORD(mem) = v69;
        v134 = v69 + 1;
        if ( v69 + 1 > B2.m_quad.m128_i32[1] )
        {
          v135 = 1;
          if ( B2.m_quad.m128_i32[1] )
            v135 = 2 * B2.m_quad.m128_i32[1];
          for ( ; v135 < v134; v135 *= 2 )
            ;
          if ( v135 - v134 > 0x10000 )
            v135 = v69 + 65537;
          if ( v135 != v69 )
          {
            v136 = 24i64 * v135;
            if ( !is_mul_ok(v135, 0x18ui64) )
              v136 = -1i64;
            v137 = UFG::qMalloc(v136, "qArray.Add", 0i64);
            v138 = (unsigned __int64)v137;
            v213 = v137;
            if ( v68 )
            {
              if ( v69 )
              {
                v139 = (int *)(v68 + 20);
                v140 = v137 - v68;
                v141 = v69;
                do
                {
                  v142 = *(v139 - 4);
                  v143 = *(v139 - 3);
                  *(int *)((char *)v139 + v140 - 20) = *(v139 - 5);
                  *(int *)((char *)v139 + v140 - 16) = v142;
                  *(int *)((char *)v139 + v140 - 12) = v143;
                  v144 = *(v139 - 1);
                  v145 = *v139;
                  *(int *)((char *)v139 + v140 - 8) = *(v139 - 2);
                  *(int *)((char *)v139 + v140 - 4) = v144;
                  *(int *)((char *)v139 + v140) = v145;
                  v139 += 6;
                  --v141;
                }
                while ( v141 );
              }
              operator delete[](v68);
            }
            v68 = (char *)v138;
            B2.m_quad.m128_u64[1] = v138;
            B2.m_quad.m128_i32[1] = v135;
            v79 = _S8_2;
            v133 = (unsigned int)mem;
          }
          v53 = B2.m_quad.m128_u64[1];
        }
        ++v69;
        B2.m_quad.m128_i32[0] = v134;
        v146 = 3i64 * v133;
        *(_DWORD *)&v68[8 * v146] = v124;
        *(float *)&v68[8 * v146 + 4] = v123;
        *(float *)&v68[8 * v146 + 8] = v122;
        *(_DWORD *)&v68[8 * v146 + 12] = v127;
        *(float *)&v68[8 * v146 + 16] = v126;
        *(float *)&v68[8 * v146 + 20] = v125;
        v65 = v193;
        v100 = v198;
        v102 = B.m_quad.m128_i64[1];
        v103 = v188;
LABEL_157:
        v57 = v217;
        goto LABEL_158;
      }
      v57 = v217;
LABEL_161:
      v56 = mem;
LABEL_162:
      v190 = ++v78;
      v80 = v200 + 4;
      v200 += 4i64;
    }
    while ( v78 < B.m_quad.m128_i32[2] );
    v58 = v218;
LABEL_164:
    if ( v79 & 2 )
    {
      v150 = kfMaxDistanceSquared;
    }
    else
    {
      _S8_2 = v79 | 2;
      v150 = FLOAT_0_00039999999;
      kfMaxDistanceSquared = FLOAT_0_00039999999;
    }
    v151 = 0;
    while ( 2 )
    {
      v152 = 0;
      v153 = 0i64;
      if ( v69 )
      {
LABEL_169:
        v154 = v57[1];
        v155 = v58[1];
        v156 = (float)((float)(*v57 - *v58) * (float)(*v57 - *v58))
             + (float)((float)(v57[1] - v155) * (float)(v57[1] - v155));
        v191 = *(float *)&v68[24 * (unsigned int)v153 + 4];
        v157 = v191 - v154;
        v189 = *(float *)&v68[24 * (unsigned int)v153];
        v158 = v189 - *v57;
        v159 = v191 - v155;
        v160 = v189 - *v58;
        v161 = *(_DWORD *)&v68[24 * (unsigned int)v153 + 16];
        v162 = *(float *)&v68[24 * (unsigned int)v153 + 16] - v154;
        v163 = *(_DWORD *)&v68[24 * (unsigned int)v153 + 12];
        v164 = *(float *)&v68[24 * (unsigned int)v153 + 12] - *v57;
        v165 = *(float *)&v68[24 * (unsigned int)v153 + 16] - v155;
        v166 = *(float *)&v68[24 * (unsigned int)v153 + 12] - *v58;
        if ( (float)((float)(v158 * v158) + (float)(v157 * v157)) < v150
          && (float)((float)(v166 * v166) + (float)(v165 * v165)) > v156 )
        {
          v167 = *(_DWORD *)&v68[24 * (unsigned int)v153 + 20];
          *(_DWORD *)v57 = v163;
          *((_DWORD *)v57 + 1) = v161;
          *((_DWORD *)v57 + 2) = v167;
          goto LABEL_182;
        }
        if ( (float)((float)(v160 * v160) + (float)(v159 * v159)) < v150
          && (float)((float)(v162 * v162) + (float)(v164 * v164)) > v156 )
        {
          v168 = *(_DWORD *)&v68[24 * (unsigned int)v153 + 20];
          *(_DWORD *)v58 = v163;
          *((_DWORD *)v58 + 1) = v161;
          goto LABEL_181;
        }
        if ( (float)((float)(v164 * v164) + (float)(v162 * v162)) < v150
          && (float)((float)(v159 * v159) + (float)(v160 * v160)) > v156 )
        {
          v169 = *(_DWORD *)&v68[24 * (unsigned int)v153 + 8];
          *v57 = v189;
          v57[1] = v191;
          *((_DWORD *)v57 + 2) = v169;
          goto LABEL_182;
        }
        if ( (float)((float)(v166 * v166) + (float)(v165 * v165)) < v150
          && (float)((float)(v158 * v158) + (float)(v157 * v157)) > v156 )
        {
          v168 = *(_DWORD *)&v68[24 * (unsigned int)v153 + 8];
          *v58 = v189;
          v58[1] = v191;
LABEL_181:
          *((_DWORD *)v58 + 2) = v168;
LABEL_182:
          v170 = v69 - 1;
          v171 = *(_DWORD *)&v68[24 * v170 + 4];
          v172 = *(_DWORD *)&v68[24 * v170 + 8];
          *(_DWORD *)&v68[24 * (unsigned int)v153] = *(_DWORD *)&v68[24 * v170];
          *(_DWORD *)&v68[24 * (unsigned int)v153 + 4] = v171;
          *(_DWORD *)&v68[24 * (unsigned int)v153 + 8] = v172;
          v173 = *(_DWORD *)&v68[24 * v170 + 12];
          v174 = *(_DWORD *)&v68[24 * v170 + 16];
          v175 = *(_DWORD *)&v68[24 * v170 + 20];
          if ( v69 <= 1 )
            LODWORD(v170) = 0;
          B2.m_quad.m128_i32[0] = v170;
          *(_DWORD *)&v68[24 * (unsigned int)v153 + 20] = v175;
          *(_DWORD *)&v68[24 * (unsigned int)v153 + 16] = v174;
          v69 = v170;
          *(_DWORD *)&v68[24 * (unsigned int)v153 + 12] = v173;
          v152 = 1;
        }
        v153 = (unsigned int)(v153 + 1);
        if ( (unsigned int)v153 >= v69 )
        {
          if ( v152 )
          {
            v151 = 1;
            continue;
          }
          break;
        }
        goto LABEL_169;
      }
      break;
    }
    B.m_quad.m128_i32[2] = 0;
    if ( B.m_quad.m128_i32[3] >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, unsigned __int64, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        B.m_quad.m128_u64[0],
        (unsigned int)(4 * B.m_quad.m128_i32[3]),
        v153);
    B.m_quad.m128_u64[0] = 0i64;
    B.m_quad.m128_i32[3] = 2147483648;
    v63 = (__m128)(unsigned int)FLOAT_1_0;
    v67 = _xmm;
    v66 = 0.0;
    v65 = v193;
    v18 = FLOAT_0_5;
  }
  while ( v151 );
  v176 = 0.0;
  v177 = *((float *)v194->m128_u64 + 1);
  v178 = *(float *)v194->m128_u64;
  if ( *(_DWORD *)(v215 + 8) <= (unsigned int)ptr )
  {
    if ( (_DWORD)ptr )
    {
      v181 = (float *)(*(_QWORD *)v215 + 48i64 * ((signed int)ptr - 1));
      v180 = v177 - v181[1];
      v176 = v178 - *v181;
    }
    else
    {
      v180 = *(float *)&FLOAT_1_0;
    }
  }
  else
  {
    v179 = (float *)(*(_QWORD *)v215 + 48i64 * ((signed int)ptr + 1));
    v180 = v179[1] - v177;
    v176 = *v179 - v178;
  }
  v182 = *((_DWORD *)v57 + 1);
  v183 = v58[1];
  v184 = *v57;
  if ( (float)((float)(v176 * (float)(v57[1] - v183)) - (float)((float)(*v57 - *v58) * v180)) < 0.0 )
  {
    v185 = *((_DWORD *)v57 + 2);
    v186 = *((_DWORD *)v58 + 2);
    *v57 = *v58;
    v57[1] = v183;
    *((_DWORD *)v57 + 2) = v186;
    *v58 = v184;
    *((_DWORD *)v58 + 1) = v182;
    *((_DWORD *)v58 + 2) = v185;
  }
  if ( v56 )
    operator delete[](v56);
  mem = 0i64;
  v194 = 0i64;
  if ( v68 )
    operator delete[](v68);
  return 1;
}

// File Line: 511
// RVA: 0xEB360
void __fastcall UFG::HavokNavDaemon::FindPathImmediate(UFG::HavokNavDaemon *this, UFG::FindPathImmediateQuery *queryInput)
{
  UFG::FindPathImmediateQuery *v2; // rsi
  UFG::HavokNavDaemon *v3; // r12
  UFG::NavManager *v4; // r15
  hkaiNavMeshQueryMediator *v5; // rax
  UFG::DaemonQueryOutput *v6; // rdi
  UFG::NavPath *v7; // rbx
  UFG::DaemonQueryOutputVtbl *v8; // rcx
  bool v9; // zf
  signed __int64 v10; // rbx
  char v11; // dl
  __int64 v12; // rax
  char v13; // cl
  __m128 v14; // xmm1
  __m128i v15; // xmm2
  UFG::NavParams *v16; // rax
  unsigned int v17; // ecx
  char v18; // al
  UFG::NavPath *v19; // rbx
  UFG::DaemonQueryOutputVtbl *v20; // rcx
  unsigned int v21; // ecx
  signed int v22; // eax
  char v23; // dl
  __int64 v24; // rax
  char v25; // cl
  char v26; // al
  char v27; // dl
  __int64 v28; // rax
  char v29; // cl
  hkJobType v30; // edx
  char *v31; // rbx
  char output[72]; // [rsp+20h] [rbp-B8h]
  __m128 *v33; // [rsp+68h] [rbp-70h]
  hkaiPathfindingUtil::FindPathInput input; // [rsp+70h] [rbp-68h]
  char *v35; // [rsp+140h] [rbp+68h]

  *(_QWORD *)&output[64] = -2i64;
  v2 = queryInput;
  v3 = this;
  v4 = UFG::NavManager::ms_pInstance;
  v5 = hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
  v6 = v2->m_pOutput;
  if ( v5 )
  {
    v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v11 = ++*(_BYTE *)(v10 + 80);
    v12 = v11;
    *(_DWORD *)(v10 + 4 * v12) = 1;
    *(_QWORD *)(v10 + 8 * v12 + 16) = "AI::HavokNavDaemon::FindPathImmediate 1";
    *(_QWORD *)(v10 + 8 * v12 + 48) = 0i64;
    v13 = *(_BYTE *)(v10 + 81);
    if ( v11 > v13 )
      v13 = v11;
    *(_BYTE *)(v10 + 81) = v13;
    hkaiPathfindingUtil::FindPathInput::FindPathInput(&input, 1);
    v14 = _mm_mul_ps(_xmm, (__m128)xmmword_141A71390);
    v15 = _mm_add_epi32(
            _mm_xor_si128(
              _mm_cvttps_epi32(v14),
              (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v14)),
            _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset));
    LOWORD(input.m_startFaceKey) = _mm_extract_epi16(v15, 1);
    HIWORD(input.m_startFaceKey) = _mm_extract_epi16(v15, 3);
    *((_WORD *)&input.m_startFaceKey + 2) = _mm_extract_epi16(v15, 5);
    v16 = v2->m_pNavParams;
    *((float *)&input.m_goalPoints.m_data + 1) = v16->m_fRadius * 2.0;
    input.m_goalPoints.m_size = v16->m_flags;
    HIBYTE(input.m_maxNumberOfIterations) = 0;
    input.m_goalFaceKeys.m_data = (unsigned int *)&v4[14];
    *(_QWORD *)&input.m_goalFaceKeys.m_size = v4 + 20;
    *(hkVector4f *)&output[56] = v2->m_npFrom.m_hkvMeshPosition;
    v17 = v2->m_npFrom.m_packedKey;
    *(_DWORD *)&input.m_memSizeAndFlags = v2->m_npFrom.m_packedKey;
    v18 = *(_BYTE *)(v10 + 80);
    if ( v18 > 0 )
    {
      *(_BYTE *)(v10 + 80) = v18 - 1;
    }
    else
    {
      *(_BYTE *)(v10 + 80) = 0;
      *(_DWORD *)v10 = 3;
      *(_QWORD *)(v10 + 16) = 0i64;
      *(_QWORD *)(v10 + 48) = 0i64;
    }
    if ( v17 == -1 )
    {
      v19 = UFG::g_NullPath;
      if ( (UFG::NavPath *)v6[1].vfptr != UFG::g_NullPath )
      {
        if ( UFG::g_NullPath )
          ++UFG::g_NullPath->m_uRefCount;
        v20 = v6[1].vfptr;
        if ( v20 )
        {
          v9 = LODWORD(v20[5].__vecDelDtor)-- == 1;
          if ( v9 )
            (*(void (__fastcall **)(UFG::DaemonQueryOutputVtbl *, signed __int64))v20->__vecDelDtor)(v20, 1i64);
        }
        v6[1].vfptr = (UFG::DaemonQueryOutputVtbl *)v19;
      }
      v6->m_status = 4;
    }
    else
    {
      *v33 = _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)LODWORD(v2->m_npTo.m_vPosition.x), (__m128)LODWORD(v2->m_npTo.m_vPosition.z)),
               _mm_unpacklo_ps((__m128)LODWORD(v2->m_npTo.m_vPosition.y), (__m128)0i64));
      v21 = v2->m_npTo.m_packedKey;
      *(_DWORD *)input.m_startPoint.m_quad.m128_u64[0] = v21;
      if ( v21 == -1 )
      {
        UFG::NavPathRefPtr::operator=((UFG::NavPathRefPtr *)&v6[1], UFG::g_NullPath);
        v6->m_status = 4;
      }
      else
      {
        v22 = 2048;
        if ( v2->m_maxSearchIterations >= 0 )
          v22 = v2->m_maxSearchIterations;
        LODWORD(input.m_goalPoints.m_data) = v22;
        HIDWORD(input.m_searchParameters.m_costModifier) = 0x2000;
        input.m_searchParameters.m_edgeFilter = (hkaiAstarEdgeFilter *)8796093059584i64;
        *(_DWORD *)&input.m_searchParameters.m_validateInputs.m_bool = 9728;
        v23 = ++*(_BYTE *)(v10 + 80);
        v24 = v23;
        *(_DWORD *)(v10 + 4 * v24) = 1;
        *(_QWORD *)(v10 + 8 * v24 + 16) = "AI::HavokNavDaemon::FindPathImmediate 2";
        *(_QWORD *)(v10 + 8 * v24 + 48) = 0i64;
        v25 = *(_BYTE *)(v10 + 81);
        if ( v23 > v25 )
          v25 = v23;
        *(_BYTE *)(v10 + 81) = v25;
        *(_DWORD *)&output[8] = 0x1FFFF;
        *(_QWORD *)output = &hkaiPathfindingUtil::FindPathOutput::`vftable';
        *(_QWORD *)&output[16] = 0i64;
        *(_DWORD *)&output[24] = 0;
        *(_DWORD *)&output[28] = 2147483648;
        *(_QWORD *)&output[32] = 0i64;
        *(_DWORD *)&output[40] = 0;
        *(_DWORD *)&output[44] = 2147483648;
        *(_DWORD *)&output[48] = 0;
        *(_DWORD *)&output[52] = -1;
        *(float *)&output[56] = FLOAT_3_40282e38;
        *(_WORD *)&output[60] = 0;
        hkaiPathfindingUtil::findPath(
          (hkaiStreamingCollection *)v4[3].vfptr->LowHealthDefrag,
          &input,
          (hkaiPathfindingUtil::FindPathOutput *)output);
        v26 = *(_BYTE *)(v10 + 80);
        if ( v26 > 0 )
        {
          *(_BYTE *)(v10 + 80) = v26 - 1;
        }
        else
        {
          *(_BYTE *)(v10 + 80) = 0;
          *(_DWORD *)v10 = 3;
          *(_QWORD *)(v10 + 16) = 0i64;
          *(_QWORD *)(v10 + 48) = 0i64;
        }
        if ( *(_DWORD *)&output[40] && output[60] == 1 )
        {
          v27 = ++*(_BYTE *)(v10 + 80);
          v28 = v27;
          *(_DWORD *)(v10 + 4 * v28) = 1;
          *(_QWORD *)(v10 + 8 * v28 + 16) = "AI::HavokNavDaemon::FindPathImmediate 3";
          *(_QWORD *)(v10 + 8 * v28 + 48) = 0i64;
          v29 = *(_BYTE *)(v10 + 81);
          if ( v27 > v29 )
            v29 = v27;
          *(_BYTE *)(v10 + 81) = v29;
          v31 = UFG::qMalloc(0x30ui64, "AI::FindPathImmediate:NavPath", 0i64);
          v35 = v31;
          if ( v31 )
          {
            *(_QWORD *)v31 = &UFG::NavPath::`vftable';
            *((_QWORD *)v31 + 2) = 0i64;
            *((_QWORD *)v31 + 1) = 0i64;
            *((_QWORD *)v31 + 4) = 0i64;
            *((_QWORD *)v31 + 3) = 0i64;
            *((_DWORD *)v31 + 10) = 0;
          }
          else
          {
            v31 = 0i64;
          }
          HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v30);
          UFG::NavPathRefPtr::operator=((UFG::NavPathRefPtr *)&v6[1], (UFG::NavPath *)v31);
          v6->m_status = 4
                       - (((unsigned __int8 (__fastcall *)(UFG::HavokNavDaemon *, char *, char *, char *, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))v3->vfptr[2].SubmitImmediateQuery)(
                            v3,
                            v31,
                            &output[32],
                            &output[16],
                            *(_QWORD *)output,
                            *(_QWORD *)&output[8],
                            *(_QWORD *)&output[16],
                            *(_QWORD *)&output[24],
                            *(_QWORD *)&output[32]) != 0);
        }
        else
        {
          UFG::NavPathRefPtr::operator=((UFG::NavPathRefPtr *)&v6[1], UFG::g_NullPath);
          v6->m_status = 4;
        }
        hkaiPathfindingUtil::FindPathOutput::~FindPathOutput((hkaiPathfindingUtil::FindPathOutput *)output);
      }
    }
    hkaiPathfindingUtil::FindPathInput::~FindPathInput(&input);
  }
  else
  {
    v7 = UFG::g_NullPath;
    if ( (UFG::NavPath *)v6[1].vfptr != UFG::g_NullPath )
    {
      if ( UFG::g_NullPath )
        ++UFG::g_NullPath->m_uRefCount;
      v8 = v6[1].vfptr;
      if ( v8 )
      {
        v9 = LODWORD(v8[5].__vecDelDtor)-- == 1;
        if ( v9 )
          (*(void (__fastcall **)(UFG::DaemonQueryOutputVtbl *, signed __int64))v8->__vecDelDtor)(v8, 1i64);
      }
      v6[1].vfptr = (UFG::DaemonQueryOutputVtbl *)v7;
    }
    v6->m_status = 4;
  }
}

// File Line: 610
// RVA: 0xEBC30
char __fastcall UFG::HavokNavDaemon::FindPathMultiDestPrioritizedImmediateSubRange(UFG::HavokNavDaemon *this, hkaiWorld *world, UFG::FindPathMultiDestPrioritizedImmediateQuery *queryInput, hkaiPathfindingUtil::FindPathInput *pInput)
{
  hkaiPathfindingUtil::FindPathInput *v4; // rsi
  UFG::FindPathMultiDestPrioritizedImmediateQuery *v5; // r14
  hkaiWorld *v6; // r15
  UFG::HavokNavDaemon *v7; // r12
  unsigned int v8; // er10
  float v9; // xmm0_4
  unsigned int v10; // er11
  int v11; // ebx
  __int64 v12; // r8
  __int64 v13; // r9
  signed __int64 v14; // rcx
  UFG::FindPathMultiDestPrioritizedImmediateQuery::PrioritizedDestination *v15; // rax
  unsigned int v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // er9
  int v20; // eax
  int v21; // eax
  int v22; // er9
  signed int v24; // eax
  signed __int64 v25; // rdi
  char v26; // dl
  __int64 v27; // rax
  char v28; // cl
  unsigned int v29; // ebx
  float *v30; // r9
  char v31; // al
  hkaiPath::PathPoint *v32; // rax
  float v33; // xmm4_4
  float v34; // xmm5_4
  float v35; // xmm6_4
  unsigned int v36; // er10
  float v37; // xmm3_4
  unsigned int v38; // edx
  signed __int64 v39; // rax
  UFG::FindPathMultiDestPrioritizedImmediateQuery::PrioritizedDestination *v40; // rax
  signed int v41; // er8
  float *v42; // rcx
  float *v43; // r8
  float v44; // xmm0_4
  char v45; // dl
  __int64 v46; // rax
  char v47; // cl
  char *v48; // rbx
  char v49; // al
  UFG::DaemonQueryOutput *v50; // rdi
  __int64 v51; // rcx
  bool v52; // zf
  char v53; // bl
  hkaiPathfindingUtil::FindPathOutput output; // [rsp+8h] [rbp-79h]
  __int64 v55; // [rsp+48h] [rbp-39h]
  char *v56; // [rsp+E8h] [rbp+67h]
  void *retaddr; // [rsp+F8h] [rbp+77h]
  float *v58; // [rsp+100h] [rbp+7Fh]

  v55 = -2i64;
  v4 = pInput;
  v5 = queryInput;
  v6 = world;
  v7 = this;
  v8 = (unsigned int)retaddr;
  v9 = (float)(queryInput->m_aPrioritizedDestinations.size - (signed int)retaddr);
  if ( v9 >= 16.0 )
    v9 = FLOAT_16_0;
  v10 = (_DWORD)retaddr + (signed int)v9;
  v11 = 0;
  if ( (unsigned int)retaddr < v10 )
  {
    v12 = 0i64;
    v13 = 0i64;
    v14 = (unsigned int)retaddr;
    do
    {
      v15 = v5->m_aPrioritizedDestinations.p;
      v16 = v15[v14].m_npPosition.m_packedKey;
      if ( v16 != -1 )
      {
        v4->m_goalPoints.m_data[v13] = v15[v14].m_npPosition.m_hkvMeshPosition;
        v4->m_goalFaceKeys.m_data[v12] = v16;
        ++v11;
        ++v13;
        ++v12;
      }
      ++v8;
      ++v14;
    }
    while ( v8 < v10 );
  }
  v17 = v4->m_goalPoints.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v17 < v11 )
  {
    v18 = 2 * v17;
    v19 = v11;
    if ( v11 < v18 )
      v19 = v18;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v4->m_goalPoints,
      v19,
      16);
  }
  v4->m_goalPoints.m_size = v11;
  v20 = v4->m_goalFaceKeys.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < v11 )
  {
    v21 = 2 * v20;
    v22 = v11;
    if ( v11 < v21 )
      v22 = v21;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v4->m_goalFaceKeys,
      v22,
      4);
  }
  v4->m_goalFaceKeys.m_size = v11;
  if ( !v11 )
    return 0;
  v24 = 512;
  if ( v5->m_maxSearchIterations >= 0 )
    v24 = v5->m_maxSearchIterations;
  v4->m_maxNumberOfIterations = v24;
  v4->m_searchParameters.m_bufferSizes.m_maxOpenSetSizeBytes = 0x2000;
  v4->m_searchParameters.m_bufferSizes.m_maxSearchStateSizeBytes = 37376;
  v4->m_searchParameters.m_hierarchyBufferSizes.m_maxOpenSetSizeBytes = 2048;
  v4->m_searchParameters.m_hierarchyBufferSizes.m_maxSearchStateSizeBytes = 9728;
  v25 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v26 = ++*(_BYTE *)(v25 + 80);
  v27 = v26;
  *(_DWORD *)(v25 + 4 * v27) = 1;
  *(_QWORD *)(v25 + 8 * v27 + 16) = "AI::HavokNavDaemon::FindPathMultiDestPrioritizedImmediate 2";
  *(_QWORD *)(v25 + 8 * v27 + 48) = 0i64;
  v28 = *(_BYTE *)(v25 + 81);
  if ( v26 > v28 )
    v28 = v26;
  *(_BYTE *)(v25 + 81) = v28;
  *(_DWORD *)&output.m_memSizeAndFlags = 0x1FFFF;
  output.vfptr = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathOutput::`vftable';
  output.m_visitedEdges.m_data = 0i64;
  output.m_visitedEdges.m_size = 0;
  output.m_visitedEdges.m_capacityAndFlags = 2147483648;
  output.m_pathOut.m_data = 0i64;
  output.m_pathOut.m_size = 0;
  output.m_pathOut.m_capacityAndFlags = 2147483648;
  output.m_outputParameters.m_numIterations = 0;
  v29 = -1;
  output.m_outputParameters.m_goalIndex = -1;
  output.m_outputParameters.m_pathLength = FLOAT_3_40282e38;
  *(_WORD *)&output.m_outputParameters.m_status.m_storage = 0;
  hkaiPathfindingUtil::findPath(v6->m_streamingCollection.m_pntr, v4, &output);
  v31 = *(_BYTE *)(v25 + 80);
  if ( v31 > 0 )
  {
    *(_BYTE *)(v25 + 80) = v31 - 1;
  }
  else
  {
    *(_BYTE *)(v25 + 80) = 0;
    *(_DWORD *)v25 = 3;
    *(_QWORD *)(v25 + 16) = 0i64;
    *(_QWORD *)(v25 + 48) = 0i64;
  }
  if ( !output.m_pathOut.m_size || output.m_outputParameters.m_status.m_storage != 1 )
    goto LABEL_70;
  v32 = &output.m_pathOut.m_data[output.m_pathOut.m_size - 1];
  v33 = v32->m_position.m_quad.m128_f32[0];
  v34 = v32->m_position.m_quad.m128_f32[1];
  v35 = v32->m_position.m_quad.m128_f32[2];
  v36 = v5->m_aPrioritizedDestinations.size;
  v37 = FLOAT_3_4028235e38;
  v38 = 0;
  v39 = 0i64;
  if ( (signed int)v36 >= 4 )
  {
    v40 = v5->m_aPrioritizedDestinations.p;
    v41 = 2;
    v30 = &v40[1].m_npPosition.m_vPosition.x;
    v42 = &v40[3].m_npPosition.m_vPosition.y;
    v39 = 4i64 * (((v36 - 4) >> 2) + 1);
    do
    {
      if ( (float)((float)((float)((float)(v34 - *(v42 - 60)) * (float)(v34 - *(v42 - 60)))
                         + (float)((float)(v33 - *(v30 - 20)) * (float)(v33 - *(v30 - 20))))
                 + (float)((float)(v35 - *(v42 - 59)) * (float)(v35 - *(v42 - 59)))) < v37 )
      {
        v29 = v38;
        v37 = (float)((float)((float)(v34 - *(v42 - 60)) * (float)(v34 - *(v42 - 60)))
                    + (float)((float)(v33 - *(v30 - 20)) * (float)(v33 - *(v30 - 20))))
            + (float)((float)(v35 - *(v42 - 59)) * (float)(v35 - *(v42 - 59)));
      }
      if ( (float)((float)((float)((float)(v34 - *(v42 - 40)) * (float)(v34 - *(v42 - 40)))
                         + (float)((float)(v33 - *v30) * (float)(v33 - *v30)))
                 + (float)((float)(v35 - *(v42 - 39)) * (float)(v35 - *(v42 - 39)))) < v37 )
      {
        v29 = v41 - 1;
        v37 = (float)((float)((float)(v34 - *(v42 - 40)) * (float)(v34 - *(v42 - 40)))
                    + (float)((float)(v33 - *v30) * (float)(v33 - *v30)))
            + (float)((float)(v35 - *(v42 - 39)) * (float)(v35 - *(v42 - 39)));
      }
      if ( (float)((float)((float)((float)(v34 - *(v42 - 20)) * (float)(v34 - *(v42 - 20)))
                         + (float)((float)(v33 - v30[20]) * (float)(v33 - v30[20])))
                 + (float)((float)(v35 - *(v42 - 19)) * (float)(v35 - *(v42 - 19)))) < v37 )
      {
        v29 = v41;
        v37 = (float)((float)((float)(v34 - *(v42 - 20)) * (float)(v34 - *(v42 - 20)))
                    + (float)((float)(v33 - v30[20]) * (float)(v33 - v30[20])))
            + (float)((float)(v35 - *(v42 - 19)) * (float)(v35 - *(v42 - 19)));
      }
      if ( (float)((float)((float)((float)(v34 - *v42) * (float)(v34 - *v42))
                         + (float)((float)(v33 - *(v42 - 1)) * (float)(v33 - *(v42 - 1))))
                 + (float)((float)(v35 - v42[1]) * (float)(v35 - v42[1]))) < v37 )
      {
        v29 = v41 + 1;
        v37 = (float)((float)((float)(v34 - *v42) * (float)(v34 - *v42))
                    + (float)((float)(v33 - *(v42 - 1)) * (float)(v33 - *(v42 - 1))))
            + (float)((float)(v35 - v42[1]) * (float)(v35 - v42[1]));
      }
      v30 += 80;
      v42 += 80;
      v38 += 4;
      v41 += 4;
    }
    while ( v38 < v36 - 3 );
  }
  if ( v38 < v36 )
  {
    v43 = &v5->m_aPrioritizedDestinations.p->m_npPosition.m_vPosition.y + 20 * v39;
    do
    {
      if ( (float)((float)((float)((float)(v34 - *v43) * (float)(v34 - *v43))
                         + (float)((float)(v33 - *(v43 - 1)) * (float)(v33 - *(v43 - 1))))
                 + (float)((float)(v35 - v43[1]) * (float)(v35 - v43[1]))) < v37 )
      {
        v29 = v38;
        v37 = (float)((float)((float)(v34 - *v43) * (float)(v34 - *v43))
                    + (float)((float)(v33 - *(v43 - 1)) * (float)(v33 - *(v43 - 1))))
            + (float)((float)(v35 - v43[1]) * (float)(v35 - v43[1]));
      }
      v43 += 20;
      ++v38;
    }
    while ( v38 < v36 );
  }
  if ( (v29 & 0x80000000) != 0 )
    goto LABEL_71;
  v44 = v5->m_aPrioritizedDestinations.p[v29].m_fPriority - *(float *)(*(_QWORD *)&v5->m_pOutput[1].m_id + 4i64 * v29);
  if ( v44 <= *v58 )
    goto LABEL_71;
  *v58 = v44;
  v45 = ++*(_BYTE *)(v25 + 80);
  v46 = v45;
  *(_DWORD *)(v25 + 4 * v46) = 1;
  *(_QWORD *)(v25 + 8 * v46 + 16) = "AI::HavokNavDaemon::FindPathMultiDestPrioritizedImmediate 3";
  *(_QWORD *)(v25 + 8 * v46 + 48) = 0i64;
  v47 = *(_BYTE *)(v25 + 81);
  if ( v45 > v47 )
    v47 = v45;
  *(_BYTE *)(v25 + 81) = v47;
  v48 = UFG::qMalloc(0x30ui64, "AI::FindPathMultiDestPrioritizedImmediate:NavPath", 0i64);
  v56 = v48;
  if ( v48 )
  {
    *(_QWORD *)v48 = &UFG::NavPath::`vftable';
    *((_QWORD *)v48 + 2) = 0i64;
    *((_QWORD *)v48 + 1) = 0i64;
    *((_QWORD *)v48 + 4) = 0i64;
    *((_QWORD *)v48 + 3) = 0i64;
    *((_DWORD *)v48 + 10) = 0;
  }
  else
  {
    v48 = 0i64;
  }
  v49 = *(_BYTE *)(v25 + 80);
  if ( v49 > 0 )
  {
    *(_BYTE *)(v25 + 80) = v49 - 1;
  }
  else
  {
    *(_BYTE *)(v25 + 80) = 0;
    *(_DWORD *)v25 = 3;
    *(_QWORD *)(v25 + 16) = 0i64;
    *(_QWORD *)(v25 + 48) = 0i64;
  }
  v50 = v5->m_pOutput;
  if ( *(char **)&v50[1].m_status != v48 )
  {
    if ( v48 )
      ++*((_DWORD *)v48 + 10);
    v51 = *(_QWORD *)&v50[1].m_status;
    if ( v51 )
    {
      v52 = (*(_DWORD *)(v51 + 40))-- == 1;
      if ( v52 )
        (**(void (__fastcall ***)(__int64, signed __int64))v51)(v51, 1i64);
    }
    *(_QWORD *)&v50[1].m_status = v48;
  }
  if ( ((unsigned __int8 (__fastcall *)(UFG::HavokNavDaemon *, char *, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *, hkArray<unsigned int,hkContainerHeapAllocator> *))v7->vfptr[2].SubmitImmediateQuery)(
         v7,
         v48,
         &output.m_pathOut,
         &output.m_visitedEdges) )
  {
LABEL_71:
    v53 = 1;
  }
  else
  {
LABEL_70:
    v53 = 0;
  }
  output.m_pathOut.m_size = 0;
  if ( output.m_pathOut.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkaiPath::PathPoint *, _QWORD, float *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      output.m_pathOut.m_data,
      48 * (output.m_pathOut.m_capacityAndFlags & 0x3FFFFFFFu),
      v30);
  output.m_pathOut.m_data = 0i64;
  output.m_pathOut.m_capacityAndFlags = 2147483648;
  output.m_visitedEdges.m_size = 0;
  if ( output.m_visitedEdges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      output.m_visitedEdges.m_data,
      4 * output.m_visitedEdges.m_capacityAndFlags);
  return v53;
}

// File Line: 741
// RVA: 0xEB7A0
void __fastcall UFG::HavokNavDaemon::FindPathMultiDestPrioritizedImmediate(UFG::HavokNavDaemon *this, UFG::FindPathMultiDestPrioritizedImmediateQuery *queryInput)
{
  UFG::FindPathMultiDestPrioritizedImmediateQuery *v2; // r13
  UFG::HavokNavDaemon *v3; // r12
  signed __int64 v4; // rsi
  char v5; // r8
  __int64 v6; // rax
  unsigned int v7; // edi
  char v8; // cl
  UFG::NavManager *v9; // rax
  UFG::DaemonQueryOutput *v10; // rbx
  UFG::NavPath *v11; // r14
  __int64 v12; // rcx
  bool v13; // zf
  char v14; // al
  unsigned int v15; // er15
  __m128 v16; // xmm1
  __m128i v17; // xmm2
  UFG::NavParams *v18; // rax
  unsigned int v19; // ecx
  char v20; // al
  unsigned int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // er8
  __int64 v24; // rcx
  unsigned int v25; // eax
  __int64 v26; // rdx
  signed __int64 v27; // rcx
  __int64 v28; // rdx
  char v29; // si
  int v30; // edi
  __int64 v31; // r14
  __int64 v32; // rbx
  __int64 v33; // [rsp+20h] [rbp-E0h]
  void **v34; // [rsp+30h] [rbp-D0h]
  int v35; // [rsp+38h] [rbp-C8h]
  char v36; // [rsp+40h] [rbp-C0h]
  hkaiPathfindingUtil::FindPathInput v37; // [rsp+50h] [rbp-B0h]
  __int64 v38; // [rsp+110h] [rbp+10h]
  NavMeshCostModifierMultiDestPrioritized v39; // [rsp+120h] [rbp+20h]
  UFG::NavManager *v40; // [rsp+1A8h] [rbp+A8h]
  UFG::NavManagerVtbl *v41; // [rsp+1B0h] [rbp+B0h]
  UFG::DaemonQueryOutput *v42; // [rsp+1B8h] [rbp+B8h]

  v38 = -2i64;
  v2 = queryInput;
  v3 = this;
  v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v5 = ++*(_BYTE *)(v4 + 80);
  v6 = v5;
  v7 = 1;
  *(_DWORD *)(v4 + 4 * v6) = 1;
  *(_QWORD *)(v4 + 8 * v6 + 16) = "AI::HavokNavDaemon::FindPathMultiDestPrioritizedImmediate 1";
  *(_QWORD *)(v4 + 8 * v6 + 48) = 0i64;
  v8 = *(_BYTE *)(v4 + 81);
  if ( v5 > v8 )
    v8 = v5;
  *(_BYTE *)(v4 + 81) = v8;
  v9 = UFG::NavManager::ms_pInstance;
  v40 = UFG::NavManager::ms_pInstance;
  v10 = queryInput->m_pOutput;
  v42 = v10;
  v11 = UFG::g_NullPath;
  if ( *(UFG::NavPath **)&v10[1].m_status != UFG::g_NullPath )
  {
    if ( UFG::g_NullPath )
      ++UFG::g_NullPath->m_uRefCount;
    v12 = *(_QWORD *)&v10[1].m_status;
    if ( v12 )
    {
      v13 = (*(_DWORD *)(v12 + 40))-- == 1;
      if ( v13 )
      {
        (**(void (__fastcall ***)(__int64, signed __int64))v12)(v12, 1i64);
        v9 = v40;
      }
    }
    *(_QWORD *)&v10[1].m_status = v11;
  }
  v10->m_status = 4;
  if ( hkaiWorld::getDynamicQueryMediator((hkaiWorld *)v9[3].vfptr) )
  {
    v15 = v2->m_aPrioritizedDestinations.size;
    hkaiPathfindingUtil::FindPathInput::FindPathInput(&v37, v2->m_aPrioritizedDestinations.size);
    v16 = _mm_mul_ps(_xmm, (__m128)xmmword_141A71390);
    v17 = _mm_add_epi32(
            _mm_xor_si128(
              _mm_cvttps_epi32(v16),
              (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v16)),
            _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset));
    v37.m_searchParameters.m_up.m_vec[0] = _mm_extract_epi16(v17, 1);
    v37.m_searchParameters.m_up.m_vec[1] = _mm_extract_epi16(v17, 3);
    v37.m_searchParameters.m_up.m_vec[2] = _mm_extract_epi16(v17, 5);
    v18 = v2->m_pNavParams;
    v37.m_agentInfo.m_diameter = v18->m_fRadius * 2.0;
    v37.m_agentInfo.m_filterInfo = v18->m_flags;
    v37.m_searchParameters.m_lineOfSightFlags.m_storage = 0;
    NavMeshCostModifierMultiDestPrioritized::NavMeshCostModifierMultiDestPrioritized(&v39, v2);
    v37.m_searchParameters.m_costModifier = (hkaiAstarCostModifier *)&v39;
    v35 = 0x1FFFF;
    v36 = 1;
    v34 = &hkaiUFGAStarEdgeFilter::`vftable';
    v37.m_searchParameters.m_edgeFilter = (hkaiAstarEdgeFilter *)&v34;
    v41 = v40[3].vfptr;
    v37.m_startPoint = v2->m_npFrom.m_hkvMeshPosition;
    v19 = v2->m_npFrom.m_packedKey;
    v37.m_startFaceKey = v2->m_npFrom.m_packedKey;
    v20 = *(_BYTE *)(v4 + 80);
    if ( v20 > 0 )
    {
      *(_BYTE *)(v4 + 80) = v20 - 1;
    }
    else
    {
      *(_BYTE *)(v4 + 80) = 0;
      *(_DWORD *)v4 = 3;
      *(_QWORD *)(v4 + 16) = 0i64;
      *(_QWORD *)(v4 + 48) = 0i64;
    }
    if ( v19 != -1 )
    {
      v21 = (unsigned int)v10[1].vfptr;
      if ( (signed int)(v15 - v21) <= 0 )
      {
        if ( v21 != v15 )
        {
          if ( v21 - v15 < v21 )
            LODWORD(v10[1].vfptr) = v15;
          else
            LODWORD(v10[1].vfptr) = 0;
        }
      }
      else
      {
        v22 = HIDWORD(v10[1].vfptr);
        if ( v15 > v22 )
        {
          if ( v22 )
            v7 = 2 * v22;
          for ( ; v7 < v15; v7 *= 2 )
            ;
          if ( v7 <= 4 )
            v7 = 4;
          if ( v7 - v15 > 0x10000 )
            v7 = v15 + 0x10000;
          UFG::qArray<float,0>::Reallocate((UFG::qArray<float,0> *)&v10[1], v7, "m_afPathCosts");
        }
        LODWORD(v10[1].vfptr) = v15;
      }
      v23 = 0;
      v24 = 0i64;
      if ( (signed int)v15 >= 4 )
      {
        v25 = ((v15 - 4) >> 2) + 1;
        v26 = v25;
        v23 = 4 * v25;
        do
        {
          *(_DWORD *)(*(_QWORD *)&v10[1].m_id + 4 * v24) = 2139095039;
          *(_DWORD *)(*(_QWORD *)&v10[1].m_id + 4 * v24 + 4) = 2139095039;
          *(_DWORD *)(*(_QWORD *)&v10[1].m_id + 4 * v24 + 8) = 2139095039;
          *(_DWORD *)(*(_QWORD *)&v10[1].m_id + 4 * v24 + 12) = 2139095039;
          v24 += 4i64;
          --v26;
        }
        while ( v26 );
      }
      if ( v23 < v15 )
      {
        v27 = 4 * v24;
        v28 = v15 - v23;
        do
        {
          *(_DWORD *)(v27 + *(_QWORD *)&v10[1].m_id) = 2139095039;
          v27 += 4i64;
          --v28;
        }
        while ( v28 );
      }
      *(float *)&v40 = FLOAT_N3_4028235e38;
      v29 = 0;
      v30 = 0;
      v31 = (v2->m_aPrioritizedDestinations.size >> 4) + 1;
      v32 = (__int64)v41;
      do
      {
        LODWORD(v33) = v30;
        v29 |= ((__int64 (__fastcall *)(UFG::HavokNavDaemon *, __int64, UFG::FindPathMultiDestPrioritizedImmediateQuery *, hkaiPathfindingUtil::FindPathInput *, __int64, UFG::NavManager **, void **, _QWORD, _QWORD))v3->vfptr[1].CancelQueueableQuery)(
                 v3,
                 v32,
                 v2,
                 &v37,
                 v33,
                 &v40,
                 v34,
                 *(_QWORD *)&v35,
                 *(_QWORD *)&v36);
        v30 += 16;
        --v31;
      }
      while ( v31 );
      if ( v29 )
        v42->m_status = 3;
    }
    v34 = &hkBaseObject::`vftable';
    v39.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
    v37.vfptr = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathInput::`vftable';
    v37.m_goalFaceKeys.m_size = 0;
    if ( v37.m_goalFaceKeys.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v37.m_goalFaceKeys.m_data,
        4 * v37.m_goalFaceKeys.m_capacityAndFlags);
    v37.m_goalFaceKeys.m_data = 0i64;
    v37.m_goalFaceKeys.m_capacityAndFlags = 2147483648;
    v37.m_goalPoints.m_size = 0;
    if ( v37.m_goalPoints.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v37.m_goalPoints.m_data,
        16 * v37.m_goalPoints.m_capacityAndFlags);
  }
  else
  {
    v14 = *(_BYTE *)(v4 + 80);
    if ( v14 > 0 )
    {
      *(_BYTE *)(v4 + 80) = v14 - 1;
    }
    else
    {
      *(_BYTE *)(v4 + 80) = 0;
      *(_DWORD *)v4 = 3;
      *(_QWORD *)(v4 + 16) = 0i64;
      *(_QWORD *)(v4 + 48) = 0i64;
    }
  }
}

// File Line: 830
// RVA: 0xEC230
void __fastcall UFG::HavokNavDaemon::FindPathToRegionImmediate(UFG::HavokNavDaemon *this, UFG::FindPathToRegionImmediateQuery *queryInput)
{
  UFG::FindPathToRegionImmediateQuery *v2; // rsi
  signed __int64 v3; // rbx
  char v4; // r8
  __int64 v5; // rax
  char v6; // cl
  UFG::DaemonQueryOutput *v7; // rdi
  UFG::NavManagerVtbl *v8; // rbp
  char v9; // al
  unsigned int v10; // er8
  char v11; // al
  char v12; // dl
  __int64 v13; // rax
  char v14; // cl
  int v15; // eax
  char v16; // al
  char v17; // dl
  __int64 v18; // rax
  char v19; // cl
  float v20; // xmm1_4
  float v21; // xmm2_4
  char v22; // al
  hkaiPathfindingUtil::NearestFeatureCallback callback; // [rsp+20h] [rbp-B8h]
  UFG::RegionComponent *v24; // [rsp+28h] [rbp-B0h]
  char v25; // [rsp+30h] [rbp-A8h]
  UFG::qVector3 v26; // [rsp+34h] [rbp-A4h]
  __int64 v27; // [rsp+40h] [rbp-98h]
  hkaiPathfindingUtil::NearestFeatureInput input; // [rsp+50h] [rbp-88h]

  v27 = -2i64;
  v2 = queryInput;
  v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v4 = ++*(_BYTE *)(v3 + 80);
  v5 = v4;
  *(_DWORD *)(v3 + 4 * v5) = 1;
  *(_QWORD *)(v3 + 8 * v5 + 16) = "AI::HavokNavDaemon::FindPathToRegionImmediate 1";
  *(_QWORD *)(v3 + 8 * v5 + 48) = 0i64;
  v6 = *(_BYTE *)(v3 + 81);
  if ( v4 > v6 )
    v6 = v4;
  *(_BYTE *)(v3 + 81) = v6;
  v7 = queryInput->m_pOutput;
  v8 = UFG::NavManager::ms_pInstance[3].vfptr;
  if ( hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr) )
  {
    hkaiPathfindingUtil::NearestFeatureInput::NearestFeatureInput(&input);
    input.m_startPoint = v2->m_npFrom.m_hkvMeshPosition;
    v10 = v2->m_npFrom.m_packedKey;
    v11 = *(_BYTE *)(v3 + 80);
    if ( v11 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v11 - 1;
    }
    else
    {
      *(_BYTE *)(v3 + 80) = 0;
      *(_DWORD *)v3 = 3;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_QWORD *)(v3 + 48) = 0i64;
    }
    if ( v10 == -1 )
    {
      v7->m_status = 4;
    }
    else
    {
      v12 = ++*(_BYTE *)(v3 + 80);
      v13 = v12;
      *(_DWORD *)(v3 + 4 * v13) = 1;
      *(_QWORD *)(v3 + 8 * v13 + 16) = "AI::HavokNavDaemon::FindPathToRegionImmediate 2";
      *(_QWORD *)(v3 + 8 * v13 + 48) = 0i64;
      v14 = *(_BYTE *)(v3 + 81);
      if ( v12 > v14 )
        v14 = v12;
      *(_BYTE *)(v3 + 81) = v14;
      input.m_startFaceKey = v10;
      v15 = 512;
      if ( v2->m_maxSearchIterations >= 0 )
        v15 = v2->m_maxSearchIterations;
      input.m_maxNumberOfIterations = v15;
      input.m_bufferSizes.m_maxOpenSetSizeBytes = 0x2000;
      input.m_bufferSizes.m_maxSearchStateSizeBytes = 37376;
      input.m_searchRadius = FLOAT_30_0;
      input.m_up.m_quad = _mm_unpacklo_ps(
                            _mm_unpacklo_ps(
                              (__m128)LODWORD(UFG::qVector3::msAxisZ.x),
                              (__m128)LODWORD(UFG::qVector3::msAxisZ.z)),
                            _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msAxisZ.y), (__m128)0i64));
      v16 = *(_BYTE *)(v3 + 80);
      if ( v16 > 0 )
      {
        *(_BYTE *)(v3 + 80) = v16 - 1;
      }
      else
      {
        *(_BYTE *)(v3 + 80) = 0;
        *(_DWORD *)v3 = 3;
        *(_QWORD *)(v3 + 16) = 0i64;
        *(_QWORD *)(v3 + 48) = 0i64;
      }
      v17 = ++*(_BYTE *)(v3 + 80);
      v18 = v17;
      *(_DWORD *)(v3 + 4 * v18) = 1;
      *(_QWORD *)(v3 + 8 * v18 + 16) = "AI::HavokNavDaemon::FindPathToRegionImmediate 3";
      *(_QWORD *)(v3 + 8 * v18 + 48) = 0i64;
      v19 = *(_BYTE *)(v3 + 81);
      if ( v17 > v19 )
        v19 = v17;
      *(_BYTE *)(v3 + 81) = v19;
      callback.vfptr = (hkaiPathfindingUtil::NearestFeatureCallbackVtbl *)&UFG::HavokRegionNearestFeatureCallback::`vftable';
      v25 = 0;
      v26 = UFG::qVector3::msZero;
      v24 = v2->m_pRegionComponent;
      hkaiPathfindingUtil::findNearestEdges((hkaiStreamingCollection *)v8->LowHealthDefrag, &input, &callback, 0i64);
      if ( v25 )
      {
        v7->m_status = 3;
        v20 = v26.y;
        v21 = v26.z;
        v7[1].m_status = LODWORD(v26.x);
        *((float *)&v7[1].m_status + 1) = v20;
        *(float *)&v7[2].vfptr = v21;
        LOBYTE(v7[2].m_id) = 0;
      }
      else
      {
        v7->m_status = 4;
      }
      v22 = *(_BYTE *)(v3 + 80);
      if ( v22 > 0 )
      {
        *(_BYTE *)(v3 + 80) = v22 - 1;
      }
      else
      {
        *(_BYTE *)(v3 + 80) = 0;
        *(_DWORD *)v3 = 3;
        *(_QWORD *)(v3 + 16) = 0i64;
        *(_QWORD *)(v3 + 48) = 0i64;
      }
    }
  }
  else
  {
    v7->m_status = 4;
    v9 = *(_BYTE *)(v3 + 80);
    if ( v9 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v9 - 1;
    }
    else
    {
      *(_BYTE *)(v3 + 80) = 0;
      *(_DWORD *)v3 = 3;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_QWORD *)(v3 + 48) = 0i64;
    }
  }
}

// File Line: 904
// RVA: 0xEC8D0
void __fastcall UFG::HavokNavDaemon::FleeTraversalImmediate(UFG::HavokNavDaemon *this, UFG::FleeTraversalImmediateQuery *queryInput)
{
  hkVector4f *v2; // rdi
  signed __int64 v3; // rbx
  char v4; // r8
  __int64 v5; // rax
  char v6; // cl
  hkVector4f *v7; // rsi
  UFG::NavManagerVtbl *v8; // r15
  char v9; // al
  unsigned int v10; // er14
  float v11; // xmm0_4
  float v12; // xmm0_4
  unsigned int v13; // er8
  float v14; // er9
  unsigned __int64 v15; // r10
  unsigned int *v16; // rdx
  signed __int64 v17; // rcx
  int v18; // eax
  unsigned int v19; // xmm1_4
  int v20; // xmm2_4
  char v21; // al
  void **v22; // [rsp+20h] [rbp-B8h]
  int v23; // [rsp+28h] [rbp-B0h]
  char v24; // [rsp+30h] [rbp-A8h]
  int v25; // [rsp+38h] [rbp-A0h]
  int v26; // [rsp+3Ch] [rbp-9Ch]
  int v27; // [rsp+40h] [rbp-98h]
  hkaiPathfindingUtil::NearestFeatureCallback callback; // [rsp+50h] [rbp-88h]
  char v29; // [rsp+58h] [rbp-80h]
  hkVector4f v30; // [rsp+60h] [rbp-78h]
  float v31; // [rsp+70h] [rbp-68h]
  float v32; // [rsp+74h] [rbp-64h]
  hkaiPathfindingUtil::NearestFeatureInput input; // [rsp+78h] [rbp-60h]
  hkVector4f hkvNewPosition; // [rsp+E8h] [rbp+10h]
  void **v35; // [rsp+F8h] [rbp+20h]
  int v36; // [rsp+100h] [rbp+28h]
  char v37; // [rsp+108h] [rbp+30h]
  unsigned int v38; // [rsp+128h] [rbp+50h]
  __int128 v39; // [rsp+138h] [rbp+60h]
  int v40[156]; // [rsp+148h] [rbp+70h]
  float v41; // [rsp+3B8h] [rbp+2E0h]
  float v42; // [rsp+3BCh] [rbp+2E4h]

  v30.m_quad.m128_u64[1] = -2i64;
  v2 = (hkVector4f *)queryInput;
  v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v4 = ++*(_BYTE *)(v3 + 80);
  v5 = v4;
  *(_DWORD *)(v3 + 4 * v5) = 1;
  *(_QWORD *)(v3 + 8 * v5 + 16) = "AI::HavokNavDaemon::FleeTraversalImmediate";
  *(_QWORD *)(v3 + 8 * v5 + 48) = 0i64;
  v6 = *(_BYTE *)(v3 + 81);
  if ( v4 > v6 )
    v6 = v4;
  *(_BYTE *)(v3 + 81) = v6;
  v7 = (hkVector4f *)queryInput->m_pOutput;
  v8 = UFG::NavManager::ms_pInstance[3].vfptr;
  if ( hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr)
    && (hkaiPathfindingUtil::NearestFeatureInput::NearestFeatureInput(&input),
        input.m_startPoint = (hkVector4f)v2[5].m_quad,
        v10 = v2[6].m_quad.m128_u32[0],
        v10 != -1) )
  {
    callback.vfptr = (hkaiPathfindingUtil::NearestFeatureCallbackVtbl *)&UFG::FleeTraversalNearestFeatureCallback::`vftable';
    v32 = UFG::qVector3::msZero.x;
    input.m_startFaceKey = LODWORD(UFG::qVector3::msZero.y);
    *(&input.m_startFaceKey + 1) = LODWORD(UFG::qVector3::msZero.z);
    v29 = 0;
    v30.m_quad = (__m128)input.m_startPoint;
    v11 = v2[7].m_quad.m128_f32[0] * 0.2;
    if ( v11 >= 10.0 )
      v11 = FLOAT_10_0;
    v12 = UFG::qRandom(v11, &UFG::qDefaultSeed);
    v31 = (float)(v2[7].m_quad.m128_f32[0] - v12) * (float)(v2[7].m_quad.m128_f32[0] - v12);
    v36 = 0x1FFFF;
    v37 = 1;
    v35 = &UFG::FleeTraversalCostModifier::`vftable';
    v38 = 0;
    v42 = FLOAT_5000_0;
    v41 = v31;
    if ( v2[7].m_quad.m128_f32[1] >= 0.0 )
      v42 = v2[7].m_quad.m128_f32[1];
    v13 = 0;
    v14 = v2[7].m_quad.m128_f32[2];
    if ( v14 != 0.0 )
    {
      v15 = v2[8].m_quad.m128_u64[0];
      do
      {
        v16 = (unsigned int *)(v15 + 80i64 * v13);
        v17 = 8i64 * v38++;
        *(__int128 *)((char *)&v39 + v17 * 4) = (__int128)_mm_unpacklo_ps(
                                                            _mm_unpacklo_ps((__m128)v16[2], (__m128)v16[4]),
                                                            _mm_unpacklo_ps((__m128)v16[3], (__m128)0i64));
        v40[v17] = v16[16];
        ++v13;
      }
      while ( v13 < LODWORD(v14) );
    }
    input.m_agentInfo.m_filterInfo = *(_DWORD *)(v2[2].m_quad.m128_u64[0] + 4);
    input.m_startFaceKey = v10;
    v18 = 512;
    if ( v2[8].m_quad.m128_i32[2] >= 0 )
      v18 = v2[8].m_quad.m128_i32[2];
    input.m_maxNumberOfIterations = v18;
    input.m_bufferSizes.m_maxOpenSetSizeBytes = 0x2000;
    input.m_bufferSizes.m_maxSearchStateSizeBytes = 37376;
    input.m_searchRadius = FLOAT_500_0;
    input.m_costModifier = (hkaiAstarCostModifier *)&v35;
    input.m_up.m_quad = _mm_unpacklo_ps(
                          _mm_unpacklo_ps(
                            (__m128)LODWORD(UFG::qVector3::msAxisZ.x),
                            (__m128)LODWORD(UFG::qVector3::msAxisZ.z)),
                          _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msAxisZ.y), (__m128)0i64));
    v23 = 0x1FFFF;
    v24 = 1;
    v22 = &hkaiUFGAStarEdgeFilter::`vftable';
    input.m_edgeFilter = (hkaiAstarEdgeFilter *)&v22;
    hkaiPathfindingUtil::findNearestEdges((hkaiStreamingCollection *)v8->LowHealthDefrag, &input, &callback, 0i64);
    if ( v29
      && (v19 = input.m_startFaceKey,
          v20 = *(&input.m_startFaceKey + 1),
          v7[2].m_quad.m128_f32[2] = v32,
          v7[2].m_quad.m128_i32[3] = v19,
          v7[3].m_quad.m128_i32[0] = v20,
          v7[3].m_quad.m128_i8[8] = 0,
          (*(void (__fastcall **)(hkVector4f *))v7[2].m_quad.m128_u64[0])(v7 + 2),
          (*(unsigned __int8 (__fastcall **)(hkVector4f *))(v7[2].m_quad.m128_u64[0] + 32))(v7 + 2)) )
    {
      (*(void (__fastcall **)(hkVector4f *, int *))(v7[2].m_quad.m128_u64[0] + 40))(v7 + 2, &v25);
      v7[2].m_quad.m128_i32[2] = v25;
      v7[2].m_quad.m128_i32[3] = v26;
      v7[3].m_quad.m128_i32[0] = v27;
      v7[3].m_quad.m128_i8[8] = 0;
      v7[1].m_quad.m128_i32[0] = (UFG::HavokAIUtilGame::FindMeshPositionAwayFromWall(v7 + 4, &hkvNewPosition, 0.38) != 0)
                               + 3;
    }
    else
    {
      v7[1].m_quad.m128_i32[0] = 4;
    }
    v21 = *(_BYTE *)(v3 + 80);
    if ( v21 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v21 - 1;
    }
    else
    {
      *(_BYTE *)(v3 + 80) = 0;
      *(_DWORD *)v3 = 3;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_QWORD *)(v3 + 48) = 0i64;
    }
  }
  else
  {
    v7[1].m_quad.m128_i32[0] = 4;
    v9 = *(_BYTE *)(v3 + 80);
    if ( v9 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v9 - 1;
    }
    else
    {
      *(_BYTE *)(v3 + 80) = 0;
      *(_DWORD *)v3 = 3;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_QWORD *)(v3 + 48) = 0i64;
    }
  }
}

// File Line: 1021
// RVA: 0xF11A0
void __fastcall UFG::HavokNavDaemon::SpawnTraversalImmediate(UFG::HavokNavDaemon *this, UFG::SpawnTraversalImmediateQuery *queryInput)
{
  hkVector4f *v2; // rdi
  signed __int64 v3; // rbx
  char v4; // r8
  __int64 v5; // rax
  char v6; // cl
  hkVector4f *v7; // rsi
  UFG::NavManagerVtbl *v8; // r14
  char v9; // al
  unsigned int v10; // edx
  int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  char v14; // al
  void **v15; // [rsp+20h] [rbp-E0h]
  int v16; // [rsp+28h] [rbp-D8h]
  char v17; // [rsp+30h] [rbp-D0h]
  int v18; // [rsp+38h] [rbp-C8h]
  int v19; // [rsp+3Ch] [rbp-C4h]
  int v20; // [rsp+40h] [rbp-C0h]
  hkaiPathfindingUtil::NearestFeatureCallback callback; // [rsp+50h] [rbp-B0h]
  hkVector4f v22; // [rsp+60h] [rbp-A0h]
  float v23; // [rsp+70h] [rbp-90h]
  UFG::qVector3 v24; // [rsp+74h] [rbp-8Ch]
  char v25; // [rsp+80h] [rbp-80h]
  void **v26; // [rsp+90h] [rbp-70h]
  int v27; // [rsp+98h] [rbp-68h]
  char v28; // [rsp+A0h] [rbp-60h]
  float v29; // [rsp+C0h] [rbp-40h]
  hkVector4f v30; // [rsp+D0h] [rbp-30h]
  __m128 v31; // [rsp+E0h] [rbp-20h]
  __int64 v32; // [rsp+F0h] [rbp-10h]
  hkaiPathfindingUtil::NearestFeatureInput input; // [rsp+100h] [rbp+0h]
  hkVector4f hkvNewPosition; // [rsp+170h] [rbp+70h]

  v32 = -2i64;
  v2 = (hkVector4f *)queryInput;
  v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v4 = ++*(_BYTE *)(v3 + 80);
  v5 = v4;
  *(_DWORD *)(v3 + 4 * v5) = 1;
  *(_QWORD *)(v3 + 8 * v5 + 16) = "AI::HavokNavDaemon::SpawnTraversalImmediate";
  *(_QWORD *)(v3 + 8 * v5 + 48) = 0i64;
  v6 = *(_BYTE *)(v3 + 81);
  if ( v4 > v6 )
    v6 = v4;
  *(_BYTE *)(v3 + 81) = v6;
  v7 = (hkVector4f *)queryInput->m_pOutput;
  v8 = UFG::NavManager::ms_pInstance[3].vfptr;
  if ( hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr)
    && (hkaiPathfindingUtil::NearestFeatureInput::NearestFeatureInput(&input),
        input.m_startPoint = (hkVector4f)v2[5].m_quad,
        v10 = v2[6].m_quad.m128_u32[0],
        v10 != -1) )
  {
    callback.vfptr = (hkaiPathfindingUtil::NearestFeatureCallbackVtbl *)&UFG::SpawnTraversalNearestFeatureCallback::`vftable';
    v24 = UFG::qVector3::msZero;
    v25 = 0;
    v22.m_quad = (__m128)input.m_startPoint;
    v23 = v2[7].m_quad.m128_f32[3] * v2[7].m_quad.m128_f32[3];
    v27 = 0x1FFFF;
    v28 = 1;
    v26 = &UFG::SpawnTraversalCostModifier::`vftable';
    v29 = FLOAT_5000_0;
    v30.m_quad = 0i64;
    v31 = (__m128)_xmm;
    if ( v2[8].m_quad.m128_f32[0] >= 0.0 )
      v29 = v2[8].m_quad.m128_f32[0];
    v30.m_quad = (__m128)input.m_startPoint;
    v31 = _mm_unpacklo_ps(
            _mm_unpacklo_ps((__m128)v2[7].m_quad.m128_u32[0], (__m128)v2[7].m_quad.m128_u32[2]),
            _mm_unpacklo_ps((__m128)v2[7].m_quad.m128_u32[1], (__m128)0i64));
    input.m_agentInfo.m_filterInfo = *(_DWORD *)(v2[2].m_quad.m128_u64[0] + 4);
    input.m_startFaceKey = v10;
    v11 = 512;
    if ( v2[8].m_quad.m128_i32[1] >= 0 )
      v11 = v2[8].m_quad.m128_i32[1];
    input.m_maxNumberOfIterations = v11;
    input.m_bufferSizes.m_maxOpenSetSizeBytes = 0x2000;
    input.m_bufferSizes.m_maxSearchStateSizeBytes = 37376;
    input.m_searchRadius = FLOAT_500_0;
    input.m_costModifier = (hkaiAstarCostModifier *)&v26;
    input.m_up.m_quad = _mm_unpacklo_ps(
                          _mm_unpacklo_ps(
                            (__m128)LODWORD(UFG::qVector3::msAxisZ.x),
                            (__m128)LODWORD(UFG::qVector3::msAxisZ.z)),
                          _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msAxisZ.y), (__m128)0i64));
    v16 = 0x1FFFF;
    v17 = 1;
    v15 = &hkaiUFGAStarEdgeFilter::`vftable';
    input.m_edgeFilter = (hkaiAstarEdgeFilter *)&v15;
    hkaiPathfindingUtil::findNearestEdges((hkaiStreamingCollection *)v8->LowHealthDefrag, &input, &callback, 0i64);
    if ( v25
      && (v12 = v24.y,
          v13 = v24.z,
          v7[2].m_quad.m128_i32[2] = LODWORD(v24.x),
          v7[2].m_quad.m128_f32[3] = v12,
          v7[3].m_quad.m128_f32[0] = v13,
          v7[3].m_quad.m128_i8[8] = 0,
          (*(void (__fastcall **)(hkVector4f *))v7[2].m_quad.m128_u64[0])(v7 + 2),
          (*(unsigned __int8 (__fastcall **)(hkVector4f *))(v7[2].m_quad.m128_u64[0] + 32))(v7 + 2)) )
    {
      (*(void (__fastcall **)(hkVector4f *, int *))(v7[2].m_quad.m128_u64[0] + 40))(v7 + 2, &v18);
      v7[2].m_quad.m128_i32[2] = v18;
      v7[2].m_quad.m128_i32[3] = v19;
      v7[3].m_quad.m128_i32[0] = v20;
      v7[3].m_quad.m128_i8[8] = 0;
      v7[1].m_quad.m128_i32[0] = (UFG::HavokAIUtilGame::FindMeshPositionAwayFromWall(v7 + 4, &hkvNewPosition, 0.38) != 0)
                               + 3;
    }
    else
    {
      v7[1].m_quad.m128_i32[0] = 4;
    }
    v14 = *(_BYTE *)(v3 + 80);
    if ( v14 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v14 - 1;
    }
    else
    {
      *(_BYTE *)(v3 + 80) = 0;
      *(_DWORD *)v3 = 3;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_QWORD *)(v3 + 48) = 0i64;
    }
  }
  else
  {
    v7[1].m_quad.m128_i32[0] = 4;
    v9 = *(_BYTE *)(v3 + 80);
    if ( v9 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v9 - 1;
    }
    else
    {
      *(_BYTE *)(v3 + 80) = 0;
      *(_DWORD *)v3 = 3;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_QWORD *)(v3 + 48) = 0i64;
    }
  }
}

// File Line: 1132
// RVA: 0xED1C0
char __fastcall UFG::HavokNavDaemon::GetPathFromHavok(UFG::HavokNavDaemon *this, UFG::NavPath *navPath, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathOut, hkArray<unsigned int,hkContainerHeapAllocator> *visitedEdges)
{
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *v4; // r14
  UFG::HavokNavDaemon *v5; // r13
  bool isDropDown; // r12
  unsigned int v7; // er15
  __int64 v8; // rbx
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm8_4
  float v12; // xmm9_4
  float v13; // xmm10_4
  float v14; // xmm11_4
  hkaiPath::PathPoint *v15; // rsi
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  signed __int64 v19; // rdi
  char v20; // dl
  __int64 v21; // rax
  char v22; // cl
  char v23; // al
  bool v24; // si
  char v25; // al
  char *v26; // rax
  char v27; // r12
  hkaiPath::PathPoint *v28; // rcx
  char v29; // al
  _QWORD *v30; // rax
  signed __int64 v31; // rdx
  char v32; // al
  UFG::qVector3 vStartEdgeB; // [rsp+38h] [rbp-90h]
  UFG::qVector3 vStartEdgeA; // [rsp+48h] [rbp-80h]
  float v36; // [rsp+54h] [rbp-74h]
  float v37; // [rsp+58h] [rbp-70h]
  float v38; // [rsp+5Ch] [rbp-6Ch]
  UFG::qVector3 vPosition; // [rsp+60h] [rbp-68h]
  float v40; // [rsp+6Ch] [rbp-5Ch]
  UFG::qVector3 vEndEdgeA; // [rsp+70h] [rbp-58h]
  float v42; // [rsp+7Ch] [rbp-4Ch]
  __int64 v43; // [rsp+80h] [rbp-48h]
  UFG::NavWaypoint v44; // [rsp+88h] [rbp-40h]
  UFG::NavWaypoint item; // [rsp+D8h] [rbp+10h]
  char v46; // [rsp+1F8h] [rbp+130h]
  __int64 v47; // [rsp+200h] [rbp+138h]
  char *v48; // [rsp+208h] [rbp+140h]

  v43 = -2i64;
  v4 = pathOut;
  v5 = this;
  ((void (__fastcall *)(UFG::HavokNavDaemon *, UFG::NavPath *, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *, hkArray<unsigned int,hkContainerHeapAllocator> *))this->vfptr[2].CancelQueueableQuery)(
    this,
    navPath,
    pathOut,
    visitedEdges);
  isDropDown = 0;
  LOBYTE(v48) = 0;
  v7 = 0;
  if ( v4->m_size > 0 )
  {
    v8 = 0i64;
    v9 = vStartEdgeA.z;
    v10 = vStartEdgeA.y;
    v11 = vStartEdgeA.x;
    v12 = vStartEdgeB.z;
    v13 = vStartEdgeB.y;
    v14 = vStartEdgeB.x;
    do
    {
      v15 = v4->m_data;
      if ( !v4->m_data[v8].m_flags.m_storage && v15[v8].m_userEdgeData == 0x80000000 )
        return 1;
      v16 = v15[v8].m_position.m_quad.m128_f32[0];
      v17 = v15[v8].m_position.m_quad.m128_f32[1];
      v18 = v15[v8].m_position.m_quad.m128_f32[2];
      vPosition.z = v15[v8].m_position.m_quad.m128_f32[0];
      v40 = v17;
      vEndEdgeA.x = v18;
      v19 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
      v20 = ++*(_BYTE *)(v19 + 80);
      v21 = v20;
      *(_DWORD *)(v19 + 4 * v21) = 1;
      *(_QWORD *)(v19 + 8 * v21 + 16) = "AI::HavokNavDaemon::GetPathFromHavok";
      *(_QWORD *)(v19 + 8 * v21 + 48) = 0i64;
      v22 = *(_BYTE *)(v19 + 81);
      if ( v20 > v22 )
        v22 = v20;
      *(_BYTE *)(v19 + 81) = v22;
      v46 = 0;
      v23 = v15[v8].m_flags.m_storage;
      if ( v23 & 1 )
      {
        if ( !((unsigned __int8 (__fastcall *)(UFG::HavokNavDaemon *, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *, _QWORD, float *, float *))v5->vfptr[3].SubmitImmediateQuery)(
                v5,
                v4,
                v7,
                &vEndEdgeA.z,
                &v37) )
          goto LABEL_31;
        v24 = (v15[v8].m_userEdgeData & 3) == 2;
        v25 = 1;
        v11 = vEndEdgeA.z;
        vStartEdgeA.x = vEndEdgeA.z;
        v10 = v42;
        vStartEdgeA.y = v42;
        v9 = vEndEdgeA.z;
        vStartEdgeA.z = vEndEdgeA.z;
        v14 = v37;
        vStartEdgeB.x = v37;
        v13 = v38;
        vStartEdgeB.y = v38;
        v12 = vPosition.x;
        vStartEdgeB.z = vPosition.x;
      }
      else
      {
        if ( !(v23 & 2) )
        {
          v27 = 1;
          if ( (signed int)(v7 + 1) < v4->m_size )
          {
            if ( v4->m_data[v8 + 1].m_flags.m_storage & 1 )
            {
              v27 = 1;
              v28 = v4->m_data;
              if ( (float)((float)((float)((float)(v28[v8 + 1].m_position.m_quad.m128_f32[1] - v17)
                                         * (float)(v28[v8 + 1].m_position.m_quad.m128_f32[1] - v17))
                                 + (float)((float)(v28[v8 + 1].m_position.m_quad.m128_f32[0] - v16)
                                         * (float)(v28[v8 + 1].m_position.m_quad.m128_f32[0] - v16)))
                         + (float)((float)(v28[v8 + 1].m_position.m_quad.m128_f32[2] - v18)
                                 * (float)(v28[v8 + 1].m_position.m_quad.m128_f32[2] - v18))) < 0.040000003 )
                v27 = 0;
            }
          }
          UFG::NavWaypoint::NavWaypoint(&v44, (UFG::qVector3 *)((char *)&vPosition + 8), 0i64);
          if ( v15[v8].m_position.m_quad.m128_f32[3] >= 1000.0 )
          {
            v44.m_canSmooth = 0;
            goto LABEL_23;
          }
          if ( v27 )
LABEL_23:
            UFG::qArray<UFG::NavWaypoint,0>::Add((UFG::qArray<UFG::NavWaypoint,0> *)(v47 + 8), &v44, "qArray.Add");
          _((AMD_HD3D *)&v44);
          v24 = 0;
          v25 = 0;
          goto LABEL_26;
        }
        if ( !((unsigned __int8 (__fastcall *)(UFG::HavokNavDaemon *, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *, _QWORD, UFG::qVector3 *, UFG::qVector3 *))v5->vfptr[3].SubmitImmediateQuery)(
                v5,
                v4,
                v7,
                &vPosition,
                &vEndEdgeA) )
        {
LABEL_31:
          v30 = NtCurrentTeb()->Reserved1[11];
          v31 = v30[tls_index] + 16i64;
          v32 = *(_BYTE *)(v30[tls_index] + 96i64);
          if ( v32 > 0 )
          {
            *(_BYTE *)(v31 + 80) = v32 - 1;
          }
          else
          {
            *(_BYTE *)(v31 + 80) = 0;
            *(_DWORD *)v31 = 3;
            *(_QWORD *)(v31 + 16) = 0i64;
            *(_QWORD *)(v31 + 48) = 0i64;
          }
          return 0;
        }
        v24 = isDropDown;
        if ( (_BYTE)v48 )
        {
          v26 = UFG::qMalloc(0xA0ui64, "AI::GetPathFromHavok:NavObjectParkour", 0i64);
          v48 = v26;
          if ( v26 )
            UFG::NavObjectParkour::NavObjectParkour(
              (UFG::NavObjectParkour *)v26,
              &vStartEdgeA,
              &vStartEdgeB,
              &vEndEdgeA,
              &vPosition,
              isDropDown);
          vStartEdgeA.z = (float)(v14 + v11) * 0.5;
          v36 = (float)(v13 + v10) * 0.5;
          v37 = (float)(v12 + v9) * 0.5;
          UFG::NavWaypoint::NavWaypoint(&item, (UFG::qVector3 *)((char *)&vStartEdgeA + 8), (UFG::NavObject *)v26);
          UFG::qArray<UFG::NavWaypoint,0>::Add((UFG::qArray<UFG::NavWaypoint,0> *)(v47 + 8), &item, "qArray.Add");
          _((AMD_HD3D *)&item);
        }
        v25 = v46;
      }
LABEL_26:
      isDropDown = v24;
      LOBYTE(v48) = v25;
      v29 = *(_BYTE *)(v19 + 80);
      if ( v29 > 0 )
      {
        *(_BYTE *)(v19 + 80) = v29 - 1;
      }
      else
      {
        *(_BYTE *)(v19 + 80) = 0;
        *(_DWORD *)v19 = 3;
        *(_QWORD *)(v19 + 16) = 0i64;
        *(_QWORD *)(v19 + 48) = 0i64;
      }
      ++v7;
      ++v8;
    }
    while ( (signed int)v7 < v4->m_size );
  }
  return 1;
}

// File Line: 1259
// RVA: 0xE8240
void __fastcall UFG::HavokNavDaemon::BatchDeferredPathJobs(UFG::HavokNavDaemon *this)
{
  UFG::HavokNavDaemon *v1; // rbx
  signed int v2; // er14
  UFG::NavManager *v3; // rsi
  float v4; // xmm0_4
  unsigned int v5; // er8
  signed __int64 v6; // r10
  char v7; // dl
  __int64 v8; // rax
  __int64 v9; // r12
  char v10; // cl
  int v11; // er13
  UFG::DaemonType v12; // er14
  __int64 v13; // r15
  signed __int64 v14; // rcx
  __int64 v15; // rdi
  __int64 v16; // rsi
  unsigned int v17; // er12
  hkaiDynamicNavMeshQueryMediator *v18; // rax
  hkVector4f v19; // xmm1
  hkVector4f v20; // xmm2
  unsigned int v21; // er8
  unsigned int v22; // ecx
  hkaiNavMeshAStarCommand *v23; // rdx
  signed __int64 v24; // r9
  unsigned int v25; // ecx
  signed int v26; // eax
  UFG::HavokNavDaemon::PathOutputEntry *v27; // rcx
  UFG::NavPath *v28; // rdi
  __int64 v29; // rcx
  bool v30; // zf
  void (__fastcall *v31)(UFG::NavManager *); // rax
  __m128 v32; // xmm1
  __m128i v33; // xmm2
  unsigned int v34; // edi
  int v35; // ecx
  __int64 v36; // r15
  UFG::DaemonQueryInput *v37; // rdi
  UFG::DaemonQueryOutput *v38; // rsi
  unsigned int v39; // xmm1_4
  UFG::QueryExecutionMode v40; // xmm2_4
  int v41; // xmm1_4
  UFG::QueryExecutionMode v42; // xmm2_4
  UFG::DaemonManager *v43; // rax
  __int64 v44; // rax
  UFG::DaemonQueryOutputVtbl *v45; // rcx
  __int64 v46; // rcx
  unsigned int v47; // eax
  __int64 v48; // r9
  UFG::DaemonQueryInput **v49; // rt1
  signed int v50; // edx
  signed __int64 v51; // r8
  unsigned int v52; // eax
  char v53; // al
  UFG::DaemonQueryOutput output; // [rsp+20h] [rbp-E0h]
  __int64 v55; // [rsp+38h] [rbp-C8h]
  __int64 v56; // [rsp+40h] [rbp-C0h]
  __int64 v57; // [rsp+48h] [rbp-B8h]
  hkJob job; // [rsp+50h] [rbp-B0h]
  __int128 v59; // [rsp+60h] [rbp-A0h]
  int v60; // [rsp+70h] [rbp-90h]
  __int16 v61; // [rsp+74h] [rbp-8Ch]
  UFG::NavManager *v62; // [rsp+78h] [rbp-88h]
  UFG::NavManager *v63; // [rsp+80h] [rbp-80h]
  int v64; // [rsp+88h] [rbp-78h]
  __int16 v65; // [rsp+8Ch] [rbp-74h]
  char v66; // [rsp+8Eh] [rbp-72h]
  __int128 v67; // [rsp+90h] [rbp-70h]
  float v68; // [rsp+A0h] [rbp-60h]
  __int64 v69; // [rsp+A4h] [rbp-5Ch]
  __int64 v70; // [rsp+ACh] [rbp-54h]
  UFG::DaemonType v71; // [rsp+B8h] [rbp-48h]
  int v72; // [rsp+BCh] [rbp-44h]
  __int64 v73; // [rsp+C0h] [rbp-40h]
  hkaiNavMeshAStarCommand *v74; // [rsp+C8h] [rbp-38h]
  __int128 v75; // [rsp+D0h] [rbp-30h]
  UFG::QueryExecutionMode v76; // [rsp+E0h] [rbp-20h]
  int v77; // [rsp+E4h] [rbp-1Ch]
  UFG::DaemonQueryInputVtbl *v78; // [rsp+F0h] [rbp-10h]
  UFG::DaemonType v79; // [rsp+F8h] [rbp-8h]
  UFG::NavManager *v80; // [rsp+100h] [rbp+0h]
  __int64 v81; // [rsp+108h] [rbp+8h]
  unsigned int meshUid; // [rsp+170h] [rbp+70h]
  signed __int64 v83; // [rsp+178h] [rbp+78h]
  unsigned int v84; // [rsp+180h] [rbp+80h]
  __int64 v85; // [rsp+188h] [rbp+88h]

  v81 = -2i64;
  v1 = this;
  v2 = this->m_PathRequests.size;
  v84 = v2;
  if ( v2 )
  {
    v3 = UFG::NavManager::ms_pInstance;
    v80 = UFG::NavManager::ms_pInstance;
    if ( hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr) )
    {
      v4 = (float)v2;
      if ( (float)v2 >= 16.0 )
        v4 = FLOAT_16_0;
      v5 = (signed int)v4;
      v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
      v56 = v6;
      v7 = ++*(_BYTE *)(v6 + 80);
      v8 = v7;
      *(_DWORD *)(v6 + 4 * v8) = 1;
      *(_QWORD *)(v6 + 8 * v8 + 16) = "AI::HavokNavDaemon::BatchDeferredPathJobs";
      LODWORD(v9) = 0;
      *(_QWORD *)(v6 + 8 * v8 + 48) = 0i64;
      v10 = *(_BYTE *)(v6 + 81);
      if ( v7 > v10 )
        v10 = v7;
      *(_BYTE *)(v6 + 81) = v10;
      v11 = 0;
      if ( UFG::HavokNavManager::ms_bEnablePathfindingMT )
      {
        v12 = 0;
        if ( !v5 )
          goto LABEL_37;
        v83 = 0i64;
        v13 = 0i64;
        v14 = 0i64;
        v85 = 0i64;
        v57 = v5;
        while ( 1 )
        {
          v15 = *(__int64 *)((char *)v1->m_PathRequests.p + v14);
          v16 = *(_QWORD *)(v15 + 24);
          if ( !*(_BYTE *)(v15 + 56) )
            goto LABEL_26;
          meshUid = *(_DWORD *)(v15 + 84);
          v17 = *(_DWORD *)(v15 + 80);
          if ( v17 != -1 )
          {
            v18 = (hkaiDynamicNavMeshQueryMediator *)hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
            if ( !v18 || !UFG::HavokAIUtilGame::IsFaceKeyValid(v18, v17, meshUid) )
              break;
          }
          if ( !UFG::HavokNavPosition::HasBeenValidated((UFG::HavokNavPosition *)(v15 + 96)) )
            break;
          v19.m_quad = *(__m128 *)(v15 + 64);
          v20.m_quad = *(__m128 *)(v15 + 128);
          v21 = *(_DWORD *)(v15 + 80);
          v22 = *(_DWORD *)(v15 + 144);
          if ( v21 != -1 && v22 != -1 )
          {
            v23 = v1->m_commands.m_data;
            v23[v13].m_startPoint = 0i64;
            v23[v13].m_goalPoint = 0i64;
            *(_QWORD *)&v23[v13].m_startFaceKey = -1i64;
            LODWORD(v9) = 0;
            v23[v13].m_multipleGoalPoints = 0i64;
            v23[v13].m_multipleGoalFaceKeys = 0i64;
            v23[v13].m_numGoals = 0;
            *(_QWORD *)&v23[v13].m_maxNumberOfIterations = 100000i64;
            v23[v13].m_agentInfo.m_filterInfo = 0;
            v23[v13].m_AStarOutput = 0i64;
            v23[v13].m_edgesOut = 0i64;
            v23[v13].m_maxEdgesOut = 0;
            v23[v13].m_pointsOut = 0i64;
            v23[v13].m_maxPointsOut = 0;
            v24 = v83;
            *(hkVector4f *)((char *)v1->m_goals.m_data + v83) = (hkVector4f)v20.m_quad;
            *(unsigned int *)((char *)v1->m_goalFaces.m_data + v83) = v22;
            v23[v13].m_startPoint = (hkVector4f)v19.m_quad;
            v23[v13].m_startFaceKey = v21;
            v25 = *(unsigned int *)((char *)v1->m_goalFaces.m_data + v83);
            v23[v13].m_goalPoint = *(hkVector4f *)((char *)v1->m_goals.m_data + v83);
            v23[v13].m_goalFaceKey = v25;
            v23[v13].m_multipleGoalPoints = 0i64;
            v23[v13].m_multipleGoalFaceKeys = 0i64;
            v23[v13].m_numGoals = 1;
            v23[v13].m_edgesOut = *(unsigned int **)((char *)&v1->m_outputs.m_data->m_data + v83);
            v23[v13].m_maxEdgesOut = *(int *)((char *)&v1->m_outputs.m_data->m_size + v83);
            v23[v13].m_pointsOut = *(hkaiPath::PathPoint **)((char *)&v1->m_smoothedPaths.m_data->m_data + v83);
            v23[v13].m_maxPointsOut = *(int *)((char *)&v1->m_smoothedPaths.m_data->m_size + v83);
            v23[v13].m_AStarOutput = &v1->m_aStarOutputs.m_data[v12];
            v23[v13].m_agentInfo.m_diameter = **(float **)(v15 + 160) * 2.0;
            v23[v13].m_agentInfo.m_filterInfo = *(_DWORD *)(*(_QWORD *)(v15 + 160) + 4i64);
            v26 = 2048;
            if ( *(_DWORD *)(v15 + 168) >= 0 )
              v26 = *(_DWORD *)(v15 + 168);
            v23[v13].m_maxNumberOfIterations = v26;
            output.m_id = v12;
            LOBYTE(output.m_internalType) = 1;
            if ( v1->m_havokResults.m_size == (v1->m_havokResults.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v1->m_havokResults,
                16);
              v24 = v83;
            }
            v27 = &v1->m_havokResults.m_data[v1->m_havokResults.m_size];
            if ( v27 )
            {
              v27->m_pUserOutput = (UFG::FindPathOutput *)v16;
              *(_QWORD *)&v27->m_iHavokDataIndex = *(_QWORD *)&output.m_id;
            }
            ++v1->m_havokResults.m_size;
            ++v12;
            ++v13;
            v83 = v24 + 16;
            goto LABEL_35;
          }
          UFG::NavPathRefPtr::operator=((UFG::NavPathRefPtr *)(v16 + 24), UFG::g_NullPath);
          ++v11;
          LODWORD(v9) = 0;
LABEL_34:
          *(_DWORD *)(v16 + 16) = 4;
LABEL_35:
          v14 = v85 + 8;
          v85 += 8i64;
          if ( !--v57 )
          {
            v3 = v80;
LABEL_37:
            v31 = v3[3].vfptr->LowHealthDefrag;
            *(_WORD *)&job.m_jobSubType = 2305;
            job.m_jobSpuType.m_storage = 1;
            job.m_size = 144;
            job.m_threadAffinity = -1;
            _mm_store_si128((__m128i *)&v59, (__m128i)0i64);
            v62 = 0i64;
            v63 = 0i64;
            v64 = 66305;
            v65 = 1;
            v66 = 1;
            v67 = _xmm_bf8000007f7fffee3c23d70a3f800000;
            v68 = FLOAT_N1_0;
            v69 = 0i64;
            v70 = 0i64;
            v60 = -2147450880;
            v61 = -32768;
            v71 = 100000;
            v74 = 0i64;
            LODWORD(v75) = 0;
            v73 = *((_QWORD *)v31 + 4);
            HIBYTE(v64) = 0;
            v32 = _mm_mul_ps(_xmm, (__m128)xmmword_141A71390);
            v33 = _mm_add_epi32(
                    _mm_xor_si128(
                      _mm_cvttps_epi32(v32),
                      (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v32)),
                    _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset));
            LOWORD(v60) = _mm_extract_epi16(v33, 1);
            HIWORD(v60) = _mm_extract_epi16(v33, 3);
            v61 = _mm_extract_epi16(v33, 5);
            v62 = v3 + 14;
            output.m_id = 0x1FFFF;
            LOBYTE(output.m_status) = 1;
            output.vfptr = (UFG::DaemonQueryOutputVtbl *)&hkaiUFGAStarEdgeFilter::`vftable';
            v63 = v3 + 20;
            v34 = 0;
            if ( v12 )
            {
              do
              {
                v35 = NavDaemonConst::kCommandsPerJob;
                if ( v12 - v34 < NavDaemonConst::kCommandsPerJob )
                  v35 = v12 - v34;
                v74 = &v1->m_commands.m_data[v34];
                LODWORD(v75) = v35;
                hkJobQueue::addJob((hkJobQueue *)v3[10].vfptr, &job, 0);
                v34 += v75;
              }
              while ( v34 < v12 );
            }
            output.vfptr = (UFG::DaemonQueryOutputVtbl *)&hkBaseObject::`vftable';
LABEL_65:
            v6 = v56;
            goto LABEL_66;
          }
        }
        LODWORD(v9) = 0;
LABEL_26:
        v28 = UFG::g_NullPath;
        if ( *(UFG::NavPath **)(v16 + 24) != UFG::g_NullPath )
        {
          if ( UFG::g_NullPath )
            ++UFG::g_NullPath->m_uRefCount;
          v29 = *(_QWORD *)(v16 + 24);
          if ( v29 )
          {
            v30 = (*(_DWORD *)(v29 + 40))-- == 1;
            if ( v30 )
              (**(void (__fastcall ***)(__int64, signed __int64))v29)(v29, 1i64);
          }
          *(_QWORD *)(v16 + 24) = v28;
        }
        ++v11;
        goto LABEL_34;
      }
      v12 = (signed int)v4;
      if ( v5 >= 2 )
        v12 = 2;
      if ( v12 )
      {
        v36 = 0i64;
        v9 = (unsigned int)v12;
        do
        {
          v37 = v1->m_PathRequests.p[v36];
          v38 = v37->m_pOutput;
          UFG::FindPathImmediateQuery::FindPathImmediateQuery((UFG::FindPathImmediateQuery *)&job);
          *(_QWORD *)&output.m_id = 0i64;
          output.m_status = 0;
          output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FindPathOutput::`vftable';
          v55 = 0i64;
          v39 = v37[1].m_internalType;
          v40 = v37[1].m_mode;
          LODWORD(v62) = v37[1].m_daemonType;
          HIDWORD(v62) = v39;
          LODWORD(v63) = v40;
          if ( LOBYTE(v37[1].m_pOutput) )
          {
            LOBYTE(v64) = v37[1].m_pOutput;
            v67 = *(_OWORD *)&v37[2].vfptr;
            v68 = *(float *)&v37[2].m_mode;
            LODWORD(v69) = *((_DWORD *)&v37[2].m_mode + 1);
          }
          else
          {
            LOBYTE(v64) = 0;
          }
          v41 = v37[3].m_internalType;
          v42 = v37[3].m_mode;
          v71 = v37[3].m_daemonType;
          v72 = v41;
          LODWORD(v73) = v42;
          if ( LOBYTE(v37[3].m_pOutput) )
          {
            LOBYTE(v74) = v37[3].m_pOutput;
            v75 = *(_OWORD *)&v37[4].vfptr;
            v76 = v37[4].m_mode;
            v77 = *((_DWORD *)&v37[4].m_mode + 1);
          }
          else
          {
            LOBYTE(v74) = 0;
          }
          v78 = v37[5].vfptr;
          v79 = v37[5].m_daemonType;
          v43 = UFG::DaemonManager::Instance();
          UFG::DaemonManager::SubmitQuery(v43, (UFG::DaemonQueryInput *)&job, &output);
          v44 = v55;
          if ( v38[1].vfptr != (UFG::DaemonQueryOutputVtbl *)v55 )
          {
            if ( v55 )
            {
              ++*(_DWORD *)(v55 + 40);
              v44 = v55;
            }
            v45 = v38[1].vfptr;
            if ( v45 )
            {
              v30 = LODWORD(v45[5].__vecDelDtor)-- == 1;
              if ( v30 )
                (*(void (__fastcall **)(UFG::DaemonQueryOutputVtbl *, signed __int64))v45->__vecDelDtor)(v45, 1i64);
              v44 = v55;
            }
            v38[1].vfptr = (UFG::DaemonQueryOutputVtbl *)v44;
          }
          v38->m_status = output.m_status;
          v46 = v55;
          if ( v55 )
          {
            --*(_DWORD *)(v55 + 40);
            if ( !*(_DWORD *)(v46 + 40) )
              (**(void (__fastcall ***)(__int64, signed __int64))v46)(v46, 1i64);
          }
          output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable';
          *(_QWORD *)&job.m_jobSubType = &UFG::DaemonQueryInput::`vftable';
          ++v36;
          --v9;
        }
        while ( v9 );
        v11 = 0;
        goto LABEL_65;
      }
LABEL_66:
      v47 = v12 + v11;
      if ( v12 + v11 < v84 )
      {
        if ( v47 )
        {
          v48 = v47;
          do
          {
            v49 = v1->m_PathRequests.p;
            v50 = 1;
            if ( v1->m_PathRequests.size != 1 )
            {
              v51 = 1i64;
              do
              {
                v1->m_PathRequests.p[v51 - 1] = v1->m_PathRequests.p[v51];
                ++v50;
                ++v51;
              }
              while ( v50 != v1->m_PathRequests.size );
            }
            v52 = v1->m_PathRequests.size;
            if ( v52 > 1 )
              v1->m_PathRequests.size = v52 - 1;
            else
              v1->m_PathRequests.size = v9;
            --v48;
          }
          while ( v48 );
        }
      }
      else
      {
        v1->m_PathRequests.size = v9;
      }
      v53 = *(_BYTE *)(v6 + 80);
      if ( v53 > 0 )
      {
        *(_BYTE *)(v6 + 80) = v53 - 1;
      }
      else
      {
        *(_BYTE *)(v6 + 80) = 0;
        *(_DWORD *)v6 = 3;
        *(_QWORD *)(v6 + 16) = 0i64;
        *(_QWORD *)(v6 + 48) = 0i64;
      }
    }
  }
}

// File Line: 1429
// RVA: 0xEA040
void __fastcall UFG::HavokNavDaemon::ExecuteDeferredPathJobs(UFG::HavokNavDaemon *this)
{
  signed __int64 v1; // rbx
  char v2; // dl
  __int64 v3; // rax
  char v4; // cl
  UFG::NavManager *v5; // rdx
  char v6; // al

  v1 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v2 = ++*(_BYTE *)(v1 + 80);
  v3 = v2;
  *(_DWORD *)(v1 + 4 * v3) = 1;
  *(_QWORD *)(v1 + 8 * v3 + 16) = "AI::HavokNavDaemon::StartUpdate";
  *(_QWORD *)(v1 + 8 * v3 + 48) = 0i64;
  v4 = *(_BYTE *)(v1 + 81);
  if ( v2 > v4 )
    v4 = v2;
  v5 = UFG::NavManager::ms_pInstance;
  *(_BYTE *)(v1 + 81) = v4;
  (*((void (__fastcall **)(UFG::NavManagerVtbl *, UFG::NavManagerVtbl *, signed __int64))v5[11].vfptr->__vecDelDtor + 11))(
    v5[11].vfptr,
    v5[10].vfptr,
    9i64);
  v6 = *(_BYTE *)(v1 + 80);
  if ( v6 > 0 )
  {
    *(_BYTE *)(v1 + 80) = v6 - 1;
  }
  else
  {
    *(_BYTE *)(v1 + 80) = 0;
    *(_DWORD *)v1 = 3;
    *(_QWORD *)(v1 + 16) = 0i64;
    *(_QWORD *)(v1 + 48) = 0i64;
  }
}

// File Line: 1446
// RVA: 0xF4000
void __fastcall UFG::HavokNavDaemon::WaitForDeferredJobsToFinish(UFG::HavokNavDaemon *this)
{
  signed __int64 v1; // rbx
  char v2; // dl
  __int64 v3; // rax
  char v4; // cl
  UFG::NavManager *v5; // rax
  char v6; // al

  v1 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v2 = ++*(_BYTE *)(v1 + 80);
  v3 = v2;
  *(_DWORD *)(v1 + 4 * v3) = 1;
  *(_QWORD *)(v1 + 8 * v3 + 16) = "AI::HavokNavDaemon::CompleteUpdate";
  *(_QWORD *)(v1 + 8 * v3 + 48) = 0i64;
  v4 = *(_BYTE *)(v1 + 81);
  v5 = UFG::NavManager::ms_pInstance;
  if ( v2 > v4 )
    v4 = v2;
  *(_BYTE *)(v1 + 81) = v4;
  (*((void (**)(void))v5[11].vfptr->__vecDelDtor + 4))();
  v6 = *(_BYTE *)(v1 + 80);
  if ( v6 > 0 )
  {
    *(_BYTE *)(v1 + 80) = v6 - 1;
  }
  else
  {
    *(_BYTE *)(v1 + 80) = 0;
    *(_DWORD *)v1 = 3;
    *(_QWORD *)(v1 + 16) = 0i64;
    *(_QWORD *)(v1 + 48) = 0i64;
  }
}

// File Line: 1455
// RVA: 0xF0180
void __fastcall UFG::HavokNavDaemon::ReadDeferredPathJobs(UFG::HavokNavDaemon *this)
{
  UFG::HavokNavDaemon *v1; // rsi
  unsigned int v2; // er8
  signed __int64 v3; // r14
  char v4; // dl
  __int64 v5; // rax
  char v6; // cl
  __int64 v7; // r15
  __int64 v8; // rbp
  UFG::HavokNavDaemon::PathOutputEntry *v9; // rax
  UFG::FindPathOutput *v10; // rdi
  __int64 v11; // rcx
  signed __int64 v12; // r8
  hkaiAstarOutputParameters *v13; // rdx
  int v14; // ecx
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *v15; // r12
  hkArray<unsigned int,hkContainerHeapAllocator> *v16; // r13
  char *v17; // rax
  char *v18; // rbx
  UFG::NavPath *v19; // rcx
  bool v20; // zf
  char v21; // al
  signed __int64 v22; // [rsp+20h] [rbp-48h]

  v22 = -2i64;
  v1 = this;
  if ( UFG::HavokNavManager::ms_bEnablePathfindingMT )
  {
    v2 = this->m_havokResults.m_size;
    if ( v2 )
    {
      v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
      v4 = ++*(_BYTE *)(v3 + 80);
      v5 = v4;
      *(_DWORD *)(v3 + 4 * v5) = 1;
      *(_QWORD *)(v3 + 8 * v5 + 16) = "AI::HavokNavDaemon::ReadDeferredPathJobs";
      *(_QWORD *)(v3 + 8 * v5 + 48) = 0i64;
      v6 = *(_BYTE *)(v3 + 81);
      if ( v4 > v6 )
        v6 = v4;
      *(_BYTE *)(v3 + 81) = v6;
      if ( v2 )
      {
        v7 = 0i64;
        v8 = v2;
        do
        {
          v9 = v1->m_havokResults.m_data;
          v10 = v9[v7].m_pUserOutput;
          v11 = *(_QWORD *)&v9[v7].m_iHavokDataIndex;
          if ( (unsigned __int8)(*(_QWORD *)&v9[v7].m_iHavokDataIndex >> 32) )
          {
            v12 = (signed int)v11;
            v13 = v1->m_aStarOutputs.m_data;
            v14 = v13[v12].m_numIterations;
            if ( v1->m_maxIterationsStat > v14 )
              v14 = v1->m_maxIterationsStat;
            v1->m_maxIterationsStat = v14;
            if ( v13[v12].m_status.m_storage == 1 )
            {
              v15 = &v1->m_smoothedPaths.m_data[v12];
              v16 = &v1->m_outputs.m_data[v12];
              v17 = UFG::qMalloc(0x30ui64, "AI::ReadDeferredPathJobs:NavPath", 0i64);
              v18 = v17;
              if ( v17 )
              {
                *(_QWORD *)v17 = &UFG::NavPath::`vftable';
                *((_QWORD *)v17 + 2) = 0i64;
                *((_QWORD *)v17 + 1) = 0i64;
                *((_QWORD *)v17 + 4) = 0i64;
                *((_QWORD *)v17 + 3) = 0i64;
                *((_DWORD *)v17 + 10) = 0;
              }
              else
              {
                v18 = 0i64;
              }
              if ( (char *)v10->m_pPath.m_pNavPath != v18 )
              {
                if ( v18 )
                  ++*((_DWORD *)v18 + 10);
                v19 = v10->m_pPath.m_pNavPath;
                if ( v19 )
                {
                  v20 = v19->m_uRefCount-- == 1;
                  if ( v20 )
                    v19->vfptr->__vecDelDtor(v19, 1u);
                }
                v10->m_pPath.m_pNavPath = (UFG::NavPath *)v18;
              }
              v10->m_status = 4
                            - (((unsigned __int8 (__fastcall *)(UFG::HavokNavDaemon *, UFG::NavPath *, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *, hkArray<unsigned int,hkContainerHeapAllocator> *, signed __int64))v1->vfptr[2].SubmitImmediateQuery)(
                                 v1,
                                 v10->m_pPath.m_pNavPath,
                                 v15,
                                 v16,
                                 v22) != 0);
            }
            else
            {
              v10->m_status = 4;
            }
          }
          ++v7;
          --v8;
        }
        while ( v8 );
      }
      v1->m_havokResults.m_size = 0;
      v21 = *(_BYTE *)(v3 + 80);
      if ( v21 > 0 )
      {
        *(_BYTE *)(v3 + 80) = v21 - 1;
      }
      else
      {
        *(_BYTE *)(v3 + 80) = 0;
        *(_DWORD *)v3 = 3;
        *(_QWORD *)(v3 + 16) = 0i64;
        *(_QWORD *)(v3 + 48) = 0i64;
      }
    }
  }
}      *(_DWORD *)v3 = 3;
        *(_QWORD *)(v3 + 16) = 0i64;
        *(_QWOR

