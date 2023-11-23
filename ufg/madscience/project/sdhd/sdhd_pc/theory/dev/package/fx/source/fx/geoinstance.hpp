// File Line: 17
// RVA: 0x1C3E50
void __fastcall Render::GeoInstance::~GeoInstance(Render::GeoInstance *this)
{
  Illusion::ModelHandle *p_mModelHandle; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mPrev; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mNext; // rax

  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::GeoInstance::`vftable;
  p_mModelHandle = &this->mModelHandle;
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(p_mModelHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(p_mModelHandle);
  v5 = `UFG::qGetResourceInventory<Render::GeoSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::GeoSettings>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0xF1734D8E);
    `UFG::qGetResourceInventory<Render::GeoSettings>::`2::result = v5;
  }
  UFG::qResourceHandle::Close(&this->mSettingsHandle, v5);
  UFG::qResourceHandle::~qResourceHandle(&this->mSettingsHandle);
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
}

