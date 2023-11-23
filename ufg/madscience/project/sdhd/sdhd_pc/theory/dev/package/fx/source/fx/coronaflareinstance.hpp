// File Line: 13
// RVA: 0x1C0EB0
void __fastcall Render::CoronaFlareInstance::CoronaFlareInstance(Render::CoronaFlareInstance *this)
{
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::CoronaFlareInstance::`vftable;
  UFG::qResourceHandle::qResourceHandle(&this->mCoronaFlare.mSettings);
}

// File Line: 14
// RVA: 0x1C2ED0
void __fastcall Render::CoronaFlareInstance::~CoronaFlareInstance(Render::CoronaFlareInstance *this)
{
  Render::CoronaFlare *p_mCoronaFlare; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mPrev; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mNext; // rax

  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::CoronaFlareInstance::`vftable;
  p_mCoronaFlare = &this->mCoronaFlare;
  Inventory = `UFG::qGetResourceInventory<Render::CoronaFlareSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::CoronaFlareSettings>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0xB76CCFB8);
    `UFG::qGetResourceInventory<Render::CoronaFlareSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&p_mCoronaFlare->mSettings, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&p_mCoronaFlare->mSettings);
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
}

