// File Line: 67
// RVA: 0xE24B00
void __fastcall hkpSaveContactPointsEndianUtil::swapEndianType(hkpAgentNnMachineTimEntry *entry)
{
  char m_timeOfSeparatingNormal_low; // dl
  __int64 v2; // r8
  char v3; // dl
  char *v4; // rax
  char v5; // cl
  char v6; // dl
  char v7; // dl

  m_timeOfSeparatingNormal_low = LOBYTE(entry->m_timeOfSeparatingNormal);
  v2 = 4i64;
  LOBYTE(entry->m_timeOfSeparatingNormal) = HIBYTE(entry->m_timeOfSeparatingNormal);
  HIBYTE(entry->m_timeOfSeparatingNormal) = m_timeOfSeparatingNormal_low;
  v3 = BYTE1(entry->m_timeOfSeparatingNormal);
  BYTE1(entry->m_timeOfSeparatingNormal) = BYTE2(entry->m_timeOfSeparatingNormal);
  v4 = &entry->m_separatingNormal.m_quad.m128_i8[3];
  BYTE2(entry->m_timeOfSeparatingNormal) = v3;
  do
  {
    v5 = *v4;
    v6 = *(v4 - 3);
    v4 += 4;
    *(v4 - 7) = v5;
    *(v4 - 4) = v6;
    v7 = *(v4 - 6);
    *(v4 - 6) = *(v4 - 5);
    *(v4 - 5) = v7;
    --v2;
  }
  while ( v2 );
}

// File Line: 78
// RVA: 0xE24A60
void __fastcall hkpSaveContactPointsEndianUtil::swapEndianType(hkpAgent1nMachineTimEntry *entry)
{
  char m_shapeKeyA; // dl
  char v3; // dl
  char m_shapeKeyB_high; // al
  char m_shapeKeyB; // cl
  char v6; // cl
  char m_timeOfSeparatingNormal_low; // cl
  char v8; // cl
  char *v9; // rax
  __int64 v10; // r8
  char v11; // cl
  char v12; // dl
  char v13; // dl

  m_shapeKeyA = entry->m_shapeKeyPair.m_shapeKeyA;
  LOBYTE(entry->m_shapeKeyPair.m_shapeKeyA) = HIBYTE(entry->m_shapeKeyPair.m_shapeKeyA);
  HIBYTE(entry->m_shapeKeyPair.m_shapeKeyA) = m_shapeKeyA;
  v3 = BYTE1(entry->m_shapeKeyPair.m_shapeKeyA);
  BYTE1(entry->m_shapeKeyPair.m_shapeKeyA) = BYTE2(entry->m_shapeKeyPair.m_shapeKeyA);
  BYTE2(entry->m_shapeKeyPair.m_shapeKeyA) = v3;
  m_shapeKeyB_high = HIBYTE(entry->m_shapeKeyPair.m_shapeKeyB);
  m_shapeKeyB = entry->m_shapeKeyPair.m_shapeKeyB;
  LOBYTE(entry->m_shapeKeyPair.m_shapeKeyB) = m_shapeKeyB_high;
  HIBYTE(entry->m_shapeKeyPair.m_shapeKeyB) = m_shapeKeyB;
  v6 = BYTE1(entry->m_shapeKeyPair.m_shapeKeyB);
  BYTE1(entry->m_shapeKeyPair.m_shapeKeyB) = BYTE2(entry->m_shapeKeyPair.m_shapeKeyB);
  BYTE2(entry->m_shapeKeyPair.m_shapeKeyB) = v6;
  m_timeOfSeparatingNormal_low = LOBYTE(entry->m_timeOfSeparatingNormal);
  LOBYTE(entry->m_timeOfSeparatingNormal) = HIBYTE(entry->m_timeOfSeparatingNormal);
  HIBYTE(entry->m_timeOfSeparatingNormal) = m_timeOfSeparatingNormal_low;
  v8 = BYTE1(entry->m_timeOfSeparatingNormal);
  BYTE1(entry->m_timeOfSeparatingNormal) = BYTE2(entry->m_timeOfSeparatingNormal);
  v9 = &entry->m_separatingNormal.m_quad.m128_i8[3];
  BYTE2(entry->m_timeOfSeparatingNormal) = v8;
  v10 = 4i64;
  do
  {
    v11 = *v9;
    v12 = *(v9 - 3);
    v9 += 4;
    *(v9 - 7) = v11;
    *(v9 - 4) = v12;
    v13 = *(v9 - 6);
    *(v9 - 6) = *(v9 - 5);
    *(v9 - 5) = v13;
    --v10;
  }
  while ( v10 );
}

// File Line: 97
// RVA: 0xE24C80
void __fastcall hkpSaveContactPointsEndianUtil::swapEndianType(hkpBoxBoxManifold *manifold)
{
  int v2; // ecx
  __int64 v3; // rax
  hkpFeatureContactPoint *v4; // r8
  char m_contactPointId; // dl
  char *v6; // rax
  __int64 v7; // r8
  char v8; // cl
  char v9; // dl
  char v10; // dl
  char m_manifoldNormalB; // cl
  char v12; // cl

  v2 = 0;
  if ( manifold->m_numPoints )
  {
    do
    {
      v3 = v2++;
      v4 = &manifold->m_contactPoints[v3];
      m_contactPointId = v4->m_contactPointId;
      LOBYTE(v4->m_contactPointId) = HIBYTE(v4->m_contactPointId);
      HIBYTE(v4->m_contactPointId) = m_contactPointId;
    }
    while ( v2 < (unsigned __int8)manifold->m_numPoints );
  }
  v6 = &manifold->m_manifoldNormalA.m_quad.m128_i8[3];
  v7 = 4i64;
  do
  {
    v8 = *v6;
    v9 = *(v6 - 3);
    v6 += 4;
    *(v6 - 7) = v8;
    *(v6 - 4) = v9;
    v10 = *(v6 - 6);
    *(v6 - 6) = *(v6 - 5);
    *(v6 - 5) = v10;
    --v7;
  }
  while ( v7 );
  m_manifoldNormalB = manifold->m_manifoldNormalB;
  LOBYTE(manifold->m_manifoldNormalB) = HIBYTE(manifold->m_manifoldNormalB);
  HIBYTE(manifold->m_manifoldNormalB) = m_manifoldNormalB;
  v12 = BYTE1(manifold->m_manifoldNormalB);
  BYTE1(manifold->m_manifoldNormalB) = BYTE2(manifold->m_manifoldNormalB);
  BYTE2(manifold->m_manifoldNormalB) = v12;
}

// File Line: 107
// RVA: 0xE24B60
void __fastcall hkpSaveContactPointsEndianUtil::swapEndianType(hkpCapsuleTriangleCache3 *cache)
{
  hkpCapsuleTriangleCache3 *v2; // r9
  char *v3; // rax
  __int64 v4; // r11
  char v5; // r8
  char v6; // dl
  char v7; // dl
  char m_invNormalLen_low; // cl
  char v9; // cl
  char m_normalLen_low; // cl
  char v11; // cl

  v2 = cache;
  v3 = (char *)cache->m_triangleCache.m_invEdgeLen + 3;
  v4 = 3i64;
  do
  {
    v5 = v2->m_contactPointId[0];
    v3 += 4;
    LOBYTE(v2->m_contactPointId[0]) = HIBYTE(v2->m_contactPointId[0]);
    HIBYTE(v2->m_contactPointId[0]) = v5;
    v6 = *(v3 - 7);
    *(v3 - 7) = *(v3 - 4);
    v2 = (hkpCapsuleTriangleCache3 *)((char *)v2 + 2);
    *(v3 - 4) = v6;
    v7 = *(v3 - 6);
    *(v3 - 6) = *(v3 - 5);
    *(v3 - 5) = v7;
    --v4;
  }
  while ( v4 );
  m_invNormalLen_low = LOBYTE(cache->m_triangleCache.m_invNormalLen);
  LOBYTE(cache->m_triangleCache.m_invNormalLen) = HIBYTE(cache->m_triangleCache.m_invNormalLen);
  HIBYTE(cache->m_triangleCache.m_invNormalLen) = m_invNormalLen_low;
  v9 = BYTE1(cache->m_triangleCache.m_invNormalLen);
  BYTE1(cache->m_triangleCache.m_invNormalLen) = BYTE2(cache->m_triangleCache.m_invNormalLen);
  BYTE2(cache->m_triangleCache.m_invNormalLen) = v9;
  m_normalLen_low = LOBYTE(cache->m_triangleCache.m_normalLen);
  LOBYTE(cache->m_triangleCache.m_normalLen) = HIBYTE(cache->m_triangleCache.m_normalLen);
  HIBYTE(cache->m_triangleCache.m_normalLen) = m_normalLen_low;
  v11 = BYTE1(cache->m_triangleCache.m_normalLen);
  BYTE1(cache->m_triangleCache.m_normalLen) = BYTE2(cache->m_triangleCache.m_normalLen);
  BYTE2(cache->m_triangleCache.m_normalLen) = v11;
}

// File Line: 118
// RVA: 0xE24D10
void __fastcall hkpSaveContactPointsEndianUtil::swapEndianType(hkpGskCache *cache)
{
  __int64 v1; // r8
  char v2; // al
  char v3; // dl

  v1 = 4i64;
  do
  {
    v2 = HIBYTE(cache->m_vertices[0]);
    v3 = cache->m_vertices[0];
    cache = (hkpGskCache *)((char *)cache + 2);
    *((_BYTE *)&cache[-1] + 10) = v2;
    cache[-1].m_gskFlags = v3;
    --v1;
  }
  while ( v1 );
}

// File Line: 126
// RVA: 0xE24C00
void __fastcall hkpSaveContactPointsEndianUtil::swapEndianType(hkpGskManifold *manifold)
{
  int v1; // r9d
  __int64 v2; // rax
  char *v3; // r8
  char v4; // dl
  int v5; // edx
  hkpGskManifold::ContactPoint *v6; // rax
  __int64 v7; // r8
  char m_dimB; // cl
  char m_dimA; // dl

  v1 = 0;
  if ( manifold->m_numContactPoints )
  {
    do
    {
      v2 = v1++;
      v3 = &manifold->m_numVertsA + 8 * v2;
      v4 = v3[6];
      v3[6] = v3[7];
      v3[7] = v4;
    }
    while ( v1 < (unsigned __int8)manifold->m_numContactPoints );
  }
  v5 = (unsigned __int8)manifold->m_numVertsA + (unsigned __int8)manifold->m_numVertsB;
  v6 = &manifold->m_contactPoints[(unsigned __int8)manifold->m_numContactPoints];
  if ( v5 > 0 )
  {
    v7 = (unsigned int)v5;
    do
    {
      m_dimB = v6->m_dimB;
      m_dimA = v6->m_dimA;
      v6 = (hkpGskManifold::ContactPoint *)((char *)v6 + 2);
      v6[-1].m_vert[2] = m_dimB;
      v6[-1].m_vert[3] = m_dimA;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 156
// RVA: 0xE24600
void __fastcall hkpSaveContactPointsEndianUtil::swapEndianTypeInCollisionEntry(
        hkpProcessCollisionInput *input,
        hkpSerializedAgentNnEntry *serializedEntry)
{
  unsigned int m_contactPointPropertiesStriding; // ecx
  int m_size; // eax
  int v5; // eax
  __int64 v6; // r10
  __int64 v7; // r11
  __int64 v8; // rdi
  char *v9; // rdx
  char v10; // cl
  char *v11; // r9
  char v12; // cl
  char v13; // cl
  char v14; // cl
  char v15; // cl
  char v16; // cl
  int v17; // eax
  __int64 v18; // rcx
  char *v19; // r8
  char v20; // dl
  char v21; // dl
  bool trackUsedOut; // [rsp+48h] [rbp+10h] BYREF
  int sizeOfThisEntryOut; // [rsp+50h] [rbp+18h] BYREF

  hkpSaveContactPointsEndianUtil::swapEndianTypeInEntry(
    input,
    (hkpAgentEntry *)serializedEntry->m_nnEntryData,
    &serializedEntry->m_trackInfo,
    (hkBool)1,
    &sizeOfThisEntryOut,
    &trackUsedOut);
  m_contactPointPropertiesStriding = (unsigned __int8)serializedEntry->m_atom.m_contactPointPropertiesStriding;
  m_size = serializedEntry->m_propertiesStream.m_size;
  *(_DWORD *)serializedEntry->m_endianCheckBuffer = 259;
  v5 = m_size / (int)m_contactPointPropertiesStriding;
  if ( v5 > 0 )
  {
    v6 = 0i64;
    v7 = (unsigned int)v5;
    v8 = m_contactPointPropertiesStriding;
    do
    {
      v9 = &serializedEntry->m_propertiesStream.m_data[v6];
      v10 = v9[24];
      v11 = v9 + 32;
      v9[24] = v9[27];
      v9[27] = v10;
      v12 = v9[25];
      v9[25] = v9[26];
      v9[26] = v12;
      v13 = *v9;
      *v9 = v9[3];
      v9[3] = v13;
      v14 = v9[1];
      v9[1] = v9[2];
      v9[2] = v14;
      v15 = v9[4];
      v9[4] = v9[7];
      v9[7] = v15;
      v16 = v9[5];
      v9[5] = v9[6];
      v17 = 0;
      for ( v9[6] = v16; v17 < 2 * (unsigned __int8)serializedEntry->m_atom.m_numUserDatasForBodyA; v19[2] = v21 )
      {
        v18 = v17++;
        v19 = &v11[4 * v18];
        v20 = *v19;
        *v19 = v19[3];
        v19[3] = v20;
        v21 = v19[1];
        v19[1] = v19[2];
      }
      v6 += v8;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 183
// RVA: 0xE24730
void __fastcall hkpSaveContactPointsEndianUtil::swapEndianTypeInEntry(
        hkpProcessCollisionInput *input,
        hkpAgentNnMachineTimEntry *entry,
        hkpSerializedTrack1nInfo *serializedTrack,
        hkBool isNnEntry,
        int *sizeOfThisEntryOut,
        bool *trackUsedOut)
{
  hkpAgentEntry *p_m_separatingNormal; // rbx
  char v10; // cl
  char v11; // cl
  char m_contactMgr; // cl
  char v13; // cl
  int SerializedAgentType; // eax

  *trackUsedOut = 0;
  switch ( entry->m_streamCommand )
  {
    case 0:
    case 1:
      *sizeOfThisEntryOut = 16;
      break;
    case 2:
    case 3:
    case 0xA:
    case 0xB:
      if ( isNnEntry.m_bool )
      {
        p_m_separatingNormal = (hkpAgentEntry *)&entry->m_separatingNormal;
      }
      else
      {
        v10 = entry->m_agentIndexOnCollidable[0];
        p_m_separatingNormal = (hkpAgentEntry *)&entry->m_collisionQualityIndex;
        LOBYTE(entry->m_agentIndexOnCollidable[0]) = HIBYTE(entry->m_agentIndexOnCollidable[1]);
        HIBYTE(entry->m_agentIndexOnCollidable[1]) = v10;
        v11 = HIBYTE(entry->m_agentIndexOnCollidable[0]);
        HIBYTE(entry->m_agentIndexOnCollidable[0]) = entry->m_agentIndexOnCollidable[1];
        LOBYTE(entry->m_agentIndexOnCollidable[1]) = v11;
        m_contactMgr = (char)entry->m_contactMgr;
        LOBYTE(entry->m_contactMgr) = BYTE3(entry->m_contactMgr);
        BYTE3(entry->m_contactMgr) = m_contactMgr;
        v13 = BYTE1(entry->m_contactMgr);
        BYTE1(entry->m_contactMgr) = BYTE2(entry->m_contactMgr);
        BYTE2(entry->m_contactMgr) = v13;
      }
      goto $continueConvertEntryToSerialized_0;
    case 4:
    case 5:
    case 6:
    case 0xC:
    case 0xD:
    case 0xE:
      if ( isNnEntry.m_bool )
      {
        p_m_separatingNormal = entry + 1;
        hkpSaveContactPointsEndianUtil::swapEndianType(entry);
      }
      else
      {
        p_m_separatingNormal = (hkpAgentEntry *)&entry->m_collidable[1];
        hkpSaveContactPointsEndianUtil::swapEndianType((hkpAgent1nMachineTimEntry *)entry);
      }
$continueConvertEntryToSerialized_0:
      SerializedAgentType = hkpSaveContactPointsUtil::getSerializedAgentType(input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_processFunc);
      *sizeOfThisEntryOut = (unsigned __int8)entry->m_size;
      switch ( SerializedAgentType )
      {
        case 1:
          hkpSaveContactPointsEndianUtil::swapEndianType((hkpBoxBoxManifold *)p_m_separatingNormal);
          return;
        case 2:
          hkpSaveContactPointsEndianUtil::swapEndianType((hkpCapsuleTriangleCache3 *)p_m_separatingNormal);
          return;
        case 3:
        case 4:
          goto $LN9_164;
        case 5:
          if ( (p_m_separatingNormal[2].m_size & 0x20) == 0 )
            goto $LN7_219;
$LN9_164:
          hkpSaveContactPointsEndianUtil::swapEndianType((hkpGskCache *)p_m_separatingNormal);
          hkpSaveContactPointsEndianUtil::swapEndianType((hkpGskManifold *)&p_m_separatingNormal[3]);
          break;
        case 6:
        case 7:
        case 8:
        case 9:
$LN7_219:
          hkpSaveContactPointsEndianUtil::swapEndianTypeIn1nTrack(input, serializedTrack);
          *trackUsedOut = 1;
          break;
        default:
          return;
      }
      break;
    default:
      return;
  }
}

// File Line: 324
// RVA: 0xE248E0
void __fastcall hkpSaveContactPointsEndianUtil::swapEndianTypeIn1nTrack(
        hkpProcessCollisionInput *input,
        hkpSerializedTrack1nInfo *serializedTrack)
{
  hkpProcessCollisionInput *v3; // r10
  hkpSerializedSubTrack1nInfo *v4; // rbx
  int v5; // r13d
  bool v6; // cc
  int v7; // r12d
  __int64 v8; // r14
  __int64 v9; // rcx
  unsigned int *v10; // rdx
  hkpAgentNnMachineTimEntry *v11; // rbp
  int v12; // edi
  unsigned __int64 v13; // [rsp+30h] [rbp-58h]
  unsigned int *v14; // [rsp+38h] [rbp-50h]
  bool trackUsedOut; // [rsp+98h] [rbp+10h] BYREF
  int sizeOfThisEntryOut; // [rsp+A0h] [rbp+18h] BYREF
  __int64 v18; // [rsp+A8h] [rbp+20h]

  v3 = input;
  if ( serializedTrack->m_subTracks.m_size )
  {
    v4 = *serializedTrack->m_subTracks.m_data;
    v5 = 0;
  }
  else
  {
    v5 = -1;
    v4 = 0i64;
  }
  v6 = serializedTrack->m_sectors.m_size <= 0;
  trackUsedOut = 0;
  v7 = 0;
  v8 = v5;
  if ( !v6 )
  {
    v9 = 0i64;
    v18 = 0i64;
    do
    {
      v10 = *(unsigned int **)((char *)serializedTrack->m_sectors.m_data + v9);
      v14 = v10;
      v11 = (hkpAgentNnMachineTimEntry *)(v10 + 4);
      v13 = (unsigned __int64)v10 + *v10 + 16;
      if ( (unsigned __int64)(v10 + 4) < v13 )
      {
        v12 = v5 + 1;
        do
        {
          sizeOfThisEntryOut = 0;
          if ( v4 && (v4->m_sectorIndex != v7 || v4->m_offsetInSector < (char *)v11 - (char *)v10 - 16) )
          {
            trackUsedOut = 0;
            if ( v12 >= serializedTrack->m_subTracks.m_size )
            {
              v4 = 0i64;
            }
            else
            {
              ++v5;
              ++v12;
              v4 = serializedTrack->m_subTracks.m_data[++v8];
            }
          }
          hkpSaveContactPointsEndianUtil::swapEndianTypeInEntry(v3, v11, v4, 0, &sizeOfThisEntryOut, &trackUsedOut);
          v10 = v14;
          v3 = input;
          v11 = (hkpAgentNnMachineTimEntry *)((char *)v11 + sizeOfThisEntryOut);
        }
        while ( (unsigned __int64)v11 < v13 );
        v9 = v18;
      }
      v9 += 8i64;
      ++v7;
      v18 = v9;
    }
    while ( v7 < serializedTrack->m_sectors.m_size );
  }
}

