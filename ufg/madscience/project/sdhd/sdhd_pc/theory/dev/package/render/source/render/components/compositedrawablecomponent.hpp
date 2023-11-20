// File Line: 80
// RVA: 0x2BD0
UFG::ComponentIDDesc *__fastcall UFG::CompositeDrawableComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::CompositeDrawableComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::CompositeDrawableComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::CompositeDrawableComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::CompositeDrawableComponent::_DescInit = 1;
    UFG::CompositeDrawableComponent::_TypeUID = UFG::CompositeDrawableComponent::_TypeIDesc.mChildBitMask | (UFG::CompositeDrawableComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::CompositeDrawableComponent::_CompositeDrawableComponentTypeUID = UFG::CompositeDrawableComponent::_TypeIDesc.mChildBitMask | (UFG::CompositeDrawableComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::CompositeDrawableComponent::_TypeIDesc;
}

// File Line: 105
// RVA: 0x3D50
void __fastcall UFG::CompositeDrawableComponent::OnAttachDecal(UFG::CompositeDrawableComponent *this, Render::Decal *decal, Render::DecalClipQuery *dcq)
{
  decal->mBindIndex = dcq->decal_info->mStoredObjLink.mIndex;
}

// File Line: 138
// RVA: 0x443290
void __fastcall UFG::CompositeDrawableComponent::SetRig(UFG::CompositeDrawableComponent *this, unsigned int rig_uid)
{
  UFG::qResourceInventory *v2; // rax
  unsigned int v3; // ebx
  UFG::CompositeDrawableComponent *v4; // rdi
  UFG::qResourceWarehouse *v5; // rax

  v2 = `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result;
  v3 = rig_uid;
  v4 = this;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v5, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4->mRigHandle.mPrev, 0x39BC0A7Eu, v3, v2);
}

