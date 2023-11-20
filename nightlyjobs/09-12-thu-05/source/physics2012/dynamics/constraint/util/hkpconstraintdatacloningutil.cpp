// File Line: 40
// RVA: 0xD8E110
hkpConstraintData *__fastcall hkpConstraintDataCloningUtil::deepClone(hkpConstraintData *data)
{
  hkpConstraintData *v1; // rdi
  int v2; // eax
  hkpConstraintData *v4; // rax
  hkpConstraintData *v5; // rsi
  _QWORD **v6; // rax
  hkpMalleableConstraintData *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rbx
  hkpConstraintData *v10; // rsi
  _QWORD **v11; // rax
  hkpBreakableConstraintData *v12; // rax
  __int64 v13; // rax

  v1 = data;
  v2 = (unsigned __int64)((__int64 (*)(void))data->vfptr[1].__first_virtual_table_function__)() - 12;
  if ( !v2 )
  {
    v10 = hkpConstraintDataCloningUtil::deepClone((hkpConstraintData *)v1[2].m_userData);
    if ( v10 )
    {
      v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (hkpBreakableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(
                                            v11[11],
                                            96i64);
      if ( v12 )
      {
        hkpBreakableConstraintData::hkpBreakableConstraintData(v12, v10);
        v9 = v13;
      }
      else
      {
        v9 = 0i64;
      }
      hkReferencedObject::removeReference((hkReferencedObject *)&v10->vfptr);
      *(_DWORD *)(v9 + 76) = HIDWORD(v1[3].vfptr);
      *(_BYTE *)(v9 + 80) = v1[3].m_memSizeAndFlags;
      *(_BYTE *)(v9 + 81) = HIBYTE(v1[3].m_memSizeAndFlags);
      goto LABEL_14;
    }
    return 0i64;
  }
  if ( v2 != 1 )
    return hkpConstraintDataUtils::deepClone(v1);
  v4 = hkpMalleableConstraintData::getWrappedConstraintData((hkpMalleableConstraintData *)v1);
  v5 = hkpConstraintDataCloningUtil::deepClone(v4);
  if ( !v5 )
    return 0i64;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpMalleableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(
                                       v6[11],
                                       80i64);
  if ( v7 )
  {
    hkpMalleableConstraintData::hkpMalleableConstraintData(v7, v5);
    v9 = v8;
    hkReferencedObject::removeReference((hkReferencedObject *)&v5->vfptr);
    *(_DWORD *)(v9 + 64) = v1[2].m_userData;
  }
  else
  {
    v9 = 0i64;
    hkReferencedObject::removeReference((hkReferencedObject *)&v5->vfptr);
    MEMORY[0x40] = v1[2].m_userData;
  }
LABEL_14:
  *(_QWORD *)(v9 + 16) = v1->m_userData;
  return (hkpConstraintData *)v9;
}

