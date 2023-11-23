// File Line: 15
// RVA: 0x1C3130
void __fastcall Render::DecalInstance::~DecalInstance(Render::DecalInstance *this)
{
  Render::DecalSettingsHandle *p_mSettingsHandle; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mPrev; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mNext; // rax

  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::DecalInstance::`vftable;
  p_mSettingsHandle = &this->mSettingsHandle;
  Inventory = `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::DecalSettings>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0xAE323146);
    `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(p_mSettingsHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(p_mSettingsHandle);
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
}

