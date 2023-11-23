// File Line: 80
// RVA: 0x2BD0
UFG::ComponentIDDesc *__fastcall UFG::CompositeDrawableComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::CompositeDrawableComponent::_DescInit )
  {
    UFG::CompositeDrawableComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::CompositeDrawableComponent::_DescInit = 1;
    UFG::CompositeDrawableComponent::_TypeUID = UFG::CompositeDrawableComponent::_TypeIDesc.mChildBitMask | (UFG::CompositeDrawableComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::CompositeDrawableComponent::_CompositeDrawableComponentTypeUID = UFG::CompositeDrawableComponent::_TypeIDesc.mChildBitMask | (UFG::CompositeDrawableComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::CompositeDrawableComponent::_TypeIDesc;
}

// File Line: 105
// RVA: 0x3D50
void __fastcall UFG::CompositeDrawableComponent::OnAttachDecal(
        UFG::CompositeDrawableComponent *this,
        Render::Decal *decal,
        Render::DecalClipQuery *dcq)
{
  decal->mBindIndex = dcq->decal_info->mStoredObjLink.mIndex;
}

// File Line: 138
// RVA: 0x443290
void __fastcall UFG::CompositeDrawableComponent::SetRig(UFG::CompositeDrawableComponent *this, unsigned int rig_uid)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax

  Inventory = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mRigHandle, 0x39BC0A7Eu, rig_uid, Inventory);
}

