// File Line: 41
// RVA: 0xE3CB0
void __fastcall UFG::HavokNavDaemon::HavokNavDaemon(UFG::HavokNavDaemon *this)
{
  hkArray<hkArray<unsigned int,hkContainerHeapAllocator>,hkContainerHeapAllocator> *p_m_outputs; // r13
  hkArray<hkaiAstarOutputParameters,hkContainerHeapAllocator> *p_m_aStarOutputs; // r15
  hkArray<hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator>,hkContainerHeapAllocator> *p_m_smoothedPaths; // r12
  __int64 v5; // rbx
  char v6; // dl
  char v7; // cl
  __int64 v8; // rsi
  int v9; // r9d
  int v10; // eax
  __int64 v11; // r14
  int *v12; // rdi
  int v13; // ecx
  __int64 v14; // rdx
  int v15; // eax
  __int64 v16; // r8
  char v17; // al
  char v18; // dl
  char v19; // cl
  int v20; // r9d
  __int64 m_size; // rax
  int v22; // ecx
  __int64 v23; // rax
  int v24; // edx
  __int64 v25; // r8
  __int64 v26; // rax
  char v27; // al
  char v28; // dl
  char v29; // cl
  int v30; // r9d
  int v31; // eax
  __int64 v32; // r14
  int *v33; // rdi
  int v34; // ecx
  __int64 v35; // rdx
  int v36; // eax
  __int64 v37; // r8
  char v38; // al
  char v39; // dl
  char v40; // cl
  int v41; // r9d
  int v42; // ecx
  hkaiNavMeshAStarCommand *v43; // rdx
  int v44; // eax
  __int64 v45; // r8
  char v46; // al
  char v47; // dl
  char v48; // cl
  int v49; // r9d
  char v50; // al
  char v51; // dl
  char v52; // cl
  int v53; // r9d
  char v54; // al
  char v55; // dl
  char v56; // cl
  int v57; // r9d
  char v58; // al
  char v59; // dl
  char v60; // cl
  __int64 v61; // r14
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *v62; // rdi
  int v63; // r9d
  int v64; // ecx
  int v65; // edx
  hkArray<unsigned int,hkContainerHeapAllocator> *v66; // rdi
  int v67; // r9d
  char v68; // al
  hkResult result; // [rsp+A8h] [rbp+50h] BYREF
  __int64 v71; // [rsp+B0h] [rbp+58h]
  __int64 v72; // [rsp+B8h] [rbp+60h] BYREF

  UFG::Daemon::Daemon(this, DaemonType_Navigation, Stage_1, 5u);
  this->vfptr = (UFG::DaemonVtbl *)&UFG::HavokNavDaemon::`vftable;
  this->m_PathRequests.p = 0i64;
  *(_QWORD *)&this->m_PathRequests.size = 0i64;
  p_m_outputs = &this->m_outputs;
  this->m_outputs.m_data = 0i64;
  this->m_outputs.m_size = 0;
  this->m_outputs.m_capacityAndFlags = 0x80000000;
  p_m_aStarOutputs = &this->m_aStarOutputs;
  this->m_aStarOutputs.m_data = 0i64;
  this->m_aStarOutputs.m_size = 0;
  this->m_aStarOutputs.m_capacityAndFlags = 0x80000000;
  p_m_smoothedPaths = &this->m_smoothedPaths;
  this->m_smoothedPaths.m_data = 0i64;
  this->m_smoothedPaths.m_size = 0;
  this->m_smoothedPaths.m_capacityAndFlags = 0x80000000;
  this->m_commands.m_data = 0i64;
  this->m_commands.m_size = 0;
  this->m_commands.m_capacityAndFlags = 0x80000000;
  this->m_goals.m_data = 0i64;
  this->m_goals.m_size = 0;
  this->m_goals.m_capacityAndFlags = 0x80000000;
  this->m_goalFaces.m_data = 0i64;
  this->m_goalFaces.m_size = 0;
  this->m_goalFaces.m_capacityAndFlags = 0x80000000;
  this->m_havokResults.m_data = 0i64;
  this->m_havokResults.m_size = 0;
  this->m_havokResults.m_capacityAndFlags = 0x80000000;
  this->m_maxIterationsStat = 0;
  UFG::Daemon::RegisterQueueableQueryType(this, 0, &this->m_PathRequests);
  UFG::Daemon::RegisterQueueableQueryType(this, 1u, &this->m_PathRequests);
  UFG::Daemon::RegisterQueueableQueryType(this, 2u, &this->m_PathRequests);
  UFG::Daemon::RegisterQueueableQueryType(this, 3u, &this->m_PathRequests);
  UFG::Daemon::RegisterQueueableQueryType(this, 4u, &this->m_PathRequests);
  v5 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v6 = ++*(_BYTE *)(v5 + 80);
  *(_DWORD *)(v5 + 4i64 * v6) = 1;
  *(_QWORD *)(v5 + 8i64 * v6 + 16) = "AI::HavokNavDaemon::m_outputs";
  *(_QWORD *)(v5 + 8i64 * v6 + 48) = 0i64;
  v7 = *(_BYTE *)(v5 + 81);
  if ( v6 > v7 )
    v7 = v6;
  *(_BYTE *)(v5 + 81) = v7;
  v8 = 16i64;
  if ( (this->m_outputs.m_capacityAndFlags & 0x3FFFFFFFu) < 0x10 )
  {
    v9 = 16;
    if ( 2 * (this->m_outputs.m_capacityAndFlags & 0x3FFFFFFF) > 16 )
      v9 = 2 * (this->m_outputs.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_outputs, v9, 16);
  }
  v10 = this->m_outputs.m_size - 17;
  v11 = v10;
  if ( v10 >= 0 )
  {
    v12 = &p_m_outputs->m_data[16].m_capacityAndFlags + 4 * v10;
    do
    {
      *(v12 - 1) = 0;
      if ( *v12 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v12 - 3),
          4 * *v12);
      *(_QWORD *)(v12 - 3) = 0i64;
      *v12 = 0x80000000;
      v12 -= 4;
      --v11;
    }
    while ( v11 >= 0 );
  }
  v13 = 16 - p_m_outputs->m_size;
  v14 = (__int64)&p_m_outputs->m_data[p_m_outputs->m_size];
  v71 = v14;
  v15 = 0;
  result.m_enum = HK_SUCCESS;
  v16 = v13;
  if ( v13 > 0 )
  {
    do
    {
      v72 = v14;
      if ( v14 )
      {
        *(_QWORD *)v14 = 0i64;
        *(_DWORD *)(v14 + 8) = 0;
        *(_DWORD *)(v14 + 12) = 0x80000000;
      }
      result.m_enum = ++v15;
      v14 += 16i64;
      --v16;
    }
    while ( v16 );
  }
  p_m_outputs->m_size = 16;
  v17 = *(_BYTE *)(v5 + 80);
  if ( v17 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v17 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  v18 = ++*(_BYTE *)(v5 + 80);
  *(_DWORD *)(v5 + 4i64 * v18) = 1;
  *(_QWORD *)(v5 + 8i64 * v18 + 16) = "AI::HavokNavDaemon::m_aStarOutputs";
  *(_QWORD *)(v5 + 8i64 * v18 + 48) = 0i64;
  v19 = *(_BYTE *)(v5 + 81);
  if ( v18 > v19 )
    v19 = v18;
  *(_BYTE *)(v5 + 81) = v19;
  if ( (p_m_aStarOutputs->m_capacityAndFlags & 0x3FFFFFFFu) < 0x10 )
  {
    v20 = 16;
    if ( 2 * (p_m_aStarOutputs->m_capacityAndFlags & 0x3FFFFFFF) > 16 )
      v20 = 2 * (p_m_aStarOutputs->m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_aStarOutputs, v20, 16);
  }
  m_size = p_m_aStarOutputs->m_size;
  v22 = 16 - m_size;
  v23 = (__int64)&p_m_aStarOutputs->m_data[m_size];
  v71 = v23;
  v24 = 0;
  result.m_enum = HK_SUCCESS;
  v25 = v22;
  if ( v22 > 0 )
  {
    v26 = v23 + 8;
    do
    {
      v72 = v26 - 8;
      if ( v26 != 8 )
      {
        *(_DWORD *)(v26 - 8) = 0;
        *(_DWORD *)(v26 - 4) = -1;
        *(_DWORD *)v26 = 2139095022;
        *(_WORD *)(v26 + 4) = 0;
      }
      result.m_enum = ++v24;
      v26 += 16i64;
      --v25;
    }
    while ( v25 );
  }
  p_m_aStarOutputs->m_size = 16;
  v27 = *(_BYTE *)(v5 + 80);
  if ( v27 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v27 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  v28 = ++*(_BYTE *)(v5 + 80);
  *(_DWORD *)(v5 + 4i64 * v28) = 1;
  *(_QWORD *)(v5 + 8i64 * v28 + 16) = "AI::HavokNavDaemon::m_smoothedPaths";
  *(_QWORD *)(v5 + 8i64 * v28 + 48) = 0i64;
  v29 = *(_BYTE *)(v5 + 81);
  if ( v28 > v29 )
    v29 = v28;
  *(_BYTE *)(v5 + 81) = v29;
  if ( (p_m_smoothedPaths->m_capacityAndFlags & 0x3FFFFFFFu) < 0x10 )
  {
    v30 = 16;
    if ( 2 * (p_m_smoothedPaths->m_capacityAndFlags & 0x3FFFFFFF) > 16 )
      v30 = 2 * (p_m_smoothedPaths->m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_smoothedPaths, v30, 16);
  }
  v31 = p_m_smoothedPaths->m_size - 17;
  v32 = v31;
  if ( v31 >= 0 )
  {
    v33 = &p_m_smoothedPaths->m_data[16].m_capacityAndFlags + 4 * v31;
    do
    {
      *(v33 - 1) = 0;
      if ( *v33 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v33 - 3),
          48 * (*v33 & 0x3FFFFFFF));
      *(_QWORD *)(v33 - 3) = 0i64;
      *v33 = 0x80000000;
      v33 -= 4;
      --v32;
    }
    while ( v32 >= 0 );
  }
  v34 = 16 - p_m_smoothedPaths->m_size;
  v35 = (__int64)&p_m_smoothedPaths->m_data[p_m_smoothedPaths->m_size];
  v71 = v35;
  v36 = 0;
  result.m_enum = HK_SUCCESS;
  v37 = v34;
  if ( v34 > 0 )
  {
    do
    {
      v72 = v35;
      if ( v35 )
      {
        *(_QWORD *)v35 = 0i64;
        *(_DWORD *)(v35 + 8) = 0;
        *(_DWORD *)(v35 + 12) = 0x80000000;
      }
      result.m_enum = ++v36;
      v35 += 16i64;
      --v37;
    }
    while ( v37 );
  }
  p_m_smoothedPaths->m_size = 16;
  v38 = *(_BYTE *)(v5 + 80);
  if ( v38 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v38 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  v39 = ++*(_BYTE *)(v5 + 80);
  *(_DWORD *)(v5 + 4i64 * v39) = 1;
  *(_QWORD *)(v5 + 8i64 * v39 + 16) = "AI::HavokNavDaemon::m_commands";
  *(_QWORD *)(v5 + 8i64 * v39 + 48) = 0i64;
  v40 = *(_BYTE *)(v5 + 81);
  if ( v39 > v40 )
    v40 = v39;
  *(_BYTE *)(v5 + 81) = v40;
  if ( (this->m_commands.m_capacityAndFlags & 0x3FFFFFFFu) < 0x10 )
  {
    v41 = 16;
    if ( 2 * (this->m_commands.m_capacityAndFlags & 0x3FFFFFFF) > 16 )
      v41 = 2 * (this->m_commands.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_commands, v41, 112);
  }
  v42 = 16 - this->m_commands.m_size;
  v43 = &this->m_commands.m_data[this->m_commands.m_size];
  v71 = (__int64)v43;
  v44 = 0;
  result.m_enum = HK_SUCCESS;
  v45 = v42;
  if ( v42 > 0 )
  {
    do
    {
      v72 = (__int64)v43;
      if ( v43 )
        v43->m_agentInfo = 0i64;
      result.m_enum = ++v44;
      ++v43;
      --v45;
    }
    while ( v45 );
  }
  this->m_commands.m_size = 16;
  v46 = *(_BYTE *)(v5 + 80);
  if ( v46 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v46 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  v47 = ++*(_BYTE *)(v5 + 80);
  *(_DWORD *)(v5 + 4i64 * v47) = 1;
  *(_QWORD *)(v5 + 8i64 * v47 + 16) = "AI::HavokNavDaemon::m_goals";
  *(_QWORD *)(v5 + 8i64 * v47 + 48) = 0i64;
  v48 = *(_BYTE *)(v5 + 81);
  if ( v47 > v48 )
    v48 = v47;
  *(_BYTE *)(v5 + 81) = v48;
  if ( (this->m_goals.m_capacityAndFlags & 0x3FFFFFFFu) < 0x10 )
  {
    v49 = 16;
    if ( 2 * (this->m_goals.m_capacityAndFlags & 0x3FFFFFFF) > 16 )
      v49 = 2 * (this->m_goals.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_goals, v49, 16);
  }
  this->m_goals.m_size = 16;
  v50 = *(_BYTE *)(v5 + 80);
  if ( v50 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v50 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  v51 = ++*(_BYTE *)(v5 + 80);
  *(_DWORD *)(v5 + 4i64 * v51) = 1;
  *(_QWORD *)(v5 + 8i64 * v51 + 16) = "AI::HavokNavDaemon::m_goalFaces";
  *(_QWORD *)(v5 + 8i64 * v51 + 48) = 0i64;
  v52 = *(_BYTE *)(v5 + 81);
  if ( v51 > v52 )
    v52 = v51;
  *(_BYTE *)(v5 + 81) = v52;
  if ( (this->m_goalFaces.m_capacityAndFlags & 0x3FFFFFFFu) < 0x40 )
  {
    v53 = 64;
    if ( 2 * (this->m_goalFaces.m_capacityAndFlags & 0x3FFFFFFF) > 64 )
      v53 = 2 * (this->m_goalFaces.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_goalFaces, v53, 4);
  }
  this->m_goalFaces.m_size = 64;
  v54 = *(_BYTE *)(v5 + 80);
  if ( v54 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v54 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  v55 = ++*(_BYTE *)(v5 + 80);
  *(_DWORD *)(v5 + 4i64 * v55) = 1;
  *(_QWORD *)(v5 + 8i64 * v55 + 16) = "AI::HavokNavDaemon::m_havokResults";
  *(_QWORD *)(v5 + 8i64 * v55 + 48) = 0i64;
  v56 = *(_BYTE *)(v5 + 81);
  if ( v55 > v56 )
    v56 = v55;
  *(_BYTE *)(v5 + 81) = v56;
  if ( (this->m_havokResults.m_capacityAndFlags & 0x3FFFFFFFu) < 0x10 )
  {
    v57 = 16;
    if ( 2 * (this->m_havokResults.m_capacityAndFlags & 0x3FFFFFFF) > 16 )
      v57 = 2 * (this->m_havokResults.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_havokResults, v57, 16);
  }
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
  *(_DWORD *)(v5 + 4i64 * v59) = 1;
  *(_QWORD *)(v5 + 8i64 * v59 + 16) = "AI::HavokNavDaemon::smoothedPath";
  *(_QWORD *)(v5 + 8i64 * v59 + 48) = 0i64;
  v60 = *(_BYTE *)(v5 + 81);
  if ( v59 > v60 )
    v60 = v59;
  *(_BYTE *)(v5 + 81) = v60;
  v61 = 0i64;
  do
  {
    v62 = &p_m_smoothedPaths->m_data[v61];
    if ( (v62->m_capacityAndFlags & 0x3FFFFFFFu) >= 0x100 )
    {
      result.m_enum = HK_SUCCESS;
    }
    else
    {
      v63 = 256;
      if ( 2 * (v62->m_capacityAndFlags & 0x3FFFFFFF) > 256 )
        v63 = 2 * (v62->m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, v62, v63, 48);
    }
    v64 = v62->m_size;
    v65 = 0;
    LODWORD(v71) = 0;
    if ( 256 - v64 > 0 )
    {
      do
        LODWORD(v71) = ++v65;
      while ( v65 < 256 - v62->m_size );
    }
    v62->m_size = 256;
    v66 = &p_m_outputs->m_data[v61];
    if ( (v66->m_capacityAndFlags & 0x3FFFFFFFu) >= 0x100 )
    {
      LODWORD(v72) = 0;
    }
    else
    {
      v67 = 256;
      if ( 2 * (v66->m_capacityAndFlags & 0x3FFFFFFF) > 256 )
        v67 = 2 * (v66->m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve((hkResult *)&v72, &hkContainerHeapAllocator::s_alloc, v66, v67, 4);
    }
    v66->m_size = 256;
    ++v61;
    --v8;
  }
  while ( v8 );
  v68 = *(_BYTE *)(v5 + 80);
  if ( v68 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v68 - 1;
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
  int m_capacityAndFlags; // r8d
  int v3; // r8d
  int v4; // r8d
  int v5; // r8d
  int v6; // eax
  __int64 v7; // rsi
  int *v8; // rdi
  int v9; // r8d
  int v10; // r8d
  int v11; // eax
  __int64 v12; // rsi
  int *v13; // rdi
  int v14; // r8d
  UFG::DaemonQueryInput **p; // rcx

  this->vfptr = (UFG::DaemonVtbl *)&UFG::HavokNavDaemon::`vftable;
  this->m_havokResults.m_size = 0;
  m_capacityAndFlags = this->m_havokResults.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_havokResults.m_data,
      16 * m_capacityAndFlags);
  this->m_havokResults.m_data = 0i64;
  this->m_havokResults.m_capacityAndFlags = 0x80000000;
  this->m_goalFaces.m_size = 0;
  v3 = this->m_goalFaces.m_capacityAndFlags;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_goalFaces.m_data,
      4 * v3);
  this->m_goalFaces.m_data = 0i64;
  this->m_goalFaces.m_capacityAndFlags = 0x80000000;
  this->m_goals.m_size = 0;
  v4 = this->m_goals.m_capacityAndFlags;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_goals.m_data, 16 * v4);
  this->m_goals.m_data = 0i64;
  this->m_goals.m_capacityAndFlags = 0x80000000;
  this->m_commands.m_size = 0;
  v5 = this->m_commands.m_capacityAndFlags;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_commands.m_data,
      112 * (v5 & 0x3FFFFFFF));
  this->m_commands.m_data = 0i64;
  this->m_commands.m_capacityAndFlags = 0x80000000;
  v6 = this->m_smoothedPaths.m_size - 1;
  v7 = v6;
  if ( v6 >= 0 )
  {
    v8 = &this->m_smoothedPaths.m_data->m_capacityAndFlags + 4 * v6;
    do
    {
      *(v8 - 1) = 0;
      if ( *v8 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v8 - 3),
          48 * (*v8 & 0x3FFFFFFF));
      *(_QWORD *)(v8 - 3) = 0i64;
      *v8 = 0x80000000;
      v8 -= 4;
      --v7;
    }
    while ( v7 >= 0 );
  }
  this->m_smoothedPaths.m_size = 0;
  v9 = this->m_smoothedPaths.m_capacityAndFlags;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_smoothedPaths.m_data,
      16 * v9);
  this->m_smoothedPaths.m_data = 0i64;
  this->m_smoothedPaths.m_capacityAndFlags = 0x80000000;
  this->m_aStarOutputs.m_size = 0;
  v10 = this->m_aStarOutputs.m_capacityAndFlags;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_aStarOutputs.m_data,
      16 * v10);
  this->m_aStarOutputs.m_data = 0i64;
  this->m_aStarOutputs.m_capacityAndFlags = 0x80000000;
  v11 = this->m_outputs.m_size - 1;
  v12 = v11;
  if ( v11 >= 0 )
  {
    v13 = &this->m_outputs.m_data->m_capacityAndFlags + 4 * v11;
    do
    {
      *(v13 - 1) = 0;
      if ( *v13 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v13 - 3),
          4 * *v13);
      *(_QWORD *)(v13 - 3) = 0i64;
      *v13 = 0x80000000;
      v13 -= 4;
      --v12;
    }
    while ( v12 >= 0 );
  }
  this->m_outputs.m_size = 0;
  v14 = this->m_outputs.m_capacityAndFlags;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_outputs.m_data,
      16 * v14);
  this->m_outputs.m_data = 0i64;
  this->m_outputs.m_capacityAndFlags = 0x80000000;
  p = this->m_PathRequests.p;
  if ( p )
    operator delete[](p);
  this->m_PathRequests.p = 0i64;
  *(_QWORD *)&this->m_PathRequests.size = 0i64;
  UFG::Daemon::~Daemon(this);
}

// File Line: 108
// RVA: 0xF1A60
void __fastcall UFG::HavokNavDaemon::SubmitImmediateQuery(UFG::HavokNavDaemon *this, UFG::DaemonQueryInput *input)
{
  unsigned int m_internalType; // r8d
  unsigned int v3; // r8d
  unsigned int v4; // r8d
  unsigned int v5; // r8d

  m_internalType = input->m_internalType;
  if ( m_internalType )
  {
    v3 = m_internalType - 1;
    if ( v3 )
    {
      v4 = v3 - 1;
      if ( v4 )
      {
        v5 = v4 - 1;
        if ( v5 )
        {
          if ( v5 == 1 )
            ((void (__fastcall *)(UFG::HavokNavDaemon *))this->vfptr[2].__vecDelDtor)(this);
        }
        else
        {
          ((void (__fastcall *)(UFG::HavokNavDaemon *))this->vfptr[1].CompleteUpdate)(this);
        }
      }
      else
      {
        ((void (__fastcall *)(UFG::HavokNavDaemon *))this->vfptr[1].StartUpdate)(this);
      }
    }
    else
    {
      ((void (__fastcall *)(UFG::HavokNavDaemon *))this->vfptr[1].SubmitImmediateQuery)(this);
    }
  }
  else
  {
    ((void (__fastcall *)(UFG::HavokNavDaemon *))this->vfptr[1].__vecDelDtor)(this);
  }
}

// File Line: 144
// RVA: 0xF1A40
void __fastcall UFG::HavokNavDaemon::StartUpdate(UFG::HavokNavDaemon *this, float dt)
{
  ((void (__fastcall *)(UFG::HavokNavDaemon *))this->vfptr[2].StartUpdate)(this);
  ((void (__fastcall *)(UFG::HavokNavDaemon *))this->vfptr[2].CompleteUpdate)(this);
}

// File Line: 161
// RVA: 0xE9590
void __fastcall UFG::HavokNavDaemon::CompleteUpdate(UFG::HavokNavDaemon *this, float dt)
{
  ((void (__fastcall *)(UFG::HavokNavDaemon *))this->vfptr[3].__vecDelDtor)(this);
  ((void (__fastcall *)(UFG::HavokNavDaemon *))this->vfptr[3].CancelQueueableQuery)(this);
}

// File Line: 179
// RVA: 0xE94D0
void __fastcall UFG::HavokNavDaemon::CancelQueueableQuery(UFG::HavokNavDaemon *this, UFG::DaemonQueryInput *query)
{
  unsigned int size; // r10d
  int v3; // r8d
  unsigned int v5; // ecx
  UFG::DaemonQueryInput **p; // rax
  unsigned int m_size; // ecx
  UFG::DaemonQueryOutput *m_pOutput; // rdx
  UFG::HavokNavDaemon::PathOutputEntry *i; // rax
  int v10; // edx
  __int64 v11; // r10
  unsigned int v12; // eax

  size = this->m_PathRequests.size;
  v3 = 0;
  v5 = 0;
  if ( size )
  {
    p = this->m_PathRequests.p;
    while ( *p != query )
    {
      ++v5;
      ++p;
      if ( v5 >= size )
        goto LABEL_5;
    }
    v10 = ((8i64 * v5) >> 3) + 1;
    if ( v10 != size )
    {
      v11 = v10;
      do
      {
        ++v10;
        ++v11;
        this->m_PathRequests.p[v11 - 2] = this->m_PathRequests.p[v11 - 1];
      }
      while ( v10 != this->m_PathRequests.size );
    }
    v12 = this->m_PathRequests.size;
    if ( v12 > 1 )
      this->m_PathRequests.size = v12 - 1;
    else
      this->m_PathRequests.size = 0;
  }
  else
  {
LABEL_5:
    m_size = this->m_havokResults.m_size;
    m_pOutput = query->m_pOutput;
    if ( m_size )
    {
      for ( i = this->m_havokResults.m_data; i->m_pUserOutput != m_pOutput; ++i )
      {
        if ( ++v3 >= m_size )
          return;
      }
      i->m_bValid = 0;
    }
  }
}

// File Line: 214
// RVA: 0xED680
char __fastcall UFG::HavokNavDaemon::GetUserEdgeOutlineForWaypoint(
        UFG::HavokNavDaemon *this,
        hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *navPath,
        int currWpIndex,
        UFG::qVector3 *a)
{
  __int64 v5; // rbx
  UFG::NavManager *v7; // rdi
  hkaiNavMeshQueryMediator *DynamicQueryMediator; // r9
  __int64 v10; // r14
  char v11; // dl
  char v12; // cl
  hkVector4f *p_m_position; // r10
  __int64 v14; // r8
  __m128 *v15; // rbx
  char v16; // al
  float v17; // xmm11_4
  unsigned int v18; // eax
  int v19; // eax
  __int64 v20; // rsi
  int v21; // edx
  float v22; // xmm9_4
  char v23; // r12
  __int64 v24; // rdi
  char v25; // dl
  char v26; // cl
  __int64 v27; // r14
  int v28; // r15d
  int v29; // ecx
  __int64 v30; // rcx
  unsigned __int64 v31; // rax
  int v32; // ecx
  int *v33; // rdx
  __int64 v34; // rax
  int v35; // ecx
  __m128 *v36; // rax
  __m128 v37; // xmm5
  __m128 v38; // xmm6
  __m128 v39; // xmm7
  __m128 v40; // xmm4
  __m128 v41; // xmm3
  __int64 v42; // rax
  __m128 *v43; // rax
  __m128 v44; // xmm3
  __m128 v45; // xmm3
  float v46; // xmm3_4
  __m128 v47; // xmm2
  __m128 v48; // xmm2
  float v49; // xmm2_4
  __int64 v50; // rax
  unsigned __int64 v51; // rdi
  char v52; // al
  unsigned __int64 v53; // rax
  void *v54; // r13
  float *v55; // r14
  float *v56; // r15
  float v57; // xmm2_4
  float v58; // xmm4_4
  __m128 v59; // xmm3
  __m128 v60; // xmm1
  __m128 v61; // xmm13
  float v62; // xmm15_4
  float v63; // xmm10_4
  float v64; // xmm15_4
  int v65; // xmm14_4
  char *v66; // rbx
  unsigned int v67; // esi
  __m128 v68; // xmm6
  float v69; // xmm0_4
  __m128 v70; // xmm8
  __m128 v71; // xmm5
  float v72; // xmm1_4
  __m128 v73; // xmm7
  __m128 v74; // xmm3
  __m128 v75; // xmm4
  int v76; // r10d
  unsigned int v77; // r12d
  __int64 v78; // rcx
  unsigned int v79; // r9d
  unsigned int v80; // r15d
  unsigned int v81; // ecx
  __int64 v82; // r13
  unsigned int v83; // r14d
  unsigned int v84; // edi
  unsigned __int64 v85; // rax
  char *v86; // r12
  void *v87; // rcx
  _DWORD *v88; // rdx
  char *v89; // r9
  __int64 v90; // r8
  _DWORD *v91; // rcx
  int v92; // r8d
  __m128 *v93; // r15
  int v94; // eax
  __int64 v95; // rcx
  int v96; // edx
  __int64 v97; // r13
  __int64 v98; // r8
  __int64 v99; // rax
  __int64 v100; // r9
  int v101; // r10d
  char v102; // dl
  char v103; // cl
  int v104; // ecx
  __int64 v105; // rcx
  unsigned __int64 v106; // rax
  int v107; // ecx
  int *v108; // rdx
  __int64 v109; // rax
  int v110; // ecx
  __m128 *v111; // rax
  __m128 v112; // xmm4
  __m128 v113; // xmm5
  __m128 v114; // xmm6
  __m128 v115; // xmm3
  __int64 v116; // rax
  __m128 *v117; // rax
  char v118; // al
  int v119; // xmm7_4
  int v120; // xmm8_4
  int v121; // xmm9_4
  int v122; // xmm10_4
  int v123; // xmm11_4
  int v124; // xmm12_4
  float v125; // xmm4_4
  __m128 v126; // xmm3
  __m128 v127; // xmm1
  float v128; // xmm1_4
  float v129; // xmm6_4
  unsigned int v130; // ecx
  unsigned int v131; // r14d
  unsigned int v132; // edi
  unsigned __int64 v133; // rax
  char *v134; // rax
  unsigned __int64 v135; // r12
  int *v136; // rcx
  signed __int64 v137; // rdx
  __int64 v138; // rax
  int v139; // xmm1_4
  int v140; // xmm2_4
  int v141; // xmm1_4
  int v142; // xmm2_4
  __int64 v143; // rcx
  float v144; // xmm15_4
  char v145; // r12
  char v146; // r10
  __int64 v147; // r9
  float v148; // xmm1_4
  float v149; // xmm4_4
  float v150; // xmm11_4
  float v151; // xmm12_4
  float v152; // xmm7_4
  float v153; // xmm6_4
  float v154; // xmm10_4
  float v155; // xmm14_4
  float v156; // xmm8_4
  float v157; // xmm13_4
  float v158; // xmm5_4
  float v159; // xmm9_4
  float v160; // xmm2_4
  unsigned int v161; // xmm0_4
  int v162; // xmm0_4
  unsigned int v163; // xmm0_4
  __int64 v164; // rdx
  int v165; // xmm1_4
  int v166; // xmm2_4
  int v167; // xmm0_4
  int v168; // xmm1_4
  int v169; // xmm2_4
  float v170; // xmm2_4
  float v171; // xmm0_4
  float v172; // xmm1_4
  float *v173; // rax
  float v174; // xmm7_4
  float *v175; // rax
  float v176; // xmm4_4
  float v177; // xmm6_4
  float v178; // xmm3_4
  unsigned int v179; // xmm1_4
  unsigned int v180; // xmm0_4
  char v181; // [rsp+20h] [rbp-A8h]
  int v182; // [rsp+28h] [rbp-A0h]
  float v183; // [rsp+28h] [rbp-A0h]
  int v184; // [rsp+30h] [rbp-98h]
  float v185; // [rsp+30h] [rbp-98h]
  hkVector4f B2; // [rsp+40h] [rbp-88h] BYREF
  float v187; // [rsp+50h] [rbp-78h]
  __m128 *p_m_quad; // [rsp+58h] [rbp-70h]
  void *mem; // [rsp+60h] [rbp-68h]
  __int64 v190; // [rsp+68h] [rbp-60h]
  hkVector4f B; // [rsp+70h] [rbp-58h] BYREF
  __int64 v192; // [rsp+80h] [rbp-48h]
  __int64 v193; // [rsp+88h] [rbp-40h]
  __int64 v194; // [rsp+90h] [rbp-38h]
  hkLineSegmentUtil::ClosestPointLineSegResult result; // [rsp+98h] [rbp-30h] BYREF
  __m128 v196; // [rsp+A8h] [rbp-20h] BYREF
  hkaiNavMeshQueryMediator *v197; // [rsp+B8h] [rbp-10h]
  UFG::NavManager *v198; // [rsp+C0h] [rbp-8h]
  __int64 v199; // [rsp+C8h] [rbp+0h]
  int v200; // [rsp+D8h] [rbp+10h] BYREF
  __int64 v201; // [rsp+E0h] [rbp+18h]
  __int128 v202; // [rsp+E8h] [rbp+20h]
  __int64 v203; // [rsp+F8h] [rbp+30h]
  __m128 m_quad; // [rsp+108h] [rbp+40h]
  __m128 v205; // [rsp+118h] [rbp+50h]
  __int64 v206; // [rsp+128h] [rbp+60h]
  char *v207; // [rsp+138h] [rbp+70h]
  __int64 v208; // [rsp+140h] [rbp+78h]
  __int64 v209; // [rsp+230h] [rbp+168h]
  void *ptr; // [rsp+238h] [rbp+170h]
  float *v211; // [rsp+240h] [rbp+178h]
  float *v212; // [rsp+248h] [rbp+180h]

  v208 = -2i64;
  v5 = currWpIndex;
  v7 = UFG::NavManager::ms_pInstance;
  v198 = UFG::NavManager::ms_pInstance;
  DynamicQueryMediator = hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
  v197 = DynamicQueryMediator;
  if ( !DynamicQueryMediator )
    return 0;
  v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  B2.m_quad.m128_u64[1] = v10;
  v11 = ++*(_BYTE *)(v10 + 80);
  *(_DWORD *)(v10 + 4i64 * v11) = 1;
  *(_QWORD *)(v10 + 8i64 * v11 + 16) = "AI::HavokNavDaemon::GetUserEdgeOutlineForWaypoint";
  *(_QWORD *)(v10 + 8i64 * v11 + 48) = 0i64;
  v12 = *(_BYTE *)(v10 + 81);
  if ( v11 > v12 )
    v12 = v11;
  *(_BYTE *)(v10 + 81) = v12;
  p_m_position = &navPath->m_data[v5].m_position;
  p_m_quad = &p_m_position->m_quad;
  v14 = p_m_position[2].m_quad.m128_u16[1];
  v15 = *(__m128 **)(*((_QWORD *)v7[3].vfptr->LowHealthDefrag + 4) + 48i64 * p_m_position[2].m_quad.m128_i32[1]);
  if ( v15[20].m128_i32[2] )
    v181 = *(_BYTE *)(v14 + v15[20].m128_u64[0]);
  else
    v181 = 0;
  v16 = *(_BYTE *)(v10 + 80);
  if ( v16 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v16 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  v17 = FLOAT_0_5;
  if ( (v181 & 1) != 0 )
  {
    v200 = 0;
    v201 = 0i64;
    v202 = 0i64;
    v203 = 0i64;
    m_quad = p_m_position->m_quad;
    v205 = _mm_shuffle_ps((__m128)0x3F000000u, (__m128)0x3F000000u, 0);
    v206 = 0i64;
    v18 = ((__int64 (__fastcall *)(hkaiNavMeshQueryMediator *, int *, __m128 *))DynamicQueryMediator->vfptr[1].__first_virtual_table_function__)(
            DynamicQueryMediator,
            &v200,
            &v196);
    LODWORD(v14) = v18 & 0x3FFFFF;
    v15 = *(__m128 **)(*((_QWORD *)v7[3].vfptr->LowHealthDefrag + 4) + 48i64 * (v18 >> 22));
    if ( !v15 )
      return 0;
    p_m_position = (hkVector4f *)p_m_quad;
  }
  v19 = v15[1].m128_i32[2];
  if ( (int)v14 < v19 )
  {
    if ( v15[14].m128_i32[2] )
      v21 = *(_DWORD *)(v15[14].m128_u64[0] + 4i64 * (int)v14);
    else
      v21 = v14;
    if ( v21 == -1 )
      v20 = v15[1].m128_u64[0] + 16i64 * (int)v14;
    else
      v20 = v15[15].m128_u64[0] + 16i64 * v21;
  }
  else
  {
    v20 = v15[17].m128_u64[0] + 16i64 * ((int)v14 - v19);
  }
  v22 = FLOAT_3_4028235e38;
  v23 = 0;
  v24 = *(int *)(v20 + 4);
  v187 = NAN;
  v25 = ++*(_BYTE *)(v10 + 80);
  *(_DWORD *)(v10 + 4i64 * v25) = 1;
  *(_QWORD *)(v10 + 8i64 * v25 + 16) = "AI::HavokNavDaemon::GetUserEdgeOutlineForWaypoint_for";
  *(_QWORD *)(v10 + 8i64 * v25 + 48) = 0i64;
  v26 = *(_BYTE *)(v10 + 81);
  if ( v25 > v26 )
    v26 = v25;
  *(_BYTE *)(v10 + 81) = v26;
  if ( *(__int16 *)(v20 + 10) > 0 )
  {
    v27 = 4 * v24;
    v28 = -(int)v24;
    do
    {
      v29 = v15[2].m128_i32[2];
      if ( (int)v24 < v29 )
      {
        if ( v15[13].m128_i32[2] )
          v32 = *(_DWORD *)(v27 + v15[13].m128_u64[0]);
        else
          v32 = v24;
        if ( v32 == -1 )
        {
          v30 = 5i64 * (int)v24;
          v31 = v15[2].m128_u64[0];
        }
        else
        {
          v30 = 5i64 * v32;
          v31 = v15[16].m128_u64[0];
        }
      }
      else
      {
        v30 = 5i64 * ((int)v24 - v29);
        v31 = v15[18].m128_u64[0];
      }
      v33 = (int *)(v31 + 4 * v30);
      B.m_quad = 0i64;
      B2.m_quad = 0i64;
      v34 = *v33;
      v35 = v15[3].m128_i32[2];
      if ( (int)v34 >= v35 )
        v36 = (__m128 *)(v15[19].m128_u64[0] + 16i64 * ((int)v34 - v35));
      else
        v36 = (__m128 *)(v15[3].m128_u64[0] + 16 * v34);
      v37 = v15[7];
      v38 = v15[8];
      v39 = v15[9];
      v40 = v15[10];
      v41 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v36, *v36, 170), v39),
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v36, *v36, 85), v38),
                  _mm_mul_ps(_mm_shuffle_ps(*v36, *v36, 0), v37))),
              v40);
      B.m_quad = v41;
      v42 = v33[1];
      if ( (int)v42 >= v35 )
        v43 = (__m128 *)(v15[19].m128_u64[0] + 16i64 * ((int)v42 - v35));
      else
        v43 = (__m128 *)(v15[3].m128_u64[0] + 16 * v42);
      B2.m_quad = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(*v43, *v43, 170), v39),
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(*v43, *v43, 85), v38),
                        _mm_mul_ps(_mm_shuffle_ps(*v43, *v43, 0), v37))),
                    v40);
      v44 = _mm_sub_ps(v41, B2.m_quad);
      v45 = _mm_mul_ps(v44, v44);
      v46 = _mm_shuffle_ps(v45, v45, 170).m128_f32[0]
          + (float)(_mm_shuffle_ps(v45, v45, 85).m128_f32[0] + _mm_shuffle_ps(v45, v45, 0).m128_f32[0]);
      if ( v46 < 0.0 )
        LODWORD(v46) ^= _xmm[0];
      if ( v46 >= 0.001 )
      {
        hkLineSegmentUtil::closestPointLineSeg(p_m_position, &B, &B2, &result);
        p_m_position = (hkVector4f *)p_m_quad;
        v47 = _mm_sub_ps(result.m_pointOnEdge.m_quad, *p_m_quad);
        v48 = _mm_mul_ps(v47, v47);
        v49 = _mm_shuffle_ps(v48, v48, 170).m128_f32[0]
            + (float)(_mm_shuffle_ps(v48, v48, 85).m128_f32[0] + _mm_shuffle_ps(v48, v48, 0).m128_f32[0]);
        if ( v49 < 0.010000001 && v49 < v22 )
        {
          *(_QWORD *)&a->x = B.m_quad.m128_u64[0];
          LODWORD(a->z) = B.m_quad.m128_i32[2];
          v50 = (__int64)v212;
          *v212 = B2.m_quad.m128_f32[0];
          *(_QWORD *)(v50 + 4) = *(unsigned __int64 *)((char *)B2.m_quad.m128_u64 + 4);
          v187 = *(float *)&v24;
          v22 = v49;
          v23 = 1;
        }
      }
      LODWORD(v24) = v24 + 1;
      v27 += 4i64;
    }
    while ( v28 + (int)v24 < *(__int16 *)(v20 + 10) );
    v17 = FLOAT_0_5;
  }
  v51 = B2.m_quad.m128_u64[1];
  v52 = *(_BYTE *)(B2.m_quad.m128_u64[1] + 80);
  if ( v52 > 0 )
  {
    *(_BYTE *)(B2.m_quad.m128_u64[1] + 80) = v52 - 1;
  }
  else
  {
    *(_BYTE *)(B2.m_quad.m128_u64[1] + 80) = 0;
    *(_DWORD *)v51 = 3;
    *(_QWORD *)(v51 + 16) = 0i64;
    *(_QWORD *)(v51 + 48) = 0i64;
  }
  if ( !v23 )
    return 0;
  B2.m_quad = (__m128)0i64;
  v193 = 16i64;
  UFG::qArray<UFG::HavokNavDaemon::MatchedEdgeCandidate,0>::Reallocate(
    (UFG::qArray<UFG::HavokNavDaemon::MatchedEdgeCandidate,0> *)&B2,
    0x10u,
    "qArray.Reallocate(Constructor)");
  mem = 0i64;
  p_m_quad = 0i64;
  v53 = 64i64;
  if ( !is_mul_ok(0x10ui64, 4ui64) )
    v53 = -1i64;
  v54 = UFG::qMalloc(v53, "qArray.Reallocate(Constructor)", 0i64);
  mem = v54;
  HIDWORD(p_m_quad) = 16;
  v55 = v211;
  v56 = v212;
  v57 = v211[2] - v212[2];
  v59 = (__m128)*((unsigned int *)v211 + 1);
  v58 = (float)(v57 * UFG::qVector3::msDirUp.x) - (float)((float)(*v211 - *v212) * UFG::qVector3::msDirUp.z);
  v59.m128_f32[0] = (float)((float)(v59.m128_f32[0] - v212[1]) * UFG::qVector3::msDirUp.z)
                  - (float)(v57 * UFG::qVector3::msDirUp.y);
  v60 = v59;
  v60.m128_f32[0] = (float)(v59.m128_f32[0] * v59.m128_f32[0]) + (float)(v58 * v58);
  v61 = (__m128)(unsigned int)FLOAT_1_0;
  if ( v60.m128_f32[0] == 0.0 )
    v62 = 0.0;
  else
    v62 = 1.0 / _mm_sqrt_ps(v60).m128_f32[0];
  v63 = v62 * v58;
  v187 = v62 * v58;
  v64 = v62 * v59.m128_f32[0];
  B.m_quad.m128_f32[0] = v64;
  v65 = _xmm;
  v66 = (char *)B2.m_quad.m128_u64[1];
  v67 = B2.m_quad.m128_i32[0];
  do
  {
    v68 = (__m128)*((unsigned int *)v55 + 2);
    v69 = v56[2];
    if ( v68.m128_f32[0] >= v69 )
      v70 = (__m128)*((unsigned int *)v56 + 2);
    else
      v70 = (__m128)*((unsigned int *)v55 + 2);
    v71 = (__m128)*((unsigned int *)v55 + 1);
    v72 = v56[1];
    if ( v71.m128_f32[0] >= v72 )
      v73 = (__m128)*((unsigned int *)v56 + 1);
    else
      v73 = (__m128)*((unsigned int *)v55 + 1);
    v74 = (__m128)*(unsigned int *)v55;
    if ( v74.m128_f32[0] >= *v56 )
      v75 = (__m128)*(unsigned int *)v56;
    else
      v75 = (__m128)*(unsigned int *)v55;
    v70.m128_f32[0] = v70.m128_f32[0] - v17;
    v73.m128_f32[0] = v73.m128_f32[0] - v17;
    v75.m128_f32[0] = v75.m128_f32[0] - v17;
    if ( v68.m128_f32[0] <= v69 )
      v68 = (__m128)*((unsigned int *)v56 + 2);
    if ( v71.m128_f32[0] <= v72 )
      v71 = (__m128)*((unsigned int *)v56 + 1);
    if ( v74.m128_f32[0] <= *v56 )
      v74 = (__m128)*(unsigned int *)v56;
    v68.m128_f32[0] = v68.m128_f32[0] + v17;
    v71.m128_f32[0] = v71.m128_f32[0] + v17;
    v74.m128_f32[0] = v74.m128_f32[0] + v17;
    B.m_quad.m128_u64[0] = 0i64;
    B.m_quad.m128_u64[1] = 0x8000000000000000ui64;
    v200 = 0;
    v201 = 0i64;
    v202 = 0i64;
    v203 = 0i64;
    m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v75, v70), _mm_unpacklo_ps(v73, v61));
    v205 = _mm_unpacklo_ps(_mm_unpacklo_ps(v74, v68), _mm_unpacklo_ps(v71, v61));
    ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, hkVector4f *))v197->vfptr[3].__first_virtual_table_function__)(
      v197,
      &v200,
      &B);
    v76 = 0;
    v184 = 0;
    v77 = _S8_2;
    if ( B.m_quad.m128_i32[2] <= 0 )
      goto LABEL_164;
    v78 = 0i64;
    v194 = 0i64;
    v79 = (unsigned int)p_m_quad;
    do
    {
      v80 = *(_DWORD *)(v78 + B.m_quad.m128_u64[0]);
      v81 = 0;
      if ( v79 )
      {
        while ( v80 != *((_DWORD *)v54 + v81) )
        {
          if ( ++v81 >= v79 )
            goto LABEL_80;
        }
        if ( v81 != -1 )
          goto LABEL_162;
      }
LABEL_80:
      v82 = v79;
      v83 = v79 + 1;
      if ( v79 + 1 > (unsigned int)v193 )
      {
        v84 = 1;
        if ( (_DWORD)v193 )
          v84 = 2 * v193;
        for ( ; v84 < v83; v84 *= 2 )
          ;
        if ( v84 <= 4 )
          v84 = 4;
        if ( v84 - v83 > 0x10000 )
          v84 = v79 + 65537;
        if ( v84 != v79 )
        {
          v85 = 4i64 * v84;
          if ( !is_mul_ok(v84, 4ui64) )
            v85 = -1i64;
          v86 = UFG::qMalloc(v85, "qArray.Add", 0i64);
          v87 = mem;
          if ( mem )
          {
            if ( (_DWORD)p_m_quad )
            {
              v88 = v86;
              v89 = (char *)((_BYTE *)mem - v86);
              v90 = (unsigned int)p_m_quad;
              do
              {
                *v88 = *(_DWORD *)((char *)v88 + (_QWORD)v89);
                ++v88;
                --v90;
              }
              while ( v90 );
            }
            operator delete[](v87);
          }
          v91 = v86;
          mem = v86;
          v193 = v84;
          HIDWORD(p_m_quad) = v84;
          v77 = _S8_2;
          v51 = B2.m_quad.m128_u64[1];
          v76 = v184;
          goto LABEL_100;
        }
        v51 = B2.m_quad.m128_u64[1];
      }
      v91 = mem;
LABEL_100:
      v79 = v83;
      LODWORD(p_m_quad) = v83;
      v91[v82] = v80;
      v92 = v80 & 0x3FFFFF;
      v93 = *(__m128 **)(*((_QWORD *)v198[3].vfptr->LowHealthDefrag + 4) + 48i64 * (v80 >> 22));
      v94 = v93[1].m128_i32[2];
      if ( v92 < v94 )
      {
        if ( v93[14].m128_i32[2] )
          v96 = *(_DWORD *)(v93[14].m128_u64[0] + 4i64 * v92);
        else
          v96 = v92;
        if ( v96 == -1 )
          v95 = v93[1].m128_u64[0] + 16i64 * v92;
        else
          v95 = v93[15].m128_u64[0] + 16i64 * v96;
      }
      else
      {
        v95 = v93[17].m128_u64[0] + 16i64 * (v92 - v94);
      }
      v190 = v95;
      v97 = *(int *)(v95 + 4);
      v98 = v97;
      v192 = v97;
      v99 = SLODWORD(v187);
      v199 = SLODWORD(v187);
      if ( *(__int16 *)(v95 + 10) > 0 )
      {
        v100 = 4 * v97;
        B.m_quad.m128_u64[1] = 4 * v97;
        v101 = -(int)v97;
        v182 = -(int)v97;
        while ( 1 )
        {
          if ( v99 == v98 )
            goto LABEL_157;
          v102 = ++*(_BYTE *)(v51 + 80);
          *(_DWORD *)(v51 + 4i64 * v102) = 1;
          *(_QWORD *)(v51 + 8i64 * v102 + 16) = "AI::HavokNavDaemon::GetUserEdgeOutlineForWaypoint_for";
          *(_QWORD *)(v51 + 8i64 * v102 + 48) = 0i64;
          v103 = *(_BYTE *)(v51 + 81);
          if ( v102 > v103 )
            v103 = v102;
          *(_BYTE *)(v51 + 81) = v103;
          v104 = v93[2].m128_i32[2];
          if ( (int)v97 < v104 )
          {
            if ( v93[13].m128_i32[2] )
              v107 = *(_DWORD *)(v100 + v93[13].m128_u64[0]);
            else
              v107 = v97;
            if ( v107 == -1 )
            {
              v105 = 5i64 * (int)v97;
              v106 = v93[2].m128_u64[0];
            }
            else
            {
              v105 = 5i64 * v107;
              v106 = v93[16].m128_u64[0];
            }
          }
          else
          {
            v105 = 5i64 * ((int)v97 - v104);
            v106 = v93[18].m128_u64[0];
          }
          v108 = (int *)(v106 + 4 * v105);
          v109 = *v108;
          v110 = v93[3].m128_i32[2];
          if ( (int)v109 >= v110 )
            v111 = (__m128 *)(v93[19].m128_u64[0] + 16i64 * ((int)v109 - v110));
          else
            v111 = (__m128 *)(v93[3].m128_u64[0] + 16 * v109);
          v112 = v93[7];
          v113 = v93[8];
          v114 = v93[9];
          v115 = v93[10];
          v196 = _mm_add_ps(
                   v115,
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(*v111, *v111, 170), v114),
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(*v111, *v111, 85), v113),
                       _mm_mul_ps(_mm_shuffle_ps(*v111, *v111, 0), v112))));
          v116 = v108[1];
          if ( (int)v116 >= v110 )
            v117 = (__m128 *)(v93[19].m128_u64[0] + 16i64 * ((int)v116 - v110));
          else
            v117 = (__m128 *)(v93[3].m128_u64[0] + 16 * v116);
          result.m_pointOnEdge.m_quad = _mm_add_ps(
                                          v115,
                                          _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps(*v117, *v117, 170), v114),
                                            _mm_add_ps(
                                              _mm_mul_ps(_mm_shuffle_ps(*v117, *v117, 85), v113),
                                              _mm_mul_ps(_mm_shuffle_ps(*v117, *v117, 0), v112))));
          v118 = *(_BYTE *)(v51 + 80);
          if ( v118 > 0 )
          {
            *(_BYTE *)(v51 + 80) = v118 - 1;
          }
          else
          {
            *(_BYTE *)(v51 + 80) = 0;
            *(_DWORD *)v51 = 3;
            *(_QWORD *)(v51 + 16) = 0i64;
            *(_QWORD *)(v51 + 48) = 0i64;
          }
          v119 = v196.m128_i32[2];
          v55 = v211;
          v120 = v196.m128_i32[1];
          v121 = v196.m128_i32[0];
          if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v196.m128_f32[2] - v211[2]) & v65) >= 0.30000001
            || COERCE_FLOAT(COERCE_UNSIGNED_INT(
                              (float)(v63 * (float)(v196.m128_f32[1] - v211[1]))
                            + (float)((float)(v196.m128_f32[0] - *v211) * v64)) & v65) >= 0.02 )
          {
            goto LABEL_158;
          }
          v122 = result.m_pointOnEdge.m_quad.m128_i32[2];
          v126 = (__m128)v196.m128_u32[1];
          v123 = result.m_pointOnEdge.m_quad.m128_i32[1];
          v124 = result.m_pointOnEdge.m_quad.m128_i32[0];
          v125 = (float)((float)(v196.m128_f32[2] - result.m_pointOnEdge.m_quad.m128_f32[2]) * UFG::qVector3::msDirUp.x)
               - (float)((float)(v196.m128_f32[0] - result.m_pointOnEdge.m_quad.m128_f32[0]) * UFG::qVector3::msDirUp.z);
          v126.m128_f32[0] = (float)((float)(v196.m128_f32[1] - result.m_pointOnEdge.m_quad.m128_f32[1])
                                   * UFG::qVector3::msDirUp.z)
                           - (float)((float)(v196.m128_f32[2] - result.m_pointOnEdge.m_quad.m128_f32[2])
                                   * UFG::qVector3::msDirUp.y);
          v127 = v126;
          v127.m128_f32[0] = (float)(v126.m128_f32[0] * v126.m128_f32[0]) + (float)(v125 * v125);
          if ( v127.m128_f32[0] == 0.0 )
            v128 = 0.0;
          else
            v128 = v61.m128_f32[0] / _mm_sqrt_ps(v127).m128_f32[0];
          v129 = (float)((float)(v128 * v125) * v187) + (float)((float)(v126.m128_f32[0] * v128) * v64);
          if ( (v77 & 1) == 0 )
          {
            v77 |= 1u;
            _S8_2 = v77;
            kfMaxDotDiff = v61.m128_f32[0] - cosf(0.034906585);
            v98 = v192;
            v100 = B.m_quad.m128_i64[1];
            v101 = v182;
          }
          if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v61.m128_f32[0] - v129) & v65) < kfMaxDotDiff )
            break;
          v63 = v187;
LABEL_158:
          LODWORD(v97) = v97 + 1;
          v100 += 4i64;
          B.m_quad.m128_u64[1] = v100;
          v192 = ++v98;
          v99 = v199;
          if ( v101 + (int)v97 >= *(__int16 *)(v190 + 10) )
          {
            v79 = (unsigned int)p_m_quad;
            v76 = v184;
            goto LABEL_161;
          }
        }
        v130 = v67;
        LODWORD(mem) = v67;
        v131 = v67 + 1;
        if ( v67 + 1 > B2.m_quad.m128_i32[1] )
        {
          v132 = 1;
          if ( B2.m_quad.m128_i32[1] )
            v132 = 2 * B2.m_quad.m128_i32[1];
          for ( ; v132 < v131; v132 *= 2 )
            ;
          if ( v132 - v131 > 0x10000 )
            v132 = v67 + 65537;
          if ( v132 != v67 )
          {
            v133 = 24i64 * v132;
            if ( !is_mul_ok(v132, 0x18ui64) )
              v133 = -1i64;
            v134 = UFG::qMalloc(v133, "qArray.Add", 0i64);
            v135 = (unsigned __int64)v134;
            v207 = v134;
            if ( v66 )
            {
              if ( v67 )
              {
                v136 = (int *)(v66 + 20);
                v137 = v134 - v66;
                v138 = v67;
                do
                {
                  v139 = *(v136 - 4);
                  v140 = *(v136 - 3);
                  *(int *)((char *)v136 + v137 - 20) = *(v136 - 5);
                  *(int *)((char *)v136 + v137 - 16) = v139;
                  *(int *)((char *)v136 + v137 - 12) = v140;
                  v141 = *(v136 - 1);
                  v142 = *v136;
                  *(int *)((char *)v136 + v137 - 8) = *(v136 - 2);
                  *(int *)((char *)v136 + v137 - 4) = v141;
                  *(int *)((char *)v136 + v137) = v142;
                  v136 += 6;
                  --v138;
                }
                while ( v138 );
              }
              operator delete[](v66);
            }
            v66 = (char *)v135;
            B2.m_quad.m128_u64[1] = v135;
            B2.m_quad.m128_i32[1] = v132;
            v77 = _S8_2;
            v130 = (unsigned int)mem;
          }
          v51 = B2.m_quad.m128_u64[1];
        }
        ++v67;
        B2.m_quad.m128_i32[0] = v131;
        v143 = 3i64 * v130;
        *(_DWORD *)&v66[8 * v143] = v121;
        *(_DWORD *)&v66[8 * v143 + 4] = v120;
        *(_DWORD *)&v66[8 * v143 + 8] = v119;
        *(_DWORD *)&v66[8 * v143 + 12] = v124;
        *(_DWORD *)&v66[8 * v143 + 16] = v123;
        *(_DWORD *)&v66[8 * v143 + 20] = v122;
        v63 = v187;
        v98 = v192;
        v100 = B.m_quad.m128_i64[1];
        v101 = v182;
LABEL_157:
        v55 = v211;
        goto LABEL_158;
      }
      v55 = v211;
LABEL_161:
      v54 = mem;
LABEL_162:
      v184 = ++v76;
      v78 = v194 + 4;
      v194 += 4i64;
    }
    while ( v76 < B.m_quad.m128_i32[2] );
    v56 = v212;
LABEL_164:
    if ( (v77 & 2) != 0 )
    {
      v144 = kfMaxDistanceSquared;
    }
    else
    {
      _S8_2 = v77 | 2;
      v144 = FLOAT_0_00039999999;
      kfMaxDistanceSquared = FLOAT_0_00039999999;
    }
    v145 = 0;
    while ( 2 )
    {
      v146 = 0;
      v147 = 0i64;
      if ( v67 )
      {
LABEL_169:
        v148 = v55[1];
        v149 = v56[1];
        v150 = (float)((float)(*v55 - *v56) * (float)(*v55 - *v56))
             + (float)((float)(v148 - v149) * (float)(v148 - v149));
        v185 = *(float *)&v66[24 * (unsigned int)v147 + 4];
        v151 = v185 - v148;
        v183 = *(float *)&v66[24 * (unsigned int)v147];
        v152 = v183 - *v55;
        v153 = v185 - v149;
        v154 = v183 - *v56;
        v155 = *(float *)&v66[24 * (unsigned int)v147 + 16];
        v156 = v155 - v148;
        v157 = *(float *)&v66[24 * (unsigned int)v147 + 12];
        v158 = v157 - *v55;
        v159 = v155 - v149;
        v160 = v157 - *v56;
        if ( (float)((float)(v152 * v152) + (float)(v151 * v151)) < v144
          && (float)((float)(v160 * v160) + (float)(v159 * v159)) > v150 )
        {
          v161 = *(_DWORD *)&v66[24 * (unsigned int)v147 + 20];
          *v55 = v157;
          v55[1] = v155;
          *((_DWORD *)v55 + 2) = v161;
          goto LABEL_182;
        }
        if ( (float)((float)(v154 * v154) + (float)(v153 * v153)) < v144
          && (float)((float)(v156 * v156) + (float)(v158 * v158)) > v150 )
        {
          v162 = *(_DWORD *)&v66[24 * (unsigned int)v147 + 20];
          *v56 = v157;
          v56[1] = v155;
          goto LABEL_181;
        }
        if ( (float)((float)(v158 * v158) + (float)(v156 * v156)) < v144
          && (float)((float)(v153 * v153) + (float)(v154 * v154)) > v150 )
        {
          v163 = *(_DWORD *)&v66[24 * (unsigned int)v147 + 8];
          *v55 = v183;
          v55[1] = v185;
          *((_DWORD *)v55 + 2) = v163;
          goto LABEL_182;
        }
        if ( (float)((float)(v160 * v160) + (float)(v159 * v159)) < v144
          && (float)((float)(v152 * v152) + (float)(v151 * v151)) > v150 )
        {
          v162 = *(_DWORD *)&v66[24 * (unsigned int)v147 + 8];
          *v56 = v183;
          v56[1] = v185;
LABEL_181:
          *((_DWORD *)v56 + 2) = v162;
LABEL_182:
          v164 = v67 - 1;
          v165 = *(_DWORD *)&v66[24 * v164 + 4];
          v166 = *(_DWORD *)&v66[24 * v164 + 8];
          *(_DWORD *)&v66[24 * (unsigned int)v147] = *(_DWORD *)&v66[24 * v164];
          *(_DWORD *)&v66[24 * (unsigned int)v147 + 4] = v165;
          *(_DWORD *)&v66[24 * (unsigned int)v147 + 8] = v166;
          v167 = *(_DWORD *)&v66[24 * v164 + 12];
          v168 = *(_DWORD *)&v66[24 * v164 + 16];
          v169 = *(_DWORD *)&v66[24 * v164 + 20];
          if ( v67 <= 1 )
            LODWORD(v164) = 0;
          B2.m_quad.m128_i32[0] = v164;
          *(_DWORD *)&v66[24 * (unsigned int)v147 + 20] = v169;
          *(_DWORD *)&v66[24 * (unsigned int)v147 + 16] = v168;
          v67 = v164;
          *(_DWORD *)&v66[24 * (unsigned int)v147 + 12] = v167;
          v146 = 1;
        }
        v147 = (unsigned int)(v147 + 1);
        if ( (unsigned int)v147 >= v67 )
        {
          if ( v146 )
          {
            v145 = 1;
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
        v147);
    B.m_quad.m128_u64[0] = 0i64;
    B.m_quad.m128_i32[3] = 0x80000000;
    v61 = (__m128)(unsigned int)FLOAT_1_0;
    v65 = _xmm;
    v64 = 0.0;
    v63 = v187;
    v17 = FLOAT_0_5;
  }
  while ( v145 );
  v170 = 0.0;
  v171 = p_m_quad->m128_f32[1];
  v172 = p_m_quad->m128_f32[0];
  if ( *(_DWORD *)(v209 + 8) <= (unsigned int)ptr )
  {
    if ( (_DWORD)ptr )
    {
      v175 = (float *)(*(_QWORD *)v209 + 48i64 * ((int)ptr - 1));
      v174 = v171 - v175[1];
      v170 = v172 - *v175;
    }
    else
    {
      v174 = *(float *)&FLOAT_1_0;
    }
  }
  else
  {
    v173 = (float *)(*(_QWORD *)v209 + 48i64 * ((int)ptr + 1));
    v174 = v173[1] - v171;
    v170 = *v173 - v172;
  }
  v176 = v55[1];
  v177 = v56[1];
  v178 = *v55;
  if ( (float)((float)(v170 * (float)(v176 - v177)) - (float)((float)(*v55 - *v56) * v174)) < 0.0 )
  {
    v179 = *((_DWORD *)v55 + 2);
    v180 = *((_DWORD *)v56 + 2);
    *v55 = *v56;
    v55[1] = v177;
    *((_DWORD *)v55 + 2) = v180;
    *v56 = v178;
    v56[1] = v176;
    *((_DWORD *)v56 + 2) = v179;
  }
  if ( v54 )
    operator delete[](v54);
  mem = 0i64;
  p_m_quad = 0i64;
  if ( v66 )
    operator delete[](v66);
  return 1;
}

// File Line: 511
// RVA: 0xEB360
void __fastcall UFG::HavokNavDaemon::FindPathImmediate(
        UFG::HavokNavDaemon *this,
        UFG::FindPathImmediateQuery *queryInput)
{
  UFG::NavManager *v4; // r15
  hkaiNavMeshQueryMediator *DynamicQueryMediator; // rax
  UFG::DaemonQueryOutput *m_pOutput; // rdi
  UFG::NavPath *v7; // rbx
  UFG::DaemonQueryOutputVtbl *v8; // rcx
  bool v9; // zf
  __int64 v10; // rbx
  char v11; // dl
  char v12; // cl
  __m128 v13; // xmm1
  __m128i v14; // xmm2
  UFG::NavParams *m_pNavParams; // rax
  unsigned int m_packedKey; // ecx
  char v17; // al
  UFG::NavPath *v18; // rbx
  UFG::DaemonQueryOutputVtbl *vfptr; // rcx
  unsigned int v20; // ecx
  int m_maxSearchIterations; // eax
  char v22; // dl
  char v23; // cl
  char v24; // al
  char v25; // dl
  char v26; // cl
  hkJobType v27; // edx
  char *v28; // rbx
  char output[72]; // [rsp+20h] [rbp-B8h] BYREF
  __m128 *v30; // [rsp+68h] [rbp-70h]
  hkaiPathfindingUtil::FindPathInput input; // [rsp+70h] [rbp-68h] BYREF
  char *v32; // [rsp+140h] [rbp+68h]

  *(_QWORD *)&output[64] = -2i64;
  v4 = UFG::NavManager::ms_pInstance;
  DynamicQueryMediator = hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr);
  m_pOutput = queryInput->m_pOutput;
  if ( DynamicQueryMediator )
  {
    v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v11 = ++*(_BYTE *)(v10 + 80);
    *(_DWORD *)(v10 + 4i64 * v11) = 1;
    *(_QWORD *)(v10 + 8i64 * v11 + 16) = "AI::HavokNavDaemon::FindPathImmediate 1";
    *(_QWORD *)(v10 + 8i64 * v11 + 48) = 0i64;
    v12 = *(_BYTE *)(v10 + 81);
    if ( v11 > v12 )
      v12 = v11;
    *(_BYTE *)(v10 + 81) = v12;
    hkaiPathfindingUtil::FindPathInput::FindPathInput(&input, 1);
    v13 = _mm_mul_ps(_xmm, (__m128)xmmword_141A71390);
    v14 = _mm_add_epi32(
            _mm_xor_si128(
              _mm_cvttps_epi32(v13),
              (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v13)),
            _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset));
    LOWORD(input.m_startFaceKey) = _mm_extract_epi16(v14, 1);
    HIWORD(input.m_startFaceKey) = _mm_extract_epi16(v14, 3);
    *((_WORD *)&input.m_startFaceKey + 2) = _mm_extract_epi16(v14, 5);
    m_pNavParams = queryInput->m_pNavParams;
    *((float *)&input.m_goalPoints.m_data + 1) = m_pNavParams->m_fRadius * 2.0;
    input.m_goalPoints.m_size = m_pNavParams->m_flags;
    HIBYTE(input.m_maxNumberOfIterations) = 0;
    input.m_goalFaceKeys.m_data = (unsigned int *)&v4[14];
    *(_QWORD *)&input.m_goalFaceKeys.m_size = v4 + 20;
    *(hkVector4f *)&output[56] = queryInput->m_npFrom.m_hkvMeshPosition;
    m_packedKey = queryInput->m_npFrom.m_packedKey;
    *(_DWORD *)&input.m_memSizeAndFlags = m_packedKey;
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
    if ( m_packedKey == -1 )
    {
      v18 = UFG::g_NullPath;
      if ( (UFG::NavPath *)m_pOutput[1].vfptr != UFG::g_NullPath )
      {
        if ( UFG::g_NullPath )
          ++UFG::g_NullPath->m_uRefCount;
        vfptr = m_pOutput[1].vfptr;
        if ( vfptr )
        {
          v9 = LODWORD(vfptr[5].__vecDelDtor)-- == 1;
          if ( v9 )
            (*(void (__fastcall **)(UFG::DaemonQueryOutputVtbl *, __int64))vfptr->__vecDelDtor)(vfptr, 1i64);
        }
        m_pOutput[1].vfptr = (UFG::DaemonQueryOutputVtbl *)v18;
      }
      m_pOutput->m_status = Status_Failed;
    }
    else
    {
      *v30 = _mm_unpacklo_ps(
               _mm_unpacklo_ps(
                 (__m128)LODWORD(queryInput->m_npTo.m_vPosition.x),
                 (__m128)LODWORD(queryInput->m_npTo.m_vPosition.z)),
               _mm_unpacklo_ps((__m128)LODWORD(queryInput->m_npTo.m_vPosition.y), (__m128)0i64));
      v20 = queryInput->m_npTo.m_packedKey;
      *(_DWORD *)input.m_startPoint.m_quad.m128_u64[0] = v20;
      if ( v20 == -1 )
      {
        UFG::NavPathRefPtr::operator=((UFG::NavPathRefPtr *)&m_pOutput[1], UFG::g_NullPath);
        m_pOutput->m_status = Status_Failed;
      }
      else
      {
        m_maxSearchIterations = 2048;
        if ( queryInput->m_maxSearchIterations >= 0 )
          m_maxSearchIterations = queryInput->m_maxSearchIterations;
        LODWORD(input.m_goalPoints.m_data) = m_maxSearchIterations;
        HIDWORD(input.m_searchParameters.m_costModifier) = 0x2000;
        input.m_searchParameters.m_edgeFilter = (hkaiAstarEdgeFilter *)0x80000009200i64;
        *(_DWORD *)&input.m_searchParameters.m_validateInputs.m_bool = 9728;
        v22 = ++*(_BYTE *)(v10 + 80);
        *(_DWORD *)(v10 + 4i64 * v22) = 1;
        *(_QWORD *)(v10 + 8i64 * v22 + 16) = "AI::HavokNavDaemon::FindPathImmediate 2";
        *(_QWORD *)(v10 + 8i64 * v22 + 48) = 0i64;
        v23 = *(_BYTE *)(v10 + 81);
        if ( v22 > v23 )
          v23 = v22;
        *(_BYTE *)(v10 + 81) = v23;
        *(_DWORD *)&output[8] = 0x1FFFF;
        *(_QWORD *)output = &hkaiPathfindingUtil::FindPathOutput::`vftable;
        *(_QWORD *)&output[16] = 0i64;
        *(_DWORD *)&output[24] = 0;
        *(_DWORD *)&output[28] = 0x80000000;
        *(_QWORD *)&output[32] = 0i64;
        *(_DWORD *)&output[40] = 0;
        *(_DWORD *)&output[44] = 0x80000000;
        *(_DWORD *)&output[48] = 0;
        *(_DWORD *)&output[52] = -1;
        *(float *)&output[56] = FLOAT_3_40282e38;
        *(_WORD *)&output[60] = 0;
        hkaiPathfindingUtil::findPath(
          (hkaiStreamingCollection *)v4[3].vfptr->LowHealthDefrag,
          &input,
          (hkaiPathfindingUtil::FindPathOutput *)output);
        v24 = *(_BYTE *)(v10 + 80);
        if ( v24 > 0 )
        {
          *(_BYTE *)(v10 + 80) = v24 - 1;
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
          v25 = ++*(_BYTE *)(v10 + 80);
          *(_DWORD *)(v10 + 4i64 * v25) = 1;
          *(_QWORD *)(v10 + 8i64 * v25 + 16) = "AI::HavokNavDaemon::FindPathImmediate 3";
          *(_QWORD *)(v10 + 8i64 * v25 + 48) = 0i64;
          v26 = *(_BYTE *)(v10 + 81);
          if ( v25 > v26 )
            v26 = v25;
          *(_BYTE *)(v10 + 81) = v26;
          v28 = UFG::qMalloc(0x30ui64, "AI::FindPathImmediate:NavPath", 0i64);
          v32 = v28;
          if ( v28 )
          {
            *(_QWORD *)v28 = &UFG::NavPath::`vftable;
            *((_QWORD *)v28 + 2) = 0i64;
            *((_QWORD *)v28 + 1) = 0i64;
            *((_QWORD *)v28 + 4) = 0i64;
            *((_QWORD *)v28 + 3) = 0i64;
            *((_DWORD *)v28 + 10) = 0;
          }
          else
          {
            v28 = 0i64;
          }
          HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v27);
          UFG::NavPathRefPtr::operator=((UFG::NavPathRefPtr *)&m_pOutput[1], (UFG::NavPath *)v28);
          m_pOutput->m_status = 4
                              - (((unsigned __int8 (__fastcall *)(UFG::HavokNavDaemon *, char *, char *, char *, _QWORD, _DWORD))this->vfptr[2].SubmitImmediateQuery)(
                                   this,
                                   v28,
                                   &output[32],
                                   &output[16],
                                   *(_QWORD *)output,
                                   *(_DWORD *)&output[8]) != 0);
        }
        else
        {
          UFG::NavPathRefPtr::operator=((UFG::NavPathRefPtr *)&m_pOutput[1], UFG::g_NullPath);
          m_pOutput->m_status = Status_Failed;
        }
        hkaiPathfindingUtil::FindPathOutput::~FindPathOutput((hkaiPathfindingUtil::FindPathOutput *)output);
      }
    }
    hkaiPathfindingUtil::FindPathInput::~FindPathInput(&input);
  }
  else
  {
    v7 = UFG::g_NullPath;
    if ( (UFG::NavPath *)m_pOutput[1].vfptr != UFG::g_NullPath )
    {
      if ( UFG::g_NullPath )
        ++UFG::g_NullPath->m_uRefCount;
      v8 = m_pOutput[1].vfptr;
      if ( v8 )
      {
        v9 = LODWORD(v8[5].__vecDelDtor)-- == 1;
        if ( v9 )
          (*(void (__fastcall **)(UFG::DaemonQueryOutputVtbl *, __int64))v8->__vecDelDtor)(v8, 1i64);
      }
      m_pOutput[1].vfptr = (UFG::DaemonQueryOutputVtbl *)v7;
    }
    m_pOutput->m_status = Status_Failed;
  }
}

// File Line: 610
// RVA: 0xEBC30
char __fastcall UFG::HavokNavDaemon::FindPathMultiDestPrioritizedImmediateSubRange(
        UFG::HavokNavDaemon *this,
        hkaiWorld *world,
        UFG::FindPathMultiDestPrioritizedImmediateQuery *queryInput,
        hkaiPathfindingUtil::FindPathInput *pInput)
{
  unsigned int v8; // r10d
  float v9; // xmm0_4
  unsigned int v10; // r11d
  int v11; // ebx
  __int64 v12; // r8
  __int64 v13; // r9
  __int64 v14; // rcx
  UFG::FindPathMultiDestPrioritizedImmediateQuery::PrioritizedDestination *p; // rax
  unsigned int m_packedKey; // edx
  int v17; // eax
  int v18; // eax
  int v19; // r9d
  int v20; // eax
  int v21; // eax
  int v22; // r9d
  int m_maxSearchIterations; // eax
  __int64 v25; // rdi
  char v26; // dl
  char v27; // cl
  int v28; // ebx
  float *p_x; // r9
  char v30; // al
  hkaiPath::PathPoint *v31; // rax
  float v32; // xmm4_4
  float v33; // xmm5_4
  float v34; // xmm6_4
  unsigned int size; // r10d
  float v36; // xmm3_4
  unsigned int v37; // edx
  __int64 v38; // rax
  UFG::FindPathMultiDestPrioritizedImmediateQuery::PrioritizedDestination *v39; // rax
  int v40; // r8d
  float *p_y; // rcx
  float *v42; // r8
  float v43; // xmm0_4
  char v44; // dl
  char v45; // cl
  char *v46; // rbx
  char v47; // al
  UFG::DaemonQueryOutput *m_pOutput; // rdi
  __int64 v49; // rcx
  char v51; // bl
  hkaiPathfindingUtil::FindPathOutput output; // [rsp+8h] [rbp-79h] BYREF
  __int64 v53; // [rsp+48h] [rbp-39h]
  char *v54; // [rsp+E8h] [rbp+67h]
  void *retaddr; // [rsp+F8h] [rbp+77h] BYREF
  float *v56; // [rsp+100h] [rbp+7Fh]

  v53 = -2i64;
  v8 = (unsigned int)retaddr;
  v9 = (float)(queryInput->m_aPrioritizedDestinations.size - (int)retaddr);
  if ( v9 >= 16.0 )
    v9 = FLOAT_16_0;
  v10 = (_DWORD)retaddr + (int)v9;
  v11 = 0;
  if ( (unsigned int)retaddr < v10 )
  {
    v12 = 0i64;
    v13 = 0i64;
    v14 = (unsigned int)retaddr;
    do
    {
      p = queryInput->m_aPrioritizedDestinations.p;
      m_packedKey = p[v14].m_npPosition.m_packedKey;
      if ( m_packedKey != -1 )
      {
        pInput->m_goalPoints.m_data[v13] = p[v14].m_npPosition.m_hkvMeshPosition;
        pInput->m_goalFaceKeys.m_data[v12] = m_packedKey;
        ++v11;
        ++v13;
        ++v12;
      }
      ++v8;
      ++v14;
    }
    while ( v8 < v10 );
  }
  v17 = pInput->m_goalPoints.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v17 < v11 )
  {
    v18 = 2 * v17;
    v19 = v11;
    if ( v11 < v18 )
      v19 = v18;
    hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerHeapAllocator::s_alloc, &pInput->m_goalPoints, v19, 16);
  }
  pInput->m_goalPoints.m_size = v11;
  v20 = pInput->m_goalFaceKeys.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < v11 )
  {
    v21 = 2 * v20;
    v22 = v11;
    if ( v11 < v21 )
      v22 = v21;
    hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerHeapAllocator::s_alloc, &pInput->m_goalFaceKeys, v22, 4);
  }
  pInput->m_goalFaceKeys.m_size = v11;
  if ( !v11 )
    return 0;
  m_maxSearchIterations = 512;
  if ( queryInput->m_maxSearchIterations >= 0 )
    m_maxSearchIterations = queryInput->m_maxSearchIterations;
  pInput->m_maxNumberOfIterations = m_maxSearchIterations;
  pInput->m_searchParameters.m_bufferSizes.m_maxOpenSetSizeBytes = 0x2000;
  pInput->m_searchParameters.m_bufferSizes.m_maxSearchStateSizeBytes = 37376;
  pInput->m_searchParameters.m_hierarchyBufferSizes.m_maxOpenSetSizeBytes = 2048;
  pInput->m_searchParameters.m_hierarchyBufferSizes.m_maxSearchStateSizeBytes = 9728;
  v25 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v26 = ++*(_BYTE *)(v25 + 80);
  *(_DWORD *)(v25 + 4i64 * v26) = 1;
  *(_QWORD *)(v25 + 8i64 * v26 + 16) = "AI::HavokNavDaemon::FindPathMultiDestPrioritizedImmediate 2";
  *(_QWORD *)(v25 + 8i64 * v26 + 48) = 0i64;
  v27 = *(_BYTE *)(v25 + 81);
  if ( v26 > v27 )
    v27 = v26;
  *(_BYTE *)(v25 + 81) = v27;
  *(_DWORD *)&output.m_memSizeAndFlags = 0x1FFFF;
  output.vfptr = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathOutput::`vftable;
  output.m_visitedEdges.m_data = 0i64;
  output.m_visitedEdges.m_size = 0;
  output.m_visitedEdges.m_capacityAndFlags = 0x80000000;
  output.m_pathOut.m_data = 0i64;
  output.m_pathOut.m_size = 0;
  output.m_pathOut.m_capacityAndFlags = 0x80000000;
  output.m_outputParameters.m_numIterations = 0;
  v28 = -1;
  output.m_outputParameters.m_goalIndex = -1;
  output.m_outputParameters.m_pathLength = FLOAT_3_40282e38;
  *(_WORD *)&output.m_outputParameters.m_status.m_storage = 0;
  hkaiPathfindingUtil::findPath(world->m_streamingCollection.m_pntr, pInput, &output);
  v30 = *(_BYTE *)(v25 + 80);
  if ( v30 > 0 )
  {
    *(_BYTE *)(v25 + 80) = v30 - 1;
  }
  else
  {
    *(_BYTE *)(v25 + 80) = 0;
    *(_DWORD *)v25 = 3;
    *(_QWORD *)(v25 + 16) = 0i64;
    *(_QWORD *)(v25 + 48) = 0i64;
  }
  if ( !output.m_pathOut.m_size || output.m_outputParameters.m_status.m_storage != 1 )
    goto LABEL_62;
  v31 = &output.m_pathOut.m_data[output.m_pathOut.m_size - 1];
  v32 = v31->m_position.m_quad.m128_f32[0];
  v33 = v31->m_position.m_quad.m128_f32[1];
  v34 = v31->m_position.m_quad.m128_f32[2];
  size = queryInput->m_aPrioritizedDestinations.size;
  v36 = FLOAT_3_4028235e38;
  v37 = 0;
  v38 = 0i64;
  if ( (int)size >= 4 )
  {
    v39 = queryInput->m_aPrioritizedDestinations.p;
    v40 = 2;
    p_x = &v39[1].m_npPosition.m_vPosition.x;
    p_y = &v39[3].m_npPosition.m_vPosition.y;
    v38 = 4i64 * (((size - 4) >> 2) + 1);
    do
    {
      if ( (float)((float)((float)((float)(v33 - *(p_y - 60)) * (float)(v33 - *(p_y - 60)))
                         + (float)((float)(v32 - *(p_x - 20)) * (float)(v32 - *(p_x - 20))))
                 + (float)((float)(v34 - *(p_y - 59)) * (float)(v34 - *(p_y - 59)))) < v36 )
      {
        v28 = v37;
        v36 = (float)((float)((float)(v33 - *(p_y - 60)) * (float)(v33 - *(p_y - 60)))
                    + (float)((float)(v32 - *(p_x - 20)) * (float)(v32 - *(p_x - 20))))
            + (float)((float)(v34 - *(p_y - 59)) * (float)(v34 - *(p_y - 59)));
      }
      if ( (float)((float)((float)((float)(v33 - *(p_y - 40)) * (float)(v33 - *(p_y - 40)))
                         + (float)((float)(v32 - *p_x) * (float)(v32 - *p_x)))
                 + (float)((float)(v34 - *(p_y - 39)) * (float)(v34 - *(p_y - 39)))) < v36 )
      {
        v28 = v40 - 1;
        v36 = (float)((float)((float)(v33 - *(p_y - 40)) * (float)(v33 - *(p_y - 40)))
                    + (float)((float)(v32 - *p_x) * (float)(v32 - *p_x)))
            + (float)((float)(v34 - *(p_y - 39)) * (float)(v34 - *(p_y - 39)));
      }
      if ( (float)((float)((float)((float)(v33 - *(p_y - 20)) * (float)(v33 - *(p_y - 20)))
                         + (float)((float)(v32 - p_x[20]) * (float)(v32 - p_x[20])))
                 + (float)((float)(v34 - *(p_y - 19)) * (float)(v34 - *(p_y - 19)))) < v36 )
      {
        v28 = v40;
        v36 = (float)((float)((float)(v33 - *(p_y - 20)) * (float)(v33 - *(p_y - 20)))
                    + (float)((float)(v32 - p_x[20]) * (float)(v32 - p_x[20])))
            + (float)((float)(v34 - *(p_y - 19)) * (float)(v34 - *(p_y - 19)));
      }
      if ( (float)((float)((float)((float)(v33 - *p_y) * (float)(v33 - *p_y))
                         + (float)((float)(v32 - *(p_y - 1)) * (float)(v32 - *(p_y - 1))))
                 + (float)((float)(v34 - p_y[1]) * (float)(v34 - p_y[1]))) < v36 )
      {
        v28 = v40 + 1;
        v36 = (float)((float)((float)(v33 - *p_y) * (float)(v33 - *p_y))
                    + (float)((float)(v32 - *(p_y - 1)) * (float)(v32 - *(p_y - 1))))
            + (float)((float)(v34 - p_y[1]) * (float)(v34 - p_y[1]));
      }
      p_x += 80;
      p_y += 80;
      v37 += 4;
      v40 += 4;
    }
    while ( v37 < size - 3 );
  }
  if ( v37 < size )
  {
    v42 = &queryInput->m_aPrioritizedDestinations.p->m_npPosition.m_vPosition.y + 20 * v38;
    do
    {
      if ( (float)((float)((float)((float)(v33 - *v42) * (float)(v33 - *v42))
                         + (float)((float)(v32 - *(v42 - 1)) * (float)(v32 - *(v42 - 1))))
                 + (float)((float)(v34 - v42[1]) * (float)(v34 - v42[1]))) < v36 )
      {
        v28 = v37;
        v36 = (float)((float)((float)(v33 - *v42) * (float)(v33 - *v42))
                    + (float)((float)(v32 - *(v42 - 1)) * (float)(v32 - *(v42 - 1))))
            + (float)((float)(v34 - v42[1]) * (float)(v34 - v42[1]));
      }
      v42 += 20;
      ++v37;
    }
    while ( v37 < size );
  }
  if ( v28 < 0 )
    goto LABEL_61;
  v43 = queryInput->m_aPrioritizedDestinations.p[v28].m_fPriority
      - *(float *)(*(_QWORD *)&queryInput->m_pOutput[1].m_id + 4i64 * (unsigned int)v28);
  if ( v43 <= *v56 )
    goto LABEL_61;
  *v56 = v43;
  v44 = ++*(_BYTE *)(v25 + 80);
  *(_DWORD *)(v25 + 4i64 * v44) = 1;
  *(_QWORD *)(v25 + 8i64 * v44 + 16) = "AI::HavokNavDaemon::FindPathMultiDestPrioritizedImmediate 3";
  *(_QWORD *)(v25 + 8i64 * v44 + 48) = 0i64;
  v45 = *(_BYTE *)(v25 + 81);
  if ( v44 > v45 )
    v45 = v44;
  *(_BYTE *)(v25 + 81) = v45;
  v46 = UFG::qMalloc(0x30ui64, "AI::FindPathMultiDestPrioritizedImmediate:NavPath", 0i64);
  v54 = v46;
  if ( v46 )
  {
    *(_QWORD *)v46 = &UFG::NavPath::`vftable;
    *((_QWORD *)v46 + 2) = 0i64;
    *((_QWORD *)v46 + 1) = 0i64;
    *((_QWORD *)v46 + 4) = 0i64;
    *((_QWORD *)v46 + 3) = 0i64;
    *((_DWORD *)v46 + 10) = 0;
  }
  else
  {
    v46 = 0i64;
  }
  v47 = *(_BYTE *)(v25 + 80);
  if ( v47 > 0 )
  {
    *(_BYTE *)(v25 + 80) = v47 - 1;
  }
  else
  {
    *(_BYTE *)(v25 + 80) = 0;
    *(_DWORD *)v25 = 3;
    *(_QWORD *)(v25 + 16) = 0i64;
    *(_QWORD *)(v25 + 48) = 0i64;
  }
  m_pOutput = queryInput->m_pOutput;
  if ( *(char **)&m_pOutput[1].m_status != v46 )
  {
    if ( v46 )
      ++*((_DWORD *)v46 + 10);
    v49 = *(_QWORD *)&m_pOutput[1].m_status;
    if ( v49 )
    {
      if ( (*(_DWORD *)(v49 + 40))-- == 1 )
        (**(void (__fastcall ***)(__int64, __int64))v49)(v49, 1i64);
    }
    *(_QWORD *)&m_pOutput[1].m_status = v46;
  }
  if ( ((unsigned __int8 (__fastcall *)(UFG::HavokNavDaemon *, char *, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *, hkArray<unsigned int,hkContainerHeapAllocator> *, _QWORD))this->vfptr[2].SubmitImmediateQuery)(
         this,
         v46,
         &output.m_pathOut,
         &output.m_visitedEdges,
         *(_QWORD *)&output.m_visitedEdges.m_size) )
  {
LABEL_61:
    v51 = 1;
  }
  else
  {
LABEL_62:
    v51 = 0;
  }
  output.m_pathOut.m_size = 0;
  if ( output.m_pathOut.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkaiPath::PathPoint *, _QWORD, float *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      output.m_pathOut.m_data,
      48 * (output.m_pathOut.m_capacityAndFlags & 0x3FFFFFFFu),
      p_x);
  output.m_pathOut.m_data = 0i64;
  output.m_pathOut.m_capacityAndFlags = 0x80000000;
  output.m_visitedEdges.m_size = 0;
  if ( output.m_visitedEdges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      output.m_visitedEdges.m_data,
      4 * output.m_visitedEdges.m_capacityAndFlags);
  return v51;
}

// File Line: 741
// RVA: 0xEB7A0
void __fastcall UFG::HavokNavDaemon::FindPathMultiDestPrioritizedImmediate(
        UFG::HavokNavDaemon *this,
        UFG::FindPathMultiDestPrioritizedImmediateQuery *queryInput)
{
  __int64 v4; // rsi
  char v5; // r8
  unsigned int v6; // edi
  char v7; // cl
  UFG::NavManager *v8; // rax
  UFG::DaemonQueryOutput *m_pOutput; // rbx
  UFG::NavPath *v10; // r14
  __int64 v11; // rcx
  char v13; // al
  unsigned int size; // r15d
  __m128 v15; // xmm1
  __m128i v16; // xmm2
  UFG::NavParams *m_pNavParams; // rax
  unsigned int m_packedKey; // ecx
  char v19; // al
  unsigned int v20; // ecx
  unsigned int vfptr_high; // eax
  unsigned int v22; // r8d
  __int64 v23; // rcx
  unsigned int v24; // eax
  __int64 v25; // rdx
  __int64 v26; // rcx
  __int64 v27; // rdx
  char v28; // si
  int v29; // edi
  __int64 v30; // r14
  __int64 v31; // rbx
  void **v32; // [rsp+30h] [rbp-D0h] BYREF
  int v33; // [rsp+38h] [rbp-C8h]
  int v34; // [rsp+40h] [rbp-C0h]
  hkaiPathfindingUtil::FindPathInput v35; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v36; // [rsp+110h] [rbp+10h]
  NavMeshCostModifierMultiDestPrioritized v37; // [rsp+120h] [rbp+20h] BYREF
  UFG::NavManager *v38; // [rsp+1A8h] [rbp+A8h] BYREF
  UFG::NavManagerVtbl *vfptr; // [rsp+1B0h] [rbp+B0h]
  UFG::DaemonQueryOutput *v40; // [rsp+1B8h] [rbp+B8h]

  v36 = -2i64;
  v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v5 = ++*(_BYTE *)(v4 + 80);
  v6 = 1;
  *(_DWORD *)(v4 + 4i64 * v5) = 1;
  *(_QWORD *)(v4 + 8i64 * v5 + 16) = "AI::HavokNavDaemon::FindPathMultiDestPrioritizedImmediate 1";
  *(_QWORD *)(v4 + 8i64 * v5 + 48) = 0i64;
  v7 = *(_BYTE *)(v4 + 81);
  if ( v5 > v7 )
    v7 = v5;
  *(_BYTE *)(v4 + 81) = v7;
  v8 = UFG::NavManager::ms_pInstance;
  v38 = UFG::NavManager::ms_pInstance;
  m_pOutput = queryInput->m_pOutput;
  v40 = m_pOutput;
  v10 = UFG::g_NullPath;
  if ( *(UFG::NavPath **)&m_pOutput[1].m_status != UFG::g_NullPath )
  {
    if ( UFG::g_NullPath )
      ++UFG::g_NullPath->m_uRefCount;
    v11 = *(_QWORD *)&m_pOutput[1].m_status;
    if ( v11 )
    {
      if ( (*(_DWORD *)(v11 + 40))-- == 1 )
      {
        (**(void (__fastcall ***)(__int64, __int64))v11)(v11, 1i64);
        v8 = v38;
      }
    }
    *(_QWORD *)&m_pOutput[1].m_status = v10;
  }
  m_pOutput->m_status = Status_Failed;
  if ( hkaiWorld::getDynamicQueryMediator((hkaiWorld *)v8[3].vfptr) )
  {
    size = queryInput->m_aPrioritizedDestinations.size;
    hkaiPathfindingUtil::FindPathInput::FindPathInput(&v35, size);
    v15 = _mm_mul_ps(_xmm, (__m128)xmmword_141A71390);
    v16 = _mm_add_epi32(
            _mm_xor_si128(
              _mm_cvttps_epi32(v15),
              (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v15)),
            _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset));
    v35.m_searchParameters.m_up.m_vec[0] = _mm_extract_epi16(v16, 1);
    v35.m_searchParameters.m_up.m_vec[1] = _mm_extract_epi16(v16, 3);
    v35.m_searchParameters.m_up.m_vec[2] = _mm_extract_epi16(v16, 5);
    m_pNavParams = queryInput->m_pNavParams;
    v35.m_agentInfo.m_diameter = m_pNavParams->m_fRadius * 2.0;
    v35.m_agentInfo.m_filterInfo = m_pNavParams->m_flags;
    v35.m_searchParameters.m_lineOfSightFlags.m_storage = 0;
    NavMeshCostModifierMultiDestPrioritized::NavMeshCostModifierMultiDestPrioritized(&v37, queryInput);
    v35.m_searchParameters.m_costModifier = &v37;
    v33 = 0x1FFFF;
    LOBYTE(v34) = 1;
    v32 = &hkaiUFGAStarEdgeFilter::`vftable;
    v35.m_searchParameters.m_edgeFilter = (hkaiAstarEdgeFilter *)&v32;
    vfptr = v38[3].vfptr;
    v35.m_startPoint = queryInput->m_npFrom.m_hkvMeshPosition;
    m_packedKey = queryInput->m_npFrom.m_packedKey;
    v35.m_startFaceKey = m_packedKey;
    v19 = *(_BYTE *)(v4 + 80);
    if ( v19 > 0 )
    {
      *(_BYTE *)(v4 + 80) = v19 - 1;
    }
    else
    {
      *(_BYTE *)(v4 + 80) = 0;
      *(_DWORD *)v4 = 3;
      *(_QWORD *)(v4 + 16) = 0i64;
      *(_QWORD *)(v4 + 48) = 0i64;
    }
    if ( m_packedKey != -1 )
    {
      v20 = (unsigned int)m_pOutput[1].vfptr;
      if ( (int)(size - v20) <= 0 )
      {
        if ( v20 != size )
        {
          if ( v20 - size < v20 )
            LODWORD(m_pOutput[1].vfptr) = size;
          else
            LODWORD(m_pOutput[1].vfptr) = 0;
        }
      }
      else
      {
        vfptr_high = HIDWORD(m_pOutput[1].vfptr);
        if ( size > vfptr_high )
        {
          if ( vfptr_high )
            v6 = 2 * vfptr_high;
          for ( ; v6 < size; v6 *= 2 )
            ;
          if ( v6 <= 4 )
            v6 = 4;
          if ( v6 - size > 0x10000 )
            v6 = size + 0x10000;
          UFG::qArray<float,0>::Reallocate((UFG::qArray<float,0> *)&m_pOutput[1], v6, "m_afPathCosts");
        }
        LODWORD(m_pOutput[1].vfptr) = size;
      }
      v22 = 0;
      v23 = 0i64;
      if ( (int)size >= 4 )
      {
        v24 = ((size - 4) >> 2) + 1;
        v25 = v24;
        v22 = 4 * v24;
        do
        {
          *(_DWORD *)(*(_QWORD *)&m_pOutput[1].m_id + 4 * v23) = 2139095039;
          *(_DWORD *)(*(_QWORD *)&m_pOutput[1].m_id + 4 * v23 + 4) = 2139095039;
          *(_DWORD *)(*(_QWORD *)&m_pOutput[1].m_id + 4 * v23 + 8) = 2139095039;
          *(_DWORD *)(*(_QWORD *)&m_pOutput[1].m_id + 4 * v23 + 12) = 2139095039;
          v23 += 4i64;
          --v25;
        }
        while ( v25 );
      }
      if ( v22 < size )
      {
        v26 = 4 * v23;
        v27 = size - v22;
        do
        {
          *(_DWORD *)(v26 + *(_QWORD *)&m_pOutput[1].m_id) = 2139095039;
          v26 += 4i64;
          --v27;
        }
        while ( v27 );
      }
      *(float *)&v38 = FLOAT_N3_4028235e38;
      v28 = 0;
      v29 = 0;
      v30 = (queryInput->m_aPrioritizedDestinations.size >> 4) + 1;
      v31 = (__int64)vfptr;
      do
      {
        v28 |= ((__int64 (__fastcall *)(UFG::HavokNavDaemon *, __int64, UFG::FindPathMultiDestPrioritizedImmediateQuery *, hkaiPathfindingUtil::FindPathInput *, int, UFG::NavManager **, void **, int, int))this->vfptr[1].CancelQueueableQuery)(
                 this,
                 v31,
                 queryInput,
                 &v35,
                 v29,
                 &v38,
                 v32,
                 v33,
                 v34);
        v29 += 16;
        --v30;
      }
      while ( v30 );
      if ( v28 )
        v40->m_status = Status_Completed;
    }
    v32 = &hkBaseObject::`vftable;
    v37.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
    v35.vfptr = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathInput::`vftable;
    v35.m_goalFaceKeys.m_size = 0;
    if ( v35.m_goalFaceKeys.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v35.m_goalFaceKeys.m_data,
        4 * v35.m_goalFaceKeys.m_capacityAndFlags);
    v35.m_goalFaceKeys.m_data = 0i64;
    v35.m_goalFaceKeys.m_capacityAndFlags = 0x80000000;
    v35.m_goalPoints.m_size = 0;
    if ( v35.m_goalPoints.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v35.m_goalPoints.m_data,
        16 * v35.m_goalPoints.m_capacityAndFlags);
  }
  else
  {
    v13 = *(_BYTE *)(v4 + 80);
    if ( v13 > 0 )
    {
      *(_BYTE *)(v4 + 80) = v13 - 1;
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
void __fastcall UFG::HavokNavDaemon::FindPathToRegionImmediate(
        UFG::HavokNavDaemon *this,
        UFG::FindPathToRegionImmediateQuery *queryInput)
{
  __int64 v3; // rbx
  char v4; // r8
  char v5; // cl
  UFG::DaemonQueryOutput *m_pOutput; // rdi
  hkaiWorld *vfptr; // rbp
  char v8; // al
  unsigned int m_packedKey; // r8d
  char v10; // al
  char v11; // dl
  char v12; // cl
  int m_maxSearchIterations; // eax
  char v14; // al
  char v15; // dl
  char v16; // cl
  float y; // xmm1_4
  float z; // xmm2_4
  char v19; // al
  hkaiPathfindingUtil::NearestFeatureCallback callback; // [rsp+20h] [rbp-B8h] BYREF
  UFG::RegionComponent *m_pRegionComponent; // [rsp+28h] [rbp-B0h]
  char v22; // [rsp+30h] [rbp-A8h]
  UFG::qVector3 v23; // [rsp+34h] [rbp-A4h]
  __int64 v24; // [rsp+40h] [rbp-98h]
  hkaiPathfindingUtil::NearestFeatureInput input; // [rsp+50h] [rbp-88h] BYREF

  v24 = -2i64;
  v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v4 = ++*(_BYTE *)(v3 + 80);
  *(_DWORD *)(v3 + 4i64 * v4) = 1;
  *(_QWORD *)(v3 + 8i64 * v4 + 16) = "AI::HavokNavDaemon::FindPathToRegionImmediate 1";
  *(_QWORD *)(v3 + 8i64 * v4 + 48) = 0i64;
  v5 = *(_BYTE *)(v3 + 81);
  if ( v4 > v5 )
    v5 = v4;
  *(_BYTE *)(v3 + 81) = v5;
  m_pOutput = queryInput->m_pOutput;
  vfptr = (hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr;
  if ( hkaiWorld::getDynamicQueryMediator(vfptr) )
  {
    hkaiPathfindingUtil::NearestFeatureInput::NearestFeatureInput(&input);
    input.m_startPoint = queryInput->m_npFrom.m_hkvMeshPosition;
    m_packedKey = queryInput->m_npFrom.m_packedKey;
    v10 = *(_BYTE *)(v3 + 80);
    if ( v10 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v10 - 1;
    }
    else
    {
      *(_BYTE *)(v3 + 80) = 0;
      *(_DWORD *)v3 = 3;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_QWORD *)(v3 + 48) = 0i64;
    }
    if ( m_packedKey == -1 )
    {
      m_pOutput->m_status = Status_Failed;
    }
    else
    {
      v11 = ++*(_BYTE *)(v3 + 80);
      *(_DWORD *)(v3 + 4i64 * v11) = 1;
      *(_QWORD *)(v3 + 8i64 * v11 + 16) = "AI::HavokNavDaemon::FindPathToRegionImmediate 2";
      *(_QWORD *)(v3 + 8i64 * v11 + 48) = 0i64;
      v12 = *(_BYTE *)(v3 + 81);
      if ( v11 > v12 )
        v12 = v11;
      *(_BYTE *)(v3 + 81) = v12;
      input.m_startFaceKey = m_packedKey;
      m_maxSearchIterations = 512;
      if ( queryInput->m_maxSearchIterations >= 0 )
        m_maxSearchIterations = queryInput->m_maxSearchIterations;
      input.m_maxNumberOfIterations = m_maxSearchIterations;
      input.m_bufferSizes.m_maxOpenSetSizeBytes = 0x2000;
      input.m_bufferSizes.m_maxSearchStateSizeBytes = 37376;
      input.m_searchRadius = FLOAT_30_0;
      input.m_up.m_quad = _mm_unpacklo_ps(
                            _mm_unpacklo_ps(
                              (__m128)LODWORD(UFG::qVector3::msAxisZ.x),
                              (__m128)LODWORD(UFG::qVector3::msAxisZ.z)),
                            _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msAxisZ.y), (__m128)0i64));
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
      v15 = ++*(_BYTE *)(v3 + 80);
      *(_DWORD *)(v3 + 4i64 * v15) = 1;
      *(_QWORD *)(v3 + 8i64 * v15 + 16) = "AI::HavokNavDaemon::FindPathToRegionImmediate 3";
      *(_QWORD *)(v3 + 8i64 * v15 + 48) = 0i64;
      v16 = *(_BYTE *)(v3 + 81);
      if ( v15 > v16 )
        v16 = v15;
      *(_BYTE *)(v3 + 81) = v16;
      callback.vfptr = (hkaiPathfindingUtil::NearestFeatureCallbackVtbl *)&UFG::HavokRegionNearestFeatureCallback::`vftable;
      v22 = 0;
      v23 = UFG::qVector3::msZero;
      m_pRegionComponent = queryInput->m_pRegionComponent;
      hkaiPathfindingUtil::findNearestEdges(vfptr->m_streamingCollection.m_pntr, &input, &callback, 0i64);
      if ( v22 )
      {
        m_pOutput->m_status = Status_Completed;
        y = v23.y;
        z = v23.z;
        m_pOutput[1].m_status = LODWORD(v23.x);
        *((float *)&m_pOutput[1].m_status + 1) = y;
        *(float *)&m_pOutput[2].vfptr = z;
        LOBYTE(m_pOutput[2].m_id) = 0;
      }
      else
      {
        m_pOutput->m_status = Status_Failed;
      }
      v19 = *(_BYTE *)(v3 + 80);
      if ( v19 > 0 )
      {
        *(_BYTE *)(v3 + 80) = v19 - 1;
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
    m_pOutput->m_status = Status_Failed;
    v8 = *(_BYTE *)(v3 + 80);
    if ( v8 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v8 - 1;
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
void __fastcall UFG::HavokNavDaemon::FleeTraversalImmediate(
        UFG::HavokNavDaemon *this,
        UFG::FleeTraversalImmediateQuery *queryInput)
{
  __int64 v3; // rbx
  char v4; // r8
  char v5; // cl
  hkVector4f *m_pOutput; // rsi
  hkaiWorld *vfptr; // r15
  char v8; // al
  unsigned int m_packedKey; // r14d
  float v10; // xmm0_4
  float v11; // xmm0_4
  unsigned int v12; // r8d
  unsigned int size; // r9d
  UFG::FleeTraversalImmediateQuery::ThreatTarget *p; // r10
  unsigned int *v15; // rdx
  __int64 v16; // rcx
  int mMaxSearchIterations; // eax
  unsigned int m_startFaceKey; // xmm1_4
  int v19; // xmm2_4
  char v20; // al
  void **v21; // [rsp+20h] [rbp-B8h] BYREF
  int v22; // [rsp+28h] [rbp-B0h]
  char v23; // [rsp+30h] [rbp-A8h]
  int v24[6]; // [rsp+38h] [rbp-A0h] BYREF
  hkaiPathfindingUtil::NearestFeatureCallback callback; // [rsp+50h] [rbp-88h] BYREF
  char v26; // [rsp+58h] [rbp-80h]
  hkVector4f v27; // [rsp+60h] [rbp-78h]
  float v28; // [rsp+70h] [rbp-68h]
  float x; // [rsp+74h] [rbp-64h]
  hkaiPathfindingUtil::NearestFeatureInput input; // [rsp+78h] [rbp-60h] BYREF
  hkVector4f hkvNewPosition; // [rsp+E8h] [rbp+10h] BYREF
  void **v32; // [rsp+F8h] [rbp+20h] BYREF
  int v33; // [rsp+100h] [rbp+28h]
  char v34; // [rsp+108h] [rbp+30h]
  unsigned int v35; // [rsp+128h] [rbp+50h]
  __int128 v36[40]; // [rsp+138h] [rbp+60h]
  float v37; // [rsp+3B8h] [rbp+2E0h]
  float mRoadCost; // [rsp+3BCh] [rbp+2E4h]

  v27.m_quad.m128_u64[1] = -2i64;
  v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v4 = ++*(_BYTE *)(v3 + 80);
  *(_DWORD *)(v3 + 4i64 * v4) = 1;
  *(_QWORD *)(v3 + 8i64 * v4 + 16) = "AI::HavokNavDaemon::FleeTraversalImmediate";
  *(_QWORD *)(v3 + 8i64 * v4 + 48) = 0i64;
  v5 = *(_BYTE *)(v3 + 81);
  if ( v4 > v5 )
    v5 = v4;
  *(_BYTE *)(v3 + 81) = v5;
  m_pOutput = (hkVector4f *)queryInput->m_pOutput;
  vfptr = (hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr;
  if ( !hkaiWorld::getDynamicQueryMediator(vfptr)
    || (hkaiPathfindingUtil::NearestFeatureInput::NearestFeatureInput(&input),
        input.m_startPoint = queryInput->mEscapeOrigin.m_hkvMeshPosition,
        m_packedKey = queryInput->mEscapeOrigin.m_packedKey,
        m_packedKey == -1) )
  {
    m_pOutput[1].m_quad.m128_i32[0] = 4;
    v8 = *(_BYTE *)(v3 + 80);
    if ( v8 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v8 - 1;
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
    callback.vfptr = (hkaiPathfindingUtil::NearestFeatureCallbackVtbl *)&UFG::FleeTraversalNearestFeatureCallback::`vftable;
    x = UFG::qVector3::msZero.x;
    input.m_startFaceKey = LODWORD(UFG::qVector3::msZero.y);
    *(&input.m_startFaceKey + 1) = LODWORD(UFG::qVector3::msZero.z);
    v26 = 0;
    v27.m_quad = (__m128)input.m_startPoint;
    v10 = queryInput->mEscapeRadius * 0.2;
    if ( v10 >= 10.0 )
      v10 = FLOAT_10_0;
    v11 = UFG::qRandom(v10, &UFG::qDefaultSeed);
    v28 = (float)(queryInput->mEscapeRadius - v11) * (float)(queryInput->mEscapeRadius - v11);
    v33 = 0x1FFFF;
    v34 = 1;
    v32 = &UFG::FleeTraversalCostModifier::`vftable;
    v35 = 0;
    mRoadCost = FLOAT_5000_0;
    v37 = v28;
    if ( queryInput->mRoadCost >= 0.0 )
      mRoadCost = queryInput->mRoadCost;
    v12 = 0;
    size = queryInput->mThreats.size;
    if ( size )
    {
      p = queryInput->mThreats.p;
      do
      {
        v15 = (unsigned int *)&p[v12];
        v16 = 2i64 * v35++;
        v36[v16] = (__int128)_mm_unpacklo_ps(
                               _mm_unpacklo_ps((__m128)v15[2], (__m128)v15[4]),
                               _mm_unpacklo_ps((__m128)v15[3], (__m128)0i64));
        LODWORD(v36[v16 + 1]) = v15[16];
        ++v12;
      }
      while ( v12 < size );
    }
    input.m_agentInfo.m_filterInfo = queryInput->mpNavParams->m_flags;
    input.m_startFaceKey = m_packedKey;
    mMaxSearchIterations = 512;
    if ( queryInput->mMaxSearchIterations >= 0 )
      mMaxSearchIterations = queryInput->mMaxSearchIterations;
    input.m_maxNumberOfIterations = mMaxSearchIterations;
    input.m_bufferSizes.m_maxOpenSetSizeBytes = 0x2000;
    input.m_bufferSizes.m_maxSearchStateSizeBytes = 37376;
    input.m_searchRadius = FLOAT_500_0;
    input.m_costModifier = (hkaiAstarCostModifier *)&v32;
    input.m_up.m_quad = _mm_unpacklo_ps(
                          _mm_unpacklo_ps(
                            (__m128)LODWORD(UFG::qVector3::msAxisZ.x),
                            (__m128)LODWORD(UFG::qVector3::msAxisZ.z)),
                          _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msAxisZ.y), (__m128)0i64));
    v22 = 0x1FFFF;
    v23 = 1;
    v21 = &hkaiUFGAStarEdgeFilter::`vftable;
    input.m_edgeFilter = (hkaiAstarEdgeFilter *)&v21;
    hkaiPathfindingUtil::findNearestEdges(vfptr->m_streamingCollection.m_pntr, &input, &callback, 0i64);
    if ( v26
      && (m_startFaceKey = input.m_startFaceKey,
          v19 = *(&input.m_startFaceKey + 1),
          m_pOutput[2].m_quad.m128_f32[2] = x,
          m_pOutput[2].m_quad.m128_i32[3] = m_startFaceKey,
          m_pOutput[3].m_quad.m128_i32[0] = v19,
          m_pOutput[3].m_quad.m128_i8[8] = 0,
          (*(void (__fastcall **)(hkVector4f *))m_pOutput[2].m_quad.m128_u64[0])(m_pOutput + 2),
          (*(unsigned __int8 (__fastcall **)(hkVector4f *))(m_pOutput[2].m_quad.m128_u64[0] + 32))(m_pOutput + 2)) )
    {
      (*(void (__fastcall **)(hkVector4f *, int *))(m_pOutput[2].m_quad.m128_u64[0] + 40))(m_pOutput + 2, v24);
      m_pOutput[2].m_quad.m128_i32[2] = v24[0];
      m_pOutput[2].m_quad.m128_i32[3] = v24[1];
      m_pOutput[3].m_quad.m128_i32[0] = v24[2];
      m_pOutput[3].m_quad.m128_i8[8] = 0;
      m_pOutput[1].m_quad.m128_i32[0] = (UFG::HavokAIUtilGame::FindMeshPositionAwayFromWall(
                                           m_pOutput + 4,
                                           &hkvNewPosition,
                                           COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_0_38))) != 0)
                                      + 3;
    }
    else
    {
      m_pOutput[1].m_quad.m128_i32[0] = 4;
    }
    v20 = *(_BYTE *)(v3 + 80);
    if ( v20 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v20 - 1;
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
void __fastcall UFG::HavokNavDaemon::SpawnTraversalImmediate(
        UFG::HavokNavDaemon *this,
        UFG::SpawnTraversalImmediateQuery *queryInput)
{
  __int64 v3; // rbx
  char v4; // r8
  char v5; // cl
  hkVector4f *m_pOutput; // rsi
  hkaiWorld *vfptr; // r14
  char v8; // al
  unsigned int m_packedKey; // edx
  int mMaxSearchIterations; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  char v13; // al
  void **v14; // [rsp+20h] [rbp-E0h] BYREF
  int v15; // [rsp+28h] [rbp-D8h]
  char v16; // [rsp+30h] [rbp-D0h]
  int v17[6]; // [rsp+38h] [rbp-C8h] BYREF
  hkaiPathfindingUtil::NearestFeatureCallback callback; // [rsp+50h] [rbp-B0h] BYREF
  hkVector4f v19; // [rsp+60h] [rbp-A0h]
  float v20; // [rsp+70h] [rbp-90h]
  UFG::qVector3 v21; // [rsp+74h] [rbp-8Ch]
  char v22; // [rsp+80h] [rbp-80h]
  void **v23; // [rsp+90h] [rbp-70h] BYREF
  int v24; // [rsp+98h] [rbp-68h]
  char v25; // [rsp+A0h] [rbp-60h]
  float mRoadCost; // [rsp+C0h] [rbp-40h]
  hkVector4f v27; // [rsp+D0h] [rbp-30h]
  __m128 v28; // [rsp+E0h] [rbp-20h]
  __int64 v29; // [rsp+F0h] [rbp-10h]
  hkaiPathfindingUtil::NearestFeatureInput input; // [rsp+100h] [rbp+0h] BYREF
  hkVector4f hkvNewPosition; // [rsp+170h] [rbp+70h] BYREF

  v29 = -2i64;
  v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v4 = ++*(_BYTE *)(v3 + 80);
  *(_DWORD *)(v3 + 4i64 * v4) = 1;
  *(_QWORD *)(v3 + 8i64 * v4 + 16) = "AI::HavokNavDaemon::SpawnTraversalImmediate";
  *(_QWORD *)(v3 + 8i64 * v4 + 48) = 0i64;
  v5 = *(_BYTE *)(v3 + 81);
  if ( v4 > v5 )
    v5 = v4;
  *(_BYTE *)(v3 + 81) = v5;
  m_pOutput = (hkVector4f *)queryInput->m_pOutput;
  vfptr = (hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr;
  if ( !hkaiWorld::getDynamicQueryMediator(vfptr)
    || (hkaiPathfindingUtil::NearestFeatureInput::NearestFeatureInput(&input),
        input.m_startPoint = queryInput->mSearchOrigin.m_hkvMeshPosition,
        m_packedKey = queryInput->mSearchOrigin.m_packedKey,
        m_packedKey == -1) )
  {
    m_pOutput[1].m_quad.m128_i32[0] = 4;
    v8 = *(_BYTE *)(v3 + 80);
    if ( v8 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v8 - 1;
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
    callback.vfptr = (hkaiPathfindingUtil::NearestFeatureCallbackVtbl *)&UFG::SpawnTraversalNearestFeatureCallback::`vftable;
    v21 = UFG::qVector3::msZero;
    v22 = 0;
    v19.m_quad = (__m128)input.m_startPoint;
    v20 = queryInput->mSearchRadius * queryInput->mSearchRadius;
    v24 = 0x1FFFF;
    v25 = 1;
    v23 = &UFG::SpawnTraversalCostModifier::`vftable;
    mRoadCost = FLOAT_5000_0;
    v27.m_quad = 0i64;
    v28 = (__m128)_xmm;
    if ( queryInput->mRoadCost >= 0.0 )
      mRoadCost = queryInput->mRoadCost;
    v27.m_quad = (__m128)input.m_startPoint;
    v28 = _mm_unpacklo_ps(
            _mm_unpacklo_ps(
              (__m128)LODWORD(queryInput->mSearchDirection.x),
              (__m128)LODWORD(queryInput->mSearchDirection.z)),
            _mm_unpacklo_ps((__m128)LODWORD(queryInput->mSearchDirection.y), (__m128)0i64));
    input.m_agentInfo.m_filterInfo = queryInput->mpNavParams->m_flags;
    input.m_startFaceKey = m_packedKey;
    mMaxSearchIterations = 512;
    if ( queryInput->mMaxSearchIterations >= 0 )
      mMaxSearchIterations = queryInput->mMaxSearchIterations;
    input.m_maxNumberOfIterations = mMaxSearchIterations;
    input.m_bufferSizes.m_maxOpenSetSizeBytes = 0x2000;
    input.m_bufferSizes.m_maxSearchStateSizeBytes = 37376;
    input.m_searchRadius = FLOAT_500_0;
    input.m_costModifier = (hkaiAstarCostModifier *)&v23;
    input.m_up.m_quad = _mm_unpacklo_ps(
                          _mm_unpacklo_ps(
                            (__m128)LODWORD(UFG::qVector3::msAxisZ.x),
                            (__m128)LODWORD(UFG::qVector3::msAxisZ.z)),
                          _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msAxisZ.y), (__m128)0i64));
    v15 = 0x1FFFF;
    v16 = 1;
    v14 = &hkaiUFGAStarEdgeFilter::`vftable;
    input.m_edgeFilter = (hkaiAstarEdgeFilter *)&v14;
    hkaiPathfindingUtil::findNearestEdges(vfptr->m_streamingCollection.m_pntr, &input, &callback, 0i64);
    if ( v22
      && (y = v21.y,
          z = v21.z,
          m_pOutput[2].m_quad.m128_i32[2] = LODWORD(v21.x),
          m_pOutput[2].m_quad.m128_f32[3] = y,
          m_pOutput[3].m_quad.m128_f32[0] = z,
          m_pOutput[3].m_quad.m128_i8[8] = 0,
          (*(void (__fastcall **)(hkVector4f *))m_pOutput[2].m_quad.m128_u64[0])(m_pOutput + 2),
          (*(unsigned __int8 (__fastcall **)(hkVector4f *))(m_pOutput[2].m_quad.m128_u64[0] + 32))(m_pOutput + 2)) )
    {
      (*(void (__fastcall **)(hkVector4f *, int *))(m_pOutput[2].m_quad.m128_u64[0] + 40))(m_pOutput + 2, v17);
      m_pOutput[2].m_quad.m128_i32[2] = v17[0];
      m_pOutput[2].m_quad.m128_i32[3] = v17[1];
      m_pOutput[3].m_quad.m128_i32[0] = v17[2];
      m_pOutput[3].m_quad.m128_i8[8] = 0;
      m_pOutput[1].m_quad.m128_i32[0] = (UFG::HavokAIUtilGame::FindMeshPositionAwayFromWall(
                                           m_pOutput + 4,
                                           &hkvNewPosition,
                                           COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_0_38))) != 0)
                                      + 3;
    }
    else
    {
      m_pOutput[1].m_quad.m128_i32[0] = 4;
    }
    v13 = *(_BYTE *)(v3 + 80);
    if ( v13 > 0 )
    {
      *(_BYTE *)(v3 + 80) = v13 - 1;
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
char __fastcall UFG::HavokNavDaemon::GetPathFromHavok(
        UFG::HavokNavDaemon *this,
        UFG::NavPath *navPath,
        hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathOut,
        hkArray<unsigned int,hkContainerHeapAllocator> *visitedEdges)
{
  bool isDropDown; // r12
  unsigned int v7; // r15d
  __int64 v8; // rbx
  float z; // xmm6_4
  float y; // xmm7_4
  float x; // xmm8_4
  float v12; // xmm9_4
  float v13; // xmm10_4
  float v14; // xmm11_4
  hkaiPath::PathPoint *m_data; // rsi
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  __int64 v19; // rdi
  char v20; // dl
  char v21; // cl
  char m_storage; // al
  bool v23; // si
  char v24; // al
  char *v25; // rax
  bool v26; // r12
  hkaiPath::PathPoint *v27; // rcx
  char v28; // al
  _QWORD *v29; // rax
  __int64 v30; // rdx
  char v31; // al
  UFG::qVector3 vStartEdgeB; // [rsp+38h] [rbp-90h] BYREF
  UFG::qVector3 vStartEdgeA; // [rsp+48h] [rbp-80h] BYREF
  float v35; // [rsp+54h] [rbp-74h]
  float v36; // [rsp+58h] [rbp-70h] BYREF
  float v37; // [rsp+5Ch] [rbp-6Ch]
  UFG::qVector3 vPosition; // [rsp+60h] [rbp-68h] BYREF
  float v39; // [rsp+6Ch] [rbp-5Ch]
  UFG::qVector3 vEndEdgeA; // [rsp+70h] [rbp-58h] BYREF
  float v41; // [rsp+7Ch] [rbp-4Ch]
  __int64 v42; // [rsp+80h] [rbp-48h]
  UFG::NavWaypoint v43; // [rsp+88h] [rbp-40h] BYREF
  UFG::NavWaypoint item; // [rsp+D8h] [rbp+10h] BYREF
  char v45; // [rsp+1F8h] [rbp+130h]
  __int64 v46; // [rsp+200h] [rbp+138h]
  char *v47; // [rsp+208h] [rbp+140h]

  v42 = -2i64;
  ((void (__fastcall *)(UFG::HavokNavDaemon *, UFG::NavPath *, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *, hkArray<unsigned int,hkContainerHeapAllocator> *))this->vfptr[2].CancelQueueableQuery)(
    this,
    navPath,
    pathOut,
    visitedEdges);
  isDropDown = 0;
  LOBYTE(v47) = 0;
  v7 = 0;
  if ( pathOut->m_size > 0 )
  {
    v8 = 0i64;
    z = vStartEdgeA.z;
    y = vStartEdgeA.y;
    x = vStartEdgeA.x;
    v12 = vStartEdgeB.z;
    v13 = vStartEdgeB.y;
    v14 = vStartEdgeB.x;
    do
    {
      m_data = pathOut->m_data;
      if ( !pathOut->m_data[v8].m_flags.m_storage && m_data[v8].m_userEdgeData == 0x80000000 )
        return 1;
      v16 = m_data[v8].m_position.m_quad.m128_f32[0];
      v17 = m_data[v8].m_position.m_quad.m128_f32[1];
      v18 = m_data[v8].m_position.m_quad.m128_f32[2];
      vPosition.z = v16;
      v39 = v17;
      vEndEdgeA.x = v18;
      v19 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
      v20 = ++*(_BYTE *)(v19 + 80);
      *(_DWORD *)(v19 + 4i64 * v20) = 1;
      *(_QWORD *)(v19 + 8i64 * v20 + 16) = "AI::HavokNavDaemon::GetPathFromHavok";
      *(_QWORD *)(v19 + 8i64 * v20 + 48) = 0i64;
      v21 = *(_BYTE *)(v19 + 81);
      if ( v20 > v21 )
        v21 = v20;
      *(_BYTE *)(v19 + 81) = v21;
      v45 = 0;
      m_storage = m_data[v8].m_flags.m_storage;
      if ( (m_storage & 1) != 0 )
      {
        if ( !((unsigned __int8 (__fastcall *)(UFG::HavokNavDaemon *, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *, _QWORD, float *, float *))this->vfptr[3].SubmitImmediateQuery)(
                this,
                pathOut,
                v7,
                &vEndEdgeA.z,
                &v36) )
          goto LABEL_30;
        v23 = (m_data[v8].m_userEdgeData & 3) == 2;
        v24 = 1;
        x = vEndEdgeA.z;
        vStartEdgeA.x = vEndEdgeA.z;
        y = v41;
        vStartEdgeA.y = v41;
        z = vEndEdgeA.z;
        vStartEdgeA.z = vEndEdgeA.z;
        v14 = v36;
        vStartEdgeB.x = v36;
        v13 = v37;
        vStartEdgeB.y = v37;
        v12 = vPosition.x;
        vStartEdgeB.z = vPosition.x;
      }
      else
      {
        if ( (m_storage & 2) == 0 )
        {
          v26 = 1;
          if ( (signed int)(v7 + 1) < pathOut->m_size && (pathOut->m_data[v8 + 1].m_flags.m_storage & 1) != 0 )
          {
            v27 = pathOut->m_data;
            v26 = (float)((float)((float)((float)(v27[v8 + 1].m_position.m_quad.m128_f32[1] - v17)
                                        * (float)(v27[v8 + 1].m_position.m_quad.m128_f32[1] - v17))
                                + (float)((float)(v27[v8 + 1].m_position.m_quad.m128_f32[0] - v16)
                                        * (float)(v27[v8 + 1].m_position.m_quad.m128_f32[0] - v16)))
                        + (float)((float)(v27[v8 + 1].m_position.m_quad.m128_f32[2] - v18)
                                * (float)(v27[v8 + 1].m_position.m_quad.m128_f32[2] - v18))) >= 0.040000003;
          }
          UFG::NavWaypoint::NavWaypoint(&v43, (UFG::qVector3 *)&vPosition.z, 0i64);
          if ( m_data[v8].m_position.m_quad.m128_f32[3] >= 1000.0 )
          {
            v43.m_canSmooth = 0;
            goto LABEL_22;
          }
          if ( v26 )
LABEL_22:
            UFG::qArray<UFG::NavWaypoint,0>::Add((UFG::qArray<UFG::NavWaypoint,0> *)(v46 + 8), &v43, "qArray.Add");
          _((AMD_HD3D *)&v43);
          v23 = 0;
          v24 = 0;
          goto LABEL_25;
        }
        if ( !((unsigned __int8 (__fastcall *)(UFG::HavokNavDaemon *, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *, _QWORD, UFG::qVector3 *, UFG::qVector3 *))this->vfptr[3].SubmitImmediateQuery)(
                this,
                pathOut,
                v7,
                &vPosition,
                &vEndEdgeA) )
        {
LABEL_30:
          v29 = NtCurrentTeb()->Reserved1[11];
          v30 = v29[tls_index] + 16i64;
          v31 = *(_BYTE *)(v29[tls_index] + 96i64);
          if ( v31 > 0 )
          {
            *(_BYTE *)(v30 + 80) = v31 - 1;
          }
          else
          {
            *(_BYTE *)(v30 + 80) = 0;
            *(_DWORD *)v30 = 3;
            *(_QWORD *)(v30 + 16) = 0i64;
            *(_QWORD *)(v30 + 48) = 0i64;
          }
          return 0;
        }
        v23 = isDropDown;
        if ( (_BYTE)v47 )
        {
          v25 = UFG::qMalloc(0xA0ui64, "AI::GetPathFromHavok:NavObjectParkour", 0i64);
          v47 = v25;
          if ( v25 )
            UFG::NavObjectParkour::NavObjectParkour(
              (UFG::NavObjectParkour *)v25,
              &vStartEdgeA,
              &vStartEdgeB,
              &vEndEdgeA,
              &vPosition,
              isDropDown);
          vStartEdgeA.z = (float)(v14 + x) * 0.5;
          v35 = (float)(v13 + y) * 0.5;
          v36 = (float)(v12 + z) * 0.5;
          UFG::NavWaypoint::NavWaypoint(&item, (UFG::qVector3 *)&vStartEdgeA.z, (UFG::NavObject *)v25);
          UFG::qArray<UFG::NavWaypoint,0>::Add((UFG::qArray<UFG::NavWaypoint,0> *)(v46 + 8), &item, "qArray.Add");
          _((AMD_HD3D *)&item);
        }
        v24 = v45;
      }
LABEL_25:
      isDropDown = v23;
      LOBYTE(v47) = v24;
      v28 = *(_BYTE *)(v19 + 80);
      if ( v28 > 0 )
      {
        *(_BYTE *)(v19 + 80) = v28 - 1;
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
    while ( (signed int)v7 < pathOut->m_size );
  }
  return 1;
}

// File Line: 1259
// RVA: 0xE8240
void __fastcall UFG::HavokNavDaemon::BatchDeferredPathJobs(UFG::HavokNavDaemon *this)
{
  signed int size; // r14d
  UFG::NavManager *v3; // rsi
  float v4; // xmm0_4
  unsigned int v5; // r8d
  __int64 v6; // r10
  char v7; // dl
  char v8; // cl
  int v9; // r13d
  UFG::DaemonType v10; // r14d
  __int64 v11; // r15
  __int64 v12; // rcx
  __int64 v13; // rdi
  __int64 v14; // rsi
  unsigned int v15; // r12d
  hkaiDynamicNavMeshQueryMediator *DynamicQueryMediator; // rax
  hkVector4f v17; // xmm1
  hkVector4f v18; // xmm2
  unsigned int v19; // r8d
  unsigned int v20; // ecx
  hkaiNavMeshAStarCommand *m_data; // rdx
  __int64 v22; // r9
  unsigned int v23; // ecx
  int v24; // eax
  UFG::HavokNavDaemon::PathOutputEntry *v25; // rcx
  UFG::NavPath *v26; // rdi
  __int64 v27; // rcx
  bool v28; // zf
  void (__fastcall *LowHealthDefrag)(UFG::NavManager *); // rax
  __m128 v30; // xmm1
  __m128i v31; // xmm2
  unsigned int v32; // edi
  int v33; // ecx
  __int64 v34; // r15
  __int64 v35; // r12
  UFG::DaemonQueryInput *v36; // rdi
  UFG::DaemonQueryOutput *m_pOutput; // rsi
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  UFG::DaemonManager *v42; // rax
  __int64 v43; // rax
  UFG::DaemonQueryOutputVtbl *vfptr; // rcx
  __int64 v45; // rcx
  unsigned int v46; // eax
  __int64 v47; // r9
  int v48; // edx
  __int64 v49; // r8
  unsigned int v50; // eax
  char v51; // al
  UFG::DaemonQueryOutput output; // [rsp+20h] [rbp-E0h] BYREF
  __int64 v53; // [rsp+38h] [rbp-C8h]
  __int64 v54; // [rsp+40h] [rbp-C0h]
  __int64 v55; // [rsp+48h] [rbp-B8h]
  UFG::FindPathImmediateQuery job; // [rsp+50h] [rbp-B0h] BYREF
  UFG::NavManager *v57; // [rsp+100h] [rbp+0h]
  __int64 v58; // [rsp+108h] [rbp+8h]
  unsigned int meshUid; // [rsp+170h] [rbp+70h]
  __int64 v60; // [rsp+178h] [rbp+78h]
  unsigned int v61; // [rsp+180h] [rbp+80h]
  __int64 v62; // [rsp+188h] [rbp+88h]

  v58 = -2i64;
  size = this->m_PathRequests.size;
  v61 = size;
  if ( size )
  {
    v3 = UFG::NavManager::ms_pInstance;
    v57 = UFG::NavManager::ms_pInstance;
    if ( hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr) )
    {
      v4 = (float)size;
      if ( (float)size >= 16.0 )
        v4 = FLOAT_16_0;
      v5 = (int)v4;
      v6 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
      v54 = v6;
      v7 = ++*(_BYTE *)(v6 + 80);
      *(_DWORD *)(v6 + 4i64 * v7) = 1;
      *(_QWORD *)(v6 + 8i64 * v7 + 16) = "AI::HavokNavDaemon::BatchDeferredPathJobs";
      *(_QWORD *)(v6 + 8i64 * v7 + 48) = 0i64;
      v8 = *(_BYTE *)(v6 + 81);
      if ( v7 > v8 )
        v8 = v7;
      *(_BYTE *)(v6 + 81) = v8;
      v9 = 0;
      if ( UFG::HavokNavManager::ms_bEnablePathfindingMT )
      {
        v10 = DaemonType_Navigation;
        if ( !v5 )
          goto LABEL_36;
        v60 = 0i64;
        v11 = 0i64;
        v12 = 0i64;
        v62 = 0i64;
        v55 = v5;
        while ( 1 )
        {
          v13 = *(__int64 *)((char *)this->m_PathRequests.p + v12);
          v14 = *(_QWORD *)(v13 + 24);
          if ( *(_BYTE *)(v13 + 56)
            && ((meshUid = *(_DWORD *)(v13 + 84), v15 = *(_DWORD *)(v13 + 80), v15 == -1)
             || (DynamicQueryMediator = (hkaiDynamicNavMeshQueryMediator *)hkaiWorld::getDynamicQueryMediator((hkaiWorld *)UFG::NavManager::ms_pInstance[3].vfptr)) != 0i64
             && UFG::HavokAIUtilGame::IsFaceKeyValid(DynamicQueryMediator, v15, meshUid))
            && UFG::HavokNavPosition::HasBeenValidated((UFG::HavokNavPosition *)(v13 + 96)) )
          {
            v17.m_quad = *(__m128 *)(v13 + 64);
            v18.m_quad = *(__m128 *)(v13 + 128);
            v19 = *(_DWORD *)(v13 + 80);
            v20 = *(_DWORD *)(v13 + 144);
            if ( v19 != -1 && v20 != -1 )
            {
              m_data = this->m_commands.m_data;
              m_data[v11].m_startPoint = 0i64;
              m_data[v11].m_goalPoint = 0i64;
              *(_QWORD *)&m_data[v11].m_startFaceKey = -1i64;
              m_data[v11].m_multipleGoalPoints = 0i64;
              m_data[v11].m_multipleGoalFaceKeys = 0i64;
              m_data[v11].m_numGoals = 0;
              *(_QWORD *)&m_data[v11].m_maxNumberOfIterations = 100000i64;
              m_data[v11].m_agentInfo.m_filterInfo = 0;
              m_data[v11].m_AStarOutput = 0i64;
              m_data[v11].m_edgesOut = 0i64;
              m_data[v11].m_maxEdgesOut = 0;
              m_data[v11].m_pointsOut = 0i64;
              m_data[v11].m_maxPointsOut = 0;
              v22 = v60;
              *(hkVector4f *)((char *)this->m_goals.m_data + v60) = (hkVector4f)v18.m_quad;
              *(unsigned int *)((char *)this->m_goalFaces.m_data + v60) = v20;
              m_data[v11].m_startPoint = (hkVector4f)v17.m_quad;
              m_data[v11].m_startFaceKey = v19;
              v23 = *(unsigned int *)((char *)this->m_goalFaces.m_data + v60);
              m_data[v11].m_goalPoint = *(hkVector4f *)((char *)this->m_goals.m_data + v60);
              m_data[v11].m_goalFaceKey = v23;
              m_data[v11].m_multipleGoalPoints = 0i64;
              m_data[v11].m_multipleGoalFaceKeys = 0i64;
              m_data[v11].m_numGoals = 1;
              m_data[v11].m_edgesOut = *(unsigned int **)((char *)&this->m_outputs.m_data->m_data + v60);
              m_data[v11].m_maxEdgesOut = *(int *)((char *)&this->m_outputs.m_data->m_size + v60);
              m_data[v11].m_pointsOut = *(hkaiPath::PathPoint **)((char *)&this->m_smoothedPaths.m_data->m_data + v60);
              m_data[v11].m_maxPointsOut = *(int *)((char *)&this->m_smoothedPaths.m_data->m_size + v60);
              m_data[v11].m_AStarOutput = &this->m_aStarOutputs.m_data[v10];
              m_data[v11].m_agentInfo.m_diameter = **(float **)(v13 + 160) * 2.0;
              m_data[v11].m_agentInfo.m_filterInfo = *(_DWORD *)(*(_QWORD *)(v13 + 160) + 4i64);
              v24 = 2048;
              if ( *(int *)(v13 + 168) >= 0 )
                v24 = *(_DWORD *)(v13 + 168);
              m_data[v11].m_maxNumberOfIterations = v24;
              output.m_id = v10;
              LOBYTE(output.m_internalType) = 1;
              if ( this->m_havokResults.m_size == (this->m_havokResults.m_capacityAndFlags & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_havokResults, 16);
                v22 = v60;
              }
              v25 = &this->m_havokResults.m_data[this->m_havokResults.m_size];
              if ( v25 )
              {
                v25->m_pUserOutput = (UFG::FindPathOutput *)v14;
                *(_QWORD *)&v25->m_iHavokDataIndex = *(_QWORD *)&output.m_id;
              }
              ++this->m_havokResults.m_size;
              ++v10;
              ++v11;
              v60 = v22 + 16;
              goto LABEL_34;
            }
            UFG::NavPathRefPtr::operator=((UFG::NavPathRefPtr *)(v14 + 24), UFG::g_NullPath);
            ++v9;
          }
          else
          {
            v26 = UFG::g_NullPath;
            if ( *(UFG::NavPath **)(v14 + 24) != UFG::g_NullPath )
            {
              if ( UFG::g_NullPath )
                ++UFG::g_NullPath->m_uRefCount;
              v27 = *(_QWORD *)(v14 + 24);
              if ( v27 )
              {
                v28 = (*(_DWORD *)(v27 + 40))-- == 1;
                if ( v28 )
                  (**(void (__fastcall ***)(__int64, __int64))v27)(v27, 1i64);
              }
              *(_QWORD *)(v14 + 24) = v26;
            }
            ++v9;
          }
          *(_DWORD *)(v14 + 16) = 4;
LABEL_34:
          v12 = v62 + 8;
          v62 += 8i64;
          if ( !--v55 )
          {
            v3 = v57;
LABEL_36:
            LowHealthDefrag = v3[3].vfptr->LowHealthDefrag;
            LOWORD(job.vfptr) = 2305;
            BYTE2(job.vfptr) = 1;
            HIDWORD(job.vfptr) = -65392;
            *(_OWORD *)&job.m_mode = 0i64;
            *(_QWORD *)&job.m_npFrom.m_vPosition.x = 0i64;
            *(_QWORD *)&job.m_npFrom.m_vPosition.z = 0i64;
            *(_DWORD *)&job.m_npFrom.m_bValid = 66305;
            *((_WORD *)&job.m_npFrom.m_bValid + 2) = 1;
            *(&job.m_npFrom.m_bValid + 6) = 1;
            job.m_npFrom.m_hkvMeshPosition = (hkVector4f)_xmm_bf8000007f7fffee3c23d70a3f800000;
            *(float *)&job.m_npFrom.m_packedKey = FLOAT_N1_0;
            *(_QWORD *)&job.m_npFrom.m_aiMeshUid = 0i64;
            *((_QWORD *)&job.m_npFrom.m_aiMeshUid + 1) = 0i64;
            LODWORD(job.m_npFrom.vfptr) = -2147450880;
            WORD2(job.m_npFrom.vfptr) = 0x8000;
            LODWORD(job.m_npTo.m_vPosition.x) = 100000;
            *(_QWORD *)&job.m_npTo.m_bValid = 0i64;
            job.m_npTo.m_hkvMeshPosition.m_quad.m128_i32[0] = 0;
            *(_QWORD *)&job.m_npTo.m_vPosition.z = *((_QWORD *)LowHealthDefrag + 4);
            v30 = _mm_mul_ps(_xmm, (__m128)xmmword_141A71390);
            v31 = _mm_add_epi32(
                    _mm_xor_si128(
                      _mm_cvttps_epi32(v30),
                      (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v30)),
                    _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset));
            LOWORD(job.m_npFrom.vfptr) = _mm_extract_epi16(v31, 1);
            WORD1(job.m_npFrom.vfptr) = _mm_extract_epi16(v31, 3);
            WORD2(job.m_npFrom.vfptr) = _mm_extract_epi16(v31, 5);
            *(_QWORD *)&job.m_npFrom.m_vPosition.x = v3 + 14;
            output.m_id = 0x1FFFF;
            LOBYTE(output.m_status) = 1;
            output.vfptr = (UFG::DaemonQueryOutputVtbl *)&hkaiUFGAStarEdgeFilter::`vftable;
            *(_QWORD *)&job.m_npFrom.m_vPosition.z = v3 + 20;
            v32 = 0;
            if ( v10 )
            {
              do
              {
                v33 = NavDaemonConst::kCommandsPerJob;
                if ( v10 - v32 < NavDaemonConst::kCommandsPerJob )
                  v33 = v10 - v32;
                *(_QWORD *)&job.m_npTo.m_bValid = &this->m_commands.m_data[v32];
                job.m_npTo.m_hkvMeshPosition.m_quad.m128_i32[0] = v33;
                hkJobQueue::addJob((hkJobQueue *)v3[10].vfptr, (hkJob *)&job, JOB_HIGH_PRIORITY);
                v32 += job.m_npTo.m_hkvMeshPosition.m_quad.m128_u32[0];
              }
              while ( v32 < v10 );
            }
            output.vfptr = (UFG::DaemonQueryOutputVtbl *)&hkBaseObject::`vftable;
LABEL_64:
            v6 = v54;
            goto LABEL_65;
          }
        }
      }
      v10 = (int)v4;
      if ( v5 >= 2 )
        v10 = 2;
      if ( v10 )
      {
        v34 = 0i64;
        v35 = (unsigned int)v10;
        do
        {
          v36 = this->m_PathRequests.p[v34];
          m_pOutput = v36->m_pOutput;
          UFG::FindPathImmediateQuery::FindPathImmediateQuery(&job);
          *(_QWORD *)&output.m_id = 0i64;
          output.m_status = Status_Undefined;
          output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FindPathOutput::`vftable;
          v53 = 0i64;
          v38 = *(float *)&v36[1].m_internalType;
          v39 = *(float *)&v36[1].m_mode;
          LODWORD(job.m_npFrom.m_vPosition.x) = v36[1].m_daemonType;
          job.m_npFrom.m_vPosition.y = v38;
          job.m_npFrom.m_vPosition.z = v39;
          if ( LOBYTE(v36[1].m_pOutput) )
          {
            job.m_npFrom.m_bValid = (bool)v36[1].m_pOutput;
            job.m_npFrom.m_hkvMeshPosition = *(hkVector4f *)&v36[2].vfptr;
            job.m_npFrom.m_packedKey = v36[2].m_mode;
            job.m_npFrom.m_aiMeshUid = *((_DWORD *)&v36[2].m_mode + 1);
          }
          else
          {
            job.m_npFrom.m_bValid = 0;
          }
          v40 = *(float *)&v36[3].m_internalType;
          v41 = *(float *)&v36[3].m_mode;
          LODWORD(job.m_npTo.m_vPosition.x) = v36[3].m_daemonType;
          job.m_npTo.m_vPosition.y = v40;
          job.m_npTo.m_vPosition.z = v41;
          if ( LOBYTE(v36[3].m_pOutput) )
          {
            job.m_npTo.m_bValid = (bool)v36[3].m_pOutput;
            job.m_npTo.m_hkvMeshPosition = *(hkVector4f *)&v36[4].vfptr;
            job.m_npTo.m_packedKey = v36[4].m_mode;
            job.m_npTo.m_aiMeshUid = *((_DWORD *)&v36[4].m_mode + 1);
          }
          else
          {
            job.m_npTo.m_bValid = 0;
          }
          job.m_pNavParams = (UFG::NavParams *)v36[5].vfptr;
          job.m_maxSearchIterations = v36[5].m_daemonType;
          v42 = UFG::DaemonManager::Instance();
          UFG::DaemonManager::SubmitQuery(v42, &job, &output);
          v43 = v53;
          if ( m_pOutput[1].vfptr != (UFG::DaemonQueryOutputVtbl *)v53 )
          {
            if ( v53 )
            {
              ++*(_DWORD *)(v53 + 40);
              v43 = v53;
            }
            vfptr = m_pOutput[1].vfptr;
            if ( vfptr )
            {
              v28 = LODWORD(vfptr[5].__vecDelDtor)-- == 1;
              if ( v28 )
                (*(void (__fastcall **)(UFG::DaemonQueryOutputVtbl *, __int64))vfptr->__vecDelDtor)(vfptr, 1i64);
              v43 = v53;
            }
            m_pOutput[1].vfptr = (UFG::DaemonQueryOutputVtbl *)v43;
          }
          m_pOutput->m_status = output.m_status;
          v45 = v53;
          if ( v53 )
          {
            --*(_DWORD *)(v53 + 40);
            if ( !*(_DWORD *)(v45 + 40) )
              (**(void (__fastcall ***)(__int64, __int64))v45)(v45, 1i64);
          }
          output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
          job.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
          ++v34;
          --v35;
        }
        while ( v35 );
        v9 = 0;
        goto LABEL_64;
      }
LABEL_65:
      v46 = v10 + v9;
      if ( v10 + v9 < v61 )
      {
        if ( v46 )
        {
          v47 = v46;
          do
          {
            v48 = 1;
            if ( this->m_PathRequests.size != 1 )
            {
              v49 = 1i64;
              do
              {
                this->m_PathRequests.p[v49 - 1] = this->m_PathRequests.p[v49];
                ++v48;
                ++v49;
              }
              while ( v48 != this->m_PathRequests.size );
            }
            v50 = this->m_PathRequests.size;
            if ( v50 > 1 )
              this->m_PathRequests.size = v50 - 1;
            else
              this->m_PathRequests.size = 0;
            --v47;
          }
          while ( v47 );
        }
      }
      else
      {
        this->m_PathRequests.size = 0;
      }
      v51 = *(_BYTE *)(v6 + 80);
      if ( v51 > 0 )
      {
        *(_BYTE *)(v6 + 80) = v51 - 1;
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
  __int64 v1; // rbx
  char v2; // dl
  char v3; // cl
  UFG::NavManager *v4; // rdx
  char v5; // al

  v1 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v2 = ++*(_BYTE *)(v1 + 80);
  *(_DWORD *)(v1 + 4i64 * v2) = 1;
  *(_QWORD *)(v1 + 8i64 * v2 + 16) = "AI::HavokNavDaemon::StartUpdate";
  *(_QWORD *)(v1 + 8i64 * v2 + 48) = 0i64;
  v3 = *(_BYTE *)(v1 + 81);
  if ( v2 > v3 )
    v3 = v2;
  v4 = UFG::NavManager::ms_pInstance;
  *(_BYTE *)(v1 + 81) = v3;
  (*((void (__fastcall **)(UFG::NavManagerVtbl *, UFG::NavManagerVtbl *, __int64))v4[11].vfptr->__vecDelDtor + 11))(
    v4[11].vfptr,
    v4[10].vfptr,
    9i64);
  v5 = *(_BYTE *)(v1 + 80);
  if ( v5 > 0 )
  {
    *(_BYTE *)(v1 + 80) = v5 - 1;
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
  __int64 v1; // rbx
  char v2; // dl
  char v3; // cl
  UFG::NavManager *v4; // rax
  char v5; // al

  v1 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v2 = ++*(_BYTE *)(v1 + 80);
  *(_DWORD *)(v1 + 4i64 * v2) = 1;
  *(_QWORD *)(v1 + 8i64 * v2 + 16) = "AI::HavokNavDaemon::CompleteUpdate";
  *(_QWORD *)(v1 + 8i64 * v2 + 48) = 0i64;
  v3 = *(_BYTE *)(v1 + 81);
  v4 = UFG::NavManager::ms_pInstance;
  if ( v2 > v3 )
    v3 = v2;
  *(_BYTE *)(v1 + 81) = v3;
  (*((void (__fastcall **)(UFG::NavManagerVtbl *))v4[11].vfptr->__vecDelDtor + 4))(v4[11].vfptr);
  v5 = *(_BYTE *)(v1 + 80);
  if ( v5 > 0 )
  {
    *(_BYTE *)(v1 + 80) = v5 - 1;
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
  unsigned int m_size; // r8d
  __int64 v3; // r14
  char v4; // dl
  char v5; // cl
  __int64 v6; // r15
  __int64 v7; // rbp
  UFG::HavokNavDaemon::PathOutputEntry *m_data; // rax
  UFG::FindPathOutput *m_pUserOutput; // rdi
  __int64 v10; // rcx
  __int64 v11; // r8
  hkaiAstarOutputParameters *v12; // rdx
  int m_numIterations; // ecx
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *v14; // r12
  hkArray<unsigned int,hkContainerHeapAllocator> *v15; // r13
  char *v16; // rax
  char *v17; // rbx
  UFG::NavPath *m_pNavPath; // rcx
  char v20; // al
  __int64 v21; // [rsp+20h] [rbp-48h]

  v21 = -2i64;
  if ( UFG::HavokNavManager::ms_bEnablePathfindingMT )
  {
    m_size = this->m_havokResults.m_size;
    if ( m_size )
    {
      v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
      v4 = ++*(_BYTE *)(v3 + 80);
      *(_DWORD *)(v3 + 4i64 * v4) = 1;
      *(_QWORD *)(v3 + 8i64 * v4 + 16) = "AI::HavokNavDaemon::ReadDeferredPathJobs";
      *(_QWORD *)(v3 + 8i64 * v4 + 48) = 0i64;
      v5 = *(_BYTE *)(v3 + 81);
      if ( v4 > v5 )
        v5 = v4;
      *(_BYTE *)(v3 + 81) = v5;
      v6 = 0i64;
      v7 = m_size;
      do
      {
        m_data = this->m_havokResults.m_data;
        m_pUserOutput = m_data[v6].m_pUserOutput;
        v10 = *(_QWORD *)&m_data[v6].m_iHavokDataIndex;
        if ( BYTE4(v10) )
        {
          v11 = (int)v10;
          v12 = this->m_aStarOutputs.m_data;
          m_numIterations = v12[v11].m_numIterations;
          if ( this->m_maxIterationsStat > m_numIterations )
            m_numIterations = this->m_maxIterationsStat;
          this->m_maxIterationsStat = m_numIterations;
          if ( v12[v11].m_status.m_storage == 1 )
          {
            v14 = &this->m_smoothedPaths.m_data[v11];
            v15 = &this->m_outputs.m_data[v11];
            v16 = UFG::qMalloc(0x30ui64, "AI::ReadDeferredPathJobs:NavPath", 0i64);
            v17 = v16;
            if ( v16 )
            {
              *(_QWORD *)v16 = &UFG::NavPath::`vftable;
              *((_QWORD *)v16 + 2) = 0i64;
              *((_QWORD *)v16 + 1) = 0i64;
              *((_QWORD *)v16 + 4) = 0i64;
              *((_QWORD *)v16 + 3) = 0i64;
              *((_DWORD *)v16 + 10) = 0;
            }
            else
            {
              v17 = 0i64;
            }
            if ( (char *)m_pUserOutput->m_pPath.m_pNavPath != v17 )
            {
              if ( v17 )
                ++*((_DWORD *)v17 + 10);
              m_pNavPath = m_pUserOutput->m_pPath.m_pNavPath;
              if ( m_pNavPath )
              {
                if ( m_pNavPath->m_uRefCount-- == 1 )
                  m_pNavPath->vfptr->__vecDelDtor(m_pNavPath, 1u);
              }
              m_pUserOutput->m_pPath.m_pNavPath = (UFG::NavPath *)v17;
            }
            m_pUserOutput->m_status = 4
                                    - (((unsigned __int8 (__fastcall *)(UFG::HavokNavDaemon *, UFG::NavPath *, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *, hkArray<unsigned int,hkContainerHeapAllocator> *, __int64))this->vfptr[2].SubmitImmediateQuery)(
                                         this,
                                         m_pUserOutput->m_pPath.m_pNavPath,
                                         v14,
                                         v15,
                                         v21) != 0);
          }
          else
          {
            m_pUserOutput->m_status = Status_Failed;
          }
        }
        ++v6;
        --v7;
      }
      while ( v7 );
      this->m_havokResults.m_size = 0;
      v20 = *(_BYTE *)(v3 + 80);
      if ( v20 > 0 )
      {
        *(_BYTE *)(v3 + 80) = v20 - 1;
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
}

