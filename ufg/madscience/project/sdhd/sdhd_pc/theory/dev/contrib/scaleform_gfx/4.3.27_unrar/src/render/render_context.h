// File Line: 106
// RVA: 0x939AB0
void __fastcall Scaleform::Render::ContextImpl::ContextLock::ContextLock(
        Scaleform::Render::ContextImpl::ContextLock *this,
        Scaleform::Render::ContextImpl::Context *context)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,69>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ContextImpl::ContextLock,69>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ContextImpl::ContextLock::`vftable;
  Scaleform::Lock::Lock(&this->LockObject, 0);
  this->pContext = context;
}

// File Line: 478
// RVA: 0x971F50
void __fastcall Scaleform::Render::WrapperImageSource::GetImageType(
        UFG::SensorPhantom *this,
        UFG::qVector3 *vmin,
        UFG::qVector3 *vmax)
{
  this->mPhantom->vfptr->GetExtents(this->mPhantom, vmin, vmax);
}

// File Line: 724
// RVA: 0x76C290
Scaleform::Render::TreeShape *__fastcall Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeShape>(
        Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::TreeNode::NodeData *v2; // rax
  Scaleform::Render::TreeNode::NodeData *v3; // rbx

  v2 = (Scaleform::Render::TreeNode::NodeData *)this->pHeap->vfptr->Alloc(this->pHeap, 160i64, 0i64);
  v3 = v2;
  if ( v2 )
  {
    Scaleform::Render::TreeNode::NodeData::NodeData(v2, ET_Shape);
    v3->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeShape::NodeData,Scaleform::Render::TreeNode::NodeData>::`vftable;
    v3->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeShape::NodeData::`vftable;
    v3[1].vfptr = 0i64;
    *(_DWORD *)&v3[1].Type = 0;
  }
  return (Scaleform::Render::TreeShape *)Scaleform::Render::ContextImpl::Context::createEntryHelper(this, v3);
}

// File Line: 946
// RVA: 0x6DF540
Scaleform::Render::TreeNodeArray *__fastcall Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeContainer::NodeData,Scaleform::Render::TreeNode::NodeData>::ConstructCopy(
        Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeContainer::NodeData,Scaleform::Render::TreeNode::NodeData> *this,
        Scaleform::Render::LinearHeap *heap)
{
  Scaleform::Render::TreeNode::NodeData *v3; // rax
  Scaleform::Render::TreeNodeArray *v4; // rbx

  ++Scaleform::Render::ContextImpl::ConstructCopyCalls;
  v3 = (Scaleform::Render::TreeNode::NodeData *)Scaleform::Render::LinearHeap::Alloc(heap, 0xA0ui64);
  v4 = (Scaleform::Render::TreeNodeArray *)v3;
  if ( !v3 )
    return 0i64;
  Scaleform::Render::TreeNode::NodeData::NodeData(v3, this);
  v4->pData[0] = (unsigned __int64)&Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeContainer::NodeData,Scaleform::Render::TreeNode::NodeData>::`vftable;
  v4->pData[0] = (unsigned __int64)&Scaleform::Render::TreeContainer::NodeData::`vftable;
  Scaleform::Render::TreeNodeArray::TreeNodeArray(v4 + 9, (Scaleform::Render::TreeNodeArray *)&this[1]);
  return v4;
}

// File Line: 951
// RVA: 0x8BE4C0
void __fastcall Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeRoot::NodeData,Scaleform::Render::TreeContainer::NodeData>::CopyTo(
        Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeRoot::NodeData,Scaleform::Render::TreeContainer::NodeData> *this,
        Scaleform::Render::TreeRoot::NodeData *pdest)
{
  Scaleform::Render::TreeRoot::NodeData::operator=(pdest, (Scaleform::Render::TreeRoot::NodeData *)this);
  ++Scaleform::Render::ContextImpl::CopyCalls;
}

// File Line: 956
// RVA: 0x96D000
void __fastcall Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeShape::NodeData,Scaleform::Render::TreeNode::NodeData>::Destroy(
        Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeContainer::NodeData,Scaleform::Render::TreeNode::NodeData> *this)
{
  ++Scaleform::Render::ContextImpl::DestroyCalls;
  this->vfptr->__vecDelDtor(this, 0i64);
}

