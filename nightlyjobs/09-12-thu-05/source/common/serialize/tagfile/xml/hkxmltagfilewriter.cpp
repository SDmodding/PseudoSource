// File Line: 21
// RVA: 0xE564B0
__int64 __fastcall anonymous_namespace_::worthPrinting_hkDataArray_Value_(hkDataArray_Value *value)
{
  __int64 v2; // rax
  int v3; // ecx
  _WORD *v4; // rax
  _WORD *v5; // rbx
  unsigned int v6; // eax
  bool v7; // zf
  unsigned int v8; // edi
  __int64 result; // rax
  hkDataArrayImpl *v10; // rax
  hkDataArrayImpl *v11; // rbx
  BOOL v12; // ebp
  int v13; // edi
  _WORD *v14; // rax
  hkDataArray_Value valuea; // [rsp+20h] [rbp-18h] BYREF
  int v16; // [rsp+40h] [rbp+8h]

  v2 = ((__int64 (__fastcall *)(hkDataArrayImpl *))value->m_impl->vfptr[1].__vecDelDtor)(value->m_impl);
  v3 = *(_DWORD *)v2;
  if ( *(_DWORD *)v2 == 8 )
  {
    v4 = value->m_impl->vfptr[23].__vecDelDtor(value->m_impl, (unsigned int)value->m_index);
    v5 = v4;
    if ( v4 )
    {
      ++v4[5];
      ++*((_DWORD *)v4 + 3);
    }
    v6 = (*(__int64 (__fastcall **)(_WORD *))(*(_QWORD *)v4 + 40i64))(v4);
    --v5[5];
    v7 = (*((_DWORD *)v5 + 3))-- == 1;
    v8 = v6;
    if ( v7 )
      (**(void (__fastcall ***)(_WORD *, __int64))v5)(v5, 1i64);
    return v8;
  }
  else if ( v3 == 9 )
  {
    if ( **(_DWORD **)(v2 + 8) != 3 || ((*(_DWORD *)(v2 + 16) - 4) & 0xFFFFFFF3) != 0 )
    {
      v10 = (hkDataArrayImpl *)value->m_impl->vfptr[23].__vecDelDtor(value->m_impl, (unsigned int)value->m_index);
      v11 = v10;
      if ( v10 )
      {
        ++v10->m_externalCount;
        ++v10->m_count;
      }
      v12 = 0;
      v16 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v10->vfptr[5].__vecDelDtor)(v10);
      v13 = 0;
      if ( v16 > 0 )
      {
        while ( 1 )
        {
          valuea.m_impl = v11;
          valuea.m_index = v13;
          if ( anonymous_namespace_::worthPrinting_hkDataArray_Value_(&valuea) )
            break;
          if ( ++v13 >= v16 )
            goto LABEL_18;
        }
        v12 = 1;
      }
LABEL_18:
      --v11->m_externalCount;
      v7 = v11->m_count-- == 1;
      if ( v7 )
      {
        v11->vfptr->__vecDelDtor(v11, 1u);
        return v12;
      }
      else
      {
        return v12;
      }
    }
    else
    {
      return 1i64;
    }
  }
  else
  {
    switch ( v3 )
    {
      case 2:
      case 4:
        result = value->m_impl->vfptr[19].__vecDelDtor(value->m_impl, (unsigned int)value->m_index) != 0;
        break;
      case 3:
        result = ((float (__fastcall *)(hkDataArrayImpl *, _QWORD))value->m_impl->vfptr[15].__vecDelDtor)(
                   value->m_impl,
                   (unsigned int)value->m_index) != 0.0;
        break;
      case 5:
        result = value->m_impl->vfptr[13].__vecDelDtor(value->m_impl, (unsigned int)value->m_index) != 0;
        break;
      case 6:
      case 7:
        v14 = value->m_impl->vfptr[21].__vecDelDtor(value->m_impl, (unsigned int)value->m_index);
        if ( v14 )
        {
          ++v14[5];
          ++*((_DWORD *)v14 + 3);
        }
        v12 = v14 != 0i64;
        if ( v14 )
        {
          --v14[5];
          v7 = (*((_DWORD *)v14 + 3))-- == 1;
          if ( v7 )
            (**(void (__fastcall ***)(void *, __int64))v14)(v14, 1i64);
        }
        return v12;
      default:
        result = 0i64;
        break;
    }
  }
  return result;
}

// File Line: 83
// RVA: 0xE56110
const char *__fastcall anonymous_namespace_::nameFromType(hkTypeManager::Type *type)
{
  const char *result; // rax
  int TupleSize; // eax

  switch ( type->m_subType )
  {
    case SUB_TYPE_VOID:
      result = "void";
      break;
    case SUB_TYPE_BYTE:
      result = "byte";
      break;
    case SUB_TYPE_REAL:
      result = "real";
      break;
    case SUB_TYPE_INT:
      result = "int";
      break;
    case SUB_TYPE_CSTRING:
      result = "string";
      break;
    case SUB_TYPE_CLASS:
      result = "struct";
      break;
    case SUB_TYPE_POINTER:
      result = "ref";
      break;
    case SUB_TYPE_TUPLE:
      if ( type->m_parent->m_subType != SUB_TYPE_REAL )
        goto LABEL_18;
      TupleSize = hkTypeManager::Type::getTupleSize(type);
      switch ( TupleSize )
      {
        case 4:
          result = "vec4";
          break;
        case 8:
          result = "vec8";
          break;
        case 12:
          result = "vec12";
          break;
        case 16:
          result = "vec16";
          break;
        default:
          goto LABEL_18;
      }
      break;
    default:
LABEL_18:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 115
// RVA: 0xE56210
__int64 __fastcall anonymous_namespace_::calcWrapMod(hkTypeManager::Type *type)
{
  __int64 result; // rax

  switch ( type->m_subType )
  {
    case SUB_TYPE_VOID:
      result = 32i64;
      break;
    case SUB_TYPE_BYTE:
      result = 16i64;
      break;
    case SUB_TYPE_REAL:
    case SUB_TYPE_INT:
      result = 8i64;
      break;
    case SUB_TYPE_CLASS:
      result = 0xFFFFFFFFi64;
      break;
    default:
      result = 1i64;
      break;
  }
  return result;
}

// File Line: 140
// RVA: 0xE575B0
void __fastcall `anonymous namespace::Indenter::push(Indenter *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // eax
  int v5; // r9d
  __int64 v6; // rdx
  int v7; // ecx
  char *v8; // r9
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  v2 = this->m_indent.m_size + this->m_indentStep;
  v3 = this->m_indent.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v3 < v2 )
  {
    v4 = 2 * v3;
    v5 = this->m_indent.m_size + this->m_indentStep;
    if ( v2 < v4 )
      v5 = v4;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_indent.m_data, v5, 1);
  }
  v6 = 0i64;
  v7 = v2 - this->m_indent.m_size;
  v8 = &this->m_indent.m_data[this->m_indent.m_size];
  if ( v7 > 0 )
  {
    do
      v8[v6++] = this->m_value;
    while ( v6 < v7 );
  }
  this->m_indent.m_size = v2;
  if ( v2 == (this->m_indent.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_indent.m_data, 1);
  this->m_indent.m_data[this->m_indent.m_size] = 0;
}

// File Line: 146
// RVA: 0xE57530
void __fastcall `anonymous namespace::Indenter::pop(Indenter *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // eax
  int v5; // r9d
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  this->m_indent.m_data[this->m_indent.m_size - (__int64)(int)this->m_indentStep] = 0;
  v2 = this->m_indent.m_size - this->m_indentStep;
  v3 = this->m_indent.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v3 >= v2 )
  {
    this->m_indent.m_size = v2;
  }
  else
  {
    v4 = 2 * v3;
    v5 = this->m_indent.m_size - this->m_indentStep;
    if ( v2 < v4 )
      v5 = v4;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_indent.m_data, v5, 1);
    this->m_indent.m_size = v2;
  }
}

// File Line: 187
// RVA: 0xE56F40
void __fastcall `anonymous namespace::SeenObjects::SeenObjects(
        SeenObjects *this,
        hkTagfileWriter::AddDataObjectListener *listener)
{
  int m_capacityAndFlags; // eax
  unsigned __int128 v4; // xmm0
  hkDataObject_Handle *v5; // rax
  hkDataObject_Handle v6; // [rsp+20h] [rbp-18h] BYREF

  this->m_objectIndexFromHandle.m_hashMod = -1;
  this->m_objectIndexFromHandle.m_elem = 0i64;
  this->m_objectIndexFromHandle.m_numElems = 0;
  this->m_objects.m_data = 0i64;
  this->m_objects.m_size = 0;
  this->m_objects.m_capacityAndFlags = 0x80000000;
  this->m_listener = listener;
  this->m_cachedObjects.m_data = 0i64;
  this->m_cachedObjects.m_size = 0;
  this->m_cachedObjects.m_capacityAndFlags = 0x80000000;
  this->m_classes.m_data = 0i64;
  this->m_classes.m_size = 0;
  this->m_classes.m_capacityAndFlags = 0x80000000;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_classIndexFromName.m_map,
    0);
  m_capacityAndFlags = this->m_objects.m_capacityAndFlags;
  v6 = (hkDataObject_Handle)0i64;
  if ( this->m_objects.m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_objects.m_data, 16);
  v4 = (unsigned __int128)v6;
  v5 = &this->m_objects.m_data[this->m_objects.m_size];
  if ( v5 )
    *v5 = v6;
  ++this->m_objects.m_size;
  v6 = (hkDataObject_Handle)v4;
  hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::insert(
    &this->m_objectIndexFromHandle,
    &hkContainerHeapAllocator::s_alloc,
    &v6,
    0);
}

// File Line: 195
// RVA: 0xE57660
void __fastcall `anonymous namespace::SeenObjects::scanObject(SeenObjects *this, hkDataObject *objIn)
{
  hkDataObjectImpl *v4; // rcx
  bool v5; // zf
  hkDataObjectImpl *m_impl; // rbx
  int m_size; // r13d
  void **v8; // rax
  void *v9; // r15
  void *v10; // r12
  hkDataObject_Handle *v11; // rax
  hkDataObjectImpl *v12; // rcx
  unsigned __int128 *v13; // rax
  hkDataObjectImpl *v14; // rcx
  unsigned __int128 *v15; // rax
  __int64 v16; // rdi
  __int64 v17; // r14
  _QWORD *v18; // rax
  unsigned __int128 v19; // [rsp+20h] [rbp-40h] BYREF
  char v20[16]; // [rsp+30h] [rbp-30h] BYREF
  hkDataObject result; // [rsp+88h] [rbp+28h] BYREF
  hkDataClass k; // [rsp+90h] [rbp+30h] BYREF

  if ( objIn->m_impl )
  {
    v19 = *(_OWORD *)objIn->m_impl->vfptr[1].__vecDelDtor(objIn->m_impl, &v19);
    if ( (unsigned int)hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
                         &this->m_objectIndexFromHandle,
                         (hkDataObject_Handle *)&v19,
                         0xFFFFFFFF) == -1 )
    {
      `anonymous namespace::SeenObjects::callListenerAndCache(this, &result, objIn);
      if ( objIn->m_impl )
      {
        m_impl = result.m_impl;
        k.m_impl = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataObjectImpl *))result.m_impl->vfptr[2].__vecDelDtor)(result.m_impl);
        `anonymous namespace::SeenObjects::addClass(this, &k);
        m_size = this->m_objects.m_size;
        v8 = (void **)m_impl->vfptr[1].__vecDelDtor(m_impl, (unsigned int)&v19);
        v9 = *v8;
        v10 = v8[1];
        if ( this->m_objects.m_size == (this->m_objects.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_objects.m_data, 16);
        v11 = &this->m_objects.m_data[this->m_objects.m_size];
        if ( v11 )
        {
          v11->p0 = v9;
          v11->p1 = v10;
        }
        ++this->m_objects.m_size;
        v12 = objIn->m_impl;
        v19 = 0ui64;
        if ( v12 )
          v13 = (unsigned __int128 *)v12->vfptr[1].__vecDelDtor(v12, (unsigned int)&v19);
        else
          v13 = &v19;
        v19 = *v13;
        hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::insert(
          &this->m_objectIndexFromHandle,
          &hkContainerHeapAllocator::s_alloc,
          (hkDataObject_Handle *)&v19,
          m_size);
        v14 = objIn->m_impl;
        v19 = 0ui64;
        if ( v14 )
          v15 = (unsigned __int128 *)v14->vfptr[1].__vecDelDtor(v14, (unsigned int)&v19);
        else
          v15 = &v19;
        v16 = *(_QWORD *)v15;
        v17 = *((_QWORD *)v15 + 1);
        v18 = m_impl->vfptr[1].__vecDelDtor(m_impl, (unsigned int)v20);
        if ( *v18 != v16 || v18[1] != v17 )
        {
          v19 = *(_OWORD *)m_impl->vfptr[1].__vecDelDtor(m_impl, (unsigned int)v20);
          hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::insert(
            &this->m_objectIndexFromHandle,
            &hkContainerHeapAllocator::s_alloc,
            (hkDataObject_Handle *)&v19,
            m_size);
        }
        `anonymous namespace::SeenObjects::scanObjectMembers(this, &result);
        --m_impl->m_externalCount;
        v5 = m_impl->m_count-- == 1;
        if ( v5 )
          m_impl->vfptr->__vecDelDtor(m_impl, 1u);
      }
      else
      {
        v4 = result.m_impl;
        if ( result.m_impl )
        {
          --result.m_impl->m_externalCount;
          v5 = v4->m_count-- == 1;
          if ( v5 )
            v4->vfptr->__vecDelDtor(v4, 1u);
        }
      }
    }
  }
}

// File Line: 229
// RVA: 0xE57880
void __fastcall `anonymous namespace::SeenObjects::scanObjectMembers(SeenObjects *this, hkDataObject *obj)
{
  hkDataObject *v3; // rdi
  unsigned int v4; // ebx
  hkTypeManager::Type *Type; // rbx
  hkTypeManager::SubType m_subType; // ecx
  hkTypeManager::Type *m_parent; // rax
  hkDataObjectImpl *v8; // rax
  hkDataObjectImpl *v9; // rbx
  int v10; // edi
  int v11; // esi
  hkDataObjectImpl *v12; // rax
  hkDataObjectImpl *v13; // rcx
  bool v14; // zf
  hkDataRefCountedVtbl *vfptr; // rax
  hkDataObjectImpl *m_impl; // rcx
  hkDataObjectImpl *v17; // rax
  int v18; // edi
  int v19; // esi
  hkDataObjectImpl *v20; // rax
  hkDataObjectImpl *v21; // rcx
  hkDataObjectImpl *v22; // rax
  hkDataObjectImpl *v23; // rax
  hkDataObject obja; // [rsp+20h] [rbp-48h] BYREF
  hkDataObject v25; // [rsp+28h] [rbp-40h] BYREF
  hkDataObject v26; // [rsp+30h] [rbp-38h] BYREF
  hkDataObject_Value v27; // [rsp+38h] [rbp-30h] BYREF
  unsigned int v29; // [rsp+80h] [rbp+18h]
  hkDataObject objIn; // [rsp+88h] [rbp+20h] BYREF

  v3 = obj;
  v4 = ((__int64 (__fastcall *)(hkDataObjectImpl *))obj->m_impl->vfptr[5].__vecDelDtor)(obj->m_impl);
  v29 = v4;
  if ( v3->m_impl->vfptr[6].__vecDelDtor(v3->m_impl, v4) )
  {
    do
    {
      ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, _QWORD))v3->m_impl->vfptr[9].__vecDelDtor)(
        v3->m_impl,
        &v27,
        v4);
      Type = hkDataObject_Value::getType(&v27);
      if ( hkTypeManager::Type::findTerminal(Type)->m_subType == SUB_TYPE_CLASS )
      {
        m_subType = Type->m_subType;
        if ( Type->m_subType == SUB_TYPE_CLASS )
        {
          v23 = (hkDataObjectImpl *)v27.m_impl->vfptr[13].__vecDelDtor(v27.m_impl, v27.m_handle);
          v26.m_impl = v23;
          if ( v23 )
          {
            ++v23->m_externalCount;
            ++v23->m_count;
          }
          `anonymous namespace::SeenObjects::scanObjectMembers(this, &v26);
          m_impl = v26.m_impl;
          goto LABEL_36;
        }
        if ( m_subType == SUB_TYPE_POINTER )
        {
          v22 = (hkDataObjectImpl *)v27.m_impl->vfptr[13].__vecDelDtor(v27.m_impl, v27.m_handle);
          v25.m_impl = v22;
          if ( v22 )
          {
            ++v22->m_externalCount;
            ++v22->m_count;
          }
          `anonymous namespace::SeenObjects::scanObject(this, &v25);
          m_impl = v25.m_impl;
LABEL_36:
          if ( !m_impl )
            goto LABEL_40;
          --m_impl->m_externalCount;
          v14 = m_impl->m_count-- == 1;
          if ( !v14 )
            goto LABEL_40;
          vfptr = m_impl->vfptr;
          goto LABEL_39;
        }
        if ( (unsigned int)(m_subType - 8) <= 1 )
        {
          m_parent = Type->m_parent;
          if ( m_parent->m_subType == SUB_TYPE_POINTER && m_parent->m_parent->m_subType == SUB_TYPE_CLASS )
          {
            v8 = (hkDataObjectImpl *)v27.m_impl->vfptr[10].__vecDelDtor(v27.m_impl, v27.m_handle);
            v9 = v8;
            if ( v8 )
            {
              ++v8->m_externalCount;
              ++v8->m_count;
            }
            v10 = 0;
            v11 = ((__int64 (__fastcall *)(hkDataObjectImpl *))v8->vfptr[5].__vecDelDtor)(v8);
            if ( v11 > 0 )
            {
              do
              {
                v12 = (hkDataObjectImpl *)v9->vfptr[21].__vecDelDtor(v9, v10);
                objIn.m_impl = v12;
                if ( v12 )
                {
                  ++v12->m_externalCount;
                  ++v12->m_count;
                }
                `anonymous namespace::SeenObjects::scanObject(this, &objIn);
                v13 = objIn.m_impl;
                if ( objIn.m_impl )
                {
                  --objIn.m_impl->m_externalCount;
                  v14 = v13->m_count-- == 1;
                  if ( v14 )
                    v13->vfptr->__vecDelDtor(v13, 1u);
                }
                ++v10;
              }
              while ( v10 < v11 );
            }
          }
          else
          {
            if ( m_parent->m_subType != SUB_TYPE_CLASS )
              goto LABEL_40;
            v17 = (hkDataObjectImpl *)v27.m_impl->vfptr[10].__vecDelDtor(v27.m_impl, v27.m_handle);
            v9 = v17;
            if ( v17 )
            {
              ++v17->m_externalCount;
              ++v17->m_count;
            }
            v18 = 0;
            v19 = ((__int64 (__fastcall *)(hkDataObjectImpl *))v17->vfptr[5].__vecDelDtor)(v17);
            if ( v19 > 0 )
            {
              do
              {
                v20 = (hkDataObjectImpl *)v9->vfptr[21].__vecDelDtor(v9, v18);
                obja.m_impl = v20;
                if ( v20 )
                {
                  ++v20->m_externalCount;
                  ++v20->m_count;
                }
                `anonymous namespace::SeenObjects::scanObjectMembers(this, &obja);
                v21 = obja.m_impl;
                if ( obja.m_impl )
                {
                  --obja.m_impl->m_externalCount;
                  v14 = v21->m_count-- == 1;
                  if ( v14 )
                    v21->vfptr->__vecDelDtor(v21, 1u);
                }
                ++v18;
              }
              while ( v18 < v19 );
            }
          }
          --v9->m_externalCount;
          v14 = v9->m_count-- == 1;
          if ( v14 )
          {
            vfptr = v9->vfptr;
            m_impl = v9;
LABEL_39:
            vfptr->__vecDelDtor(m_impl, 1u);
          }
        }
      }
LABEL_40:
      v4 = (unsigned int)obj->m_impl->vfptr[7].__vecDelDtor(obj->m_impl, v29);
      v29 = v4;
      v3 = obj;
    }
    while ( obj->m_impl->vfptr[6].__vecDelDtor(obj->m_impl, v4) );
  }
}

// File Line: 291
// RVA: 0xE57370
hkDataObject *__fastcall `anonymous namespace::SeenObjects::callListenerAndCache(
        SeenObjects *this,
        hkDataObject *result,
        hkDataObject *object)
{
  hkTagfileWriter::AddDataObjectListener *m_listener; // rcx
  hkDataObjectImpl *v7; // r8
  __int128 *v8; // rax
  __int64 v9; // r15
  __int64 v10; // r14
  hkDataObjectImpl *v11; // rcx
  __int128 *v12; // rax
  bool v13; // zf
  hkDataObjectImpl *m_impl; // rax
  hkArray<hkDataObject,hkContainerHeapAllocator> *p_m_cachedObjects; // rbx
  hkDataObject *v17; // rdx
  __int64 m_size; // rdx
  hkDataObject *v19; // rsi
  hkDataObjectImpl *v20; // rcx
  hkDataObjectImpl *v21; // rax
  hkDataObjectImpl *v22; // rcx
  __int128 v23; // [rsp+20h] [rbp-20h] BYREF
  char v24[16]; // [rsp+30h] [rbp-10h] BYREF
  hkDataObjectImpl *v25; // [rsp+70h] [rbp+30h] BYREF

  m_listener = this->m_listener;
  if ( !m_listener )
  {
LABEL_13:
    m_impl = object->m_impl;
    result->m_impl = object->m_impl;
    if ( m_impl )
    {
      ++m_impl->m_externalCount;
      ++m_impl->m_count;
    }
    return result;
  }
  ((void (__fastcall *)(hkTagfileWriter::AddDataObjectListener *, hkDataObjectImpl **))m_listener->vfptr[1].__first_virtual_table_function__)(
    m_listener,
    &v25);
  v7 = v25;
  v23 = 0ui64;
  if ( v25 )
  {
    v8 = (__int128 *)v25->vfptr[1].__vecDelDtor(v25, (unsigned int)v24);
    v7 = v25;
  }
  else
  {
    v8 = &v23;
  }
  v9 = *(_QWORD *)v8;
  v10 = *((_QWORD *)v8 + 1);
  v11 = object->m_impl;
  v23 = 0ui64;
  if ( v11 )
  {
    v12 = (__int128 *)((__int64 (__fastcall *)(hkDataObjectImpl *, __int128 *, hkDataObjectImpl *))v11->vfptr[1].__vecDelDtor)(
                        v11,
                        &v23,
                        v7);
    v7 = v25;
  }
  else
  {
    v12 = &v23;
  }
  if ( v9 == *(_QWORD *)v12 && v10 == *((_QWORD *)v12 + 1) )
  {
    if ( v7 )
    {
      --v7->m_externalCount;
      v13 = v7->m_count-- == 1;
      if ( v13 )
        v7->vfptr->__vecDelDtor(v7, 1u);
    }
    goto LABEL_13;
  }
  p_m_cachedObjects = &this->m_cachedObjects;
  if ( this->m_cachedObjects.m_size == (this->m_cachedObjects.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_cachedObjects.m_data, 8);
    v7 = v25;
  }
  v17 = &p_m_cachedObjects->m_data[this->m_cachedObjects.m_size];
  if ( v17 )
  {
    v17->m_impl = 0i64;
    v7 = v25;
  }
  m_size = this->m_cachedObjects.m_size;
  v19 = &p_m_cachedObjects->m_data[m_size];
  p_m_cachedObjects->m_size = m_size + 1;
  if ( v7 )
  {
    ++v7->m_externalCount;
    ++v7->m_count;
    v7 = v25;
  }
  v20 = v19->m_impl;
  if ( v19->m_impl )
  {
    --v20->m_externalCount;
    v13 = v20->m_count-- == 1;
    if ( v13 )
      ((void (__fastcall *)(hkDataObjectImpl *, __int64, hkDataObjectImpl *))v20->vfptr->__vecDelDtor)(v20, 1i64, v7);
    v7 = v25;
  }
  v19->m_impl = v7;
  v21 = v25;
  result->m_impl = v25;
  if ( v21 )
  {
    ++v21->m_externalCount;
    ++v21->m_count;
    v22 = v25;
    if ( v25 )
    {
      --v25->m_externalCount;
      v13 = v22->m_count-- == 1;
      if ( v13 )
        v22->vfptr->__vecDelDtor(v22, 1u);
    }
  }
  return result;
}

// File Line: 307
// RVA: 0xE57140
void __fastcall `anonymous namespace::SeenObjects::addClass(SeenObjects *this, hkDataClass *k)
{
  hkDataClass *v3; // rdi
  const char *v4; // rax
  unsigned __int64 m_size; // rbx
  const char *v6; // rax
  hkDataClass *v7; // rdx
  hkDataClassImpl *m_impl; // rcx
  __int64 v9; // rbp
  int v10; // eax
  int v11; // ebx
  int v12; // r9d
  __int64 v13; // rdx
  hkTypeManager::Type **p_m_type; // rax
  int i; // esi
  _QWORD *v16; // rax
  __int64 v17; // rdi
  _QWORD *v18; // rbx
  const char *TypeName; // rax
  hkArrayBase<hkDataClass_MemberInfo> array; // [rsp+30h] [rbp-38h] BYREF
  hkDataClass ka; // [rsp+80h] [rbp+18h] BYREF
  hkDataClass v24; // [rsp+88h] [rbp+20h] BYREF

  v3 = k;
  v4 = (const char *)((__int64 (__fastcall *)(hkDataClassImpl *))k->m_impl->vfptr[2].__vecDelDtor)(k->m_impl);
  if ( (unsigned int)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                       (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classIndexFromName,
                       v4,
                       0xFFFFFFFFFFFFFFFFui64) == -1 )
  {
    if ( ((__int64 (__fastcall *)(hkDataClassImpl *))v3->m_impl->vfptr[4].__vecDelDtor)(v3->m_impl) )
    {
      ka.m_impl = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataClassImpl *))v3->m_impl->vfptr[4].__vecDelDtor)(v3->m_impl);
      `anonymous namespace::SeenObjects::addClass(this, &ka);
    }
    m_size = this->m_classes.m_size;
    v6 = (const char *)((__int64 (__fastcall *)(hkDataClassImpl *))v3->m_impl->vfptr[2].__vecDelDtor)(v3->m_impl);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      &this->m_classIndexFromName.m_map,
      v6,
      m_size);
    if ( this->m_classes.m_size == (this->m_classes.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_classes.m_data, 8);
    v7 = &this->m_classes.m_data[this->m_classes.m_size];
    if ( v7 )
      v7->m_impl = v3->m_impl;
    ++this->m_classes.m_size;
    m_impl = v3->m_impl;
    v9 = 0i64;
    array.m_data = 0i64;
    array.m_size = 0;
    array.m_capacityAndFlags = 0x80000000;
    v10 = ((__int64 (__fastcall *)(hkDataClassImpl *))m_impl->vfptr[6].__vecDelDtor)(m_impl);
    v11 = v10;
    if ( v10 > 0 )
    {
      v12 = v10;
      hkArrayUtil::_reserve((hkResult *)&ka, &hkContainerTempAllocator::s_alloc, (const void **)&array.m_data, v12, 32);
    }
    v13 = v11 - array.m_size;
    if ( v11 - array.m_size > 0 )
    {
      p_m_type = &array.m_data[array.m_size].m_type;
      do
      {
        if ( p_m_type != (hkTypeManager::Type **)16 )
        {
          *(p_m_type - 2) = 0i64;
          *(p_m_type - 1) = 0i64;
          *p_m_type = 0i64;
          p_m_type[1] = 0i64;
        }
        p_m_type += 4;
        --v13;
      }
      while ( v13 );
    }
    array.m_size = v11;
    hkDataClass::getAllDeclaredMemberInfo(v3, &array);
    for ( i = 0; i < array.m_size; ++v9 )
    {
      ka.m_impl = (hkDataClassImpl *)hkTypeManager::Type::findTerminal(array.m_data[v9].m_type);
      if ( LODWORD(ka.m_impl->vfptr) == 6 )
      {
        v16 = (_QWORD *)((__int64 (__fastcall *)(hkDataClassImpl *))v3->m_impl->vfptr[1].__vecDelDtor)(v3->m_impl);
        v17 = *v16;
        v18 = v16;
        TypeName = hkTypeManager::Type::getTypeName((hkTypeManager::Type *)ka.m_impl);
        v24.m_impl = (hkDataClassImpl *)(*(__int64 (__fastcall **)(_QWORD *, const char *))(v17 + 72))(v18, TypeName);
        `anonymous namespace::SeenObjects::addClass(this, &v24);
        v3 = k;
      }
      ++i;
    }
    array.m_size = 0;
    if ( array.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        array.m_data,
        32 * array.m_capacityAndFlags);
  }
}

// File Line: 391
// RVA: 0xE57C80
void __fastcall `anonymous namespace::Context::writeClass(Context *this, hkDataClass *k, hkOstream *os)
{
  Context *v3; // rsi
  int v6; // ebx
  const char *v7; // rax
  __int64 v8; // rax
  const char *v9; // rax
  hkDataClassImpl *m_impl; // rcx
  unsigned int TupleSize; // r14d
  int v12; // eax
  int v13; // ebx
  __int64 v14; // rdx
  hkTypeManager::Type **p_m_type; // rax
  int v16; // r15d
  __int64 v17; // r12
  hkDataClass_MemberInfo *m_data; // r13
  char v19; // bl
  hkTypeManager::Type *m_type; // rsi
  const char *v21; // rdi
  const char *v22; // rax
  hkTypeManager::Type *Terminal; // rax
  const char *TypeName; // rax
  int v25; // ebx
  int v26; // eax
  int v27; // eax
  int v28; // r9d
  hkArrayBase<hkDataClass_MemberInfo> array; // [rsp+30h] [rbp-48h] BYREF
  Context *v30; // [rsp+80h] [rbp+8h] BYREF
  hkResult result; // [rsp+88h] [rbp+10h] BYREF

  v30 = this;
  v3 = this;
  ((void (__fastcall *)(hkDataClassImpl *))k->m_impl->vfptr[3].__vecDelDtor)(k->m_impl);
  v6 = ((__int64 (__fastcall *)(hkDataClassImpl *))k->m_impl->vfptr[3].__vecDelDtor)(k->m_impl);
  v7 = (const char *)((__int64 (__fastcall *)(hkDataClassImpl *))k->m_impl->vfptr[2].__vecDelDtor)(k->m_impl);
  hkOstream::printf(os, "%s<class name=\"%s\" version=\"%i\"", v3->m_indenter.m_indent.m_data, v7, v6);
  if ( ((__int64 (__fastcall *)(hkDataClassImpl *))k->m_impl->vfptr[4].__vecDelDtor)(k->m_impl) )
  {
    v8 = ((__int64 (__fastcall *)(hkDataClassImpl *))k->m_impl->vfptr[4].__vecDelDtor)(k->m_impl);
    v9 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 16i64))(v8);
    hkOstream::printf(os, " parent=\"%s\"", v9);
  }
  hkOstream::printf(os, ">\n");
  `anonymous namespace::Indenter::push(&v3->m_indenter);
  m_impl = k->m_impl;
  TupleSize = 0;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  v12 = ((__int64 (__fastcall *)(hkDataClassImpl *))m_impl->vfptr[6].__vecDelDtor)(m_impl);
  v13 = v12;
  if ( v12 > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&array.m_data, v12, 32);
  v14 = v13 - array.m_size;
  if ( v13 - array.m_size > 0 )
  {
    p_m_type = &array.m_data[array.m_size].m_type;
    do
    {
      if ( p_m_type != (hkTypeManager::Type **)16 )
      {
        *(p_m_type - 2) = 0i64;
        *(p_m_type - 1) = 0i64;
        *p_m_type = 0i64;
        p_m_type[1] = 0i64;
      }
      p_m_type += 4;
      --v14;
    }
    while ( v14 );
  }
  array.m_size = v13;
  hkDataClass::getAllDeclaredMemberInfo(k, &array);
  v16 = 0;
  if ( array.m_size > 0 )
  {
    v17 = 0i64;
    while ( 1 )
    {
      m_data = array.m_data;
      v19 = 0;
      m_type = array.m_data[v17].m_type;
      if ( m_type->m_subType == SUB_TYPE_ARRAY )
      {
        v19 = 1;
      }
      else
      {
        if ( m_type->m_subType != SUB_TYPE_TUPLE
          || m_type->m_parent->m_subType == SUB_TYPE_REAL && ((m_type->m_extra.m_size - 4) & 0xFFFFFFF3) == 0 )
        {
          goto LABEL_19;
        }
        TupleSize = hkTypeManager::Type::getTupleSize(array.m_data[v17].m_type);
      }
      m_type = m_type->m_parent;
LABEL_19:
      v21 = v30->m_indenter.m_indent.m_data;
      v22 = anonymous_namespace_::nameFromType(m_type);
      hkOstream::printf(os, "%s<member name=\"%s\" type=\"%s\"", v21, m_data[v17].m_name, v22);
      if ( v19 )
        hkOstream::printf(os, " array=\"true\"");
      if ( TupleSize )
        hkOstream::printf(os, " count=\"%i\"", TupleSize);
      Terminal = hkTypeManager::Type::findTerminal(m_type);
      if ( Terminal->m_subType == SUB_TYPE_CLASS )
      {
        TypeName = hkTypeManager::Type::getTypeName(Terminal);
        hkOstream::printf(os, " class=\"%s\"", TypeName);
      }
      hkOstream::printf(os, "/>\n");
      ++v16;
      ++v17;
      TupleSize = 0;
      if ( v16 >= array.m_size )
      {
        v3 = v30;
        break;
      }
    }
  }
  v3->m_indenter.m_indent.m_data[v3->m_indenter.m_indent.m_size - (__int64)(int)v3->m_indenter.m_indentStep] = 0;
  v25 = v3->m_indenter.m_indent.m_size - v3->m_indenter.m_indentStep;
  v26 = v3->m_indenter.m_indent.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v26 < v25 )
  {
    v27 = 2 * v26;
    v28 = v3->m_indenter.m_indent.m_size - v3->m_indenter.m_indentStep;
    if ( v25 < v27 )
      v28 = v27;
    hkArrayUtil::_reserve(
      (hkResult *)&v30,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&v3->m_indenter.m_indent.m_data,
      v28,
      1);
  }
  v3->m_indenter.m_indent.m_size = v25;
  hkOstream::printf(os, "%s</class>\n", v3->m_indenter.m_indent.m_data);
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      32 * array.m_capacityAndFlags);
}

// File Line: 456
// RVA: 0xE58200
void __fastcall `anonymous namespace::Context::writeFloat(Context *this, hkOstream *os, float r)
{
  bool v3; // zf
  hkStringBuf buf; // [rsp+20h] [rbp-D8h] BYREF
  int v7; // [rsp+B0h] [rbp-48h]
  int v8; // [rsp+B4h] [rbp-44h]
  char v9; // [rsp+B8h] [rbp-40h] BYREF
  unsigned int v10; // [rsp+168h] [rbp+70h]

  v3 = this->m_writeFloatAsHex.m_bool == 0;
  buf.m_string.m_data = buf.m_string.m_storage;
  buf.m_string.m_capacityAndFlags = -2147483520;
  buf.m_string.m_size = 1;
  buf.m_string.m_storage[0] = 0;
  if ( v3 )
  {
    hkFloatParseUtil::calcFloatTextWithPoint(r, &buf);
  }
  else
  {
    hkStringBuf::printf(&buf, "x%08x", v10);
    if ( this->m_floatComment.m_bool )
    {
      v8 = -2147483520;
      v7 = 1;
      v9 = 0;
      *(_QWORD *)&buf.m_string.m_storage[120] = &v9;
      hkFloatParseUtil::calcFloatTextWithPoint(r, (hkStringBuf *)&buf.m_string.m_storage[120]);
      hkStringBuf::append(&buf, " <!-- ", -1);
      hkStringBuf::append(&buf, *(const char **)&buf.m_string.m_storage[120], -1);
      hkStringBuf::append(&buf, " -->", -1);
      v7 = 0;
      if ( v8 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          *(void **)&buf.m_string.m_storage[120],
          v8 & 0x3FFFFFFF);
    }
  }
  hkOstream::write(os, buf.m_string.m_data, (unsigned int)(buf.m_string.m_size - 1));
  buf.m_string.m_size = 0;
  if ( buf.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      buf.m_string.m_data,
      buf.m_string.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 486
// RVA: 0xE58620
void __fastcall `anonymous namespace::Context::writeReals(Context *this, hkOstream *os, const float *ra, int nreal)
{
  __int64 v7; // r14
  __int64 i; // rbx
  float v9; // xmm6_4
  hkStringBuf buf; // [rsp+20h] [rbp-B8h] BYREF
  unsigned int vars0; // [rsp+170h] [rbp+98h]

  if ( nreal > 0 )
  {
    v7 = nreal;
    for ( i = 0i64; i < v7; ++i )
    {
      if ( i )
        hkOstream::printf(os, " ");
      v9 = ra[i];
      buf.m_string.m_capacityAndFlags = -2147483520;
      buf.m_string.m_size = 1;
      buf.m_string.m_storage[0] = 0;
      vars0 = LODWORD(v9);
      buf.m_string.m_data = buf.m_string.m_storage;
      if ( this->m_writeFloatAsHex.m_bool )
      {
        hkStringBuf::printf(&buf, "x%08x", vars0);
        if ( this->m_floatComment.m_bool )
        {
          *(_DWORD *)&buf.m_string.m_storage[100] = -2147483520;
          *(_DWORD *)&buf.m_string.m_storage[96] = 1;
          buf.m_string.m_storage[104] = 0;
          *(_QWORD *)&buf.m_string.m_storage[88] = &buf.m_string.m_storage[104];
          hkFloatParseUtil::calcFloatTextWithPoint(v9, (hkStringBuf *)&buf.m_string.m_storage[88]);
          hkStringBuf::append(&buf, " <!-- ", -1);
          hkStringBuf::append(&buf, *(const char **)&buf.m_string.m_storage[88], -1);
          hkStringBuf::append(&buf, " -->", -1);
          *(_DWORD *)&buf.m_string.m_storage[96] = 0;
          if ( *(int *)&buf.m_string.m_storage[100] >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              *(void **)&buf.m_string.m_storage[88],
              *(_DWORD *)&buf.m_string.m_storage[100] & 0x3FFFFFFF);
        }
      }
      else
      {
        hkFloatParseUtil::calcFloatTextWithPoint(v9, &buf);
      }
      hkOstream::write(os, buf.m_string.m_data, (unsigned int)(buf.m_string.m_size - 1));
      buf.m_string.m_size = 0;
      if ( buf.m_string.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          buf.m_string.m_data,
          buf.m_string.m_capacityAndFlags & 0x3FFFFFFF);
    }
  }
}

// File Line: 499
// RVA: 0xE56B10
void __fastcall `anonymous namespace::Context::writeValue<hkDataObject_Value>(
        Context *this,
        hkDataObject_Value *value,
        hkOstream *os)
{
  int v4; // r15d
  hkTypeManager::Type *Type; // rdx
  __int64 v8; // r8
  __int64 v9; // rax
  float v10; // xmm0_4
  __int64 v11; // rax
  __int64 v12; // rbx
  hkDataArray *v13; // rax
  unsigned int v14; // eax
  hkDataObjectImpl *v15; // rax
  hkDataObjectImpl *m_impl; // rcx
  bool v17; // zf
  const char *v18; // rax
  __int64 TupleSize; // rbx
  const float *v20; // rax
  __int64 v21; // rax
  hkDataObjectImpl *v22; // rax
  hkDataObjectImpl *v23; // rcx
  hkDataArrayImpl *v24; // rax
  hkDataArrayImpl *v25; // rbx
  hkDataArray a[2]; // [rsp+20h] [rbp-79h] BYREF
  hkDataObject v27; // [rsp+30h] [rbp-69h] BYREF
  char v28[24]; // [rsp+38h] [rbp-61h] BYREF
  hkStringBuf v29; // [rsp+50h] [rbp-49h] BYREF
  hkDataObject obj; // [rsp+118h] [rbp+7Fh] BYREF

  v4 = 0;
  LODWORD(obj.m_impl) = 0;
  Type = hkDataObject_Value::getType(value);
  v8 = Type->m_subType - 2;
  switch ( Type->m_subType )
  {
    case SUB_TYPE_BYTE:
    case SUB_TYPE_INT:
      v9 = ((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64, unsigned __int64))value->m_impl->vfptr[12].__vecDelDtor)(
             value->m_impl,
             value->m_handle,
             v8,
             0x140000000ui64);
      hkOstream::printf(os, "%I64i", v9);
      return;
    case SUB_TYPE_REAL:
      v10 = ((float (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64, unsigned __int64))value->m_impl->vfptr[15].__vecDelDtor)(
              value->m_impl,
              value->m_handle,
              v8,
              0x140000000ui64);
      `anonymous namespace::Context::writeFloat(this, os, v10);
      return;
    case SUB_TYPE_CSTRING:
      v18 = (const char *)((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64, unsigned __int64))value->m_impl->vfptr[11].__vecDelDtor)(
                            value->m_impl,
                            value->m_handle,
                            v8,
                            0x140000000ui64);
      if ( v18 )
      {
        hkStringBuf::hkStringBuf(&v29, v18);
        hkStringBuf::replace(&v29, "&", "&amp;", REPLACE_ALL);
        hkStringBuf::replace(&v29, "<", "&lt;", REPLACE_ALL);
        hkStringBuf::replace(&v29, ">", "&gt;", REPLACE_ALL);
        hkOstream::write(os, v29.m_string.m_data, (unsigned int)(v29.m_string.m_size - 1));
        v29.m_string.m_size = 0;
        if ( v29.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            v29.m_string.m_data,
            v29.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      }
      else
      {
        hkOstream::printf(os, "<null/>");
      }
      return;
    case SUB_TYPE_CLASS:
      v15 = (hkDataObjectImpl *)((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64, unsigned __int64))value->m_impl->vfptr[13].__vecDelDtor)(
                                  value->m_impl,
                                  value->m_handle,
                                  v8,
                                  0x140000000ui64);
      obj.m_impl = v15;
      if ( v15 )
      {
        ++v15->m_externalCount;
        ++v15->m_count;
      }
      `anonymous namespace::Context::writeObjectMembers(this, &obj, os);
      m_impl = obj.m_impl;
      if ( obj.m_impl )
      {
        --obj.m_impl->m_externalCount;
        v17 = m_impl->m_count-- == 1;
        if ( v17 )
          m_impl->vfptr->__vecDelDtor(m_impl, 1u);
      }
      goto LABEL_43;
    case SUB_TYPE_POINTER:
      v11 = ((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64, unsigned __int64))value->m_impl->vfptr[13].__vecDelDtor)(
              value->m_impl,
              value->m_handle,
              v8,
              0x140000000ui64);
      v12 = v11;
      if ( v11 )
      {
        ++*(_WORD *)(v11 + 10);
        ++*(_DWORD *)(v11 + 12);
      }
      a[0].m_impl = 0i64;
      a[1].m_impl = 0i64;
      if ( v11 )
        v13 = (hkDataArray *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v11 + 8i64))(v11, v28);
      else
        v13 = a;
      *(_OWORD *)&a[0].m_impl = *(_OWORD *)&v13->m_impl;
      v14 = hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
              &this->m_seenObjects.m_objectIndexFromHandle,
              (hkDataObject_Handle *)a,
              0xFFFFFFFF);
      hkOstream::printf(os, "#%04i", v14);
      if ( v12 )
        goto LABEL_35;
      return;
    case SUB_TYPE_ARRAY:
      goto $LN7_230;
    case SUB_TYPE_TUPLE:
      if ( Type->m_subType == SUB_TYPE_TUPLE
        && Type->m_parent->m_subType == SUB_TYPE_REAL
        && ((Type->m_extra.m_size - 4) & 0xFFFFFFF3) == 0 )
      {
        TupleSize = (unsigned int)hkTypeManager::Type::getTupleSize(Type);
        v20 = (const float *)((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64))value->m_impl->vfptr[14].__vecDelDtor)(
                               value->m_impl,
                               value->m_handle,
                               TupleSize);
        `anonymous namespace::Context::writeReals(this, os, v20, TupleSize);
      }
      else
      {
$LN7_230:
        if ( Type->m_parent->m_subType == SUB_TYPE_CLASS )
        {
          v21 = ((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64, unsigned __int64))value->m_impl->vfptr[10].__vecDelDtor)(
                  value->m_impl,
                  value->m_handle,
                  v8,
                  0x140000000ui64);
          v12 = v21;
          if ( v21 )
          {
            ++*(_WORD *)(v21 + 10);
            ++*(_DWORD *)(v21 + 12);
          }
          `anonymous namespace::Indenter::push(&this->m_indenter);
          if ( (*(int (__fastcall **)(__int64))(*(_QWORD *)v12 + 40i64))(v12) > 0 )
          {
            do
            {
              hkOstream::printf(os, "\n%s<struct>", this->m_indenter.m_indent.m_data);
              v22 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v12 + 168i64))(
                                          v12,
                                          (unsigned int)v4);
              v27.m_impl = v22;
              if ( v22 )
              {
                ++v22->m_externalCount;
                ++v22->m_count;
              }
              `anonymous namespace::Context::writeObjectMembers(this, &v27, os);
              v23 = v27.m_impl;
              if ( v27.m_impl )
              {
                --v27.m_impl->m_externalCount;
                v17 = v23->m_count-- == 1;
                if ( v17 )
                  v23->vfptr->__vecDelDtor(v23, 1u);
              }
              hkOstream::printf(os, "\n%s</struct>", this->m_indenter.m_indent.m_data);
              ++v4;
            }
            while ( v4 < (*(int (__fastcall **)(__int64))(*(_QWORD *)v12 + 40i64))(v12) );
          }
          `anonymous namespace::Indenter::pop(&this->m_indenter);
          hkOstream::printf(os, "\n%s", this->m_indenter.m_indent.m_data);
LABEL_35:
          --*(_WORD *)(v12 + 10);
          v17 = (*(_DWORD *)(v12 + 12))-- == 1;
          if ( v17 )
            (**(void (__fastcall ***)(__int64, __int64))v12)(v12, 1i64);
        }
        else
        {
          `anonymous namespace::Indenter::push(&this->m_indenter);
          v24 = (hkDataArrayImpl *)value->m_impl->vfptr[10].__vecDelDtor(value->m_impl, value->m_handle);
          v25 = v24;
          a[0].m_impl = v24;
          if ( v24 )
          {
            ++v24->m_externalCount;
            ++v24->m_count;
          }
          `anonymous namespace::Context::writeArray(this, a, os);
          if ( v25 )
          {
            --v25->m_externalCount;
            v17 = v25->m_count-- == 1;
            if ( v17 )
              v25->vfptr->__vecDelDtor(v25, 1u);
          }
          `anonymous namespace::Indenter::pop(&this->m_indenter);
LABEL_43:
          hkOstream::printf(os, "\n%s", this->m_indenter.m_indent.m_data);
        }
      }
      break;
    default:
      return;
  }
}

// File Line: 587
// RVA: 0xE57B30
void __fastcall `anonymous namespace::Context::writeArray(Context *this, hkDataArray *a, hkOstream *os)
{
  hkTypeManager::Type *v6; // r12
  int v7; // esi
  int v8; // r13d
  int v9; // ebx
  const char *v10; // rbp
  hkDataArrayImpl *m_impl; // rax
  hkDataArray_Value value; // [rsp+20h] [rbp-48h] BYREF
  hkDataArray_Value v13; // [rsp+30h] [rbp-38h] BYREF
  int v14; // [rsp+78h] [rbp+10h]

  v6 = (hkTypeManager::Type *)((__int64 (*)(void))a->m_impl->vfptr[1].__vecDelDtor)();
  v7 = 1;
  v14 = anonymous_namespace_::calcWrapMod(v6);
  v8 = ((__int64 (__fastcall *)(hkDataArrayImpl *))a->m_impl->vfptr[5].__vecDelDtor)(a->m_impl);
  v9 = 0;
  v10 = anonymous_namespace_::nameFromType(v6);
  if ( (unsigned int)(v6->m_subType - 2) <= 2 )
    v10 = 0i64;
  if ( v8 > 0 )
  {
    do
    {
      if ( !--v7 )
      {
        hkOstream::printf(os, "\n%s", this->m_indenter.m_indent.m_data);
        v7 = v14;
      }
      if ( v10 )
      {
        if ( v6->m_subType != SUB_TYPE_CSTRING || a->m_impl->vfptr[13].__vecDelDtor(a->m_impl, (unsigned int)v9) )
        {
          hkOstream::printf(os, "<%s>", v10);
          value.m_impl = a->m_impl;
          value.m_index = v9;
          `anonymous namespace::Context::writeValue<hkDataArray_Value>(this, &value, os);
          hkOstream::printf(os, "</%s>", v10);
        }
        else
        {
          hkOstream::printf(os, "<null/>");
        }
      }
      else
      {
        m_impl = a->m_impl;
        v13.m_index = v9;
        v13.m_impl = m_impl;
        `anonymous namespace::Context::writeValue<hkDataArray_Value>(this, &v13, os);
        hkOstream::printf(os, " ");
      }
      ++v9;
    }
    while ( v9 < v8 );
  }
}

// File Line: 631
// RVA: 0xE58370
void __fastcall `anonymous namespace::Context::writeObjectMembers(Context *this, hkDataObject *obj, hkOstream *os)
{
  int v3; // esi
  void *v7; // r15
  __int64 v8; // rbx
  hkTypeManager::Type *Type; // rdi
  hkTypeManager::SubType m_subType; // edx
  const char *v11; // rbp
  const char *v12; // rax
  const char *v13; // rax
  int TupleSize; // eax
  _WORD *v15; // rax
  int v16; // edi
  const char *v18; // rax
  int v19; // ebx
  int v20; // eax
  int v21; // eax
  int v22; // r9d
  __int64 v23; // [rsp+28h] [rbp-40h]
  hkDataObject_Value value; // [rsp+30h] [rbp-38h] BYREF
  __int64 result; // [rsp+70h] [rbp+8h] BYREF

  v3 = 0;
  LODWORD(result) = 0;
  `anonymous namespace::Indenter::push(&this->m_indenter);
  v7 = (void *)((unsigned int (__fastcall *)(hkDataObjectImpl *))obj->m_impl->vfptr[5].__vecDelDtor)(obj->m_impl);
  if ( obj->m_impl->vfptr[6].__vecDelDtor(obj->m_impl, v7) )
  {
    v8 = result;
    do
    {
      ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, _QWORD))obj->m_impl->vfptr[9].__vecDelDtor)(
        obj->m_impl,
        &value,
        (unsigned int)v7);
      Type = hkDataObject_Value::getType(&value);
      if ( (unsigned int)anonymous_namespace_::worthPrinting_hkDataObject_Value_(&value) )
      {
        m_subType = Type->m_subType;
        if ( Type->m_subType == SUB_TYPE_ARRAY
          || m_subType == SUB_TYPE_TUPLE
          && (Type->m_parent->m_subType != SUB_TYPE_REAL || ((Type->m_extra.m_size - 4) & 0xFFFFFFF3) != 0) )
        {
          v11 = "array";
          if ( m_subType == SUB_TYPE_TUPLE )
            v11 = "tuple";
          if ( m_subType == SUB_TYPE_TUPLE )
          {
            TupleSize = hkTypeManager::Type::getTupleSize(Type);
          }
          else
          {
            v3 |= 1u;
            v15 = value.m_impl->vfptr[10].__vecDelDtor(value.m_impl, value.m_handle);
            v8 = (__int64)v15;
            if ( v15 )
            {
              ++v15[5];
              ++*((_DWORD *)v15 + 3);
            }
            TupleSize = (*(__int64 (__fastcall **)(_WORD *))(*(_QWORD *)v15 + 40i64))(v15);
          }
          v16 = TupleSize;
          if ( (v3 & 1) != 0 )
          {
            v3 &= ~1u;
            if ( v8 )
            {
              --*(_WORD *)(v8 + 10);
              if ( (*(_DWORD *)(v8 + 12))-- == 1 )
                (**(void (__fastcall ***)(__int64, __int64))v8)(v8, 1i64);
            }
          }
          v18 = (const char *)obj->m_impl->vfptr[8].__vecDelDtor(obj->m_impl, (unsigned int)v7);
          LODWORD(v23) = v16;
          hkOstream::printf(os, "\n%s<%s name=\"%s\" size=\"%i\">", this->m_indenter.m_indent.m_data, v11, v18, v23);
          goto LABEL_24;
        }
        v11 = anonymous_namespace_::nameFromType(Type);
        if ( Type->m_subType != SUB_TYPE_CSTRING || value.m_impl->vfptr[11].__vecDelDtor(value.m_impl, value.m_handle) )
        {
          v13 = (const char *)obj->m_impl->vfptr[8].__vecDelDtor(obj->m_impl, (unsigned int)v7);
          hkOstream::printf(os, "\n%s<%s name=\"%s\">", this->m_indenter.m_indent.m_data, v11, v13);
LABEL_24:
          `anonymous namespace::Context::writeValue<hkDataObject_Value>(this, &value, os);
          hkOstream::printf(os, "</%s>", v11);
          goto LABEL_25;
        }
        v12 = (const char *)obj->m_impl->vfptr[8].__vecDelDtor(obj->m_impl, (unsigned int)v7);
        hkOstream::printf(os, "\n%s<null name=\"%s\"/>", this->m_indenter.m_indent.m_data, v12);
      }
LABEL_25:
      v7 = obj->m_impl->vfptr[7].__vecDelDtor(obj->m_impl, (unsigned int)v7);
    }
    while ( obj->m_impl->vfptr[6].__vecDelDtor(obj->m_impl, v7) );
  }
  this->m_indenter.m_indent.m_data[this->m_indenter.m_indent.m_size - (__int64)(int)this->m_indenter.m_indentStep] = 0;
  v19 = this->m_indenter.m_indent.m_size - this->m_indenter.m_indentStep;
  v20 = this->m_indenter.m_indent.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < v19 )
  {
    v21 = 2 * v20;
    v22 = this->m_indenter.m_indent.m_size - this->m_indenter.m_indentStep;
    if ( v19 < v21 )
      v22 = v21;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_indenter.m_indent.m_data,
      v22,
      1);
  }
  this->m_indenter.m_indent.m_size = v19;
}

// File Line: 683
// RVA: 0xE57FB0
void __fastcall `anonymous namespace::Context::writeFile(Context *this, hkDataObject *topObj, hkStreamWriter *stream)
{
  int i; // ebx
  __int64 v6; // rax
  int v7; // r14d
  __int64 v8; // r15
  hkDataObjectImpl *m_impl; // rbx
  int *v10; // rax
  unsigned int v11; // esi
  __int64 v12; // rax
  const char *v13; // rax
  hkDataObjectImpl *v14; // rcx
  int v16; // ebx
  int v17; // eax
  int v18; // eax
  int v19; // r9d
  int sizeElem[4]; // [rsp+18h] [rbp-29h] BYREF
  hkDataObject_Handle v21; // [rsp+28h] [rbp-19h] BYREF
  char v22[16]; // [rsp+38h] [rbp-9h] BYREF
  hkOstream os; // [rsp+48h] [rbp+7h] BYREF
  hkDataObject obj; // [rsp+A8h] [rbp+67h] BYREF

  hkOstream::hkOstream(&os, stream);
  hkOstream::printf(&os, "<?xml version=\"1.0\" encoding=\"ascii\"?>");
  hkOstream::printf(&os, "\n<hktagfile version=\"%d\" sdkversion=\"%s\">\n", 1i64, "hk_2013.2.0-r1");
  `anonymous namespace::Indenter::push(&this->m_indenter);
  for ( i = 0; i < this->m_seenObjects.m_classes.m_size; ++i )
    `anonymous namespace::Context::writeClass(this, &this->m_seenObjects.m_classes.m_data[i], &os);
  v6 = ((__int64 (__fastcall *)(hkDataObjectImpl *))topObj->m_impl->vfptr[2].__vecDelDtor)(topObj->m_impl);
  v7 = 1;
  v8 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 8i64))(v6);
  if ( this->m_seenObjects.m_objects.m_size > 1 )
  {
    memset(sizeElem, 0, sizeof(sizeElem));
    do
    {
      (*(void (__fastcall **)(__int64, hkDataObject *, hkDataObject_Handle *))(*(_QWORD *)v8 + 80i64))(
        v8,
        &obj,
        &this->m_seenObjects.m_objects.m_data[v7]);
      m_impl = obj.m_impl;
      if ( obj.m_impl )
      {
        v10 = (int *)obj.m_impl->vfptr[1].__vecDelDtor(obj.m_impl, v22);
        m_impl = obj.m_impl;
      }
      else
      {
        *(_OWORD *)sizeElem = 0u;
        v10 = sizeElem;
      }
      v21 = *(hkDataObject_Handle *)v10;
      v11 = hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
              &this->m_seenObjects.m_objectIndexFromHandle,
              &v21,
              0xFFFFFFFF);
      v12 = ((__int64 (__fastcall *)(hkDataObjectImpl *))m_impl->vfptr[2].__vecDelDtor)(m_impl);
      v13 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v12 + 16i64))(v12);
      hkOstream::printf(&os, "\n%s<object id=\"#%04i\" type=\"%s\">", this->m_indenter.m_indent.m_data, v11, v13);
      `anonymous namespace::Context::writeObjectMembers(this, &obj, &os);
      hkOstream::printf(&os, "\n%s</object>", this->m_indenter.m_indent.m_data);
      v14 = obj.m_impl;
      if ( obj.m_impl )
      {
        --obj.m_impl->m_externalCount;
        if ( v14->m_count-- == 1 )
          v14->vfptr->__vecDelDtor(v14, 1u);
      }
      ++v7;
    }
    while ( v7 < this->m_seenObjects.m_objects.m_size );
  }
  this->m_indenter.m_indent.m_data[this->m_indenter.m_indent.m_size - (__int64)(int)this->m_indenter.m_indentStep] = 0;
  v16 = this->m_indenter.m_indent.m_size - this->m_indenter.m_indentStep;
  v17 = this->m_indenter.m_indent.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v17 < v16 )
  {
    v18 = 2 * v17;
    v19 = this->m_indenter.m_indent.m_size - this->m_indenter.m_indentStep;
    if ( v16 < v18 )
      v19 = v18;
    hkArrayUtil::_reserve(
      (hkResult *)&obj,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_indenter.m_indent.m_data,
      v19,
      1);
  }
  this->m_indenter.m_indent.m_size = v16;
  hkOstream::printf(&os, "\n</hktagfile>\n");
  hkOstream::~hkOstream(&os);
}

// File Line: 715
// RVA: 0xE55FD0
hkResult *__fastcall hkXmlTagfileWriter::save(
        hkXmlTagfileWriter *this,
        hkResult *result,
        hkDataObject *obj,
        hkStreamWriter *stream,
        hkTagfileWriter::AddDataObjectListener *userListener,
        hkTagfileWriter::Options *options)
{
  Context array; // [rsp+20h] [rbp-88h] BYREF

  array.m_indenter.m_indent.m_data = 0i64;
  array.m_indenter.m_indent.m_size = 0;
  array.m_indenter.m_indent.m_capacityAndFlags = 0x80000000;
  array.m_indenter.m_indentStep = 2;
  array.m_indenter.m_value = 32;
  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_indenter.m_indent.m_data, 1);
  array.m_indenter.m_indent.m_data[array.m_indenter.m_indent.m_size] = 0;
  `anonymous namespace::SeenObjects::SeenObjects(&array.m_seenObjects, userListener);
  array.m_writeFloatAsHex.m_bool = options->m_exact.m_bool;
  array.m_floatComment.m_bool = options->m_verbose.m_bool;
  `anonymous namespace::SeenObjects::scanObject(&array.m_seenObjects, obj);
  `anonymous namespace::Context::writeFile(&array, obj, stream);
  stream->vfptr[2].__first_virtual_table_function__(stream);
  result->m_enum = *(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, hkTagfileWriter::Options **))stream->vfptr[1].__first_virtual_table_function__)(
                               stream,
                               &options) == 0;
  `anonymous namespace::SeenObjects::~SeenObjects(&array.m_seenObjects);
  array.m_indenter.m_indent.m_size = 0;
  if ( array.m_indenter.m_indent.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_indenter.m_indent.m_data,
      array.m_indenter.m_indent.m_capacityAndFlags & 0x3FFFFFFF);
  return result;
}

