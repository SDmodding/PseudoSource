// File Line: 14
// RVA: 0xE631C0
void __fastcall hkDataWorldCloner::hkDataWorldCloner(hkDataWorldCloner *this, hkDataWorld *dstWorld, hkDataWorld *srcWorld)
{
  this->m_dstWorld = dstWorld;
  this->m_srcWorld = srcWorld;
  this->m_copied.m_elem = 0i64;
  this->m_copied.m_numElems = 0;
  this->m_copied.m_hashMod = -1;
}

// File Line: 20
// RVA: 0xE64430
void __fastcall hkDataWorldCloner::copySimpleValue<hkDataArray_Value>(hkDataWorldCloner *this, hkDataArray_Value *dst, hkDataArray_Value *src)
{
  hkDataWorldCloner *v3; // rbp
  hkDataArray_Value *v4; // rbx
  hkDataArray_Value *v5; // rdi
  __int64 v6; // rsi
  unsigned int v7; // eax
  __int64 v8; // rbx
  hkDataObjectImpl *v9; // rax
  hkDataObject *v10; // rax
  hkDataObjectImpl *v11; // rcx
  bool v12; // zf
  hkDataObjectImpl *v13; // rcx
  __int64 v14; // rax
  hkDataObject srcObject; // [rsp+50h] [rbp+18h]
  hkDataObject result; // [rsp+58h] [rbp+20h]

  v3 = this;
  v4 = src;
  v5 = dst;
  v6 = ((__int64 (*)(void))src->m_impl->vfptr[1].__vecDelDtor)();
  switch ( *(_DWORD *)v6 )
  {
    case 2:
    case 4:
      v7 = (__int64)v4->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v4->m_impl, v4->m_index);
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))v5->m_impl->vfptr[18].__vecDelDtor)(
        v5->m_impl,
        (unsigned int)v5->m_index,
        v7);
      break;
    case 3:
      v4->m_impl->vfptr[15].__vecDelDtor((hkDataRefCounted *)v4->m_impl, v4->m_index);
      v5->m_impl->vfptr[16].__vecDelDtor((hkDataRefCounted *)v5->m_impl, v5->m_index);
      break;
    case 5:
      v14 = (__int64)v4->m_impl->vfptr[13].__vecDelDtor((hkDataRefCounted *)v4->m_impl, v4->m_index);
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v5->m_impl->vfptr[14].__vecDelDtor)(
        v5->m_impl,
        (unsigned int)v5->m_index,
        v14);
      break;
    case 6:
    case 7:
      v9 = (hkDataObjectImpl *)v4->m_impl->vfptr[21].__vecDelDtor((hkDataRefCounted *)v4->m_impl, v4->m_index);
      srcObject.m_impl = v9;
      if ( v9 )
      {
        ++v9->m_externalCount;
        ++v9->m_count;
      }
      v10 = hkDataWorldCloner::copyObject(v3, &result, &srcObject);
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, hkDataObjectImpl *))v5->m_impl->vfptr[22].__vecDelDtor)(
        v5->m_impl,
        (unsigned int)v5->m_index,
        v10->m_impl);
      v11 = result.m_impl;
      if ( result.m_impl )
      {
        --result.m_impl->m_externalCount;
        v12 = v11->m_count-- == 1;
        if ( v12 )
          v11->vfptr->__vecDelDtor((hkDataRefCounted *)&v11->vfptr, 1u);
      }
      v13 = srcObject.m_impl;
      if ( srcObject.m_impl )
      {
        --srcObject.m_impl->m_externalCount;
        v12 = v13->m_count-- == 1;
        if ( v12 )
          v13->vfptr->__vecDelDtor((hkDataRefCounted *)&v13->vfptr, 1u);
      }
      break;
    case 9:
      if ( **(_DWORD **)(v6 + 8) == 3 )
      {
        hkTypeManager::Type::getTupleSize((hkTypeManager::Type *)v6);
        v8 = (__int64)v4->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v4->m_impl, v4->m_index);
        hkTypeManager::Type::getTupleSize((hkTypeManager::Type *)v6);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v5->m_impl->vfptr[12].__vecDelDtor)(
          v5->m_impl,
          (unsigned int)v5->m_index,
          v8);
      }
      break;
    default:
      return;
  }
}

// File Line: 71
// RVA: 0xE63280
void __fastcall hkDataWorldCloner::copyArray(hkDataWorldCloner *this, hkDataArray *dst, hkDataArray *src, int arraySize)
{
  int v4; // edi
  hkDataArray *v5; // rsi
  hkDataArray *v6; // rbx
  hkTypeManager::Type *v7; // rax
  int i; // esi
  unsigned int v9; // eax
  int j; // esi
  int v11; // eax
  _DWORD *v12; // rcx
  int n; // esi
  __int64 v14; // rax
  int ii; // esi
  hkDataArrayImpl *v16; // rax
  hkDataArrayImpl *v17; // rax
  hkDataArrayImpl *v18; // rcx
  bool v19; // zf
  hkDataArrayImpl *v20; // rcx
  int m; // esi
  hkDataArrayImpl *v22; // rax
  hkDataArray *v23; // rax
  unsigned int v24; // eax
  int v25; // eax
  hkDataArray *v26; // rcx
  hkDataArrayImpl *v27; // rcx
  int l; // esi
  hkDataObjectImpl *v29; // rax
  hkDataArrayImpl *v30; // rbx
  hkDataObject *v31; // rax
  hkDataObjectImpl *v32; // rcx
  hkDataObjectImpl *v33; // rcx
  __int64 v34; // rax
  __int64 v35; // rbx
  int v36; // eax
  int v37; // esi
  __int64 v38; // rdi
  int v39; // er8
  _QWORD *v40; // rcx
  unsigned int v41; // eax
  int v42; // edx
  _QWORD *v43; // rax
  __int64 v44; // rdx
  int v45; // eax
  signed __int64 v46; // r8
  __int64 v47; // rdx
  _QWORD *v48; // rax
  __int64 v49; // rdi
  char *v50; // rbx
  int *v51; // rax
  int v52; // ecx
  __int64 v53; // rax
  __int64 v54; // rdi
  __int64 v55; // rax
  __int64 v56; // rbx
  hkDataArrayImpl *v57; // rax
  hkDataArrayImpl *v58; // rax
  unsigned int v59; // eax
  int v60; // eax
  hkDataArrayImpl *v61; // rcx
  hkDataArrayImpl *v62; // rcx
  int k; // esi
  __int64 v64; // rax
  hkDataArray dsta; // [rsp+20h] [rbp-49h]
  int v66; // [rsp+28h] [rbp-41h]
  char *v67; // [rsp+30h] [rbp-39h]
  int v68; // [rsp+38h] [rbp-31h]
  int v69; // [rsp+3Ch] [rbp-2Dh]
  hkDataArray srca; // [rsp+40h] [rbp-29h]
  __int64 v71; // [rsp+48h] [rbp-21h]
  __int64 v72; // [rsp+50h] [rbp-19h]
  hkDataObject srcObject; // [rsp+58h] [rbp-11h]
  hkDataObject result; // [rsp+60h] [rbp-9h]
  __m128i v75; // [rsp+70h] [rbp+7h]
  __int64 v76; // [rsp+80h] [rbp+17h]
  int v77; // [rsp+88h] [rbp+1Fh]
  __int128 v78; // [rsp+90h] [rbp+27h]
  hkDataWorldCloner *v79; // [rsp+D0h] [rbp+67h]
  hkDataArray *arraySizea; // [rsp+D8h] [rbp+6Fh]
  hkDataArray *v81; // [rsp+E0h] [rbp+77h]
  int v82; // [rsp+E8h] [rbp+7Fh]

  v82 = arraySize;
  v81 = src;
  arraySizea = dst;
  v79 = this;
  v4 = arraySize;
  v5 = src;
  v6 = dst;
  v7 = (hkTypeManager::Type *)((__int64 (*)(void))dst->m_impl->vfptr[1].__vecDelDtor)();
  v72 = (__int64)v7;
  switch ( v7->m_subType )
  {
    case 2:
    case 4:
      for ( i = 0; i < v4; ++i )
      {
        v9 = (__int64)v81->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v81->m_impl, i);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))v6->m_impl->vfptr[18].__vecDelDtor)(
          v6->m_impl,
          (unsigned int)i,
          v9);
      }
      break;
    case 3:
      for ( j = 0; j < v4; ++j )
      {
        v81->m_impl->vfptr[15].__vecDelDtor((hkDataRefCounted *)v81->m_impl, j);
        v6->m_impl->vfptr[16].__vecDelDtor((hkDataRefCounted *)v6->m_impl, j);
      }
      break;
    case 5:
      for ( k = 0; k < v4; ++k )
      {
        v64 = (__int64)v81->m_impl->vfptr[13].__vecDelDtor((hkDataRefCounted *)v81->m_impl, k);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v6->m_impl->vfptr[14].__vecDelDtor)(
          v6->m_impl,
          (unsigned int)k,
          v64);
      }
      break;
    case 6:
      v6->m_impl->vfptr[4].__vecDelDtor((hkDataRefCounted *)v6->m_impl, v4);
      v34 = ((__int64 (*)(void))v5->m_impl->vfptr[6].__vecDelDtor)();
      v35 = v34;
      v36 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v34 + 72i64))(v34);
      v37 = 0;
      v69 = 2147483648;
      v38 = v36;
      v67 = 0i64;
      v68 = 0;
      v39 = v36;
      if ( v36 )
      {
        v66 = 32 * v36;
        v40 = (_QWORD *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, _QWORD))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                          &hkContainerTempAllocator::s_alloc,
                          &v66,
                          (unsigned int)v36);
        v39 = v66 / 32;
      }
      else
      {
        v40 = 0i64;
      }
      v41 = 2147483648;
      v42 = v38;
      if ( v39 )
        v41 = v39;
      v67 = (char *)v40;
      v72 = v38;
      v68 = v38;
      v69 = v41;
      if ( (signed int)v38 > 0 )
      {
        v43 = v40 + 2;
        v44 = v38;
        do
        {
          if ( v43 != (_QWORD *)16 )
          {
            *(v43 - 2) = 0i64;
            *(v43 - 1) = 0i64;
            *v43 = 0i64;
            v43[1] = 0i64;
          }
          v43 += 4;
          --v44;
        }
        while ( v44 );
        v42 = v68;
        v40 = v67;
      }
      v45 = v38 - v42;
      v46 = 32i64 * v42 + 16;
      v47 = (signed int)v38 - v42;
      if ( v45 > 0 )
      {
        v48 = (_QWORD *)((char *)v40 + v46);
        do
        {
          if ( v48 != (_QWORD *)16 )
          {
            *(v48 - 2) = 0i64;
            *(v48 - 1) = 0i64;
            *v48 = 0i64;
            v48[1] = 0i64;
          }
          v48 += 4;
          --v47;
        }
        while ( v47 );
      }
      v68 = v38;
      (*(void (__fastcall **)(__int64, char **, signed __int64))(*(_QWORD *)v35 + 96i64))(v35, &v67, v46);
      if ( (signed int)v38 > 0 )
      {
        v49 = 0i64;
        v71 = 0i64;
        do
        {
          v50 = v67;
          v51 = *(int **)&v67[v49 + 16];
          v52 = *v51;
          if ( *v51 == 8 || v52 == 9 && **((_DWORD **)v51 + 1) != 3 )
          {
            v57 = (hkDataArrayImpl *)arraySizea->m_impl->vfptr[10].__vecDelDtor(
                                       (hkDataRefCounted *)arraySizea->m_impl,
                                       *(_QWORD *)&v67[v49]);
            srca.m_impl = v57;
            if ( v57 )
            {
              ++v57->m_externalCount;
              ++v57->m_count;
            }
            v58 = (hkDataArrayImpl *)v81->m_impl->vfptr[10].__vecDelDtor(
                                       (hkDataRefCounted *)v81->m_impl,
                                       *(_QWORD *)&v50[v49]);
            dsta.m_impl = v58;
            if ( v58 )
            {
              ++v58->m_externalCount;
              ++v58->m_count;
              v58 = dsta.m_impl;
            }
            v59 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v58->vfptr[5].__vecDelDtor)(v58);
            srca.m_impl->vfptr[4].__vecDelDtor((hkDataRefCounted *)srca.m_impl, v59);
            v60 = ((__int64 (*)(void))dsta.m_impl->vfptr[5].__vecDelDtor)();
            hkDataWorldCloner::copyArray(v79, &srca, &dsta, v60);
            v61 = dsta.m_impl;
            if ( dsta.m_impl )
            {
              --dsta.m_impl->m_externalCount;
              v19 = v61->m_count-- == 1;
              if ( v19 )
                v61->vfptr->__vecDelDtor((hkDataRefCounted *)&v61->vfptr, 1u);
            }
            v62 = srca.m_impl;
            if ( srca.m_impl )
            {
              --srca.m_impl->m_externalCount;
              v19 = v62->m_count-- == 1;
              if ( v19 )
                v62->vfptr->__vecDelDtor((hkDataRefCounted *)&v62->vfptr, 1u);
            }
          }
          else if ( v52 != 1 )
          {
            v53 = (__int64)arraySizea->m_impl->vfptr[10].__vecDelDtor(
                             (hkDataRefCounted *)arraySizea->m_impl,
                             *(_QWORD *)&v67[v49]);
            v54 = v53;
            if ( v53 )
            {
              ++*(_WORD *)(v53 + 10);
              ++*(_DWORD *)(v53 + 12);
            }
            v55 = (__int64)v81->m_impl->vfptr[10].__vecDelDtor((hkDataRefCounted *)v81->m_impl, *(_QWORD *)&v50[v71]);
            v56 = v55;
            if ( v55 )
            {
              ++*(_WORD *)(v55 + 10);
              ++*(_DWORD *)(v55 + 12);
            }
            if ( v82 > 0 )
            {
              do
              {
                v75.m128i_i64[0] = v54;
                v75.m128i_i32[2] = v37;
                _mm_store_si128((__m128i *)&v78, v75);
                v76 = v56;
                v77 = v37;
                hkDataWorldCloner::copySimpleValue<hkDataArray_Value>(
                  v79,
                  (hkDataArray_Value *)&v78,
                  (hkDataArray_Value *)&v76);
                ++v37;
              }
              while ( v37 < v82 );
              v37 = 0;
            }
            if ( v56 )
            {
              --*(_WORD *)(v56 + 10);
              v19 = (*(_DWORD *)(v56 + 12))-- == 1;
              if ( v19 )
                (**(void (__fastcall ***)(__int64, signed __int64))v56)(v56, 1i64);
            }
            if ( v54 )
            {
              --*(_WORD *)(v54 + 10);
              v19 = (*(_DWORD *)(v54 + 12))-- == 1;
              if ( v19 )
                (**(void (__fastcall ***)(__int64, signed __int64))v54)(v54, 1i64);
            }
            v49 = v71;
          }
          v49 += 32i64;
          v19 = v72-- == 1;
          v71 = v49;
        }
        while ( !v19 );
      }
      v68 = 0;
      if ( v69 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v67,
          32 * v69);
      break;
    case 7:
      v6->m_impl->vfptr[4].__vecDelDtor((hkDataRefCounted *)v6->m_impl, v4);
      for ( l = 0; l < v4; ++l )
      {
        v29 = (hkDataObjectImpl *)v81->m_impl->vfptr[21].__vecDelDtor((hkDataRefCounted *)v81->m_impl, l);
        srcObject.m_impl = v29;
        if ( v29 )
        {
          ++v29->m_externalCount;
          ++v29->m_count;
        }
        v30 = v6->m_impl;
        v31 = hkDataWorldCloner::copyObject(v79, &result, &srcObject);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, hkDataObjectImpl *))v30->vfptr[22].__vecDelDtor)(
          v30,
          (unsigned int)l,
          v31->m_impl);
        v32 = result.m_impl;
        if ( result.m_impl )
        {
          --result.m_impl->m_externalCount;
          v19 = v32->m_count-- == 1;
          if ( v19 )
            v32->vfptr->__vecDelDtor((hkDataRefCounted *)&v32->vfptr, 1u);
        }
        v33 = srcObject.m_impl;
        if ( srcObject.m_impl )
        {
          --srcObject.m_impl->m_externalCount;
          v19 = v33->m_count-- == 1;
          if ( v19 )
            v33->vfptr->__vecDelDtor((hkDataRefCounted *)&v33->vfptr, 1u);
        }
        v6 = arraySizea;
      }
      break;
    case 8:
      v6->m_impl->vfptr[4].__vecDelDtor((hkDataRefCounted *)v6->m_impl, v4);
      for ( m = 0; m < v4; ++m )
      {
        v22 = (hkDataArrayImpl *)v6->m_impl->vfptr[23].__vecDelDtor((hkDataRefCounted *)v6->m_impl, m);
        dsta.m_impl = v22;
        if ( v22 )
        {
          ++v22->m_externalCount;
          ++v22->m_count;
        }
        v23 = (hkDataArray *)v81->m_impl->vfptr[23].__vecDelDtor((hkDataRefCounted *)v81->m_impl, m);
        arraySizea = v23;
        if ( v23 )
        {
          ++WORD1(v23[1].m_impl);
          ++HIDWORD(v23[1].m_impl);
          v23 = arraySizea;
        }
        v24 = (*(__int64 (__fastcall **)(hkDataArray *))&v23->m_impl[2].m_memSize)(v23);
        dsta.m_impl->vfptr[4].__vecDelDtor((hkDataRefCounted *)dsta.m_impl, v24);
        v25 = (*(__int64 (**)(void))&arraySizea->m_impl[2].m_memSize)();
        hkDataWorldCloner::copyArray(v79, &dsta, (hkDataArray *)&arraySizea, v25);
        v26 = arraySizea;
        if ( arraySizea )
        {
          --WORD1(arraySizea[1].m_impl);
          v19 = HIDWORD(v26[1].m_impl)-- == 1;
          if ( v19 )
            ((void (__fastcall *)(hkDataArray *, signed __int64))v26->m_impl->vfptr)(v26, 1i64);
        }
        v27 = dsta.m_impl;
        if ( dsta.m_impl )
        {
          --dsta.m_impl->m_externalCount;
          v19 = v27->m_count-- == 1;
          if ( v19 )
            v27->vfptr->__vecDelDtor((hkDataRefCounted *)&v27->vfptr, 1u);
        }
      }
      break;
    case 9:
      v11 = hkTypeManager::Type::getTupleSize(v7);
      v12 = *(_DWORD **)(v72 + 8);
      LODWORD(arraySizea) = v11;
      if ( *v12 == 3 )
      {
        for ( n = 0; n < v4; ++n )
        {
          v14 = (__int64)v81->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v81->m_impl, n);
          ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v6->m_impl->vfptr[12].__vecDelDtor)(
            v6->m_impl,
            (unsigned int)n,
            v14);
        }
      }
      else
      {
        v6->m_impl->vfptr[4].__vecDelDtor((hkDataRefCounted *)v6->m_impl, v4);
        for ( ii = 0; ii < v4; ++ii )
        {
          v16 = (hkDataArrayImpl *)v81->m_impl->vfptr[23].__vecDelDtor((hkDataRefCounted *)v81->m_impl, ii);
          srca.m_impl = v16;
          if ( v16 )
          {
            ++v16->m_externalCount;
            ++v16->m_count;
          }
          v17 = (hkDataArrayImpl *)v6->m_impl->vfptr[23].__vecDelDtor((hkDataRefCounted *)v6->m_impl, ii);
          dsta.m_impl = v17;
          if ( v17 )
          {
            ++v17->m_externalCount;
            ++v17->m_count;
            v17 = dsta.m_impl;
          }
          v17->vfptr[4].__vecDelDtor((hkDataRefCounted *)&v17->vfptr, (unsigned int)arraySizea);
          hkDataWorldCloner::copyArray(v79, &dsta, &srca, (int)arraySizea);
          v18 = dsta.m_impl;
          if ( dsta.m_impl )
          {
            --dsta.m_impl->m_externalCount;
            v19 = v18->m_count-- == 1;
            if ( v19 )
              v18->vfptr->__vecDelDtor((hkDataRefCounted *)&v18->vfptr, 1u);
          }
          v20 = srca.m_impl;
          if ( srca.m_impl )
          {
            --srca.m_impl->m_externalCount;
            v19 = v20->m_count-- == 1;
            if ( v19 )
              v20->vfptr->__vecDelDtor((hkDataRefCounted *)&v20->vfptr, 1u);
          }
        }
      }
      break;
    default:
      return;
  }
}

// File Line: 212
// RVA: 0xE639A0
void __fastcall hkDataWorldCloner::copyValue(hkDataWorldCloner *this, hkDataObject *dstObj, hkDataObject *srcObj, hkDataClass_MemberInfo *minfo)
{
  hkTypeManager::Type *v4; // rax
  hkDataClass_MemberInfo *v5; // rsi
  hkDataObject *v6; // rbx
  hkDataObject *v7; // rdi
  hkDataWorldCloner *v8; // r14
  hkDataArrayImpl *v9; // rax
  hkDataArrayImpl *v10; // rbx
  hkDataArrayImpl *v11; // rax
  hkDataArrayImpl *v12; // rdi
  unsigned int v13; // eax
  int v14; // eax
  bool v15; // zf
  hkDataArrayImpl *v16; // rax
  hkDataArrayImpl *v17; // rax
  hkDataArrayImpl *v18; // rdi
  unsigned int v19; // eax
  int v20; // eax
  hkDataObjectImpl *v21; // rcx
  hkDataRefCountedVtbl *v22; // rax
  const char *v23; // r8
  hkDataArray dst; // [rsp+20h] [rbp-30h]
  __int64 v25; // [rsp+28h] [rbp-28h]
  __m128i v26; // [rsp+30h] [rbp-20h]
  __int128 v27; // [rsp+40h] [rbp-10h]
  hkDataArray src; // [rsp+88h] [rbp+38h]

  v4 = minfo->m_type;
  v5 = minfo;
  v6 = srcObj;
  v7 = dstObj;
  v8 = this;
  if ( v4->m_subType != 9 || v4->m_parent->m_subType == 3 )
  {
    if ( v4->m_subType != 8 )
    {
      ((void (__fastcall *)(hkDataObjectImpl *, __m128i *, const char *))dstObj->m_impl->vfptr[3].__vecDelDtor)(
        dstObj->m_impl,
        &v26,
        minfo->m_name);
      v21 = v6->m_impl;
      v22 = v6->m_impl->vfptr;
      v23 = v5->m_name;
      _mm_store_si128((__m128i *)&v27, v26);
      ((void (__fastcall *)(hkDataObjectImpl *, hkDataArray *, const char *))v22[3].__vecDelDtor)(v21, &dst, v23);
      hkDataWorldCloner::copySimpleValue<hkDataObject_Value>(v8, (hkDataObject_Value *)&v27, (hkDataObject_Value *)&dst);
      return;
    }
    ((void (__fastcall *)(hkDataObjectImpl *, __m128i *, const char *))srcObj->m_impl->vfptr[3].__vecDelDtor)(
      srcObj->m_impl,
      &v26,
      minfo->m_name);
    v16 = (hkDataArrayImpl *)(*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v26.m128i_i64[0] + 80i64))(
                               v26.m128i_i64[0],
                               v26.m128i_i64[1]);
    v10 = v16;
    src.m_impl = v16;
    if ( v16 )
    {
      ++v16->m_externalCount;
      ++v16->m_count;
    }
    ((void (__fastcall *)(hkDataObjectImpl *, __m128i *, const char *))v7->m_impl->vfptr[3].__vecDelDtor)(
      v7->m_impl,
      &v26,
      v5->m_name);
    v17 = (hkDataArrayImpl *)(*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v26.m128i_i64[0] + 80i64))(
                               v26.m128i_i64[0],
                               v26.m128i_i64[1]);
    v18 = v17;
    dst.m_impl = v17;
    if ( v17 )
    {
      ++v17->m_externalCount;
      ++v17->m_count;
    }
    v19 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v10->vfptr[5].__vecDelDtor)(v10);
    v18->vfptr[4].__vecDelDtor((hkDataRefCounted *)&v18->vfptr, v19);
    v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v10->vfptr[5].__vecDelDtor)(v10);
    hkDataWorldCloner::copyArray(v8, &dst, &src, v20);
    --v18->m_externalCount;
    v15 = v18->m_count-- == 1;
    if ( v15 )
      v18->vfptr->__vecDelDtor((hkDataRefCounted *)&v18->vfptr, 1u);
    goto LABEL_18;
  }
  ((void (__fastcall *)(hkDataObjectImpl *, hkDataArray *, const char *))srcObj->m_impl->vfptr[3].__vecDelDtor)(
    srcObj->m_impl,
    &dst,
    minfo->m_name);
  v9 = (hkDataArrayImpl *)dst.m_impl->vfptr[10].__vecDelDtor((hkDataRefCounted *)dst.m_impl, v25);
  v10 = v9;
  src.m_impl = v9;
  if ( v9 )
  {
    ++v9->m_externalCount;
    ++v9->m_count;
  }
  ((void (__fastcall *)(hkDataObjectImpl *, __m128i *, const char *))v7->m_impl->vfptr[3].__vecDelDtor)(
    v7->m_impl,
    &v26,
    v5->m_name);
  v11 = (hkDataArrayImpl *)(*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v26.m128i_i64[0] + 80i64))(
                             v26.m128i_i64[0],
                             v26.m128i_i64[1]);
  v12 = v11;
  dst.m_impl = v11;
  if ( v11 )
  {
    ++v11->m_externalCount;
    ++v11->m_count;
  }
  v13 = hkTypeManager::Type::getTupleSize(v5->m_type);
  v12->vfptr[4].__vecDelDtor((hkDataRefCounted *)&v12->vfptr, v13);
  v14 = hkTypeManager::Type::getTupleSize(v5->m_type);
  hkDataWorldCloner::copyArray(v8, &dst, &src, v14);
  --v12->m_externalCount;
  v15 = v12->m_count-- == 1;
  if ( v15 )
    v12->vfptr->__vecDelDtor((hkDataRefCounted *)&v12->vfptr, 1u);
  if ( v10 )
  {
LABEL_18:
    --v10->m_externalCount;
    v15 = v10->m_count-- == 1;
    if ( v15 )
      v10->vfptr->__vecDelDtor((hkDataRefCounted *)&v10->vfptr, 1u);
  }
}

// File Line: 236
// RVA: 0xE63BC0
hkDataClassImpl *__fastcall hkDataWorldCloner::findDestClass(hkDataWorldCloner *this, const char *classname)
{
  hkDataWorldCloner *v2; // rsi
  const char *v3; // rbx
  int v4; // edi
  hkDataClassImpl *v5; // rax
  __int64 v6; // rax
  int v7; // er8
  hkDataClass::Cinfo *v8; // rdx
  __int64 v9; // rax
  __int64 v10; // rax
  int v11; // eax
  __int64 v12; // rdi
  signed __int64 v13; // rcx
  __int64 v14; // rdx
  __int64 v15; // rsi
  __int64 v16; // rbx
  int v17; // er9
  __int64 v18; // rcx
  __int64 v19; // rbx
  _QWORD *v20; // rdi
  hkTypeManager *v21; // rax
  hkTypeManager::Type *v22; // rax
  bool v23; // zf
  signed int v24; // edi
  __int64 v25; // rbx
  hkTypeManager::Type *v26; // rax
  const char *v27; // rax
  hkDataClassImpl *v28; // rsi
  __int64 v29; // rdi
  __int64 v30; // rbx
  __int64 v31; // [rsp+30h] [rbp-19h]
  __int64 v32; // [rsp+38h] [rbp-11h]
  signed __int64 v33; // [rsp+40h] [rbp-9h]
  hkDataClass::Cinfo *array; // [rsp+48h] [rbp-1h]
  int v35; // [rsp+50h] [rbp+7h]
  int v36; // [rsp+54h] [rbp+Bh]
  __int64 v37; // [rsp+58h] [rbp+Fh]
  __int64 v38; // [rsp+60h] [rbp+17h]
  __int128 v39; // [rsp+68h] [rbp+1Fh]
  int v40; // [rsp+78h] [rbp+2Fh]
  int v41; // [rsp+7Ch] [rbp+33h]
  hkDataWorldCloner *v42; // [rsp+B0h] [rbp+67h]
  const char *v43; // [rsp+B8h] [rbp+6Fh]
  hkResult result; // [rsp+C0h] [rbp+77h]
  __int64 v45; // [rsp+C8h] [rbp+7Fh]

  v43 = classname;
  v42 = this;
  v2 = this;
  v3 = classname;
  result.m_enum = 0;
  v4 = 0;
  v5 = (hkDataClassImpl *)((__int64 (*)(void))this->m_dstWorld->vfptr[4].__first_virtual_table_function__)();
  if ( !v5 )
  {
    array = 0i64;
    v35 = 0;
    v36 = 2147483648;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 10, 40);
    if ( v43 )
    {
      do
      {
        if ( ((__int64 (__fastcall *)(hkDataWorld *, const char *))v2->m_dstWorld->vfptr[4].__first_virtual_table_function__)(
               v2->m_dstWorld,
               v3) )
        {
          break;
        }
        v6 = ((__int64 (__fastcall *)(hkDataWorld *, const char *))v2->m_srcWorld->vfptr[4].__first_virtual_table_function__)(
               v2->m_srcWorld,
               v3);
        v7 = v35;
        *(_QWORD *)&result.m_enum = v6;
        if ( v35 == (v36 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 40);
          v7 = v35;
        }
        v8 = array;
        v3 = 0i64;
        v9 = (__int64)&array[v7];
        if ( v9 )
        {
          *(_QWORD *)(v9 + 24) = 0i64;
          *(_DWORD *)(v9 + 32) = 0;
          *(_DWORD *)(v9 + 36) = 2147483648;
          v7 = v35;
          v8 = array;
        }
        v35 = v7 + 1;
        hkDataClass::getCinfo((hkDataClass *)&result, &v8[v7]);
        if ( (*(__int64 (**)(void))(**(_QWORD **)&result.m_enum + 32i64))() )
        {
          v4 |= 1u;
          v10 = (*(__int64 (**)(void))(**(_QWORD **)&result.m_enum + 32i64))();
          v3 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 16i64))(v10);
        }
        if ( v4 & 1 )
          v4 &= 0xFFFFFFFE;
      }
      while ( v3 );
    }
    v11 = v35 - 1;
    v12 = v35 - 1;
    v32 = v35 - 1;
    if ( v35 - 1 >= 0 )
    {
      v13 = 40i64 * v11;
      v14 = 0i64;
      v33 = 40i64 * v11;
      do
      {
        v40 = 0;
        v15 = (__int64)array + v13;
        v41 = 2147483648;
        v37 = *(__int64 *)((char *)&array->name + v13);
        LODWORD(v38) = *(int *)((char *)&array->version + v13);
        v39 = *(unsigned __int64 *)((char *)&array->parent + v13);
        v16 = *(int *)((char *)&array->members.m_size + v13);
        if ( (signed int)v16 <= 0 )
        {
          result.m_enum = (signed int)v14;
        }
        else
        {
          v17 = v16;
          if ( (signed int)v16 < 0 )
            v17 = v14;
          hkArrayUtil::_reserve(
            &result,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            (char *)&v39 + 8,
            v17,
            24);
          v14 = 0i64;
        }
        v40 = v16;
        v31 = v16;
        if ( (signed int)v16 > 0 )
        {
          v18 = 0i64;
          v45 = 0i64;
          do
          {
            v19 = v18 + *(_QWORD *)(v15 + 24);
            v20 = (_QWORD *)(v18 + *((_QWORD *)&v39 + 1));
            *v20 = *(_QWORD *)v19;
            v20[1] = *(_QWORD *)(v19 + 8);
            v20[2] = *(_QWORD *)(v19 + 16);
            v21 = (hkTypeManager *)((__int64 (__fastcall *)(hkDataWorld *, __int64))v42->m_dstWorld->vfptr[5].__first_virtual_table_function__)(
                                     v42->m_dstWorld,
                                     v14);
            v22 = hkTypeManager::copyType(v21, *(hkTypeManager::Type **)(v19 + 8));
            v18 = v45 + 24;
            v23 = v31-- == 1;
            v20[1] = v22;
            v45 = v18;
          }
          while ( !v23 );
          v12 = v32;
        }
        v2 = v42;
        ((void (__fastcall *)(hkDataWorld *, __int64 *))v42->m_dstWorld->vfptr[1].__first_virtual_table_function__)(
          v42->m_dstWorld,
          &v37);
        v14 = 0i64;
        v40 = 0;
        if ( v41 >= 0 )
        {
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            (void *)*((_QWORD *)&v39 + 1),
            24 * (v41 & 0x3FFFFFFF));
          v14 = 0i64;
        }
        --v12;
        v13 = v33 - 40;
        v32 = v12;
        v33 -= 40i64;
      }
      while ( v12 >= 0 );
    }
    v24 = 0;
    v25 = ((__int64 (__fastcall *)(hkDataWorld *, const char *))v2->m_srcWorld->vfptr[4].__first_virtual_table_function__)(
            v2->m_srcWorld,
            v43);
    if ( (*(signed int (__fastcall **)(__int64))(*(_QWORD *)v25 + 72i64))(v25) > 0 )
    {
      do
      {
        v37 = 0i64;
        v38 = 0i64;
        v39 = 0ui64;
        (*(void (__fastcall **)(__int64, _QWORD, __int64 *))(*(_QWORD *)v25 + 80i64))(v25, (unsigned int)v24, &v37);
        v26 = hkTypeManager::Type::findTerminal((hkTypeManager::Type *)v39);
        if ( v26->m_subType == 6 )
        {
          v27 = hkTypeManager::Type::getTypeName(v26);
          hkDataWorldCloner::findDestClass(v2, v27);
        }
        ++v24;
      }
      while ( v24 < (*(signed int (__fastcall **)(__int64))(*(_QWORD *)v25 + 72i64))(v25) );
    }
    v28 = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorld *, const char *))v2->m_dstWorld->vfptr[4].__first_virtual_table_function__)(
                               v2->m_dstWorld,
                               v43);
    v29 = v35 - 1;
    if ( v35 - 1 >= 0 )
    {
      v30 = (__int64)(&array->members.m_capacityAndFlags + 10 * (v35 - 1));
      do
      {
        *(_DWORD *)(v30 - 4) = 0;
        if ( *(_DWORD *)v30 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)(v30 - 12),
            24 * (*(_DWORD *)v30 & 0x3FFFFFFF));
        *(_DWORD *)v30 = 2147483648;
        v30 -= 40i64;
        --v29;
        *(_QWORD *)(v30 + 28) = 0i64;
      }
      while ( v29 >= 0 );
    }
    v35 = 0;
    if ( v36 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        40 * (v36 & 0x3FFFFFFF));
    v5 = v28;
  }
  return v5;
}

// File Line: 295
// RVA: 0xE63F90
void __fastcall hkDataWorldCloner::getClassMemberInfos(hkDataWorldCloner *this, hkArray<hkDataClass_MemberInfo,hkContainerTempAllocator> *dstInfos, hkDataClass *dstClass, hkDataClass *srcClass)
{
  hkDataWorldCloner *v4; // rbp
  hkDataClass *v5; // rsi
  hkDataClass *v6; // r14
  hkArray<hkDataClass_MemberInfo,hkContainerTempAllocator> *v7; // rbx
  int v8; // eax
  int v9; // ecx
  int v10; // edi
  int v11; // ecx
  int v12; // er9
  __int64 v13; // rax
  int v14; // ecx
  signed __int64 v15; // rax
  __int64 v16; // rdx
  _QWORD *v17; // rax
  hkDataClassImpl *v18; // rcx
  int v19; // eax
  int v20; // ebx
  int v21; // er9
  __int64 v22; // rdx
  char *v23; // rax
  hkDataClassImpl *v24; // rcx
  signed int v25; // edi
  __int64 v26; // rbx
  hkTypeManager::Type *v27; // rax
  const char *v28; // rax
  char *array; // [rsp+30h] [rbp-28h]
  int v30; // [rsp+38h] [rbp-20h]
  int v31; // [rsp+3Ch] [rbp-1Ch]
  hkResult result; // [rsp+68h] [rbp+10h]

  v4 = this;
  v5 = srcClass;
  v6 = dstClass;
  v7 = dstInfos;
  v8 = ((__int64 (*)(void))dstClass->m_impl->vfptr[9].__vecDelDtor)();
  v9 = v7->m_capacityAndFlags & 0x3FFFFFFF;
  v10 = v8;
  if ( v9 < v8 )
  {
    v11 = 2 * v9;
    v12 = v8;
    if ( v8 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v7, v12, 32);
  }
  v13 = v7->m_size;
  v14 = v10 - v13;
  v15 = 32 * v13 + 16;
  v16 = v14;
  if ( v14 > 0 )
  {
    v17 = (const char **)((char *)&v7->m_data->m_name + v15);
    do
    {
      if ( v17 != (_QWORD *)16 )
      {
        *(v17 - 2) = 0i64;
        *(v17 - 1) = 0i64;
        *v17 = 0i64;
        v17[1] = 0i64;
      }
      v17 += 4;
      --v16;
    }
    while ( v16 );
  }
  v7->m_size = v10;
  v6->m_impl->vfptr[12].__vecDelDtor((hkDataRefCounted *)&v6->m_impl->vfptr, (unsigned int)v7);
  v18 = v5->m_impl;
  array = 0i64;
  v30 = 0;
  v31 = 2147483648;
  v19 = ((__int64 (*)(void))v18->vfptr[9].__vecDelDtor)();
  v20 = v19;
  if ( v19 > 0 )
  {
    v21 = v19;
    if ( v19 < 0 )
      v21 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v21, 32);
  }
  v22 = v20 - v30;
  if ( v20 - v30 > 0 )
  {
    v23 = &array[32 * v30 + 16];
    do
    {
      if ( v23 != (char *)16 )
      {
        *((_QWORD *)v23 - 2) = 0i64;
        *((_QWORD *)v23 - 1) = 0i64;
        *(_QWORD *)v23 = 0i64;
        *((_QWORD *)v23 + 1) = 0i64;
      }
      v23 += 32;
      --v22;
    }
    while ( v22 );
  }
  v24 = v5->m_impl;
  v30 = v20;
  v24->vfptr[12].__vecDelDtor((hkDataRefCounted *)&v24->vfptr, (unsigned int)&array);
  v25 = 0;
  if ( ((signed int (*)(void))v5->m_impl->vfptr[9].__vecDelDtor)() > 0 )
  {
    v26 = 0i64;
    do
    {
      v27 = hkTypeManager::Type::findTerminal(*(hkTypeManager::Type **)&array[v26 + 16]);
      if ( v27->m_subType == 6 )
      {
        v28 = hkTypeManager::Type::getTypeName(v27);
        hkDataWorldCloner::findDestClass(v4, v28);
      }
      ++v25;
      v26 += 32i64;
    }
    while ( v25 < ((signed int (*)(void))v5->m_impl->vfptr[9].__vecDelDtor)() );
  }
  v30 = 0;
  if ( v31 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      32 * v31);
}

// File Line: 316
// RVA: 0xE64190
void __fastcall hkDataWorldCloner::copyObjectMembers(hkDataWorldCloner *this, hkDataObject *dstObject, hkDataObject *srcObject)
{
  hkDataWorldCloner *v3; // rbp
  hkDataObject *v4; // rdi
  hkDataObject *v5; // rsi
  hkDataClassImpl *v6; // rax
  hkDataObject v7; // rcx
  int i; // ebx
  hkArray<hkDataClass_MemberInfo,hkContainerTempAllocator> dstInfos; // [rsp+20h] [rbp-28h]
  hkDataClass srcClass; // [rsp+58h] [rbp+10h]
  hkDataClass dstClass; // [rsp+60h] [rbp+18h]

  v3 = this;
  v4 = srcObject;
  v5 = dstObject;
  v6 = (hkDataClassImpl *)((__int64 (*)(void))dstObject->m_impl->vfptr[2].__vecDelDtor)();
  v7.m_impl = v4->m_impl;
  dstInfos.m_data = 0i64;
  dstClass.m_impl = v6;
  dstInfos.m_size = 0;
  dstInfos.m_capacityAndFlags = 2147483648;
  srcClass.m_impl = (hkDataClassImpl *)((__int64 (*)(void))v7.m_impl->vfptr[2].__vecDelDtor)();
  hkDataWorldCloner::getClassMemberInfos(v3, &dstInfos, &dstClass, &srcClass);
  for ( i = 0; i < dstInfos.m_size; ++i )
    hkDataWorldCloner::copyValue(v3, v5, v4, &dstInfos.m_data[i]);
  dstInfos.m_size = 0;
  if ( dstInfos.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      dstInfos.m_data,
      32 * dstInfos.m_capacityAndFlags);
}

// File Line: 327
// RVA: 0xE64270
hkDataObject *__fastcall hkDataWorldCloner::copyObject(hkDataWorldCloner *this, hkDataObject *result, hkDataObject *srcObject)
{
  hkDataWorldCloner *v3; // r15
  hkDataObject *v4; // r14
  hkDataObject *v5; // rsi
  hkDataObject *v6; // rax
  __int64 v7; // rax
  const char *v8; // rax
  hkDataClassImpl *v9; // rax
  hkDataWorld *v10; // rcx
  hkDataObjectImpl *v11; // rax
  hkDataObjectImpl *v12; // rbx
  __m128i *v13; // rax
  __m128i v14; // xmm6
  hkDataObjectImpl *v15; // rcx
  __m128i *v16; // rax
  __m128i v17; // xmm0
  int v18; // eax
  __m128i v19; // [rsp+20h] [rbp-40h]
  hkDataObject_Handle v20; // [rsp+30h] [rbp-30h]
  __int128 v21; // [rsp+40h] [rbp-20h]
  hkDataClassImpl *v22; // [rsp+A0h] [rbp+40h]
  hkDataObject dstObject; // [rsp+A8h] [rbp+48h]

  v3 = this;
  v4 = srcObject;
  v5 = result;
  if ( srcObject->m_impl )
  {
    v19 = *(__m128i *)srcObject->m_impl->vfptr[1].__vecDelDtor(
                        (hkDataRefCounted *)srcObject->m_impl,
                        (unsigned int)&v21);
    if ( hkMapBase<hkDataObject_Handle,hkDataObject_Handle,hkMapOperations<hkDataObject_Handle>>::get(
           (hkMapBase<hkDataObject_Handle,hkDataObject_Handle,hkMapOperations<hkDataObject_Handle> > *)&v3->m_copied.m_elem,
           (hkResult *)&v22,
           (hkDataObject_Handle *)&v19,
           &v20)->m_enum )
    {
      v7 = ((__int64 (*)(void))v4->m_impl->vfptr[2].__vecDelDtor)();
      v8 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 16i64))(v7);
      v9 = hkDataWorldCloner::findDestClass(v3, v8);
      v10 = v3->m_dstWorld;
      v22 = v9;
      v11 = (hkDataObjectImpl *)((__int64 (__fastcall *)(hkDataWorld *, hkDataClassImpl **, _QWORD))v10->vfptr[2].__vecDelDtor)(
                                  v10,
                                  &v22,
                                  0i64);
      v12 = v11;
      dstObject.m_impl = v11;
      if ( v11 )
      {
        ++v11->m_externalCount;
        ++v11->m_count;
      }
      v19 = 0ui64;
      if ( v11 )
      {
        v13 = (__m128i *)v11->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v11->vfptr, (unsigned int)&v21);
      }
      else
      {
        v13 = &v19;
        _mm_store_si128(&v19, v19);
      }
      v14 = *v13;
      v15 = v4->m_impl;
      v19 = 0ui64;
      if ( v15 )
      {
        v16 = (__m128i *)v15->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v15->vfptr, (unsigned int)&v19);
      }
      else
      {
        v16 = &v19;
        _mm_store_si128(&v19, v19);
      }
      v17 = *v16;
      _mm_store_si128((__m128i *)&v21, v14);
      v19 = v17;
      hkMapBase<hkDataObject_Handle,hkDataObject_Handle,hkMapOperations<hkDataObject_Handle>>::insert(
        (hkMapBase<hkDataObject_Handle,hkDataObject_Handle,hkMapOperations<hkDataObject_Handle> > *)&v3->m_copied.m_elem,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (hkDataObject_Handle *)&v19,
        (hkDataObject_Handle *)&v21);
      hkDataWorldCloner::copyObjectMembers(v3, &dstObject, v4);
      v5->m_impl = v12;
      if ( v12 )
      {
        v18 = v12->m_count;
        v12->m_count = v18;
        if ( !v18 )
          v12->vfptr->__vecDelDtor((hkDataRefCounted *)&v12->vfptr, 1u);
      }
      v6 = v5;
    }
    else
    {
      ((void (__fastcall *)(hkDataWorld *, hkDataObject *, hkDataObject_Handle *))v3->m_dstWorld->vfptr[5].__vecDelDtor)(
        v3->m_dstWorld,
        v5,
        &v20);
      v6 = v5;
    }
  }
  else
  {
    v6 = result;
    result->m_impl = 0i64;
  }
  return v6;
}

// File Line: 349
// RVA: 0xE631F0
hkResult *__fastcall hkDataWorldCloner::clone(hkDataWorldCloner *this, hkResult *result)
{
  hkDataWorldCloner *v2; // rbx
  hkResult *v3; // rdi
  hkDataObject *v4; // rax
  hkDataObjectImpl *v5; // rcx
  bool v6; // zf
  __int64 v7; // rcx
  hkDataObject resulta; // [rsp+30h] [rbp+8h]
  __int64 v10; // [rsp+38h] [rbp+10h]

  v2 = this;
  v3 = result;
  v4 = (hkDataObject *)((__int64 (__fastcall *)(hkDataWorld *, __int64 *))this->m_srcWorld->vfptr[3].__first_virtual_table_function__)(
                         this->m_srcWorld,
                         &v10);
  hkDataWorldCloner::copyObject(v2, &resulta, v4);
  v5 = resulta.m_impl;
  if ( resulta.m_impl )
  {
    --resulta.m_impl->m_externalCount;
    v6 = v5->m_count-- == 1;
    if ( v6 )
      v5->vfptr->__vecDelDtor((hkDataRefCounted *)&v5->vfptr, 1u);
  }
  v7 = v10;
  if ( v10 )
  {
    --*(_WORD *)(v10 + 10);
    v6 = (*(_DWORD *)(v7 + 12))-- == 1;
    if ( v6 )
      (**(void (__fastcall ***)(__int64, signed __int64))v7)(v7, 1i64);
  }
  v3->m_enum = 0;
  return v3;
}

