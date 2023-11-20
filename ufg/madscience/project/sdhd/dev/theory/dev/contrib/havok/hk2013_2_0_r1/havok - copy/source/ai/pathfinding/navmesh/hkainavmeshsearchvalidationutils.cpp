// File Line: 15
// RVA: 0xC02730
void __fastcall checkFaceKey(hkaiStreamingCollection *collection, unsigned int key, bool *sectionValid, bool *indexValid, bool *faceValid)
{
  __int64 v5; // rax
  unsigned int v6; // er10
  hkaiNavMeshInstance *v7; // rdx
  int v8; // er10
  char v9; // al
  char v10; // [rsp+10h] [rbp+10h]

  *sectionValid = 0;
  *indexValid = 0;
  *faceValid = 0;
  v5 = key >> 22;
  v6 = key;
  if ( (signed int)v5 >= collection->m_instances.m_size )
    v7 = 0i64;
  else
    v7 = collection->m_instances.m_data[v5].m_instancePtr;
  if ( v7 )
  {
    *sectionValid = 1;
    v8 = v6 & 0x3FFFFF;
    if ( v8 < v7->m_numOriginalFaces + v7->m_ownedFaces.m_size )
    {
      *indexValid = 1;
      if ( v7->m_faceFlags.m_size )
        v10 = v7->m_faceFlags.m_data[v8].m_storage;
      else
        v10 = 0;
      v9 = *faceValid;
      if ( !(v10 & 1) )
        v9 = 1;
      *faceValid = v9;
    }
  }
}

// File Line: 82
// RVA: 0xC02570
char __fastcall hkaiNavMeshSearchValidationUtils::validateNavMeshAStarData(hkaiStreamingCollection *collection, hkVector4f *startPoint, unsigned int startFaceKey, int numGoalPoints, hkVector4f *goalPoints, int numGoalFaceKeys, const unsigned int *goalFaceKeys, hkaiNavMeshPathSearchParameters *searchParameters, hkaiAgentTraversalInfo *agentInfo, unsigned int *validGoalsMask)
{
  __int64 v10; // rbp
  const unsigned int *v11; // rsi
  int v12; // er12
  unsigned int v13; // er13
  bool v14; // r10
  signed int v15; // ebx
  bool v16; // r8
  bool v17; // r11
  int v18; // er14
  bool v19; // r9
  int v20; // er15
  int v21; // edi
  signed int v22; // eax
  const unsigned int *v23; // rcx
  __int64 v24; // rdx
  unsigned int v25; // edx
  bool sectionValid; // [rsp+30h] [rbp-48h]
  bool indexValid; // [rsp+31h] [rbp-47h]
  bool faceValid; // [rsp+32h] [rbp-46h]
  hkaiStreamingCollection *collectiona; // [rsp+80h] [rbp+8h]
  bool v31; // [rsp+90h] [rbp+18h]
  bool v32; // [rsp+98h] [rbp+20h]

  collectiona = collection;
  v10 = (unsigned int)numGoalFaceKeys;
  v11 = goalFaceKeys;
  v12 = 0;
  v13 = startFaceKey;
  v14 = startFaceKey != -1;
  v15 = 1;
  v16 = numGoalFaceKeys <= 0;
  *validGoalsMask = 0;
  v17 = numGoalPoints <= 0;
  v18 = 0;
  v19 = numGoalPoints == (_DWORD)v10;
  v20 = 0;
  v21 = 0;
  v22 = 1;
  if ( (signed int)v10 > 0 )
  {
    v23 = v11;
    v24 = (unsigned int)v10;
    do
    {
      if ( *v23 != -1 )
        v12 |= v22;
      v22 = __ROL4__(v22, 1);
      ++v23;
      --v24;
    }
    while ( v24 );
  }
  if ( !v14 || v16 || v17 || !v19 || !v12 )
    return 0;
  sectionValid = 0;
  indexValid = 0;
  faceValid = 0;
  checkFaceKey(collectiona, v13, &sectionValid, &indexValid, &faceValid);
  if ( (signed int)v10 > 0 )
  {
    do
    {
      v25 = *v11;
      if ( *v11 != -1 )
      {
        LOBYTE(numGoalFaceKeys) = 0;
        v31 = 0;
        v32 = 0;
        checkFaceKey(collectiona, v25, (bool *)&numGoalFaceKeys, &v31, &v32);
        if ( (_BYTE)numGoalFaceKeys )
          v18 |= v15;
        if ( v31 )
          v20 |= v15;
        if ( v32 )
          v21 |= v15;
      }
      v15 = __ROL4__(v15, 1);
      ++v11;
      --v10;
    }
    while ( v10 );
  }
  if ( !sectionValid || !indexValid || !v18 || !v20 || !faceValid || !v21 )
    return 0;
  *validGoalsMask = v12 & v18 & v20 & v21;
  return 1;
}

// File Line: 268
// RVA: 0xC02500
bool __fastcall hkaiNavMeshSearchValidationUtils::validateFindPathInput(hkaiStreamingCollection *collection, hkaiPathfindingUtil::FindPathInput *input, unsigned int *validGoalsMask)
{
  return hkaiNavMeshSearchValidationUtils::validateNavMeshAStarData(
           collection,
           &input->m_startPoint,
           input->m_startFaceKey,
           input->m_goalPoints.m_size,
           input->m_goalPoints.m_data,
           input->m_goalFaceKeys.m_size,
           input->m_goalFaceKeys.m_data,
           &input->m_searchParameters,
           &input->m_agentInfo,
           validGoalsMask);
}

