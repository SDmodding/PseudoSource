// File Line: 13
// RVA: 0xE34AF0
void __fastcall hkxMaterial::~hkxMaterial(hkxMaterial *this)
{
  int m_capacityAndFlags; // r8d
  hkReferencedObject *m_pntr; // rcx
  hkRefPtr<hkxMaterial> *m_data; // rsi
  int v5; // eax
  __int64 i; // rbx
  hkReferencedObject *v7; // rcx
  int v8; // r8d
  int v9; // eax
  __int64 v10; // rsi
  hkxMaterial::TextureStage *v11; // rbx
  int v12; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkxMaterial::`vftable;
  m_capacityAndFlags = this->m_properties.m_capacityAndFlags;
  this->m_properties.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_properties.m_data,
      8 * m_capacityAndFlags);
  this->m_properties.m_data = 0i64;
  this->m_properties.m_capacityAndFlags = 0x80000000;
  m_pntr = this->m_extraData.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_extraData.m_pntr = 0i64;
  m_data = this->m_subMaterials.m_data;
  v5 = this->m_subMaterials.m_size - 1;
  for ( i = v5; i >= 0; m_data[i--].m_pntr = 0i64 )
  {
    v7 = m_data[i].m_pntr;
    if ( v7 )
      hkReferencedObject::removeReference(v7);
  }
  v8 = this->m_subMaterials.m_capacityAndFlags;
  this->m_subMaterials.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_subMaterials.m_data,
      8 * v8);
  this->m_subMaterials.m_data = 0i64;
  this->m_subMaterials.m_capacityAndFlags = 0x80000000;
  v9 = this->m_stages.m_size - 1;
  v10 = v9;
  if ( v9 >= 0 )
  {
    v11 = &this->m_stages.m_data[v9];
    do
    {
      if ( v11->m_texture.m_pntr )
        hkReferencedObject::removeReference(v11->m_texture.m_pntr);
      v11->m_texture.m_pntr = 0i64;
      --v11;
      --v10;
    }
    while ( v10 >= 0 );
  }
  v12 = this->m_stages.m_capacityAndFlags;
  this->m_stages.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_stages.m_data,
      16 * v12);
  this->m_stages.m_data = 0i64;
  this->m_stages.m_capacityAndFlags = 0x80000000;
  hkStringPtr::~hkStringPtr(&this->m_name);
  hkxAttributeHolder::~hkxAttributeHolder(this);
}

// File Line: 30
// RVA: 0xE34C80
void __fastcall hkxMaterial::sortTextureStageOrder(hkxMaterial *this)
{
  __int64 m_size; // rbp
  __int64 v2; // r13
  hkxMaterial::TextureStage *v3; // r15
  hkReferencedObject *m_pntr; // r12
  int m_tcoordChannel; // esi
  int m_storage; // ebx
  __int64 v7; // r14
  hkEnum<enum hkxMaterial::TextureType,int> *p_m_usageHint; // rdi
  int v9; // r12d
  hkReferencedObject **v10; // rsi
  hkReferencedObject *v11; // rbp
  int v12; // eax
  hkxMaterial::TextureStage *v13; // rdi
  char v14; // [rsp+20h] [rbp-58h] BYREF
  int v15; // [rsp+80h] [rbp+8h]
  hkReferencedObject *v16; // [rsp+88h] [rbp+10h]
  __int64 v17; // [rsp+90h] [rbp+18h]
  hkxMaterial::TextureStage *m_data; // [rsp+98h] [rbp+20h]

  m_size = this->m_stages.m_size;
  v2 = 0i64;
  m_data = this->m_stages.m_data;
  v17 = m_size;
  if ( m_size > 0 )
  {
    v3 = this->m_stages.m_data;
    do
    {
      if ( v3->m_texture.m_pntr )
        hkReferencedObject::addReference(v3->m_texture.m_pntr);
      m_pntr = v3->m_texture.m_pntr;
      m_tcoordChannel = v3->m_tcoordChannel;
      m_storage = v3->m_usageHint.m_storage;
      v16 = v3->m_texture.m_pntr;
      v15 = m_tcoordChannel;
      v7 = v2;
      if ( v2 > 0 )
      {
        p_m_usageHint = &v3[-1].m_usageHint;
        v9 = v3->m_tcoordChannel;
        do
        {
          if ( m_storage >= p_m_usageHint->m_storage
            && (m_storage != p_m_usageHint->m_storage || v9 >= p_m_usageHint[1].m_storage) )
          {
            break;
          }
          v10 = (hkReferencedObject **)&p_m_usageHint[2];
          if ( &p_m_usageHint[2] != &p_m_usageHint[-2] )
          {
            v11 = *(hkReferencedObject **)&p_m_usageHint[-2].m_storage;
            if ( v11 )
              hkReferencedObject::addReference(*(hkReferencedObject **)&p_m_usageHint[-2].m_storage);
            if ( *v10 )
              hkReferencedObject::removeReference(*v10);
            *v10 = v11;
          }
          v12 = p_m_usageHint->m_storage;
          --v7;
          p_m_usageHint -= 4;
          p_m_usageHint[8].m_storage = v12;
          p_m_usageHint[9].m_storage = p_m_usageHint[5].m_storage;
        }
        while ( v7 > 0 );
        m_pntr = v16;
        m_tcoordChannel = v15;
        m_size = v17;
      }
      v13 = &m_data[v7];
      if ( v13 != (hkxMaterial::TextureStage *)&v14 )
      {
        if ( m_pntr )
          hkReferencedObject::addReference(m_pntr);
        if ( v13->m_texture.m_pntr )
          hkReferencedObject::removeReference(v13->m_texture.m_pntr);
        v13->m_texture.m_pntr = m_pntr;
      }
      v13->m_usageHint.m_storage = m_storage;
      v13->m_tcoordChannel = m_tcoordChannel;
      if ( m_pntr )
        hkReferencedObject::removeReference(m_pntr);
      ++v2;
      ++v3;
    }
    while ( v2 < m_size );
  }
}

// File Line: 38
// RVA: 0xE34E00
void __fastcall hkxMaterial::addProperty(hkxMaterial *this, unsigned int key, unsigned int value)
{
  hkArray<hkxMaterial::Property,hkContainerHeapAllocator> *p_m_properties; // rbx
  __int64 m_size; // rdi
  int v8; // r9d
  int v9; // eax
  int v10; // eax
  hkxMaterial::Property *m_data; // rax
  hkResult result; // [rsp+58h] [rbp+20h] BYREF

  if ( !hkxMaterial::hasProperty(this, (hkBool *)&result, key)->m_bool )
  {
    p_m_properties = &this->m_properties;
    m_size = p_m_properties->m_size;
    v8 = m_size + 1;
    v9 = p_m_properties->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 < (int)m_size + 1 )
    {
      v10 = 2 * v9;
      if ( v8 < v10 )
        v8 = v10;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_properties->m_data, v8, 8);
    }
    m_data = p_m_properties->m_data;
    ++p_m_properties->m_size;
    m_data[m_size].m_key = key;
    m_data[m_size].m_value = value;
  }
}

// File Line: 50
// RVA: 0xE34EA0
__int64 __fastcall hkxMaterial::getProperty(hkxMaterial *this, int key)
{
  int v2; // eax
  __int64 v3; // r8
  hkxMaterial::Property *i; // rax

  v2 = this->m_properties.m_size - 1;
  v3 = v2;
  if ( v2 < 0 )
    return 0xFFFFFFFFi64;
  for ( i = &this->m_properties.m_data[v2]; i->m_key != key; --i )
  {
    if ( --v3 < 0 )
      return 0xFFFFFFFFi64;
  }
  return i->m_value;
}

// File Line: 67
// RVA: 0xE34EE0
hkBool *__fastcall hkxMaterial::hasProperty(hkxMaterial *this, hkBool *result, int key)
{
  __int64 v3; // rax
  hkxMaterial::Property *v4; // r9

  v3 = this->m_properties.m_size - 1;
  if ( (int)v3 < 0 )
  {
LABEL_5:
    result->m_bool = 0;
    return result;
  }
  else
  {
    v4 = &this->m_properties.m_data[(int)v3];
    while ( v4->m_key != key )
    {
      --v4;
      if ( --v3 < 0 )
        goto LABEL_5;
    }
    result->m_bool = 1;
    return result;
  }
}

