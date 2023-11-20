// File Line: 67
// RVA: 0xE24B00
void __fastcall hkpSaveContactPointsEndianUtil::swapEndianType(hkpAgentNnMachineTimEntry *entry)
{
  char v1; // dl
  signed __int64 v2; // r8
  char v3; // dl
  char *v4; // rax
  char v5; // cl
  char v6; // dl
  char v7; // dl

  v1 = LOBYTE(entry->m_timeOfSeparatingNormal);
  v2 = 4i64;
  LOBYTE(entry->m_timeOfSeparatingNormal) = HIBYTE(entry->m_timeOfSeparatingNormal);
  HIBYTE(entry->m_timeOfSeparatingNormal) = v1;
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
  char v1; // dl
  hkpAgent1nMachineTimEntry *v2; // r8
  char v3; // dl
  char v4; // al
  char v5; // cl
  char v6; // cl
  char v7; // cl
  char v8; // cl
  char *v9; // rax
  signed __int64 v10; // r8
  char v11; // cl
  char v12; // dl
  char v13; // dl

  v1 = entry->m_shapeKeyPair.m_shapeKeyA;
  v2 = entry;
  LOBYTE(entry->m_shapeKeyPair.m_shapeKeyA) = HIBYTE(entry->m_shapeKeyPair.m_shapeKeyA);
  HIBYTE(entry->m_shapeKeyPair.m_shapeKeyA) = v1;
  v3 = BYTE1(entry->m_shapeKeyPair.m_shapeKeyA);
  BYTE1(entry->m_shapeKeyPair.m_shapeKeyA) = BYTE2(entry->m_shapeKeyPair.m_shapeKeyA);
  BYTE2(entry->m_shapeKeyPair.m_shapeKeyA) = v3;
  v4 = HIBYTE(entry->m_shapeKeyPair.m_shapeKeyB);
  v5 = entry->m_shapeKeyPair.m_shapeKeyB;
  LOBYTE(v2->m_shapeKeyPair.m_shapeKeyB) = v4;
  HIBYTE(v2->m_shapeKeyPair.m_shapeKeyB) = v5;
  v6 = BYTE1(v2->m_shapeKeyPair.m_shapeKeyB);
  BYTE1(v2->m_shapeKeyPair.m_shapeKeyB) = BYTE2(v2->m_shapeKeyPair.m_shapeKeyB);
  BYTE2(v2->m_shapeKeyPair.m_shapeKeyB) = v6;
  v7 = LOBYTE(v2->m_timeOfSeparatingNormal);
  LOBYTE(v2->m_timeOfSeparatingNormal) = HIBYTE(v2->m_timeOfSeparatingNormal);
  HIBYTE(v2->m_timeOfSeparatingNormal) = v7;
  v8 = BYTE1(v2->m_timeOfSeparatingNormal);
  BYTE1(v2->m_timeOfSeparatingNormal) = BYTE2(v2->m_timeOfSeparatingNormal);
  v9 = &v2->m_separatingNormal.m_quad.m128_i8[3];
  BYTE2(v2->m_timeOfSeparatingNormal) = v8;
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
  unsigned __int8 *v1; // r9
  signed int v2; // ecx
  __int64 v3; // rax
  signed __int64 v4; // r8
  char v5; // dl
  char *v6; // rax
  signed __int64 v7; // r8
  char v8; // cl
  char v9; // dl
  char v10; // dl
  unsigned __int8 v11; // cl
  unsigned __int8 v12; // cl

  v1 = (unsigned __int8 *)manifold;
  v2 = 0;
  if ( v1[33] )
  {
    do
    {
      v3 = v2++;
      v4 = (signed __int64)&v1[4 * v3];
      v5 = *(_BYTE *)(v4 + 2);
      *(_BYTE *)(v4 + 2) = v1[4 * v3 + 3];
      *(_BYTE *)(v4 + 3) = v5;
    }
    while ( v2 < v1[33] );
  }
  v6 = (char *)(v1 + 51);
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
  v11 = v1[36];
  v1[36] = v1[39];
  v1[39] = v11;
  v12 = v1[37];
  v1[37] = v1[38];
  v1[38] = v12;
}

// File Line: 107
// RVA: 0xE24B60
void __fastcall hkpSaveContactPointsEndianUtil::swapEndianType(hkpCapsuleTriangleCache3 *cache)
{
  hkpCapsuleTriangleCache3 *v1; // r10
  hkpCapsuleTriangleCache3 *v2; // r9
  char *v3; // rax
  signed __int64 v4; // r11
  char v5; // r8
  char v6; // dl
  char v7; // dl
  char v8; // cl
  char v9; // cl
  char v10; // cl
  char v11; // cl

  v1 = cache;
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
  v8 = LOBYTE(cache->m_triangleCache.m_invNormalLen);
  LOBYTE(v1->m_triangleCache.m_invNormalLen) = HIBYTE(v1->m_triangleCache.m_invNormalLen);
  HIBYTE(v1->m_triangleCache.m_invNormalLen) = v8;
  v9 = BYTE1(v1->m_triangleCache.m_invNormalLen);
  BYTE1(v1->m_triangleCache.m_invNormalLen) = BYTE2(v1->m_triangleCache.m_invNormalLen);
  BYTE2(v1->m_triangleCache.m_invNormalLen) = v9;
  v10 = LOBYTE(v1->m_triangleCache.m_normalLen);
  LOBYTE(v1->m_triangleCache.m_normalLen) = HIBYTE(v1->m_triangleCache.m_normalLen);
  HIBYTE(v1->m_triangleCache.m_normalLen) = v10;
  v11 = BYTE1(v1->m_triangleCache.m_normalLen);
  BYTE1(v1->m_triangleCache.m_normalLen) = BYTE2(v1->m_triangleCache.m_normalLen);
  BYTE2(v1->m_triangleCache.m_normalLen) = v11;
}

// File Line: 118
// RVA: 0xE24D10
void __fastcall hkpSaveContactPointsEndianUtil::swapEndianType(hkpGskCache *cache)
{
  signed __int64 v1; // r8
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
  signed int v1; // er9
  __int64 v2; // rax
  char *v3; // r8
  char v4; // dl
  int v5; // edx
  hkpGskManifold::ContactPoint *v6; // rax
  __int64 v7; // r8
  char v8; // cl
  char v9; // dl

  v1 = 0;
  if ( manifold->m_numContactPoints )
  {
    do
    {
      v2 = v1++;
      v3 = &manifold->m_numVertsA + 8 * v2;
      v4 = v3[6];
      v3[6] = HIBYTE(manifold->m_contactPoints[v2].m_id);
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
      v8 = v6->m_dimB;
      v9 = v6->m_dimA;
      v6 = (hkpGskManifold::ContactPoint *)((char *)v6 + 2);
      v6[-1].m_vert[2] = v8;
      v6[-1].m_vert[3] = v9;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 156
// RVA: 0xE24600
void __fastcall hkpSaveContactPointsEndianUtil::swapEndianTypeInCollisionEntry(hkpProcessCollisionInput *input, hkpSerializedAgentNnEntry *serializedEntry)
{
  hkpSerializedAgentNnEntry *v2; // rbx
  unsigned int v3; // ecx
  int v4; // eax
  int v5; // edx
  unsigned int v6; // eax
  __int64 v7; // r10
  __int64 v8; // r11
  __int64 v9; // rdi
  char *v10; // rdx
  char v11; // cl
  signed __int64 v12; // r9
  char v13; // cl
  char v14; // cl
  char v15; // cl
  char v16; // cl
  char v17; // cl
  int v18; // eax
  __int64 v19; // rcx
  char *v20; // r8
  char v21; // dl
  char v22; // dl
  bool trackUsedOut; // [rsp+48h] [rbp+10h]
  int sizeOfThisEntryOut; // [rsp+50h] [rbp+18h]

  v2 = serializedEntry;
  hkpSaveContactPointsEndianUtil::swapEndianTypeInEntry(
    input,
    (hkpAgentEntry *)serializedEntry->m_nnEntryData,
    &serializedEntry->m_trackInfo,
    (hkBool)1,
    &sizeOfThisEntryOut,
    &trackUsedOut);
  v3 = (unsigned __int8)v2->m_atom.m_contactPointPropertiesStriding;
  v4 = v2->m_propertiesStream.m_size;
  v5 = v2->m_propertiesStream.m_size >> 31;
  *(_DWORD *)v2->m_endianCheckBuffer = 259;
  v6 = __PAIR__(v5, v4) / (signed int)v3;
  if ( (signed int)v6 > 0 )
  {
    v7 = 0i64;
    v8 = v6;
    v9 = v3;
    do
    {
      v10 = &v2->m_propertiesStream.m_data[v7];
      v11 = v10[24];
      v12 = (signed __int64)(v10 + 32);
      v10[24] = v10[27];
      v10[27] = v11;
      v13 = v10[25];
      v10[25] = v10[26];
      v10[26] = v13;
      v14 = *v10;
      *v10 = v10[3];
      v10[3] = v14;
      v15 = v10[1];
      v10[1] = v10[2];
      v10[2] = v15;
      v16 = v10[4];
      v10[4] = v10[7];
      v10[7] = v16;
      v17 = v10[5];
      v10[5] = v10[6];
      v18 = 0;
      for ( v10[6] = v17; v18 < 2 * (unsigned __int8)v2->m_atom.m_numUserDatasForBodyA; v20[2] = v22 )
      {
        v19 = v18++;
        v20 = (char *)(v12 + 4 * v19);
        v21 = *v20;
        *v20 = *(_BYTE *)(v12 + 4 * v19 + 3);
        v20[3] = v21;
        v22 = v20[1];
        v20[1] = v20[2];
      }
      v7 += v9;
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 183
// RVA: 0xE24730
void __fastcall hkpSaveContactPointsEndianUtil::swapEndianTypeInEntry(hkpProcessCollisionInput *input, hkpAgentEntry *entry, hkpSerializedTrack1nInfo *serializedTrack, hkBool isNnEntry, int *sizeOfThisEntryOut, bool *trackUsedOut)
{
  hkpSerializedTrack1nInfo *v6; // rbp
  hkpAgentEntry *v7; // rdi
  hkpProcessCollisionInput *v8; // r14
  hkpAgentEntry *v9; // rbx
  char v10; // cl
  char v11; // cl
  char v12; // cl
  char v13; // cl
  int v14; // eax

  v6 = serializedTrack;
  v7 = entry;
  *trackUsedOut = 0;
  v8 = input;
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
        v9 = entry + 12;
      }
      else
      {
        v10 = entry[1].m_streamCommand;
        v9 = entry + 4;
        entry[1].m_streamCommand = entry[1].m_size;
        entry[1].m_size = v10;
        v11 = entry[1].m_agentType;
        entry[1].m_agentType = entry[1].m_numContactPoints;
        entry[1].m_numContactPoints = v11;
        v12 = entry[2].m_streamCommand;
        entry[2].m_streamCommand = entry[2].m_size;
        entry[2].m_size = v12;
        v13 = entry[2].m_agentType;
        entry[2].m_agentType = entry[2].m_numContactPoints;
        entry[2].m_numContactPoints = v13;
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
        v9 = entry + 16;
        hkpSaveContactPointsEndianUtil::swapEndianType((hkpAgentNnMachineTimEntry *)entry);
      }
      else
      {
        v9 = entry + 8;
        hkpSaveContactPointsEndianUtil::swapEndianType((hkpAgent1nMachineTimEntry *)entry);
      }
$continueConvertEntryToSerialized_0:
      v14 = hkpSaveContactPointsUtil::getSerializedAgentType(v8->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)v7->m_agentType].m_processFunc);
      *sizeOfThisEntryOut = (unsigned __int8)v7->m_size;
      switch ( v14 )
      {
        case 1:
          hkpSaveContactPointsEndianUtil::swapEndianType((hkpBoxBoxManifold *)v9);
          return;
        case 2:
          hkpSaveContactPointsEndianUtil::swapEndianType((hkpCapsuleTriangleCache3 *)v9);
          return;
        case 3:
        case 4:
          goto $LN9_164;
        case 5:
          if ( !(v9[2].m_size & 0x20) )
            goto $LN7_219;
$LN9_164:
          hkpSaveContactPointsEndianUtil::swapEndianType((hkpGskCache *)v9);
          hkpSaveContactPointsEndianUtil::swapEndianType((hkpGskManifold *)&v9[3]);
          break;
        case 6:
        case 7:
        case 8:
        case 9:
$LN7_219:
          hkpSaveContactPointsEndianUtil::swapEndianTypeIn1nTrack(v8, v6);
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
void __fastcall hkpSaveContactPointsEndianUtil::swapEndianTypeIn1nTrack(hkpProcessCollisionInput *input, hkpSerializedTrack1nInfo *serializedTrack)
{
  hkpSerializedTrack1nInfo *v2; // rsi
  hkpProcessCollisionInput *v3; // r10
  hkpSerializedSubTrack1nInfo *v4; // rbx
  signed int v5; // er13
  bool v6; // zf
  bool v7; // sf
  int v8; // er12
  __int64 v9; // r14
  __int64 v10; // rcx
  hkpAgentEntry *v11; // rdx
  hkpAgentEntry *v12; // rbp
  int v13; // edi
  unsigned __int64 v14; // [rsp+30h] [rbp-58h]
  hkpAgentEntry *v15; // [rsp+38h] [rbp-50h]
  hkpProcessCollisionInput *v16; // [rsp+90h] [rbp+8h]
  bool trackUsedOut; // [rsp+98h] [rbp+10h]
  int sizeOfThisEntryOut; // [rsp+A0h] [rbp+18h]
  __int64 v19; // [rsp+A8h] [rbp+20h]

  v16 = input;
  v2 = serializedTrack;
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
  v6 = serializedTrack->m_sectors.m_size == 0;
  v7 = serializedTrack->m_sectors.m_size < 0;
  trackUsedOut = 0;
  v8 = 0;
  v9 = v5;
  if ( !v7 && !v6 )
  {
    v10 = 0i64;
    v19 = 0i64;
    do
    {
      v11 = *(hkpAgentEntry **)((char *)v2->m_sectors.m_data + v10);
      v15 = v11;
      v12 = v11 + 4;
      v14 = (unsigned __int64)&v11[4] + *(_DWORD *)v11;
      if ( (unsigned __int64)&v11[4] < v14 )
      {
        v13 = v5 + 1;
        do
        {
          sizeOfThisEntryOut = 0;
          if ( v4 && (v4->m_sectorIndex != v8 || v4->m_offsetInSector < (char *)v12 - (char *)v11 - 16) )
          {
            trackUsedOut = 0;
            if ( v13 >= v2->m_subTracks.m_size )
            {
              v4 = 0i64;
            }
            else
            {
              ++v5;
              ++v13;
              v4 = v2->m_subTracks.m_data[v9++ + 1];
            }
          }
          hkpSaveContactPointsEndianUtil::swapEndianTypeInEntry(
            v3,
            v12,
            (hkpSerializedTrack1nInfo *)&v4->m_sectors,
            0,
            &sizeOfThisEntryOut,
            &trackUsedOut);
          v11 = v15;
          v3 = v16;
          v12 = (hkpAgentEntry *)((char *)v12 + sizeOfThisEntryOut);
        }
        while ( (unsigned __int64)v12 < v14 );
        v10 = v19;
      }
      v10 += 8i64;
      ++v8;
      v19 = v10;
    }
    while ( v8 < v2->m_sectors.m_size );
  }
}

