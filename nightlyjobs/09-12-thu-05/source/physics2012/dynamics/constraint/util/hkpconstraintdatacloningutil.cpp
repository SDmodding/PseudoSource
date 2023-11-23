// File Line: 40
// RVA: 0xD8E110
hkpConstraintData *__fastcall hkpConstraintDataCloningUtil::deepClone(hkpMalleableConstraintData *data)
{
  int v2; // eax
  hkpConstraintData *WrappedConstraintData; // rax
  hkpConstraintData *v5; // rsi
  _QWORD **v6; // rax
  hkpMalleableConstraintData *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rbx
  hkpConstraintData *v10; // rsi
  _QWORD **Value; // rax
  hkpBreakableConstraintData *v12; // rax
  __int64 v13; // rax

  v2 = ((__int64 (__fastcall *)(hkpMalleableConstraintData *))data->vfptr[1].__first_virtual_table_function__)(data)
     - 12;
  if ( !v2 )
  {
    v10 = hkpConstraintDataCloningUtil::deepClone(*(hkpConstraintData **)&data->m_strength);
    if ( v10 )
    {
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (hkpBreakableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                            Value[11],
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
      hkReferencedObject::removeReference(v10);
      *(_DWORD *)(v9 + 76) = *((_DWORD *)&data->m_strength + 3);
      *(_BYTE *)(v9 + 80) = data[1].vfptr;
      *(_BYTE *)(v9 + 81) = BYTE1(data[1].vfptr);
      goto LABEL_14;
    }
    return 0i64;
  }
  if ( v2 != 1 )
    return hkpConstraintDataUtils::deepClone(data);
  WrappedConstraintData = hkpMalleableConstraintData::getWrappedConstraintData(data);
  v5 = hkpConstraintDataCloningUtil::deepClone(WrappedConstraintData);
  if ( !v5 )
    return 0i64;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkpMalleableConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v6[11] + 8i64))(v6[11], 80i64);
  if ( v7 )
  {
    hkpMalleableConstraintData::hkpMalleableConstraintData(v7, v5);
    v9 = v8;
    hkReferencedObject::removeReference(v5);
    *(float *)(v9 + 64) = data->m_strength;
  }
  else
  {
    v9 = 0i64;
    hkReferencedObject::removeReference(v5);
    MEMORY[0x40] = LODWORD(data->m_strength);
  }
LABEL_14:
  *(_QWORD *)(v9 + 16) = data->m_userData;
  return (hkpConstraintData *)v9;
}

