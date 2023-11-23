// File Line: 14
// RVA: 0xE631C0
void __fastcall hkDataWorldCloner::hkDataWorldCloner(
        hkDataWorldCloner *this,
        hkDataWorld *dstWorld,
        hkDataWorld *srcWorld)
{
  this->m_dstWorld = dstWorld;
  this->m_srcWorld = srcWorld;
  this->m_copied.m_elem = 0i64;
  this->m_copied.m_numElems = 0;
  this->m_copied.m_hashMod = -1;
}

// File Line: 20
// RVA: 0xE64430
void __fastcall hkDataWorldCloner::copySimpleValue<hkDataArray_Value>(
        hkDataWorldCloner *this,
        hkDataArray_Value *dst,
        hkDataArray_Value *src)
{
  __int64 v6; // rsi
  unsigned int v7; // eax
  void *v8; // rbx
  hkDataObjectImpl *v9; // rax
  hkDataObject *v10; // rax
  hkDataObjectImpl *m_impl; // rcx
  bool v12; // zf
  hkDataObjectImpl *v13; // rcx
  void *v14; // rax
  hkDataObject srcObject; // [rsp+50h] [rbp+18h] BYREF
  hkDataObject result; // [rsp+58h] [rbp+20h] BYREF

  v6 = ((__int64 (__fastcall *)(hkDataArrayImpl *))src->m_impl->vfptr[1].__vecDelDtor)(src->m_impl);
  switch ( *(_DWORD *)v6 )
  {
    case 2:
    case 4:
      v7 = (unsigned int)src->m_impl->vfptr[17].__vecDelDtor(src->m_impl, (unsigned int)src->m_index);
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))dst->m_impl->vfptr[18].__vecDelDtor)(
        dst->m_impl,
        (unsigned int)dst->m_index,
        v7);
      break;
    case 3:
      src->m_impl->vfptr[15].__vecDelDtor(src->m_impl, src->m_index);
      dst->m_impl->vfptr[16].__vecDelDtor(dst->m_impl, dst->m_index);
      break;
    case 5:
      v14 = src->m_impl->vfptr[13].__vecDelDtor(src->m_impl, (unsigned int)src->m_index);
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, void *))dst->m_impl->vfptr[14].__vecDelDtor)(
        dst->m_impl,
        (unsigned int)dst->m_index,
        v14);
      break;
    case 6:
    case 7:
      v9 = (hkDataObjectImpl *)src->m_impl->vfptr[21].__vecDelDtor(src->m_impl, (unsigned int)src->m_index);
      srcObject.m_impl = v9;
      if ( v9 )
      {
        ++v9->m_externalCount;
        ++v9->m_count;
      }
      v10 = hkDataWorldCloner::copyObject(this, &result, &srcObject);
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, hkDataObjectImpl *))dst->m_impl->vfptr[22].__vecDelDtor)(
        dst->m_impl,
        (unsigned int)dst->m_index,
        v10->m_impl);
      m_impl = result.m_impl;
      if ( result.m_impl )
      {
        --result.m_impl->m_externalCount;
        v12 = m_impl->m_count-- == 1;
        if ( v12 )
          m_impl->vfptr->__vecDelDtor(m_impl, 1u);
      }
      v13 = srcObject.m_impl;
      if ( srcObject.m_impl )
      {
        --srcObject.m_impl->m_externalCount;
        v12 = v13->m_count-- == 1;
        if ( v12 )
          v13->vfptr->__vecDelDtor(v13, 1u);
      }
      break;
    case 9:
      if ( **(_DWORD **)(v6 + 8) == 3 )
      {
        hkTypeManager::Type::getTupleSize((hkTypeManager::Type *)v6);
        v8 = src->m_impl->vfptr[11].__vecDelDtor(src->m_impl, (unsigned int)src->m_index);
        hkTypeManager::Type::getTupleSize((hkTypeManager::Type *)v6);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, void *))dst->m_impl->vfptr[12].__vecDelDtor)(
          dst->m_impl,
          (unsigned int)dst->m_index,
          v8);
      }
      break;
    default:
      return;
  }
}

// File Line: 71
// RVA: 0xE63280
void __fastcall hkDataWorldCloner::copyArray(
        hkDataWorldCloner *this,
        hkDataArrayImpl *dst,
        hkDataArray *src,
        int arraySize)
{
  hkDataArrayImpl *v6; // rbx
  hkTypeManager::Type *v7; // rax
  unsigned int i; // esi
  unsigned int v9; // eax
  unsigned int j; // esi
  int TupleSize; // eax
  _DWORD *v12; // rcx
  unsigned int ii; // esi
  __int64 v14; // rax
  unsigned int jj; // esi
  hkDataArrayImpl *v16; // rax
  hkDataArrayImpl *v17; // rax
  hkDataArrayImpl *v18; // rcx
  bool v19; // zf
  hkDataArrayImpl *v20; // rcx
  unsigned int n; // esi
  hkDataArrayImpl *v22; // rax
  hkDataArrayImpl *v23; // rax
  unsigned int v24; // eax
  int v25; // eax
  hkDataArrayImpl *v26; // rcx
  hkDataArrayImpl *v27; // rcx
  unsigned int m; // esi
  hkDataObjectImpl *v29; // rax
  hkDataRefCountedVtbl *vfptr; // rbx
  hkDataObject *v31; // rax
  hkDataObjectImpl *v32; // rcx
  hkDataObjectImpl *v33; // rcx
  __int64 v34; // rbx
  int v35; // eax
  int v36; // esi
  __int64 v37; // rdi
  int v38; // r8d
  _QWORD *v39; // rcx
  unsigned int v40; // eax
  int v41; // edx
  _QWORD *v42; // rax
  __int64 v43; // rdx
  int v44; // eax
  __int64 v45; // r8
  __int64 v46; // rdx
  _QWORD *v47; // rax
  __int64 v48; // rdi
  char *v49; // rbx
  int *v50; // rax
  int v51; // ecx
  __int64 v52; // rax
  hkDataArrayImpl *v53; // rdi
  __int64 v54; // rax
  hkDataArrayImpl *v55; // rbx
  hkDataArrayImpl *v56; // rax
  hkDataArrayImpl *m_impl; // rax
  unsigned int v58; // eax
  int v59; // eax
  hkDataArrayImpl *v60; // rcx
  hkDataArrayImpl *v61; // rcx
  unsigned int k; // esi
  __int64 v63; // rax
  hkDataArray dsta; // [rsp+20h] [rbp-49h] BYREF
  int v65; // [rsp+28h] [rbp-41h] BYREF
  char *v66; // [rsp+30h] [rbp-39h] BYREF
  int v67; // [rsp+38h] [rbp-31h]
  int v68; // [rsp+3Ch] [rbp-2Dh]
  hkDataArray srca; // [rsp+40h] [rbp-29h] BYREF
  __int64 v70; // [rsp+48h] [rbp-21h]
  __int64 v71; // [rsp+50h] [rbp-19h]
  hkDataObject srcObject; // [rsp+58h] [rbp-11h] BYREF
  hkDataObject result; // [rsp+60h] [rbp-9h] BYREF
  hkDataArray_Value v74; // [rsp+70h] [rbp+7h]
  hkDataArray_Value v75; // [rsp+80h] [rbp+17h] BYREF
  hkDataArray_Value v76; // [rsp+90h] [rbp+27h] BYREF
  hkDataArray arraySizea; // [rsp+D8h] [rbp+6Fh] BYREF
  hkDataArray *v79; // [rsp+E0h] [rbp+77h]
  int v80; // [rsp+E8h] [rbp+7Fh]

  v80 = arraySize;
  v79 = src;
  arraySizea.m_impl = dst;
  v6 = dst;
  v7 = (hkTypeManager::Type *)(*((__int64 (**)(void))dst->vfptr->__vecDelDtor + 1))();
  v71 = (__int64)v7;
  switch ( v7->m_subType )
  {
    case SUB_TYPE_BYTE:
    case SUB_TYPE_INT:
      for ( i = 0; (int)i < arraySize; ++i )
      {
        v9 = (unsigned int)v79->m_impl->vfptr[17].__vecDelDtor(v79->m_impl, i);
        (*((void (__fastcall **)(hkDataRefCountedVtbl *, _QWORD, _QWORD))v6->vfptr->__vecDelDtor + 18))(
          v6->vfptr,
          i,
          v9);
      }
      break;
    case SUB_TYPE_REAL:
      for ( j = 0; (int)j < arraySize; ++j )
      {
        v79->m_impl->vfptr[15].__vecDelDtor(v79->m_impl, j);
        (*((void (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v6->vfptr->__vecDelDtor + 16))(v6->vfptr, j);
      }
      break;
    case SUB_TYPE_CSTRING:
      for ( k = 0; (int)k < arraySize; ++k )
      {
        v63 = (__int64)v79->m_impl->vfptr[13].__vecDelDtor(v79->m_impl, k);
        (*((void (__fastcall **)(hkDataRefCountedVtbl *, _QWORD, __int64))v6->vfptr->__vecDelDtor + 14))(
          v6->vfptr,
          k,
          v63);
      }
      break;
    case SUB_TYPE_CLASS:
      (*((void (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v6->vfptr->__vecDelDtor + 4))(
        v6->vfptr,
        (unsigned int)arraySize);
      v34 = ((__int64 (__fastcall *)(hkDataArrayImpl *))src->m_impl->vfptr[6].__vecDelDtor)(src->m_impl);
      v35 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v34 + 72i64))(v34);
      v36 = 0;
      v68 = 0x80000000;
      v37 = v35;
      v66 = 0i64;
      v67 = 0;
      v38 = v35;
      if ( v35 )
      {
        v65 = 32 * v35;
        v39 = (_QWORD *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, _QWORD))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                          &hkContainerTempAllocator::s_alloc,
                          &v65,
                          (unsigned int)v35);
        v38 = v65 / 32;
      }
      else
      {
        v39 = 0i64;
      }
      v40 = 0x80000000;
      v41 = v37;
      if ( v38 )
        v40 = v38;
      v66 = (char *)v39;
      v71 = v37;
      v67 = v37;
      v68 = v40;
      if ( (int)v37 > 0 )
      {
        v42 = v39 + 2;
        v43 = v37;
        do
        {
          if ( v42 != (_QWORD *)16 )
          {
            *(v42 - 2) = 0i64;
            *(v42 - 1) = 0i64;
            *v42 = 0i64;
            v42[1] = 0i64;
          }
          v42 += 4;
          --v43;
        }
        while ( v43 );
        v41 = v67;
        v39 = v66;
      }
      v44 = v37 - v41;
      v45 = 32i64 * v41 + 16;
      v46 = (int)v37 - v41;
      if ( v44 > 0 )
      {
        v47 = (_QWORD *)((char *)v39 + v45);
        do
        {
          if ( v47 != (_QWORD *)16 )
          {
            *(v47 - 2) = 0i64;
            *(v47 - 1) = 0i64;
            *v47 = 0i64;
            v47[1] = 0i64;
          }
          v47 += 4;
          --v46;
        }
        while ( v46 );
      }
      v67 = v37;
      (*(void (__fastcall **)(__int64, char **, __int64))(*(_QWORD *)v34 + 96i64))(v34, &v66, v45);
      if ( (int)v37 > 0 )
      {
        v48 = 0i64;
        v70 = 0i64;
        do
        {
          v49 = v66;
          v50 = *(int **)&v66[v48 + 16];
          v51 = *v50;
          if ( *v50 == 8 || v51 == 9 && **((_DWORD **)v50 + 1) != 3 )
          {
            v56 = (hkDataArrayImpl *)(*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))arraySizea.m_impl->vfptr->__vecDelDtor
                                      + 10))(
                                       arraySizea.m_impl->vfptr,
                                       *(_QWORD *)&v66[v48]);
            srca.m_impl = v56;
            if ( v56 )
            {
              ++v56->m_externalCount;
              ++v56->m_count;
            }
            m_impl = (hkDataArrayImpl *)v79->m_impl->vfptr[10].__vecDelDtor(v79->m_impl, *(_QWORD *)&v49[v48]);
            dsta.m_impl = m_impl;
            if ( m_impl )
            {
              ++m_impl->m_externalCount;
              ++m_impl->m_count;
              m_impl = dsta.m_impl;
            }
            v58 = ((__int64 (__fastcall *)(hkDataArrayImpl *))m_impl->vfptr[5].__vecDelDtor)(m_impl);
            srca.m_impl->vfptr[4].__vecDelDtor(srca.m_impl, v58);
            v59 = ((__int64 (__fastcall *)(hkDataArrayImpl *))dsta.m_impl->vfptr[5].__vecDelDtor)(dsta.m_impl);
            hkDataWorldCloner::copyArray(this, &srca, &dsta, v59);
            v60 = dsta.m_impl;
            if ( dsta.m_impl )
            {
              --dsta.m_impl->m_externalCount;
              v19 = v60->m_count-- == 1;
              if ( v19 )
                v60->vfptr->__vecDelDtor(v60, 1u);
            }
            v61 = srca.m_impl;
            if ( srca.m_impl )
            {
              --srca.m_impl->m_externalCount;
              v19 = v61->m_count-- == 1;
              if ( v19 )
                v61->vfptr->__vecDelDtor(v61, 1u);
            }
          }
          else if ( v51 != 1 )
          {
            v52 = (*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))arraySizea.m_impl->vfptr->__vecDelDtor + 10))(
                    arraySizea.m_impl->vfptr,
                    *(_QWORD *)&v66[v48]);
            v53 = (hkDataArrayImpl *)v52;
            if ( v52 )
            {
              ++*(_WORD *)(v52 + 10);
              ++*(_DWORD *)(v52 + 12);
            }
            v54 = (__int64)v79->m_impl->vfptr[10].__vecDelDtor(v79->m_impl, *(_QWORD *)&v49[v70]);
            v55 = (hkDataArrayImpl *)v54;
            if ( v54 )
            {
              ++*(_WORD *)(v54 + 10);
              ++*(_DWORD *)(v54 + 12);
            }
            if ( v80 > 0 )
            {
              do
              {
                v74.m_impl = v53;
                v74.m_index = v36;
                v76 = v74;
                v75.m_impl = v55;
                v75.m_index = v36;
                hkDataWorldCloner::copySimpleValue<hkDataArray_Value>(this, &v76, &v75);
                ++v36;
              }
              while ( v36 < v80 );
              v36 = 0;
            }
            if ( v55 )
            {
              --v55->m_externalCount;
              v19 = v55->m_count-- == 1;
              if ( v19 )
                v55->vfptr->__vecDelDtor(v55, 1u);
            }
            if ( v53 )
            {
              --v53->m_externalCount;
              v19 = v53->m_count-- == 1;
              if ( v19 )
                v53->vfptr->__vecDelDtor(v53, 1u);
            }
            v48 = v70;
          }
          v48 += 32i64;
          v19 = v71-- == 1;
          v70 = v48;
        }
        while ( !v19 );
      }
      v67 = 0;
      if ( v68 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v66, 32 * v68);
      break;
    case SUB_TYPE_POINTER:
      (*((void (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v6->vfptr->__vecDelDtor + 4))(
        v6->vfptr,
        (unsigned int)arraySize);
      for ( m = 0; (int)m < arraySize; ++m )
      {
        v29 = (hkDataObjectImpl *)v79->m_impl->vfptr[21].__vecDelDtor(v79->m_impl, m);
        srcObject.m_impl = v29;
        if ( v29 )
        {
          ++v29->m_externalCount;
          ++v29->m_count;
        }
        vfptr = v6->vfptr;
        v31 = hkDataWorldCloner::copyObject(this, &result, &srcObject);
        (*((void (__fastcall **)(hkDataRefCountedVtbl *, _QWORD, hkDataObjectImpl *))vfptr->__vecDelDtor + 22))(
          vfptr,
          m,
          v31->m_impl);
        v32 = result.m_impl;
        if ( result.m_impl )
        {
          --result.m_impl->m_externalCount;
          v19 = v32->m_count-- == 1;
          if ( v19 )
            v32->vfptr->__vecDelDtor(v32, 1u);
        }
        v33 = srcObject.m_impl;
        if ( srcObject.m_impl )
        {
          --srcObject.m_impl->m_externalCount;
          v19 = v33->m_count-- == 1;
          if ( v19 )
            v33->vfptr->__vecDelDtor(v33, 1u);
        }
        v6 = arraySizea.m_impl;
      }
      break;
    case SUB_TYPE_ARRAY:
      (*((void (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v6->vfptr->__vecDelDtor + 4))(
        v6->vfptr,
        (unsigned int)arraySize);
      for ( n = 0; (int)n < arraySize; ++n )
      {
        v22 = (hkDataArrayImpl *)(*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v6->vfptr->__vecDelDtor + 23))(
                                   v6->vfptr,
                                   n);
        dsta.m_impl = v22;
        if ( v22 )
        {
          ++v22->m_externalCount;
          ++v22->m_count;
        }
        v23 = (hkDataArrayImpl *)v79->m_impl->vfptr[23].__vecDelDtor(v79->m_impl, n);
        arraySizea.m_impl = v23;
        if ( v23 )
        {
          ++v23->m_externalCount;
          ++v23->m_count;
          v23 = arraySizea.m_impl;
        }
        v24 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v23->vfptr[5].__vecDelDtor)(v23);
        dsta.m_impl->vfptr[4].__vecDelDtor(dsta.m_impl, v24);
        v25 = ((__int64 (__fastcall *)(hkDataArrayImpl *))arraySizea.m_impl->vfptr[5].__vecDelDtor)(arraySizea.m_impl);
        hkDataWorldCloner::copyArray(this, &dsta, &arraySizea, v25);
        v26 = arraySizea.m_impl;
        if ( arraySizea.m_impl )
        {
          --arraySizea.m_impl->m_externalCount;
          v19 = v26->m_count-- == 1;
          if ( v19 )
            v26->vfptr->__vecDelDtor(v26, 1u);
        }
        v27 = dsta.m_impl;
        if ( dsta.m_impl )
        {
          --dsta.m_impl->m_externalCount;
          v19 = v27->m_count-- == 1;
          if ( v19 )
            v27->vfptr->__vecDelDtor(v27, 1u);
        }
      }
      break;
    case SUB_TYPE_TUPLE:
      TupleSize = hkTypeManager::Type::getTupleSize(v7);
      v12 = *(_DWORD **)(v71 + 8);
      LODWORD(arraySizea.m_impl) = TupleSize;
      if ( *v12 == 3 )
      {
        for ( ii = 0; (int)ii < arraySize; ++ii )
        {
          v14 = (__int64)v79->m_impl->vfptr[11].__vecDelDtor(v79->m_impl, ii);
          (*((void (__fastcall **)(hkDataRefCountedVtbl *, _QWORD, __int64))v6->vfptr->__vecDelDtor + 12))(
            v6->vfptr,
            ii,
            v14);
        }
      }
      else
      {
        (*((void (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v6->vfptr->__vecDelDtor + 4))(
          v6->vfptr,
          (unsigned int)arraySize);
        for ( jj = 0; (int)jj < arraySize; ++jj )
        {
          v16 = (hkDataArrayImpl *)v79->m_impl->vfptr[23].__vecDelDtor(v79->m_impl, jj);
          srca.m_impl = v16;
          if ( v16 )
          {
            ++v16->m_externalCount;
            ++v16->m_count;
          }
          v17 = (hkDataArrayImpl *)(*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v6->vfptr->__vecDelDtor
                                    + 23))(
                                     v6->vfptr,
                                     jj);
          dsta.m_impl = v17;
          if ( v17 )
          {
            ++v17->m_externalCount;
            ++v17->m_count;
            v17 = dsta.m_impl;
          }
          v17->vfptr[4].__vecDelDtor(v17, (unsigned int)arraySizea.m_impl);
          hkDataWorldCloner::copyArray(this, &dsta, &srca, (int)arraySizea.m_impl);
          v18 = dsta.m_impl;
          if ( dsta.m_impl )
          {
            --dsta.m_impl->m_externalCount;
            v19 = v18->m_count-- == 1;
            if ( v19 )
              v18->vfptr->__vecDelDtor(v18, 1u);
          }
          v20 = srca.m_impl;
          if ( srca.m_impl )
          {
            --srca.m_impl->m_externalCount;
            v19 = v20->m_count-- == 1;
            if ( v19 )
              v20->vfptr->__vecDelDtor(v20, 1u);
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
void __fastcall hkDataWorldCloner::copyValue(
        hkDataWorldCloner *this,
        hkDataObject *dstObj,
        hkDataObject *srcObj,
        hkDataClass_MemberInfo *minfo)
{
  hkTypeManager::Type *m_type; // rax
  hkDataArrayImpl *v9; // rax
  hkDataArrayImpl *v10; // rbx
  hkDataObjectImpl *v11; // rax
  hkDataObjectImpl *v12; // rdi
  unsigned int TupleSize; // eax
  int v14; // eax
  bool v15; // zf
  hkDataArrayImpl *v16; // rax
  hkDataObjectImpl *v17; // rax
  hkDataObjectImpl *v18; // rdi
  unsigned int v19; // eax
  int v20; // eax
  hkDataObjectImpl *m_impl; // rcx
  hkDataRefCountedVtbl *vfptr; // rax
  const char *m_name; // r8
  hkDataObject_Value dst; // [rsp+20h] [rbp-30h] BYREF
  hkDataObject_Value v25; // [rsp+30h] [rbp-20h] BYREF
  hkDataObject_Value v26; // [rsp+40h] [rbp-10h] BYREF
  hkDataArray src; // [rsp+88h] [rbp+38h] BYREF

  m_type = minfo->m_type;
  if ( m_type->m_subType != SUB_TYPE_TUPLE || m_type->m_parent->m_subType == SUB_TYPE_REAL )
  {
    if ( m_type->m_subType != SUB_TYPE_ARRAY )
    {
      ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, const char *))dstObj->m_impl->vfptr[3].__vecDelDtor)(
        dstObj->m_impl,
        &v25,
        minfo->m_name);
      m_impl = srcObj->m_impl;
      vfptr = srcObj->m_impl->vfptr;
      m_name = minfo->m_name;
      v26 = v25;
      ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, const char *))vfptr[3].__vecDelDtor)(
        m_impl,
        &dst,
        m_name);
      hkDataWorldCloner::copySimpleValue<hkDataObject_Value>(this, &v26, &dst);
      return;
    }
    ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, const char *))srcObj->m_impl->vfptr[3].__vecDelDtor)(
      srcObj->m_impl,
      &v25,
      minfo->m_name);
    v16 = (hkDataArrayImpl *)v25.m_impl->vfptr[10].__vecDelDtor(v25.m_impl, v25.m_handle);
    v10 = v16;
    src.m_impl = v16;
    if ( v16 )
    {
      ++v16->m_externalCount;
      ++v16->m_count;
    }
    ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, const char *))dstObj->m_impl->vfptr[3].__vecDelDtor)(
      dstObj->m_impl,
      &v25,
      minfo->m_name);
    v17 = (hkDataObjectImpl *)v25.m_impl->vfptr[10].__vecDelDtor(v25.m_impl, v25.m_handle);
    v18 = v17;
    dst.m_impl = v17;
    if ( v17 )
    {
      ++v17->m_externalCount;
      ++v17->m_count;
    }
    v19 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v10->vfptr[5].__vecDelDtor)(v10);
    v18->vfptr[4].__vecDelDtor(v18, v19);
    v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v10->vfptr[5].__vecDelDtor)(v10);
    hkDataWorldCloner::copyArray(this, (hkDataArrayImpl *)&dst, &src, v20);
    --v18->m_externalCount;
    v15 = v18->m_count-- == 1;
    if ( v15 )
      v18->vfptr->__vecDelDtor(v18, 1u);
    goto LABEL_18;
  }
  ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, const char *))srcObj->m_impl->vfptr[3].__vecDelDtor)(
    srcObj->m_impl,
    &dst,
    minfo->m_name);
  v9 = (hkDataArrayImpl *)dst.m_impl->vfptr[10].__vecDelDtor(dst.m_impl, dst.m_handle);
  v10 = v9;
  src.m_impl = v9;
  if ( v9 )
  {
    ++v9->m_externalCount;
    ++v9->m_count;
  }
  ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, const char *))dstObj->m_impl->vfptr[3].__vecDelDtor)(
    dstObj->m_impl,
    &v25,
    minfo->m_name);
  v11 = (hkDataObjectImpl *)v25.m_impl->vfptr[10].__vecDelDtor(v25.m_impl, v25.m_handle);
  v12 = v11;
  dst.m_impl = v11;
  if ( v11 )
  {
    ++v11->m_externalCount;
    ++v11->m_count;
  }
  TupleSize = hkTypeManager::Type::getTupleSize(minfo->m_type);
  v12->vfptr[4].__vecDelDtor(v12, TupleSize);
  v14 = hkTypeManager::Type::getTupleSize(minfo->m_type);
  hkDataWorldCloner::copyArray(this, (hkDataArrayImpl *)&dst, &src, v14);
  --v12->m_externalCount;
  v15 = v12->m_count-- == 1;
  if ( v15 )
    v12->vfptr->__vecDelDtor(v12, 1u);
  if ( v10 )
  {
LABEL_18:
    --v10->m_externalCount;
    v15 = v10->m_count-- == 1;
    if ( v15 )
      v10->vfptr->__vecDelDtor(v10, 1u);
  }
}--v10->m_externalCount;
    v15 = v10->m_count-- == 1;
    if ( v15 )
      v1

// File Line: 236
// RVA: 0xE63BC0
hkDataClassImpl *__fastcall hkDataWorldCloner::findDestClass(hkDataWorldCloner *this, const char *classname)
{
  hkDataWorldCloner *v2; // rsi
  const char *v3; // rbx
  int v4; // edi
  hkDataClassImpl *v5; // rax
  hkDataClassImpl *v6; // rax
  int v7; // r8d
  char *v8; // rdx
  char *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rdi
  __int64 v12; // rcx
  __int64 v13; // rdx
  char *v14; // rsi
  __int64 v15; // rbx
  __int64 v16; // rcx
  __int64 v17; // rbx
  char *v18; // rdi
  hkTypeManager *v19; // rax
  hkTypeManager::Type *v20; // rax
  bool v21; // zf
  int v22; // edi
  __int64 v23; // rbx
  hkTypeManager::Type *Terminal; // rax
  const char *TypeName; // rax
  __int64 v26; // rsi
  __int64 v27; // rdi
  char *v28; // rbx
  __int64 v29; // [rsp+30h] [rbp-19h]
  __int64 v30; // [rsp+38h] [rbp-11h]
  __int64 v31; // [rsp+40h] [rbp-9h]
  char *array; // [rsp+48h] [rbp-1h] BYREF
  int v33; // [rsp+50h] [rbp+7h]
  int v34; // [rsp+54h] [rbp+Bh]
  __int64 v35; // [rsp+58h] [rbp+Fh] BYREF
  __int64 v36; // [rsp+60h] [rbp+17h]
  hkTypeManager::Type *v37; // [rsp+68h] [rbp+1Fh]
  char *v38; // [rsp+70h] [rbp+27h] BYREF
  int v39; // [rsp+78h] [rbp+2Fh]
  int v40; // [rsp+7Ch] [rbp+33h]
  hkDataClass result; // [rsp+C0h] [rbp+77h] BYREF
  __int64 v44; // [rsp+C8h] [rbp+7Fh]

  v2 = this;
  v3 = classname;
  LODWORD(result.m_impl) = 0;
  v4 = 0;
  v5 = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorld *))this->m_dstWorld->vfptr[4].__first_virtual_table_function__)(this->m_dstWorld);
  if ( !v5 )
  {
    array = 0i64;
    v33 = 0;
    v34 = 0x80000000;
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerTempAllocator::s_alloc, (const void **)&array, 10, 40);
    if ( classname )
    {
      do
      {
        if ( ((__int64 (__fastcall *)(hkDataWorld *, const char *))v2->m_dstWorld->vfptr[4].__first_virtual_table_function__)(
               v2->m_dstWorld,
               v3) )
        {
          break;
        }
        v6 = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorld *, const char *))v2->m_srcWorld->vfptr[4].__first_virtual_table_function__)(
                                  v2->m_srcWorld,
                                  v3);
        v7 = v33;
        result.m_impl = v6;
        if ( v33 == (v34 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&array, 40);
          v7 = v33;
        }
        v8 = array;
        v3 = 0i64;
        v9 = &array[40 * v7];
        if ( v9 )
        {
          *((_QWORD *)v9 + 3) = 0i64;
          *((_DWORD *)v9 + 8) = 0;
          *((_DWORD *)v9 + 9) = 0x80000000;
          v7 = v33;
          v8 = array;
        }
        v33 = v7 + 1;
        hkDataClass::getCinfo(&result, (hkDataClass::Cinfo *)&v8[40 * v7]);
        if ( ((__int64 (__fastcall *)(hkDataClassImpl *))result.m_impl->vfptr[4].__vecDelDtor)(result.m_impl) )
        {
          v4 |= 1u;
          v10 = ((__int64 (__fastcall *)(hkDataClassImpl *))result.m_impl->vfptr[4].__vecDelDtor)(result.m_impl);
          v3 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 16i64))(v10);
        }
        if ( (v4 & 1) != 0 )
          v4 &= ~1u;
      }
      while ( v3 );
    }
    v11 = v33 - 1;
    v30 = v11;
    if ( v33 - 1 >= 0 )
    {
      v12 = 40i64 * (v33 - 1);
      v13 = 0i64;
      v31 = v12;
      do
      {
        v38 = 0i64;
        v39 = 0;
        v14 = &array[v12];
        v40 = 0x80000000;
        v35 = *(_QWORD *)&array[v12];
        LODWORD(v36) = *(_DWORD *)&array[v12 + 8];
        v37 = *(hkTypeManager::Type **)&array[v12 + 16];
        v15 = *(int *)&array[v12 + 32];
        if ( (int)v15 <= 0 )
        {
          LODWORD(result.m_impl) = 0;
        }
        else
        {
          hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v38, v15, 24);
          v13 = 0i64;
        }
        v39 = v15;
        v29 = v15;
        if ( (int)v15 > 0 )
        {
          v16 = 0i64;
          v44 = 0i64;
          do
          {
            v17 = v16 + *((_QWORD *)v14 + 3);
            v18 = &v38[v16];
            *(_QWORD *)v18 = *(_QWORD *)v17;
            *((_QWORD *)v18 + 1) = *(_QWORD *)(v17 + 8);
            *((_QWORD *)v18 + 2) = *(_QWORD *)(v17 + 16);
            v19 = (hkTypeManager *)((__int64 (__fastcall *)(hkDataWorld *, __int64))this->m_dstWorld->vfptr[5].__first_virtual_table_function__)(
                                     this->m_dstWorld,
                                     v13);
            v20 = hkTypeManager::copyType(v19, *(hkTypeManager::Type **)(v17 + 8));
            v16 = v44 + 24;
            v21 = v29-- == 1;
            *((_QWORD *)v18 + 1) = v20;
            v44 = v16;
          }
          while ( !v21 );
          v11 = v30;
        }
        v2 = this;
        ((void (__fastcall *)(hkDataWorld *, __int64 *))this->m_dstWorld->vfptr[1].__first_virtual_table_function__)(
          this->m_dstWorld,
          &v35);
        v13 = 0i64;
        v39 = 0;
        if ( v40 >= 0 )
        {
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v38,
            24 * (v40 & 0x3FFFFFFF));
          v13 = 0i64;
        }
        --v11;
        v12 = v31 - 40;
        v30 = v11;
        v31 -= 40i64;
      }
      while ( v11 >= 0 );
    }
    v22 = 0;
    v23 = ((__int64 (__fastcall *)(hkDataWorld *, const char *))v2->m_srcWorld->vfptr[4].__first_virtual_table_function__)(
            v2->m_srcWorld,
            classname);
    if ( (*(int (__fastcall **)(__int64))(*(_QWORD *)v23 + 72i64))(v23) > 0 )
    {
      do
      {
        v35 = 0i64;
        v36 = 0i64;
        v37 = 0i64;
        v38 = 0i64;
        (*(void (__fastcall **)(__int64, _QWORD, __int64 *))(*(_QWORD *)v23 + 80i64))(v23, (unsigned int)v22, &v35);
        Terminal = hkTypeManager::Type::findTerminal(v37);
        if ( Terminal->m_subType == SUB_TYPE_CLASS )
        {
          TypeName = hkTypeManager::Type::getTypeName(Terminal);
          hkDataWorldCloner::findDestClass(v2, TypeName);
        }
        ++v22;
      }
      while ( v22 < (*(int (__fastcall **)(__int64))(*(_QWORD *)v23 + 72i64))(v23) );
    }
    v26 = ((__int64 (__fastcall *)(hkDataWorld *, const char *))v2->m_dstWorld->vfptr[4].__first_virtual_table_function__)(
            v2->m_dstWorld,
            classname);
    v27 = v33 - 1;
    if ( v33 - 1 >= 0 )
    {
      v28 = &array[40 * v33 - 4];
      do
      {
        *((_DWORD *)v28 - 1) = 0;
        if ( *(int *)v28 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)(v28 - 12),
            24 * (*(_DWORD *)v28 & 0x3FFFFFFF));
        *(_DWORD *)v28 = 0x80000000;
        v28 -= 40;
        --v27;
        *(_QWORD *)(v28 + 28) = 0i64;
      }
      while ( v27 >= 0 );
    }
    v33 = 0;
    if ( v34 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        array,
        40 * (v34 & 0x3FFFFFFF));
    return (hkDataClassImpl *)v26;
  }
  return v5;
}

// File Line: 295
// RVA: 0xE63F90
void __fastcall hkDataWorldCloner::getClassMemberInfos(
        hkDataWorldCloner *this,
        hkArray<hkDataClass_MemberInfo,hkContainerTempAllocator> *dstInfos,
        hkDataClass *dstClass,
        hkDataClass *srcClass)
{
  int v8; // eax
  int v9; // ecx
  int v10; // edi
  int v11; // ecx
  int v12; // r9d
  __int64 m_size; // rax
  int v14; // ecx
  __int64 v15; // rax
  __int64 v16; // rdx
  _QWORD *v17; // rax
  hkDataClassImpl *m_impl; // rcx
  int v19; // eax
  int v20; // ebx
  int v21; // r9d
  __int64 v22; // rdx
  char *v23; // rax
  hkDataClassImpl *v24; // rcx
  int v25; // edi
  __int64 v26; // rbx
  hkTypeManager::Type *Terminal; // rax
  const char *TypeName; // rax
  char *array; // [rsp+30h] [rbp-28h] BYREF
  int v30; // [rsp+38h] [rbp-20h]
  int v31; // [rsp+3Ch] [rbp-1Ch]
  hkResult result; // [rsp+68h] [rbp+10h] BYREF

  v8 = ((__int64 (*)(void))dstClass->m_impl->vfptr[9].__vecDelDtor)();
  v9 = dstInfos->m_capacityAndFlags & 0x3FFFFFFF;
  v10 = v8;
  if ( v9 < v8 )
  {
    v11 = 2 * v9;
    v12 = v8;
    if ( v8 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&dstInfos->m_data, v12, 32);
  }
  m_size = dstInfos->m_size;
  v14 = v10 - m_size;
  v15 = 32 * m_size + 16;
  v16 = v14;
  if ( v14 > 0 )
  {
    v17 = (const char **)((char *)&dstInfos->m_data->m_name + v15);
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
  dstInfos->m_size = v10;
  dstClass->m_impl->vfptr[12].__vecDelDtor(dstClass->m_impl, (unsigned int)dstInfos);
  m_impl = srcClass->m_impl;
  array = 0i64;
  v30 = 0;
  v31 = 0x80000000;
  v19 = ((__int64 (__fastcall *)(hkDataClassImpl *))m_impl->vfptr[9].__vecDelDtor)(m_impl);
  v20 = v19;
  if ( v19 > 0 )
  {
    v21 = v19;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&array, v21, 32);
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
  v24 = srcClass->m_impl;
  v30 = v20;
  v24->vfptr[12].__vecDelDtor(v24, (unsigned int)&array);
  v25 = 0;
  if ( ((int (__fastcall *)(hkDataClassImpl *))srcClass->m_impl->vfptr[9].__vecDelDtor)(srcClass->m_impl) > 0 )
  {
    v26 = 0i64;
    do
    {
      Terminal = hkTypeManager::Type::findTerminal(*(hkTypeManager::Type **)&array[v26 + 16]);
      if ( Terminal->m_subType == SUB_TYPE_CLASS )
      {
        TypeName = hkTypeManager::Type::getTypeName(Terminal);
        hkDataWorldCloner::findDestClass(this, TypeName);
      }
      ++v25;
      v26 += 32i64;
    }
    while ( v25 < ((int (__fastcall *)(hkDataClassImpl *))srcClass->m_impl->vfptr[9].__vecDelDtor)(srcClass->m_impl) );
  }
  v30 = 0;
  if ( v31 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 32 * v31);
}

// File Line: 316
// RVA: 0xE64190
void __fastcall hkDataWorldCloner::copyObjectMembers(
        hkDataWorldCloner *this,
        hkDataObject *dstObject,
        hkDataObject *srcObject)
{
  hkDataClassImpl *v6; // rax
  hkDataObjectImpl *m_impl; // rcx
  int i; // ebx
  hkArray<hkDataClass_MemberInfo,hkContainerTempAllocator> dstInfos; // [rsp+20h] [rbp-28h] BYREF
  hkDataClass srcClass; // [rsp+58h] [rbp+10h] BYREF
  hkDataClass dstClass; // [rsp+60h] [rbp+18h] BYREF

  v6 = (hkDataClassImpl *)((__int64 (*)(void))dstObject->m_impl->vfptr[2].__vecDelDtor)();
  m_impl = srcObject->m_impl;
  dstInfos.m_data = 0i64;
  dstClass.m_impl = v6;
  dstInfos.m_size = 0;
  dstInfos.m_capacityAndFlags = 0x80000000;
  srcClass.m_impl = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataObjectImpl *))m_impl->vfptr[2].__vecDelDtor)(m_impl);
  hkDataWorldCloner::getClassMemberInfos(this, &dstInfos, &dstClass, &srcClass);
  for ( i = 0; i < dstInfos.m_size; ++i )
    hkDataWorldCloner::copyValue(this, dstObject, srcObject, &dstInfos.m_data[i]);
  dstInfos.m_size = 0;
  if ( dstInfos.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      dstInfos.m_data,
      32 * dstInfos.m_capacityAndFlags);
}

// File Line: 327
// RVA: 0xE64270
hkDataObject *__fastcall hkDataWorldCloner::copyObject(
        hkDataWorldCloner *this,
        hkDataObject *result,
        hkDataObject *srcObject)
{
  hkDataObject *v6; // rax
  __int64 v7; // rax
  const char *v8; // rax
  hkDataClassImpl *DestClass; // rax
  hkDataWorld *m_dstWorld; // rcx
  hkDataObjectImpl *v11; // rax
  hkDataObjectImpl *v12; // rbx
  hkDataObject_Handle *v13; // rax
  hkDataObject_Handle v14; // xmm6
  hkDataObjectImpl *m_impl; // rcx
  unsigned __int128 *v16; // rax
  unsigned __int128 v17; // xmm0
  int m_count; // eax
  unsigned __int128 v19; // [rsp+20h] [rbp-40h] BYREF
  hkDataObject_Handle v20; // [rsp+30h] [rbp-30h] BYREF
  hkDataObject_Handle v21; // [rsp+40h] [rbp-20h] BYREF
  hkDataClassImpl *v22; // [rsp+A0h] [rbp+40h] BYREF
  hkDataObject dstObject; // [rsp+A8h] [rbp+48h] BYREF

  if ( srcObject->m_impl )
  {
    v19 = *(_OWORD *)srcObject->m_impl->vfptr[1].__vecDelDtor(srcObject->m_impl, &v21);
    if ( hkMapBase<hkDataObject_Handle,hkDataObject_Handle,hkMapOperations<hkDataObject_Handle>>::get(
           &this->m_copied,
           (hkResult *)&v22,
           (hkDataObject_Handle *)&v19,
           &v20)->m_enum )
    {
      v7 = ((__int64 (__fastcall *)(hkDataObjectImpl *))srcObject->m_impl->vfptr[2].__vecDelDtor)(srcObject->m_impl);
      v8 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 16i64))(v7);
      DestClass = hkDataWorldCloner::findDestClass(this, v8);
      m_dstWorld = this->m_dstWorld;
      v22 = DestClass;
      v11 = (hkDataObjectImpl *)((__int64 (__fastcall *)(hkDataWorld *, hkDataClassImpl **, _QWORD))m_dstWorld->vfptr[2].__vecDelDtor)(
                                  m_dstWorld,
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
        v13 = (hkDataObject_Handle *)v11->vfptr[1].__vecDelDtor(v11, (unsigned int)&v21);
      else
        v13 = (hkDataObject_Handle *)&v19;
      v14 = *v13;
      m_impl = srcObject->m_impl;
      v19 = 0ui64;
      if ( m_impl )
        v16 = (unsigned __int128 *)m_impl->vfptr[1].__vecDelDtor(m_impl, (unsigned int)&v19);
      else
        v16 = &v19;
      v17 = *v16;
      v21 = v14;
      v19 = v17;
      hkMapBase<hkDataObject_Handle,hkDataObject_Handle,hkMapOperations<hkDataObject_Handle>>::insert(
        &this->m_copied,
        &hkContainerHeapAllocator::s_alloc,
        (hkDataObject_Handle *)&v19,
        &v21);
      hkDataWorldCloner::copyObjectMembers(this, &dstObject, srcObject);
      result->m_impl = v12;
      if ( v12 )
      {
        m_count = v12->m_count;
        v12->m_count = m_count;
        if ( !m_count )
          v12->vfptr->__vecDelDtor(v12, 1u);
      }
      return result;
    }
    else
    {
      ((void (__fastcall *)(hkDataWorld *, hkDataObject *, hkDataObject_Handle *))this->m_dstWorld->vfptr[5].__vecDelDtor)(
        this->m_dstWorld,
        result,
        &v20);
      return result;
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
  hkDataObject *v4; // rax
  hkDataObjectImpl *m_impl; // rcx
  bool v6; // zf
  __int64 v7; // rcx
  hkDataObject resulta; // [rsp+30h] [rbp+8h] BYREF
  __int64 v10; // [rsp+38h] [rbp+10h] BYREF

  v4 = (hkDataObject *)((__int64 (__fastcall *)(hkDataWorld *, __int64 *))this->m_srcWorld->vfptr[3].__first_virtual_table_function__)(
                         this->m_srcWorld,
                         &v10);
  hkDataWorldCloner::copyObject(this, &resulta, v4);
  m_impl = resulta.m_impl;
  if ( resulta.m_impl )
  {
    --resulta.m_impl->m_externalCount;
    v6 = m_impl->m_count-- == 1;
    if ( v6 )
      m_impl->vfptr->__vecDelDtor(m_impl, 1u);
  }
  v7 = v10;
  if ( v10 )
  {
    --*(_WORD *)(v10 + 10);
    v6 = (*(_DWORD *)(v7 + 12))-- == 1;
    if ( v6 )
      (**(void (__fastcall ***)(__int64, __int64))v7)(v7, 1i64);
  }
  result->m_enum = HK_SUCCESS;
  return result;
}

