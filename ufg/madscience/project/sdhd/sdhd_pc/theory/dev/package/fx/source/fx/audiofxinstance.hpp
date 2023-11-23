// File Line: 56
// RVA: 0x1C4A80
// attributes: thunk
void __fastcall Illusion::ShaderParam::operator delete(void *ptr)
{
  operator delete[](ptr);
}

// File Line: 60
// RVA: 0x1C2C10
void __fastcall Render::AudioFXInstance::~AudioFXInstance(Render::AudioFXInstance *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mPrev; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mNext; // rax

  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::AudioFXInstance::`vftable;
  UFG::OneShotHandle::Release(&this->mOneShot);
  Inventory = `UFG::qGetResourceInventory<Render::AudioFXSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::AudioFXSettings>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0xD77CCEB2);
    `UFG::qGetResourceInventory<Render::AudioFXSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mSettingsHandle);
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
}

