// File Line: 99
// RVA: 0x8B5BD0
Scaleform::GFx::PathAllocator::Page *__fastcall Scaleform::GFx::PathAllocator::AllocMemoryBlock(
        Scaleform::GFx::PathAllocator *this,
        unsigned int sizeForCurrentPage,
        unsigned int sizeInNewPage)
{
  unsigned int FreeBytes; // edi
  __int16 v4; // si
  Scaleform::GFx::PathAllocator::Page *result; // rax
  Scaleform::GFx::PathAllocator::Page *v7; // rdx
  Scaleform::GFx::PathAllocator::Page *pLastPage; // rax
  bool v9; // zf

  FreeBytes = this->FreeBytes;
  v4 = sizeInNewPage;
  if ( this->pLastPage && FreeBytes >= sizeForCurrentPage )
  {
    v4 = sizeForCurrentPage;
LABEL_11:
    result = (Scaleform::GFx::PathAllocator::Page *)((char *)&this->pLastPage->PageSize
                                                   + this->pLastPage->PageSize
                                                   - (unsigned __int64)FreeBytes
                                                   + 4);
    this->FreeBytes = FreeBytes - v4;
    return result;
  }
  FreeBytes = this->DefaultPageSize;
  if ( sizeInNewPage > FreeBytes )
    FreeBytes = sizeInNewPage;
  result = (Scaleform::GFx::PathAllocator::Page *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this,
                                                    FreeBytes + 16i64,
                                                    0i64);
  v7 = result;
  if ( result )
  {
    result->pNext = 0i64;
    result->PageSize = FreeBytes;
    pLastPage = this->pLastPage;
    if ( pLastPage )
    {
      pLastPage->pNext = v7;
      this->pLastPage->PageSize -= this->FreeBytes;
    }
    v9 = this->pFirstPage == 0i64;
    this->pLastPage = v7;
    if ( v9 )
      this->pFirstPage = v7;
    goto LABEL_11;
  }
  return result;
}

// File Line: 145
// RVA: 0x8FE250
bool __fastcall Scaleform::GFx::PathAllocator::ReallocLastBlock(
        Scaleform::GFx::PathAllocator *this,
        char *ptr,
        unsigned int oldSize,
        unsigned int newSize)
{
  Scaleform::GFx::PathAllocator::Page *pLastPage; // r11
  char *v5; // rbx
  bool result; // al
  unsigned __int64 v7; // rdx

  if ( newSize >= oldSize )
    return 0;
  pLastPage = this->pLastPage;
  if ( !pLastPage )
    return 0;
  if ( ptr - (char *)pLastPage - 12 >= (int)pLastPage->PageSize )
    return 0;
  v5 = (char *)(ptr - (char *)pLastPage - 12);
  if ( pLastPage->PageSize - (unsigned __int64)oldSize - (_QWORD)v5 != this->FreeBytes )
    return 0;
  result = 0;
  v7 = pLastPage->PageSize - (unsigned __int64)newSize - (_QWORD)v5;
  if ( v7 < 0x10000 )
    this->FreeBytes = v7;
  return result;
}

// File Line: 172
// RVA: 0x8C41C0
Scaleform::Ptr<Scaleform::Render::TreeNode> *__fastcall Scaleform::GFx::ShapeBaseCharacterDef::CreateTreeShape(
        Scaleform::GFx::ShapeBaseCharacterDef *this,
        Scaleform::Ptr<Scaleform::Render::TreeNode> *result,
        Scaleform::Render::ContextImpl::Context *context,
        Scaleform::GFx::MovieDefImpl *defImpl)
{
  Scaleform::Render::TreeShape *v7; // rbx
  Scaleform::Render::ContextImpl::EntryDataVtbl *pObject; // rdx
  Scaleform::Render::ShapeMeshProvider **v9; // r14
  __int64 v12[6]; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> resulta; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v14; // [rsp+68h] [rbp+10h]

  v14 = result;
  v12[1] = -2i64;
  v7 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeShape>(context);
  v12[2] = (__int64)v7;
  if ( (unsigned __int8)this->vfptr[3].GetResourceTypeCode(this) )
  {
    Scaleform::GFx::MovieDefImpl::BindTaskData::GetShapeMeshProvider(
      defImpl->pBindData.pObject,
      &resulta,
      this->pShapeMeshProvider.pObject);
    pObject = (Scaleform::Render::ContextImpl::EntryDataVtbl *)resulta.pObject;
    if ( !resulta.pObject )
    {
      v9 = (Scaleform::Render::ShapeMeshProvider **)((__int64 (__fastcall *)(Scaleform::GFx::ShapeBaseCharacterDef *, __int64 *, Scaleform::GFx::ResourceBinding *))this->vfptr[3].GetKey)(
                                                      this,
                                                      v12,
                                                      &defImpl->pBindData.pObject->ResourceBinding);
      if ( *v9 )
        (*((void (__fastcall **)(Scaleform::Render::MeshProvider *))&(*v9)->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->__vecDelDtor
         + 1))(&(*v9)->Scaleform::Render::MeshProvider);
      if ( resulta.pObject )
        resulta.pObject->vfptr->Release(&resulta.pObject->Scaleform::Render::MeshProvider);
      resulta.pObject = *v9;
      if ( v12[0] )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)(v12[0] + 16) + 16i64))(v12[0] + 16);
      Scaleform::GFx::MovieDefImpl::BindTaskData::AddShapeMeshProvider(
        defImpl->pBindData.pObject,
        this->pShapeMeshProvider.pObject,
        resulta.pObject);
      pObject = (Scaleform::Render::ContextImpl::EntryDataVtbl *)resulta.pObject;
    }
    Scaleform::Render::TreeShape::SetShape(v7, pObject);
    if ( resulta.pObject )
      resulta.pObject->vfptr->Release(&resulta.pObject->Scaleform::Render::MeshProvider);
  }
  else
  {
    Scaleform::Render::TreeShape::SetShape(
      v7,
      (Scaleform::Render::ContextImpl::EntryDataVtbl *)this->pShapeMeshProvider.pObject);
  }
  if ( v7 )
    ++v7->RefCount;
  result->pObject = v7;
  if ( v7 )
  {
    if ( v7->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v7);
  }
  return result;
}

