// File Line: 92
// RVA: 0xC08090
void __fastcall hkAlgorithm::quickSortRecursive<hkaiNavVolumePathRequestInfo,hkAlgorithm::less<hkaiNavVolumePathRequestInfo>>(
        hkaiNavVolumePathRequestInfo *pArr,
        int d,
        int h,
        hkAlgorithm::less<hkaiNavVolumePathRequestInfo> cmpLess)
{
  int v4; // eax
  __int64 v5; // r9
  __int64 v6; // rdi
  hkReferencedObject *v7; // r8
  int v8; // ebx
  int v9; // ebp
  __int64 v10; // rsi
  hkReferencedObject *m_pntr; // rcx
  hkReferencedObject *v12; // rcx
  hkaiNavVolumePathRequestInfo *v13; // r10
  int m_priority; // edx
  int *p_m_priority; // rcx
  int *v16; // rax
  hkaiNavVolumePathRequestInfo *v17; // rbp
  hkReferencedObject *v18; // rcx
  hkReferencedObject *v19; // rcx
  char m_bool; // bl
  hkReferencedObject *v21; // rcx
  hkReferencedObject *v22; // rcx
  hkReferencedObject *v23; // rcx
  hkReferencedObject *v24; // rcx
  hkaiNavVolumePathRequestInfo *v25; // rcx
  hkaiNavVolumePathRequestInfo *v26; // [rsp+20h] [rbp-D8h]
  hkaiNavVolumePathRequestInfo *v27; // [rsp+20h] [rbp-D8h]
  int v28; // [rsp+28h] [rbp-D0h]
  int v29; // [rsp+2Ch] [rbp-CCh]
  int v30; // [rsp+30h] [rbp-C8h]
  hkReferencedObject *v31; // [rsp+40h] [rbp-B8h]
  int v32; // [rsp+50h] [rbp-A8h]
  hkReferencedObject *v33; // [rsp+60h] [rbp-98h]
  hkReferencedObject *v34; // [rsp+68h] [rbp-90h]
  hkaiPathRequestInfoOwner *m_owner; // [rsp+70h] [rbp-88h]
  hkReferencedObject *v36; // [rsp+80h] [rbp-78h]
  hkaiNavVolumePathRequestInfo *pArra; // [rsp+100h] [rbp+8h]
  int da; // [rsp+108h] [rbp+10h]

  da = d;
  pArra = pArr;
  v4 = d;
  v5 = h;
  v6 = d;
  v33 = 0i64;
  v7 = 0i64;
  v31 = 0i64;
  while ( 1 )
  {
    v8 = v4;
    v28 = v4;
    v9 = v5;
    v29 = v5;
    v10 = v5;
    v26 = &pArr[(__int64)((int)v5 + v4) >> 1];
    m_pntr = v26->m_input.m_pntr;
    if ( m_pntr )
    {
      hkReferencedObject::addReference(m_pntr);
      v7 = v31;
    }
    if ( v7 )
      hkReferencedObject::removeReference(v7);
    v31 = v26->m_input.m_pntr;
    v12 = v26->m_output.m_pntr;
    if ( v12 )
      hkReferencedObject::addReference(v12);
    if ( v33 )
      hkReferencedObject::removeReference(v33);
    v13 = pArra;
    m_priority = v26->m_priority;
    v33 = v26->m_output.m_pntr;
    v30 = m_priority;
    do
    {
      p_m_priority = &v13[v6].m_priority;
      if ( *p_m_priority > m_priority )
      {
        do
        {
          p_m_priority += 14;
          ++v8;
          ++v6;
        }
        while ( *p_m_priority > m_priority );
        v28 = v8;
      }
      v16 = &v13[v10].m_priority;
      if ( m_priority > *v16 )
      {
        do
        {
          v16 -= 14;
          --v9;
          --v10;
        }
        while ( m_priority > *v16 );
        v29 = v9;
      }
      if ( v10 < v6 )
        break;
      if ( v10 != v6 )
      {
        v17 = &v13[v10];
        v18 = v17->m_input.m_pntr;
        v27 = &v13[v6];
        if ( v18 )
          hkReferencedObject::addReference(v18);
        v19 = v17->m_output.m_pntr;
        v36 = v17->m_input.m_pntr;
        if ( v19 )
          hkReferencedObject::addReference(v19);
        m_bool = v17->m_markedForDeletion.m_bool;
        v34 = v17->m_output.m_pntr;
        v32 = v17->m_priority;
        m_owner = v17->m_owner;
        v21 = v27->m_input.m_pntr;
        if ( v21 )
          hkReferencedObject::addReference(v21);
        v22 = v17->m_input.m_pntr;
        if ( v22 )
          hkReferencedObject::removeReference(v22);
        v17->m_input.m_pntr = v27->m_input.m_pntr;
        v23 = v27->m_output.m_pntr;
        if ( v23 )
          hkReferencedObject::addReference(v23);
        v24 = v17->m_output.m_pntr;
        if ( v24 )
          hkReferencedObject::removeReference(v24);
        v25 = v27;
        v17->m_output.m_pntr = v27->m_output.m_pntr;
        v17->m_priority = v27->m_priority;
        v17->m_owner = v27->m_owner;
        v17->m_markedForDeletion.m_bool = v27->m_markedForDeletion.m_bool;
        if ( v36 )
        {
          hkReferencedObject::addReference(v36);
          v25 = v27;
        }
        if ( v25->m_input.m_pntr )
        {
          hkReferencedObject::removeReference(v25->m_input.m_pntr);
          v25 = v27;
        }
        v25->m_input.m_pntr = (hkaiVolumePathfindingUtil::FindPathInput *)v36;
        if ( v34 )
        {
          hkReferencedObject::addReference(v34);
          v25 = v27;
        }
        if ( v25->m_output.m_pntr )
        {
          hkReferencedObject::removeReference(v25->m_output.m_pntr);
          v25 = v27;
        }
        v25->m_output.m_pntr = (hkaiVolumePathfindingUtil::FindPathOutput *)v34;
        v25->m_priority = v32;
        v25->m_markedForDeletion.m_bool = m_bool;
        v25->m_owner = m_owner;
        if ( v34 )
          hkReferencedObject::removeReference(v34);
        if ( v36 )
          hkReferencedObject::removeReference(v36);
        v13 = pArra;
        m_priority = v30;
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
        cmpLess);
    v5 = h;
    if ( v8 >= h )
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

