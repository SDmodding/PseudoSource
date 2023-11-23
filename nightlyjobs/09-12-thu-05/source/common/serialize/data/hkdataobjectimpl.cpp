// File Line: 18
// RVA: 0xE5F710
void __fastcall hkDataObjectImpl::assignValueImpl(
        hkDataObjectImpl *dstObj,
        const struct _hkDataObject_MemberHandle *handle,
        hkDataObject_Value *valueIn)
{
  hkTypeManager::Type *Type; // rcx
  _WORD *v7; // rax
  _WORD *v8; // rbx
  unsigned int v10; // eax
  __int64 TupleSize; // rbx
  __int64 v12; // rax
  void *v13; // rax

  Type = hkDataObject_Value::getType(valueIn);
  switch ( Type->m_subType )
  {
    case SUB_TYPE_BYTE:
    case SUB_TYPE_INT:
      v10 = (unsigned int)valueIn->m_impl->vfptr[12].__vecDelDtor(valueIn->m_impl, valueIn->m_handle);
      ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, _QWORD))dstObj->vfptr[17].__vecDelDtor)(
        dstObj,
        handle,
        v10);
      break;
    case SUB_TYPE_REAL:
      valueIn->m_impl->vfptr[15].__vecDelDtor(valueIn->m_impl, (unsigned int)valueIn->m_handle);
      dstObj->vfptr[20].__vecDelDtor(dstObj, (unsigned int)handle);
      break;
    case SUB_TYPE_CSTRING:
      v13 = valueIn->m_impl->vfptr[11].__vecDelDtor(valueIn->m_impl, valueIn->m_handle);
      ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, void *))dstObj->vfptr[21].__vecDelDtor)(
        dstObj,
        handle,
        v13);
      break;
    case SUB_TYPE_CLASS:
    case SUB_TYPE_POINTER:
      v7 = valueIn->m_impl->vfptr[13].__vecDelDtor(valueIn->m_impl, valueIn->m_handle);
      v8 = v7;
      if ( v7 )
      {
        ++v7[5];
        ++*((_DWORD *)v7 + 3);
      }
      ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, _WORD *))dstObj->vfptr[23].__vecDelDtor)(
        dstObj,
        handle,
        v7);
      if ( v8 )
      {
        --v8[5];
        if ( (*((_DWORD *)v8 + 3))-- == 1 )
          (**(void (__fastcall ***)(_WORD *, __int64))v8)(v8, 1i64);
      }
      break;
    case SUB_TYPE_TUPLE:
      if ( Type->m_parent->m_subType == SUB_TYPE_REAL )
      {
        TupleSize = (unsigned int)hkTypeManager::Type::getTupleSize(Type);
        v12 = ((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64))valueIn->m_impl->vfptr[14].__vecDelDtor)(
                valueIn->m_impl,
                valueIn->m_handle,
                TupleSize);
        ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64, _QWORD))dstObj->vfptr[18].__vecDelDtor)(
          dstObj,
          handle,
          v12,
          (unsigned int)TupleSize);
      }
      break;
    default:
      return;
  }
}

// File Line: 70
// RVA: 0xE5F550
void __fastcall hkDataArrayImpl::set(hkDataArrayImpl *this, unsigned int index, hkDataObject_Value *val)
{
  __int64 v6; // rax
  __int64 v7; // rbp
  unsigned int v8; // eax
  _WORD *v9; // rax
  _WORD *v10; // rbx
  void *v12; // rax
  _WORD *v13; // rax
  unsigned int TupleSize; // eax
  __int64 v15; // rax

  v6 = ((__int64 (__fastcall *)(hkDataArrayImpl *))this->vfptr[1].__vecDelDtor)(this);
  v7 = v6;
  if ( *(_DWORD *)v6 == 9 && **(_DWORD **)(v6 + 8) != 3 )
  {
$LN4_209:
    v13 = val->m_impl->vfptr[10].__vecDelDtor(val->m_impl, val->m_handle);
    v10 = v13;
    if ( v13 )
    {
      ++v13[5];
      ++*((_DWORD *)v13 + 3);
    }
    ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _WORD *))this->vfptr[24].__vecDelDtor)(this, index, v13);
LABEL_9:
    if ( v10 )
    {
      --v10[5];
      if ( (*((_DWORD *)v10 + 3))-- == 1 )
        (**(void (__fastcall ***)(_WORD *, __int64))v10)(v10, 1i64);
    }
  }
  else
  {
    switch ( *(_DWORD *)((__int64 (__fastcall *)(hkDataArrayImpl *))this->vfptr[1].__vecDelDtor)(this) )
    {
      case 2:
      case 4:
        v8 = (unsigned int)val->m_impl->vfptr[12].__vecDelDtor(val->m_impl, val->m_handle);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))this->vfptr[18].__vecDelDtor)(this, index, v8);
        break;
      case 3:
        val->m_impl->vfptr[15].__vecDelDtor(val->m_impl, (unsigned int)val->m_handle);
        this->vfptr[16].__vecDelDtor(this, index);
        break;
      case 5:
        v12 = val->m_impl->vfptr[11].__vecDelDtor(val->m_impl, val->m_handle);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, void *))this->vfptr[14].__vecDelDtor)(this, index, v12);
        break;
      case 6:
      case 7:
        v9 = val->m_impl->vfptr[13].__vecDelDtor(val->m_impl, val->m_handle);
        v10 = v9;
        if ( v9 )
        {
          ++v9[5];
          ++*((_DWORD *)v9 + 3);
        }
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _WORD *))this->vfptr[22].__vecDelDtor)(this, index, v9);
        goto LABEL_9;
      case 8:
        goto $LN4_209;
      case 9:
        if ( **(_DWORD **)(v7 + 8) == 3 )
        {
          TupleSize = hkTypeManager::Type::getTupleSize((hkTypeManager::Type *)v7);
          v15 = ((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, _QWORD))val->m_impl->vfptr[14].__vecDelDtor)(
                  val->m_impl,
                  val->m_handle,
                  TupleSize);
          ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))this->vfptr[12].__vecDelDtor)(this, index, v15);
        }
        break;
      default:
        return;
    }
  }
}

