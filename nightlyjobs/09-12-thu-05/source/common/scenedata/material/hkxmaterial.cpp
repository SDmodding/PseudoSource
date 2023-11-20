// File Line: 13
// RVA: 0xE34AF0
void __fastcall hkxMaterial::~hkxMaterial(hkxMaterial *this)
{
  hkxMaterial *v1; // rdi
  int v2; // er8
  hkReferencedObject *v3; // rcx
  hkRefPtr<hkxMaterial> *v4; // rsi
  int v5; // eax
  __int64 i; // rbx
  hkReferencedObject *v7; // rcx
  int v8; // er8
  int v9; // eax
  __int64 v10; // rsi
  hkReferencedObject **v11; // rbx
  int v12; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkxMaterial::`vftable';
  v2 = this->m_properties.m_capacityAndFlags;
  this->m_properties.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_properties.m_data,
      8 * v2);
  v1->m_properties.m_data = 0i64;
  v1->m_properties.m_capacityAndFlags = 2147483648;
  v3 = v1->m_extraData.m_pntr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_extraData.m_pntr = 0i64;
  v4 = v1->m_subMaterials.m_data;
  v5 = v1->m_subMaterials.m_size - 1;
  for ( i = v5; i >= 0; v4[i--].m_pntr = 0i64 )
  {
    v7 = (hkReferencedObject *)&v4[i].m_pntr->vfptr;
    if ( v7 )
      hkReferencedObject::removeReference(v7);
  }
  v8 = v1->m_subMaterials.m_capacityAndFlags;
  v1->m_subMaterials.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_subMaterials.m_data,
      8 * v8);
  v1->m_subMaterials.m_data = 0i64;
  v1->m_subMaterials.m_capacityAndFlags = 2147483648;
  v9 = v1->m_stages.m_size - 1;
  v10 = v9;
  if ( v9 >= 0 )
  {
    v11 = &v1->m_stages.m_data[v9].m_texture.m_pntr;
    do
    {
      if ( *v11 )
        hkReferencedObject::removeReference(*v11);
      *v11 = 0i64;
      v11 -= 2;
      --v10;
    }
    while ( v10 >= 0 );
  }
  v12 = v1->m_stages.m_capacityAndFlags;
  v1->m_stages.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_stages.m_data,
      16 * v12);
  v1->m_stages.m_data = 0i64;
  v1->m_stages.m_capacityAndFlags = 2147483648;
  hkStringPtr::~hkStringPtr(&v1->m_name);
  hkxAttributeHolder::~hkxAttributeHolder((hkxAttributeHolder *)&v1->vfptr);
}

// File Line: 30
// RVA: 0xE34C80
void __fastcall hkxMaterial::sortTextureStageOrder(hkxMaterial *this)
{
  __int64 v1; // rbp
  __int64 v2; // r13
  hkxMaterial::TextureStage *v3; // r15
  hkReferencedObject *v4; // r12
  int v5; // esi
  int v6; // ebx
  __int64 v7; // r14
  hkEnum<enum hkxMaterial::TextureType,int> *v8; // rdi
  int v9; // er12
  hkReferencedObject **v10; // rsi
  hkReferencedObject *v11; // rbp
  int v12; // eax
  signed __int64 v13; // rdi
  char v14; // [rsp+20h] [rbp-58h]
  int v15; // [rsp+80h] [rbp+8h]
  hkReferencedObject *v16; // [rsp+88h] [rbp+10h]
  __int64 v17; // [rsp+90h] [rbp+18h]
  hkxMaterial::TextureStage *v18; // [rsp+98h] [rbp+20h]

  v1 = this->m_stages.m_size;
  v2 = 0i64;
  v18 = this->m_stages.m_data;
  v17 = v1;
  if ( v1 > 0 )
  {
    v3 = this->m_stages.m_data;
    do
    {
      if ( v3->m_texture.m_pntr )
        hkReferencedObject::addReference(v3->m_texture.m_pntr);
      v4 = v3->m_texture.m_pntr;
      v5 = v3->m_tcoordChannel;
      v6 = v3->m_usageHint.m_storage;
      v16 = v3->m_texture.m_pntr;
      v15 = v3->m_tcoordChannel;
      v7 = v2;
      if ( v2 > 0 )
      {
        v8 = &v3[-1].m_usageHint;
        v9 = v3->m_tcoordChannel;
        do
        {
          if ( v6 >= v8->m_storage && (v6 != v8->m_storage || v9 >= v8[1].m_storage) )
            break;
          v10 = (hkReferencedObject **)&v8[2];
          if ( &v8[2] != &v8[-2] )
          {
            v11 = *(hkReferencedObject **)&v8[-2].m_storage;
            if ( v11 )
              hkReferencedObject::addReference(*(hkReferencedObject **)&v8[-2].m_storage);
            if ( *v10 )
              hkReferencedObject::removeReference(*v10);
            *v10 = v11;
          }
          v12 = v8->m_storage;
          --v7;
          v8 -= 4;
          v8[8].m_storage = v12;
          v8[9].m_storage = v8[5].m_storage;
        }
        while ( v7 > 0 );
        v4 = v16;
        v5 = v15;
        v1 = v17;
      }
      v13 = (signed __int64)&v18[v7];
      if ( (char *)v13 != &v14 )
      {
        if ( v4 )
          hkReferencedObject::addReference(v4);
        if ( *(_QWORD *)v13 )
          hkReferencedObject::removeReference(*(hkReferencedObject **)v13);
        *(_QWORD *)v13 = v4;
      }
      *(_DWORD *)(v13 + 8) = v6;
      *(_DWORD *)(v13 + 12) = v5;
      if ( v4 )
        hkReferencedObject::removeReference(v4);
      ++v2;
      ++v3;
    }
    while ( v2 < v1 );
  }
}

// File Line: 38
// RVA: 0xE34E00
void __fastcall hkxMaterial::addProperty(hkxMaterial *this, int key, int value)
{
  int v3; // ebp
  int v4; // esi
  hkxMaterial *v5; // rbx
  signed int *v6; // rbx
  __int64 v7; // rdi
  int v8; // er9
  int v9; // eax
  int v10; // eax
  __int64 v11; // rax
  hkBool result; // [rsp+58h] [rbp+20h]

  v3 = value;
  v4 = key;
  v5 = this;
  if ( !hkxMaterial::hasProperty(this, &result, key)->m_bool )
  {
    v6 = (signed int *)&v5->m_properties;
    v7 = v6[2];
    v8 = v7 + 1;
    v9 = v6[3] & 0x3FFFFFFF;
    if ( v9 < (signed int)v7 + 1 )
    {
      v10 = 2 * v9;
      if ( v8 < v10 )
        v8 = v10;
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v6,
        v8,
        8);
    }
    v11 = *(_QWORD *)v6;
    ++v6[2];
    *(_DWORD *)(v11 + 8 * v7) = v4;
    *(_DWORD *)(v11 + 8 * v7 + 4) = v3;
  }
}

// File Line: 50
// RVA: 0xE34EA0
signed __int64 __fastcall hkxMaterial::getProperty(hkxMaterial *this, int key)
{
  int v2; // eax
  __int64 v3; // r8
  hkxMaterial::Property *v4; // rax

  v2 = this->m_properties.m_size - 1;
  v3 = v2;
  if ( v2 < 0 )
    return 0xFFFFFFFFi64;
  v4 = &this->m_properties.m_data[v2];
  while ( v4->m_key != key )
  {
    --v4;
    if ( --v3 < 0 )
      return 0xFFFFFFFFi64;
  }
  return v4->m_value;
}

// File Line: 67
// RVA: 0xE34EE0
hkBool *__fastcall hkxMaterial::hasProperty(hkxMaterial *this, hkBool *result, int key)
{
  __int64 v3; // rax
  hkxMaterial::Property *v4; // r9
  hkBool *v5; // rax

  v3 = this->m_properties.m_size - 1;
  if ( (signed int)v3 < 0 )
  {
LABEL_5:
    result->m_bool = 0;
    v5 = result;
  }
  else
  {
    v4 = &this->m_properties.m_data[(signed int)v3];
    while ( v4->m_key != key )
    {
      --v4;
      if ( --v3 < 0 )
        goto LABEL_5;
    }
    result->m_bool = 1;
    v5 = result;
  }
  return v5;
}

