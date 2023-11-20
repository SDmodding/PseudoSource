// File Line: 50
// RVA: 0xE60720
hkClass *__fastcall hkDataObjectToNative::findClassOf(hkDataObjectToNative *this, hkDataObject *obj)
{
  hkDataObjectToNative *v2; // rbx
  __int64 v3; // rax
  __int64 v4; // rax

  v2 = this;
  v3 = ((__int64 (*)(void))obj->m_impl->vfptr[2].__vecDelDtor)();
  v4 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v3 + 16i64))(v3);
  return (hkClass *)v2->m_classReg->vfptr[2].__vecDelDtor((hkBaseObject *)&v2->m_classReg->vfptr, v4);
}

// File Line: 59
// RVA: 0xE5FC90
hkVariant *__fastcall hkDataObjectToNative::allocateObject(hkDataObjectToNative *this, hkVariant *result, hkDataObject *obj, hkDataObjectToNative::CopyInfoOut *infoOut)
{
  hkDataObjectToNative *v4; // rsi
  hkDataObjectToNative::CopyInfoOut *v5; // r15
  hkDataObject *v6; // rdi
  hkVariant *v7; // rbx
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  hkClass *v11; // rsi
  __int64 v12; // rax
  int v13; // er14
  unsigned int v14; // er14
  _QWORD **v15; // rax
  void *v16; // rbp
  signed __int64 v17; // rcx

  v4 = this;
  v5 = infoOut;
  v6 = obj;
  v7 = result;
  if ( ((__int64 (*)(void))obj->m_impl->vfptr[2].__vecDelDtor)()
    && (v8 = ((__int64 (*)(void))v6->m_impl->vfptr[2].__vecDelDtor)(),
        (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 16i64))(v8))
    && (v9 = ((__int64 (*)(void))v6->m_impl->vfptr[2].__vecDelDtor)(),
        v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 16i64))(v9),
        (v11 = (hkClass *)v4->m_classReg->vfptr[2].__vecDelDtor((hkBaseObject *)&v4->m_classReg->vfptr, v10)) != 0i64) )
  {
    v12 = ((__int64 (*)(void))v6->m_impl->vfptr[2].__vecDelDtor)();
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v12 + 24i64))(v12);
    hkClass::getDescribedVersion(v11);
    v13 = hkClass::getObjectSize(v11);
    v14 = (unsigned __int64)hkDataObjectUtil::getExtraStorageSize(v11, v6) + v13;
    v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v15[11] + 8i64))(v15[11], v14);
    if ( v5->allocs.m_size == (v5->allocs.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v5->allocs, 16);
    v17 = (signed __int64)&v5->allocs.m_data[v5->allocs.m_size++];
    *(_QWORD *)v17 = v16;
    *(_DWORD *)(v17 + 8) = v14;
    hkString::memSet(v16, 0, v14);
    v7->m_object = v16;
    v7->m_class = v11;
  }
  else
  {
    v7->m_object = 0i64;
    v7->m_class = 0i64;
  }
  return v7;
}

// File Line: 91
// RVA: 0xE62690
_BOOL8 __fastcall canFastCopy(hkClassMember::Type type)
{
  return (unsigned int)(type - 1) <= 0x11 || type == 30;
}

// File Line: 133
// RVA: 0xE60760
hkResult *__usercall hkDataObjectToNative::copyIntoNativeArray@<rax>(hkDataObjectToNative *this@<rcx>, hkResult *result@<rdx>, void *address@<r8>, hkClassMember *member@<r9>, int a5@<xmm0>, hkDataArray *srcArray, hkDataObjectToNative::CopyInfoOut *copyInfoOut)
{
  hkDataArray *v7; // r14
  hkDataObjectToNative *v8; // r13
  hkClassMember *v9; // r12
  hkResult *v10; // rbx
  signed int v11; // er15
  hkResult *v12; // rax
  hkClassMember::Type v13; // ebx
  hkClassMember::TypeProperties *v14; // rdi
  int v15; // er12
  int v16; // esi
  int v17; // er14
  _QWORD **v18; // rax
  void *v19; // rax
  void *v20; // r15
  int v21; // edi
  hkDataObjectToNative::CopyInfoOut *v22; // rcx
  unsigned int v23; // er13
  unsigned int v24; // esi
  hkDataRefCountedVtbl *v25; // rax
  hkResultEnum v26; // edi
  int v27; // er13
  __int64 v28; // r12
  __int64 v29; // rbx
  _QWORD **v30; // rax
  __int64 v31; // rax
  signed int v32; // er13
  hkDataObjectImpl *v33; // r15
  __int64 v34; // rdi
  int v35; // eax
  _QWORD **v36; // rax
  __int64 v37; // rax
  __int64 v38; // rdi
  char v39; // al
  _QWORD **v40; // rax
  __int64 v41; // rax
  __int64 v42; // rdi
  char v43; // al
  _QWORD **v44; // rax
  __int64 v45; // rax
  __int64 v46; // rdi
  char v47; // al
  __int64 v48; // rcx
  __int64 v49; // rdi
  __int16 v50; // ax
  __int64 v51; // rcx
  __int64 v52; // rdi
  __int16 v53; // ax
  __int64 v54; // rcx
  __int64 v55; // rdi
  int v56; // eax
  __int64 v57; // rcx
  __int64 v58; // rdi
  int v59; // eax
  __int64 v60; // rcx
  __int64 v61; // rdi
  __int64 v62; // rax
  __int64 v63; // rcx
  __int64 v64; // rdi
  __int64 v65; // rax
  __int64 v66; // rcx
  __int64 v67; // rdi
  __int64 v68; // rax
  __int64 v69; // rcx
  __int64 v70; // rdi
  __int64 v71; // rcx
  __int64 v72; // rdi
  __int64 v73; // rcx
  hkDataObjectImpl *v74; // rdi
  hkDataObjectImpl *v75; // rax
  __int64 v76; // rcx
  hkDataObjectImpl *v77; // rdi
  hkDataObjectImpl *v78; // rax
  __int64 v79; // rcx
  signed __int64 v80; // rdi
  _OWORD *v81; // rax
  __int64 v82; // rcx
  signed __int64 v83; // rdi
  _OWORD *v84; // rax
  __int64 v85; // rcx
  signed __int64 v86; // rdi
  _OWORD *v87; // rax
  __int64 v88; // rcx
  signed __int64 v89; // r13
  _OWORD *v90; // rax
  __int64 v91; // rcx
  signed __int64 v92; // r13
  _OWORD *v93; // rax
  __int64 v94; // rax
  __int64 v95; // rbx
  hkClass *v96; // r13
  bool v97; // zf
  int v98; // ebx
  __int64 v99; // rcx
  int v100; // eax
  int v101; // eax
  hkDataRefCountedVtbl *v102; // rdx
  int v103; // ebx
  int v104; // eax
  char *v105; // rdi
  hkDataObjectImpl *v106; // rax
  hkDataObjectImpl *v107; // rbx
  _DWORD *v108; // rsi
  __int64 v109; // rcx
  hkDataObjectImpl *v110; // rax
  hkDataObjectImpl *v111; // rdi
  hkDataObjectToNative::CopyInfoOut *v112; // r15
  __int64 v113; // rax
  __int64 v114; // rbx
  hkDataObjectToNative::CopyInfoOut *v115; // rbx
  int v116; // er12
  signed __int64 v117; // rcx
  __int64 v118; // rcx
  hkDataObjectImpl *v119; // rax
  hkVariant *v120; // rdi
  hkDataObjectToNative::CopyInfoOut *v121; // r15
  __int64 v122; // rax
  __int64 v123; // rbx
  __int64 v124; // rcx
  __int64 v125; // rax
  int v126; // ecx
  int v127; // edx
  hkDataArrayImpl *v128; // rax
  __int64 v129; // rcx
  __int64 v130; // rax
  int v131; // ecx
  int v132; // edx
  hkDataArrayImpl *v133; // rax
  int v134; // [rsp+40h] [rbp-59h]
  int v135; // [rsp+44h] [rbp-55h]
  hkDataObject srcObj; // [rsp+48h] [rbp-51h]
  int v137; // [rsp+50h] [rbp-49h]
  hkStridedBasicArray dst; // [rsp+58h] [rbp-41h]
  hkResult resulta; // [rsp+70h] [rbp-29h]
  hkResult v140; // [rsp+74h] [rbp-25h]
  hkResult v141; // [rsp+78h] [rbp-21h]
  hkStridedBasicArray src; // [rsp+80h] [rbp-19h]
  hkDataObjectToNative *v143; // [rsp+F0h] [rbp+57h]
  hkResult *v144; // [rsp+F8h] [rbp+5Fh]
  _DWORD *v145; // [rsp+100h] [rbp+67h]
  hkClassMember *membera; // [rsp+108h] [rbp+6Fh]

  membera = member;
  v145 = address;
  v144 = result;
  v143 = this;
  v7 = srcArray;
  v8 = this;
  v9 = member;
  v10 = result;
  v11 = -1;
  if ( ((unsigned int (*)(void))srcArray->m_impl->vfptr[5].__vecDelDtor)() )
  {
    v13 = (unsigned __int8)v9->m_subtype.m_storage;
    v14 = hkClassMember::getClassMemberTypeProperties(v13);
    if ( v14->m_size <= 0
      || !canFastCopy(v13)
      || (((void (__fastcall *)(hkDataArrayImpl *, hkDataArray **, hkStridedBasicArray *))v7->m_impl->vfptr[8].__vecDelDtor)(
            v7->m_impl,
            &srcArray,
            &src),
          (_DWORD)srcArray) )
    {
      v23 = v9->m_flags.m_storage;
      v24 = 0;
      v25 = v7->m_impl->vfptr;
      LOWORD(v23) = ~(_WORD)v23;
      v26 = 0;
      v135 = 0;
      v27 = (v23 >> 9) & 1;
      LODWORD(srcObj.m_impl) = v27;
      v28 = ((signed int (*)(void))v25[5].__vecDelDtor)();
      v29 = v28;
      switch ( membera->m_subtype.m_storage )
      {
        case 0:
          goto $LN872_0;
        case 1:
          v30 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v134 = v28;
          v31 = (*(__int64 (__fastcall **)(_QWORD *, int *))(*v30[11] + 24i64))(v30[11], &v134);
          v32 = 1;
          LODWORD(srcArray) = v134;
          v33 = (hkDataObjectImpl *)v31;
          if ( (signed int)v28 > 0 )
          {
            v34 = 0i64;
            do
            {
              v35 = (__int64)v7->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24);
              ++v34;
              ++v24;
              *((_BYTE *)v33 + v34 - 1) = v35 != 0;
            }
            while ( v34 < v28 );
            v26 = v135;
          }
          goto LABEL_131;
        case 2:
          v36 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v134 = v28;
          v37 = (*(__int64 (__fastcall **)(_QWORD *, int *))(*v36[11] + 24i64))(v36[11], &v134);
          v32 = 1;
          LODWORD(srcArray) = v134;
          v33 = (hkDataObjectImpl *)v37;
          if ( (signed int)v28 > 0 )
          {
            v38 = 0i64;
            do
            {
              v39 = (__int64)v7->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24);
              ++v38;
              ++v24;
              *((_BYTE *)v33 + v38 - 1) = v39;
            }
            while ( v38 < v28 );
            v26 = v135;
          }
          goto LABEL_131;
        case 3:
          v40 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v134 = v28;
          v41 = (*(__int64 (__fastcall **)(_QWORD *, int *))(*v40[11] + 24i64))(v40[11], &v134);
          v32 = 1;
          LODWORD(srcArray) = v134;
          v33 = (hkDataObjectImpl *)v41;
          if ( (signed int)v28 > 0 )
          {
            v42 = 0i64;
            do
            {
              v43 = (__int64)v7->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24);
              ++v42;
              ++v24;
              *((_BYTE *)v33 + v42 - 1) = v43;
            }
            while ( v42 < v28 );
            v26 = v135;
          }
          goto LABEL_131;
        case 4:
          v44 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v134 = v28;
          v45 = (*(__int64 (__fastcall **)(_QWORD *, int *))(*v44[11] + 24i64))(v44[11], &v134);
          v32 = 1;
          LODWORD(srcArray) = v134;
          v33 = (hkDataObjectImpl *)v45;
          if ( (signed int)v28 > 0 )
          {
            v46 = 0i64;
            do
            {
              v47 = (__int64)v7->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24);
              ++v46;
              ++v24;
              *((_BYTE *)v33 + v46 - 1) = v47;
            }
            while ( v46 < v28 );
            v26 = v135;
          }
          goto LABEL_131;
        case 5:
          v48 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v134 = 2 * v28;
          v32 = 2;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v48 + 24i64))(v48, &v134);
          LODWORD(srcArray) = v134 / 2;
          if ( (signed int)v28 > 0 )
          {
            v49 = 0i64;
            do
            {
              v50 = (__int64)v7->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24);
              ++v49;
              ++v24;
              *((_WORD *)v33 + v49 - 1) = v50;
            }
            while ( v49 < v28 );
            v26 = v135;
          }
          goto LABEL_131;
        case 6:
          v51 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v134 = 2 * v28;
          v32 = 2;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v51 + 24i64))(v51, &v134);
          LODWORD(srcArray) = v134 / 2;
          if ( (signed int)v28 > 0 )
          {
            v52 = 0i64;
            do
            {
              v53 = (__int64)v7->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24);
              ++v52;
              ++v24;
              *((_WORD *)v33 + v52 - 1) = v53;
            }
            while ( v52 < v28 );
            v26 = v135;
          }
          goto LABEL_131;
        case 7:
          v54 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v134 = 4 * v28;
          v32 = 4;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v54 + 24i64))(v54, &v134);
          LODWORD(srcArray) = v134 / 4;
          if ( (signed int)v28 > 0 )
          {
            v55 = 0i64;
            do
            {
              v56 = (__int64)v7->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24);
              ++v55;
              ++v24;
              *((_DWORD *)v33 + v55 - 1) = v56;
            }
            while ( v55 < v28 );
            v26 = v135;
          }
          goto LABEL_131;
        case 8:
          v57 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v134 = 4 * v28;
          v32 = 4;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v57 + 24i64))(v57, &v134);
          LODWORD(srcArray) = v134 / 4;
          if ( (signed int)v28 > 0 )
          {
            v58 = 0i64;
            do
            {
              v59 = (__int64)v7->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24);
              ++v58;
              ++v24;
              *((_DWORD *)v33 + v58 - 1) = v59;
            }
            while ( v58 < v28 );
            v26 = v135;
          }
          goto LABEL_131;
        case 9:
          v60 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v134 = 8 * v28;
          v32 = 8;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v60 + 24i64))(v60, &v134);
          LODWORD(srcArray) = v134 / 8;
          if ( (signed int)v28 > 0 )
          {
            v61 = 0i64;
            do
            {
              v62 = (__int64)v7->m_impl->vfptr[19].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24);
              ++v61;
              ++v24;
              *((_QWORD *)v33 + v61 - 1) = v62;
            }
            while ( v61 < v28 );
            v26 = v135;
          }
          goto LABEL_131;
        case 0xA:
          v63 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v134 = 8 * v28;
          v32 = 8;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v63 + 24i64))(v63, &v134);
          LODWORD(srcArray) = v134 / 8;
          if ( (signed int)v28 > 0 )
          {
            v64 = 0i64;
            do
            {
              v65 = (__int64)v7->m_impl->vfptr[19].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24);
              ++v64;
              ++v24;
              *((_QWORD *)v33 + v64 - 1) = v65;
            }
            while ( v64 < v28 );
            v26 = v135;
          }
          goto LABEL_131;
        case 0xB:
          v69 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v134 = 4 * v28;
          v32 = 4;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v69 + 24i64))(v69, &v134);
          LODWORD(srcArray) = v134 / 4;
          if ( (signed int)v28 > 0 )
          {
            v70 = 0i64;
            do
            {
              v7->m_impl->vfptr[15].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24);
              ++v70;
              ++v24;
              *((_DWORD *)v33 + v70 - 1) = a5;
            }
            while ( v70 < v28 );
            v26 = v135;
          }
          goto LABEL_131;
        case 0xC:
          v73 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v134 = 16 * v28;
          v32 = 16;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v73 + 24i64))(v73, &v134);
          LODWORD(srcArray) = v134 / 16;
          if ( (signed int)v28 > 0 )
          {
            v74 = v33;
            do
            {
              v75 = (hkDataObjectImpl *)v7->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24++);
              ++v74;
              v74[-1] = *v75;
              --v29;
            }
            while ( v29 );
            v26 = v135;
          }
          goto LABEL_131;
        case 0xD:
          v76 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v134 = 16 * v28;
          v32 = 16;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v76 + 24i64))(v76, &v134);
          LODWORD(srcArray) = v134 / 16;
          if ( (signed int)v28 > 0 )
          {
            v77 = v33;
            do
            {
              v78 = (hkDataObjectImpl *)v7->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24++);
              ++v77;
              v77[-1] = *v78;
              --v29;
            }
            while ( v29 );
            v26 = v135;
          }
          goto LABEL_131;
        case 0xE:
          v79 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v134 = 48 * v28;
          v32 = 48;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v79 + 24i64))(v79, &v134);
          LODWORD(srcArray) = v134 / 48;
          if ( (signed int)v28 > 0 )
          {
            v80 = (signed __int64)&v33[2];
            do
            {
              v81 = (_OWORD *)v7->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24++);
              v80 += 48i64;
              *(_OWORD *)(v80 - 80) = *v81;
              *(_OWORD *)(v80 - 64) = v81[1];
              *(_OWORD *)(v80 - 48) = v81[2];
              --v29;
            }
            while ( v29 );
            v26 = v135;
          }
          goto LABEL_131;
        case 0xF:
          v82 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v134 = 48 * v28;
          v32 = 48;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v82 + 24i64))(v82, &v134);
          LODWORD(srcArray) = v134 / 48;
          if ( (signed int)v28 > 0 )
          {
            v83 = (signed __int64)&v33[2];
            do
            {
              v84 = (_OWORD *)v7->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24++);
              v83 += 48i64;
              *(_OWORD *)(v83 - 80) = *v84;
              *(_OWORD *)(v83 - 64) = v84[1];
              *(_OWORD *)(v83 - 48) = v84[2];
              --v29;
            }
            while ( v29 );
            v26 = v135;
          }
          goto LABEL_131;
        case 0x10:
          v85 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v134 = 48 * v28;
          v32 = 48;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v85 + 24i64))(v85, &v134);
          LODWORD(srcArray) = v134 / 48;
          if ( (signed int)v28 > 0 )
          {
            v86 = (signed __int64)&v33[2];
            do
            {
              v87 = (_OWORD *)v7->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24++);
              v86 += 48i64;
              *(_OWORD *)(v86 - 80) = *v87;
              *(_OWORD *)(v86 - 64) = v87[1];
              *(_OWORD *)(v86 - 48) = v87[2];
              --v29;
            }
            while ( v29 );
            v26 = v135;
          }
          goto LABEL_131;
        case 0x11:
          v88 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v134 = (_DWORD)v28 << 6;
          v32 = 64;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v88 + 24i64))(v88, &v134);
          LODWORD(srcArray) = v134 / 64;
          if ( (signed int)v28 > 0 )
          {
            v89 = (signed __int64)&v33[2];
            do
            {
              v90 = (_OWORD *)v7->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24++);
              v89 += 64i64;
              *(_OWORD *)(v89 - 96) = *v90;
              *(_OWORD *)(v89 - 80) = v90[1];
              *(_OWORD *)(v89 - 64) = v90[2];
              *(_OWORD *)(v89 - 48) = v90[3];
              --v29;
            }
            while ( v29 );
            v32 = 64;
          }
          goto LABEL_131;
        case 0x12:
          v91 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v135 = (_DWORD)v28 << 6;
          v32 = 64;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v91 + 24i64))(v91, &v135);
          v134 = 64;
          LODWORD(srcArray) = v135 / 64;
          if ( (signed int)v28 <= 0 )
            goto LABEL_131;
          v92 = (signed __int64)&v33[2];
          do
          {
            v93 = (_OWORD *)v7->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24++);
            v92 += 64i64;
            *(_OWORD *)(v92 - 96) = *v93;
            *(_OWORD *)(v92 - 80) = v93[1];
            *(_OWORD *)(v92 - 64) = v93[2];
            *(_OWORD *)(v92 - 48) = v93[3];
            --v29;
          }
          while ( v29 );
          goto LABEL_130;
        case 0x14:
          v109 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v137 = 8 * v28;
          v110 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v109 + 24i64))(v109, &v137);
          v134 = 8;
          v33 = v110;
          srcObj.m_impl = v110;
          LODWORD(srcArray) = v137 / 8;
          hkString::memSet(v110, 0, 8 * v28);
          if ( (signed int)v28 <= 0 )
            goto LABEL_130;
          v111 = v33;
          v112 = copyInfoOut;
          do
          {
            v113 = (__int64)v7->m_impl->vfptr[21].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24);
            v114 = v113;
            *(_QWORD *)&dst.m_type = v113;
            if ( v113 )
            {
              ++*(_WORD *)(v113 + 10);
              ++*(_DWORD *)(v113 + 12);
            }
            hkDataObjectToNative::CopyInfoOut::addPointer(v112, (hkDataObject *)&dst, v111, v27);
            if ( v114 )
            {
              --*(_WORD *)(v114 + 10);
              v97 = (*(_DWORD *)(v114 + 12))-- == 1;
              if ( v97 )
                (**(void (__fastcall ***)(__int64, signed __int64))v114)(v114, 1i64);
            }
            ++v24;
            v111 = (hkDataObjectImpl *)((char *)v111 + 8);
          }
          while ( (signed int)v24 < (signed int)v28 );
          goto LABEL_129;
        case 0x19:
          v94 = (__int64)v7->m_impl->vfptr[21].__vecDelDtor((hkDataRefCounted *)v7->m_impl, 0);
          v95 = v94;
          srcArray = (hkDataArray *)v94;
          if ( v94 )
          {
            ++*(_WORD *)(v94 + 10);
            ++*(_DWORD *)(v94 + 12);
          }
          v96 = hkDataObjectToNative::getMemberClassAndCheck(v143, membera, (hkDataObject *)&srcArray);
          if ( v95 )
          {
            --*(_WORD *)(v95 + 10);
            v97 = (*(_DWORD *)(v95 + 12))-- == 1;
            if ( v97 )
              (**(void (__fastcall ***)(__int64, signed __int64))v95)(v95, 1i64);
          }
          if ( !v96 )
            goto $LN872_0;
          v98 = v28 * hkClass::getObjectSize(v96);
          v99 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v135 = v98;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v99 + 24i64))(v99, &v135);
          v100 = hkClass::getObjectSize(v96);
          LODWORD(srcArray) = v135 / v100;
          v101 = hkClass::getObjectSize(v96);
          v102 = v7->m_impl->vfptr;
          v134 = v101;
          v103 = ((__int64 (*)(void))v102[5].__vecDelDtor)();
          v104 = hkClass::getObjectSize(v96);
          hkString::memSet(v33, 0, v103 * v104);
          if ( (signed int)v28 > 0 )
          {
            do
            {
              if ( v26 )
                break;
              v105 = (char *)v33 + (signed int)(v24 * (unsigned __int64)hkClass::getObjectSize(v96));
              v106 = (hkDataObjectImpl *)v7->m_impl->vfptr[21].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24);
              v107 = v106;
              srcObj.m_impl = v106;
              if ( v106 )
              {
                ++v106->m_externalCount;
                ++v106->m_count;
              }
              v26 = hkDataObjectToNative::fillNativeMembers(v143, &resulta, v105, &srcObj, copyInfoOut)->m_enum;
              if ( v107 )
              {
                --v107->m_externalCount;
                v97 = v107->m_count-- == 1;
                if ( v97 )
                  v107->vfptr->__vecDelDtor((hkDataRefCounted *)&v107->vfptr, 1u);
              }
              ++v24;
            }
            while ( (signed int)v24 < (signed int)v28 );
          }
          v32 = v134;
          if ( v134 > 0 )
            goto LABEL_131;
          v11 = (signed int)srcArray;
$LN872_0:
          v108 = v145;
          goto LABEL_116;
        case 0x1C:
          v118 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v137 = 16 * v28;
          v119 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v118 + 24i64))(v118, &v137);
          v134 = 16;
          v33 = v119;
          srcObj.m_impl = v119;
          LODWORD(srcArray) = v137 / 16;
          hkString::memSet(v119, 0, 16 * v28);
          if ( (signed int)v28 > 0 )
          {
            v120 = (hkVariant *)v33;
            v121 = copyInfoOut;
            do
            {
              v122 = (__int64)v7->m_impl->vfptr[21].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24);
              v123 = v122;
              *(_QWORD *)&dst.m_type = v122;
              if ( v122 )
              {
                ++*(_WORD *)(v122 + 10);
                ++*(_DWORD *)(v122 + 12);
              }
              hkDataObjectToNative::CopyInfoOut::addVariant(v121, (hkDataObject *)&dst, v120, v27);
              if ( v123 )
              {
                --*(_WORD *)(v123 + 10);
                v97 = (*(_DWORD *)(v123 + 12))-- == 1;
                if ( v97 )
                  (**(void (__fastcall ***)(__int64, signed __int64))v123)(v123, 1i64);
              }
              ++v24;
              ++v120;
            }
            while ( (signed int)v24 < (signed int)v28 );
LABEL_129:
            v26 = v135;
            v33 = srcObj.m_impl;
          }
LABEL_130:
          v32 = v134;
          goto LABEL_131;
        case 0x1D:
          v124 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v137 = 8 * v28;
          v125 = (*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v124 + 24i64))(v124, &v137);
          v126 = 0;
          v32 = 8;
          v33 = (hkDataObjectImpl *)v125;
          v134 = 0;
          LODWORD(srcArray) = v137 / 8;
          if ( (signed int)v28 > 0 )
          {
            v127 = 0;
            v135 = 0;
            do
            {
              if ( v26 )
                break;
              v128 = v7->m_impl;
              LODWORD(dst.m_data) = v126;
              *(_QWORD *)&dst.m_type = v128;
              v26 = hkDataObjectToNative::fillNativeSimpleMember<hkDataArray_Value>(
                      v143,
                      &v140,
                      (char *)v33 + v127,
                      (hkClassMember::Type)(unsigned __int8)membera->m_subtype.m_storage,
                      (hkDataArray_Value *)&dst,
                      0i64,
                      (unsigned int)srcObj.m_impl,
                      copyInfoOut)->m_enum;
              v126 = v134 + 1;
              v127 = v135 + 8;
              v134 = v126;
              v135 += 8;
            }
            while ( v126 < (signed int)v28 );
          }
          goto LABEL_131;
        case 0x1E:
          v66 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v134 = 8 * v28;
          v32 = 8;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v66 + 24i64))(v66, &v134);
          LODWORD(srcArray) = v134 / 8;
          if ( (signed int)v28 > 0 )
          {
            v67 = 0i64;
            do
            {
              v68 = (__int64)v7->m_impl->vfptr[19].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24);
              ++v67;
              ++v24;
              *((_QWORD *)v33 + v67 - 1) = v68;
            }
            while ( v67 < v28 );
            v26 = v135;
          }
          goto LABEL_131;
        case 0x20:
          v71 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v134 = 2 * v28;
          v32 = 2;
          v33 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v71 + 24i64))(v71, &v134);
          LODWORD(srcArray) = v134 / 2;
          if ( (signed int)v28 > 0 )
          {
            v72 = 0i64;
            do
            {
              v7->m_impl->vfptr[15].__vecDelDtor((hkDataRefCounted *)v7->m_impl, v24);
              ++v72;
              ++v24;
              LODWORD(srcObj.m_impl) = a5;
              *((_WORD *)v33 + v72 - 1) = HIWORD(a5);
            }
            while ( v72 < v28 );
            v26 = v135;
          }
          goto LABEL_131;
        case 0x21:
          v129 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
          v137 = 8 * v28;
          v130 = (*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v129 + 24i64))(v129, &v137);
          v131 = 0;
          v32 = 8;
          v33 = (hkDataObjectImpl *)v130;
          v134 = 0;
          LODWORD(srcArray) = v137 / 8;
          if ( (signed int)v28 > 0 )
          {
            v132 = 0;
            v135 = 0;
            do
            {
              if ( v26 )
                break;
              v133 = v7->m_impl;
              LODWORD(dst.m_data) = v131;
              *(_QWORD *)&dst.m_type = v133;
              v26 = hkDataObjectToNative::fillNativeSimpleMember<hkDataArray_Value>(
                      v143,
                      &v141,
                      (char *)v33 + v132,
                      (hkClassMember::Type)(unsigned __int8)membera->m_subtype.m_storage,
                      (hkDataArray_Value *)&dst,
                      0i64,
                      (unsigned int)srcObj.m_impl,
                      copyInfoOut)->m_enum;
              v131 = v134 + 1;
              v132 = v135 + 8;
              v134 = v131;
              v135 += 8;
            }
            while ( v131 < (signed int)v28 );
          }
LABEL_131:
          v108 = v145;
          v115 = copyInfoOut;
          v145[2] = v28;
          *(_QWORD *)v145 = v33;
          v116 = v32 * v28;
          if ( v115->allocs.m_size == (v115->allocs.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v115->allocs, 16);
          v117 = (signed __int64)&v115->allocs.m_data[v115->allocs.m_size++];
          *(_QWORD *)v117 = v33;
          v11 = (signed int)srcArray;
          *(_DWORD *)(v117 + 8) = v116;
LABEL_116:
          if ( membera->m_type.m_storage == 22 )
          {
            if ( !v143->m_allocatedOnHeap )
              v11 |= 0x80000000;
            v108[3] = v11;
          }
          v12 = v144;
          v144->m_enum = v26;
          break;
        default:
          v12 = v144;
          v144->m_enum = 1;
          break;
      }
    }
    else
    {
      v15 = src.m_size;
      v16 = v14->m_size;
      v17 = v16 * src.m_size;
      LODWORD(srcArray) = v16 * src.m_size;
      v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v19 = (void *)(*(__int64 (__fastcall **)(_QWORD *, hkDataArray **))(*v18[11] + 24i64))(v18[11], &srcArray);
      dst.m_type = v13;
      v20 = v19;
      dst.m_size = src.m_size;
      dst.m_stride = v16;
      dst.m_tupleSize = 1;
      dst.m_data = v19;
      v21 = (signed int)srcArray / v16;
      switch ( v13 )
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
          dst.m_type = 11;
          break;
        default:
          break;
      }
      hkVariantDataUtil::convertArray(&src, &dst);
      if ( v16 > 0 )
      {
        v22 = copyInfoOut;
        *(_QWORD *)v145 = v20;
        v145[2] = v15;
        hkDataObjectToNative::CopyInfoOut::addAlloc(v22, v20, v17);
      }
      if ( membera->m_type.m_storage == 22 )
      {
        if ( !v8->m_allocatedOnHeap )
          v21 |= 0x80000000;
        v145[3] = v21;
      }
      v12 = v144;
      v144->m_enum = 0;
    }
  }
  else
  {
    v12 = v10;
    v10->m_enum = 0;
  }
  return v12;
}

// File Line: 452
// RVA: 0xE617F0
hkResult *__usercall hkDataObjectToNative::copyIntoRelArray@<rax>(hkDataObjectToNative *this@<rcx>, hkResult *result@<rdx>, void *address@<r8>, hkClassMember *member@<r9>, int a5@<xmm0>, hkDataArray *srcArray, hkDataObjectToNative::CopyInfoOut *copyInfoOut, void **relArrayAddress)
{
  hkDataArray *v8; // r14
  signed int v9; // esi
  hkClassMember *v10; // r13
  _DWORD *v11; // rdi
  hkResult *v12; // rbx
  hkDataRefCountedVtbl *v13; // rax
  hkResult *v14; // rax
  unsigned int v15; // er12
  hkResultEnum v16; // edi
  int owningReference; // er12
  void **v18; // r15
  signed int v19; // ebp
  __int64 v20; // r12
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
  hkDataArrayImpl *v44; // rcx
  __int64 v45; // rbx
  char *v46; // rax
  __int64 v47; // rbx
  _OWORD *v48; // rax
  __int64 v49; // rbx
  _OWORD *v50; // rax
  __int64 v51; // rbx
  _OWORD *v52; // rax
  char *v53; // rcx
  __int64 v54; // rbx
  _OWORD *v55; // rax
  char *v56; // rcx
  __int64 v57; // rbx
  _OWORD *v58; // rax
  char *v59; // rcx
  __int64 v60; // rbx
  _OWORD *v61; // rax
  char *v62; // rcx
  __int64 v63; // rbx
  _OWORD *v64; // rax
  char *v65; // rcx
  __int64 v66; // rax
  __int64 v67; // rbx
  hkClass *v68; // r13
  bool v69; // zf
  signed int v70; // eax
  hkDataRefCountedVtbl *v71; // rdx
  int v72; // ebx
  int v73; // eax
  hkDataObjectToNative::CopyInfoOut *v74; // rbp
  char *v75; // rbx
  hkDataObjectImpl *v76; // rax
  hkResult *v77; // rax
  hkDataObjectImpl *v78; // rcx
  int v79; // eax
  void *v80; // rcx
  hkDataObjectToNative::CopyInfoOut *v81; // r13
  hkDataObjectImpl *v82; // rax
  hkDataObjectImpl *v83; // rbx
  int v84; // eax
  void *v85; // rcx
  hkDataObjectToNative::CopyInfoOut *v86; // r13
  hkDataObjectImpl *v87; // rax
  hkDataObjectImpl *v88; // rbx
  __int16 v89; // ax
  hkDataArrayImpl *v90; // rcx
  int v91; // ebx
  int v92; // ecx
  hkClassMember::Type v93; // er9
  char *v94; // r8
  hkResult *v95; // rax
  hkDataArrayImpl *v96; // rcx
  int v97; // eax
  __int16 v98; // ax
  hkDataArrayImpl *v99; // rcx
  hkDataRefCountedVtbl *v100; // rax
  int v101; // ebx
  int v102; // ebp
  hkClassMember::Type v103; // er9
  char *v104; // r8
  hkDataObject obj; // [rsp+5Ah] [rbp-68h]
  hkResult resulta; // [rsp+62h] [rbp-60h]
  hkResult v107; // [rsp+66h] [rbp-5Ch]
  hkResult v108; // [rsp+6Ah] [rbp-58h]
  hkDataObject srcObj; // [rsp+72h] [rbp-50h]
  hkDataArray_Value value; // [rsp+7Ah] [rbp-48h]
  hkDataObjectToNative *v111; // [rsp+CAh] [rbp+8h]
  hkResult *v112; // [rsp+D2h] [rbp+10h]
  _WORD *v113; // [rsp+DAh] [rbp+18h]

  v113 = address;
  v112 = result;
  v111 = this;
  v8 = srcArray;
  v9 = 0;
  v10 = member;
  v11 = address;
  v12 = result;
  v13 = srcArray->m_impl->vfptr;
  LODWORD(obj.m_impl) = 0;
  if ( ((unsigned int (*)(void))v13[5].__vecDelDtor)() )
  {
    v15 = v10->m_flags.m_storage;
    v16 = 0;
    LOWORD(v15) = ~(_WORD)v15;
    owningReference = (v15 >> 9) & 1;
    v18 = relArrayAddress;
    switch ( v10->m_subtype.m_storage )
    {
      case 0:
        goto $LN1_70;
      case 1:
        v19 = 1;
        LOWORD(v20) = ((__int64 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        v21 = 0i64;
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          do
          {
            v22 = (__int64)v8->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9);
            ++v21;
            ++v9;
            *((char *)*v18 + v21 - 1) = v22 != 0;
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 2:
        v19 = 1;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        v23 = 0i64;
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          do
          {
            v24 = (__int64)v8->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9++);
            *((_BYTE *)*v18 + v23++) = v24;
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 3:
        v19 = 1;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        v25 = 0i64;
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          do
          {
            v26 = (__int64)v8->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9++);
            *((_BYTE *)*v18 + v25++) = v26;
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 4:
        v19 = 1;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        v27 = 0i64;
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          do
          {
            v28 = (__int64)v8->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9++);
            *((_BYTE *)*v18 + v27++) = v28;
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 5:
        v19 = 2;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v29 = 0i64;
          do
          {
            v30 = (__int64)v8->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9++);
            *(_WORD *)((char *)*v18 + v29) = v30;
            v29 += 2i64;
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 6:
        v19 = 2;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v31 = 0i64;
          do
          {
            v32 = (__int64)v8->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9++);
            *(_WORD *)((char *)*v18 + v31) = v32;
            v31 += 2i64;
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 7:
        v19 = 4;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v33 = 0i64;
          do
          {
            v34 = (__int64)v8->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9++);
            *(_DWORD *)((char *)*v18 + v33) = v34;
            v33 += 4i64;
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 8:
        v19 = 4;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v35 = 0i64;
          do
          {
            v36 = (__int64)v8->m_impl->vfptr[17].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9++);
            *(_DWORD *)((char *)*v18 + v35) = v36;
            v35 += 4i64;
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 9:
        v19 = 8;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v37 = 0i64;
          do
          {
            v38 = (__int64)v8->m_impl->vfptr[19].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9++);
            *(_QWORD *)((char *)*v18 + v37) = v38;
            v37 += 8i64;
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 0xA:
        v19 = 8;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v39 = 0i64;
          do
          {
            v40 = (__int64)v8->m_impl->vfptr[19].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9++);
            *(_QWORD *)((char *)*v18 + v39) = v40;
            v39 += 8i64;
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 0xB:
        v19 = 4;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v43 = 0i64;
          do
          {
            v8->m_impl->vfptr[15].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9);
            v44 = v8->m_impl;
            *(_DWORD *)((char *)*v18 + v43) = a5;
            ++v9;
            v43 += 4i64;
          }
          while ( v9 < ((signed int (*)(void))v44->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 0xC:
        v19 = 16;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v47 = 0i64;
          do
          {
            v48 = (_OWORD *)v8->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9++);
            v47 += 16i64;
            *(_OWORD *)((char *)*v18 + v47 - 16) = *v48;
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 0xD:
        v19 = 16;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v49 = 0i64;
          do
          {
            v50 = (_OWORD *)v8->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9++);
            v49 += 16i64;
            *(_OWORD *)((char *)*v18 + v49 - 16) = *v50;
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 0xE:
        v19 = 48;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v51 = 0i64;
          do
          {
            v52 = (_OWORD *)v8->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9);
            v53 = (char *)*v18;
            ++v9;
            v51 += 48i64;
            *(_OWORD *)&v53[v51 - 48] = *v52;
            *(_OWORD *)&v53[v51 - 32] = v52[1];
            *(_OWORD *)&v53[v51 - 16] = v52[2];
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 0xF:
        v19 = 48;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v54 = 0i64;
          do
          {
            v55 = (_OWORD *)v8->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9);
            v56 = (char *)*v18;
            ++v9;
            v54 += 48i64;
            *(_OWORD *)&v56[v54 - 48] = *v55;
            *(_OWORD *)&v56[v54 - 32] = v55[1];
            *(_OWORD *)&v56[v54 - 16] = v55[2];
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 0x10:
        v19 = 48;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v57 = 0i64;
          do
          {
            v58 = (_OWORD *)v8->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9);
            v59 = (char *)*v18;
            ++v9;
            v57 += 48i64;
            *(_OWORD *)&v59[v57 - 48] = *v58;
            *(_OWORD *)&v59[v57 - 32] = v58[1];
            *(_OWORD *)&v59[v57 - 16] = v58[2];
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 0x11:
        v19 = 64;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v60 = 0i64;
          do
          {
            v61 = (_OWORD *)v8->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9);
            v62 = (char *)*v18;
            ++v9;
            v60 += 64i64;
            *(_OWORD *)&v62[v60 - 64] = *v61;
            *(_OWORD *)&v62[v60 - 48] = v61[1];
            *(_OWORD *)&v62[v60 - 32] = v61[2];
            *(_OWORD *)&v62[v60 - 16] = v61[3];
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 0x12:
        v19 = 64;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v63 = 0i64;
          do
          {
            v64 = (_OWORD *)v8->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9);
            v65 = (char *)*v18;
            ++v9;
            v63 += 64i64;
            *(_OWORD *)&v65[v63 - 64] = *v64;
            *(_OWORD *)&v65[v63 - 48] = v64[1];
            *(_OWORD *)&v65[v63 - 32] = v64[2];
            *(_OWORD *)&v65[v63 - 16] = v64[3];
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 0x14:
        v79 = ((__int64 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        v80 = *v18;
        LODWORD(srcArray) = v79;
        v19 = 8;
        hkString::memSet(v80, 0, 8 * (unsigned __int16)v79);
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v81 = copyInfoOut;
          do
          {
            v82 = (hkDataObjectImpl *)v8->m_impl->vfptr[21].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9);
            v83 = v82;
            obj.m_impl = v82;
            if ( v82 )
            {
              ++v82->m_externalCount;
              ++v82->m_count;
            }
            hkDataObjectToNative::CopyInfoOut::addPointer(v81, &obj, (char *)*v18 + 8 * v9, owningReference);
            if ( v83 )
            {
              --v83->m_externalCount;
              v69 = v83->m_count-- == 1;
              if ( v69 )
                v83->vfptr->__vecDelDtor((hkDataRefCounted *)&v83->vfptr, 1u);
            }
            ++v9;
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_126;
      case 0x19:
        v66 = (__int64)v8->m_impl->vfptr[21].__vecDelDtor((hkDataRefCounted *)v8->m_impl, 0);
        v67 = v66;
        srcArray = (hkDataArray *)v66;
        if ( v66 )
        {
          ++*(_WORD *)(v66 + 10);
          ++*(_DWORD *)(v66 + 12);
        }
        v68 = hkDataObjectToNative::getMemberClassAndCheck(v111, v10, (hkDataObject *)&srcArray);
        if ( v67 )
        {
          --*(_WORD *)(v67 + 10);
          v69 = (*(_DWORD *)(v67 + 12))-- == 1;
          if ( v69 )
            (**(void (__fastcall ***)(__int64, signed __int64))v67)(v67, 1i64);
        }
        if ( v68 )
        {
          LOWORD(srcArray) = ((__int64 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
          v70 = hkClass::getObjectSize(v68);
          v71 = v8->m_impl->vfptr;
          v19 = v70;
          LODWORD(obj.m_impl) = v70;
          v72 = ((__int64 (*)(void))v71[5].__vecDelDtor)();
          v73 = hkClass::getObjectSize(v68);
          hkString::memSet(*v18, 0, v72 * v73);
          if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
          {
            v74 = copyInfoOut;
            do
            {
              if ( v16 )
                break;
              v75 = (char *)*v18 + (signed int)(v9 * (unsigned __int64)hkClass::getObjectSize(v68));
              v76 = (hkDataObjectImpl *)v8->m_impl->vfptr[21].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9);
              srcObj.m_impl = v76;
              if ( v76 )
              {
                ++v76->m_externalCount;
                ++v76->m_count;
              }
              v77 = hkDataObjectToNative::fillNativeMembers(v111, &resulta, v75, &srcObj, v74);
              v78 = srcObj.m_impl;
              v16 = v77->m_enum;
              if ( srcObj.m_impl )
              {
                --srcObj.m_impl->m_externalCount;
                v69 = v78->m_count-- == 1;
                if ( v69 )
                  v78->vfptr->__vecDelDtor((hkDataRefCounted *)&v78->vfptr, 1u);
              }
              ++v9;
            }
            while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
            v19 = (signed int)obj.m_impl;
          }
          if ( v19 > 0 )
            goto LABEL_126;
        }
        goto $LN1_70;
      case 0x1C:
        v84 = ((__int64 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        v85 = *v18;
        LODWORD(srcArray) = v84;
        v19 = 16;
        hkString::memSet(v85, 0, 16 * (unsigned __int16)v84);
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v86 = copyInfoOut;
          do
          {
            v87 = (hkDataObjectImpl *)v8->m_impl->vfptr[21].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9);
            v88 = v87;
            obj.m_impl = v87;
            if ( v87 )
            {
              ++v87->m_externalCount;
              ++v87->m_count;
            }
            hkDataObjectToNative::CopyInfoOut::addVariant(v86, &obj, (hkVariant *)*v18 + v9, owningReference);
            if ( v88 )
            {
              --v88->m_externalCount;
              v69 = v88->m_count-- == 1;
              if ( v69 )
                v88->vfptr->__vecDelDtor((hkDataRefCounted *)&v88->vfptr, 1u);
            }
            ++v9;
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_126;
      case 0x1D:
        v89 = ((__int64 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        v90 = v8->m_impl;
        v19 = 8;
        LOWORD(srcArray) = v89;
        v91 = 0;
        if ( ((signed int (*)(void))v90->vfptr[5].__vecDelDtor)() > 0 )
        {
          v92 = 0;
          LODWORD(obj.m_impl) = 0;
          do
          {
            if ( v16 )
              break;
            v93 = (unsigned __int8)v10->m_subtype.m_storage;
            v94 = (char *)*v18 + v92;
            value.m_impl = v8->m_impl;
            value.m_index = v91;
            v95 = hkDataObjectToNative::fillNativeSimpleMember<hkDataArray_Value>(
                    v111,
                    &v107,
                    v94,
                    v93,
                    &value,
                    0i64,
                    owningReference,
                    copyInfoOut);
            v96 = v8->m_impl;
            v16 = v95->m_enum;
            LODWORD(obj.m_impl) += 8;
            ++v91;
            v97 = ((__int64 (*)(void))v96->vfptr[5].__vecDelDtor)();
            v92 = (int)obj.m_impl;
          }
          while ( v91 < v97 );
        }
        goto LABEL_126;
      case 0x1E:
        v19 = 8;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v41 = 0i64;
          do
          {
            v42 = (__int64)v8->m_impl->vfptr[19].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9++);
            *(_QWORD *)((char *)*v18 + v41) = v42;
            v41 += 8i64;
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 0x20:
        v19 = 2;
        v20 = ((unsigned __int16 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        if ( ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() > 0 )
        {
          v45 = 0i64;
          do
          {
            v8->m_impl->vfptr[15].__vecDelDtor((hkDataRefCounted *)v8->m_impl, v9);
            v46 = (char *)*v18;
            ++v9;
            v45 += 2i64;
            LODWORD(srcArray) = a5;
            *(_WORD *)&v46[v45 - 2] = HIWORD(a5);
          }
          while ( v9 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
        }
        goto LABEL_127;
      case 0x21:
        v98 = ((__int64 (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)();
        v99 = v8->m_impl;
        v19 = 8;
        LOWORD(srcArray) = v98;
        v100 = v99->vfptr;
        LODWORD(obj.m_impl) = 8;
        v101 = 0;
        if ( ((signed int (*)(void))v100[5].__vecDelDtor)() > 0 )
        {
          v102 = 0;
          do
          {
            if ( v16 )
              break;
            v103 = (unsigned __int8)v10->m_subtype.m_storage;
            value.m_impl = v8->m_impl;
            v104 = (char *)*v18 + v102;
            value.m_index = v101;
            v16 = hkDataObjectToNative::fillNativeSimpleMember<hkDataArray_Value>(
                    v111,
                    &v108,
                    v104,
                    v103,
                    &value,
                    0i64,
                    owningReference,
                    copyInfoOut)->m_enum;
            ++v101;
            v102 += 8;
          }
          while ( v101 < ((signed int (*)(void))v8->m_impl->vfptr[5].__vecDelDtor)() );
          v19 = (signed int)obj.m_impl;
        }
LABEL_126:
        LOWORD(v20) = (_WORD)srcArray;
LABEL_127:
        v113[1] = *(_WORD *)v18 - (_WORD)v113;
        *v18 = (char *)*v18 + ((v19 * (unsigned __int16)v20 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
        *v113 = v20;
$LN1_70:
        v14 = v112;
        v112->m_enum = v16;
        break;
      default:
        v12->m_enum = 1;
        v14 = v12;
        break;
    }
  }
  else
  {
    v12->m_enum = 0;
    *v11 = 0;
    v14 = v12;
  }
  return v14;
}

// File Line: 655
// RVA: 0xE62500
hkResult *__fastcall hkDataObjectToNative::fillNativeEnumMember(hkDataObjectToNative *this, hkResult *result, void *address, hkClassMember *member, hkDataObject_Value *value)
{
  int v5; // eax
  hkClassMember *v6; // rdi
  void *v7; // rsi
  hkResult *v8; // rbx
  hkResult *v9; // rax
  int v10; // eax

  v5 = (unsigned __int8)member->m_type.m_storage;
  v6 = member;
  v7 = address;
  v8 = result;
  if ( v5 == 24 || v5 == 31 )
  {
    if ( member->m_enum )
    {
      v10 = (__int64)value->m_impl->vfptr[12].__vecDelDtor(
                       (hkDataRefCounted *)value->m_impl,
                       (unsigned int)value->m_handle);
      hkClassMember::setEnumValue(v6, v7, v10);
    }
    v8->m_enum = 0;
    v9 = v8;
  }
  else
  {
    result->m_enum = 1;
    v9 = result;
  }
  return v9;
}

// File Line: 695
// RVA: 0xE62B30
hkResult *__usercall hkDataObjectToNative::fillNativeSimpleMember<hkDataObject_Value>@<rax>(hkDataObjectToNative *this@<rcx>, hkResult *result@<rdx>, void *address@<r8>, hkClassMember::Type mtype@<r9d>, hkResultEnum a5@<xmm0>, hkDataObject_Value *value, hkClass *structClass, unsigned int owningReference, hkDataObjectToNative::CopyInfoOut *copyInfoOut)
{
  hkVariant *v9; // rdi
  hkResult *v10; // rsi
  hkDataObjectToNative *v11; // rbp
  int v12; // eax
  char v13; // al
  __int16 v14; // ax
  int v15; // eax
  void *v16; // rax
  hkDataObjectImpl *v17; // rax
  hkDataObjectImpl *v18; // rbx
  hkDataObjectImpl *v19; // rax
  hkResult *v20; // rax
  hkDataObjectImpl *v21; // rcx
  bool v22; // bl
  bool v23; // zf
  hkVariant *v24; // rax
  hkVariant *v25; // rax
  hkVariant *v26; // rax
  hkDataObject_Value *v27; // rbx
  const char *v28; // rax
  char *v29; // rax
  char *v30; // rbx
  hkDataObject_Value *v31; // rbx
  const char *v32; // rax
  hkDataObjectImpl *v33; // rax
  hkDataObject srcObj; // [rsp+30h] [rbp-18h]
  hkDataObject obj; // [rsp+38h] [rbp-10h]
  hkResult resulta; // [rsp+68h] [rbp+20h]

  v9 = (hkVariant *)address;
  v10 = result;
  v11 = this;
  switch ( mtype )
  {
    case 1:
      v12 = (__int64)value->m_impl->vfptr[12].__vecDelDtor(
                       (hkDataRefCounted *)value->m_impl,
                       (unsigned int)value->m_handle);
      v10->m_enum = 0;
      LOBYTE(v9->m_object) = v12 != 0;
      return v10;
    case 2:
    case 3:
    case 4:
      v13 = (__int64)value->m_impl->vfptr[12].__vecDelDtor(
                       (hkDataRefCounted *)value->m_impl,
                       (unsigned int)value->m_handle);
      v10->m_enum = 0;
      LOBYTE(v9->m_object) = v13;
      return v10;
    case 5:
    case 6:
      v14 = (__int64)value->m_impl->vfptr[12].__vecDelDtor(
                       (hkDataRefCounted *)value->m_impl,
                       (unsigned int)value->m_handle);
      v10->m_enum = 0;
      LOWORD(v9->m_object) = v14;
      return v10;
    case 7:
    case 8:
      v15 = (__int64)value->m_impl->vfptr[12].__vecDelDtor(
                       (hkDataRefCounted *)value->m_impl,
                       (unsigned int)value->m_handle);
      v10->m_enum = 0;
      LODWORD(v9->m_object) = v15;
      return v10;
    case 9:
    case 10:
    case 30:
      v16 = value->m_impl->vfptr[12].__vecDelDtor((hkDataRefCounted *)value->m_impl, (unsigned int)value->m_handle);
      v10->m_enum = 0;
      v9->m_object = v16;
      return v10;
    case 11:
      value->m_impl->vfptr[15].__vecDelDtor((hkDataRefCounted *)value->m_impl, (unsigned int)value->m_handle);
      v10->m_enum = 0;
      LODWORD(v9->m_object) = a5;
      return v10;
    case 12:
    case 13:
      v24 = (hkVariant *)((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, signed __int64))value->m_impl->vfptr[14].__vecDelDtor)(
                           value->m_impl,
                           value->m_handle,
                           4i64);
      v10->m_enum = 0;
      *v9 = *v24;
      return v10;
    case 14:
    case 15:
    case 16:
      v25 = (hkVariant *)((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, signed __int64))value->m_impl->vfptr[14].__vecDelDtor)(
                           value->m_impl,
                           value->m_handle,
                           12i64);
      v10->m_enum = 0;
      *v9 = *v25;
      v9[1] = v25[1];
      v9[2] = v25[2];
      return v10;
    case 17:
    case 18:
      v26 = (hkVariant *)((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, signed __int64))value->m_impl->vfptr[14].__vecDelDtor)(
                           value->m_impl,
                           value->m_handle,
                           16i64);
      v10->m_enum = 0;
      *v9 = *v26;
      v9[1] = v26[1];
      v9[2] = v26[2];
      v9[3] = v26[3];
      return v10;
    case 20:
      if ( !structClass )
        goto LABEL_41;
      v17 = (hkDataObjectImpl *)value->m_impl->vfptr[13].__vecDelDtor(
                                  (hkDataRefCounted *)value->m_impl,
                                  (unsigned int)value->m_handle);
      v18 = v17;
      obj.m_impl = v17;
      if ( v17 )
      {
        ++v17->m_externalCount;
        ++v17->m_count;
      }
      hkDataObjectToNative::CopyInfoOut::addPointer(copyInfoOut, &obj, v9, owningReference);
      goto LABEL_38;
    case 25:
      if ( !structClass )
        goto LABEL_41;
      v19 = (hkDataObjectImpl *)value->m_impl->vfptr[13].__vecDelDtor(
                                  (hkDataRefCounted *)value->m_impl,
                                  (unsigned int)value->m_handle);
      srcObj.m_impl = v19;
      if ( v19 )
      {
        ++v19->m_externalCount;
        ++v19->m_count;
      }
      v20 = hkDataObjectToNative::fillNativeMembers(v11, &resulta, v9, &srcObj, copyInfoOut);
      v21 = srcObj.m_impl;
      v22 = v20->m_enum == 1;
      if ( srcObj.m_impl )
      {
        --srcObj.m_impl->m_externalCount;
        v23 = v21->m_count-- == 1;
        if ( v23 )
          v21->vfptr->__vecDelDtor((hkDataRefCounted *)&v21->vfptr, 1u);
      }
      if ( !v22 )
        goto LABEL_41;
      v10->m_enum = 1;
      return v10;
    case 28:
      if ( this->m_allocatedOnHeap )
        goto LABEL_42;
      v33 = (hkDataObjectImpl *)value->m_impl->vfptr[13].__vecDelDtor(
                                  (hkDataRefCounted *)value->m_impl,
                                  (unsigned int)value->m_handle);
      v18 = v33;
      obj.m_impl = v33;
      if ( v33 )
      {
        ++v33->m_externalCount;
        ++v33->m_count;
      }
      hkDataObjectToNative::CopyInfoOut::addVariant(copyInfoOut, &obj, v9, owningReference);
LABEL_38:
      if ( v18 )
      {
        --v18->m_externalCount;
        v23 = v18->m_count-- == 1;
        if ( v23 )
          v18->vfptr->__vecDelDtor((hkDataRefCounted *)&v18->vfptr, 1u);
      }
LABEL_41:
      v10->m_enum = 0;
      return v10;
    case 29:
      if ( this->m_allocatedOnHeap )
        goto LABEL_42;
      v27 = value;
      if ( !(__int64)value->m_impl->vfptr[11].__vecDelDtor(
                       (hkDataRefCounted *)value->m_impl,
                       (unsigned int)value->m_handle) )
        goto LABEL_28;
      v28 = (const char *)v27->m_impl->vfptr[11].__vecDelDtor(
                            (hkDataRefCounted *)v27->m_impl,
                            (unsigned int)v27->m_handle);
      v29 = hkString::strDup(v28);
      v30 = v29;
      if ( v29 )
        goto LABEL_27;
      goto LABEL_29;
    case 32:
      value->m_impl->vfptr[15].__vecDelDtor((hkDataRefCounted *)value->m_impl, (unsigned int)value->m_handle);
      v10->m_enum = 0;
      resulta.m_enum = a5;
      LOWORD(v9->m_object) = HIWORD(a5);
      return v10;
    case 33:
      v31 = value;
      if ( !(__int64)value->m_impl->vfptr[11].__vecDelDtor(
                       (hkDataRefCounted *)value->m_impl,
                       (unsigned int)value->m_handle) )
      {
LABEL_28:
        v30 = 0i64;
LABEL_29:
        v9->m_object = v30;
        v10->m_enum = 0;
        return v10;
      }
      v32 = (const char *)v31->m_impl->vfptr[11].__vecDelDtor(
                            (hkDataRefCounted *)v31->m_impl,
                            (unsigned int)v31->m_handle);
      v29 = hkString::strDup(v32);
      v30 = v29;
      if ( !v29 )
        goto LABEL_29;
      if ( v11->m_allocatedOnHeap )
      {
        v10->m_enum = 0;
        v9->m_object = v29 + 1;
      }
      else
      {
LABEL_27:
        hkDataObjectToNative::CopyInfoOut::addAlloc(copyInfoOut, v29, -1);
        v9->m_object = v30;
        v10->m_enum = 0;
      }
      return v10;
    default:
LABEL_42:
      result->m_enum = 1;
      return v10;
  }
}  v10->m_enum = 0;
      }
      return v10;
    default:
LABEL_42:
      result->m_enum = 1;
      return v10;
  }
}

// File Line: 839
// RVA: 0xE5FDF0
hkResult *__fastcall hkDataObjectToNative::fillNativeMembers(hkDataObjectToNative *this, hkResult *result, void *dstObject, hkDataObject *srcObj, hkDataObjectToNative::CopyInfoOut *copyInfoOut)
{
  char *v5; // rsi
  hkResultEnum v6; // edi
  hkClass *v7; // rax
  hkClass *v8; // rbx
  __int64 v9; // rcx
  hkClass *v10; // rax
  int v11; // ebx
  hkClassMember *v12; // rax
  __int64 v13; // rbx
  hkClassMember *v14; // rsi
  char *v15; // rbx
  const char *v16; // r8
  hkDataObjectImpl *v17; // rcx
  int v18; // ebx
  const char *v19; // rax
  int v20; // eax
  int v21; // er8
  int v22; // eax
  unsigned int v23; // edx
  int v24; // edx
  hkClass *structClass; // rax
  hkDataArrayImpl *v26; // rax
  hkDataArrayImpl *v27; // rbx
  hkDataRefCountedVtbl *v28; // rax
  int v29; // ecx
  hkClass *v30; // rax
  hkResult *v31; // rax
  int v32; // eax
  hkDataArrayImpl *v33; // rax
  hkResult *v34; // rax
  hkDataArrayImpl *v35; // rcx
  bool v36; // zf
  hkDataRefCountedVtbl *v37; // rax
  hkDataArrayImpl *v38; // rax
  char v39; // al
  hkDataArrayImpl *v40; // rax
  int v41; // esi
  int v42; // eax
  int v43; // eax
  bool v44; // sf
  unsigned __int8 v45; // of
  hkDataRefCountedVtbl *v46; // rax
  hkDataArrayImpl *v47; // rax
  hkClass *v48; // rax
  __int64 v49; // rax
  hkDataArrayImpl *v50; // rsi
  __int64 v51; // rax
  int v52; // ebx
  hkDataObjectImpl *v53; // rax
  hkDataObjectImpl *v54; // rbx
  hkClass *v55; // rax
  hkDataRefCountedVtbl *v56; // rax
  hkDataArrayImpl *v57; // rax
  hkDataObjectImpl *v58; // rax
  hkDataObjectImpl *v59; // rsi
  hkClass *v60; // rax
  int v61; // eax
  _DWORD *v62; // rsi
  hkClass *v63; // rcx
  int v64; // eax
  __int64 v65; // rcx
  void *v66; // rax
  void **v67; // rsi
  int v68; // er8
  signed int v69; // esi
  hkDataObjectImpl *v70; // rax
  hkResult *v71; // rax
  hkDataObjectImpl *v72; // rcx
  hkResult *v73; // rax
  int n; // [rsp+40h] [rbp-C0h]
  int v75; // [rsp+44h] [rbp-BCh]
  int v76; // [rsp+48h] [rbp-B8h]
  hkClassMember::Type mtype; // [rsp+4Ch] [rbp-B4h]
  void *dst; // [rsp+50h] [rbp-B0h]
  unsigned int owningReference; // [rsp+58h] [rbp-A8h]
  hkDataObject_Value value; // [rsp+60h] [rbp-A0h]
  int declaredIndex; // [rsp+70h] [rbp-90h]
  hkClass *klass; // [rsp+78h] [rbp-88h]
  hkDataArray v83; // [rsp+80h] [rbp-80h]
  hkDataObject v84; // [rsp+88h] [rbp-78h]
  hkDataObject obj; // [rsp+90h] [rbp-70h]
  hkDataArray srcArray; // [rsp+98h] [rbp-68h]
  hkResult v87; // [rsp+A0h] [rbp-60h]
  hkResult v88; // [rsp+A4h] [rbp-5Ch]
  void *relArrayAddress; // [rsp+A8h] [rbp-58h]
  hkResult v90; // [rsp+B0h] [rbp-50h]
  hkResult v91; // [rsp+B4h] [rbp-4Ch]
  hkResult v92; // [rsp+B8h] [rbp-48h]
  hkResult resulta; // [rsp+BCh] [rbp-44h]
  hkResult v94; // [rsp+C0h] [rbp-40h]
  hkResult v95; // [rsp+C4h] [rbp-3Ch]
  hkResult v96; // [rsp+C8h] [rbp-38h]
  hkResult v97; // [rsp+CCh] [rbp-34h]
  hkDataArray_Value v98; // [rsp+D0h] [rbp-30h]
  hkDataArray_Value v99; // [rsp+E0h] [rbp-20h]
  hkDataArray_Value v100; // [rsp+F0h] [rbp-10h]
  __int64 v101; // [rsp+100h] [rbp+0h]
  __int64 v102; // [rsp+108h] [rbp+8h]
  __int64 v103; // [rsp+110h] [rbp+10h]
  __int64 v104; // [rsp+118h] [rbp+18h]
  hkDataObjectToNative *v105; // [rsp+150h] [rbp+50h]
  hkResult *v106; // [rsp+158h] [rbp+58h]
  char *objectStart; // [rsp+160h] [rbp+60h]
  hkDataObject *v108; // [rsp+168h] [rbp+68h]

  v108 = srcObj;
  objectStart = (char *)dstObject;
  v106 = result;
  v105 = this;
  v5 = (char *)dstObject;
  v6 = 0;
  v7 = hkDataObjectToNative::findClassOf(this, srcObj);
  v8 = v7;
  klass = v7;
  hkClass::getObjectSize(v7);
  v9 = (signed int)((unsigned __int64)hkClass::getObjectSize(v8) + 15);
  v10 = v8;
  relArrayAddress = &v5[v9 & 0xFFFFFFFFFFFFFFF0ui64];
  if ( !v8 )
  {
LABEL_98:
    v73 = v106;
    v106->m_enum = v6;
    return v73;
  }
  while ( 1 )
  {
    v11 = 0;
    declaredIndex = 0;
    if ( (signed int)hkClass::getNumDeclaredMembers(v10) > 0 )
      break;
LABEL_97:
    v10 = hkClass::getParent(klass);
    klass = v10;
    if ( !v10 )
      goto LABEL_98;
  }
  while ( 1 )
  {
    v12 = hkClass::getDeclaredMember(klass, v11);
    v13 = v12->m_offset;
    v14 = v12;
    v83.m_impl = (hkDataArrayImpl *)v12;
    v15 = &objectStart[v13];
    v16 = v12->m_name;
    mtype = (unsigned __int8)v12->m_type.m_storage;
    dst = v15;
    ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, const char *))v108->m_impl->vfptr[3].__vecDelDtor)(
      v108->m_impl,
      &value,
      v16);
    v17 = value.m_impl;
    if ( value.m_impl )
    {
      if ( value.m_impl->vfptr[26].__vecDelDtor((hkDataRefCounted *)value.m_impl, (unsigned int)value.m_handle) )
        goto LABEL_17;
      v17 = value.m_impl;
    }
    v101 = 0i64;
    v102 = 0i64;
    v103 = 0i64;
    v104 = 0i64;
    if ( v17 )
      ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64 *))v17->vfptr[25].__vecDelDtor)(
        v17,
        value.m_handle,
        &v101);
    if ( v14->m_type.m_storage == 22 )
      *((_DWORD *)v15 + 3) = 2147483648;
    if ( !(unsigned int)hkClass::hasDeclaredDefault(klass, declaredIndex)
      || !((unsigned int (*)(void))v108->m_impl->vfptr[27].__vecDelDtor)() )
    {
      break;
    }
    v18 = hkClassMember::getSizeInBytes(v14);
    v19 = hkClass::getDeclaredDefault(klass, declaredIndex);
    hkString::memCpy(dst, v19, v18);
LABEL_96:
    v11 = ++declaredIndex;
    if ( v11 >= (signed int)hkClass::getNumDeclaredMembers(klass) )
      goto LABEL_97;
  }
  if ( (!value.m_impl || !v104) && (mtype != 25 || v14->m_flags.m_storage & 0x400) )
    goto LABEL_96;
LABEL_17:
  if ( (unsigned int)hkClassMember::getCstyleArraySize(v14) )
  {
    v75 = hkClassMember::getCstyleArraySize(v14);
    v20 = hkClassMember::getSizeInBytes(v14);
    v21 = v75;
    v22 = v20 / v75;
  }
  else
  {
    v75 = 1;
    v22 = hkClassMember::getSizeInBytes(v14);
    v21 = v75;
  }
  v23 = v14->m_flags.m_storage;
  v76 = v22;
  LOWORD(v23) = ~(_WORD)v23;
  v24 = (v23 >> 9) & 1;
  owningReference = v24;
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
      if ( v21 == 1 )
      {
        structClass = hkClassMember::getClass(v14);
        v6 = hkDataObjectToNative::fillNativeSimpleMember<hkDataObject_Value>(
               v105,
               &resulta,
               v15,
               mtype,
               &value,
               structClass,
               owningReference,
               copyInfoOut)->m_enum;
        goto LABEL_95;
      }
      v26 = (hkDataArrayImpl *)value.m_impl->vfptr[10].__vecDelDtor(
                                 (hkDataRefCounted *)value.m_impl,
                                 (unsigned int)value.m_handle);
      v27 = v26;
      if ( v26 )
      {
        ++v26->m_externalCount;
        ++v26->m_count;
      }
      v28 = v26->vfptr;
      v75 = 0;
      if ( ((signed int (__fastcall *)(hkDataArrayImpl *))v28[5].__vecDelDtor)(v27) > 0 )
      {
        v29 = v75;
        n = 0;
        do
        {
          if ( v6 )
            break;
          v98.m_index = v29;
          v98.m_impl = v27;
          v30 = hkClassMember::getClass(v14);
          v31 = hkDataObjectToNative::fillNativeSimpleMember<hkDataArray_Value>(
                  v105,
                  &v96,
                  (char *)dst + n,
                  mtype,
                  &v98,
                  v30,
                  owningReference,
                  copyInfoOut);
          ++v75;
          v6 = v31->m_enum;
          n += v76;
          v32 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v27->vfptr[5].__vecDelDtor)(v27);
          v29 = v75;
        }
        while ( v75 < v32 );
      }
      goto LABEL_92;
    case 20:
      v39 = v14->m_subtype.m_storage;
      if ( v39 == 2 )
      {
        if ( v21 == 1 )
        {
          v6 = hkDataObjectToNative::fillNativeSimpleMember<hkDataObject_Value>(
                 v105,
                 &v94,
                 v15,
                 (hkClassMember::Type)29,
                 &value,
                 0i64,
                 v24,
                 copyInfoOut)->m_enum;
          goto LABEL_95;
        }
        v40 = (hkDataArrayImpl *)value.m_impl->vfptr[10].__vecDelDtor(
                                   (hkDataRefCounted *)value.m_impl,
                                   (unsigned int)value.m_handle);
        v27 = v40;
        if ( v40 )
        {
          ++v40->m_externalCount;
          ++v40->m_count;
        }
        v41 = 0;
        if ( ((signed int (__fastcall *)(hkDataArrayImpl *))v40->vfptr[5].__vecDelDtor)(v40) > 0 )
        {
          v42 = 0;
          n = 0;
          do
          {
            if ( v6 )
              break;
            v100.m_impl = v27;
            v100.m_index = v41;
            v6 = hkDataObjectToNative::fillNativeSimpleMember<hkDataArray_Value>(
                   v105,
                   &v88,
                   (char *)dst + v42,
                   (hkClassMember::Type)29,
                   &v100,
                   0i64,
                   owningReference,
                   copyInfoOut)->m_enum;
            n += v76;
            ++v41;
            v43 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v27->vfptr[5].__vecDelDtor)(v27);
            v45 = __OFSUB__(v41, v43);
            v44 = v41 - v43 < 0;
            v42 = n;
          }
          while ( v44 ^ v45 );
        }
LABEL_92:
        --v27->m_externalCount;
        v36 = v27->m_count-- == 1;
        if ( !v36 )
          goto LABEL_95;
        v37 = v27->vfptr;
        v35 = v27;
LABEL_94:
        v37->__vecDelDtor((hkDataRefCounted *)&v35->vfptr, 1u);
        goto LABEL_95;
      }
      if ( v39 != 25 )
        goto LABEL_95;
      v46 = value.m_impl->vfptr;
      if ( v21 == 1 )
      {
        v47 = (hkDataArrayImpl *)v46[13].__vecDelDtor(
                                   (hkDataRefCounted *)&value.m_impl->vfptr,
                                   (unsigned int)value.m_handle);
        v27 = v47;
        v83.m_impl = v47;
        if ( v47 )
        {
          ++v47->m_externalCount;
          ++v47->m_count;
        }
        v48 = hkDataObjectToNative::getMemberClassAndCheck(v105, v14, (hkDataObject *)&v83);
        v6 = hkDataObjectToNative::fillNativeSimpleMember<hkDataObject_Value>(
               v105,
               &v91,
               dst,
               mtype,
               &value,
               v48,
               owningReference,
               copyInfoOut)->m_enum;
        if ( v27 )
          goto LABEL_92;
      }
      else
      {
        v49 = (__int64)v46[10].__vecDelDtor((hkDataRefCounted *)&value.m_impl->vfptr, (unsigned int)value.m_handle);
        v50 = (hkDataArrayImpl *)v49;
        if ( v49 )
        {
          ++*(_WORD *)(v49 + 10);
          ++*(_DWORD *)(v49 + 12);
        }
        v51 = *(_QWORD *)v49;
        v52 = 0;
        n = 0;
        if ( (*(signed int (__fastcall **)(hkDataArrayImpl *))(v51 + 40))(v50) > 0 )
        {
          v75 = 0;
          do
          {
            if ( v6 )
              break;
            v53 = (hkDataObjectImpl *)v50->vfptr[21].__vecDelDtor((hkDataRefCounted *)&v50->vfptr, v52);
            v54 = v53;
            v84.m_impl = v53;
            if ( v53 )
            {
              ++v53->m_externalCount;
              ++v53->m_count;
            }
            v99.m_index = n;
            v99.m_impl = v50;
            v55 = hkDataObjectToNative::getMemberClassAndCheck(v105, (hkClassMember *)v83.m_impl, &v84);
            v6 = hkDataObjectToNative::fillNativeSimpleMember<hkDataArray_Value>(
                   v105,
                   &v87,
                   (char *)dst + v75,
                   mtype,
                   &v99,
                   v55,
                   owningReference,
                   copyInfoOut)->m_enum;
            if ( v54 )
            {
              --v54->m_externalCount;
              v36 = v54->m_count-- == 1;
              if ( v36 )
                v54->vfptr->__vecDelDtor((hkDataRefCounted *)&v54->vfptr, 1u);
            }
            v75 += v76;
            v56 = v50->vfptr;
            v52 = ++n;
          }
          while ( v52 < ((signed int (__fastcall *)(hkDataArrayImpl *))v56[5].__vecDelDtor)(v50) );
        }
        --v50->m_externalCount;
        v36 = v50->m_count-- == 1;
        if ( v36 )
        {
          v37 = v50->vfptr;
          v35 = v50;
          goto LABEL_94;
        }
      }
LABEL_95:
      if ( v6 != 1 )
        goto LABEL_96;
LABEL_99:
      v73 = v106;
      v106->m_enum = 1;
      break;
    case 22:
    case 26:
      if ( v105->m_allocatedOnHeap
        && (v14->m_type.m_storage == 26 || (unsigned __int8)(v14->m_subtype.m_storage - 28) <= 1u) )
      {
        goto LABEL_99;
      }
      v33 = (hkDataArrayImpl *)value.m_impl->vfptr[10].__vecDelDtor(
                                 (hkDataRefCounted *)value.m_impl,
                                 (unsigned int)value.m_handle);
      srcArray.m_impl = v33;
      if ( v33 )
      {
        ++v33->m_externalCount;
        ++v33->m_count;
      }
      v34 = hkDataObjectToNative::copyIntoNativeArray(v105, &v92, v15, v14, &srcArray, copyInfoOut);
      v35 = srcArray.m_impl;
      v6 = v34->m_enum;
      if ( !srcArray.m_impl )
        goto LABEL_95;
      --srcArray.m_impl->m_externalCount;
      v36 = v35->m_count-- == 1;
      if ( !v36 )
        goto LABEL_95;
      v37 = v35->vfptr;
      goto LABEL_94;
    case 24:
    case 31:
      v6 = hkDataObjectToNative::fillNativeEnumMember(v105, &v97, v15, v14, &value, klass)->m_enum;
      goto LABEL_95;
    case 27:
      if ( v105->m_allocatedOnHeap )
        goto LABEL_99;
      v57 = (hkDataArrayImpl *)value.m_impl->vfptr[10].__vecDelDtor(
                                 (hkDataRefCounted *)value.m_impl,
                                 (unsigned int)value.m_handle);
      v27 = v57;
      if ( v57 )
      {
        ++v57->m_externalCount;
        ++v57->m_count;
      }
      v58 = (hkDataObjectImpl *)v57->vfptr[21].__vecDelDtor((hkDataRefCounted *)&v57->vfptr, 0);
      v59 = v58;
      v84.m_impl = v58;
      if ( v58 )
      {
        ++v58->m_externalCount;
        ++v58->m_count;
      }
      v60 = hkDataObjectToNative::getMemberClassAndCheck(v105, (hkClassMember *)v83.m_impl, &v84);
      *(_QWORD *)dst = v60;
      if ( v59 )
      {
        --v59->m_externalCount;
        v36 = v59->m_count-- == 1;
        if ( v36 )
          v59->vfptr->__vecDelDtor((hkDataRefCounted *)&v59->vfptr, 1u);
      }
      v61 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v27->vfptr[5].__vecDelDtor)(v27);
      v62 = dst;
      v63 = *(hkClass **)dst;
      *((_DWORD *)dst + 4) = v61;
      v64 = hkClass::getObjectSize(v63);
      LODWORD(v62) = v64 * v62[4];
      v76 = v64;
      v65 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
      n = (signed int)v62;
      v66 = (void *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v65 + 24i64))(v65, &n);
      v67 = (void **)dst;
      v68 = n;
      *((_QWORD *)dst + 1) = v66;
      hkString::memSet(v66, 0, v68);
      hkDataObjectToNative::CopyInfoOut::addAlloc(copyInfoOut, v67[1], v76 * *((_DWORD *)v67 + 4));
      v69 = 0;
      if ( *((_DWORD *)dst + 4) > 0 )
      {
        n = 0;
        do
        {
          if ( v6 )
            break;
          v70 = (hkDataObjectImpl *)v27->vfptr[21].__vecDelDtor((hkDataRefCounted *)&v27->vfptr, v69);
          obj.m_impl = v70;
          if ( v70 )
          {
            ++v70->m_externalCount;
            ++v70->m_count;
          }
          v71 = hkDataObjectToNative::fillNativeMembers(
                  v105,
                  &v90,
                  (void *)(*((_QWORD *)dst + 1) + n),
                  &obj,
                  copyInfoOut);
          v72 = obj.m_impl;
          v6 = v71->m_enum;
          if ( obj.m_impl )
          {
            --obj.m_impl->m_externalCount;
            v36 = v72->m_count-- == 1;
            if ( v36 )
              v72->vfptr->__vecDelDtor((hkDataRefCounted *)&v72->vfptr, 1u);
          }
          ++v69;
          n += v76;
        }
        while ( v69 < *((_DWORD *)dst + 4) );
      }
      goto LABEL_92;
    case 34:
      if ( v105->m_allocatedOnHeap
        && (v14->m_type.m_storage == 26 || (unsigned __int8)(v14->m_subtype.m_storage - 28) <= 1u) )
      {
        goto LABEL_99;
      }
      v38 = (hkDataArrayImpl *)value.m_impl->vfptr[10].__vecDelDtor(
                                 (hkDataRefCounted *)value.m_impl,
                                 (unsigned int)value.m_handle);
      v27 = v38;
      v83.m_impl = v38;
      if ( v38 )
      {
        ++v38->m_externalCount;
        ++v38->m_count;
      }
      v6 = hkDataObjectToNative::copyIntoRelArray(
             v105,
             &v95,
             dst,
             v14,
             &v83,
             copyInfoOut,
             &relArrayAddress,
             objectStart)->m_enum;
      if ( v27 )
        goto LABEL_92;
      goto LABEL_95;
    default:
      goto LABEL_99;
  }
  return v73;
}

// File Line: 1077
// RVA: 0xE62590
hkClass *__fastcall hkDataObjectToNative::getMemberClassAndCheck(hkDataObjectToNative *this, hkClassMember *member, hkDataObject *obj)
{
  hkDataObject *v3; // rbx
  hkClassMember *v4; // rbp
  hkDataObjectToNative *v5; // r14
  hkClass *v6; // rax
  hkClass *v7; // rdi
  __int64 v8; // rax
  __int64 v9; // rax
  const char *v10; // rsi
  hkClass *v11; // rbx
  const char *v12; // rax
  hkVariant *v13; // rax
  bool v14; // zf
  hkBool result; // [rsp+50h] [rbp+18h]

  v3 = obj;
  v4 = member;
  v5 = this;
  if ( !obj->m_impl )
    return 0i64;
  v7 = hkClassMember::getClass(member);
  v8 = ((__int64 (*)(void))v3->m_impl->vfptr[2].__vecDelDtor)();
  v9 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 16i64))(v8);
  v10 = (const char *)v9;
  if ( v9 )
    v11 = (hkClass *)v5->m_classReg->vfptr[2].__vecDelDtor((hkBaseObject *)&v5->m_classReg->vfptr, v9);
  else
    v11 = 0i64;
  if ( !v7 )
    return v11;
  if ( !v11 )
    return 0i64;
  v12 = hkClass::getName(v7);
  if ( !(unsigned int)hkString::strCmp(v12, v10) )
    return v7;
  if ( hkClass::isSuperClass(v7, &result, v11)->m_bool )
    return v11;
  v13 = hkClassMember::getAttribute(v4, "hk.DataObjectType");
  if ( !v13 )
    return v7;
  v7 = (hkClass *)v5->m_classReg->vfptr[2].__vecDelDtor((hkBaseObject *)v5->m_classReg, *(_QWORD *)v13->m_object);
  v14 = hkClass::isSuperClass(v7, &result, v11)->m_bool == 0;
  v6 = v11;
  if ( v14 )
    return v7;
  return v6;
}

