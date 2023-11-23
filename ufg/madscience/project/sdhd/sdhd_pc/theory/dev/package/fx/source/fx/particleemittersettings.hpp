// File Line: 86
// RVA: 0x1C1D10
void __fastcall Render::ParticleEmitterSettings::ParticleEmitterSettings(Render::ParticleEmitterSettings *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax

  UFG::qResourceData::qResourceData(this);
  UFG::qResourceHandle::qResourceHandle(&this->mModel);
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mModel, 0xA2ADCD77, this->mModel.mNameUID, Inventory);
}

// File Line: 92
// RVA: 0x1C45D0
void __fastcall Render::ParticleEmitterSettings::~ParticleEmitterSettings(Render::ParticleEmitterSettings *this)
{
  Illusion::ModelHandle *p_mModel; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  p_mModel = &this->mModel;
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(p_mModel, Inventory);
  UFG::qResourceHandle::~qResourceHandle(p_mModel);
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&this->mResourceHandles);
  mPrev = this->mResourceHandles.UFG::qResourceData::mNode.mPrev;
  mNext = this->mResourceHandles.UFG::qResourceData::mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mResourceHandles.UFG::qResourceData::mNode.mPrev = &this->mResourceHandles.UFG::qResourceData::mNode;
  this->mResourceHandles.UFG::qResourceData::mNode.mNext = &this->mResourceHandles.UFG::qResourceData::mNode;
}

