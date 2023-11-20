// File Line: 21
// RVA: 0xE564B0
signed __int64 __usercall anonymous_namespace_::worthPrinting_hkDataArray_Value_@<rax>(hkDataArray_Value *value@<rcx>, float a2@<xmm0>)
{
  hkDataArray_Value *v2; // rbx
  __int64 v3; // rax
  int v4; // ecx
  __int64 v5; // rax
  __int64 v6; // rbx
  unsigned int v7; // eax
  bool v8; // zf
  unsigned int v9; // edi
  signed __int64 result; // rax
  __int64 v11; // rax
  hkDataArrayImpl *v12; // rbx
  BOOL v13; // ebp
  int v14; // edi
  __int64 v15; // rax
  hkDataArray_Value valuea; // [rsp+20h] [rbp-18h]
  int v17; // [rsp+40h] [rbp+8h]

  v2 = value;
  v3 = ((__int64 (*)(void))value->m_impl->vfptr[1].__vecDelDtor)();
  v4 = *(_DWORD *)v3;
  if ( *(_DWORD *)v3 == 8 )
  {
    v5 = (__int64)v2->m_impl->vfptr[23].__vecDelDtor((hkDataRefCounted *)v2->m_impl, v2->m_index);
    v6 = v5;
    if ( v5 )
    {
      ++*(_WORD *)(v5 + 10);
      ++*(_DWORD *)(v5 + 12);
    }
    v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v5 + 40i64))(v5);
    --*(_WORD *)(v6 + 10);
    v8 = (*(_DWORD *)(v6 + 12))-- == 1;
    v9 = v7;
    if ( v8 )
      (**(void (__fastcall ***)(__int64, signed __int64))v6)(v6, 1i64);
    result = v9;
  }
  else if ( v4 == 9 )
  {
    if ( **(_DWORD **)(v3 + 8) != 3 || (*(_DWORD *)(v3 + 16) - 4) & 0xFFFFFFF3 )
    {
      v11 = (__int64)v2->m_impl->vfptr[23].__vecDelDtor((hkDataRefCounted *)v2->m_impl, v2->m_index);
      v12 = (hkDataArrayImpl *)v11;
      if ( v11 )
      {
        ++*(_WORD *)(v11 + 10);
        ++*(_DWORD *)(v11 + 12);
      }
      v13 = 0;
      v17 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 40i64))(v11);
      v14 = 0;
      if ( v17 > 0 )
      {
        while ( 1 )
        {
          valuea.m_impl = v12;
          valuea.m_index = v14;
          if ( anonymous_namespace_::worthPrinting_hkDataArray_Value_(&valuea) )
            break;
          if ( ++v14 >= v17 )
            goto LABEL_18;
        }
        v13 = 1;
      }
LABEL_18:
      --v12->m_externalCount;
      v8 = v12->m_count-- == 1;
      if ( v8 )
      {
        v12->vfptr->__vecDelDtor((hkDataRefCounted *)&v12->vfptr, 1u);
        result = (unsigned int)v13;
      }
      else
      {
LABEL_28:
        result = (unsigned int)v13;
      }
    }
    else
    {
      result = 1i64;
    }
  }
  else
  {
    switch ( v4 )
    {
      case 2:
      case 4:
        result = (__int64)v2->m_impl->vfptr[19].__vecDelDtor((hkDataRefCounted *)v2->m_impl, v2->m_index) != 0;
        break;
      case 3:
        v2->m_impl->vfptr[15].__vecDelDtor((hkDataRefCounted *)v2->m_impl, v2->m_index);
        result = a2 != 0.0;
        break;
      case 5:
        result = (__int64)v2->m_impl->vfptr[13].__vecDelDtor((hkDataRefCounted *)v2->m_impl, v2->m_index) != 0;
        break;
      case 6:
      case 7:
        v15 = (__int64)v2->m_impl->vfptr[21].__vecDelDtor((hkDataRefCounted *)v2->m_impl, v2->m_index);
        if ( v15 )
        {
          ++*(_WORD *)(v15 + 10);
          ++*(_DWORD *)(v15 + 12);
        }
        v13 = v15 != 0;
        if ( v15 )
        {
          --*(_WORD *)(v15 + 10);
          v8 = (*(_DWORD *)(v15 + 12))-- == 1;
          if ( v8 )
            (**(void (__fastcall ***)(__int64, signed __int64))v15)(v15, 1i64);
        }
        goto LABEL_28;
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
  int v2; // eax

  switch ( type->m_subType )
  {
    case 1:
      result = "void";
      break;
    case 2:
      result = "byte";
      break;
    case 3:
      result = "real";
      break;
    case 4:
      result = "int";
      break;
    case 5:
      result = "string";
      break;
    case 6:
      result = "struct";
      break;
    case 7:
      result = "ref";
      break;
    case 9:
      if ( type->m_parent->m_subType != 3 )
        goto LABEL_18;
      v2 = hkTypeManager::Type::getTupleSize(type);
      switch ( v2 )
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
signed __int64 __fastcall anonymous_namespace_::calcWrapMod(hkTypeManager::Type *type)
{
  signed __int64 result; // rax

  switch ( type->m_subType )
  {
    case 1:
      result = 32i64;
      break;
    case 2:
      result = 16i64;
      break;
    case 3:
    case 4:
      result = 8i64;
      break;
    case 6:
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
void __fastcall `anonymous namespace'::Indenter::push(Indenter *this)
{
  Indenter *v1; // rbx
  int v2; // edi
  int v3; // eax
  int v4; // eax
  int v5; // er9
  signed __int64 v6; // rdx
  int v7; // ecx
  char *v8; // r9
  hkResult result; // [rsp+40h] [rbp+8h]

  v1 = this;
  v2 = this->m_indent.m_size + this->m_indentStep;
  v3 = this->m_indent.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v3 < v2 )
  {
    v4 = 2 * v3;
    v5 = this->m_indent.m_size + this->m_indentStep;
    if ( v2 < v4 )
      v5 = v4;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, v5, 1);
  }
  v6 = 0i64;
  v7 = v2 - v1->m_indent.m_size;
  v8 = &v1->m_indent.m_data[v1->m_indent.m_size];
  if ( v7 > 0 )
  {
    do
      v8[++v6 - 1] = v1->m_value;
    while ( v6 < v7 );
  }
  v1->m_indent.m_size = v2;
  if ( v2 == (v1->m_indent.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v1, 1);
  v1->m_indent.m_data[v1->m_indent.m_size] = 0;
}

// File Line: 146
// RVA: 0xE57530
void __fastcall `anonymous namespace'::Indenter::pop(Indenter *this)
{
  Indenter *v1; // rbx
  int v2; // edi
  int v3; // eax
  int v4; // eax
  int v5; // er9
  hkResult result; // [rsp+40h] [rbp+8h]

  v1 = this;
  this->m_indent.m_data[this->m_indent.m_size - (signed __int64)(signed int)this->m_indentStep] = 0;
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
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, v5, 1);
    v1->m_indent.m_size = v2;
  }
}

// File Line: 187
// RVA: 0xE56F40
void __fastcall `anonymous namespace'::SeenObjects::SeenObjects(SeenObjects *this, hkTagfileWriter::AddDataObjectListener *listener)
{
  SeenObjects *v2; // rdi
  int v3; // eax
  __m128i v4; // xmm0
  hkDataObject_Handle *v5; // rax
  __m128i v6; // [rsp+20h] [rbp-18h]

  this->m_objectIndexFromHandle.m_hashMod = -1;
  this->m_objectIndexFromHandle.m_elem = 0i64;
  this->m_objectIndexFromHandle.m_numElems = 0;
  this->m_objects.m_data = 0i64;
  this->m_objects.m_size = 0;
  this->m_objects.m_capacityAndFlags = 2147483648;
  this->m_listener = listener;
  this->m_cachedObjects.m_data = 0i64;
  this->m_cachedObjects.m_size = 0;
  this->m_cachedObjects.m_capacityAndFlags = 2147483648;
  this->m_classes.m_data = 0i64;
  this->m_classes.m_size = 0;
  this->m_classes.m_capacityAndFlags = 2147483648;
  v2 = this;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_classIndexFromName.m_map,
    0);
  v3 = v2->m_objects.m_capacityAndFlags;
  v6 = 0ui64;
  if ( v2->m_objects.m_size == (v3 & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_objects, 16);
  v4 = v6;
  v5 = &v2->m_objects.m_data[v2->m_objects.m_size];
  if ( v5 )
    *v5 = (hkDataObject_Handle)v6;
  ++v2->m_objects.m_size;
  _mm_store_si128(&v6, v4);
  hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::insert(
    (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v2->m_objectIndexFromHandle.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (hkDataObject_Handle *)&v6,
    0);
}

// File Line: 195
// RVA: 0xE57660
void __fastcall `anonymous namespace'::SeenObjects::scanObject(SeenObjects *this, hkDataObject *objIn)
{
  SeenObjects *v2; // rsi
  hkDataObject *v3; // rdi
  hkDataObjectImpl *v4; // rcx
  bool v5; // zf
  hkDataObjectImpl *v6; // rbx
  int v7; // er13
  void **v8; // rax
  void *v9; // r15
  void *v10; // r12
  hkDataObject_Handle *v11; // rax
  hkDataObject v12; // rcx
  __m128i *v13; // rax
  hkDataObject v14; // rcx
  __m128i *v15; // rax
  __int64 v16; // rdi
  __int64 v17; // r14
  _QWORD *v18; // rax
  __m128i v19; // [rsp+20h] [rbp-40h]
  char v20; // [rsp+30h] [rbp-30h]
  hkDataObject result; // [rsp+88h] [rbp+28h]
  hkDataClass k; // [rsp+90h] [rbp+30h]

  v2 = this;
  v3 = objIn;
  if ( objIn->m_impl )
  {
    v19 = *(__m128i *)objIn->m_impl->vfptr[1].__vecDelDtor((hkDataRefCounted *)objIn->m_impl, (unsigned int)&v19);
    if ( (unsigned int)hkMapBase<hkDataObject_Handle,int,`anonymous namespace'::HandleOps>::getWithDefault(
                         (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v2->m_objectIndexFromHandle.m_elem,
                         (hkDataObject_Handle *)&v19,
                         -1) == -1 )
    {
      `anonymous namespace'::SeenObjects::callListenerAndCache(v2, &result, v3);
      if ( v3->m_impl )
      {
        v6 = result.m_impl;
        k.m_impl = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataObjectImpl *))result.m_impl->vfptr[2].__vecDelDtor)(result.m_impl);
        `anonymous namespace'::SeenObjects::addClass(v2, &k);
        v7 = v2->m_objects.m_size;
        v8 = (void **)v6->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v6->vfptr, (unsigned int)&v19);
        v9 = *v8;
        v10 = v8[1];
        if ( v2->m_objects.m_size == (v2->m_objects.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_objects, 16);
        v11 = &v2->m_objects.m_data[v2->m_objects.m_size];
        if ( v11 )
        {
          v11->p0 = v9;
          v11->p1 = v10;
        }
        ++v2->m_objects.m_size;
        v12.m_impl = v3->m_impl;
        v19 = 0ui64;
        if ( v12.m_impl )
        {
          v13 = (__m128i *)((__int64 (__fastcall *)(hkDataObject, __m128i *))v12.m_impl->vfptr[1].__vecDelDtor)(
                             v12,
                             &v19);
        }
        else
        {
          v13 = &v19;
          _mm_store_si128(&v19, v19);
        }
        v19 = *v13;
        hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::insert(
          (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v2->m_objectIndexFromHandle.m_elem,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          (hkDataObject_Handle *)&v19,
          v7);
        v14.m_impl = v3->m_impl;
        v19 = 0ui64;
        if ( v14.m_impl )
        {
          v15 = (__m128i *)((__int64 (__fastcall *)(hkDataObject, __m128i *))v14.m_impl->vfptr[1].__vecDelDtor)(
                             v14,
                             &v19);
        }
        else
        {
          v15 = &v19;
          _mm_store_si128(&v19, v19);
        }
        v16 = v15->m128i_i64[0];
        v17 = v15->m128i_i64[1];
        v18 = (_QWORD *)v6->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v6->vfptr, (unsigned int)&v20);
        if ( *v18 != v16 || v18[1] != v17 )
        {
          v19 = *(__m128i *)v6->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v6->vfptr, (unsigned int)&v20);
          hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::insert(
            (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v2->m_objectIndexFromHandle.m_elem,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            (hkDataObject_Handle *)&v19,
            v7);
        }
        `anonymous namespace'::SeenObjects::scanObjectMembers(v2, &result);
        --v6->m_externalCount;
        v5 = v6->m_count-- == 1;
        if ( v5 )
          v6->vfptr->__vecDelDtor((hkDataRefCounted *)&v6->vfptr, 1u);
      }
      else
      {
        v4 = result.m_impl;
        if ( result.m_impl )
        {
          --result.m_impl->m_externalCount;
          v5 = v4->m_count-- == 1;
          if ( v5 )
            v4->vfptr->__vecDelDtor((hkDataRefCounted *)&v4->vfptr, 1u);
        }
      }
    }
  }
}

// File Line: 229
// RVA: 0xE57880
void __fastcall `anonymous namespace'::SeenObjects::scanObjectMembers(SeenObjects *this, hkDataObject *obj)
{
  SeenObjects *v2; // rbp
  hkDataObject *v3; // rdi
  unsigned int v4; // ebx
  hkTypeManager::Type *v5; // rbx
  hkTypeManager::SubType v6; // ecx
  hkTypeManager::Type *v7; // rax
  hkDataObjectImpl *v8; // rax
  hkDataObjectImpl *v9; // rbx
  signed int v10; // edi
  signed int v11; // esi
  hkDataObjectImpl *v12; // rax
  hkDataObjectImpl *v13; // rcx
  bool v14; // zf
  hkDataRefCountedVtbl *v15; // rax
  hkDataObjectImpl *v16; // rcx
  hkDataObjectImpl *v17; // rax
  signed int v18; // edi
  signed int v19; // esi
  hkDataObjectImpl *v20; // rax
  hkDataObjectImpl *v21; // rcx
  hkDataObjectImpl *v22; // rax
  hkDataObjectImpl *v23; // rax
  hkDataObject obja; // [rsp+20h] [rbp-48h]
  hkDataObject v25; // [rsp+28h] [rbp-40h]
  hkDataObject v26; // [rsp+30h] [rbp-38h]
  hkDataObject_Value v27; // [rsp+38h] [rbp-30h]
  hkDataObject *v28; // [rsp+78h] [rbp+10h]
  unsigned int v29; // [rsp+80h] [rbp+18h]
  hkDataObject objIn; // [rsp+88h] [rbp+20h]

  v28 = obj;
  v2 = this;
  v3 = obj;
  v4 = ((__int64 (*)(void))obj->m_impl->vfptr[5].__vecDelDtor)();
  v29 = v4;
  if ( v3->m_impl->vfptr[6].__vecDelDtor((hkDataRefCounted *)v3->m_impl, v4) )
  {
    do
    {
      ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, _QWORD))v3->m_impl->vfptr[9].__vecDelDtor)(
        v3->m_impl,
        &v27,
        v4);
      v5 = hkDataObject_Value::getType(&v27);
      if ( hkTypeManager::Type::findTerminal(v5)->m_subType == 6 )
      {
        v6 = v5->m_subType;
        if ( v5->m_subType == 6 )
        {
          v23 = (hkDataObjectImpl *)v27.m_impl->vfptr[13].__vecDelDtor(
                                      (hkDataRefCounted *)v27.m_impl,
                                      (unsigned int)v27.m_handle);
          v26.m_impl = v23;
          if ( v23 )
          {
            ++v23->m_externalCount;
            ++v23->m_count;
          }
          `anonymous namespace'::SeenObjects::scanObjectMembers(v2, &v26);
          v16 = v26.m_impl;
          goto LABEL_36;
        }
        if ( v6 == 7 )
        {
          v22 = (hkDataObjectImpl *)v27.m_impl->vfptr[13].__vecDelDtor(
                                      (hkDataRefCounted *)v27.m_impl,
                                      (unsigned int)v27.m_handle);
          v25.m_impl = v22;
          if ( v22 )
          {
            ++v22->m_externalCount;
            ++v22->m_count;
          }
          `anonymous namespace'::SeenObjects::scanObject(v2, &v25);
          v16 = v25.m_impl;
LABEL_36:
          if ( !v16 )
            goto LABEL_40;
          --v16->m_externalCount;
          v14 = v16->m_count-- == 1;
          if ( !v14 )
            goto LABEL_40;
          v15 = v16->vfptr;
          goto LABEL_39;
        }
        if ( (unsigned int)(v6 - 8) <= 1 )
        {
          v7 = v5->m_parent;
          if ( v7->m_subType != 7 || v7->m_parent->m_subType != 6 )
          {
            if ( v7->m_subType != 6 )
              goto LABEL_40;
            v17 = (hkDataObjectImpl *)v27.m_impl->vfptr[10].__vecDelDtor(
                                        (hkDataRefCounted *)v27.m_impl,
                                        (unsigned int)v27.m_handle);
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
                v20 = (hkDataObjectImpl *)v9->vfptr[21].__vecDelDtor((hkDataRefCounted *)&v9->vfptr, v18);
                obja.m_impl = v20;
                if ( v20 )
                {
                  ++v20->m_externalCount;
                  ++v20->m_count;
                }
                `anonymous namespace'::SeenObjects::scanObjectMembers(v2, &obja);
                v21 = obja.m_impl;
                if ( obja.m_impl )
                {
                  --obja.m_impl->m_externalCount;
                  v14 = v21->m_count-- == 1;
                  if ( v14 )
                    v21->vfptr->__vecDelDtor((hkDataRefCounted *)&v21->vfptr, 1u);
                }
                ++v18;
              }
              while ( v18 < v19 );
            }
          }
          else
          {
            v8 = (hkDataObjectImpl *)v27.m_impl->vfptr[10].__vecDelDtor(
                                       (hkDataRefCounted *)v27.m_impl,
                                       (unsigned int)v27.m_handle);
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
                v12 = (hkDataObjectImpl *)v9->vfptr[21].__vecDelDtor((hkDataRefCounted *)&v9->vfptr, v10);
                objIn.m_impl = v12;
                if ( v12 )
                {
                  ++v12->m_externalCount;
                  ++v12->m_count;
                }
                `anonymous namespace'::SeenObjects::scanObject(v2, &objIn);
                v13 = objIn.m_impl;
                if ( objIn.m_impl )
                {
                  --objIn.m_impl->m_externalCount;
                  v14 = v13->m_count-- == 1;
                  if ( v14 )
                    v13->vfptr->__vecDelDtor((hkDataRefCounted *)&v13->vfptr, 1u);
                }
                ++v10;
              }
              while ( v10 < v11 );
            }
          }
          --v9->m_externalCount;
          v14 = v9->m_count-- == 1;
          if ( v14 )
          {
            v15 = v9->vfptr;
            v16 = v9;
LABEL_39:
            v15->__vecDelDtor((hkDataRefCounted *)&v16->vfptr, 1u);
            goto LABEL_40;
          }
        }
      }
LABEL_40:
      v4 = (__int64)v28->m_impl->vfptr[7].__vecDelDtor((hkDataRefCounted *)v28->m_impl, v29);
      v29 = v4;
      v3 = v28;
    }
    while ( v28->m_impl->vfptr[6].__vecDelDtor((hkDataRefCounted *)v28->m_impl, v4) );
  }
}

// File Line: 291
// RVA: 0xE57370
hkDataObject *__fastcall `anonymous namespace'::SeenObjects::callListenerAndCache(SeenObjects *this, hkDataObject *result, hkDataObject *object)
{
  SeenObjects *v3; // rsi
  hkTagfileWriter::AddDataObjectListener *v4; // rcx
  hkDataObject *v5; // rbx
  hkDataObject *v6; // rdi
  _WORD *v7; // r8
  __m128i *v8; // rax
  __int64 v9; // r15
  __int64 v10; // r14
  hkDataObjectImpl *v11; // rcx
  __m128i *v12; // rax
  bool v13; // zf
  hkDataObjectImpl *v14; // rax
  signed __int64 v16; // rbx
  _QWORD *v17; // rdx
  __int64 v18; // rdx
  __int64 *v19; // rsi
  __int64 v20; // rcx
  _WORD *v21; // rax
  _WORD *v22; // rcx
  __m128i v23; // [rsp+20h] [rbp-20h]
  char v24; // [rsp+30h] [rbp-10h]
  _WORD *v25; // [rsp+70h] [rbp+30h]

  v3 = this;
  v4 = this->m_listener;
  v5 = object;
  v6 = result;
  if ( !v4 )
  {
LABEL_13:
    v14 = v5->m_impl;
    v6->m_impl = v5->m_impl;
    if ( v14 )
    {
      ++v14->m_externalCount;
      ++v14->m_count;
    }
    return v6;
  }
  ((void (__fastcall *)(hkTagfileWriter::AddDataObjectListener *, _WORD **))v4->vfptr[1].__first_virtual_table_function__)(
    v4,
    &v25);
  v7 = v25;
  v23 = 0ui64;
  if ( v25 )
  {
    v8 = (__m128i *)(*(__int64 (__fastcall **)(_WORD *, char *))(*(_QWORD *)v25 + 8i64))(v25, &v24);
    v7 = v25;
  }
  else
  {
    v8 = &v23;
    _mm_store_si128(&v23, v23);
  }
  v9 = v8->m128i_i64[0];
  v10 = v8->m128i_i64[1];
  v11 = v5->m_impl;
  v23 = 0ui64;
  if ( v11 )
  {
    v12 = (__m128i *)((__int64 (__fastcall *)(hkDataObjectImpl *, __m128i *, _WORD *))v11->vfptr[1].__vecDelDtor)(
                       v11,
                       &v23,
                       v7);
    v7 = v25;
  }
  else
  {
    v12 = &v23;
    _mm_store_si128(&v23, v23);
  }
  if ( v9 == v12->m128i_i64[0] && v10 == v12->m128i_i64[1] )
  {
    if ( v7 )
    {
      --v7[5];
      v13 = (*((_DWORD *)v7 + 3))-- == 1;
      if ( v13 )
        (**(void (__fastcall ***)(_WORD *, signed __int64))v7)(v7, 1i64);
    }
    goto LABEL_13;
  }
  v16 = (signed __int64)&v3->m_cachedObjects;
  if ( v3->m_cachedObjects.m_size == (v3->m_cachedObjects.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_cachedObjects, 8);
    v7 = v25;
  }
  v17 = (_QWORD *)(*(_QWORD *)v16 + 8i64 * v3->m_cachedObjects.m_size);
  if ( v17 )
  {
    *v17 = 0i64;
    v7 = v25;
  }
  v18 = v3->m_cachedObjects.m_size;
  v19 = (__int64 *)(*(_QWORD *)v16 + 8 * v18);
  *(_DWORD *)(v16 + 8) = v18 + 1;
  if ( v7 )
  {
    ++v7[5];
    ++*((_DWORD *)v7 + 3);
    v7 = v25;
  }
  v20 = *v19;
  if ( *v19 )
  {
    --*(_WORD *)(v20 + 10);
    v13 = (*(_DWORD *)(v20 + 12))-- == 1;
    if ( v13 )
      (**(void (__fastcall ***)(__int64, signed __int64, _WORD *))v20)(v20, 1i64, v7);
    v7 = v25;
  }
  *v19 = (__int64)v7;
  v21 = v25;
  v6->m_impl = (hkDataObjectImpl *)v25;
  if ( v21 )
  {
    ++v21[5];
    ++*((_DWORD *)v21 + 3);
    v22 = v25;
    if ( v25 )
    {
      --v25[5];
      v13 = (*((_DWORD *)v22 + 3))-- == 1;
      if ( v13 )
        (**(void (__fastcall ***)(_WORD *, signed __int64))v22)(v22, 1i64);
    }
  }
  return v6;
}

// File Line: 307
// RVA: 0xE57140
void __fastcall `anonymous namespace'::SeenObjects::addClass(SeenObjects *this, hkDataClass *k)
{
  SeenObjects *v2; // rsi
  hkDataClass *v3; // rdi
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rax
  hkDataClass *v7; // rdx
  hkDataClassImpl *v8; // rcx
  __int64 v9; // rbp
  int v10; // eax
  int v11; // ebx
  int v12; // er9
  __int64 v13; // rdx
  char *v14; // rax
  int v15; // esi
  _QWORD *v16; // rax
  __int64 v17; // rdi
  _QWORD *v18; // rbx
  const char *v19; // rax
  char *array; // [rsp+30h] [rbp-38h]
  int v21; // [rsp+38h] [rbp-30h]
  int v22; // [rsp+3Ch] [rbp-2Ch]
  SeenObjects *v23; // [rsp+70h] [rbp+8h]
  hkDataClass *v24; // [rsp+78h] [rbp+10h]
  hkDataClass ka; // [rsp+80h] [rbp+18h]
  hkDataClass v26; // [rsp+88h] [rbp+20h]

  v24 = k;
  v23 = this;
  v2 = this;
  v3 = k;
  v4 = ((__int64 (*)(void))k->m_impl->vfptr[2].__vecDelDtor)();
  if ( (unsigned int)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                       (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_classIndexFromName,
                       v4,
                       0xFFFFFFFFFFFFFFFFui64) == -1 )
  {
    if ( ((__int64 (*)(void))v3->m_impl->vfptr[4].__vecDelDtor)() )
    {
      ka.m_impl = (hkDataClassImpl *)((__int64 (*)(void))v3->m_impl->vfptr[4].__vecDelDtor)();
      `anonymous namespace'::SeenObjects::addClass(v2, &ka);
    }
    v5 = v2->m_classes.m_size;
    v6 = ((__int64 (*)(void))v3->m_impl->vfptr[2].__vecDelDtor)();
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&v2->m_classIndexFromName.m_map, v6, v5);
    if ( v2->m_classes.m_size == (v2->m_classes.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_classes, 8);
    v7 = &v2->m_classes.m_data[v2->m_classes.m_size];
    if ( v7 )
      v7->m_impl = v3->m_impl;
    ++v2->m_classes.m_size;
    v8 = v3->m_impl;
    v9 = 0i64;
    array = 0i64;
    v21 = 0;
    v22 = 2147483648;
    v10 = ((__int64 (*)(void))v8->vfptr[6].__vecDelDtor)();
    v11 = v10;
    if ( v10 > 0 )
    {
      v12 = v10;
      if ( v10 < 0 )
        v12 = 0;
      hkArrayUtil::_reserve(
        (hkResult *)&ka,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        &array,
        v12,
        32);
    }
    v13 = v11 - v21;
    if ( v11 - v21 > 0 )
    {
      v14 = &array[32 * v21 + 16];
      do
      {
        if ( v14 != (char *)16 )
        {
          *((_QWORD *)v14 - 2) = 0i64;
          *((_QWORD *)v14 - 1) = 0i64;
          *(_QWORD *)v14 = 0i64;
          *((_QWORD *)v14 + 1) = 0i64;
        }
        v14 += 32;
        --v13;
      }
      while ( v13 );
    }
    v21 = v11;
    hkDataClass::getAllDeclaredMemberInfo(v3, (hkArrayBase<hkDataClass_MemberInfo> *)&array);
    v15 = 0;
    if ( v21 > 0 )
    {
      do
      {
        ka.m_impl = (hkDataClassImpl *)hkTypeManager::Type::findTerminal(*(hkTypeManager::Type **)&array[v9 + 16]);
        if ( LODWORD(ka.m_impl->vfptr) == 6 )
        {
          v16 = (_QWORD *)((__int64 (*)(void))v3->m_impl->vfptr[1].__vecDelDtor)();
          v17 = *v16;
          v18 = v16;
          v19 = hkTypeManager::Type::getTypeName((hkTypeManager::Type *)ka.m_impl);
          v26.m_impl = (hkDataClassImpl *)(*(__int64 (__fastcall **)(_QWORD *, const char *))(v17 + 72))(v18, v19);
          `anonymous namespace'::SeenObjects::addClass(v23, &v26);
          v3 = v24;
        }
        ++v15;
        v9 += 32i64;
      }
      while ( v15 < v21 );
      LODWORD(v9) = 0;
    }
    v21 = v9;
    if ( v22 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        32 * v22);
  }
}

// File Line: 391
// RVA: 0xE57C80
void __fastcall `anonymous namespace'::Context::writeClass(Context *this, hkDataClass *k, hkOstream *os)
{
  Context *v3; // rsi
  hkOstream *v4; // rbp
  hkDataClass *v5; // rdi
  int v6; // ebx
  int v7; // eax
  char *v8; // r8
  __int64 v9; // rax
  __int64 v10; // rax
  int v11; // eax
  hkDataClassImpl *v12; // rcx
  int v13; // er14
  int v14; // eax
  int v15; // ebx
  int v16; // er9
  __int64 v17; // rdx
  char *v18; // rax
  int v19; // er15
  __int64 v20; // r12
  char *v21; // r13
  char v22; // bl
  __int64 v23; // rsi
  char *v24; // rdi
  const char *v25; // rax
  __int64 v26; // r9
  int v27; // eax
  hkTypeManager::Type *v28; // rax
  int v29; // eax
  int v30; // ebx
  int v31; // eax
  int v32; // eax
  int v33; // er9
  char *v34; // r8
  __int64 sizeElem[2]; // [rsp+20h] [rbp-58h]
  char *array; // [rsp+30h] [rbp-48h]
  int v37; // [rsp+38h] [rbp-40h]
  int v38; // [rsp+3Ch] [rbp-3Ch]
  Context *v39; // [rsp+80h] [rbp+8h]
  hkResult result; // [rsp+88h] [rbp+10h]

  v39 = this;
  v3 = this;
  v4 = os;
  v5 = k;
  ((void (*)(void))k->m_impl->vfptr[3].__vecDelDtor)();
  v6 = ((__int64 (*)(void))v5->m_impl->vfptr[3].__vecDelDtor)();
  v7 = ((__int64 (*)(void))v5->m_impl->vfptr[2].__vecDelDtor)();
  v8 = v3->m_indenter.m_indent.m_data;
  LODWORD(sizeElem[0]) = v6;
  hkOstream::printf(v4, "%s<class name=\"%s\" version=\"%i\"", v7, sizeElem[0]);
  v9 = ((__int64 (*)(void))v5->m_impl->vfptr[4].__vecDelDtor)();
  if ( v9 )
  {
    v10 = ((__int64 (*)(void))v5->m_impl->vfptr[4].__vecDelDtor)();
    v11 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 16i64))(v10);
    hkOstream::printf(v4, " parent=\"%s\"", v11);
  }
  hkOstream::printf(v4, ">\n", v9);
  `anonymous namespace'::Indenter::push(&v3->m_indenter);
  v12 = v5->m_impl;
  v13 = 0;
  array = 0i64;
  v37 = 0;
  v38 = 2147483648;
  v14 = ((__int64 (*)(void))v12->vfptr[6].__vecDelDtor)();
  v15 = v14;
  if ( v14 > 0 )
  {
    v16 = v14;
    if ( v14 < 0 )
      v16 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v16, 32);
  }
  v17 = v15 - v37;
  if ( v15 - v37 > 0 )
  {
    v18 = &array[32 * v37 + 16];
    do
    {
      if ( v18 != (char *)16 )
      {
        *((_QWORD *)v18 - 2) = 0i64;
        *((_QWORD *)v18 - 1) = 0i64;
        *(_QWORD *)v18 = 0i64;
        *((_QWORD *)v18 + 1) = 0i64;
      }
      v18 += 32;
      --v17;
    }
    while ( v17 );
  }
  v37 = v15;
  hkDataClass::getAllDeclaredMemberInfo(v5, (hkArrayBase<hkDataClass_MemberInfo> *)&array);
  v19 = 0;
  if ( v37 > 0 )
  {
    v20 = 0i64;
    while ( 1 )
    {
      v21 = array;
      v22 = 0;
      v23 = *(_QWORD *)&array[v20 + 16];
      if ( *(_DWORD *)v23 == 8 )
      {
        v22 = 1;
      }
      else
      {
        if ( *(_DWORD *)v23 != 9 || **(_DWORD **)(v23 + 8) == 3 && !((*(_DWORD *)(v23 + 16) - 4) & 0xFFFFFFF3) )
          goto LABEL_21;
        v13 = hkTypeManager::Type::getTupleSize(*(hkTypeManager::Type **)&array[v20 + 16]);
      }
      v23 = *(_QWORD *)(v23 + 8);
LABEL_21:
      v24 = v39->m_indenter.m_indent.m_data;
      v25 = anonymous_namespace_::nameFromType((hkTypeManager::Type *)v23);
      v26 = *(_QWORD *)&v21[v20];
      hkOstream::printf(v4, "%s<member name=\"%s\" type=\"%s\"", (int)v25, v25);
      if ( v22 )
        hkOstream::printf(v4, " array=\"true\"", v27);
      if ( v13 )
        hkOstream::printf(v4, " count=\"%i\"", v27);
      v28 = hkTypeManager::Type::findTerminal((hkTypeManager::Type *)v23);
      if ( v28->m_subType == 6 )
      {
        v29 = (unsigned __int64)hkTypeManager::Type::getTypeName(v28);
        hkOstream::printf(v4, " class=\"%s\"", v29);
      }
      hkOstream::printf(v4, "/>\n", (int)v28);
      ++v19;
      v20 += 32i64;
      v13 = 0;
      if ( v19 >= v37 )
      {
        v3 = v39;
        break;
      }
    }
  }
  v3->m_indenter.m_indent.m_data[v3->m_indenter.m_indent.m_size
                               - (signed __int64)(signed int)v3->m_indenter.m_indentStep] = 0;
  v30 = v3->m_indenter.m_indent.m_size - v3->m_indenter.m_indentStep;
  v31 = v3->m_indenter.m_indent.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v31 < v30 )
  {
    v32 = 2 * v31;
    v33 = v3->m_indenter.m_indent.m_size - v3->m_indenter.m_indentStep;
    if ( v30 < v32 )
      v33 = v32;
    v31 = (unsigned __int64)hkArrayUtil::_reserve(
                              (hkResult *)&v39,
                              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                              v3,
                              v33,
                              1);
  }
  v3->m_indenter.m_indent.m_size = v30;
  v34 = v3->m_indenter.m_indent.m_data;
  hkOstream::printf(v4, "%s</class>\n", v31);
  v37 = 0;
  if ( v38 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      32 * v38);
}

// File Line: 456
// RVA: 0xE58200
void __fastcall `anonymous namespace'::Context::writeFloat(Context *this, hkOstream *os, float r)
{
  bool v3; // zf
  hkOstream *v4; // rdi
  Context *v5; // rbx
  hkStringBuf buf; // [rsp+20h] [rbp-D8h]
  int v7; // [rsp+B0h] [rbp-48h]
  int v8; // [rsp+B4h] [rbp-44h]
  char v9; // [rsp+B8h] [rbp-40h]
  unsigned int v10; // [rsp+168h] [rbp+70h]

  v3 = this->m_writeFloatAsHex.m_bool == 0;
  v4 = os;
  v5 = this;
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
    if ( v5->m_floatComment.m_bool )
    {
      v8 = -2147483520;
      v7 = 1;
      v9 = 0;
      *(_QWORD *)&buf.m_string.m_storage[120] = &v9;
      hkFloatParseUtil::calcFloatTextWithPoint(r, (hkStringBuf *)((char *)&buf + 136));
      hkStringBuf::append(&buf, " <!-- ", -1);
      hkStringBuf::append(&buf, *(const char **)&buf.m_string.m_storage[120], -1);
      hkStringBuf::append(&buf, " -->", -1);
      v7 = 0;
      if ( v8 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          *(void **)&buf.m_string.m_storage[120],
          v8 & 0x3FFFFFFF);
    }
  }
  hkOstream::write(v4, buf.m_string.m_data, (unsigned int)(buf.m_string.m_size - 1));
  buf.m_string.m_size = 0;
  if ( buf.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      buf.m_string.m_data,
      buf.m_string.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 486
// RVA: 0xE58620
void __fastcall `anonymous namespace'::Context::writeReals(Context *this, hkOstream *os, const float *ra, int nreal)
{
  void **v4; // rax
  const float *v5; // r15
  hkOstream *v6; // rsi
  Context *v7; // rdi
  __int64 v8; // r14
  __int64 v9; // rbx
  float v10; // xmm6_4
  hkStringBuf buf; // [rsp+20h] [rbp-B8h]
  unsigned int vars0; // [rsp+170h] [rbp+98h]
  void *retaddr; // [rsp+178h] [rbp+A0h]

  if ( nreal > 0 )
  {
    v4 = &retaddr;
    v5 = ra;
    v6 = os;
    v7 = this;
    v8 = nreal;
    v9 = 0i64;
    do
    {
      if ( v9 )
        hkOstream::printf(
          v6,
          " ",
          (int)v4,
          buf.m_string.m_data,
          *(_QWORD *)&buf.m_string.m_size,
          *(_QWORD *)buf.m_string.m_storage);
      v10 = v5[v9];
      buf.m_string.m_capacityAndFlags = -2147483520;
      buf.m_string.m_size = 1;
      buf.m_string.m_storage[0] = 0;
      vars0 = LODWORD(v10);
      buf.m_string.m_data = buf.m_string.m_storage;
      if ( v7->m_writeFloatAsHex.m_bool )
      {
        hkStringBuf::printf(&buf, "x%08x", vars0);
        if ( v7->m_floatComment.m_bool )
        {
          *(_DWORD *)&buf.m_string.m_storage[100] = -2147483520;
          *(_DWORD *)&buf.m_string.m_storage[96] = 1;
          buf.m_string.m_storage[104] = 0;
          *(_QWORD *)&buf.m_string.m_storage[88] = (char *)&buf + 120;
          hkFloatParseUtil::calcFloatTextWithPoint(v10, (hkStringBuf *)((char *)&buf + 104));
          hkStringBuf::append(&buf, " <!-- ", -1);
          hkStringBuf::append(&buf, *(const char **)&buf.m_string.m_storage[88], -1);
          hkStringBuf::append(&buf, " -->", -1);
          *(_DWORD *)&buf.m_string.m_storage[96] = 0;
          if ( *(_DWORD *)&buf.m_string.m_storage[100] >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              *(void **)&buf.m_string.m_storage[88],
              *(_DWORD *)&buf.m_string.m_storage[100] & 0x3FFFFFFF);
        }
      }
      else
      {
        hkFloatParseUtil::calcFloatTextWithPoint(v10, &buf);
      }
      LODWORD(v4) = hkOstream::write(v6, buf.m_string.m_data, (unsigned int)(buf.m_string.m_size - 1));
      buf.m_string.m_size = 0;
      if ( buf.m_string.m_capacityAndFlags >= 0 )
        LODWORD(v4) = ((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, char *, _QWORD))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
                        &hkContainerTempAllocator::s_alloc,
                        buf.m_string.m_data,
                        buf.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      ++v9;
    }
    while ( v9 < v8 );
  }
}

// File Line: 499
// RVA: 0xE56B10
void __usercall `anonymous namespace'::Context::writeValue<hkDataObject_Value>(Context *this@<rcx>, hkDataObject_Value *value@<rdx>, hkOstream *os@<r8>, float a4@<xmm0>)
{
  Context *v4; // rdi
  int v5; // er15
  hkOstream *v6; // rsi
  hkDataObject_Value *v7; // r14
  hkTypeManager::Type *v8; // rax
  hkTypeManager::Type *v9; // rdx
  hkTypeManager::SubType v10; // eax
  __int64 v11; // r8
  int v12; // eax
  const char *v13; // rdx
  __int64 v14; // rax
  __int64 v15; // rbx
  hkDataArray *v16; // rax
  int v17; // eax
  hkDataObjectImpl *v18; // rax
  hkDataObjectImpl *v19; // rcx
  bool v20; // zf
  const char *v21; // rax
  unsigned int v22; // eax
  int v23; // ebx
  const float *v24; // rax
  __int64 v25; // rax
  int v26; // eax
  char *v27; // r8
  hkDataObjectImpl *v28; // rax
  int v29; // eax
  hkDataObjectImpl *v30; // rcx
  char *v31; // r8
  char *v32; // r8
  int v33; // eax
  hkDataArrayImpl *v34; // rax
  hkDataArrayImpl *v35; // rbx
  char *v36; // r8
  hkDataArray a[2]; // [rsp+20h] [rbp-79h]
  hkDataObject v38; // [rsp+30h] [rbp-69h]
  char v39; // [rsp+38h] [rbp-61h]
  hkStringBuf v40; // [rsp+50h] [rbp-49h]
  hkDataObject obj; // [rsp+118h] [rbp+7Fh]

  v4 = this;
  v5 = 0;
  v6 = os;
  v7 = value;
  LODWORD(obj.m_impl) = 0;
  v8 = hkDataObject_Value::getType(value);
  v9 = v8;
  v10 = v8->m_subType;
  v11 = v10 - 2;
  switch ( v10 )
  {
    case 2:
    case 4:
      v12 = ((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64, signed __int64))v7->m_impl->vfptr[12].__vecDelDtor)(
              v7->m_impl,
              v7->m_handle,
              v11,
              5368709120i64);
      v13 = "%I64i";
      goto LABEL_44;
    case 3:
      ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64, signed __int64))v7->m_impl->vfptr[15].__vecDelDtor)(
        v7->m_impl,
        v7->m_handle,
        v11,
        5368709120i64);
      `anonymous namespace'::Context::writeFloat(v4, v6, a4);
      return;
    case 5:
      v21 = (const char *)((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64, signed __int64))v7->m_impl->vfptr[11].__vecDelDtor)(
                            v7->m_impl,
                            v7->m_handle,
                            v11,
                            5368709120i64);
      if ( v21 )
      {
        hkStringBuf::hkStringBuf(&v40, v21);
        hkStringBuf::replace(&v40, "&", "&amp;", REPLACE_ALL);
        hkStringBuf::replace(&v40, "<", "&lt;", REPLACE_ALL);
        hkStringBuf::replace(&v40, ">", "&gt;", REPLACE_ALL);
        hkOstream::write(v6, v40.m_string.m_data, (unsigned int)(v40.m_string.m_size - 1));
        v40.m_string.m_size = 0;
        if ( v40.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v40.m_string.m_data,
            v40.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      }
      else
      {
        hkOstream::printf(v6, "<null/>", 0);
      }
      return;
    case 6:
      v18 = (hkDataObjectImpl *)((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64, signed __int64))v7->m_impl->vfptr[13].__vecDelDtor)(
                                  v7->m_impl,
                                  v7->m_handle,
                                  v11,
                                  5368709120i64);
      obj.m_impl = v18;
      if ( v18 )
      {
        ++v18->m_externalCount;
        ++v18->m_count;
      }
      `anonymous namespace'::Context::writeObjectMembers(v4, &obj, v6);
      v19 = obj.m_impl;
      if ( obj.m_impl )
      {
        --obj.m_impl->m_externalCount;
        v20 = v19->m_count-- == 1;
        if ( v20 )
          v12 = v19->vfptr->__vecDelDtor((hkDataRefCounted *)&v19->vfptr, 1u);
      }
      goto LABEL_43;
    case 7:
      v14 = ((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64, signed __int64))v7->m_impl->vfptr[13].__vecDelDtor)(
              v7->m_impl,
              v7->m_handle,
              v11,
              5368709120i64);
      v15 = v14;
      if ( v14 )
      {
        ++*(_WORD *)(v14 + 10);
        ++*(_DWORD *)(v14 + 12);
      }
      a[0].m_impl = 0i64;
      a[1].m_impl = 0i64;
      if ( v14 )
      {
        v16 = (hkDataArray *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v14 + 8i64))(v14, &v39);
      }
      else
      {
        v16 = a;
        _mm_store_si128((__m128i *)a, *(__m128i *)&a[0].m_impl);
      }
      *(_OWORD *)&a[0].m_impl = *(_OWORD *)&v16->m_impl;
      v17 = hkMapBase<hkDataObject_Handle,int,`anonymous namespace'::HandleOps>::getWithDefault(
              (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v4->m_seenObjects.m_objectIndexFromHandle.m_elem,
              (hkDataObject_Handle *)a,
              -1);
      hkOstream::printf(v6, "#%04i", v17);
      if ( v15 )
        goto LABEL_35;
      return;
    case 8:
      goto $LN7_230;
    case 9:
      if ( v10 != 9 || v9->m_parent->m_subType != 3 || (v9->m_extra.m_size - 4) & 0xFFFFFFF3 )
      {
$LN7_230:
        if ( v9->m_parent->m_subType == 6 )
        {
          v25 = ((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64, signed __int64))v7->m_impl->vfptr[10].__vecDelDtor)(
                  v7->m_impl,
                  v7->m_handle,
                  v11,
                  5368709120i64);
          v15 = v25;
          if ( v25 )
          {
            ++*(_WORD *)(v25 + 10);
            ++*(_DWORD *)(v25 + 12);
          }
          `anonymous namespace'::Indenter::push(&v4->m_indenter);
          v26 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v15 + 40i64))(v15);
          if ( v26 > 0 )
          {
            do
            {
              v27 = v4->m_indenter.m_indent.m_data;
              hkOstream::printf(v6, "\n%s<struct>", v26);
              v28 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v15 + 168i64))(
                                          v15,
                                          (unsigned int)v5);
              v38.m_impl = v28;
              if ( v28 )
              {
                ++v28->m_externalCount;
                ++v28->m_count;
              }
              `anonymous namespace'::Context::writeObjectMembers(v4, &v38, v6);
              v30 = v38.m_impl;
              if ( v38.m_impl )
              {
                --v38.m_impl->m_externalCount;
                v20 = v30->m_count-- == 1;
                if ( v20 )
                  v29 = v30->vfptr->__vecDelDtor((hkDataRefCounted *)&v30->vfptr, 1u);
              }
              v31 = v4->m_indenter.m_indent.m_data;
              hkOstream::printf(v6, "\n%s</struct>", v29);
              ++v5;
              v26 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v15 + 40i64))(v15);
            }
            while ( v5 < v26 );
          }
          `anonymous namespace'::Indenter::pop(&v4->m_indenter);
          v32 = v4->m_indenter.m_indent.m_data;
          hkOstream::printf(v6, "\n%s", v33);
LABEL_35:
          --*(_WORD *)(v15 + 10);
          v20 = (*(_DWORD *)(v15 + 12))-- == 1;
          if ( v20 )
            (**(void (__fastcall ***)(__int64, signed __int64))v15)(v15, 1i64);
        }
        else
        {
          `anonymous namespace'::Indenter::push(&v4->m_indenter);
          v34 = (hkDataArrayImpl *)v7->m_impl->vfptr[10].__vecDelDtor(
                                     (hkDataRefCounted *)v7->m_impl,
                                     (unsigned int)v7->m_handle);
          v35 = v34;
          a[0].m_impl = v34;
          if ( v34 )
          {
            ++v34->m_externalCount;
            ++v34->m_count;
          }
          `anonymous namespace'::Context::writeArray(v4, a, v6);
          if ( v35 )
          {
            --v35->m_externalCount;
            v20 = v35->m_count-- == 1;
            if ( v20 )
              v35->vfptr->__vecDelDtor((hkDataRefCounted *)&v35->vfptr, 1u);
          }
          `anonymous namespace'::Indenter::pop(&v4->m_indenter);
LABEL_43:
          v36 = v4->m_indenter.m_indent.m_data;
          v13 = "\n%s";
LABEL_44:
          hkOstream::printf(v6, v13, v12, a[0].m_impl);
        }
      }
      else
      {
        v22 = hkTypeManager::Type::getTupleSize(v9);
        v23 = v22;
        v24 = (const float *)((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, _QWORD))v7->m_impl->vfptr[14].__vecDelDtor)(
                               v7->m_impl,
                               v7->m_handle,
                               v22);
        `anonymous namespace'::Context::writeReals(v4, v6, v24, v23);
      }
      break;
    default:
      return;
  }
}

// File Line: 587
// RVA: 0xE57B30
void __usercall `anonymous namespace'::Context::writeArray(Context *this@<rcx>, hkDataArray *a@<rdx>, hkOstream *os@<r8>, float a4@<xmm0>)
{
  Context *v4; // r14
  hkOstream *v5; // rdi
  hkDataArray *v6; // r15
  hkTypeManager::Type *v7; // r12
  signed int v8; // esi
  signed int v9; // er13
  const char *v10; // rax
  unsigned int v11; // ebx
  const char *v12; // rbp
  char *v13; // r8
  const char *v14; // rdx
  int v15; // eax
  hkDataArrayImpl *v16; // rax
  hkDataArray_Value value; // [rsp+20h] [rbp-48h]
  hkDataArray_Value v18; // [rsp+30h] [rbp-38h]
  signed int v19; // [rsp+78h] [rbp+10h]

  v4 = this;
  v5 = os;
  v6 = a;
  v7 = (hkTypeManager::Type *)((__int64 (*)(void))a->m_impl->vfptr[1].__vecDelDtor)();
  v8 = 1;
  v19 = anonymous_namespace_::calcWrapMod(v7);
  v9 = ((__int64 (*)(void))v6->m_impl->vfptr[5].__vecDelDtor)();
  v10 = anonymous_namespace_::nameFromType(v7);
  v11 = 0;
  v12 = v10;
  if ( (unsigned int)(v7->m_subType - 2) <= 2 )
    v12 = 0i64;
  if ( v9 > 0 )
  {
    while ( 1 )
    {
      if ( !--v8 )
      {
        v13 = v4->m_indenter.m_indent.m_data;
        hkOstream::printf(v5, "\n%s", (int)v10);
        v8 = v19;
      }
      if ( !v12 )
        break;
      if ( v7->m_subType == 5 )
      {
        v10 = (const char *)v6->m_impl->vfptr[13].__vecDelDtor((hkDataRefCounted *)v6->m_impl, v11);
        if ( !v10 )
        {
          v14 = "<null/>";
LABEL_12:
          hkOstream::printf(v5, v14, (int)v10);
          goto LABEL_13;
        }
      }
      hkOstream::printf(v5, "<%s>", (int)v10);
      value.m_impl = v6->m_impl;
      value.m_index = v11;
      `anonymous namespace'::Context::writeValue<hkDataArray_Value>(v4, &value, v5, a4);
      hkOstream::printf(v5, "</%s>", v15);
LABEL_13:
      if ( (signed int)++v11 >= v9 )
        return;
    }
    v16 = v6->m_impl;
    v18.m_index = v11;
    v18.m_impl = v16;
    `anonymous namespace'::Context::writeValue<hkDataArray_Value>(v4, &v18, v5, a4);
    v14 = " ";
    goto LABEL_12;
  }
}

// File Line: 631
// RVA: 0xE58370
void __usercall `anonymous namespace'::Context::writeObjectMembers(Context *this@<rcx>, hkDataObject *obj@<rdx>, hkOstream *os@<r8>, float a4@<xmm0>)
{
  int v4; // esi
  hkOstream *v5; // r13
  hkDataObject *v6; // r12
  Context *v7; // r14
  __int64 v8; // r15
  _WORD *v9; // rbx
  hkTypeManager::Type *v10; // rdi
  hkTypeManager::SubType v11; // edx
  int v12; // eax
  char *v13; // r8
  __int64 v14; // rax
  char *v15; // r8
  int v16; // eax
  _WORD *v17; // rax
  int v18; // edi
  bool v19; // zf
  __int64 v20; // rax
  char *v21; // r8
  int v22; // eax
  int v23; // ebx
  int v24; // eax
  int v25; // eax
  int v26; // er9
  __int64 v27; // [rsp+28h] [rbp-40h]
  hkDataObject_Value value; // [rsp+30h] [rbp-38h]
  hkResult result; // [rsp+70h] [rbp+8h]

  v4 = 0;
  v5 = os;
  v6 = obj;
  v7 = this;
  result.m_enum = 0;
  `anonymous namespace'::Indenter::push(&this->m_indenter);
  v8 = ((unsigned int (*)(void))v6->m_impl->vfptr[5].__vecDelDtor)();
  if ( v6->m_impl->vfptr[6].__vecDelDtor((hkDataRefCounted *)v6->m_impl, v8) )
  {
    v9 = *(_WORD **)&result.m_enum;
    do
    {
      ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, _QWORD))v6->m_impl->vfptr[9].__vecDelDtor)(
        v6->m_impl,
        &value,
        (unsigned int)v8);
      v10 = hkDataObject_Value::getType(&value);
      if ( (unsigned int)anonymous_namespace_::worthPrinting_hkDataObject_Value_(&value, a4) )
      {
        v11 = v10->m_subType;
        if ( v10->m_subType == 8
          || v11 == 9 && (v10->m_parent->m_subType != 3 || (v10->m_extra.m_size - 4) & 0xFFFFFFF3) )
        {
          if ( v11 == 9 )
          {
            v16 = hkTypeManager::Type::getTupleSize(v10);
          }
          else
          {
            v4 |= 1u;
            v17 = (_WORD *)value.m_impl->vfptr[10].__vecDelDtor(
                             (hkDataRefCounted *)value.m_impl,
                             (unsigned int)value.m_handle);
            v9 = v17;
            if ( v17 )
            {
              ++v17[5];
              ++*((_DWORD *)v17 + 3);
            }
            v16 = (*(__int64 (__fastcall **)(_WORD *))(*(_QWORD *)v17 + 40i64))(v17);
          }
          v18 = v16;
          if ( v4 & 1 )
          {
            v4 &= 0xFFFFFFFE;
            if ( v9 )
            {
              --v9[5];
              v19 = (*((_DWORD *)v9 + 3))-- == 1;
              if ( v19 )
                (**(void (__fastcall ***)(_WORD *, signed __int64))v9)(v9, 1i64);
            }
          }
          v20 = (__int64)v6->m_impl->vfptr[8].__vecDelDtor((hkDataRefCounted *)v6->m_impl, v8);
          v21 = v7->m_indenter.m_indent.m_data;
          LODWORD(v27) = v18;
          hkOstream::printf(v5, "\n%s<%s name=\"%s\" size=\"%i\">", v20, v20, v27);
          goto LABEL_22;
        }
        anonymous_namespace_::nameFromType(v10);
        if ( v10->m_subType != 5
          || (__int64)value.m_impl->vfptr[11].__vecDelDtor(
                        (hkDataRefCounted *)value.m_impl,
                        (unsigned int)value.m_handle) )
        {
          v14 = (__int64)v6->m_impl->vfptr[8].__vecDelDtor((hkDataRefCounted *)v6->m_impl, v8);
          v15 = v7->m_indenter.m_indent.m_data;
          hkOstream::printf(v5, "\n%s<%s name=\"%s\">", v14, v14);
LABEL_22:
          `anonymous namespace'::Context::writeValue<hkDataObject_Value>(v7, &value, v5, a4);
          hkOstream::printf(v5, "</%s>", v22);
          goto LABEL_23;
        }
        v12 = (__int64)v6->m_impl->vfptr[8].__vecDelDtor((hkDataRefCounted *)v6->m_impl, v8);
        v13 = v7->m_indenter.m_indent.m_data;
        hkOstream::printf(v5, "\n%s<null name=\"%s\"/>", v12);
      }
LABEL_23:
      v8 = (unsigned int)v6->m_impl->vfptr[7].__vecDelDtor((hkDataRefCounted *)v6->m_impl, v8);
    }
    while ( v6->m_impl->vfptr[6].__vecDelDtor((hkDataRefCounted *)v6->m_impl, v8) );
  }
  v7->m_indenter.m_indent.m_data[v7->m_indenter.m_indent.m_size
                               - (signed __int64)(signed int)v7->m_indenter.m_indentStep] = 0;
  v23 = v7->m_indenter.m_indent.m_size - v7->m_indenter.m_indentStep;
  v24 = v7->m_indenter.m_indent.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v24 < v23 )
  {
    v25 = 2 * v24;
    v26 = v7->m_indenter.m_indent.m_size - v7->m_indenter.m_indentStep;
    if ( v23 < v25 )
      v26 = v25;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v26, 1);
  }
  v7->m_indenter.m_indent.m_size = v23;
}

// File Line: 683
// RVA: 0xE57FB0
void __fastcall `anonymous namespace'::Context::writeFile(Context *this, hkDataObject *topObj, hkStreamWriter *stream)
{
  Context *v3; // rdi
  hkDataObject *v4; // rsi
  int v5; // eax
  int v6; // eax
  int i; // ebx
  __int64 v8; // rax
  signed int v9; // er14
  __int64 v10; // r15
  hkDataObjectImpl *v11; // rbx
  int *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rax
  char *v15; // r8
  char *v16; // r8
  int v17; // eax
  hkDataObjectImpl *v18; // rcx
  bool v19; // zf
  int v20; // ebx
  int v21; // eax
  int v22; // eax
  int v23; // er9
  int sizeElem[4]; // [rsp+18h] [rbp-29h]
  __int128 v25; // [rsp+28h] [rbp-19h]
  char v26; // [rsp+38h] [rbp-9h]
  hkOstream os; // [rsp+48h] [rbp+7h]
  hkDataObject obj; // [rsp+A8h] [rbp+67h]

  v3 = this;
  v4 = topObj;
  hkOstream::hkOstream(&os, stream);
  hkOstream::printf(&os, "<?xml version=\"1.0\" encoding=\"ascii\"?>", v5);
  hkOstream::printf(&os, "\n<hktagfile version=\"%d\" sdkversion=\"%s\">\n", v6);
  `anonymous namespace'::Indenter::push(&v3->m_indenter);
  for ( i = 0; i < v3->m_seenObjects.m_classes.m_size; ++i )
    `anonymous namespace'::Context::writeClass(v3, &v3->m_seenObjects.m_classes.m_data[i], &os);
  v8 = ((__int64 (*)(void))v4->m_impl->vfptr[2].__vecDelDtor)();
  v9 = 1;
  v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 8i64))(v8);
  if ( v3->m_seenObjects.m_objects.m_size > 1 )
  {
    *(_QWORD *)sizeElem = 0i64;
    *(_QWORD *)&sizeElem[2] = 0i64;
    do
    {
      (*(void (__fastcall **)(__int64, hkDataObject *, hkDataObject_Handle *))(*(_QWORD *)v10 + 80i64))(
        v10,
        &obj,
        &v3->m_seenObjects.m_objects.m_data[v9]);
      v11 = obj.m_impl;
      if ( obj.m_impl )
      {
        v12 = (int *)obj.m_impl->vfptr[1].__vecDelDtor((hkDataRefCounted *)obj.m_impl, (unsigned int)&v26);
        v11 = obj.m_impl;
      }
      else
      {
        _mm_store_si128((__m128i *)sizeElem, 0);
        v12 = sizeElem;
      }
      v25 = *(_OWORD *)v12;
      hkMapBase<hkDataObject_Handle,int,`anonymous namespace'::HandleOps>::getWithDefault(
        (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v3->m_seenObjects.m_objectIndexFromHandle.m_elem,
        (hkDataObject_Handle *)&v25,
        -1);
      v13 = ((__int64 (__fastcall *)(hkDataObjectImpl *))v11->vfptr[2].__vecDelDtor)(v11);
      v14 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v13 + 16i64))(v13);
      v15 = v3->m_indenter.m_indent.m_data;
      *(_QWORD *)&sizeElem[2] = v14;
      hkOstream::printf(&os, "\n%s<object id=\"#%04i\" type=\"%s\">", v14, v14);
      `anonymous namespace'::Context::writeObjectMembers(v3, &obj, &os);
      v16 = v3->m_indenter.m_indent.m_data;
      hkOstream::printf(&os, "\n%s</object>", v17);
      v18 = obj.m_impl;
      if ( obj.m_impl )
      {
        --obj.m_impl->m_externalCount;
        v19 = v18->m_count-- == 1;
        if ( v19 )
          v18->vfptr->__vecDelDtor((hkDataRefCounted *)&v18->vfptr, 1u);
      }
      ++v9;
    }
    while ( v9 < v3->m_seenObjects.m_objects.m_size );
  }
  v3->m_indenter.m_indent.m_data[v3->m_indenter.m_indent.m_size
                               - (signed __int64)(signed int)v3->m_indenter.m_indentStep] = 0;
  v20 = v3->m_indenter.m_indent.m_size - v3->m_indenter.m_indentStep;
  v21 = v3->m_indenter.m_indent.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v21 < v20 )
  {
    v22 = 2 * v21;
    v23 = v3->m_indenter.m_indent.m_size - v3->m_indenter.m_indentStep;
    if ( v20 < v22 )
      v23 = v22;
    v21 = (unsigned __int64)hkArrayUtil::_reserve(
                              (hkResult *)&obj,
                              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                              v3,
                              v23,
                              1);
  }
  v3->m_indenter.m_indent.m_size = v20;
  hkOstream::printf(&os, "\n</hktagfile>\n", v21);
  hkOstream::~hkOstream(&os);
}

// File Line: 715
// RVA: 0xE55FD0
hkResult *__fastcall hkXmlTagfileWriter::save(hkXmlTagfileWriter *this, hkResult *result, hkDataObject *obj, hkStreamWriter *stream, hkTagfileWriter::AddDataObjectListener *userListener, hkTagfileWriter::Options *options)
{
  hkResult *v6; // rsi
  hkDataObject *v7; // rbx
  hkStreamWriter *v8; // rdi
  _BYTE *array; // [rsp+20h] [rbp-88h]
  int v11; // [rsp+28h] [rbp-80h]
  int v12; // [rsp+2Ch] [rbp-7Ch]
  int v13; // [rsp+30h] [rbp-78h]
  char v14; // [rsp+34h] [rbp-74h]
  SeenObjects v15; // [rsp+38h] [rbp-70h]
  char v16; // [rsp+98h] [rbp-10h]
  char v17; // [rsp+99h] [rbp-Fh]

  v6 = result;
  v7 = obj;
  v8 = stream;
  array = 0i64;
  v11 = 0;
  v12 = 2147483648;
  v13 = 2;
  v14 = 32;
  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 1);
  array[v11] = 0;
  `anonymous namespace'::SeenObjects::SeenObjects(&v15, userListener);
  v16 = options->m_exact.m_bool;
  v17 = options->m_verbose.m_bool;
  `anonymous namespace'::SeenObjects::scanObject(&v15, v7);
  `anonymous namespace'::Context::writeFile((Context *)&array, v7, v8);
  v8->vfptr[2].__first_virtual_table_function__((hkBaseObject *)&v8->vfptr);
  v6->m_enum = *(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, hkTagfileWriter::Options **))v8->vfptr[1].__first_virtual_table_function__)(
                           v8,
                           &options) == 0;
  `anonymous namespace'::SeenObjects::~SeenObjects(&v15);
  v11 = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      v12 & 0x3FFFFFFF);
  return v6;
}

