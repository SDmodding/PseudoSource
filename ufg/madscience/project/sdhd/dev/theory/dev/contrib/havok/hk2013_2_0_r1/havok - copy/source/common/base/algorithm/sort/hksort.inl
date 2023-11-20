// File Line: 92
// RVA: 0xC08090
void __fastcall hkAlgorithm::quickSortRecursive<hkaiNavVolumePathRequestInfo,hkAlgorithm::less<hkaiNavVolumePathRequestInfo>>(hkaiNavVolumePathRequestInfo *pArr, int d, int h, hkAlgorithm::less<hkaiNavVolumePathRequestInfo> cmpLess)
{
  int v4; // eax
  __int64 v5; // r9
  __int64 v6; // rdi
  hkReferencedObject *v7; // r8
  int v8; // ebx
  int v9; // ebp
  __int64 v10; // rsi
  hkReferencedObject *v11; // rcx
  hkReferencedObject *v12; // rcx
  hkaiNavVolumePathRequestInfo *v13; // r10
  int v14; // edx
  int *v15; // rcx
  int *v16; // rax
  signed __int64 v17; // rbp
  hkReferencedObject *v18; // rcx
  hkReferencedObject *v19; // rcx
  char v20; // bl
  hkReferencedObject *v21; // rcx
  hkReferencedObject *v22; // rcx
  hkReferencedObject *v23; // rcx
  hkReferencedObject *v24; // rcx
  signed __int64 v25; // rcx
  hkaiNavVolumePathRequestInfo *v26; // [rsp+20h] [rbp-D8h]
  signed __int64 v27; // [rsp+20h] [rbp-D8h]
  int v28; // [rsp+28h] [rbp-D0h]
  int v29; // [rsp+2Ch] [rbp-CCh]
  int v30; // [rsp+30h] [rbp-C8h]
  hkReferencedObject *v31; // [rsp+40h] [rbp-B8h]
  int v32; // [rsp+50h] [rbp-A8h]
  hkReferencedObject *v33; // [rsp+60h] [rbp-98h]
  hkReferencedObject *v34; // [rsp+68h] [rbp-90h]
  __int64 v35; // [rsp+70h] [rbp-88h]
  hkReferencedObject *v36; // [rsp+80h] [rbp-78h]
  hkReferencedObject *v37; // [rsp+A0h] [rbp-58h]
  hkReferencedObject *v38; // [rsp+A8h] [rbp-50h]
  hkaiNavVolumePathRequestInfo *pArra; // [rsp+100h] [rbp+8h]
  int da; // [rsp+108h] [rbp+10h]
  int v41; // [rsp+110h] [rbp+18h]
  hkAlgorithm::less<hkaiNavVolumePathRequestInfo> v42; // [rsp+118h] [rbp+20h]

  v42 = cmpLess;
  v41 = h;
  da = d;
  pArra = pArr;
  v4 = d;
  v5 = h;
  v6 = d;
  _mm_store_si128((__m128i *)&v37, (__m128i)0i64);
  v7 = v37;
  v33 = v38;
  v31 = v37;
  while ( 1 )
  {
    v8 = v4;
    v28 = v4;
    v9 = v5;
    v29 = v5;
    v10 = v5;
    v26 = &pArr[(signed __int64)((signed int)v5 + v4) >> 1];
    v11 = (hkReferencedObject *)&v26->m_input.m_pntr->vfptr;
    if ( v11 )
    {
      hkReferencedObject::addReference(v11);
      v7 = v31;
    }
    if ( v7 )
      hkReferencedObject::removeReference(v7);
    v31 = (hkReferencedObject *)&v26->m_input.m_pntr->vfptr;
    v12 = (hkReferencedObject *)&v26->m_output.m_pntr->vfptr;
    if ( v12 )
      hkReferencedObject::addReference(v12);
    if ( v33 )
      hkReferencedObject::removeReference(v33);
    v13 = pArra;
    v14 = v26->m_priority;
    v33 = (hkReferencedObject *)&v26->m_output.m_pntr->vfptr;
    v30 = v26->m_priority;
    do
    {
      v15 = &v13[v6].m_priority;
      if ( *v15 > v14 )
      {
        do
        {
          v15 += 14;
          ++v8;
          ++v6;
        }
        while ( *v15 > v14 );
        v28 = v8;
      }
      v16 = &v13[v10].m_priority;
      if ( v14 > *v16 )
      {
        do
        {
          v16 -= 14;
          --v9;
          --v10;
        }
        while ( v14 > *v16 );
        v29 = v9;
      }
      if ( v10 < v6 )
        break;
      if ( v10 != v6 )
      {
        v17 = (signed __int64)&v13[v10];
        v18 = *(hkReferencedObject **)(v17 + 16);
        v27 = (signed __int64)&v13[v6];
        if ( v18 )
          hkReferencedObject::addReference(v18);
        v19 = *(hkReferencedObject **)(v17 + 24);
        v36 = *(hkReferencedObject **)(v17 + 16);
        if ( v19 )
          hkReferencedObject::addReference(v19);
        v20 = *(_BYTE *)(v17 + 48);
        v34 = *(hkReferencedObject **)(v17 + 24);
        v32 = *(_DWORD *)(v17 + 32);
        v35 = *(_QWORD *)(v17 + 40);
        v21 = *(hkReferencedObject **)(v27 + 16);
        if ( v21 )
          hkReferencedObject::addReference(v21);
        v22 = *(hkReferencedObject **)(v17 + 16);
        if ( v22 )
          hkReferencedObject::removeReference(v22);
        *(_QWORD *)(v17 + 16) = *(_QWORD *)(v27 + 16);
        v23 = *(hkReferencedObject **)(v27 + 24);
        if ( v23 )
          hkReferencedObject::addReference(v23);
        v24 = *(hkReferencedObject **)(v17 + 24);
        if ( v24 )
          hkReferencedObject::removeReference(v24);
        v25 = v27;
        *(_QWORD *)(v17 + 24) = *(_QWORD *)(v27 + 24);
        *(_DWORD *)(v17 + 32) = *(_DWORD *)(v27 + 32);
        *(_QWORD *)(v17 + 40) = *(_QWORD *)(v27 + 40);
        *(_BYTE *)(v17 + 48) = *(_BYTE *)(v27 + 48);
        if ( v36 )
        {
          hkReferencedObject::addReference(v36);
          v25 = v27;
        }
        if ( *(_QWORD *)(v25 + 16) )
        {
          hkReferencedObject::removeReference(*(hkReferencedObject **)(v25 + 16));
          v25 = v27;
        }
        *(_QWORD *)(v25 + 16) = v36;
        if ( v34 )
        {
          hkReferencedObject::addReference(v34);
          v25 = v27;
        }
        if ( *(_QWORD *)(v25 + 24) )
        {
          hkReferencedObject::removeReference(*(hkReferencedObject **)(v25 + 24));
          v25 = v27;
        }
        *(_QWORD *)(v25 + 24) = v34;
        *(_DWORD *)(v25 + 32) = v32;
        *(_BYTE *)(v25 + 48) = v20;
        *(_QWORD *)(v25 + 40) = v35;
        if ( v34 )
          hkReferencedObject::removeReference(v34);
        if ( v36 )
          hkReferencedObject::removeReference(v36);
        v13 = pArra;
        v14 = v30;
        v9 = v29;
        v8 = v28;
      }
      --v9;
      ++v8;
      --v10;
      ++v6;
      v29 = v9;
      v28 = v8;
    }
    while ( v6 <= v10 );
    if ( da < v9 )
      hkAlgorithm::quickSortRecursive<hkaiNavVolumePathRequestInfo,hkAlgorithm::less<hkaiNavVolumePathRequestInfo>>(
        v13,
        da,
        v9,
        v42);
    v5 = v41;
    if ( v8 >= v41 )
      break;
    pArr = pArra;
    v7 = v31;
    v4 = v8;
    da = v8;
  }
  if ( v33 )
    hkReferencedObject::removeReference(v33);
  if ( v31 )
    hkReferencedObject::removeReference(v31);
}

