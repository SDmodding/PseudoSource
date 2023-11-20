// File Line: 44
// RVA: 0x940200
void __fastcall Scaleform::Render::TreeShape::NodeData::NodeData(Scaleform::Render::TreeShape::NodeData *this, Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeShape::NodeData> src)
{
  Scaleform::Render::TreeShape::NodeData *v2; // rdi
  Scaleform::Render::TreeShape::NodeData *v3; // rbx
  Scaleform::Render::ContextImpl::EntryDataVtbl *v4; // rsi
  void *(__fastcall *v5)(Scaleform::Render::ContextImpl::EntryData *, unsigned int); // rcx
  Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData> srca; // [rsp+48h] [rbp+10h]

  v2 = src.pC;
  v3 = this;
  srca.pC = (Scaleform::Render::TreeNode::NodeData *)src.pC->vfptr;
  Scaleform::Render::TreeNode::NodeData::NodeData(
    (Scaleform::Render::TreeNode::NodeData *)&this->vfptr,
    (Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData>)&srca);
  v3->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeShape::NodeData,Scaleform::Render::TreeNode::NodeData>::`vftable;
  v3->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeShape::NodeData::`vftable;
  v4 = v2->vfptr;
  v5 = v2->vfptr[3].__vecDelDtor;
  if ( v5 )
    (*(void (__cdecl **)(signed __int64))(*((_QWORD *)v5 + 2) + 8i64))((signed __int64)v5 + 16);
  v3->pMeshProvider.pObject = (Scaleform::Render::ShapeMeshProvider *)v4[3].__vecDelDtor;
  v3->MorphRatio = *(float *)&v2->vfptr[3].ConstructCopy;
}

// File Line: 69
// RVA: 0x81D530
void __fastcall Scaleform::Render::TreeShape::SetShape(Scaleform::Render::TreeShape *this, Scaleform::Render::ShapeMeshProvider *pshape)
{
  Scaleform::Render::ShapeMeshProvider *v2; // rdi
  Scaleform::Render::TreeShape *v3; // rbx
  Scaleform::Render::ContextImpl::EntryData *v4; // rsi
  Scaleform::Render::ContextImpl::EntryDataVtbl *v5; // rcx

  v2 = pshape;
  v3 = this;
  v4 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&this->0, 0x400u);
  if ( v2 )
    (*((void (__fastcall **)(Scaleform::Render::MeshProviderVtbl **))&v2->vfptr->__vecDelDtor + 1))(&v2->vfptr);
  v5 = v4[9].vfptr;
  if ( v5 )
    (*((void (__fastcall **)(void (__fastcall **)(Scaleform::Render::ContextImpl::EntryData *, void *)))v5->CopyTo + 2))(&v5->CopyTo);
  v4[9].vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)v2;
  if ( !v3->PNode.pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl((Scaleform::Render::ContextImpl::Entry *)&v3->0);
}

