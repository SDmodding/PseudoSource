// File Line: 15
// RVA: 0xB36290
void __fastcall hkaMeshBinding::hkaMeshBinding(hkaMeshBinding *this)
{
  hkaMeshBinding *v1; // rbx
  hkStringPtr *v2; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaMeshBinding::`vftable;
  v2 = &this->m_originalSkeletonName;
  v2[-1].m_stringAndFlag = 0i64;
  hkStringPtr::hkStringPtr(v2);
  hkStringPtr::hkStringPtr(&v1->m_name);
  v1->m_skeleton.m_pntr = 0i64;
  v1->m_mappings.m_data = 0i64;
  v1->m_mappings.m_size = 0;
  v1->m_mappings.m_capacityAndFlags = 2147483648;
  v1->m_boneFromSkinMeshTransforms.m_data = 0i64;
  v1->m_boneFromSkinMeshTransforms.m_size = 0;
  v1->m_boneFromSkinMeshTransforms.m_capacityAndFlags = 2147483648;
}

// File Line: 26
// RVA: 0xB36450
void __fastcall hkaMeshBinding::hkaMeshBinding(hkaMeshBinding *this, hkFinishLoadedObjectFlag f)
{
  hkaMeshBinding *v2; // rbx
  hkStringPtr *v3; // rcx
  int fa; // [rsp+38h] [rbp+10h]

  fa = f.m_finishing;
  v2 = this;
  v3 = &this->m_originalSkeletonName;
  v3[-3].m_stringAndFlag = (const char *)&hkaMeshBinding::`vftable;
  hkStringPtr::hkStringPtr(v3, f);
  hkStringPtr::hkStringPtr(&v2->m_name, (hkFinishLoadedObjectFlag)fa);
}

// File Line: 30
// RVA: 0xB36300
void __fastcall hkaMeshBinding::~hkaMeshBinding(hkaMeshBinding *this)
{
  int v1; // er8
  hkaMeshBinding *v2; // rdi
  int v3; // eax
  __int64 v4; // rsi
  int *v5; // rbx
  int v6; // er8
  int v7; // er8
  hkReferencedObject *v8; // rcx
  hkReferencedObject *v9; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaMeshBinding::`vftable;
  v1 = this->m_boneFromSkinMeshTransforms.m_capacityAndFlags;
  v2 = this;
  this->m_boneFromSkinMeshTransforms.m_size = 0;
  if ( v1 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_boneFromSkinMeshTransforms.m_data,
      v1 << 6);
  v2->m_boneFromSkinMeshTransforms.m_data = 0i64;
  v2->m_boneFromSkinMeshTransforms.m_capacityAndFlags = 2147483648;
  v3 = v2->m_mappings.m_size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = &v2->m_mappings.m_data->m_mapping.m_capacityAndFlags + 4 * v3;
    do
    {
      v6 = *v5;
      *(v5 - 1) = 0;
      if ( v6 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v5 - 3),
          2 * (v6 & 0x3FFFFFFF));
      *(_QWORD *)(v5 - 3) = 0i64;
      *v5 = 2147483648;
      v5 -= 4;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v7 = v2->m_mappings.m_capacityAndFlags;
  v2->m_mappings.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_mappings.m_data,
      16 * v7);
  v2->m_mappings.m_data = 0i64;
  v2->m_mappings.m_capacityAndFlags = 2147483648;
  v8 = (hkReferencedObject *)&v2->m_skeleton.m_pntr->vfptr;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  v2->m_skeleton.m_pntr = 0i64;
  hkStringPtr::~hkStringPtr(&v2->m_name);
  hkStringPtr::~hkStringPtr(&v2->m_originalSkeletonName);
  v9 = (hkReferencedObject *)&v2->m_mesh.m_pntr->vfptr;
  if ( v9 )
    hkReferencedObject::removeReference(v9);
  v2->m_mesh.m_pntr = 0i64;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

