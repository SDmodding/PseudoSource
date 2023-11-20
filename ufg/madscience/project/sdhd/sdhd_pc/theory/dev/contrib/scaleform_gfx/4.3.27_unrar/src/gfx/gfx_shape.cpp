// File Line: 99
// RVA: 0x8B5BD0
char *__fastcall Scaleform::GFx::PathAllocator::AllocMemoryBlock(Scaleform::GFx::PathAllocator *this, unsigned int sizeForCurrentPage, unsigned int sizeInNewPage)
{
  unsigned int v3; // edi
  __int16 v4; // si
  Scaleform::GFx::PathAllocator *v5; // rbx
  char *result; // rax
  char *v7; // rdx
  _QWORD *v8; // rax
  bool v9; // zf

  v3 = this->FreeBytes;
  v4 = sizeInNewPage;
  v5 = this;
  if ( this->pLastPage && v3 >= sizeForCurrentPage )
  {
    v4 = sizeForCurrentPage;
LABEL_11:
    result = (char *)&v5->pLastPage->PageSize + v5->pLastPage->PageSize - (unsigned __int64)v3 + 4;
    v5->FreeBytes = v3 - v4;
    return result;
  }
  v3 = this->DefaultPageSize;
  if ( sizeInNewPage > v3 )
    v3 = sizeInNewPage;
  result = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                     Scaleform::Memory::pGlobalHeap,
                     this,
                     v3 + 16i64,
                     0i64);
  v7 = result;
  if ( result )
  {
    *(_QWORD *)result = 0i64;
    *((_DWORD *)result + 2) = v3;
    v8 = &v5->pLastPage->pNext;
    if ( v8 )
    {
      *v8 = v7;
      v5->pLastPage->PageSize -= v5->FreeBytes;
    }
    v9 = v5->pFirstPage == 0i64;
    v5->pLastPage = (Scaleform::GFx::PathAllocator::Page *)v7;
    if ( v9 )
      v5->pFirstPage = (Scaleform::GFx::PathAllocator::Page *)v7;
    goto LABEL_11;
  }
  return result;
}

// File Line: 145
// RVA: 0x8FE250
bool __fastcall Scaleform::GFx::PathAllocator::ReallocLastBlock(Scaleform::GFx::PathAllocator *this, char *ptr, unsigned int oldSize, unsigned int newSize)
{
  Scaleform::GFx::PathAllocator::Page *v4; // r11
  char *v5; // rbx
  bool result; // al
  unsigned __int64 v7; // rdx

  if ( newSize >= oldSize )
    return 0;
  v4 = this->pLastPage;
  if ( !v4 )
    return 0;
  if ( ptr - (char *)v4 - 12 >= (signed int)v4->PageSize )
    return 0;
  v5 = (char *)(ptr - (char *)v4 - 12);
  if ( v4->PageSize - (unsigned __int64)oldSize - (_QWORD)v5 != this->FreeBytes )
    return 0;
  result = 0;
  v7 = v4->PageSize - (unsigned __int64)newSize - (_QWORD)v5;
  if ( v7 < 0x10000 )
    this->FreeBytes = v7;
  return result;
}

// File Line: 172
// RVA: 0x8C41C0
Scaleform::Ptr<Scaleform::Render::TreeNode> *__fastcall Scaleform::GFx::ShapeBaseCharacterDef::CreateTreeShape(Scaleform::GFx::ShapeBaseCharacterDef *this, Scaleform::Ptr<Scaleform::Render::TreeNode> *result, Scaleform::Render::ContextImpl::Context *context, Scaleform::GFx::MovieDefImpl *defImpl)
{
  Scaleform::GFx::MovieDefImpl *v4; // rbp
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v5; // rdi
  Scaleform::GFx::ShapeBaseCharacterDef *v6; // rsi
  Scaleform::Render::TreeShape *v7; // rbx
  Scaleform::Render::ShapeMeshProvider *v8; // rdx
  Scaleform::Render::ShapeMeshProvider **v9; // r14
  bool v10; // zf
  __int64 v12; // [rsp+28h] [rbp-30h]
  __int64 v13; // [rsp+30h] [rbp-28h]
  Scaleform::Render::TreeShape *v14; // [rsp+38h] [rbp-20h]
  Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> resulta; // [rsp+60h] [rbp+8h]
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v16; // [rsp+68h] [rbp+10h]

  v16 = result;
  v13 = -2i64;
  v4 = defImpl;
  v5 = result;
  v6 = this;
  v7 = (Scaleform::Render::TreeShape *)Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeShape>(context);
  v14 = v7;
  if ( v6->vfptr[3].GetResourceTypeCode((Scaleform::GFx::Resource *)&v6->vfptr) )
  {
    Scaleform::GFx::MovieDefImpl::BindTaskData::GetShapeMeshProvider(
      v4->pBindData.pObject,
      &resulta,
      v6->pShapeMeshProvider.pObject);
    v8 = resulta.pObject;
    if ( !resulta.pObject )
    {
      v9 = (Scaleform::Render::ShapeMeshProvider **)((__int64 (__fastcall *)(Scaleform::GFx::ShapeBaseCharacterDef *, __int64 *, Scaleform::GFx::ResourceBinding *))v6->vfptr[3].GetKey)(
                                                      v6,
                                                      &v12,
                                                      &v4->pBindData.pObject->ResourceBinding);
      if ( *v9 )
        (*((void (__cdecl **)(Scaleform::Render::MeshProviderVtbl **))&(*v9)->vfptr->__vecDelDtor + 1))(&(*v9)->vfptr);
      if ( resulta.pObject )
        ((void (__cdecl *)(Scaleform::Render::MeshProviderVtbl **))resulta.pObject->vfptr->Release)(&resulta.pObject->vfptr);
      resulta.pObject = *v9;
      if ( v12 )
        (*(void (__cdecl **)(__int64))(*(_QWORD *)(v12 + 16) + 16i64))(v12 + 16);
      Scaleform::GFx::MovieDefImpl::BindTaskData::AddShapeMeshProvider(
        v4->pBindData.pObject,
        v6->pShapeMeshProvider.pObject,
        resulta.pObject);
      v8 = resulta.pObject;
    }
    Scaleform::Render::TreeShape::SetShape(v7, v8);
    if ( resulta.pObject )
      ((void (__cdecl *)(Scaleform::Render::MeshProviderVtbl **))resulta.pObject->vfptr->Release)(&resulta.pObject->vfptr);
  }
  else
  {
    Scaleform::Render::TreeShape::SetShape(v7, v6->pShapeMeshProvider.pObject);
  }
  if ( v7 )
    ++v7->RefCount;
  v5->pObject = (Scaleform::Render::TreeNode *)&v7->0;
  if ( v7 )
  {
    v10 = v7->RefCount-- == 1;
    if ( v10 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v7->0);
  }
  return v5;
}

