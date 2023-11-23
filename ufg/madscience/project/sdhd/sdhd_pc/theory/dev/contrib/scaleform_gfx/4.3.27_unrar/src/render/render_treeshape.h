// File Line: 44
// RVA: 0x940200
void __fastcall Scaleform::Render::TreeShape::NodeData::NodeData(
        Scaleform::Render::TreeShape::NodeData *this,
        Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeShape::NodeData> src)
{
  Scaleform::Render::ContextImpl::EntryDataVtbl *vfptr; // rsi
  void *(__fastcall *vecDelDtor)(Scaleform::Render::ContextImpl::EntryData *, unsigned int); // rcx
  Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData> srca; // [rsp+48h] [rbp+10h] BYREF

  srca.pC = (Scaleform::Render::TreeNode::NodeData *)src.pC->vfptr;
  Scaleform::Render::TreeNode::NodeData::NodeData(
    this,
    (Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData>)&srca);
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeShape::NodeData,Scaleform::Render::TreeNode::NodeData>::`vftable;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeShape::NodeData::`vftable;
  vfptr = src.pC->vfptr;
  vecDelDtor = src.pC->vfptr[3].__vecDelDtor;
  if ( vecDelDtor )
    (*(void (__fastcall **)(__int64))(*((_QWORD *)vecDelDtor + 2) + 8i64))((__int64)vecDelDtor + 16);
  this->pMeshProvider.pObject = (Scaleform::Render::ShapeMeshProvider *)vfptr[3].__vecDelDtor;
  this->MorphRatio = *(float *)&src.pC->vfptr[3].ConstructCopy;
}

// File Line: 69
// RVA: 0x81D530
void __fastcall Scaleform::Render::TreeShape::SetShape(
        Scaleform::Render::TreeShape *this,
        Scaleform::Render::ContextImpl::EntryDataVtbl *pshape)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rsi
  Scaleform::Render::ContextImpl::EntryDataVtbl *vfptr; // rcx

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  if ( pshape )
    (*((void (__fastcall **)(void (__fastcall **)(Scaleform::Render::ContextImpl::EntryData *, void *)))pshape->CopyTo
     + 1))(&pshape->CopyTo);
  vfptr = WritableData[9].vfptr;
  if ( vfptr )
    (*((void (__fastcall **)(void (__fastcall **)(Scaleform::Render::ContextImpl::EntryData *, void *)))vfptr->CopyTo + 2))(&vfptr->CopyTo);
  WritableData[9].vfptr = pshape;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}

