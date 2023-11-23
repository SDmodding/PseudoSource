// File Line: 15
// RVA: 0xB36290
void __fastcall hkaMeshBinding::hkaMeshBinding(hkaMeshBinding *this)
{
  hkStringPtr *p_m_originalSkeletonName; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaMeshBinding::`vftable;
  p_m_originalSkeletonName = &this->m_originalSkeletonName;
  p_m_originalSkeletonName[-1].m_stringAndFlag = 0i64;
  hkStringPtr::hkStringPtr(p_m_originalSkeletonName);
  hkStringPtr::hkStringPtr(&this->m_name);
  this->m_skeleton.m_pntr = 0i64;
  this->m_mappings.m_data = 0i64;
  this->m_mappings.m_size = 0;
  this->m_mappings.m_capacityAndFlags = 0x80000000;
  this->m_boneFromSkinMeshTransforms.m_data = 0i64;
  this->m_boneFromSkinMeshTransforms.m_size = 0;
  this->m_boneFromSkinMeshTransforms.m_capacityAndFlags = 0x80000000;
}

// File Line: 26
// RVA: 0xB36450
void __fastcall hkaMeshBinding::hkaMeshBinding(hkaMeshBinding *this, hkFinishLoadedObjectFlag f)
{
  hkStringPtr *p_m_originalSkeletonName; // rcx

  p_m_originalSkeletonName = &this->m_originalSkeletonName;
  p_m_originalSkeletonName[-3].m_stringAndFlag = (const char *)&hkaMeshBinding::`vftable;
  hkStringPtr::hkStringPtr(p_m_originalSkeletonName, f);
  hkStringPtr::hkStringPtr(&this->m_name, f);
}

// File Line: 30
// RVA: 0xB36300
void __fastcall hkaMeshBinding::~hkaMeshBinding(hkaMeshBinding *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // eax
  __int64 v4; // rsi
  int *v5; // rbx
  int v6; // r8d
  int v7; // r8d
  hkaSkeleton *m_pntr; // rcx
  hkxMesh *v9; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaMeshBinding::`vftable;
  m_capacityAndFlags = this->m_boneFromSkinMeshTransforms.m_capacityAndFlags;
  this->m_boneFromSkinMeshTransforms.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_boneFromSkinMeshTransforms.m_data,
      m_capacityAndFlags << 6);
  this->m_boneFromSkinMeshTransforms.m_data = 0i64;
  this->m_boneFromSkinMeshTransforms.m_capacityAndFlags = 0x80000000;
  v3 = this->m_mappings.m_size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = &this->m_mappings.m_data->m_mapping.m_capacityAndFlags + 4 * v3;
    do
    {
      v6 = *v5;
      *(v5 - 1) = 0;
      if ( v6 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v5 - 3),
          2 * (v6 & 0x3FFFFFFF));
      *(_QWORD *)(v5 - 3) = 0i64;
      *v5 = 0x80000000;
      v5 -= 4;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v7 = this->m_mappings.m_capacityAndFlags;
  this->m_mappings.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_mappings.m_data,
      16 * v7);
  this->m_mappings.m_data = 0i64;
  this->m_mappings.m_capacityAndFlags = 0x80000000;
  m_pntr = this->m_skeleton.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_skeleton.m_pntr = 0i64;
  hkStringPtr::~hkStringPtr(&this->m_name);
  hkStringPtr::~hkStringPtr(&this->m_originalSkeletonName);
  v9 = this->m_mesh.m_pntr;
  if ( v9 )
    hkReferencedObject::removeReference(v9);
  this->m_mesh.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

