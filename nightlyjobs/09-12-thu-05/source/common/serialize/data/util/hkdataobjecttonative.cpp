// File Line: 50
// RVA: 0xE60720
hkClass *__fastcall hkDataObjectToNative::findClassOf(hkDataObjectToNative *this, hkDataObject *obj)
{
  __int64 v3; // rax
  __int64 v4; // rax

  v3 = ((__int64 (__fastcall *)(hkDataObjectImpl *))obj->m_impl->vfptr[2].__vecDelDtor)(obj->m_impl);
  v4 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v3 + 16i64))(v3);
  return (hkClass *)this->m_classReg->vfptr[2].__vecDelDtor(this->m_classReg, v4);
}

// File Line: 59
// RVA: 0xE5FC90
hkVariant *__fastcall hkDataObjectToNative::allocateObject(
        hkDataObjectToNative *this,
        hkVariant *result,
        hkDataObject *obj,
        hkDataObjectToNative::CopyInfoOut *infoOut)
{
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  hkClass *v11; // rsi
  __int64 v12; // rax
  int ObjectSize; // r14d
  unsigned int v14; // r14d
  _QWORD **Value; // rax
  void *v16; // rbp
  hkDataObjectToNative::Alloc *v17; // rcx

  if ( ((__int64 (*)(void))obj->m_impl->vfptr[2].__vecDelDtor)()
    && (v8 = ((__int64 (__fastcall *)(hkDataObjectImpl *))obj->m_impl->vfptr[2].__vecDelDtor)(obj->m_impl),
        (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 16i64))(v8))
    && (v9 = ((__int64 (__fastcall *)(hkDataObjectImpl *))obj->m_impl->vfptr[2].__vecDelDtor)(obj->m_impl),
        v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 16i64))(v9),
        (v11 = (hkClass *)this->m_classReg->vfptr[2].__vecDelDtor(this->m_classReg, v10)) != 0i64) )
  {
    v12 = ((__int64 (__fastcall *)(hkDataObjectImpl *))obj->m_impl->vfptr[2].__vecDelDtor)(obj->m_impl);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v12 + 24i64))(v12);
    hkClass::getDescribedVersion(v11);
    ObjectSize = hkClass::getObjectSize(v11);
    v14 = hkDataObjectUtil::getExtraStorageSize(v11, obj) + ObjectSize;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[11] + 8i64))(Value[11], v14);
    if ( infoOut->allocs.m_size == (infoOut->allocs.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&infoOut->allocs.m_data, 16);
    v17 = &infoOut->allocs.m_data[infoOut->allocs.m_size++];
    v17->m_addr = v16;
    v17->m_size = v14;
    hkString::memSet(v16, 0, v14);
    result->m_object = v16;
    result->m_class = v11;
  }
  else
  {
    result->m_object = 0i64;
    result->m_class = 0i64;
  }
  return result;
}

// File Line: 91
// RVA: 0xE62690
_BOOL8 __fastcall canFastCopy(hkClassMember::Type type)
{
  return (unsigned int)(type - 1) <= 0x11 || type == 30;
}

// File Line: 133
// RVA: 0xE60760
hkResult *__fastcall hkDataObjectToNative::copyIntoNativeArray(
        hkDataObjectToNative *this,
        hkResult *result,
        _DWORD *address,
        hkClassMember *member,
        hkDataArray *srcArray,
        hkDataObjectToNative::CopyInfoOut *copyInfoOut)
{
  hkDataArray *v6; // r14
  int v10; // r15d
  hkResult *v11; // rax
  hkClassMember::Type m_storage; // ebx
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rdi
  int m_size; // r12d
  int v15; // esi
  int v16; // r14d
  _QWORD **v17; // rax
  void *v18; // rax
  void *v19; // r15
  int v20; // edi
  hkDataObjectToNative::CopyInfoOut *v21; // rcx
  unsigned int v22; // r13d
  hkDataArrayImpl *m_impl; // rcx
  unsigned int v24; // esi
  hkDataRefCountedVtbl *vfptr; // rax
  int m_enum; // edi
  int v27; // r13d
  int v28; // eax
  __int64 v29; // r12
  __int64 v30; // rbx
  _QWORD **Value; // rax
  __int64 v32; // rax
  int v33; // r13d
  hkDataObjectImpl *v34; // r15
  __int64 i; // rdi
  int v36; // eax
  _QWORD **v37; // rax
  __int64 v38; // rax
  __int64 j; // rdi
  char v40; // al
  _QWORD **v41; // rax
  __int64 v42; // rax
  __int64 k; // rdi
  char v44; // al
  _QWORD **v45; // rax
  __int64 v46; // rax
  __int64 m; // rdi
  char v48; // al
  __int64 v49; // rcx
  __int64 n; // rdi
  __int16 v51; // ax
  __int64 v52; // rcx
  __int64 ii; // rdi
  __int16 v54; // ax
  __int64 v55; // rcx
  __int64 jj; // rdi
  int v57; // eax
  __int64 v58; // rcx
  __int64 kk; // rdi
  int v60; // eax
  __int64 v61; // rcx
  __int64 mm; // rdi
  __int64 v63; // rax
  __int64 v64; // rcx
  __int64 nn; // rdi
  __int64 v66; // rax
  __int64 v67; // rcx
  __int64 i2; // rdi
  __int64 v69; // rax
  __int64 v70; // rcx
  __int64 i1; // rdi
  float v72; // xmm0_4
  __int64 v73; // rcx
  __int64 i3; // rdi
  float v75; // xmm0_4
  __int64 v76; // rcx
  hkDataObjectImpl *v77; // rdi
  hkDataObjectImpl *v78; // rax
  __int64 v79; // rcx
  hkDataObjectImpl *v80; // rdi
  hkDataObjectImpl *v81; // rax
  __int64 v82; // rcx
  hkDataObjectImpl *v83; // rdi
  hkDataObjectImpl *v84; // rax
  __int64 v85; // rcx
  hkDataObjectImpl *v86; // rdi
  hkDataObjectImpl *v87; // rax
  __int64 v88; // rcx
  hkDataObjectImpl *v89; // rdi
  hkDataObjectImpl *v90; // rax
  __int64 v91; // rcx
  hkDataObjectImpl *v92; // r13
  hkDataObjectImpl *v93; // rax
  __int64 v94; // rcx
  hkDataObjectImpl *v95; // r13
  hkDataObjectImpl *v96; // rax
  __int64 v97; // rax
  __int64 v98; // rbx
  hkClass *v99; // r13
  bool v100; // zf
  int v101; // ebx
  __int64 v102; // rcx
  int ObjectSize; // eax
  int v104; // eax
  hkDataArrayImpl *v105; // rcx
  hkDataRefCountedVtbl *v106; // rdx
  int v107; // ebx
  int v108; // eax
  char *v109; // rdi
  hkDataObjectImpl *v110; // rax
  hkDataObjectImpl *v111; // rbx
  _DWORD *v112; // rsi
  __int64 v113; // rcx
  hkDataObjectImpl *v114; // rax
  hkDataObjectImpl *v115; // rdi
  hkDataObjectToNative::CopyInfoOut *v116; // r15
  __int64 v117; // rax
  __int64 v118; // rbx
  hkDataObjectToNative::CopyInfoOut *v119; // rbx
  int v120; // r12d
  __int64 v121; // rcx
  __int64 v122; // rcx
  hkDataObjectImpl *v123; // rax
  hkVariant *v124; // rdi
  hkDataObjectToNative::CopyInfoOut *v125; // r15
  __int64 v126; // rax
  __int64 v127; // rbx
  __int64 v128; // rcx
  __int64 v129; // rax
  int v130; // ecx
  int v131; // edx
  hkDataArrayImpl *v132; // rax
  __int64 v133; // rcx
  __int64 v134; // rax
  int v135; // ecx
  int v136; // edx
  hkDataArrayImpl *v137; // rax
  int v138; // [rsp+40h] [rbp-59h] BYREF
  int v139; // [rsp+44h] [rbp-55h] BYREF
  hkDataObject srcObj; // [rsp+48h] [rbp-51h] BYREF
  int v141; // [rsp+50h] [rbp-49h] BYREF
  hkStridedBasicArray dst; // [rsp+58h] [rbp-41h] BYREF
  hkResult resulta; // [rsp+70h] [rbp-29h] BYREF
  hkResult v144; // [rsp+74h] [rbp-25h] BYREF
  hkResult v145; // [rsp+78h] [rbp-21h] BYREF
  hkStridedBasicArray src; // [rsp+80h] [rbp-19h] BYREF

  v6 = srcArray;
  v10 = -1;
  if ( ((unsigned int (__fastcall *)(hkDataArrayImpl *))srcArray->m_impl->vfptr[5].__vecDelDtor)(srcArray->m_impl) )
  {
    m_storage = (unsigned __int8)member->m_subtype.m_storage;
    ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties(m_storage);
    if ( ClassMemberTypeProperties->m_size <= 0
      || !canFastCopy(m_storage)
      || (((void (__fastcall *)(hkDataArrayImpl *, hkDataArray **, hkStridedBasicArray *))v6->m_impl->vfptr[8].__vecDelDtor)(
            v6->m_impl,
            &srcArray,
            &src),
          (_DWORD)srcArray) )
    {
      v22 = member->m_flags.m_storage;
      m_impl = v6->m_impl;
      v24 = 0;
      vfptr = v6->m_impl->vfptr;
      LOWORD(v22) = ~(_WORD)v22;
      m_enum = 0;
      v139 = 0;
      v27 = (v22 >> 9) & 1;
      LODWORD(srcObj.m_impl) = v27;
      v28 = ((__int64 (__fastcall *)(hkDataArrayImpl *))vfptr[5].__vecDelDtor)(m_impl);
      v29 = v28;
      v30 = v28;
      switch ( member->m_subtype.m_storage )
      {
        case 0:
          goto $LN872_0;
        case 1:
          Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v138 = v29;
          v32 = (*(__int64 (__fastcall **)(_QWORD *, int *))(*Value[11] + 24i64))(Value[11], &v138);
          v33 = 1;
          LODWORD(srcArray) = v138;
          v34 = (hkDataObjectImpl *)v32;
          if ( (int)v29 > 0 )
          {
            for ( i = 0i64; i < v29; *((_BYTE *)v34 + i - 1) = v36 != 0 )
            {
              v36 = (int)v6->m_impl->vfptr[17].__vecDelDtor(v6->m_impl, v24);
              ++i;
              ++v24;
            }
            m_enum = v139;
          }
          goto LABEL_131;
        case 2:
          v37 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v138 = v29;
          v38 = (*(__int64 (__fastcall **)(_QWORD *, int *))(*v37[11] + 24i64))(v37[11], &v138);
          v33 = 1;
          LODWORD(srcArray) = v138;
          v34 = (hkDataObjectImpl *)v38;
          if ( (int)v29 > 0 )
          {
            for ( j = 0i64; j < v29; *((_BYTE *)v34 + j - 1) = v40 )
            {
              v40 = (char)v6->m_impl->vfptr[17].__vecDelDtor(v6->m_impl, v24);
              ++j;
              ++v24;
            }
            m_enum = v139;
          }
          goto LABEL_131;
        case 3:
          v41 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v138 = v29;
          v42 = (*(__int64 (__fastcall **)(_QWORD *, int *))(*v41[11] + 24i64))(v41[11], &v138);
          v33 = 1;
          LODWORD(srcArray) = v138;
          v34 = (hkDataObjectImpl *)v42;
          if ( (int)v29 > 0 )
          {
            for ( k = 0i64; k < v29; *((_BYTE *)v34 + k - 1) = v44 )
            {
              v44 = (char)v6->m_impl->vfptr[17].__vecDelDtor(v6->m_impl, v24);
              ++k;
              ++v24;
            }
            m_enum = v139;
          }
          goto LABEL_131;
        case 4:
          v45 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v138 = v29;
          v46 = (*(__int64 (__fastcall **)(_QWORD *, int *))(*v45[11] + 24i64))(v45[11], &v138);
          v33 = 1;
          LODWORD(srcArray) = v138;
          v34 = (hkDataObjectImpl *)v46;
          if ( (int)v29 > 0 )
          {
            for ( m = 0i64; m < v29; *((_BYTE *)v34 + m - 1) = v48 )
            {
              v48 = (char)v6->m_impl->vfptr[17].__vecDelDtor(v6->m_impl, v24);
              ++m;
              ++v24;
            }
            m_enum = v139;
          }
          goto LABEL_131;
        case 5:
          v49 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v138 = 2 * v29;
          v33 = 2;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v49 + 24i64))(v49, &v138);
          LODWORD(srcArray) = v138 / 2;
          if ( (int)v29 > 0 )
          {
            for ( n = 0i64; n < v29; *((_WORD *)v34 + n - 1) = v51 )
            {
              v51 = (__int16)v6->m_impl->vfptr[17].__vecDelDtor(v6->m_impl, v24);
              ++n;
              ++v24;
            }
            m_enum = v139;
          }
          goto LABEL_131;
        case 6:
          v52 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v138 = 2 * v29;
          v33 = 2;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v52 + 24i64))(v52, &v138);
          LODWORD(srcArray) = v138 / 2;
          if ( (int)v29 > 0 )
          {
            for ( ii = 0i64; ii < v29; *((_WORD *)v34 + ii - 1) = v54 )
            {
              v54 = (__int16)v6->m_impl->vfptr[17].__vecDelDtor(v6->m_impl, v24);
              ++ii;
              ++v24;
            }
            m_enum = v139;
          }
          goto LABEL_131;
        case 7:
          v55 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v138 = 4 * v29;
          v33 = 4;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v55 + 24i64))(v55, &v138);
          LODWORD(srcArray) = v138 / 4;
          if ( (int)v29 > 0 )
          {
            for ( jj = 0i64; jj < v29; *((_DWORD *)v34 + jj - 1) = v57 )
            {
              v57 = (int)v6->m_impl->vfptr[17].__vecDelDtor(v6->m_impl, v24);
              ++jj;
              ++v24;
            }
            m_enum = v139;
          }
          goto LABEL_131;
        case 8:
          v58 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v138 = 4 * v29;
          v33 = 4;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v58 + 24i64))(v58, &v138);
          LODWORD(srcArray) = v138 / 4;
          if ( (int)v29 > 0 )
          {
            for ( kk = 0i64; kk < v29; *((_DWORD *)v34 + kk - 1) = v60 )
            {
              v60 = (int)v6->m_impl->vfptr[17].__vecDelDtor(v6->m_impl, v24);
              ++kk;
              ++v24;
            }
            m_enum = v139;
          }
          goto LABEL_131;
        case 9:
          v61 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v138 = 8 * v29;
          v33 = 8;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v61 + 24i64))(v61, &v138);
          LODWORD(srcArray) = v138 / 8;
          if ( (int)v29 > 0 )
          {
            for ( mm = 0i64; mm < v29; *((_QWORD *)v34 + mm - 1) = v63 )
            {
              v63 = (__int64)v6->m_impl->vfptr[19].__vecDelDtor(v6->m_impl, v24);
              ++mm;
              ++v24;
            }
            m_enum = v139;
          }
          goto LABEL_131;
        case 0xA:
          v64 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v138 = 8 * v29;
          v33 = 8;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v64 + 24i64))(v64, &v138);
          LODWORD(srcArray) = v138 / 8;
          if ( (int)v29 > 0 )
          {
            for ( nn = 0i64; nn < v29; *((_QWORD *)v34 + nn - 1) = v66 )
            {
              v66 = (__int64)v6->m_impl->vfptr[19].__vecDelDtor(v6->m_impl, v24);
              ++nn;
              ++v24;
            }
            m_enum = v139;
          }
          goto LABEL_131;
        case 0xB:
          v70 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v138 = 4 * v29;
          v33 = 4;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v70 + 24i64))(v70, &v138);
          LODWORD(srcArray) = v138 / 4;
          if ( (int)v29 > 0 )
          {
            for ( i1 = 0i64; i1 < v29; *((float *)v34 + i1 - 1) = v72 )
            {
              v72 = ((float (__fastcall *)(hkDataArrayImpl *, _QWORD))v6->m_impl->vfptr[15].__vecDelDtor)(
                      v6->m_impl,
                      v24);
              ++i1;
              ++v24;
            }
            m_enum = v139;
          }
          goto LABEL_131;
        case 0xC:
          v76 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v138 = 16 * v29;
          v33 = 16;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v76 + 24i64))(v76, &v138);
          LODWORD(srcArray) = v138 / 16;
          if ( (int)v29 > 0 )
          {
            v77 = v34;
            do
            {
              v78 = (hkDataObjectImpl *)v6->m_impl->vfptr[11].__vecDelDtor(v6->m_impl, v24++);
              ++v77;
              v77[-1] = *v78;
              --v30;
            }
            while ( v30 );
            m_enum = v139;
          }
          goto LABEL_131;
        case 0xD:
          v79 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v138 = 16 * v29;
          v33 = 16;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v79 + 24i64))(v79, &v138);
          LODWORD(srcArray) = v138 / 16;
          if ( (int)v29 > 0 )
          {
            v80 = v34;
            do
            {
              v81 = (hkDataObjectImpl *)v6->m_impl->vfptr[11].__vecDelDtor(v6->m_impl, v24++);
              ++v80;
              v80[-1] = *v81;
              --v30;
            }
            while ( v30 );
            m_enum = v139;
          }
          goto LABEL_131;
        case 0xE:
          v82 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v138 = 48 * v29;
          v33 = 48;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v82 + 24i64))(v82, &v138);
          LODWORD(srcArray) = v138 / 48;
          if ( (int)v29 > 0 )
          {
            v83 = v34 + 2;
            do
            {
              v84 = (hkDataObjectImpl *)v6->m_impl->vfptr[11].__vecDelDtor(v6->m_impl, v24++);
              v83 += 3;
              v83[-5] = *v84;
              v83[-4] = v84[1];
              v83[-3] = v84[2];
              --v30;
            }
            while ( v30 );
            m_enum = v139;
          }
          goto LABEL_131;
        case 0xF:
          v85 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v138 = 48 * v29;
          v33 = 48;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v85 + 24i64))(v85, &v138);
          LODWORD(srcArray) = v138 / 48;
          if ( (int)v29 > 0 )
          {
            v86 = v34 + 2;
            do
            {
              v87 = (hkDataObjectImpl *)v6->m_impl->vfptr[11].__vecDelDtor(v6->m_impl, v24++);
              v86 += 3;
              v86[-5] = *v87;
              v86[-4] = v87[1];
              v86[-3] = v87[2];
              --v30;
            }
            while ( v30 );
            m_enum = v139;
          }
          goto LABEL_131;
        case 0x10:
          v88 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v138 = 48 * v29;
          v33 = 48;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v88 + 24i64))(v88, &v138);
          LODWORD(srcArray) = v138 / 48;
          if ( (int)v29 > 0 )
          {
            v89 = v34 + 2;
            do
            {
              v90 = (hkDataObjectImpl *)v6->m_impl->vfptr[11].__vecDelDtor(v6->m_impl, v24++);
              v89 += 3;
              v89[-5] = *v90;
              v89[-4] = v90[1];
              v89[-3] = v90[2];
              --v30;
            }
            while ( v30 );
            m_enum = v139;
          }
          goto LABEL_131;
        case 0x11:
          v91 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v138 = (_DWORD)v29 << 6;
          v33 = 64;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v91 + 24i64))(v91, &v138);
          LODWORD(srcArray) = v138 / 64;
          if ( (int)v29 > 0 )
          {
            v92 = v34 + 2;
            do
            {
              v93 = (hkDataObjectImpl *)v6->m_impl->vfptr[11].__vecDelDtor(v6->m_impl, v24++);
              v92 += 4;
              v92[-6] = *v93;
              v92[-5] = v93[1];
              v92[-4] = v93[2];
              v92[-3] = v93[3];
              --v30;
            }
            while ( v30 );
            v33 = 64;
          }
          goto LABEL_131;
        case 0x12:
          v94 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v139 = (_DWORD)v29 << 6;
          v33 = 64;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v94 + 24i64))(v94, &v139);
          v138 = 64;
          LODWORD(srcArray) = v139 / 64;
          if ( (int)v29 <= 0 )
            goto LABEL_131;
          v95 = v34 + 2;
          do
          {
            v96 = (hkDataObjectImpl *)v6->m_impl->vfptr[11].__vecDelDtor(v6->m_impl, v24++);
            v95 += 4;
            v95[-6] = *v96;
            v95[-5] = v96[1];
            v95[-4] = v96[2];
            v95[-3] = v96[3];
            --v30;
          }
          while ( v30 );
          goto LABEL_130;
        case 0x14:
          v113 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v141 = 8 * v29;
          v114 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v113 + 24i64))(v113, &v141);
          v138 = 8;
          v34 = v114;
          srcObj.m_impl = v114;
          LODWORD(srcArray) = v141 / 8;
          hkString::memSet(v114, 0, 8 * v29);
          if ( (int)v29 <= 0 )
            goto LABEL_130;
          v115 = v34;
          v116 = copyInfoOut;
          do
          {
            v117 = (__int64)v6->m_impl->vfptr[21].__vecDelDtor(v6->m_impl, v24);
            v118 = v117;
            *(_QWORD *)&dst.m_type = v117;
            if ( v117 )
            {
              ++*(_WORD *)(v117 + 10);
              ++*(_DWORD *)(v117 + 12);
            }
            hkDataObjectToNative::CopyInfoOut::addPointer(v116, (hkDataObject *)&dst, v115, v27);
            if ( v118 )
            {
              --*(_WORD *)(v118 + 10);
              v100 = (*(_DWORD *)(v118 + 12))-- == 1;
              if ( v100 )
                (**(void (__fastcall ***)(__int64, __int64))v118)(v118, 1i64);
            }
            ++v24;
            v115 = (hkDataObjectImpl *)((char *)v115 + 8);
          }
          while ( (int)v24 < (int)v29 );
          goto LABEL_129;
        case 0x19:
          v97 = (__int64)v6->m_impl->vfptr[21].__vecDelDtor(v6->m_impl, 0i64);
          v98 = v97;
          srcArray = (hkDataArray *)v97;
          if ( v97 )
          {
            ++*(_WORD *)(v97 + 10);
            ++*(_DWORD *)(v97 + 12);
          }
          v99 = hkDataObjectToNative::getMemberClassAndCheck(this, member, (hkDataObject *)&srcArray);
          if ( v98 )
          {
            --*(_WORD *)(v98 + 10);
            v100 = (*(_DWORD *)(v98 + 12))-- == 1;
            if ( v100 )
              (**(void (__fastcall ***)(__int64, __int64))v98)(v98, 1i64);
          }
          if ( !v99 )
            goto $LN872_0;
          v101 = v29 * hkClass::getObjectSize(v99);
          v102 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v139 = v101;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v102 + 24i64))(v102, &v139);
          ObjectSize = hkClass::getObjectSize(v99);
          LODWORD(srcArray) = v139 / ObjectSize;
          v104 = hkClass::getObjectSize(v99);
          v105 = v6->m_impl;
          v106 = v6->m_impl->vfptr;
          v138 = v104;
          v107 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v106[5].__vecDelDtor)(v105);
          v108 = hkClass::getObjectSize(v99);
          hkString::memSet(v34, 0, v107 * v108);
          if ( (int)v29 > 0 )
          {
            do
            {
              if ( m_enum )
                break;
              v109 = (char *)v34 + (int)(v24 * hkClass::getObjectSize(v99));
              v110 = (hkDataObjectImpl *)v6->m_impl->vfptr[21].__vecDelDtor(v6->m_impl, v24);
              v111 = v110;
              srcObj.m_impl = v110;
              if ( v110 )
              {
                ++v110->m_externalCount;
                ++v110->m_count;
              }
              m_enum = hkDataObjectToNative::fillNativeMembers(this, &resulta, v109, &srcObj, copyInfoOut)->m_enum;
              if ( v111 )
              {
                --v111->m_externalCount;
                v100 = v111->m_count-- == 1;
                if ( v100 )
                  v111->vfptr->__vecDelDtor(v111, 1u);
              }
              ++v24;
            }
            while ( (int)v24 < (int)v29 );
          }
          v33 = v138;
          if ( v138 > 0 )
            goto LABEL_131;
          v10 = (int)srcArray;
$LN872_0:
          v112 = address;
          break;
        case 0x1C:
          v122 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v141 = 16 * v29;
          v123 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v122 + 24i64))(v122, &v141);
          v138 = 16;
          v34 = v123;
          srcObj.m_impl = v123;
          LODWORD(srcArray) = v141 / 16;
          hkString::memSet(v123, 0, 16 * v29);
          if ( (int)v29 <= 0 )
            goto LABEL_130;
          v124 = (hkVariant *)v34;
          v125 = copyInfoOut;
          do
          {
            v126 = (__int64)v6->m_impl->vfptr[21].__vecDelDtor(v6->m_impl, v24);
            v127 = v126;
            *(_QWORD *)&dst.m_type = v126;
            if ( v126 )
            {
              ++*(_WORD *)(v126 + 10);
              ++*(_DWORD *)(v126 + 12);
            }
            hkDataObjectToNative::CopyInfoOut::addVariant(v125, (hkDataObject *)&dst, v124, v27);
            if ( v127 )
            {
              --*(_WORD *)(v127 + 10);
              v100 = (*(_DWORD *)(v127 + 12))-- == 1;
              if ( v100 )
                (**(void (__fastcall ***)(__int64, __int64))v127)(v127, 1i64);
            }
            ++v24;
            ++v124;
          }
          while ( (int)v24 < (int)v29 );
LABEL_129:
          m_enum = v139;
          v34 = srcObj.m_impl;
LABEL_130:
          v33 = v138;
LABEL_131:
          v112 = address;
          v119 = copyInfoOut;
          address[2] = v29;
          *(_QWORD *)address = v34;
          v120 = v33 * v29;
          if ( v119->allocs.m_size == (v119->allocs.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&v119->allocs.m_data, 16);
          v121 = (__int64)&v119->allocs.m_data[v119->allocs.m_size++];
          *(_QWORD *)v121 = v34;
          v10 = (int)srcArray;
          *(_DWORD *)(v121 + 8) = v120;
          break;
        case 0x1D:
          v128 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v141 = 8 * v29;
          v129 = (*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v128 + 24i64))(v128, &v141);
          v130 = 0;
          v33 = 8;
          v34 = (hkDataObjectImpl *)v129;
          v138 = 0;
          LODWORD(srcArray) = v141 / 8;
          if ( (int)v29 > 0 )
          {
            v131 = 0;
            v139 = 0;
            do
            {
              if ( m_enum )
                break;
              v132 = v6->m_impl;
              LODWORD(dst.m_data) = v130;
              *(_QWORD *)&dst.m_type = v132;
              m_enum = hkDataObjectToNative::fillNativeSimpleMember<hkDataArray_Value>(
                         this,
                         &v144,
                         (char *)v34 + v131,
                         (hkClassMember::Type)(unsigned __int8)member->m_subtype.m_storage,
                         (hkDataArray_Value *)&dst,
                         0i64,
                         (unsigned int)srcObj.m_impl,
                         copyInfoOut)->m_enum;
              v130 = v138 + 1;
              v131 = v139 + 8;
              v138 = v130;
              v139 += 8;
            }
            while ( v130 < (int)v29 );
          }
          goto LABEL_131;
        case 0x1E:
          v67 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v138 = 8 * v29;
          v33 = 8;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v67 + 24i64))(v67, &v138);
          LODWORD(srcArray) = v138 / 8;
          if ( (int)v29 > 0 )
          {
            for ( i2 = 0i64; i2 < v29; *((_QWORD *)v34 + i2 - 1) = v69 )
            {
              v69 = (__int64)v6->m_impl->vfptr[19].__vecDelDtor(v6->m_impl, v24);
              ++i2;
              ++v24;
            }
            m_enum = v139;
          }
          goto LABEL_131;
        case 0x20:
          v73 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v138 = 2 * v29;
          v33 = 2;
          v34 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v73 + 24i64))(v73, &v138);
          LODWORD(srcArray) = v138 / 2;
          if ( (int)v29 > 0 )
          {
            for ( i3 = 0i64; i3 < v29; *((_WORD *)v34 + i3 - 1) = HIWORD(v75) )
            {
              v75 = ((float (__fastcall *)(hkDataArrayImpl *, _QWORD))v6->m_impl->vfptr[15].__vecDelDtor)(
                      v6->m_impl,
                      v24);
              ++i3;
              ++v24;
              *(float *)&srcObj.m_impl = v75;
            }
            m_enum = v139;
          }
          goto LABEL_131;
        case 0x21:
          v133 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v141 = 8 * v29;
          v134 = (*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v133 + 24i64))(v133, &v141);
          v135 = 0;
          v33 = 8;
          v34 = (hkDataObjectImpl *)v134;
          v138 = 0;
          LODWORD(srcArray) = v141 / 8;
          if ( (int)v29 > 0 )
          {
            v136 = 0;
            v139 = 0;
            do
            {
              if ( m_enum )
                break;
              v137 = v6->m_impl;
              LODWORD(dst.m_data) = v135;
              *(_QWORD *)&dst.m_type = v137;
              m_enum = hkDataObjectToNative::fillNativeSimpleMember<hkDataArray_Value>(
                         this,
                         &v145,
                         (char *)v34 + v136,
                         (hkClassMember::Type)(unsigned __int8)member->m_subtype.m_storage,
                         (hkDataArray_Value *)&dst,
                         0i64,
                         (unsigned int)srcObj.m_impl,
                         copyInfoOut)->m_enum;
              v135 = v138 + 1;
              v136 = v139 + 8;
              v138 = v135;
              v139 += 8;
            }
            while ( v135 < (int)v29 );
          }
          goto LABEL_131;
        default:
          v11 = result;
          result->m_enum = HK_FAILURE;
          return v11;
      }
      if ( member->m_type.m_storage == 22 )
      {
        if ( !this->m_allocatedOnHeap )
          v10 |= 0x80000000;
        v112[3] = v10;
      }
      v11 = result;
      result->m_enum = m_enum;
    }
    else
    {
      m_size = src.m_size;
      v15 = ClassMemberTypeProperties->m_size;
      v16 = v15 * src.m_size;
      LODWORD(srcArray) = v15 * src.m_size;
      v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v18 = (void *)(*(__int64 (__fastcall **)(_QWORD *, hkDataArray **))(*v17[11] + 24i64))(v17[11], &srcArray);
      dst.m_type = m_storage;
      v19 = v18;
      dst.m_size = src.m_size;
      dst.m_stride = v15;
      dst.m_tupleSize = 1;
      dst.m_data = v18;
      v20 = (int)srcArray / v15;
      switch ( m_storage )
      {
        case 12:
        case 13:
          dst.m_tupleSize = 4;
          goto LABEL_10;
        case 14:
        case 15:
        case 16:
          dst.m_tupleSize = 12;
          goto LABEL_10;
        case 17:
        case 18:
          dst.m_tupleSize = 16;
LABEL_10:
          dst.m_type = TYPE_NULL_CONTACT_MGR|0x8;
          break;
        default:
          break;
      }
      hkVariantDataUtil::convertArray(&src, &dst);
      if ( v15 > 0 )
      {
        v21 = copyInfoOut;
        *(_QWORD *)address = v19;
        address[2] = m_size;
        hkDataObjectToNative::CopyInfoOut::addAlloc(v21, v19, v16);
      }
      if ( member->m_type.m_storage == 22 )
      {
        if ( !this->m_allocatedOnHeap )
          v20 |= 0x80000000;
        address[3] = v20;
      }
      v11 = result;
      result->m_enum = HK_SUCCESS;
    }
  }
  else
  {
    v11 = result;
    result->m_enum = HK_SUCCESS;
  }
  return v11;
}

// File Line: 452
// RVA: 0xE617F0
hkResult *__fastcall hkDataObjectToNative::copyIntoRelArray(
        hkDataObjectToNative *this,
        hkResult *result,
        unsigned __int16 *address,
        hkClassMember *member,
        hkDataArray *srcArray,
        hkDataObjectToNative::CopyInfoOut *copyInfoOut,
        void **relArrayAddress)
{
  hkDataArray *v7; // r14
  int v8; // esi
  hkDataArrayImpl *m_impl; // rcx
  hkDataRefCountedVtbl *vfptr; // rax
  hkResult *v14; // rax
  unsigned int m_storage; // r12d
  hkResultEnum m_enum; // edi
  int owningReference; // r12d
  void **v18; // r15
  int v19; // ebp
  unsigned __int16 v20; // r12
  __int64 v21; // rbx
  int v22; // eax
  __int64 v23; // rbx
  char v24; // al
  __int64 v25; // rbx
  char v26; // al
  __int64 v27; // rbx
  char v28; // al
  __int64 v29; // rbx
  __int16 v30; // ax
  __int64 v31; // rbx
  __int16 v32; // ax
  __int64 v33; // rbx
  int v34; // eax
  __int64 v35; // rbx
  int v36; // eax
  __int64 v37; // rbx
  __int64 v38; // rax
  __int64 v39; // rbx
  __int64 v40; // rax
  __int64 v41; // rbx
  __int64 v42; // rax
  __int64 v43; // rbx
  float v44; // xmm0_4
  hkDataArrayImpl *v45; // rcx
  __int64 v46; // rbx
  float v47; // xmm0_4
  char *v48; // rax
  __int64 v49; // rbx
  _OWORD *v50; // rax
  __int64 v51; // rbx
  _OWORD *v52; // rax
  __int64 v53; // rbx
  _OWORD *v54; // rax
  char *v55; // rcx
  __int64 v56; // rbx
  _OWORD *v57; // rax
  char *v58; // rcx
  __int64 v59; // rbx
  _OWORD *v60; // rax
  char *v61; // rcx
  __int64 v62; // rbx
  _OWORD *v63; // rax
  char *v64; // rcx
  __int64 v65; // rbx
  _OWORD *v66; // rax
  char *v67; // rcx
  __int64 v68; // rax
  __int64 v69; // rbx
  hkClass *v70; // r13
  bool v71; // zf
  int ObjectSize; // eax
  hkDataArrayImpl *v73; // rcx
  hkDataRefCountedVtbl *v74; // rdx
  int v75; // ebx
  int v76; // eax
  hkDataObjectToNative::CopyInfoOut *v77; // rbp
  char *v78; // rbx
  hkDataObjectImpl *v79; // rax
  hkResult *v80; // rax
  hkDataObjectImpl *v81; // rcx
  int v82; // eax
  void *v83; // rcx
  hkDataObjectToNative::CopyInfoOut *v84; // r13
  hkDataObjectImpl *v85; // rax
  hkDataObjectImpl *v86; // rbx
  int v87; // eax
  void *v88; // rcx
  hkDataObjectToNative::CopyInfoOut *v89; // r13
  hkDataObjectImpl *v90; // rax
  hkDataObjectImpl *v91; // rbx
  __int16 v92; // ax
  hkDataArrayImpl *v93; // rcx
  int v94; // ebx
  int v95; // ecx
  hkClassMember::Type v96; // r9d
  char *v97; // r8
  hkResult *v98; // rax
  hkDataArrayImpl *v99; // rcx
  int v100; // eax
  __int16 v101; // ax
  hkDataArrayImpl *v102; // rcx
  hkDataRefCountedVtbl *v103; // rax
  int v104; // ebx
  int v105; // ebp
  hkClassMember::Type v106; // r9d
  char *v107; // r8
  hkDataObject obj; // [rsp+5Ah] [rbp-68h] BYREF
  hkResult resulta; // [rsp+62h] [rbp-60h] BYREF
  hkResult v110; // [rsp+66h] [rbp-5Ch] BYREF
  hkResult v111; // [rsp+6Ah] [rbp-58h] BYREF
  hkDataObject srcObj; // [rsp+72h] [rbp-50h] BYREF
  hkDataArray_Value value; // [rsp+7Ah] [rbp-48h] BYREF

  v7 = srcArray;
  v8 = 0;
  m_impl = srcArray->m_impl;
  vfptr = srcArray->m_impl->vfptr;
  LODWORD(obj.m_impl) = 0;
  if ( ((unsigned int (__fastcall *)(hkDataArrayImpl *))vfptr[5].__vecDelDtor)(m_impl) )
  {
    m_storage = member->m_flags.m_storage;
    m_enum = HK_SUCCESS;
    LOWORD(m_storage) = ~(_WORD)m_storage;
    owningReference = (m_storage >> 9) & 1;
    v18 = relArrayAddress;
    switch ( member->m_subtype.m_storage )
    {
      case 0:
        goto $LN1_70;
      case 1:
        v19 = 1;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        v21 = 0i64;
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          do
          {
            v22 = (int)v7->m_impl->vfptr[17].__vecDelDtor(v7->m_impl, (unsigned int)v8);
            ++v21;
            ++v8;
            *((char *)*v18 + v21 - 1) = v22 != 0;
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 2:
        v19 = 1;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        v23 = 0i64;
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          do
          {
            v24 = (char)v7->m_impl->vfptr[17].__vecDelDtor(v7->m_impl, (unsigned int)v8++);
            *((_BYTE *)*v18 + v23++) = v24;
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 3:
        v19 = 1;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        v25 = 0i64;
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          do
          {
            v26 = (char)v7->m_impl->vfptr[17].__vecDelDtor(v7->m_impl, (unsigned int)v8++);
            *((_BYTE *)*v18 + v25++) = v26;
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 4:
        v19 = 1;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        v27 = 0i64;
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          do
          {
            v28 = (char)v7->m_impl->vfptr[17].__vecDelDtor(v7->m_impl, (unsigned int)v8++);
            *((_BYTE *)*v18 + v27++) = v28;
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 5:
        v19 = 2;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v29 = 0i64;
          do
          {
            v30 = (__int16)v7->m_impl->vfptr[17].__vecDelDtor(v7->m_impl, (unsigned int)v8++);
            *(_WORD *)((char *)*v18 + v29) = v30;
            v29 += 2i64;
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 6:
        v19 = 2;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v31 = 0i64;
          do
          {
            v32 = (__int16)v7->m_impl->vfptr[17].__vecDelDtor(v7->m_impl, (unsigned int)v8++);
            *(_WORD *)((char *)*v18 + v31) = v32;
            v31 += 2i64;
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 7:
        v19 = 4;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v33 = 0i64;
          do
          {
            v34 = (int)v7->m_impl->vfptr[17].__vecDelDtor(v7->m_impl, (unsigned int)v8++);
            *(_DWORD *)((char *)*v18 + v33) = v34;
            v33 += 4i64;
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 8:
        v19 = 4;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v35 = 0i64;
          do
          {
            v36 = (int)v7->m_impl->vfptr[17].__vecDelDtor(v7->m_impl, (unsigned int)v8++);
            *(_DWORD *)((char *)*v18 + v35) = v36;
            v35 += 4i64;
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 9:
        v19 = 8;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v37 = 0i64;
          do
          {
            v38 = (__int64)v7->m_impl->vfptr[19].__vecDelDtor(v7->m_impl, (unsigned int)v8++);
            *(_QWORD *)((char *)*v18 + v37) = v38;
            v37 += 8i64;
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 0xA:
        v19 = 8;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v39 = 0i64;
          do
          {
            v40 = (__int64)v7->m_impl->vfptr[19].__vecDelDtor(v7->m_impl, (unsigned int)v8++);
            *(_QWORD *)((char *)*v18 + v39) = v40;
            v39 += 8i64;
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 0xB:
        v19 = 4;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v43 = 0i64;
          do
          {
            v44 = ((float (__fastcall *)(hkDataArrayImpl *, _QWORD))v7->m_impl->vfptr[15].__vecDelDtor)(
                    v7->m_impl,
                    (unsigned int)v8);
            v45 = v7->m_impl;
            *(float *)((char *)*v18 + v43) = v44;
            ++v8;
            v43 += 4i64;
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v45->vfptr[5].__vecDelDtor)(v45) );
        }
        goto LABEL_127;
      case 0xC:
        v19 = 16;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v49 = 0i64;
          do
          {
            v50 = v7->m_impl->vfptr[11].__vecDelDtor(v7->m_impl, (unsigned int)v8++);
            v49 += 16i64;
            *(_OWORD *)((char *)*v18 + v49 - 16) = *v50;
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 0xD:
        v19 = 16;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v51 = 0i64;
          do
          {
            v52 = v7->m_impl->vfptr[11].__vecDelDtor(v7->m_impl, (unsigned int)v8++);
            v51 += 16i64;
            *(_OWORD *)((char *)*v18 + v51 - 16) = *v52;
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 0xE:
        v19 = 48;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v53 = 0i64;
          do
          {
            v54 = v7->m_impl->vfptr[11].__vecDelDtor(v7->m_impl, (unsigned int)v8);
            v55 = (char *)*v18;
            ++v8;
            v53 += 48i64;
            *(_OWORD *)&v55[v53 - 48] = *v54;
            *(_OWORD *)&v55[v53 - 32] = v54[1];
            *(_OWORD *)&v55[v53 - 16] = v54[2];
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 0xF:
        v19 = 48;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v56 = 0i64;
          do
          {
            v57 = v7->m_impl->vfptr[11].__vecDelDtor(v7->m_impl, (unsigned int)v8);
            v58 = (char *)*v18;
            ++v8;
            v56 += 48i64;
            *(_OWORD *)&v58[v56 - 48] = *v57;
            *(_OWORD *)&v58[v56 - 32] = v57[1];
            *(_OWORD *)&v58[v56 - 16] = v57[2];
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 0x10:
        v19 = 48;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v59 = 0i64;
          do
          {
            v60 = v7->m_impl->vfptr[11].__vecDelDtor(v7->m_impl, (unsigned int)v8);
            v61 = (char *)*v18;
            ++v8;
            v59 += 48i64;
            *(_OWORD *)&v61[v59 - 48] = *v60;
            *(_OWORD *)&v61[v59 - 32] = v60[1];
            *(_OWORD *)&v61[v59 - 16] = v60[2];
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 0x11:
        v19 = 64;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v62 = 0i64;
          do
          {
            v63 = v7->m_impl->vfptr[11].__vecDelDtor(v7->m_impl, (unsigned int)v8);
            v64 = (char *)*v18;
            ++v8;
            v62 += 64i64;
            *(_OWORD *)&v64[v62 - 64] = *v63;
            *(_OWORD *)&v64[v62 - 48] = v63[1];
            *(_OWORD *)&v64[v62 - 32] = v63[2];
            *(_OWORD *)&v64[v62 - 16] = v63[3];
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 0x12:
        v19 = 64;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v65 = 0i64;
          do
          {
            v66 = v7->m_impl->vfptr[11].__vecDelDtor(v7->m_impl, (unsigned int)v8);
            v67 = (char *)*v18;
            ++v8;
            v65 += 64i64;
            *(_OWORD *)&v67[v65 - 64] = *v66;
            *(_OWORD *)&v67[v65 - 48] = v66[1];
            *(_OWORD *)&v67[v65 - 32] = v66[2];
            *(_OWORD *)&v67[v65 - 16] = v66[3];
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 0x14:
        v82 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        v83 = *v18;
        LODWORD(srcArray) = v82;
        v19 = 8;
        hkString::memSet(v83, 0, 8 * (unsigned __int16)v82);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v84 = copyInfoOut;
          do
          {
            v85 = (hkDataObjectImpl *)v7->m_impl->vfptr[21].__vecDelDtor(v7->m_impl, (unsigned int)v8);
            v86 = v85;
            obj.m_impl = v85;
            if ( v85 )
            {
              ++v85->m_externalCount;
              ++v85->m_count;
            }
            hkDataObjectToNative::CopyInfoOut::addPointer(v84, &obj, (char *)*v18 + 8 * v8, owningReference);
            if ( v86 )
            {
              --v86->m_externalCount;
              v71 = v86->m_count-- == 1;
              if ( v71 )
                v86->vfptr->__vecDelDtor(v86, 1u);
            }
            ++v8;
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_126;
      case 0x19:
        v68 = (__int64)v7->m_impl->vfptr[21].__vecDelDtor(v7->m_impl, 0i64);
        v69 = v68;
        srcArray = (hkDataArray *)v68;
        if ( v68 )
        {
          ++*(_WORD *)(v68 + 10);
          ++*(_DWORD *)(v68 + 12);
        }
        v70 = hkDataObjectToNative::getMemberClassAndCheck(this, member, (hkDataObject *)&srcArray);
        if ( v69 )
        {
          --*(_WORD *)(v69 + 10);
          v71 = (*(_DWORD *)(v69 + 12))-- == 1;
          if ( v71 )
            (**(void (__fastcall ***)(__int64, __int64))v69)(v69, 1i64);
        }
        if ( v70 )
        {
          LOWORD(srcArray) = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
          ObjectSize = hkClass::getObjectSize(v70);
          v73 = v7->m_impl;
          v74 = v7->m_impl->vfptr;
          v19 = ObjectSize;
          LODWORD(obj.m_impl) = ObjectSize;
          v75 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v74[5].__vecDelDtor)(v73);
          v76 = hkClass::getObjectSize(v70);
          hkString::memSet(*v18, 0, v75 * v76);
          if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
          {
            v77 = copyInfoOut;
            do
            {
              if ( m_enum )
                break;
              v78 = (char *)*v18 + (int)(v8 * hkClass::getObjectSize(v70));
              v79 = (hkDataObjectImpl *)v7->m_impl->vfptr[21].__vecDelDtor(v7->m_impl, (unsigned int)v8);
              srcObj.m_impl = v79;
              if ( v79 )
              {
                ++v79->m_externalCount;
                ++v79->m_count;
              }
              v80 = hkDataObjectToNative::fillNativeMembers(this, &resulta, v78, &srcObj, v77);
              v81 = srcObj.m_impl;
              m_enum = v80->m_enum;
              if ( srcObj.m_impl )
              {
                --srcObj.m_impl->m_externalCount;
                v71 = v81->m_count-- == 1;
                if ( v71 )
                  v81->vfptr->__vecDelDtor(v81, 1u);
              }
              ++v8;
            }
            while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
            v19 = (int)obj.m_impl;
          }
          if ( v19 > 0 )
            goto LABEL_126;
        }
        goto $LN1_70;
      case 0x1C:
        v87 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        v88 = *v18;
        LODWORD(srcArray) = v87;
        v19 = 16;
        hkString::memSet(v88, 0, 16 * (unsigned __int16)v87);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v89 = copyInfoOut;
          do
          {
            v90 = (hkDataObjectImpl *)v7->m_impl->vfptr[21].__vecDelDtor(v7->m_impl, (unsigned int)v8);
            v91 = v90;
            obj.m_impl = v90;
            if ( v90 )
            {
              ++v90->m_externalCount;
              ++v90->m_count;
            }
            hkDataObjectToNative::CopyInfoOut::addVariant(v89, &obj, (hkVariant *)*v18 + v8, owningReference);
            if ( v91 )
            {
              --v91->m_externalCount;
              v71 = v91->m_count-- == 1;
              if ( v71 )
                v91->vfptr->__vecDelDtor(v91, 1u);
            }
            ++v8;
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_126;
      case 0x1D:
        v92 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        v93 = v7->m_impl;
        v19 = 8;
        LOWORD(srcArray) = v92;
        v94 = 0;
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v93->vfptr[5].__vecDelDtor)(v93) > 0 )
        {
          v95 = 0;
          LODWORD(obj.m_impl) = 0;
          do
          {
            if ( m_enum )
              break;
            v96 = (unsigned __int8)member->m_subtype.m_storage;
            v97 = (char *)*v18 + v95;
            value.m_impl = v7->m_impl;
            value.m_index = v94;
            v98 = hkDataObjectToNative::fillNativeSimpleMember<hkDataArray_Value>(
                    this,
                    &v110,
                    v97,
                    v96,
                    &value,
                    0i64,
                    owningReference,
                    copyInfoOut);
            v99 = v7->m_impl;
            m_enum = v98->m_enum;
            LODWORD(obj.m_impl) += 8;
            ++v94;
            v100 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v99->vfptr[5].__vecDelDtor)(v99);
            v95 = (int)obj.m_impl;
          }
          while ( v94 < v100 );
        }
        goto LABEL_126;
      case 0x1E:
        v19 = 8;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v41 = 0i64;
          do
          {
            v42 = (__int64)v7->m_impl->vfptr[19].__vecDelDtor(v7->m_impl, (unsigned int)v8++);
            *(_QWORD *)((char *)*v18 + v41) = v42;
            v41 += 8i64;
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 0x20:
        v19 = 2;
        v20 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) > 0 )
        {
          v46 = 0i64;
          do
          {
            v47 = ((float (__fastcall *)(hkDataArrayImpl *, _QWORD))v7->m_impl->vfptr[15].__vecDelDtor)(
                    v7->m_impl,
                    (unsigned int)v8);
            v48 = (char *)*v18;
            ++v8;
            v46 += 2i64;
            *(float *)&srcArray = v47;
            *(_WORD *)&v48[v46 - 2] = HIWORD(v47);
          }
          while ( v8 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
        }
        goto LABEL_127;
      case 0x21:
        v101 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl);
        v102 = v7->m_impl;
        v19 = 8;
        LOWORD(srcArray) = v101;
        v103 = v102->vfptr;
        LODWORD(obj.m_impl) = 8;
        v104 = 0;
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v103[5].__vecDelDtor)(v102) > 0 )
        {
          v105 = 0;
          do
          {
            if ( m_enum )
              break;
            v106 = (unsigned __int8)member->m_subtype.m_storage;
            value.m_impl = v7->m_impl;
            v107 = (char *)*v18 + v105;
            value.m_index = v104;
            m_enum = hkDataObjectToNative::fillNativeSimpleMember<hkDataArray_Value>(
                       this,
                       &v111,
                       v107,
                       v106,
                       &value,
                       0i64,
                       owningReference,
                       copyInfoOut)->m_enum;
            ++v104;
            v105 += 8;
          }
          while ( v104 < ((int (__fastcall *)(hkDataArrayImpl *))v7->m_impl->vfptr[5].__vecDelDtor)(v7->m_impl) );
          v19 = (int)obj.m_impl;
        }
LABEL_126:
        v20 = (unsigned __int16)srcArray;
LABEL_127:
        address[1] = *(_WORD *)v18 - (_WORD)address;
        *v18 = (char *)*v18 + ((v19 * v20 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
        *address = v20;
$LN1_70:
        v14 = result;
        result->m_enum = m_enum;
        break;
      default:
        result->m_enum = HK_FAILURE;
        v14 = result;
        break;
    }
  }
  else
  {
    result->m_enum = HK_SUCCESS;
    *(_DWORD *)address = 0;
    return result;
  }
  return v14;
}

// File Line: 655
// RVA: 0xE62500
hkResult *__fastcall hkDataObjectToNative::fillNativeEnumMember(
        hkDataObjectToNative *this,
        hkResult *result,
        void *address,
        hkClassMember *member,
        hkDataObject_Value *value)
{
  int m_storage; // eax
  int v10; // eax

  m_storage = (unsigned __int8)member->m_type.m_storage;
  if ( m_storage == 24 || m_storage == 31 )
  {
    if ( member->m_enum )
    {
      v10 = (int)value->m_impl->vfptr[12].__vecDelDtor(value->m_impl, value->m_handle);
      hkClassMember::setEnumValue(member, address, v10);
    }
    result->m_enum = HK_SUCCESS;
    return result;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
}

// File Line: 695
// RVA: 0xE62B30
hkResult *__fastcall hkDataObjectToNative::fillNativeSimpleMember<hkDataObject_Value>(
        hkDataObjectToNative *this,
        hkResult *result,
        hkVariant *address,
        hkClassMember::Type mtype,
        hkDataObject_Value *value,
        hkClass *structClass,
        unsigned int owningReference,
        hkDataObjectToNative::CopyInfoOut *copyInfoOut)
{
  int v11; // eax
  char v12; // al
  __int16 v13; // ax
  int v14; // eax
  void *v15; // rax
  float v16; // xmm0_4
  hkResultEnum v17; // xmm0_4
  hkDataObjectImpl *v18; // rax
  hkDataObjectImpl *v19; // rbx
  hkDataObjectImpl *v20; // rax
  hkResult *v21; // rax
  hkDataObjectImpl *m_impl; // rcx
  bool v23; // bl
  bool v24; // zf
  hkVariant *v25; // rax
  hkVariant *v26; // rax
  hkVariant *v27; // rax
  hkDataObject_Value *v28; // rbx
  char *v29; // rax
  char *v30; // rax
  char *v31; // rbx
  hkDataObject_Value *v32; // rbx
  char *v33; // rax
  hkDataObjectImpl *v34; // rax
  hkDataObject srcObj; // [rsp+30h] [rbp-18h] BYREF
  hkDataObject obj; // [rsp+38h] [rbp-10h] BYREF
  hkResult resulta; // [rsp+68h] [rbp+20h] BYREF

  switch ( mtype )
  {
    case 1:
      v11 = (int)value->m_impl->vfptr[12].__vecDelDtor(value->m_impl, value->m_handle);
      result->m_enum = HK_SUCCESS;
      LOBYTE(address->m_object) = v11 != 0;
      return result;
    case 2:
    case 3:
    case 4:
      v12 = (char)value->m_impl->vfptr[12].__vecDelDtor(value->m_impl, value->m_handle);
      result->m_enum = HK_SUCCESS;
      LOBYTE(address->m_object) = v12;
      return result;
    case 5:
    case 6:
      v13 = (__int16)value->m_impl->vfptr[12].__vecDelDtor(value->m_impl, value->m_handle);
      result->m_enum = HK_SUCCESS;
      LOWORD(address->m_object) = v13;
      return result;
    case 7:
    case 8:
      v14 = (int)value->m_impl->vfptr[12].__vecDelDtor(value->m_impl, value->m_handle);
      result->m_enum = HK_SUCCESS;
      LODWORD(address->m_object) = v14;
      return result;
    case 9:
    case 10:
    case 30:
      v15 = value->m_impl->vfptr[12].__vecDelDtor(value->m_impl, value->m_handle);
      result->m_enum = HK_SUCCESS;
      address->m_object = v15;
      return result;
    case 11:
      v16 = ((float (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *))value->m_impl->vfptr[15].__vecDelDtor)(
              value->m_impl,
              value->m_handle);
      result->m_enum = HK_SUCCESS;
      *(float *)&address->m_object = v16;
      return result;
    case 12:
    case 13:
      v25 = (hkVariant *)((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64))value->m_impl->vfptr[14].__vecDelDtor)(
                           value->m_impl,
                           value->m_handle,
                           4i64);
      result->m_enum = HK_SUCCESS;
      *address = *v25;
      return result;
    case 14:
    case 15:
    case 16:
      v26 = (hkVariant *)((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64))value->m_impl->vfptr[14].__vecDelDtor)(
                           value->m_impl,
                           value->m_handle,
                           12i64);
      result->m_enum = HK_SUCCESS;
      *address = *v26;
      address[1] = v26[1];
      address[2] = v26[2];
      return result;
    case 17:
    case 18:
      v27 = (hkVariant *)((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64))value->m_impl->vfptr[14].__vecDelDtor)(
                           value->m_impl,
                           value->m_handle,
                           16i64);
      result->m_enum = HK_SUCCESS;
      *address = *v27;
      address[1] = v27[1];
      address[2] = v27[2];
      address[3] = v27[3];
      return result;
    case 20:
      if ( !structClass )
        goto LABEL_41;
      v18 = (hkDataObjectImpl *)value->m_impl->vfptr[13].__vecDelDtor(value->m_impl, value->m_handle);
      v19 = v18;
      obj.m_impl = v18;
      if ( v18 )
      {
        ++v18->m_externalCount;
        ++v18->m_count;
      }
      hkDataObjectToNative::CopyInfoOut::addPointer(copyInfoOut, &obj, address, owningReference);
      goto LABEL_38;
    case 25:
      if ( !structClass )
        goto LABEL_41;
      v20 = (hkDataObjectImpl *)value->m_impl->vfptr[13].__vecDelDtor(value->m_impl, value->m_handle);
      srcObj.m_impl = v20;
      if ( v20 )
      {
        ++v20->m_externalCount;
        ++v20->m_count;
      }
      v21 = hkDataObjectToNative::fillNativeMembers(this, &resulta, (char *)address, &srcObj, copyInfoOut);
      m_impl = srcObj.m_impl;
      v23 = v21->m_enum == HK_FAILURE;
      if ( srcObj.m_impl )
      {
        --srcObj.m_impl->m_externalCount;
        v24 = m_impl->m_count-- == 1;
        if ( v24 )
          m_impl->vfptr->__vecDelDtor(m_impl, 1u);
      }
      if ( !v23 )
        goto LABEL_41;
      result->m_enum = HK_FAILURE;
      return result;
    case 28:
      if ( this->m_allocatedOnHeap )
        goto LABEL_42;
      v34 = (hkDataObjectImpl *)value->m_impl->vfptr[13].__vecDelDtor(value->m_impl, value->m_handle);
      v19 = v34;
      obj.m_impl = v34;
      if ( v34 )
      {
        ++v34->m_externalCount;
        ++v34->m_count;
      }
      hkDataObjectToNative::CopyInfoOut::addVariant(copyInfoOut, &obj, address, owningReference);
LABEL_38:
      if ( v19 )
      {
        --v19->m_externalCount;
        v24 = v19->m_count-- == 1;
        if ( v24 )
          v19->vfptr->__vecDelDtor(v19, 1u);
      }
LABEL_41:
      result->m_enum = HK_SUCCESS;
      return result;
    case 29:
      if ( this->m_allocatedOnHeap )
        goto LABEL_42;
      v28 = value;
      if ( value->m_impl->vfptr[11].__vecDelDtor(value->m_impl, value->m_handle) )
      {
        v29 = (char *)v28->m_impl->vfptr[11].__vecDelDtor(v28->m_impl, v28->m_handle);
        v30 = hkString::strDup(v29);
        v31 = v30;
        if ( v30 )
        {
LABEL_27:
          hkDataObjectToNative::CopyInfoOut::addAlloc(copyInfoOut, v30, -1);
          address->m_object = v31;
          result->m_enum = HK_SUCCESS;
          return result;
        }
      }
      else
      {
LABEL_28:
        v31 = 0i64;
      }
LABEL_29:
      address->m_object = v31;
      result->m_enum = HK_SUCCESS;
      return result;
    case 32:
      *(float *)&v17 = ((float (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *))value->m_impl->vfptr[15].__vecDelDtor)(
                         value->m_impl,
                         value->m_handle);
      result->m_enum = HK_SUCCESS;
      resulta.m_enum = v17;
      LOWORD(address->m_object) = HIWORD(v17);
      return result;
    case 33:
      v32 = value;
      if ( !value->m_impl->vfptr[11].__vecDelDtor(value->m_impl, value->m_handle) )
        goto LABEL_28;
      v33 = (char *)v32->m_impl->vfptr[11].__vecDelDtor(v32->m_impl, v32->m_handle);
      v30 = hkString::strDup(v33);
      v31 = v30;
      if ( !v30 )
        goto LABEL_29;
      if ( !this->m_allocatedOnHeap )
        goto LABEL_27;
      result->m_enum = HK_SUCCESS;
      address->m_object = v30 + 1;
      return result;
    default:
LABEL_42:
      result->m_enum = HK_FAILURE;
      return result;
  }
}

// File Line: 839
// RVA: 0xE5FDF0
hkResult *__fastcall hkDataObjectToNative::fillNativeMembers(
        hkDataObjectToNative *this,
        hkResult *result,
        char *dstObject,
        hkDataObject *srcObj,
        hkDataObjectToNative::CopyInfoOut *copyInfoOut)
{
  hkResultEnum m_enum; // edi
  __int64 v7; // rcx
  hkClass *Parent; // rax
  int v9; // ebx
  hkClassMember *DeclaredMember; // rax
  __int64 m_offset; // rbx
  hkClassMember *v12; // rsi
  char *v13; // rbx
  const char *m_name; // r8
  hkDataObjectImpl *m_impl; // rcx
  unsigned int SizeInBytes; // ebx
  const char *DeclaredDefault; // rax
  int v18; // eax
  int v19; // r8d
  int v20; // eax
  unsigned int m_storage; // edx
  int v22; // edx
  hkClass *structClass; // rax
  hkDataArrayImpl *v24; // rax
  hkDataArrayImpl *v25; // rbx
  hkDataRefCountedVtbl *vfptr; // rax
  int v27; // ecx
  hkClass *Class; // rax
  hkResult *v29; // rax
  int v30; // eax
  hkDataArrayImpl *v31; // rax
  hkResult *v32; // rax
  hkDataArrayImpl *v33; // rcx
  bool v34; // zf
  hkDataRefCountedVtbl *v35; // rax
  hkDataArrayImpl *v36; // rax
  char v37; // al
  hkDataArrayImpl *v38; // rax
  int v39; // esi
  int v40; // eax
  bool v41; // cc
  hkDataRefCountedVtbl *v42; // rax
  hkDataArrayImpl *v43; // rax
  hkClass *v44; // rax
  __int64 v45; // rax
  hkDataArrayImpl *v46; // rsi
  __int64 v47; // rax
  int v48; // ebx
  hkDataObjectImpl *v49; // rax
  hkDataObjectImpl *v50; // rbx
  hkClass *v51; // rax
  hkDataRefCountedVtbl *v52; // rax
  hkDataArrayImpl *v53; // rax
  hkDataObjectImpl *v54; // rax
  hkDataObjectImpl *v55; // rsi
  hkClass *v56; // rax
  int v57; // eax
  _DWORD *v58; // rsi
  hkClass *v59; // rcx
  int ObjectSize; // eax
  __int64 v61; // rcx
  void *v62; // rax
  void **v63; // rsi
  int v64; // r8d
  signed int v65; // esi
  hkDataObjectImpl *v66; // rax
  hkResult *v67; // rax
  hkDataObjectImpl *v68; // rcx
  hkResult *v69; // rax
  int n; // [rsp+40h] [rbp-C0h] BYREF
  int CstyleArraySize; // [rsp+44h] [rbp-BCh]
  int v72; // [rsp+48h] [rbp-B8h]
  hkClassMember::Type mtype; // [rsp+4Ch] [rbp-B4h]
  void *dst; // [rsp+50h] [rbp-B0h]
  unsigned int owningReference; // [rsp+58h] [rbp-A8h]
  hkDataObject_Value value; // [rsp+60h] [rbp-A0h] BYREF
  int declaredIndex; // [rsp+70h] [rbp-90h]
  hkClass *klass; // [rsp+78h] [rbp-88h]
  hkDataArray v79; // [rsp+80h] [rbp-80h] BYREF
  hkDataObject v80; // [rsp+88h] [rbp-78h] BYREF
  hkDataObject obj; // [rsp+90h] [rbp-70h] BYREF
  hkDataArray srcArray; // [rsp+98h] [rbp-68h] BYREF
  hkResult v83; // [rsp+A0h] [rbp-60h] BYREF
  hkResult v84; // [rsp+A4h] [rbp-5Ch] BYREF
  void *relArrayAddress; // [rsp+A8h] [rbp-58h] BYREF
  hkResult v86; // [rsp+B0h] [rbp-50h] BYREF
  hkResult v87; // [rsp+B4h] [rbp-4Ch] BYREF
  hkResult v88; // [rsp+B8h] [rbp-48h] BYREF
  hkResult resulta; // [rsp+BCh] [rbp-44h] BYREF
  hkResult v90; // [rsp+C0h] [rbp-40h] BYREF
  hkResult v91; // [rsp+C4h] [rbp-3Ch] BYREF
  hkResult v92; // [rsp+C8h] [rbp-38h] BYREF
  hkResult v93; // [rsp+CCh] [rbp-34h] BYREF
  hkDataArray_Value v94; // [rsp+D0h] [rbp-30h] BYREF
  hkDataArray_Value v95; // [rsp+E0h] [rbp-20h] BYREF
  hkDataArray_Value v96; // [rsp+F0h] [rbp-10h] BYREF
  __int64 v97[3]; // [rsp+100h] [rbp+0h] BYREF
  __int64 v98; // [rsp+118h] [rbp+18h]

  m_enum = HK_SUCCESS;
  klass = hkDataObjectToNative::findClassOf(this, srcObj);
  hkClass::getObjectSize(klass);
  v7 = (int)(hkClass::getObjectSize(klass) + 15);
  Parent = klass;
  relArrayAddress = &dstObject[v7 & 0xFFFFFFFFFFFFFFF0ui64];
  if ( !klass )
  {
LABEL_98:
    v69 = result;
    result->m_enum = m_enum;
    return v69;
  }
  while ( 1 )
  {
    v9 = 0;
    declaredIndex = 0;
    if ( (int)hkClass::getNumDeclaredMembers(Parent) > 0 )
      break;
LABEL_97:
    Parent = hkClass::getParent(klass);
    klass = Parent;
    if ( !Parent )
      goto LABEL_98;
  }
  while ( 1 )
  {
    DeclaredMember = hkClass::getDeclaredMember(klass, v9);
    m_offset = DeclaredMember->m_offset;
    v12 = DeclaredMember;
    v79.m_impl = (hkDataArrayImpl *)DeclaredMember;
    v13 = &dstObject[m_offset];
    m_name = DeclaredMember->m_name;
    mtype = (unsigned __int8)DeclaredMember->m_type.m_storage;
    dst = v13;
    ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, const char *))srcObj->m_impl->vfptr[3].__vecDelDtor)(
      srcObj->m_impl,
      &value,
      m_name);
    m_impl = value.m_impl;
    if ( value.m_impl )
    {
      if ( value.m_impl->vfptr[26].__vecDelDtor(value.m_impl, value.m_handle) )
        goto LABEL_17;
      m_impl = value.m_impl;
    }
    memset(v97, 0, sizeof(v97));
    v98 = 0i64;
    if ( m_impl )
      ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64 *))m_impl->vfptr[25].__vecDelDtor)(
        m_impl,
        value.m_handle,
        v97);
    if ( v12->m_type.m_storage == 22 )
      *((_DWORD *)v13 + 3) = 0x80000000;
    if ( !hkClass::hasDeclaredDefault(klass, declaredIndex)
      || !((unsigned int (__fastcall *)(hkDataObjectImpl *))srcObj->m_impl->vfptr[27].__vecDelDtor)(srcObj->m_impl) )
    {
      break;
    }
    SizeInBytes = hkClassMember::getSizeInBytes(v12);
    DeclaredDefault = hkClass::getDeclaredDefault(klass, declaredIndex);
    hkString::memCpy(dst, DeclaredDefault, SizeInBytes);
LABEL_96:
    v9 = ++declaredIndex;
    if ( v9 >= (int)hkClass::getNumDeclaredMembers(klass) )
      goto LABEL_97;
  }
  if ( (!value.m_impl || !v98) && (mtype != 25 || (v12->m_flags.m_storage & 0x400) != 0) )
    goto LABEL_96;
LABEL_17:
  if ( (unsigned int)hkClassMember::getCstyleArraySize(v12) )
  {
    CstyleArraySize = hkClassMember::getCstyleArraySize(v12);
    v18 = hkClassMember::getSizeInBytes(v12);
    v19 = CstyleArraySize;
    v20 = v18 / CstyleArraySize;
  }
  else
  {
    CstyleArraySize = 1;
    v20 = hkClassMember::getSizeInBytes(v12);
    v19 = CstyleArraySize;
  }
  m_storage = v12->m_flags.m_storage;
  v72 = v20;
  LOWORD(m_storage) = ~(_WORD)m_storage;
  v22 = (m_storage >> 9) & 1;
  owningReference = v22;
  switch ( mtype )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 25:
    case 28:
    case 29:
    case 30:
    case 32:
    case 33:
      if ( v19 == 1 )
      {
        structClass = hkClassMember::getClass(v12);
        m_enum = hkDataObjectToNative::fillNativeSimpleMember<hkDataObject_Value>(
                   this,
                   &resulta,
                   v13,
                   mtype,
                   &value,
                   structClass,
                   owningReference,
                   copyInfoOut)->m_enum;
        goto LABEL_95;
      }
      v24 = (hkDataArrayImpl *)value.m_impl->vfptr[10].__vecDelDtor(value.m_impl, value.m_handle);
      v25 = v24;
      if ( v24 )
      {
        ++v24->m_externalCount;
        ++v24->m_count;
      }
      vfptr = v24->vfptr;
      CstyleArraySize = 0;
      if ( ((int (__fastcall *)(hkDataArrayImpl *))vfptr[5].__vecDelDtor)(v25) > 0 )
      {
        v27 = CstyleArraySize;
        n = 0;
        do
        {
          if ( m_enum )
            break;
          v94.m_index = v27;
          v94.m_impl = v25;
          Class = hkClassMember::getClass(v12);
          v29 = hkDataObjectToNative::fillNativeSimpleMember<hkDataArray_Value>(
                  this,
                  &v92,
                  (char *)dst + n,
                  mtype,
                  &v94,
                  Class,
                  owningReference,
                  copyInfoOut);
          ++CstyleArraySize;
          m_enum = v29->m_enum;
          n += v72;
          v30 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v25->vfptr[5].__vecDelDtor)(v25);
          v27 = CstyleArraySize;
        }
        while ( CstyleArraySize < v30 );
      }
      goto LABEL_92;
    case 20:
      v37 = v12->m_subtype.m_storage;
      if ( v37 == 2 )
      {
        if ( v19 == 1 )
        {
          m_enum = hkDataObjectToNative::fillNativeSimpleMember<hkDataObject_Value>(
                     this,
                     &v90,
                     v13,
                     (hkClassMember::Type)29,
                     &value,
                     0i64,
                     v22,
                     copyInfoOut)->m_enum;
          goto LABEL_95;
        }
        v38 = (hkDataArrayImpl *)value.m_impl->vfptr[10].__vecDelDtor(value.m_impl, value.m_handle);
        v25 = v38;
        if ( v38 )
        {
          ++v38->m_externalCount;
          ++v38->m_count;
        }
        v39 = 0;
        if ( ((int (__fastcall *)(hkDataArrayImpl *))v38->vfptr[5].__vecDelDtor)(v38) > 0 )
        {
          v40 = 0;
          n = 0;
          do
          {
            if ( m_enum )
              break;
            v96.m_impl = v25;
            v96.m_index = v39;
            m_enum = hkDataObjectToNative::fillNativeSimpleMember<hkDataArray_Value>(
                       this,
                       &v84,
                       (char *)dst + v40,
                       (hkClassMember::Type)29,
                       &v96,
                       0i64,
                       owningReference,
                       copyInfoOut)->m_enum;
            n += v72;
            v41 = ++v39 < ((int (__fastcall *)(hkDataArrayImpl *))v25->vfptr[5].__vecDelDtor)(v25);
            v40 = n;
          }
          while ( v41 );
        }
LABEL_92:
        --v25->m_externalCount;
        v34 = v25->m_count-- == 1;
        if ( !v34 )
          goto LABEL_95;
        v35 = v25->vfptr;
        v33 = v25;
LABEL_94:
        v35->__vecDelDtor(v33, 1u);
        goto LABEL_95;
      }
      if ( v37 != 25 )
        goto LABEL_95;
      v42 = value.m_impl->vfptr;
      if ( v19 == 1 )
      {
        v43 = (hkDataArrayImpl *)v42[13].__vecDelDtor(value.m_impl, (unsigned int)value.m_handle);
        v25 = v43;
        v79.m_impl = v43;
        if ( v43 )
        {
          ++v43->m_externalCount;
          ++v43->m_count;
        }
        v44 = hkDataObjectToNative::getMemberClassAndCheck(this, v12, (hkDataObject *)&v79);
        m_enum = hkDataObjectToNative::fillNativeSimpleMember<hkDataObject_Value>(
                   this,
                   &v87,
                   dst,
                   mtype,
                   &value,
                   v44,
                   owningReference,
                   copyInfoOut)->m_enum;
        if ( v25 )
          goto LABEL_92;
      }
      else
      {
        v45 = (__int64)v42[10].__vecDelDtor(value.m_impl, (unsigned int)value.m_handle);
        v46 = (hkDataArrayImpl *)v45;
        if ( v45 )
        {
          ++*(_WORD *)(v45 + 10);
          ++*(_DWORD *)(v45 + 12);
        }
        v47 = *(_QWORD *)v45;
        v48 = 0;
        n = 0;
        if ( (*(int (__fastcall **)(hkDataArrayImpl *))(v47 + 40))(v46) > 0 )
        {
          CstyleArraySize = 0;
          do
          {
            if ( m_enum )
              break;
            v49 = (hkDataObjectImpl *)v46->vfptr[21].__vecDelDtor(v46, v48);
            v50 = v49;
            v80.m_impl = v49;
            if ( v49 )
            {
              ++v49->m_externalCount;
              ++v49->m_count;
            }
            v95.m_index = n;
            v95.m_impl = v46;
            v51 = hkDataObjectToNative::getMemberClassAndCheck(this, (hkClassMember *)v79.m_impl, &v80);
            m_enum = hkDataObjectToNative::fillNativeSimpleMember<hkDataArray_Value>(
                       this,
                       &v83,
                       (char *)dst + CstyleArraySize,
                       mtype,
                       &v95,
                       v51,
                       owningReference,
                       copyInfoOut)->m_enum;
            if ( v50 )
            {
              --v50->m_externalCount;
              v34 = v50->m_count-- == 1;
              if ( v34 )
                v50->vfptr->__vecDelDtor(v50, 1u);
            }
            CstyleArraySize += v72;
            v52 = v46->vfptr;
            v48 = ++n;
          }
          while ( v48 < ((int (__fastcall *)(hkDataArrayImpl *))v52[5].__vecDelDtor)(v46) );
        }
        --v46->m_externalCount;
        v34 = v46->m_count-- == 1;
        if ( v34 )
        {
          v35 = v46->vfptr;
          v33 = v46;
          goto LABEL_94;
        }
      }
LABEL_95:
      if ( m_enum != HK_FAILURE )
        goto LABEL_96;
LABEL_99:
      v69 = result;
      result->m_enum = HK_FAILURE;
      break;
    case 22:
    case 26:
      if ( this->m_allocatedOnHeap
        && (v12->m_type.m_storage == 26 || (unsigned __int8)(v12->m_subtype.m_storage - 28) <= 1u) )
      {
        goto LABEL_99;
      }
      v31 = (hkDataArrayImpl *)value.m_impl->vfptr[10].__vecDelDtor(value.m_impl, value.m_handle);
      srcArray.m_impl = v31;
      if ( v31 )
      {
        ++v31->m_externalCount;
        ++v31->m_count;
      }
      v32 = hkDataObjectToNative::copyIntoNativeArray(this, &v88, v13, v12, &srcArray, copyInfoOut);
      v33 = srcArray.m_impl;
      m_enum = v32->m_enum;
      if ( !srcArray.m_impl )
        goto LABEL_95;
      --srcArray.m_impl->m_externalCount;
      v34 = v33->m_count-- == 1;
      if ( !v34 )
        goto LABEL_95;
      v35 = v33->vfptr;
      goto LABEL_94;
    case 24:
    case 31:
      m_enum = hkDataObjectToNative::fillNativeEnumMember(this, &v93, v13, v12, &value, klass)->m_enum;
      goto LABEL_95;
    case 27:
      if ( this->m_allocatedOnHeap )
        goto LABEL_99;
      v53 = (hkDataArrayImpl *)value.m_impl->vfptr[10].__vecDelDtor(value.m_impl, value.m_handle);
      v25 = v53;
      if ( v53 )
      {
        ++v53->m_externalCount;
        ++v53->m_count;
      }
      v54 = (hkDataObjectImpl *)v53->vfptr[21].__vecDelDtor(v53, 0);
      v55 = v54;
      v80.m_impl = v54;
      if ( v54 )
      {
        ++v54->m_externalCount;
        ++v54->m_count;
      }
      v56 = hkDataObjectToNative::getMemberClassAndCheck(this, (hkClassMember *)v79.m_impl, &v80);
      *(_QWORD *)dst = v56;
      if ( v55 )
      {
        --v55->m_externalCount;
        v34 = v55->m_count-- == 1;
        if ( v34 )
          v55->vfptr->__vecDelDtor(v55, 1u);
      }
      v57 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v25->vfptr[5].__vecDelDtor)(v25);
      v58 = dst;
      v59 = *(hkClass **)dst;
      *((_DWORD *)dst + 4) = v57;
      ObjectSize = hkClass::getObjectSize(v59);
      LODWORD(v58) = ObjectSize * v58[4];
      v72 = ObjectSize;
      v61 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
      n = (int)v58;
      v62 = (void *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v61 + 24i64))(v61, &n);
      v63 = (void **)dst;
      v64 = n;
      *((_QWORD *)dst + 1) = v62;
      hkString::memSet(v62, 0, v64);
      hkDataObjectToNative::CopyInfoOut::addAlloc(copyInfoOut, v63[1], v72 * *((_DWORD *)v63 + 4));
      v65 = 0;
      if ( *((int *)dst + 4) > 0 )
      {
        n = 0;
        do
        {
          if ( m_enum )
            break;
          v66 = (hkDataObjectImpl *)v25->vfptr[21].__vecDelDtor(v25, v65);
          obj.m_impl = v66;
          if ( v66 )
          {
            ++v66->m_externalCount;
            ++v66->m_count;
          }
          v67 = hkDataObjectToNative::fillNativeMembers(
                  this,
                  &v86,
                  (void *)(*((_QWORD *)dst + 1) + n),
                  &obj,
                  copyInfoOut);
          v68 = obj.m_impl;
          m_enum = v67->m_enum;
          if ( obj.m_impl )
          {
            --obj.m_impl->m_externalCount;
            v34 = v68->m_count-- == 1;
            if ( v34 )
              v68->vfptr->__vecDelDtor(v68, 1u);
          }
          ++v65;
          n += v72;
        }
        while ( v65 < *((_DWORD *)dst + 4) );
      }
      goto LABEL_92;
    case 34:
      if ( this->m_allocatedOnHeap
        && (v12->m_type.m_storage == 26 || (unsigned __int8)(v12->m_subtype.m_storage - 28) <= 1u) )
      {
        goto LABEL_99;
      }
      v36 = (hkDataArrayImpl *)value.m_impl->vfptr[10].__vecDelDtor(value.m_impl, value.m_handle);
      v25 = v36;
      v79.m_impl = v36;
      if ( v36 )
      {
        ++v36->m_externalCount;
        ++v36->m_count;
      }
      m_enum = hkDataObjectToNative::copyIntoRelArray(
                 this,
                 &v91,
                 dst,
                 v12,
                 &v79,
                 copyInfoOut,
                 &relArrayAddress,
                 dstObject)->m_enum;
      if ( v25 )
        goto LABEL_92;
      goto LABEL_95;
    default:
      goto LABEL_99;
  }
  return v69;
}

// File Line: 1077
// RVA: 0xE62590
hkClass *__fastcall hkDataObjectToNative::getMemberClassAndCheck(
        hkDataObjectToNative *this,
        hkClassMember *member,
        hkDataObject *obj)
{
  hkClass *v6; // rax
  hkClass *Class; // rdi
  __int64 v8; // rax
  __int64 v9; // rax
  const char *v10; // rsi
  hkClass *v11; // rbx
  const char *Name; // rax
  hkVariant *Attribute; // rax
  bool v14; // zf
  hkBool result; // [rsp+50h] [rbp+18h] BYREF

  if ( !obj->m_impl )
    return 0i64;
  Class = hkClassMember::getClass(member);
  v8 = ((__int64 (__fastcall *)(hkDataObjectImpl *))obj->m_impl->vfptr[2].__vecDelDtor)(obj->m_impl);
  v9 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 16i64))(v8);
  v10 = (const char *)v9;
  if ( v9 )
    v11 = (hkClass *)this->m_classReg->vfptr[2].__vecDelDtor(this->m_classReg, v9);
  else
    v11 = 0i64;
  if ( !Class )
    return v11;
  if ( !v11 )
    return 0i64;
  Name = hkClass::getName(Class);
  if ( !(unsigned int)hkString::strCmp(Name, v10) )
    return Class;
  if ( hkClass::isSuperClass(Class, &result, v11)->m_bool )
    return v11;
  Attribute = hkClassMember::getAttribute(member, "hk.DataObjectType");
  if ( !Attribute )
    return Class;
  Class = (hkClass *)this->m_classReg->vfptr[2].__vecDelDtor(this->m_classReg, *(_QWORD *)Attribute->m_object);
  v14 = hkClass::isSuperClass(Class, &result, v11)->m_bool == 0;
  v6 = v11;
  if ( v14 )
    return Class;
  return v6;
}

