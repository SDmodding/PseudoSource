// File Line: 18
// RVA: 0xE5F710
void __fastcall hkDataObjectImpl::assignValueImpl(hkDataObjectImpl *dstObj, const struct _hkDataObject_MemberHandle *handle, hkDataObject_Value *valueIn)
{
  hkDataObjectImpl *v3; // rsi
  hkDataObject_Value *v4; // rdi
  const struct _hkDataObject_MemberHandle *v5; // rbp
  hkTypeManager::Type *v6; // rcx
  __int64 v7; // rax
  __int64 v8; // rbx
  bool v9; // zf
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // ebx
  __int64 v13; // rax
  __int64 v14; // rax

  v3 = dstObj;
  v4 = valueIn;
  v5 = handle;
  v6 = hkDataObject_Value::getType(valueIn);
  switch ( v6->m_subType )
  {
    case 2:
    case 4:
      v10 = (__int64)v4->m_impl->vfptr[12].__vecDelDtor((hkDataRefCounted *)v4->m_impl, (unsigned int)v4->m_handle);
      ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, _QWORD))v3->vfptr[17].__vecDelDtor)(
        v3,
        v5,
        v10);
      break;
    case 3:
      v4->m_impl->vfptr[15].__vecDelDtor((hkDataRefCounted *)v4->m_impl, (unsigned int)v4->m_handle);
      v3->vfptr[20].__vecDelDtor((hkDataRefCounted *)&v3->vfptr, (unsigned int)v5);
      break;
    case 5:
      v14 = (__int64)v4->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v4->m_impl, (unsigned int)v4->m_handle);
      ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64))v3->vfptr[21].__vecDelDtor)(
        v3,
        v5,
        v14);
      break;
    case 6:
    case 7:
      v7 = (__int64)v4->m_impl->vfptr[13].__vecDelDtor((hkDataRefCounted *)v4->m_impl, (unsigned int)v4->m_handle);
      v8 = v7;
      if ( v7 )
      {
        ++*(_WORD *)(v7 + 10);
        ++*(_DWORD *)(v7 + 12);
      }
      ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64))v3->vfptr[23].__vecDelDtor)(
        v3,
        v5,
        v7);
      if ( v8 )
      {
        --*(_WORD *)(v8 + 10);
        v9 = (*(_DWORD *)(v8 + 12))-- == 1;
        if ( v9 )
          (**(void (__fastcall ***)(__int64, signed __int64))v8)(v8, 1i64);
      }
      break;
    case 9:
      if ( v6->m_parent->m_subType == 3 )
      {
        v11 = hkTypeManager::Type::getTupleSize(v6);
        v12 = v11;
        v13 = ((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, _QWORD))v4->m_impl->vfptr[14].__vecDelDtor)(
                v4->m_impl,
                v4->m_handle,
                v11);
        ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64, _QWORD))v3->vfptr[18].__vecDelDtor)(
          v3,
          v5,
          v13,
          v12);
      }
      break;
    default:
      return;
  }
}

// File Line: 70
// RVA: 0xE5F550
void __fastcall hkDataArrayImpl::set(hkDataArrayImpl *this, int index, hkDataObject_Value *val)
{
  hkDataObject_Value *v3; // rbx
  unsigned int v4; // esi
  hkDataArrayImpl *v5; // rdi
  __int64 v6; // rax
  __int64 v7; // rbp
  unsigned int v8; // eax
  __int64 v9; // rax
  __int64 v10; // rbx
  bool v11; // zf
  __int64 v12; // rax
  __int64 v13; // rax
  unsigned int v14; // eax
  __int64 v15; // rax

  v3 = val;
  v4 = index;
  v5 = this;
  v6 = ((__int64 (*)(void))this->vfptr[1].__vecDelDtor)();
  v7 = v6;
  if ( *(_DWORD *)v6 == 9 && **(_DWORD **)(v6 + 8) != 3 )
  {
$LN4_209:
    v13 = (__int64)v3->m_impl->vfptr[10].__vecDelDtor((hkDataRefCounted *)v3->m_impl, (unsigned int)v3->m_handle);
    v10 = v13;
    if ( v13 )
    {
      ++*(_WORD *)(v13 + 10);
      ++*(_DWORD *)(v13 + 12);
    }
    ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v5->vfptr[24].__vecDelDtor)(v5, v4, v13);
LABEL_9:
    if ( v10 )
    {
      --*(_WORD *)(v10 + 10);
      v11 = (*(_DWORD *)(v10 + 12))-- == 1;
      if ( v11 )
        (**(void (__fastcall ***)(__int64, signed __int64))v10)(v10, 1i64);
    }
  }
  else
  {
    switch ( *(_DWORD *)((__int64 (__fastcall *)(hkDataArrayImpl *))v5->vfptr[1].__vecDelDtor)(v5) )
    {
      case 2:
      case 4:
        v8 = (__int64)v3->m_impl->vfptr[12].__vecDelDtor((hkDataRefCounted *)v3->m_impl, (unsigned int)v3->m_handle);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))v5->vfptr[18].__vecDelDtor)(v5, v4, v8);
        return;
      case 3:
        v3->m_impl->vfptr[15].__vecDelDtor((hkDataRefCounted *)v3->m_impl, (unsigned int)v3->m_handle);
        v5->vfptr[16].__vecDelDtor((hkDataRefCounted *)&v5->vfptr, v4);
        return;
      case 5:
        v12 = (__int64)v3->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v3->m_impl, (unsigned int)v3->m_handle);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v5->vfptr[14].__vecDelDtor)(v5, v4, v12);
        return;
      case 6:
      case 7:
        v9 = (__int64)v3->m_impl->vfptr[13].__vecDelDtor((hkDataRefCounted *)v3->m_impl, (unsigned int)v3->m_handle);
        v10 = v9;
        if ( v9 )
        {
          ++*(_WORD *)(v9 + 10);
          ++*(_DWORD *)(v9 + 12);
        }
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v5->vfptr[22].__vecDelDtor)(v5, v4, v9);
        goto LABEL_9;
      case 8:
        goto $LN4_209;
      case 9:
        if ( **(_DWORD **)(v7 + 8) == 3 )
        {
          v14 = hkTypeManager::Type::getTupleSize((hkTypeManager::Type *)v7);
          v15 = ((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, _QWORD))v3->m_impl->vfptr[14].__vecDelDtor)(
                  v3->m_impl,
                  v3->m_handle,
                  v14);
          ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v5->vfptr[12].__vecDelDtor)(v5, v4, v15);
        }
        break;
      default:
        return;
    }
  }
}

